#ifndef FACTORY_PLAYER_EVENT_H
#define FACTORY_PLAYER_EVENT_H
#include "Factory.h"

class FactoryPlayerEvent : public Factory {
protected:
    Field* CurField;
    Player* CurPlayer;
public:
    FactoryPlayerEvent(Field* StartField, Player* StartPlayer): CurField(StartField), CurPlayer(StartPlayer) {}

    virtual Event* CreateEvent() = 0;
};
#endif
