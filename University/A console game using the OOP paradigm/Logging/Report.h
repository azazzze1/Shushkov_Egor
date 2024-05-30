#ifndef REPORT_H
#define REPORT_H

#include "../Support/Enum.h"
#include <iostream>

class Report{
private:
    Enum::Logs CurLogType;
    int iData;
    bool bData;
    std::pair<int,int> pData;

public:
    Report(Enum::Logs StartLogType);
    void SetData(int NewIData);
    void SetData(bool NewBData);
    void SetData(int y, int x);

    int ShowIData();
    bool ShowBDate();
    std::pair<int,int> ShowPDate();

    Enum::Logs GetLogType();
};

#endif
