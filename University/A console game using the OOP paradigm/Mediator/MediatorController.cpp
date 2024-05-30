#include "MediatorController.h"


void MediatorController::LargeCommandNotify(MediatorObj *obj, std::string Command) {
    if(auto comandR = dynamic_cast<Game *>(obj)){
        if(Command == "CreateStandartField")
            comand_controller -> CreateStandartSizeField();
        else if(Command == "CreateField")
            comand_reader -> ReadStartField();
        if(Command == "ShowKeysInfo")
            ConfContr -> CoutInfoAboutKeys();
    }
    if(auto comandR = dynamic_cast<ComandController *>(obj)){
        if(Command == "GameOver with energy")
            game -> GameOverEnergy();
        if(Command == "Win")
            game -> Win();
    }
    if(auto comandR = dynamic_cast<ComandReader *>(obj)){
        if(Command == "Read")
            ConfContr->Read();
        if(Command == "ReadStartField")
            ConfContr->ReadStartField();
    }

}


MediatorController::MediatorController(ComandReader* comand_reader, ComandController* comand_controller, Game* game, ConfController* ConfContr):
    comand_reader(comand_reader), comand_controller(comand_controller), game(game), ConfContr(ConfContr){
        comand_reader->setMediator(this);
        comand_controller->setMediator(this);
        game->setMediator(this);
        ConfContr->setMediator(this);
        ConfContr->get_conf();
}


//сделать map с указателем на функции 0_о
void MediatorController::ShortCommandNotify(MediatorObj *obj, char Command){
    if (auto comandR = dynamic_cast<ConfController*>(obj)){
        if(Command == ConfContr->show_char("Move_Direction_Up"))
            comand_controller->MovePlayer(Enum::UP);
        else if(Command == ConfContr->show_char("Move_Direction_Left"))
            comand_controller->MovePlayer(Enum::LEFT);
        else if(Command == ConfContr->show_char("Move_Direction_Down"))
            comand_controller->MovePlayer(Enum::DOWN);
        else if(Command == ConfContr->show_char("Move_Direction_Right"))
            comand_controller->MovePlayer(Enum::RIGHT);
        else if(Command == ConfContr->show_char("Dig_Direction_Up"))
            comand_controller->Dig(Enum::UP);
        else if(Command == ConfContr->show_char("Dig_Direction_Left"))
            comand_controller->Dig(Enum::LEFT);
        else if(Command == ConfContr->show_char("Dig_Direction_Down"))
            comand_controller->Dig(Enum::DOWN);
        else if(Command == ConfContr->show_char("Dig_Direction_Right"))
            comand_controller->Dig(Enum::RIGHT);
        else if(Command == ConfContr->show_char("Save_Game"))
            comand_controller->Save();
        else if(Command == ConfContr->show_char("Load_Game"))
            comand_controller->Load();
        else if(Command == ConfContr->show_char("Close_Game"))
            game->QuitGame();


    }
}

void MediatorController::ShortIntCommandNotify(MediatorObj* obj, int Command){
    if(auto comandR = dynamic_cast<Game* >(obj)){
        comand_controller -> CreateLevelField(Command);
    }
}


void MediatorController::FieldSizeNotify(MediatorObj *obj, std::pair<int, int> StartField) {
    if(auto comandR = dynamic_cast<ConfController*>(obj)){
        comand_controller -> CreateCustomField(StartField.first,StartField.second);
    }
}