#include <genesis.h>

#include "screen_state.h"
#include "joy_handler.h"
#include "gfx.h"
#include "music.h"


#define ANIM_STAND 0
#define AKER_SEGA 64


Sprite* opsega_obj;
Sprite* sega_spr_red_obj;


void processStateMenu(){

    u16 timer = 200;
    u16 timer2 = 30;

    //Init
    JOY_setEventHandler(&joyHandlerMenu);

    XGM_setPCM(AKER_SEGA, akersega, sizeof(akersega));

    VDP_setPaletteColor(0, RGB24_TO_VDPCOLOR(0x000000));


    

    SPR_init();
    VDP_setPalette(PAL3, palette_black);
    opsega_obj = SPR_addSprite(&sega_spr, 1,  1, TILE_ATTR(PAL3, 0, FALSE, FALSE));
    SPR_setAnim(opsega_obj, ANIM_STAND);
    SPR_setPosition(opsega_obj, 110, 80);
    SPR_update();
    VDP_drawText("Opeth Sound Cartridge v0.1", 1, 26);
    PAL_fadeInPalette(3,sega_spr.palette->data,60,FALSE);
    while(timer2--){
        SYS_doVBlankProcess();
    };
    PAL_fadePalette(3,sega_spr.palette->data,sega_spr_red.palette->data,20,TRUE);
    timer2 = 10;
    while(timer2--){
        SYS_doVBlankProcess();
    };
    XGM_startPlayPCM(AKER_SEGA,1,SOUND_PCM_CH2);
    
        //                              X   Y

    

    //Update
    while(currentState == STATE_MENU){
        SPR_update();
        SYS_doVBlankProcess();
        timer--;
        if(timer == 0){
            currentState = STATE_PLAY;
        }
       
    }

    PAL_fadeOutPalette(3,30,FALSE);
    //Cleanup
    VDP_clearText(10, 13, 10);

}