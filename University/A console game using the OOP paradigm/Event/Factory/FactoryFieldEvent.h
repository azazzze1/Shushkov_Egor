#ifndef FACTORY_FIELD_EVENT_H
#define FACTORY_FIELD_EVENT_H
#include "Factory.h"

class FactoryFieldEvent : public Factory{
protected:
    Field* CurField;
public:
    FactoryFieldEvent(Field* StartField): CurField(StartField) {}

    virtual Event* CreateEvent() = 0;
};


#endif
