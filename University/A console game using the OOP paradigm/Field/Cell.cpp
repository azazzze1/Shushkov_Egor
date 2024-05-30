#include "Cell.h"


Cell::Cell(CellType* StartCellType, bool StartPassable, char StartIcon, Event* StartCellEvent):
    CurCellType(StartCellType), Passable(StartPassable), CurIcon(StartIcon), CurCellEvent(StartCellEvent) {};

Cell::Cell(const Cell& obj): Cell(obj.CurCellType, obj.Passable,obj.CurIcon,obj.CurCellEvent){}

Cell &Cell::operator= (Cell const &other){
    if(this == &other)
        return *this;
    this->CurIcon = other.CurIcon;
    this->CurCellType = other.CurCellType;
    this->Passable = other.Passable;
    return *this; 
}

CellType* Cell::ShowCellType(){
    return this->CurCellType;
}

char Cell::ShowCurIcon(){
    return this->CurIcon; 
}

bool Cell::ShowPassable(){
    return this->Passable;
}


Event* Cell::ActivationCheck(){
    return this->CurCellEvent;
}

void Cell::ChangeEvent(Event* NewEvent){
    this->CurCellEvent = NewEvent;
}

void Cell::ChangeCellIcon(char NewIcon){
    CurIcon = NewIcon;
}

void Cell::ChangeIconToStandart() {
    CurIcon = CurCellType->SetIcon();
}

void Cell::ChangePassToStandart() {
    Passable = CurCellType->SetPassable();
}

void Cell::ChangeCellType(CellType *NewCellType){
    CurCellType = NewCellType;
    ChangeIconToStandart();
    ChangePassToStandart();
}

void Cell::ActivateEvent(){
    CurCellEvent -> trigger();
}

size_t Cell::hash_func() const {
    return std::hash<char>()(CurIcon)<<3;
}

