import wikipedia as wk


def is_page_valid(page):
    try:
        wk.page(page)
    except Exception:
        return False
    return True


def max_len_in_summary(page_names):
    max_len = 0
    max_len_name = ""
    for i in range(0, len(page_names)):
        summary = wk.summary(page_names[i])
        if len(summary.split()) >= max_len:
            max_len = len(summary.split())
            max_len_name = wk.page(page_names[i]).title
    return [max_len, max_len_name]


def page_chains(page_names):
    chain_arr = [page_names[0]]

    for i in range(0, len(page_names) - 1):
        links = wk.page(page_names[i]).links

        if page_names[i + 1] in links:
            chain_arr.append(page_names[i + 1])
        else:
            for li in links:

                sec_links = wk.page(li).links
                if is_page_valid(li) and page_names[i + 1] in sec_links:
                    chain_arr.append(li)
                    chain_arr.append(page_names[i + 1])
                    break
    return chain_arr


def language_search(page_names):
    if page_names[-1] in wk.languages():
        wk.set_lang(page_names[-1])

        return [max_len_in_summary(page_names[0:len(page_names) - 1]), page_chains(page_names[0:len(page_names) - 1])]
    else:
        return ("no results")


page_names = input().split(", ")
ans = language_search(page_names)
if ans == "no results":
    print(ans)
else:
    print(*ans[0])
    print(ans[1])
