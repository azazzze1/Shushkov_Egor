#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include "Field.h"

#include "Rules/RuleFieldSize.h"
#include "Rules/RuleMoveEnergy.h"
#include "Rules/RuleSpawnChest.h"
#include "Rules/RuleSpawnPlayer.h"
#include "Rules/RuleSpawnStones.h"
#include "Rules/RuleSpawnKey.h"

template <class... Rules>
class FieldGenerator{
public:
    Field* fill(Player* player){
        Field* field = new Field;
        (Rules()(field, player),...);
        return field;
    }
};

#endif
