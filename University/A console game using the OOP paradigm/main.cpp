#include "GameControl/ComandController.h"
#include "Input-Output/ComandReader.h"
#include "Mediator/MediatorController.h"
#include "Event/Event.h"
#include "Logging/LogLVL/LogFacade.h"
#include "Settings/ConfController.h"



int main(){
    LogFacade* logFacade = new LogFacade;
    ComandReader* comandReader = new ComandReader();
    ComandController* comandController = new ComandController(logFacade->GetCurLogStatus(),logFacade->GetCurLogError());
    Game* game = new Game();
    ConfController* ConfContr = new ConfController();
    MediatorController* mediator = new MediatorController(comandReader, comandController, game, ConfContr);

    game->StartGame(logFacade->GetCurLogGame());


    comandController -> ClearConsole();
    comandController -> ViewField();


    while(game->CheckGameStatus()){
        comandReader -> Read();
        comandController -> ViewField();
        comandController -> CheckGameEnd();
    }

    delete comandReader;
    delete comandController;
    delete game;
    delete mediator;
    return 0;
}