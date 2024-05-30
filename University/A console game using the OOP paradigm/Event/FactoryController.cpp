#include "FactoryController.h"

Event* FactoryController::CreateEventOpenChest() {
    CurFactory = new FactoryOpenChest(CurField,CurPlayer);
    return CurFactory->CreateEvent();
}

Event* FactoryController::CreateEventCaveCollaps() {
    CurFactory = new FactoryCaveCollaps(CurField);
    return CurFactory->CreateEvent();
}

Event* FactoryController::CreateEventSetKey() {
    CurFactory = new FactorySetKey(CurField);
    return CurFactory->CreateEvent();
}

Event* FactoryController::CreateEventGetKey() {
    CurFactory = new FactoryGetKey(CurField,CurPlayer);
    return CurFactory->CreateEvent();
}

Event* FactoryController::CreateEventSetChest() {
    CurFactory = new FactorySetChest(CurField);
    return CurFactory->CreateEvent();
}

Event* FactoryController::CreateEventEnergyMove() {
    CurFactory = new FactoryEnergyMove(CurField,CurPlayer);
    return CurFactory->CreateEvent();
}

Event* FactoryController::CreateEventSetExit() {
    CurFactory = new FactorySetExit(CurField);
    return CurFactory->CreateEvent();
}

Event* FactoryController::CreateEventGetExit() {
    CurFactory = new FactoryGetExit(CurField,CurPlayer);
    return CurFactory->CreateEvent();
}

void FactoryController::EventsDistribution() {
    for(int i = 0;i < CurField->ShowHeight(); ++i){
        for(int j = 0;j < CurField->ShowWidth();++j){
            if(auto R = dynamic_cast<CellTypeKey* >(CurField->GetCell(i,j)->ShowCellType())){
                CurField->GetCell(i,j)->ChangeEvent(CreateEventGetKey());
                Report msg = Report(Enum::Logs::STATUS_LOG_EVENT_SET_KEY);
                msg.SetData(i,j);
                notify(msg);
            }
            else if(auto R = dynamic_cast<CellTypeChest* >(CurField->GetCell(i,j)->ShowCellType())){
                CurField->GetCell(i,j)->ChangeEvent(CreateEventOpenChest());
                Report msg = Report(Enum::Logs::STATUS_LOG_EVENT_SET_CHEST);
                msg.SetData(i,j);
                notify(msg);
            }
            else if(auto R = dynamic_cast<CellTypeLand* >(CurField->GetCell(i,j)->ShowCellType()))
                CurField->GetCell(i,j)->ChangeEvent(CreateEventEnergyMove());

            else if(auto R = dynamic_cast<CellTypeStone* >(CurField->GetCell(i,j)->ShowCellType())){
                ++StoneCount;
                Report msg = Report(Enum::Logs::STATUS_LOG_EVENT_SET_STONE);
                msg.SetData(i,j);
                notify(msg);
            }
        }
    }
}

void FactoryController::EventsDistributionIC() {
    StoneCount = 0;
    for(int i = 0;i < CurField->ShowHeight(); ++i){
        for(int j = 0;j < CurField->ShowWidth();++j){
            if(CurField->GetCell(i,j)->ShowCurIcon() == 'F'){
                CurField->GetCell(i,j)->ChangeEvent(CreateEventGetKey());
                CurField->GetCell(i,j)->ChangeCellType(new CellTypeKey);
            }
            else if(CurField->GetCell(i,j)->ShowCurIcon() == '$'){
                CurField->GetCell(i,j)->ChangeEvent(CreateEventOpenChest());
                CurField->GetCell(i,j)->ChangeCellType(new CellTypeChest);
            }
            else if(CurField->GetCell(i,j)->ShowCurIcon() == '.')
                CurField->GetCell(i,j)->ChangeEvent(CreateEventEnergyMove());

            else if(CurField->GetCell(i,j)->ShowCurIcon() == '#'){
                CurField->GetCell(i,j)->ChangeEvent(new BreakStone(CurField, CurField->GetCell(i,j)));
                CurField->GetCell(i,j)->ChangeCellType(new CellTypeStone());
                CurField->GetCell(i,j)->ChangePassToStandart();
                ++StoneCount;
            }
        }
    }
}

void FactoryController::StartFieldEvents() {
    CurEvent = CreateEventSetKey();
    CurEvent->trigger();
    CurEvent = CreateEventCaveCollaps();
    CurEvent->trigger();
    CurEvent = CreateEventSetChest();
    CurEvent->trigger();
    EventsDistribution();
}

int FactoryController::ShowStoneCount(){
    return StoneCount;
}

void FactoryController::ReduceStone(){
    --StoneCount;
}

void FactoryController::EndGameSetUp(){
    CurEvent = CreateEventSetExit();
    CurEvent->trigger();
    CurField->GetCell(CurField->ShowHeight()/2,CurField->ShowWidth()/2)->ChangeEvent(CreateEventGetExit());
}

void FactoryController::addObserver(IObserver *obs) {
    observers.push_back(obs);
}

void FactoryController::removeObserver(IObserver *obs) {
    std::remove(observers.begin(),observers.end(),obs);
}

void FactoryController::notify(Report& msg){
    for(auto obs : observers)
        obs -> update(msg);
}

