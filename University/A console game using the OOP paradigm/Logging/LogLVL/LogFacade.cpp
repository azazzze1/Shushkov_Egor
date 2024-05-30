#include "LogFacade.h"

LogFacade::LogFacade() {
    CurLogStatus = new IObserver;
    CurLogGame = new IObserver;
    CurLogError = new IObserver;

    TextOutput text;
    text.FacadeLogCont();

    std::getline(std::cin,LogOutChoose);
    for(char c : LogOutChoose){
        switch(c){
            case '1':
                delete CurLogStatus;
                CurLogStatus = new LogStatus;
                break;
            case '2':
                delete CurLogGame;
                CurLogGame = new LogGame;
                break;
            case '3':
                delete CurLogError;
                CurLogError = new LogError;
                break;
        }
    }
    std::cout<<"\033c";

    text.FacadeLogStart();
    std::getline(std::cin,LogOutChoose);
    for(char c : LogOutChoose){
        switch(c){
            case '1':
                CurLogError = new OutConsole(CurLogError);
                CurLogStatus = new OutConsole(CurLogStatus);
                CurLogGame = new OutConsole(CurLogGame);
                break;
            case '2':
                CurLogError = new OutFile(CurLogError);
                CurLogStatus = new OutFile(CurLogStatus);
                CurLogGame = new OutFile(CurLogGame);
                break;
        }
    }
    std::cout<<"\033c";
}

IObserver *LogFacade::GetCurLogStatus() {
    return CurLogStatus;
}

IObserver *LogFacade::GetCurLogGame() {
    return CurLogGame;
}

IObserver *LogFacade::GetCurLogError() {
    return CurLogError;
}