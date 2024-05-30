#ifndef RULE_SPAWN_KEY_H
#define RULE_SPAWN_KEY_H
#include "../Field.h"
#include "../../Event/PlayerEvent /GetKey.h"
#include "../../Player/Player.h"
#include <cmath>

template<int y = 0, int x = 1>
class RuleSpawnKey{
public:
    void operator()(Field* field, Player* player){
        if(y<field->ShowHeight() && x<field->ShowWidth()){
            field->GetCell(y,x)->ChangeEvent(new GetKey(field,player));
            field->GetCell(y,x)->ChangeCellType(new CellTypeKey);
        }else{
            Coords PlayerCoords = field->ShowPlayerCoords();
            int dist = 0, x_far, y_far;
            for(int i = 0; i < field->ShowHeight(); ++i)
                for(int j = 0; j < field->ShowWidth(); ++j)
                    if(sqrt(pow(j - PlayerCoords.xCoord,2) + pow(i - PlayerCoords.yCoord, 2))>dist){
                        x_far = j; y_far = i; dist = sqrt(pow(j - PlayerCoords.xCoord,2) + pow(i - PlayerCoords.yCoord, 2));
                    }
            field->GetCell(y_far,x_far)->ChangeEvent(new GetKey(field,player));
            field->GetCell(y_far,x_far)->ChangeCellType(new CellTypeKey);
        }
    }
};
#endif