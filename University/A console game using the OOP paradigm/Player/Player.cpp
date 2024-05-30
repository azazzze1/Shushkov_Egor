#include "Player.h"

Player::Player(int Health, int PickaxePower, bool Key):
    pHealth(Health), pPickaxePower(PickaxePower), pKey(Key), ReadyToGo(false) {}

Player::Player(const Player& obj): 
    Player(obj.pHealth, obj.pPickaxePower, obj.pKey) {};

Player &Player::operator =(Player const &other){
    if(this == &other)
        return *this;
    this->pPickaxePower = other.pPickaxePower;
    this->pHealth = other.pHealth;
    this->pKey = other.pKey;
    return *this;
}

void Player::addObserver(IObserver *obs) {
    observers.push_back(obs);
}

void Player::removeObserver(IObserver *obs) {
    std::remove(observers.begin(),observers.end(),obs);
}

void Player::notify(Report& msg){
    for(auto obs : observers)
        obs -> update(msg);
}

int Player::ShowHealth(){
    return pHealth;
}

int Player::ShowPickaxePower(){
    return pPickaxePower;
}

bool Player::ShowKey(){
    return pKey;
}

bool Player::ShowReadyToGo() {
    return ReadyToGo;
}

void Player::ChangeKey(){
    pKey ? pKey = false : pKey = true;
    Report msg = Report(Enum::Logs::STATUS_LOG_KEY);
    msg.SetData(pKey);
    notify(msg);
}

void Player::LevelUpPickaxePower(){
    ++pPickaxePower;
    Report msg = Report(Enum::Logs::STATUS_LOG_LVL_PICKAXE_UP);
    notify(msg);
}

void Player::ChangeHealth(int MinusHealth) {
    pHealth-=MinusHealth;
    Report msg = Report(Enum::Logs::STATUS_LOG_ENERGY);
    msg.SetData(MinusHealth);
    notify(msg);
}

void Player::ReadyToExit() {
    ReadyToGo = true;
}

size_t Player::hash_func(int health, int pickaxe, bool key, bool RTG) {
    size_t hash_health = std::hash<int>()(health) << 5;
    size_t hash_pickaxe = std::hash<int>()(health) << 4;
    size_t hash_key = std::hash<bool>()(health) << 3;
    size_t hash_RTG = std::hash<bool>()(RTG) << 2;

    return hash_RTG + hash_key + hash_pickaxe + hash_health;
}

Memento *Player::save() {
    std::string s("Player: "+std::to_string(hash_func(pHealth,pPickaxePower,pKey,ReadyToGo))+'\n');
    s+=std::to_string(pHealth) + ' ' + std::to_string(pPickaxePower) + ' ' + std::to_string(pKey) + ' ' + std::to_string(ReadyToGo) + '\n';

    return new Memento(s);
}


void Player::restore(Memento *mem) {
    std::string s = mem->getData();
    std::istringstream data(s);
    std::string garbage;
    size_t HASH;
    int H,P,K,R;
    data>>garbage>>HASH>>H>>P>>K>>R;
    pHealth = H; pPickaxePower = P; pKey = (bool)K; ReadyToGo = (bool)R;
}






