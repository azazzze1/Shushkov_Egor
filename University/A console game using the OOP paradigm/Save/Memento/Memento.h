#ifndef OOP_CMAKE_MEMENTO_H
#define OOP_CMAKE_MEMENTO_H

#include <string>

class Memento {
private:
    std::string data;
public:
    explicit Memento(const std::string& new_data): data(new_data) {}
    std::string getData() const{return data;}
};

#endif
