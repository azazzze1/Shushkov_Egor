#include "main.h"
#include "read_text.h"
#include "mutual_act.h"
#include "tasks.h"
//dsl sds 21.
int main() {
    //установка языка системы
    setlocale(LC_ALL, "");
    int break_point = 1;
    struct Text txt0;
    wprintf(L"Здравствуйте, вас приветствует программа для обработки текста!\n");
    wprintf(L"Сейчас вам предложат ввести текст с клавиатуры.\n");
    wprintf(L"Предложения нужно разделять точкой и одним пробелом. Ввод текста завершится после переноса строки.\n");
    wprintf(L"<-------------------------------------------------------------------------------------------------------------------->\n");
    wprintf(L"Введите свой текст:\n");
    txt0 = TextRead();
    if (txt0.sent_count == -1) {
        return 0;
    }
    wprintf(L"<-------------------------------------------------------------------------------------------------------------------->\n");
    wprintf(L"Ваш текст без повторных предложений:\n");
    print_text(txt0);
    wprintf(L"\n");
    while (break_point != 100) {
        wprintf(L"<-------------------------------------------------------------------------------------------------------------------->\n");
        Comand();
        int sym = 'x';
        wscanf(L"%d", &sym);

        wprintf(L"<-------------------------------------------------------------------------------------------------------------------->\n");
        int num, N;
        switch (sym) {
            case 1:
                wprintf(L"Введите номер предложения:\n");
                wscanf(L"%ld", &num);
                if(num<txt0.sent_count){
                    if (num == 1) {
                        num = 0;
                    }
                    wprintf(L"Введите, на сколько позиций хотите сдвинуть предложение:\n");
                    wscanf(L"%d", &N);
                    wprintf(L"Предложение со сдвигом:\n");
                    WordShift(txt0.text[num]->Sent, N);
                    wprintf(L"\n");
                }else{
                    wprintf(L"Предложения с таким номером не существует!\n");
                }
                break;
            case 2:
                UniqueSymbols(txt0);
                break;
            case 3:
                wprintf(L"Обработанный текст:\n");
                RemovingLastUpper(txt0);
                break;
            case 4:
                wprintf(L"Количество слов с определённой длинной:\n");
                WordLensCount(txt0);
                break;
            default:
                Free_Mem(txt0.text, txt0.sent_count);
                wprintf(L"Приятного дня!\n");
                break_point = 100;
        }
    }
    return 0;
}

