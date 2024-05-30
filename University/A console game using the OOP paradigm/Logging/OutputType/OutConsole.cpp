#include "OutConsole.h"

void OutConsole::update(Report& msg){
    Decorator::update(msg);
    Output(std::cout);
}

std::ostream &OutConsole::Output(std::ostream &out) {
    return CurObserver->Output(out);
}