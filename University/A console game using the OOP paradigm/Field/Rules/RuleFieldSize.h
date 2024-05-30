#ifndef RULE_FIELD_SIZE_H
#define RULE_FIELD_SIZE_H
#include "../Field.h"
#include "../../Player/Player.h"

template<int height = 35, int width = 50>
class RuleFieldSize{
public:
    void operator ()(Field* field, Player* player){
        delete field;
        field = new Field(height,width);
    }
};

#endif
