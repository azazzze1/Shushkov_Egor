#ifndef RULE_SPAWN_PLAYER_H
#define RULE_SPAWN_PLAYER_H

#include "../Field.h"
#include "../../Player/Player.h"

template<int y = 0, int x = 0>
class RuleSpawnPlayer{
public:
    void operator ()(Field* field, Player* player){
        if(field->GetCell(y,x)->ShowPassable())
            field->ChangePlayersCoords(y,x);
        else
            for(int i = 0; i < field->ShowWidth(); ++i)
                if(field->GetCell(y,(x+i)%field->ShowWidth())->ShowPassable()){
                    field->ChangePlayersCoords(y,(x+i)%field->ShowWidth());
                    break;
                }
    }
};

#endif
