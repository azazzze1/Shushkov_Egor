#ifndef FIELD_EVENT_H
#define FIELD_EVENT_H
#include "../Event.h"

class FieldEvent : public Event{
protected:
    std::list<Cell*> ChangeCellList;
    Field* CurField;
public:
    virtual void trigger() = 0;
};


#endif
