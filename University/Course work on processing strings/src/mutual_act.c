#include "main.h"

void Comand(){
    wprintf(L"Выберите команду, которую хотите выполнить:\n");
    wprintf(L"1. Сделать сдвиг слов в предложении на положительное целое число N.\n");
    wprintf(L"2. Вывести все уникальные кириллические и латинские символы в тексте.\n");
    wprintf(L"3. Удалить все слова которые заканчиваются на заглавный символ.\n");
    wprintf(L"4. Подсчитать и вывести количество слов (плюс слова в скобках), длина которых равна 1, 2, 3 и т.д.\n");
    wprintf(L"Другой символ. Выход из программы.\n\n");
}

void Free_Mem(struct Sentence** txt, int num){
    for(int i=0;i<=num;i++){
        free(txt[i]);
    }
    free(txt);
}

void print_text(struct Text txt){
    for(int i=0; i<txt.sent_count; i++){
        if(txt.text[i]->zero_sent==1){
            for(int j=0; j<wcslen(txt.text[i]->Sent); j++){
                wprintf(L"%lc", txt.text[i]->Sent[j]);
            }
        }
    }
}

wchar_t* DoublePointDelete(wchar_t* sent){
    for(int k=0;k< wcslen(sent);k++){
        if(sent[k]==' ' && sent[k+1]==' '){
            for(int q=k+1;q<wcslen(sent);q++){
                sent[q]=sent[q+1];
            }
            k--;
        }
    }
}