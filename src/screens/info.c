#include <genesis.h>

#include "screen_state.h"
#include "gfx.h"
#include "music.h"
#include "font.h"



void joyHandler(u16 joy, u16 changed, u16 state)
{
    if (state) currentState = STATE_MENU;
}

void infoScreen(){

    //VDP_fadeInAll(PAL1, 30,TRUE);
    XGM_startPlay(wpane_mini);

    JOY_setEventHandler(NULL); 
    JOY_init();
    JOY_setEventHandler(&joyHandler);
    VDP_loadFont(&font_default, DMA);

    
    PAL_setColor(15, 0xfff);
    PAL_setColor(47, 0x00f);
    PAL_setColor(31, 0x555);
    VDP_setTextPalette(PAL2);
    VDP_drawText("Disclaimer",15,1);
    VDP_setTextPalette(PAL0);
        
    VDP_drawText("Credit is due to the original owners ",1,3);
    VDP_drawText("of any copyrighted material contained",1,4);
    VDP_drawText("in this cartridge. Contents are not  ",1,5);
    VDP_drawText("licensed or endorsed by SEGA or OPETH",1,6);
    VDP_drawText("SEGA and OPETH logos are copyrighted ",1,8);
    VDP_drawText("by their respective owners.          ",1,9);
    
    VDP_drawText("Unauthorized selling of this free,fan-",1,11);
    
    VDP_drawText("made item is strongly discouraged.",1,12);

    VDP_setTextPalette(PAL1);
    VDP_drawText("           Created by Flosk using SGDK",1,15);
    VDP_drawText("      Based on Stephane-D's XGM Player",1,16);
    
    PAL_setColor(63, 0x0FF);
    VDP_setTextPalette(PAL3);
    VDP_drawText("           Special Thanks to",1,19);
    VDP_setTextPalette(PAL0);

    VDP_drawText("          Saitore     TheGaiel",1,21);
    VDP_drawText("          HighGen     Tenebru",1,22);



    VDP_setTextPalette(PAL1);
    VDP_drawText(" Die-hard Opeth fans and friends whose",1,24);
    VDP_drawText(" I dedicate this silly creation to.",1,25);

    int timer = 30;

    while(currentState == STATE_INFO){
        
        timer = 30;
        VDP_drawText("      PRESS ANY BUTTON TO RETURN      ",1,27);
        while(timer--){
            SYS_doVBlankProcess();
        }
        VDP_clearText(1,27,32);
        timer = 30;
        while(timer--){
            SYS_doVBlankProcess();
        }

        SYS_doVBlankProcess();
       
    }

    XGM_stopPlay();
    PAL_fadeOutAll(30, TRUE);
    //Cleanup

    JOY_setEventHandler(NULL);
    VDP_clearPlane(WINDOW, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    VDP_clearPlane(BG_A, TRUE);


}