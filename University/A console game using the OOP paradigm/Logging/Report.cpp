#include "Report.h"

Report::Report(Enum::Logs StartLogType): CurLogType(StartLogType) {}

void Report::SetData(int NewIData) {
    iData = NewIData;
}

void Report::SetData(bool NewBData) {
    bData = NewBData;
}

void Report::SetData(int y, int x) {
    pData.first = y;
    pData.second = x;
}

Enum::Logs Report::GetLogType() {
    return CurLogType;
}

int Report::ShowIData(){
    return iData;
}

bool Report::ShowBDate(){
    return bData;
}

std::pair<int, int> Report::ShowPDate() {
    return pData;
}