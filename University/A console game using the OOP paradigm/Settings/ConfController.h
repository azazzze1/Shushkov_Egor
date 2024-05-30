#ifndef CONFCONTROLLER_H
#define CONFCONTROLLER_H

#include "IConfig.h"
#include "../Mediator/MediatorObj.h"
#include "IGameManagement.h"


class ConfController : public MediatorObj{
private:
    IConfig* CurConfReader;
    IGameManagement* CurGameManagement;
    std::map<std::string, std::string>  ConfMap;

public:
    ConfController();
    void setMediator(Mediator* med);
    void get_conf();

    void Read();
    void ReadStartField();

    void CoutInfoAboutKeys();
    char show_char(std::string Command);
};


#endif
