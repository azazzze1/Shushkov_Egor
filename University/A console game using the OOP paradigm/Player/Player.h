#ifndef PLAYER_H
#define PLAYER_H

#include "../Support/Enum.h"
#include "../Logging/Observer.h"
#include "../Save/Memento/IOriginator.h"
#include <vector>
#include <algorithm>
#include <sstream>

class Player : public IObservable, public IOriginator{
private:
    std::vector<IObserver*> observers;
    int pHealth;
    int pPickaxePower;
    bool pKey;
    bool ReadyToGo;
public:
    size_t hash_func(int health, int pickaxe, bool key, bool RTG);

    Player(int Health = Enum::HEALTH, int pPickaxePower = Enum::PICKAXE_POWER, bool Key = Enum::KEY_ABILITY);

    Player(const Player &obj);
    Player &operator=(Player const &other);

    void addObserver(IObserver* obs) override;
    void removeObserver(IObserver* obs) override;
    void notify(Report& msg) override;

    int ShowHealth();
    int ShowPickaxePower();
    bool ShowKey();
    bool ShowReadyToGo();

    void ReadyToExit();
    void ChangeKey();
    void LevelUpPickaxePower();
    void ChangeHealth(int MinusHealth);

    void restore(Memento* mem);
    Memento* save();
};

#endif
