#include "main.h"
#include "mutual_act.h"

//смещение слов в предложениии
void WordShift(wchar_t *sent, int shift_count) {

    int i = 0;
    int sent_s = wcslen(sent) - 2;
    while (i < shift_count) {
        int size_last_word = 0;
        wchar_t sym = 'a';

        //поиск кол-ва индексов для смещения первого слова, т.е. длина последнего+пробел
        for (int k = sent_s; sym != L' ' && k>-2; k--) {
            sym = sent[k];
            size_last_word++;
        }

        wchar_t *last_word = malloc((size_last_word - 1) * sizeof(wchar_t));

        //Запись последнего слова в отдельный массив
        int idx_last_word = 0;
        for (int k = sent_s - size_last_word + 2; k < sent_s + 1; k++) {
            last_word[idx_last_word++] = sent[k];

        }

        //смещение слов прошлого массива
        for (int k = sent_s - size_last_word; k > -1; k--) {
            sent[k + size_last_word] = sent[k];
        }

        for (int k = 0; k < size_last_word; k++) {
            sent[k] = ' ';
        }

        // подстановка последнего слова в начало
        for (int k = 0; k < size_last_word - 1; k++) {
            sent[k] = last_word[k];
        }

        free(last_word);
        i++;
    }

    DoublePointDelete(sent);
    wprintf(L"%ls", sent);
}

//поиск уникальных символов
void UniqueSymbols(struct Text pr_text) {
    //Создаём массивы для каждого алфавита
    int *latin_large = calloc(26, sizeof(int));
    int *cyrillic_large = calloc(33, sizeof(int));
    int *latin_low = calloc(26, sizeof(int));
    int *cyrillic_low = calloc(33, sizeof(int));

    //проверяем каждый символ. В зависимости от алфавита прибавляем к "его" ячейке единицу
    for (int i = 0; i < pr_text.sent_count; i++) {
        wchar_t *sent = pr_text.text[i]->Sent;
        for (int j = 0; j < wcslen(sent); j++) {
            if ('A' <= sent[j] && sent[j] <= 'Z') {
                latin_large[sent[j] - 'A']++;
            } else if ('a' <= sent[j] && sent[j] <= 'z') {
                latin_low[sent[j] - 'a']++;
            } else if (L'А' <= sent[j] && sent[j] <= L'Я') {
                cyrillic_large[sent[j] - L'А']++;
            } else if (L'а' <= sent[j] && sent[j] <= L'я') {
                cyrillic_low[sent[j] - L'а']++;
            }
        }
    }

    wprintf(L"Уникальные латинские символы:\n");

    int br_p = 0, br_p2 = 0;

    //выводим уникальные латинские символы
    for (int i = 0; i < 26; i++) {
        if (latin_large[i] == 1) {
            wprintf(L"%c ", i + 'A');
            br_p++;
        }
        if (latin_low[i] == 1) {
            wprintf(L"%c ", i + 'a');
            br_p++;
        }
    }
    if (br_p == 0) {
        wprintf(L"Нет");
    }

    wprintf(L"\nУникальные кириллические символы:\n");
    //выводим уникальные кириллические символы
    for (int i = 0; i < 33; i++) {
        if (cyrillic_large[i] == 1) {
            br_p2++;
            wprintf(L"%lc ", i + L'А');
        }
        if (cyrillic_low[i] == 1) {
            br_p2++;
            wprintf(L"%lc ", i + L'а');
        }
    }

    if (br_p2 == 0) {
        wprintf(L"Нет");
    }
    wprintf(L"\n");

    free(latin_large);
    free(latin_low);
    free(cyrillic_large);
    free(cyrillic_low);

}

//Удаление слов с Заглавной на конце
void RemovingLastUpper(struct Text pr_text) {
    int len_word = 0;
    wchar_t sym = ' ';
    for (int i = 0; i < pr_text.sent_count; i++) {
        int real_size = 0;
        wchar_t *sent = pr_text.text[i]->Sent;
        for (int j = wcslen(sent) - 1; j > -1; j--) {
            sym = towupper(sent[j]);
            len_word = 0;

            if (sent[j] == sym && iswalpha(sent[j]) &&
                (sent[j + 1] == L' ' || sent[j + 1] == L'.' || sent[j + 1] == L',')) {
                int first_sym;
                for (int k = j; k > -1 && sent[k] != L' ' && sent[k] != L'.' && sent[k] != L','; k--) {
                    len_word++;
                    first_sym = k;
                }
                real_size += len_word;
                for (int k = first_sym; k <= wcslen(sent); k++) {
                    if ((k + len_word) <= wcslen(sent)) {

                        sent[k] = sent[k + len_word];
                    } else {
                        sent[k] = ' ';
                    }
                }
            }
        }
        DoublePointDelete(sent);
        if (sent[wcslen(sent) - 2] == ' ') {
            sent[wcslen(sent) - 2] = sent[wcslen(sent) - 1];
            sent[wcslen(sent) - 1] = ' ';
        }

        if (wcscasecmp(sent, L".") == 0 || wcscasecmp(sent, L". ") == 0
                ) {
            pr_text.text[i]->zero_sent = 0;
        }
    }

    print_text(pr_text);
    wprintf(L"\n");
}

//кол-во слов опред. длины
void WordLensCount(struct Text pr_text) {
    int read_size = 0, max_size = 0;

    //Поиск наибольшей длины слова
    for (int i = 0; i < pr_text.sent_count; i++) {
        wchar_t *sent = pr_text.text[i]->Sent;
        for (int j = 0; j < wcslen(sent); j++) {
            if (sent[j] != L' ' && sent[j] != L'.' && sent[j] != L'(' && sent[j] != L')') {
                read_size++;
            } else {
                if (read_size > max_size) {
                    max_size = read_size;
                }
                read_size = 0;
            }

        }
    }

    int *counts = calloc(max_size + 1, sizeof(int));

    //запись длин слов
    for (int i = 0; i < pr_text.sent_count; i++) {
        wchar_t *sent = pr_text.text[i]->Sent;
        for (int j = 0; j < wcslen(sent); j++) {
            if (sent[j] != L' ' && sent[j] != L'.' && sent[j] != L'(' && sent[j] != L')') {
                read_size++;
            } else {
                counts[read_size] += 1;
                read_size = 0;
            }

        }
    }

    for (int i = 1; i < max_size + 1; i++) {
        if (counts[i] != 0) {
            wprintf(L"Слов размером %d: %d\n", i, counts[i]);
        }
    }
    free(counts);
}
