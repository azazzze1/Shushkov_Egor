#include "Field.h"

Field &Field::operator= (Field const &other){
    if(this == &other)
        return *this;

    for(int i = 0; i < height; ++i)
        CurField[i].clear();
    CurField.clear();

    this->height = other.height;
    this->width = other.width;

    for(int i = 0; i < height; ++i)
        CurField.push_back(other.CurField[i]); 

    this->pCoords = other.pCoords;
    return *this;
}

Field::Field (const Field &obj): Field(obj.height,obj.width){
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            this->CurField[i][j] = obj.CurField[i][j];
    this->pCoords = obj.pCoords;
}

Field::Field (Field &&obj): Field(obj.height,obj.width){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j)
            this->CurField[i][j] = obj.CurField[i][j];
        obj.CurField[i].clear();
    }
    obj.CurField.clear();
    this->pCoords = obj.pCoords;
    obj.pCoords.xCoord = -1;
    obj.pCoords.yCoord = -1;
}

int Field::ShowHeight(){
    return height;
}

int Field::ShowWidth(){
    return width;
}

Coords Field::ShowPlayerCoords(){
    return pCoords;
}

std::vector <std::vector<Cell>> Field::ShowCurField(){
    return CurField; 
}

void Field::FixFieldSettings(){
    if(height<1){
        Report msg = Report(Enum::Logs::ERROR_LOG_WRONG_SIZE_MINUS);
        notify(msg);
        height = Enum::DEFAULT_HEIGHT_OF_FIELD;
    }
    else if(height>35){
        Report msg = Report(Enum::Logs::ERROR_LOG_WRONG_SIZE_LARGE);
        notify(msg);
        height = 35;
    }
    if(width<1){
        Report msg = Report(Enum::Logs::ERROR_LOG_WRONG_SIZE_MINUS);
        notify(msg);
        width = Enum::DEFAULT_WIDTH_OF_FIELD;
    }
    else if(width>50){
        Report msg = Report(Enum::Logs::ERROR_LOG_WRONG_SIZE_LARGE);
        notify(msg);
        width = 50;
    }
}

Field::Field(int _height, int _width):height(_height), width(_width){
    FixFieldSettings();
    for(int i = 0; i<height; ++i){
        CurField.push_back(std::vector<Cell>(width));
        for(int j = 0; j<width; ++j)
            CurField.back().emplace_back(Cell());
    }
//    pCoords.xCoord = width/2;
//    pCoords.yCoord = height/2;
//    CurField[pCoords.yCoord][pCoords.xCoord].ChangeCellIcon('P');
}

void Field::ChangeIconToStandart(Coords CellCoords){
    CurField[CellCoords.yCoord][CellCoords.xCoord].ChangeIconToStandart();
}

void Field::PlayersMove(Enum::Direction direction){
    Coords PrevCoords = pCoords;
    CurField[pCoords.yCoord][pCoords.xCoord].ChangeIconToStandart();
    switch (direction)
    {
        case Enum::UP:
        pCoords.yCoord -1 >= 0 ? --pCoords.yCoord : pCoords.yCoord = height-1;
        break;

        case Enum::DOWN:
        pCoords.yCoord + 1 < height ? ++pCoords.yCoord : pCoords.yCoord = 0;
        break;

        case Enum::LEFT:
        pCoords.xCoord - 1 >= 0 ?  --pCoords.xCoord : pCoords.xCoord = width - 1;
        break;
    
        case Enum::RIGHT:
        pCoords.xCoord + 1 < width ? ++pCoords.xCoord : pCoords.xCoord = 0;
        break;
    }

    if(!CurField[pCoords.yCoord][pCoords.xCoord].ShowPassable()){
        Report msg = Report(Enum::Logs::ERROR_LOG_UNPASSABLE);
        msg.SetData(pCoords.yCoord, pCoords.xCoord);
        notify(msg);
        pCoords=PrevCoords;
    }else{
        Report msg = Report(Enum::Logs::STATUS_LOG_MOVE_PLAYER);
        msg.SetData(pCoords.yCoord, pCoords.xCoord);
        notify(msg);
    }

    CurField[pCoords.yCoord][pCoords.xCoord].ChangeCellIcon('P'); 

    if(CurField[pCoords.yCoord][pCoords.xCoord].ActivationCheck())
        CurField[pCoords.yCoord][pCoords.xCoord].ActivateEvent();
}

Cell* Field::GetCell(int height, int width){
    return &(CurField[height][width]);
}

bool Field::Dig(Enum::Direction direction, int PowerOfPickaxe){
    Report msg = Report(Enum::Logs::STATUS_LOG_DIG);
    msg.SetData(direction);
    switch(direction){
        case Enum::UP:
            for(int i = 1; i<=PowerOfPickaxe && pCoords.yCoord-i >= 0; ++i){
                if(auto R = dynamic_cast<CellTypeStone*>(CurField[pCoords.yCoord-i][pCoords.xCoord].ShowCellType())){
                    CurField[pCoords.yCoord-i][pCoords.xCoord].ActivateEvent();
                    notify(msg);
                    return true;
                }
            }
            break;

        case Enum::DOWN:
            for(int i = 1; i<=PowerOfPickaxe && pCoords.yCoord + i < height ; ++i){
                if(auto R = dynamic_cast<CellTypeStone*>(CurField[pCoords.yCoord+i][pCoords.xCoord].ShowCellType())){
                    CurField[pCoords.yCoord+i][pCoords.xCoord].ActivateEvent();
                    notify(msg);
                    return true;
                }
            }
            break;

        case Enum::RIGHT:
            for(int i = 1; i<=PowerOfPickaxe && pCoords.xCoord + i < width; ++i){
                if(auto R = dynamic_cast<CellTypeStone*>(CurField[pCoords.yCoord][pCoords.xCoord+i].ShowCellType())){
                    CurField[pCoords.yCoord][pCoords.xCoord+i].ActivateEvent();
                    notify(msg);
                    return true;
                }
            }
            break;

        case Enum::LEFT:
            for(int i = 1; i<=PowerOfPickaxe && pCoords.xCoord-i >= 0; ++i){
                if(auto R = dynamic_cast<CellTypeStone*>(CurField[pCoords.yCoord][pCoords.xCoord-i].ShowCellType())){
                    CurField[pCoords.yCoord][pCoords.xCoord-i].ActivateEvent();
                    notify(msg);
                    return true;
                }
            }
            break;
    }
    msg.SetData(-1);
    notify(msg);
    return false;
}

void Field::addObserver(IObserver *obs) {
    observers.push_back(obs);
}

void Field::removeObserver(IObserver *obs) {
    std::remove(observers.begin(),observers.end(),obs);
}

void Field::notify(Report& msg){
    for(auto obs : observers)
        obs -> update(msg);
}

void Field::ChangePlayersCoords(int height, int width){
    pCoords.xCoord=width;
    pCoords.yCoord=height;
    CurField[pCoords.yCoord][pCoords.xCoord].ChangeCellIcon('P');
}

size_t Field::hash_func(const std::vector <std::vector<Cell>> _field, int _height, int _width, Coords PlayerCoords){
    size_t result_hash = 0;

    size_t hash_width = std::hash<int>()(_width) << 5;
    size_t hash_height = std::hash<int>()(_height) * 4;
    Coords hash_coords = {std::hash<int>()(PlayerCoords.xCoord) << 2, std::hash<int>()(PlayerCoords.yCoord)<<4};

    for(const auto& i : _field)
        for(const auto& j : i)
            result_hash += j.hash_func();

    return result_hash + hash_height + hash_width + hash_coords.xCoord + hash_coords.yCoord;
}



Memento *Field::save(){
    std::string s("Field: " + std::to_string(hash_func(CurField,height,width,pCoords)) + '\n');

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j)
            s+=CurField[i][j].ShowCurIcon();
        s+='\n';
    }

    s += std::to_string(width)+" "+std::to_string(height)+" "+std::to_string(pCoords.yCoord)+" "+std::to_string(pCoords.xCoord) + '\n';
    return new Memento(s);
}

void Field::restore(Memento *mem) {
    std::string s = mem->getData();
    std::vector<std::string> VecStr;
    std::istringstream data(s);
    std::string line;
    while(std::getline(data,line,'\n'))
        VecStr.push_back(line);

    std::istringstream SS(VecStr[VecStr.size()-1]);
    int w,h,y,x;
    SS>>w>>h>>y>>x;

    pCoords.yCoord = y; pCoords.xCoord = x;
    height = h; width = w;

    std::vector <std::vector<Cell>> new_field;
    for(int i = 0; i<height; ++i){
        new_field.push_back(std::vector<Cell>(width));
        for(int j = 0; j<width; ++j)
            new_field.back().emplace_back(Cell());
    }
    CurField = new_field;

    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            CurField[i][j].ChangeCellIcon(VecStr[i+1][j]);
}

