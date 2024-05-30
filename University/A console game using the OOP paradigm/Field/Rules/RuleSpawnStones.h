#ifndef OOP_CMAKE_RULESPAWNSTONES_H
#define OOP_CMAKE_RULESPAWNSTONES_H

#include "../Field.h"
#include "../../Player/Player.h"
#include "../../Event/PlayerEvent /EnergyMove.h"
#include "../../Event/FieldEvent/CaveCollaps.h"

template<int ColapsSize = 1>
class RuleSpawnStones{
public:
    void operator ()(Field* field, Player* player){
        CaveCollaps* CurCaveCollaps = new CaveCollaps(field);
        for(int i = 0; i < ColapsSize;++i){
            srand(time(NULL));
            CurCaveCollaps->trigger();
            CurCaveCollaps = new CaveCollaps(field);
        }

    }
};

#endif
