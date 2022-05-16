#include <genesis.h>

#include "screen_state.h"
#include "gfx.h"
#include "font.h"
#include "xgm.h"
#include "music.h"


int cursor_position;

int X_POS_MENU = 15;
int Y_POS_MENU = 24;




void joyHandlerMenu(u16 joy, u16 changed, u16 state)
{
    if (state & BUTTON_UP)
    {
        cursor_position-= 1;
    }  
    if (state & BUTTON_DOWN)
    {
        cursor_position+= 1;
    }

    if (cursor_position < 0) cursor_position = 1;
    if (cursor_position > 1) cursor_position = 0;

    if( state & (BUTTON_START | BUTTON_C) ) { 
        if ( cursor_position == 0 ) {
            VDP_fadeOutAll(30,TRUE);
            JOY_setEventHandler(NULL);
            currentState = STATE_PLAYER;
        } 
        if ( cursor_position == 1 ) {
            VDP_fadeOutAll(30,TRUE);
            JOY_setEventHandler(NULL);
            currentState = STATE_INFO;
        } 
    }


}

void menuScreen(){

    cursor_position = 0;
    PAL_setColor(15, 0xfff);
    VDP_setTextPalette(PAL0);
    VDP_setPalette(PAL1, palette_black);

    JOY_setEventHandler(NULL);

    VDP_setTextPlane(WINDOW);
    VDP_setWindowHPos(0, 0);
    VDP_setWindowVPos(0, 26);
    //VDP_clearPlane(WINDOW, TRUE);


    

    VDP_drawImageEx(WINDOW, &opeth_img, TILE_ATTR_FULL(PAL1, TRUE, FALSE, FALSE, TILE_USERINDEX), 0, 0, FALSE, TRUE);
    PAL_fadeInPalette(1, opeth_img.palette->data, 60, TRUE);

    //XGM_startPlay(xgm_musics[shuffledIndexes[trackPlayed]]);


    VDP_setTextPlane(BG_B);

    VDP_loadFont(custom_font.tileset, DMA);
    VDP_setTextPalette(PAL0);
    
    VDP_drawText("Start Player", X_POS_MENU, Y_POS_MENU);
    VDP_drawText("Information", X_POS_MENU, Y_POS_MENU+1);
    JOY_init();
    JOY_setEventHandler(&joyHandlerMenu);





    while(currentState == STATE_MENU){
        
        

        VDP_clearText(X_POS_MENU-1, Y_POS_MENU, 1);
        VDP_clearText(X_POS_MENU-1, Y_POS_MENU+1, 1);
        PAL_setColor(47, 0x00f);
        VDP_setTextPalette(PAL2);


        if (cursor_position == 0 ){
            VDP_drawText(">", X_POS_MENU-1, Y_POS_MENU);
            
        } else if ( cursor_position == 1){
            VDP_drawText(">", X_POS_MENU-1, Y_POS_MENU+1);
            
        }

        SYS_doVBlankProcess();
       
    }

    PAL_fadeOutPalette(3,30,FALSE);
    //Cleanup

    JOY_setEventHandler(NULL);
    VDP_clearPlane(WINDOW, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    VDP_clearPlane(BG_A, TRUE);

    SYS_doVBlankProcess();

}