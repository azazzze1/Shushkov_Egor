#include "Game.h"
Game::Game(): GameStatus(true){}

void Game::StartGame(IObserver* obs){
    addObserver(obs);
    text.StartText1();
    mediator -> LargeCommandNotify(this, "ShowKeysInfo");
    text.StartText2();

    std::cin>>StartGameSymbol;

    Report msg = Report(Enum::Logs::GAME_START);
    msg.SetData(false);
    notify(msg);

    mediator->ShortIntCommandNotify(this, StartGameSymbol);
}

void Game::setMediator(Mediator* med){
     mediator = med;
}

void Game::QuitGame(){
    Report msg = Report(Enum::Logs::GAME_EXIT);
    notify(msg);
    GameStatus = false;
}

bool Game::CheckGameStatus(){
    return GameStatus;
}

void Game::GameOverEnergy(){
    Report msg = Report(Enum::Logs::GAME_OVER_ENERGY);
    notify(msg);
    text.GameOverEnergy();
    QuitGame();
}

void Game::Win() {
    Report msg = Report(Enum::Logs::GAME_VICTORY);
    notify(msg);
    text.Win();
    QuitGame();
}

void Game::addObserver(IObserver *obs) {
    observers.push_back(obs);
}

void Game::removeObserver(IObserver *obs) {
    std::remove(observers.begin(),observers.end(),obs);
}

void Game::notify(Report& msg){
    for(auto obs : observers)
        obs -> update(msg);
}