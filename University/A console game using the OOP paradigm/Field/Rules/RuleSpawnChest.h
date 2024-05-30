#ifndef OOP_CMAKE_RULECHESTSPAWN_H
#define OOP_CMAKE_RULECHESTSPAWN_H

#include "../Field.h"
#include "../../Event/PlayerEvent /OpenChest.h"
#include "../../Player/Player.h"


template<int y = 0, int x = 2>
class RuleSpawnChest{
public:
    void operator()(Field* field, Player* player){
        if(y<field->ShowHeight() && x<field->ShowWidth()){
            field->GetCell(y,x)->ChangeCellType(new CellTypeChest());
            field->GetCell(y,x)->ChangeEvent(new OpenChest(field, player));
        }else{
            Coords PlayerCoords = field->ShowPlayerCoords();
            int x_close=PlayerCoords.xCoord, y_close=PlayerCoords.yCoord;
            if(x_close + 1 < field->ShowWidth() && field->GetCell(y_close, x_close+1)->ShowPassable())
                x_close++;
            else if(x_close - 1 >= 0  && field->GetCell(y_close, x_close-1)->ShowPassable())
                x_close--;
            else if(y_close + 1 < field -> ShowHeight() && field->GetCell(y_close+1, x_close)->ShowPassable())
                y_close++;
            else if(y_close - 1 >= 0  && field->GetCell(y_close-1, x_close)->ShowPassable())
                y_close--;

            field->GetCell(y_close,x_close)->ChangeCellType(new CellTypeChest());
            field->GetCell(y_close,x_close)->ChangeEvent(new OpenChest(field, player));
        }
    }
};

#endif
