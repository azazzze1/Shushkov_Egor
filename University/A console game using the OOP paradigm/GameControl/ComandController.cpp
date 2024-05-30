#include "ComandController.h"

ComandController::ComandController(IObserver* StartLogStats, IObserver* StartLogError): factory_controller(&CurField, &CurPlayer,StartLogStats){
    CurPlayer.addObserver(StartLogStats);
    CurLogStats = StartLogStats;
    CurLogError = StartLogError;
    CurMementoManager = new MementoManager(&CurPlayer, &CurField);
}

void ComandController::setMediator(Mediator* med){
    mediator = med;
}

void ComandController::ViewField(){
    PlayerViewer.PlayerView(CurPlayer);
    viewer.DrawField(CurField);
    stoneCountView.ViewStoneCount(factory_controller);
}

void ComandController::MovePlayer(Enum::Direction dir){
    CurField.PlayersMove(dir);
}

void ComandController::CreateLevelField(int LVL){
    CurLevelManager = new LevelManager(LVL, &CurPlayer);
    CurField = *(CurLevelManager->GetField());
    factory_controller.EventsDistribution();
    CurField.addObserver(CurLogStats);
    CurField.addObserver(CurLogError);
}

void ComandController::CreateStandartSizeField(){
    CurField = Field();
    CurField.addObserver(CurLogStats);
    CurField.addObserver(CurLogError);
    factory_controller.StartFieldEvents();
}

void ComandController::CreateCustomField(int heigth, int width){
    CurField = Field(heigth, width);
    CurField.addObserver(CurLogStats);
    CurField.addObserver(CurLogError);
    factory_controller.StartFieldEvents();
}

void ComandController::Dig(Enum::Direction dir){
    if(CurField.Dig(dir, CurPlayer.ShowPickaxePower()))
        factory_controller.ReduceStone();
    if(factory_controller.ShowStoneCount() == 0)
        factory_controller.EndGameSetUp();
}

void ComandController::CheckGameEnd() {
    if(CurPlayer.ShowHealth() <= 0)
        mediator -> LargeCommandNotify(this, "GameOver with energy");
    if(CurPlayer.ShowReadyToGo())
        mediator -> LargeCommandNotify(this, "Win");
}

void ComandController::ClearConsole() {
    std::cout<<"\033c";
}

void ComandController::Save(){
    CurMementoManager->save(CurPlayer.save());
    CurMementoManager->save(CurField.save());
}

void ComandController::Load(){
    CurMementoManager->restore();
    factory_controller.EventsDistributionIC();
}