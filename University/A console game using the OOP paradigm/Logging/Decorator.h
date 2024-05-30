#ifndef OOP_CMAKE_DECORATOR_H
#define OOP_CMAKE_DECORATOR_H
#include "Observer.h"

class Decorator : public IObserver{
protected:
    IObserver* CurObserver;
public:
    Decorator(IObserver* obs);
    std::ostream& Output(std::ostream& out) override;
    void update(Report& msg) override;
};


#endif
