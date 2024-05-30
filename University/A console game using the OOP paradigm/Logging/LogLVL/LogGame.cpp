#include "LogGame.h"

std::ostream &LogGame::Output(std::ostream &out) {
    return out<<*this;
}

void LogGame::update(Report &msg){
    CurMsg = &msg;
}

std::ostream& operator<<(std::ostream &out, const LogGame &logStatus){
    switch (logStatus.CurMsg->GetLogType()){
        case Enum::Logs::GAME_START:
            out<<"[GAME] ";
            if(logStatus.CurMsg->ShowBDate())
                return out<<"Старт игры с пользовательским полем\n";
            else
                return out<<"Старт игры со стандартным полем\n";
            break;

        case Enum::Logs::GAME_EXIT:
            out<<"[GAME] ";
            return out<<"Пользователь вышел из игры\n";
            break;

        case Enum::Logs::GAME_OVER_ENERGY:
            out<<"[GAME] ";
            return out<<"Игра завершилась проигрышем из-за нулевой энергии\n";
            break;

        case Enum::Logs::GAME_VICTORY:
            out<<"[GAME] ";
            return out<<"Игра завершилась победой игрока - пользователь вошёл в дверь выхода\n";
            break;

        default:
            return out;
    }
}
