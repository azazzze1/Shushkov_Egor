#ifndef OOP_CMAKE_IORIGINATOR_H
#define OOP_CMAKE_IORIGINATOR_H

#include "Memento.h"

class IOriginator{
public:
    virtual Memento* save() = 0;
    virtual void restore(Memento* mem) = 0;
};

#endif
