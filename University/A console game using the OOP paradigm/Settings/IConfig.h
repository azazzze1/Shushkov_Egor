#ifndef ICONFIG_H
#define ICONFIG_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>


class IConfig{
public:
    virtual std::map<std::string, std::string> get_conf() = 0;
};

//разбить на два класса
class ReadConfFile : public IConfig{
private:
    std::ifstream ConfFile;
public:
    ReadConfFile(){
        ConfFile.open("/home/azazzzel/CLionProjects/OOP_CMAKE/Settings/Config.txt",std::ofstream::app);
    }

    std::map<std::string, std::string> get_conf() override;

    ~ReadConfFile(){
        ConfFile.close();
    }
};


#endif
