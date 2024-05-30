#ifndef SET_KEY_H
#define SET_KEY_H
#include "FieldEvent.h"


class SetKey : public FieldEvent{
public:
    SetKey(Field* StartField, int height = -1, int width = -1);
    void trigger() override;
};


#endif
