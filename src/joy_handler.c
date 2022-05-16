#include "genesis.h"
#include "screen_state.h"

#include "joy_handler.h"


void joyHandlerTitle(u16 joy, u16 changed, u16 state)
{
    if (state & BUTTON_START)
    {
        currentState = STATE_MENU;
    }    
}

