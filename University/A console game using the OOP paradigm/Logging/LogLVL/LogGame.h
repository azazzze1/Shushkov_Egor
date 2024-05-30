#ifndef LOGGAME_H
#define LOGGAME_H
#include "../Observer.h"

class LogGame : public IObserver{
private:
    IObservable* product;
public:
    LogGame() {}

    std::ostream &Output(std::ostream &out) override;
    friend std::ostream& operator <<(std::ostream& out, const LogGame& logStatus);
    void update(Report &msg) override;
};


#endif
