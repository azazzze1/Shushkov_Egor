#ifndef COMAND_CONTROLLER_H
#define COMAND_CONTROLLER_H

#include "../Mediator/MediatorObj.h"
#include "../Field/Field.h"
#include "../Input-Output/FieldView.h"
#include "../Support/Enum.h"
#include "../Input-Output/PlayerStatsView.h"
#include "../Event/FactoryController.h"
#include "../Input-Output/StoneCountView.h"
#include "../Logging/LogLVL/LogFacade.h"
#include "../Save/Memento/MementoManager.h"
#include "../Field/LevelManager.h"


class ComandController : public MediatorObj{
private:
    FactoryController factory_controller;
    Field CurField;
    Player CurPlayer;

    StoneCountView stoneCountView;
    FieldView viewer;
    PlayerStatsView PlayerViewer;

    IObserver* CurLogStats;
    IObserver* CurLogError;

    MementoManager* CurMementoManager;
    LevelManager* CurLevelManager;

public:
    ComandController(IObserver* StartLogStats, IObserver* StartLogError);

    void setMediator(Mediator* med);
    void ViewField();
    void MovePlayer(Enum::Direction dir);
    void CreateStandartSizeField();
    void CreateCustomField(int heigth, int width);
    void CreateLevelField(int LVL);
    void Dig(Enum::Direction dir);
    void CheckGameEnd();
    void ClearConsole();

    void Save();
    void Load();
};

#endif