#ifndef SET_EXIT_H
#define SET_EXIT_H
#include "FieldEvent.h"


class SetExit : public FieldEvent{
public:
    SetExit(Field* StartField);
    void trigger() override;
};

#endif
