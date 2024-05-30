#ifndef FIELD_H
#define FIELD_H

#include "../Player/Player.h"
#include "Cell.h"
#include "../Support/Enum.h"
#include "../Logging/Observer.h"
#include "../Save/Memento/IOriginator.h"
#include "../Input-Output/FieldView.h"
#include <vector>
#include <sstream>


class Cell;

struct Coords{
    int xCoord, yCoord;
};

class Field : public  IObservable, public IOriginator
{
private:
    std::vector<IObserver*> observers;
    int height, width;
    Coords pCoords; 
    std::vector <std::vector<Cell>> CurField;
public:
    Field(int height = Enum::DEFAULT_HEIGHT_OF_FIELD, int width = Enum::DEFAULT_WIDTH_OF_FIELD);

    Field (const Field &obj);
    Field (Field &&obj);
    Field &operator =(Field const &other);


    int ShowHeight(); 
    int ShowWidth();
    Coords ShowPlayerCoords();
    std::vector <std::vector<Cell>> ShowCurField();

    void addObserver(IObserver* obs) override;
    void removeObserver(IObserver* obs) override;
    void notify(Report& msg) override;

    Cell* GetCell(int height, int width);

    void PlayersMove(Enum::Direction direction);
    void FixFieldSettings();

    bool Dig(Enum::Direction direction, int PowerOfPickaxe);

    void ChangeIconToStandart(Coords CellCoords);
    void ChangePlayersCoords(int height, int width);

    size_t hash_func(const std::vector<std::vector<Cell>> _field, int _height, int _width, Coords _PlayerCoords);
    Memento* save();
    void restore(Memento* mem); // реализовать
};

#endif