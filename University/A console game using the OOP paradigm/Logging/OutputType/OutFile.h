#ifndef OUTFILE_H
#define OUTFILE_H
#include "../Decorator.h"
#include "../LogLVL/LogStatus.h"
#include "../LogLVL/LogGame.h"
#include "../LogLVL/LogError.h"

#include <iostream>
#include <fstream>

class OutFile : public Decorator{
private:
    std::ofstream log_file;
public:
    OutFile(IObserver* obs) : Decorator(obs){
        log_file.open("/home/azazzzel/CLionProjects/OOP_CMAKE/log.txt",std::ofstream::app);
    }
    std::ostream& Output(std::ostream& out) override;
    void update(Report& msg) override;
    ~OutFile(){
        log_file.close();
    }
};


#endif
