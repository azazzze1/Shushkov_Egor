#include "CaveCollaps.h"

CaveCollaps::CaveCollaps(Field* StartField){
    CurField = StartField;
    srand(time(NULL));

        for(int i = 0; i < rand() % (CurField->ShowHeight() * CurField->ShowWidth() / 4) + 2;++i){
            int rand_height = rand() % CurField->ShowHeight();
            int rand_width = rand() % CurField->ShowWidth();
            if(auto R = dynamic_cast<CellTypeLand*> (CurField->ShowCurField()[rand_height][rand_width].ShowCellType())
                        && CurField -> ShowPlayerCoords().xCoord != rand_width
                        && CurField -> ShowPlayerCoords().yCoord != rand_height){
                Cell* Test = CurField->GetCell(rand_height,rand_width);
                ChangeCellList.push_back(Test);
            }
        }
}

void CaveCollaps::trigger() {
    for (Cell* CellElem : ChangeCellList){
        CellElem -> ChangeCellType(new CellTypeStone());
        CellElem -> ChangeEvent(new BreakStone(CurField,CellElem));
    }
}