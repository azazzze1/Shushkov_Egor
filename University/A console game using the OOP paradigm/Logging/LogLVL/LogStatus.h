#ifndef LOGSTATUS_H
#define LOGSTATUS_H

#include "../Observer.h"
#include <iostream>

class LogStatus : public IObserver{
private:
    IObservable* product;
public:
    LogStatus() {}
    std::ostream &Output(std::ostream &out) override;
    friend std::ostream& operator <<(std::ostream& out, const LogStatus& logStatus);
    void update(Report &msg) override;
};



#endif
