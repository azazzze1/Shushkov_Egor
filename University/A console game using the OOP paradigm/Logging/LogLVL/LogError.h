#ifndef LOGERROR_H
#define LOGERROR_H
#include "../Observer.h"

class LogError : public IObserver{
private:
    IObservable* product;
public:
    LogError() {}

    friend std::ostream& operator <<(std::ostream& out, const LogError& logError);
    std::ostream &Output(std::ostream &out) override;
    void update(Report &msg) override;
};
#endif
