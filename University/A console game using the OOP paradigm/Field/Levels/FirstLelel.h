#ifndef OOP_CMAKE_FIRSTLELEL_H
#define OOP_CMAKE_FIRSTLELEL_H

#include "../level.h"
#include "../../Player/Player.h"
#include <list>



class FirstLevel : public Level{
public:
    FirstLevel(Player* player): CurPlayer(player){}

    Field* GenerateLevel() override{
        FieldGenerator <RuleFieldSize<10,10>,
                RuleSpawnPlayer<0,0>,
                RuleSpawnKey<0,9>,
                RuleSpawnChest<9,9>,
                RuleSpawnStones<1>,
                RuleMoveEnergy<1>> build;
        return build.fill(CurPlayer);
    }

private:
    Player* CurPlayer;
};


#endif