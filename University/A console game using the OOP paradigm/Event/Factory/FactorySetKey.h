#ifndef FACTORY_SET_KEY_H
#define FACTORY_SET_KEY_H
#include "FactoryFieldEvent.h"
#include "../FieldEvent/SetKey.h"

class FactorySetKey : public FactoryFieldEvent{
public:
    FactorySetKey(Field* StartField): FactoryFieldEvent(StartField) {}

    Event* CreateEvent() override {return new SetKey(CurField);}
};
#endif
