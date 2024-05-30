#ifndef FACTORY_GET_EXIT_H
#define FACTORY_GET_EXIT_H
#include "FactoryPlayerEvent.h"
#include "../PlayerEvent /GetExit.h"


class FactoryGetExit : public FactoryPlayerEvent{
public:
    FactoryGetExit(Field* StartField, Player* StartPlayer): FactoryPlayerEvent(StartField,StartPlayer){}

    Event* CreateEvent() override{return new GetExit(CurField,CurPlayer);}
};

#endif