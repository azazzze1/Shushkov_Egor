#ifndef FACTORY_SET_EXIT_H
#define FACTORY_SET_EXIT_H
#include "FactoryFieldEvent.h"
#include "../FieldEvent/SetExit.h"

class FactorySetExit : public FactoryFieldEvent{
public:
    FactorySetExit(Field* StartField): FactoryFieldEvent(StartField) {}

    Event* CreateEvent() override {return new SetExit(CurField);}
};
#endif