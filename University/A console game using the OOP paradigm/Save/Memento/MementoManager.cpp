#include "MementoManager.h"

MementoManager::MementoManager(Player* nPlayer, Field* nField) : error_code(0) {
    file.open("save.txt", std::ios::in | std::ios::out | std::ios::app);
    if(!file.is_open())
        error_code = 1;
    exception();
    CurField = nField;
    CurPlayer = nPlayer;
}

MementoManager::~MementoManager() {
    file.close();
}

void MementoManager::save(Memento *mem) {
    exception();
    file.seekp(file.tellp());
    std::string DATA = mem->getData();
    file << DATA;
}

void MementoManager::restore(){
    file.seekp(0,std::ios::beg);

    if(file.eof()){
        error_code = 2;
        exception();
        return;
    }

    std::vector<std::string> str_vect;
    std::string mem;
    getline(file,mem);
    while(!file.eof()){
        str_vect.push_back(mem);
        getline(file,mem);
    }

    std::string s = str_vect[str_vect.size()-1];
    std::istringstream _STR(s);
    int N;
    _STR>>N;

    mem.clear();
    mem = str_vect[str_vect.size()-(N+2)] + "\n";
    for(int i = N+1; i > 0; --i)
        mem+=str_vect[str_vect.size()-i] + "\n";
    Memento MemField(mem);

    mem.clear();
    mem = str_vect[str_vect.size()-(N+4)] + ' ' + str_vect[str_vect.size()-(N+3)];
    Memento MemPlayer(mem);

    if(check_mem_player(MemPlayer) && check_mem_field(MemField)){
        CurPlayer -> restore(&MemPlayer);
        CurField -> restore(&MemField);
    }
}


bool MementoManager::check_mem_field(Memento mem){
    std::string s = mem.getData();
    std::vector<std::string> VecStr;
    std::istringstream data(s);
    std::string line;
    while(std::getline(data,line,'\n'))
        VecStr.push_back(line);


    std::istringstream SS(VecStr[VecStr.size()-1]);
    int w,h,y,x;
    SS>>w>>h>>y>>x;

    std::istringstream SSS(VecStr[VecStr.size()-(w+2)]);
    size_t HASH;
    SSS>>line>>HASH;

    Field tmp_f(h,w);
    for(int i = 0; i < tmp_f.ShowHeight(); ++i)
        for(int j = 0; j < tmp_f.ShowWidth(); ++j)
            tmp_f.GetCell(i,j)->ChangeCellIcon(VecStr[i+1][j]);

    if(w<1 || h<1 || y>=tmp_f.ShowHeight() || y<0 || x>=tmp_f.ShowWidth() || x<0){
        error_code = 4;
        exception();
        return false;
    }

    Coords pCord = {x,y};

    if(HASH == tmp_f.hash_func(tmp_f.ShowCurField(),h,w,pCord))
        return true;

    error_code = 3;
    exception();
    return false;
}

bool MementoManager::check_mem_player(Memento mem){
    std::string s = mem.getData();
    std::istringstream data(s);
    std::string garbage;
    size_t HASH;
    int H,P,K,R;
    data>>garbage>>HASH>>H>>P>>K>>R;

    if(H<0 || P<0){
        error_code = 4;
        exception();
        return false;
    }

    if(HASH == CurPlayer->hash_func(H,P,K,R))
        return true;

    error_code = 3;
    exception();
    return false;
}

void MementoManager::exception(){
    switch(error_code){
        case 1:
            std::cout<<"Не удалось открыть файл \"save.txt\"\n";
            break;
        case 2:
            std::cout<<"Невозможно восставновить сохранение - файл пустой\n";
            break;
        case 3:
            std::cout<<"Логическая ошибка в файле сохранения!\n";
            break;
        case 4:
            std::cout<<"Файл сохранения был изменён! Пожалуйста, не пытайтесь сжульничать!\n";
            break;
    }
}