#include "Decorator.h"

Decorator::Decorator(IObserver *obs): CurObserver(obs) {}

void Decorator::update(Report &msg){
    CurObserver->update(msg);
}

std::ostream &Decorator::Output(std::ostream &out) {
    return out;
}