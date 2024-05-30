#ifndef SET_CHEST_H
#define SET_CHEST_H
#include "FieldEvent.h"
#include "../PlayerEvent /OpenChest.h"

class SetChest : public  FieldEvent{
public:
    SetChest(Field* StartField, int height = -1, int width = -1);
    void trigger() override;
};

#endif
