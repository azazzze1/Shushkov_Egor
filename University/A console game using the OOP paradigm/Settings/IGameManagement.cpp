#include "IGameManagement.h"

char ConsoleManagement::read(){
    char MoveSymbol;
    std::cin>>MoveSymbol;
    std::cout<<"\033c";
    return MoveSymbol;
}

std::pair<int,int> ConsoleManagement::readStartField() {
    std::pair<int,int> FieldSize;
    std::cin>>FieldSize.first;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Вы ввели не число! Введите другие значения!\n";
        readStartField();
    }
    std::cin>>FieldSize.second;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Вы ввели не число! Введите другие значения!\n";
        readStartField();
    }
    return FieldSize;
}