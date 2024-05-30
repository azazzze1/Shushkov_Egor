#include "main.h"
#include "mutual_act.h"

//Проверка на равенство предложений(возвращает 1, если одинаковые. Разные - 0)
int str_is_equal(wchar_t* str_1, wchar_t* str_2)
{
    if(wcslen(str_1)==wcslen(str_2)){
        for(int i=0; i<wcslen(str_1);i++){
            if(towlower(str_1[i])!=towlower(str_2[i])) return 0;
        }
    } else return 0;
    return 1;

}

//чтение предложения
struct Sentence* SentRead(){

    int size = MEM_STEP;
    int num = 0;
    wchar_t sym;
    wchar_t* sent = malloc(size*sizeof(wchar_t));
    if(sent==NULL){
        wprintf(L"Компьютер не смог выделить память!");
        return 0;
    }

    while(sym!=L'.' && sym!=L'\n'){
        sym=getwchar();
        sent[num++]=sym;

        if(num==size-1){
            size+=MEM_STEP;
            sent=realloc(sent,size*sizeof(wchar_t));
            if(sent==NULL){
                free(sent);
                wprintf(L"Компьютер не смог выделить память!");
                return 0;
            }
        }
    }
    sent[num]=L'\0';
    struct Sentence* sentence = malloc(sizeof(struct Sentence));
    if(sentence==NULL){
        wprintf(L"Компьютер не смог выделить память!");
        free(sent);
        return 0;
    }
    sentence->Sent = sent;
    sentence->size = num;
    sentence->zero_sent=1;
    return sentence;

}

//чтение текста
struct Text TextRead(){
    int size = MEM_STEP;
    struct Sentence** Text=malloc(size*sizeof(struct Sentece*));

    if(Text==NULL){
        wprintf(L"Компьютер не смог выделить память!");
        struct Text txtx;
        txtx.sent_count=-1;
        return txtx;
    }

    int num=0, replay_signal=0;
    struct Sentence* sent;
    while(1){
        sent = SentRead();
        if(sent==0){
            wprintf(L"Компьютер не смог выделить память!");
            Free_Mem(Text,num);
            struct Text txtx;
            txtx.sent_count=-1;
            return txtx;
        }

        if(sent->Sent[0]==L'\n'){
            break;
        }

        for(int i=0;i<num;i++){
            if(str_is_equal(Text[i]->Sent, sent->Sent)==1){
                replay_signal++;
            }
        }

        if(replay_signal==0){
            Text[num]=sent;
            num++;
        }else{
            replay_signal=0;
        }

        if(num==size-1){
            size+=MEM_STEP;
            Text=realloc(Text,size*sizeof(struct Sentence*));
            if(Text==NULL){
                wprintf(L"Компьютер не смог выделить память!");
                Free_Mem(Text,num);
                struct Text txtx;
                txtx.sent_count=-1;
                return txtx;
            }
        }
    }
    struct Text txt;
    txt.text = Text;
    txt.sent_count=num;
    txt.size = size;
    return txt;

}