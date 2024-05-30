#ifndef OBSERVER_H
#define OBSERVER_H

#include "Report.h"

class IObserver{
protected:
    Report* CurMsg;
public:
    virtual void update(Report& msg) { return; }
    virtual std::ostream& Output(std::ostream& out) {return out; };
};

class IObservable{
public:
    virtual void addObserver(IObserver* obs) = 0;
    virtual void removeObserver(IObserver* obs) = 0;
    virtual void notify(Report& msg) = 0;
    virtual ~IObservable() {}
};

#endif
