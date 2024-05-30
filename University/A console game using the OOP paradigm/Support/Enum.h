#ifndef ENUM_H
#define ENUM_H


class Enum {
public:
    enum PlayerStats{
        HEALTH = 100,
        PICKAXE_POWER = 0,
        KEY_ABILITY = 0
    };

    enum FieldDefaultSize{
        DEFAULT_HEIGHT_OF_FIELD = 12,
        DEFAULT_WIDTH_OF_FIELD = 16
    };

    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum Logs{
        STATUS_LOG_ENERGY,
        STATUS_LOG_KEY,
        STATUS_LOG_LVL_PICKAXE_UP,
        STATUS_LOG_MOVE_PLAYER,
        STATUS_LOG_DIG,
        STATUS_LOG_EVENT_SET_STONE,
        STATUS_LOG_EVENT_SET_KEY,
        STATUS_LOG_EVENT_SET_CHEST,
        GAME_START,
        GAME_EXIT,
        GAME_VICTORY,
        GAME_OVER_ENERGY,
        ERROR_LOG_UNPASSABLE,
        ERROR_LOG_WRONG_SIZE_MINUS,
        ERROR_LOG_WRONG_SIZE_LARGE
    };
};


#endif
