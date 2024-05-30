#include "OutFile.h"

//закрывать файл в конце ИСПРАВИТЬ

void OutFile::update(Report &msg) {
    Decorator::update(msg);
    Output(log_file);
}

std::ostream &OutFile::Output(std::ostream &out) {
    return CurObserver->Output(out);
}