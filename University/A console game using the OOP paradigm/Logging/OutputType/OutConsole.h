#ifndef OUTCONSOLE_H
#define OUTCONSOLE_H
#include "../Decorator.h"
#include "../LogLVL/LogStatus.h"
#include "../LogLVL/LogGame.h"
#include "../LogLVL/LogError.h"

#include <iostream>

class OutConsole : public Decorator{
public:
    OutConsole(IObserver* obs) : Decorator(obs) {}
    std::ostream& Output(std::ostream& out) override;
    void update(Report& msg) override;
};

#endif
