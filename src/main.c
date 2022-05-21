#include <genesis.h>


#include "screen_state.h"
#include "screens/title.h"
#include "screens/player.h"
#include "screens/menu.h"
#include "screens/info.h"


void basicInit(){
    JOY_init();
    currentState = STATE_LOGO;
}


int main()
{
    basicInit();


    while(1){


        switch(currentState){
            case STATE_LOGO:{
                processStateMenu();
                break;
            }
            case STATE_INFO:{
                infoScreen();
                break;
            }
            case STATE_MENU:{
                menuScreen();
                break;
            }
            case STATE_PLAYER:{
                playerScreen();
                break;
            }
        }
    }

    // =======================================

 
    return 0;
}

