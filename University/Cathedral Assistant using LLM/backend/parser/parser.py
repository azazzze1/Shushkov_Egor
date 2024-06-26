import datetime
import json
import unicodedata
import requests
from bs4 import BeautifulSoup
import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


def check_links(links, viewed_links):
    new_links = []
    for i in links:
        if (i not in viewed_links and "?do=login&sectok=" not in i and "?do=diff&rev" not in i and "do=media" not in i
                and not i.endswith(('jpg', 'png', 'gif', 'jpeg', 'pdf', 'doc', 'odt', 'docs'))):
            new_links.append(i)
    return new_links


def find_date(text):
    last_modified_index = text.find('Last modified:')
    if last_modified_index != -1:
        last_modified_text = text[last_modified_index + len('Last modified:'):].strip()
        split_text = last_modified_text.split(' ')
        date = split_text[0] + " " + split_text[1]
        date_format = "%Y/%m/%d %H:%M"
        timestamp = datetime.datetime.strptime(date, date_format)
        return str(timestamp)


def scrape_page(url, viewed_links):
    try:
        response = requests.get("https://se.moevm.info" + url)
        if url not in ['jpg', 'png', 'gif', 'jpeg', 'pdf', 'doc', 'odt', 'docs']:
            soup = BeautifulSoup(response.text, 'html.parser')
            text_data = soup.get_text()
            text_data = unicodedata.normalize('NFKD', text_data).encode('utf-8', 'ignore').decode('utf-8', 'ignore')
            links = soup.find_all('a', href=True)
            links = check_links([link['href'] for link in links if link['href'].startswith('/')], viewed_links)
            return {'url': url, 'text': text_data, 'links': links}
    except Exception as e:
        logger.error("An error occurred while scraping the page:", e)
        return None


def recursive_scrape(page, viewed_links, depth, max_depth, courses, courses_data):
    if depth >= max_depth:
        return []

    result = []
    viewed_links.add(page["url"])
    page_data = scrape_page(page['url'], viewed_links)
    if depth == 0:
        subject = next((s for s in courses_data[courses] if s["name"] == page["name"]), None)
        if subject:
            subject["date"] = find_date(page_data["text"])
    if page_data is not None:
        result.append(page_data['text'])
        if 'links' in page_data:
            for link in page_data["links"]:
                if "/doku.php" in link:
                    result.extend(
                        recursive_scrape({'name': '', 'url': link}, viewed_links, depth + 1, max_depth, courses,
                                         courses_data))
    return result


def read_courses(viewed_links):
    url = "https://se.moevm.info/doku.php"
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    text_data = soup.get_text()
    courses_data = {}
    course_elems = soup.find_all('li', class_=["level1 node", "level2 node", "level3 node"])
    courses_data["info"] = []
    for course_elem in course_elems:
        course_name = course_elem.find("div", class_="li").text.strip()
        subjects = course_elem.find_all("a", class_="wikilink1")
        courses_data[course_name] = []
        for subject in subjects:
            subject_name = subject.text.strip()
            subject_url = subject["href"]
            viewed_links.add(subject_url)
            courses_data[course_name].append({"name": subject_name, "url": subject_url})

    first_courses = [i["name"] for i in courses_data["1 курс"]]
    info_elems = soup.find_all('li', class_="level1")
    for info_elem in info_elems:
        course_name = info_elem.find("div", class_="li").text.strip()
        subjects = info_elem.find_all("a", class_="wikilink1")
        for subject in subjects:
            subject_name = subject.text.strip()
            if subject_name not in first_courses:
                subject_url = subject["href"]
                viewed_links.add(subject_url)
                courses_data["info"].append({"name": subject_name, "url": subject_url})
    courses_data["date"] = find_date(text_data)
    return courses_data


def create_data(courses_data, viewed_links, max_depth):
    for courses in courses_data:
        if courses != "date":
            for subject in courses_data[courses]:
                subject["data"] = recursive_scrape(subject, viewed_links, 0, max_depth, courses, courses_data)


viewed_links = set()
courses_data = read_courses(viewed_links)
max_depth = 2
create_data(courses_data, viewed_links, max_depth)

with open("./data.json", "w", encoding="utf-8") as json_file:
    json.dump(courses_data, json_file, ensure_ascii=False, indent=4)
