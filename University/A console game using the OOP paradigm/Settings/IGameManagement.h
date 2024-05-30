#ifndef IGAMEMANAGEMENT_H
#define IGAMEMANAGEMENT_H

#include <iostream>
#include <string>
#include <limits>

class IGameManagement{
public:
    virtual char read() = 0;
    virtual std::pair<int,int> readStartField() = 0;
};

class ConsoleManagement : public IGameManagement{
public:
    ConsoleManagement() {}
    char read() override;
    std::pair<int,int> readStartField() override;
};

#endif
