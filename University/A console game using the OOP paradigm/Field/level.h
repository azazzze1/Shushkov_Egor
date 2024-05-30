#ifndef OOP_CMAKE_LEVEL_H
#define OOP_CMAKE_LEVEL_H

#include "FieldGenerator.h"


class Level{
public:
    virtual Field* GenerateLevel() = 0;
    virtual ~Level() {};
};

#endif
