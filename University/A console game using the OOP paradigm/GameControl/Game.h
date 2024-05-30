#ifndef GAME_H
#define GAME_H
#include "../Mediator/MediatorObj.h"
#include "../Input-Output/ComandReader.h"
#include "../Input-Output/TextOutput.h"
#include "../Logging/Observer.h"

class Game : public MediatorObj, public IObservable{
private:
    std::vector<IObserver*> observers;
    TextOutput text;
    bool GameStatus;
    int StartGameSymbol;

public:
    Game();

    void addObserver(IObserver* obs) override;
    void removeObserver(IObserver* obs) override;
    void notify(Report& msg) override;

    void StartGame(IObserver* obs);
    void QuitGame();
    void setMediator(Mediator* med);
    bool CheckGameStatus();

    void GameOverEnergy();
    void Win();
};

#endif
