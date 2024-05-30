#ifndef OOP_CMAKE_MEMENTOMANAGER_H
#define OOP_CMAKE_MEMENTOMANAGER_H

#include "Memento.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "../../Field/Field.h"
#include "../../Player/Player.h"
#include <sstream>
#include <cstdlib>

class MementoManager {
private:
    int error_code;
    std::fstream file;
    Field* CurField;
    Player* CurPlayer;
    bool check_mem_field(Memento mem);
    bool check_mem_player(Memento mem);
public:
    MementoManager(Player* nPlayer, Field* nField);
    ~MementoManager();

    void exception();

    void save(Memento* mem);
    void restore();
};


#endif
