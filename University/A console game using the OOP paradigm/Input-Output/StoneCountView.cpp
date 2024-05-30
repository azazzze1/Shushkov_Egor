#include "StoneCountView.h"

void StoneCountView::ViewStoneCount(FactoryController &fact_cntrl){
    std::cout<<"Камней осталось: "<<fact_cntrl.ShowStoneCount()<<std::endl;
}