#include "genesis.h"
#include "screen_state.h"

#include "joy_handler.h"


void joyHandlerMenu(u16 joy, u16 changed, u16 state)
{
    if (joy == JOY_1)
    {
        if (state & BUTTON_START)
        {
            currentState = STATE_PLAY;
        }
    }
}