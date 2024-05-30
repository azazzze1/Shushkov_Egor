#include "SetExit.h"

SetExit::SetExit(Field *StartField) {
    srand(time(NULL));
    CurField = StartField;
    Cell* Test = CurField->GetCell(CurField->ShowHeight() / 2,CurField->ShowWidth() / 2);
    ChangeCellList.push_back(Test);
}

void SetExit::trigger(){
    for(Cell* elem : ChangeCellList){
        elem->ChangeCellType(new CellTypeExit());
    }


}