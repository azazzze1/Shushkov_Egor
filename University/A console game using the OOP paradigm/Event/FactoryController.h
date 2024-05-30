#ifndef FACTORY_CONTROLLER_H
#define FACTORY_CONTROLLER_H

#include "Factory/Factory.h"
#include "Factory/FactoryCaveCollaps.h"
#include "Factory/FactorySetChest.h"
#include "Factory/FactorySetKey.h"
#include "Factory/FactoryGetKey.h"
#include "Factory/FactoryOpenChest.h"
#include "Factory/FactoryEnergyMove.h"
#include "Factory/FactorySetExit.h"
#include "Factory/FactoryGetExit.h"
#include "../Logging/Observer.h"

class FactoryController : public IObservable{
private:
    std::vector<IObserver*> observers;
    Field* CurField;
    Player* CurPlayer;
    Event* CurEvent;
    Factory* CurFactory;
    int StoneCount;
public:
    FactoryController(Field* StartField, Player* StartPlayer, IObserver* StartObs = nullptr): CurField(StartField), CurPlayer(StartPlayer){
        addObserver(StartObs);
    }

    void addObserver(IObserver* obs) override;
    void removeObserver(IObserver* obs) override;
    void notify(Report& msg) override;

    void EventsDistribution();
    void EventsDistributionIC();
    void StartFieldEvents();

    int ShowStoneCount();
    void ReduceStone();

    void EndGameSetUp();

    Event* CreateEventOpenChest();
    Event* CreateEventSetKey();
    Event* CreateEventSetChest();
    Event* CreateEventCaveCollaps();
    Event* CreateEventGetKey();
    Event* CreateEventEnergyMove();
    Event* CreateEventSetExit();
    Event* CreateEventGetExit();
};


#endif
