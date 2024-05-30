#ifndef FACTORY_OPEN_CHEST_H
#define FACTORY_OPEN_CHEST_H
#include "FactoryPlayerEvent.h"
#include "../PlayerEvent /OpenChest.h"

class FactoryOpenChest : public FactoryPlayerEvent{
public:
    FactoryOpenChest(Field* StartField, Player* StartPlayer): FactoryPlayerEvent(StartField,StartPlayer) {}

    Event* CreateEvent() override {return new OpenChest(CurField,CurPlayer);}
};
#endif
