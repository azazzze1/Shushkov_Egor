#include "LogError.h"

std::ostream &LogError::Output(std::ostream &out) {
    return out<<*this;
}

void LogError::update(Report &msg){
    CurMsg = &msg;
}

std::ostream& operator<<(std::ostream &out, const LogError &logError){
    switch (logError.CurMsg->GetLogType()){
        case Enum::Logs::ERROR_LOG_UNPASSABLE:
            out<<"[ERROR] ";
            out<<"Игрок встретил препятствие на координатах [x,y]: ["<<logError.CurMsg->ShowPDate().second<<',';
            out<<logError.CurMsg->ShowPDate().first;
            return out<<"]\n";

        case Enum::Logs::ERROR_LOG_WRONG_SIZE_LARGE:
            out<<"[ERROR] ";
            return out<<"Пользователь ввёл размер поля, превышающий допустимый\n";

        case Enum::Logs::ERROR_LOG_WRONG_SIZE_MINUS:
            out<<"[ERROR] ";
            return out<<"Пользователь ввёл параметр(ы) размера поля, меньшие 1\n";

        default:
            return out;
        }
}
