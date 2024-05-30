#ifndef CAVE_COLLAPS_H
#define CAVE_COLLAPS_H
#include "FieldEvent.h"
#include "BreakStone.h"

class CaveCollaps : public FieldEvent{
public:
    CaveCollaps(Field* StartField);
    void trigger() override;
};


#endif
