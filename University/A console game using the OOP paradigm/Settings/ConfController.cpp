#include "ConfController.h"

ConfController::ConfController(){
    std::cout<<"\033c";
    std::cout<<"Перед началом игры выбирете, откуда хотите получить управление:\n";
    std::cout<<"\t1. Ввод из файла конфигурации\n";
    int c = -1;
    while(c<0){
        std::cin>>c;
        switch(c){
        case 1:
            CurConfReader = new ReadConfFile();
            break;
        default:
            c = -1;
            break;
        }
    }
    std::cout<<"\033c";
    std::cout<<"Выберите способ управления игрой:\n";
    std::cout<<"\t1. Ввод в консоль\n";
    c = -1;
    while(c<0){
        std::cin>>c;
        switch(c){
            case 1:
                CurGameManagement = new ConsoleManagement();
                break;
            default:
                c = -1;
                break;
        }
    }
    std::cout<<"\033c";
}

void ConfController::get_conf(){
    ConfMap = CurConfReader -> get_conf();
}

void ConfController::setMediator(Mediator *med) {
    mediator = med;
}

char ConfController::show_char(std::string Command){
    std::string CommandChar = ConfMap[Command];
    return CommandChar[0];
}

void ConfController::Read(){
    mediator -> ShortCommandNotify(this, CurGameManagement->read());
}

void ConfController::ReadStartField(){
    mediator -> FieldSizeNotify(this, CurGameManagement->readStartField());
}

void ConfController::CoutInfoAboutKeys() {
    std::cout<<"Управление:\n";
    std::cout<<"\tПередвижение: ";
    std::cout<<ConfMap["Move_Direction_Up"]<<ConfMap["Move_Direction_Left"]<<ConfMap["Move_Direction_Down"]<<ConfMap["Move_Direction_Right"]<<std::endl;
    std::cout<<"\tКопание камня: ";
    std::cout<<ConfMap["Dig_Direction_Up"]<<ConfMap["Dig_Direction_Left"]<<ConfMap["Dig_Direction_Down"]<<ConfMap["Dig_Direction_Right"]<<std::endl;
    std::cout<<"\t"<<ConfMap["Close_Game"];
    std::cout<<" - выход\n";
    std::cout<<'\n';
}