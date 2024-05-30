#include "PlayerStatsView.h"

void PlayerStatsView::PlayerView(Player &vPlayer){
    std::cout<<"Энергия: "<<vPlayer.ShowHealth()<<std::endl;
    std::cout<<"Сила кирки: "<<vPlayer.ShowPickaxePower()<<std::endl;
    std::cout<<"Инвентарь: ";
    if(vPlayer.ShowKey())
        std::cout<<'F';
    std::cout<<std::endl;
}