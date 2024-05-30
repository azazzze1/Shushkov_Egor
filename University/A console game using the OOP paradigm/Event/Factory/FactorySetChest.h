#ifndef FACTORY_SET_CHEST_H
#define FACTORY_SET_CHEST_H
#include "FactoryFieldEvent.h"
#include "../FieldEvent/SetChest.h"

class FactorySetChest : public FactoryFieldEvent{
public:
    FactorySetChest(Field* StartField): FactoryFieldEvent(StartField) {}

    Event* CreateEvent() override {return new SetChest(CurField);}
};
#endif