#ifndef OOP_CMAKE_FACTORYENERGYMOVE_H
#define OOP_CMAKE_FACTORYENERGYMOVE_H
#include "FactoryPlayerEvent.h"
#include "../PlayerEvent /EnergyMove.h"


class FactoryEnergyMove : public FactoryPlayerEvent{
public:
    FactoryEnergyMove(Field* StartField, Player* StartPlayer): FactoryPlayerEvent(StartField,StartPlayer){}

    Event* CreateEvent() override{return new EnergyMove(CurField,CurPlayer);}
};
#endif
