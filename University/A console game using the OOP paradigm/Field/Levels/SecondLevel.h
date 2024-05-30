#ifndef OOP_CMAKE_SECONDLEVEL_H
#define OOP_CMAKE_SECONDLEVEL_H

#include "../level.h"
#include "../../Player/Player.h"
#include <iostream>
#include <list>


class SecondLevel : public Level{
public:
    SecondLevel(Player* player): CurPlayer(player){}

    Field* GenerateLevel() override{
        FieldGenerator <RuleFieldSize<15,15>,
                RuleSpawnPlayer<7,7>,
                RuleSpawnKey<0,1>,
                RuleSpawnChest<7,8>,
                RuleSpawnStones<10>,
                RuleMoveEnergy<3>> build;

        return build.fill(CurPlayer);
    }


private:
    Player* CurPlayer;
};



#endif //OOP_CMAKE_SECONDLEVEL_H
