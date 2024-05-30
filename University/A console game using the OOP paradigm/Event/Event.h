#ifndef EVENT_H
#define EVENT_H

#include "../Field/Field.h"
#include "../Player/Player.h"
#include <list>

class Cell;
class Field;

class Event{
public:
    virtual void trigger() = 0;
};


#endif