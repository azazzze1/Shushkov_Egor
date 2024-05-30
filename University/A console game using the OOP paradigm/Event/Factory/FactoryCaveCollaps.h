#ifndef FACTORY_CAVECOLLAPS_H
#define FACTORY_CAVECOLLAPS_H
#include "FactoryFieldEvent.h"
#include "../FieldEvent/CaveCollaps.h"

class FactoryCaveCollaps : public FactoryFieldEvent{
public:
    FactoryCaveCollaps(Field* StartField): FactoryFieldEvent(StartField) {}

    Event* CreateEvent() override {return new CaveCollaps(CurField);}
};

#endif
