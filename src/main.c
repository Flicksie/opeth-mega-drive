#include <genesis.h>

#include "tracklist.h"
#include "xgm_tool.h"
#include "ym_state.h"
#include "psg_state.h"
#include "xd3.h"
#include "log_tab.h"

#include "smp_null.h"
#include "music.h"
#include "gfx.h"
#include "font.h"


#include "joy_handler.h"
#include "screen_state.h"
#include "screens/title.h"
#include "screens/player.h"
#include "screens/test.h"


void basicInit(){
    JOY_init();
    currentState = STATE_MENU;
}


int main()
{
    basicInit();

    while(1){

        switch(currentState){
            case STATE_MENU:{
                processStateMenu();
                break;
            }
            case STATE_PLAY:{
                playerScreen();
                break;
            }
        }
    }

    // =======================================

 
    return 0;
}

