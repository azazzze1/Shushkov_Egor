#ifndef CELL_H
#define CELL_H

#include "../Event/Event.h"
#include <iostream>
#include "../Support/Enum.h"
#include "CellType.h"

class Event;

class Cell{
private:
    CellType *CurCellType;
    bool Passable;
    char CurIcon;
    Event *CurCellEvent;

public:
    size_t hash_func() const;

    Cell(CellType* StartCellType = new CellTypeLand(), bool StartPassable = true, char StartIcon = '.', Event *StartCellEvent = nullptr);
    Cell(const Cell &obj);

    Cell &operator=(Cell const &other);

    CellType* ShowCellType();
    char ShowCurIcon();
    bool ShowPassable();
    Event* ActivationCheck();

    void ChangeCellType(CellType* NewCellType);
    void ChangeEvent(Event* NewEvent);
    void ChangeCellIcon(char NewIcon);

    void ChangeIconToStandart();
    void ChangePassToStandart();

    void ActivateEvent();
};

#endif