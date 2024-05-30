#include "SetChest.h"

SetChest::SetChest(Field* StartField, int height, int width) {
    CurField = StartField;
    while(true){
        if((height == -1 && width == -1) || (height<CurField->ShowHeight() && width<CurField->ShowWidth())){
            height = rand() % CurField->ShowHeight();
            width = rand() % CurField->ShowWidth();
        }
        
        if(auto R = dynamic_cast<CellTypeLand*> (CurField->ShowCurField()[height][width].ShowCellType())
                    && CurField -> ShowPlayerCoords().xCoord != width
                    && CurField -> ShowPlayerCoords().yCoord != height){
            Cell* Test = CurField->GetCell(height,width);
            ChangeCellList.push_back(Test);
            break;
        }
    }
}

void SetChest::trigger() {
    for(Cell* elem : ChangeCellList){
        elem->ChangeCellType(new CellTypeChest());
    }




}