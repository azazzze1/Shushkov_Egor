#include "ComandReader.h"
ComandReader::ComandReader(Mediator* med): MediatorObj(med){}

void ComandReader::Read(){
    mediator -> LargeCommandNotify(this, "Read");
}

void ComandReader::ReadStartField(){
    mediator -> LargeCommandNotify(this, "ReadStartField");
}

void ComandReader::setMediator(Mediator* med){
        mediator = med;
    }