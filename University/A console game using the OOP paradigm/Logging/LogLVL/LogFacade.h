#ifndef LOGFACADE_H
#define LOGFACADE_H
#include "LogStatus.h"
#include "LogGame.h"
#include "LogError.h"
#include "../OutputType/OutConsole.h"
#include "../OutputType/OutFile.h"

#include "../../Input-Output/TextOutput.h"
#include <string>

class LogFacade {
private:
    IObserver* CurLogStatus;
    IObserver* CurLogGame;
    IObserver* CurLogError;
    std::string LogOutChoose;
public:
    LogFacade();
    IObserver* GetCurLogStatus();
    IObserver* GetCurLogGame();
    IObserver* GetCurLogError();
};


#endif
