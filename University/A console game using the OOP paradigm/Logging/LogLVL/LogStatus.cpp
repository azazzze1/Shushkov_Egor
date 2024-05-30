#include "LogStatus.h"

std::ostream &LogStatus::Output(std::ostream &out) {
    return out<<*this;
}

void LogStatus::update(Report &msg){
    CurMsg = &msg;
}

std::ostream& operator<<(std::ostream &out, const LogStatus &logStatus){
    switch(logStatus.CurMsg -> GetLogType()){
        case Enum::Logs::STATUS_LOG_KEY:
            out<<"[STATS] ";
            if(logStatus.CurMsg->ShowBDate())
                return out<<"Ключ был подобран\n";
            else
                return out<<"Ключ был использован\n";

        case Enum::Logs::STATUS_LOG_LVL_PICKAXE_UP:
            out<<"[STATS] ";
            return out<<"Уровень повысился на единицу\n";

        case Enum::Logs::STATUS_LOG_ENERGY:
            out<<"[STATS] ";
            return out<<"--Энергия понижена на "<<logStatus.CurMsg->ShowIData()<<std::endl;

        case Enum::Logs::STATUS_LOG_MOVE_PLAYER:
            out<<"[STATS] ";
            out<<"Игрок сделал шаг на клетку с координатами [x,y]: ["<<logStatus.CurMsg->ShowPDate().second<<',';
            out<<logStatus.CurMsg->ShowPDate().first;
            return out<<"]\n";

        case Enum::Logs::STATUS_LOG_DIG:
            out<<"[STATS] ";
            if(logStatus.CurMsg->ShowIData() == -1)
                return out<<"Игрок ударил киркой по воздуху\n";
            else if(logStatus.CurMsg->ShowIData() == Enum::Direction::UP)
                return out<<"Игрок сломал камень по направлению \"вверх\"\n";
            else if(logStatus.CurMsg->ShowIData() == Enum::Direction::DOWN)
                return out<<"Игрок сломал камень по направлению \"вниз\"\n";
            else if(logStatus.CurMsg->ShowIData() == Enum::Direction::RIGHT)
                return out<<"Игрок сломал камень по направлению \"вправо\"\n";
            else if(logStatus.CurMsg->ShowIData() == Enum::Direction::LEFT)
                return out<<"Игрок сломал камень по направлению \"влево\"\n";
            break;

        case Enum::Logs::STATUS_LOG_EVENT_SET_STONE:
            out<<"[STATS] ";
            return out<<"Был создан камень на позиции Y:"<<logStatus.CurMsg->ShowPDate().first<<" X: "<<logStatus.CurMsg->ShowPDate().second<<std::endl;
        case Enum::Logs::STATUS_LOG_EVENT_SET_KEY:
            out<<"[STATS] ";
            return out<<"Был создан ключ на позиции Y:"<<logStatus.CurMsg->ShowPDate().first<<" X: "<<logStatus.CurMsg->ShowPDate().second<<std::endl;
        case Enum::Logs::STATUS_LOG_EVENT_SET_CHEST:
            out<<"[STATS] ";
            return out<<"Был создан сундук на позиции Y:"<<logStatus.CurMsg->ShowPDate().first<<" X: "<<logStatus.CurMsg->ShowPDate().second<<std::endl;
        default:
            return out;
    }
}
