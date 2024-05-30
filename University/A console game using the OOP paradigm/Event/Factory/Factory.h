#ifndef OOP_CMAKE_FACTORY_H
#define OOP_CMAKE_FACTORY_H
#include "../Event.h"

class Factory{
public:
    virtual Event* CreateEvent() = 0;
};

#endif
