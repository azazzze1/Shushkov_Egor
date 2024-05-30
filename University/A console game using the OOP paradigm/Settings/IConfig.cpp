#include "IConfig.h"

std::map<std::string, std::string> ReadConfFile::get_conf(){
    char NameOfCommand[256], CommandChar[256];
    std::map<std::string, std::string> ConfigOfAllMap;

    ConfigOfAllMap["Move_Direction_Up"]="w";
    ConfigOfAllMap["Move_Direction_Left"]="a";
    ConfigOfAllMap["Move_Direction_Down"]="s";
    ConfigOfAllMap["Move_Direction_Right"]="d";
    ConfigOfAllMap["Dig_Direction_Up"]="i";
    ConfigOfAllMap["Dig_Direction_Left"]="j";
    ConfigOfAllMap["Dig_Direction_Down"]="k";
    ConfigOfAllMap["Dig_Direction_Right"]="l";
    ConfigOfAllMap["Close_Game"]="Q";
    ConfigOfAllMap["Save_Game"]="S";
    ConfigOfAllMap["Load_Game"]="L";

    while(ConfFile.getline(NameOfCommand,256,'=')){
        ConfFile.getline(CommandChar,256);
        ConfigOfAllMap[NameOfCommand] = CommandChar;
    }
    return ConfigOfAllMap;
}
