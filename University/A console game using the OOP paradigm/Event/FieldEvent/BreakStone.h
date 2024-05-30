#ifndef BREAK_STONE_H
#define BREAK_STONE_H
#include "FieldEvent.h"

class BreakStone : public FieldEvent{
public:
    BreakStone(Field* StartField, Cell* CurCell);
    void trigger() override;
};


#endif
