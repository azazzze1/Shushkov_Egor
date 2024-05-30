#ifndef OOP_CMAKE_LEVELMANAGER_H
#define OOP_CMAKE_LEVELMANAGER_H

#include "Levels/FirstLelel.h"
#include "Levels/SecondLevel.h"

class LevelManager{
public:
    LevelManager(int num, Player* player){
        Level* CurLevel;
        if(num == 1)
            CurLevel = new FirstLevel(player);
        else
            CurLevel = new SecondLevel(player);
        CurField = CurLevel -> GenerateLevel();
        delete CurLevel;
    }

    Field* GetField() const {return CurField;}

private:
    Field* CurField;
};

#endif
