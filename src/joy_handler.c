#include "genesis.h"
#include "screen_state.h"

#include "joy_handler.h"

int konamiSeq = 0;
int konamiTimer = 60;
bool konamiPositive = FALSE;

void konami (u16 joy, u16 changed, u16 state){    

    
    konamiTimer = 60;

    // U U D D L R L R B A START 
    // 0 1 2 3 4 5 6 7 8 9 10



    if (state & BUTTON_UP)
    {
        if (konamiSeq == 0 | konamiSeq == 1 ) {
            konamiSeq += 1;            
        }
        else konamiSeq = 0;
    }
    else if (state & BUTTON_DOWN)
    {
        if (konamiSeq == 2 | konamiSeq == 3 ) {
            konamiSeq += 1;            
        }
        else konamiSeq = 0;
    }
    else if (state & BUTTON_LEFT)
    {
        if (konamiSeq == 4 | konamiSeq == 6) {
            konamiSeq += 1;            
        }
        else konamiSeq = 0;
    }
    else if (state & BUTTON_RIGHT)
    {
        if (konamiSeq == 5 | konamiSeq == 7 ) {
            konamiSeq += 1;            
        }
        else konamiSeq = 0;
    }
    else if (state & BUTTON_A)
    {
        if (konamiSeq == 9 ) {
            konamiSeq += 1;            
        }
        else konamiSeq = 0;
    }
    else if (state & BUTTON_B)
    {
        if (konamiSeq == 8 ) konamiSeq += 1;
        else konamiSeq = 0;
    }
    else if (state & BUTTON_START)
    {
        if (konamiSeq == 10 ) konamiSeq += 1;
        else konamiSeq = 0;
    }
    

    if (konamiSeq > 10 ) konamiPositive = TRUE;
    

}

void joyHandlerTitle(u16 joy, u16 changed, u16 state)
{
    if (state & BUTTON_START)
    {
        currentState = STATE_MENU;
    }    
}

