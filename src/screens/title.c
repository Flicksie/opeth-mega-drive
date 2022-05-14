#include "genesis.h"

#include "screen_state.h"
#include "joy_handler.h"



void processStateMenu(){
    //Init
    JOY_setEventHandler(&joyHandlerMenu);

    VDP_setPaletteColor(0, RGB24_TO_VDPCOLOR(0x000000));
    VDP_drawText("MENU STATE", 10, 13);

    //Update
    while(currentState == STATE_MENU){
        SYS_doVBlankProcess();
    }

    //Cleanup
    VDP_clearText(10, 13, 10);

}