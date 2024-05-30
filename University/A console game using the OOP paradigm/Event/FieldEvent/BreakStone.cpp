#include "BreakStone.h"

BreakStone::BreakStone(Field* StartField, Cell* CurCell){
    CurField = StartField;
    ChangeCellList.push_back(CurCell);
}

void BreakStone::trigger(){
    for(Cell* elem : ChangeCellList){
        elem->ChangeCellType(new CellTypeLand());
        elem->ChangeEvent(nullptr);
    }
}