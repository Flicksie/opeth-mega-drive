#ifndef SCREEN_STATE
#define SCREEN_STATE

typedef enum
{
    STATE_LOGO,
    STATE_MENU,
    STATE_PLAYER,
    STATE_INFO
} GAME_STATE;

GAME_STATE currentState;

int globalSeed;
void seedUpdate();

#endif