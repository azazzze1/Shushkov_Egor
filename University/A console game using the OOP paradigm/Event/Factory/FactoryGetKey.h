#ifndef FACTORY_GET_KEY_H
#define FACTORY_GET_KEY_H
#include "FactoryPlayerEvent.h"
#include "../PlayerEvent /GetKey.h"


class FactoryGetKey : public FactoryPlayerEvent{
public:
    FactoryGetKey(Field* StartField, Player* StartPlayer): FactoryPlayerEvent(StartField,StartPlayer){}

    Event* CreateEvent() override{return new GetKey(CurField,CurPlayer);}
};

#endif
