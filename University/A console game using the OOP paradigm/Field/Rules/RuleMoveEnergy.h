#ifndef OOP_CMAKE_RULEMOVEENERGY_H
#define OOP_CMAKE_RULEMOVEENERGY_H

#include "../Field.h"
#include "../../Event/PlayerEvent /EnergyMove.h"
#include "../../Player/Player.h"


template<int EnergySize = 1>
class RuleMoveEnergy{
public:
    void operator()(Field* field, Player* player){
        for(int i = 0; i < field->ShowHeight(); ++i){
            for(int j = 0; j < field->ShowWidth(); ++j){
                if(auto R = dynamic_cast<CellTypeLand* >(field->GetCell(i,j)->ShowCellType()))
                    field->GetCell(i,j)->ChangeEvent(new EnergyMove(field, player, EnergySize));
            }
        }
    }
};

#endif
