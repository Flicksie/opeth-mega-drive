#include "types.h"
#include "joy.h"
#include "konami_code.h"


int konami_progress = 0;
int konami_timer = 60;
bool konami_triggered = FALSE;

void konamiInput(u16 joy, u16 changed, u16 state){
    
    konami_timer = 60;

    //    U U D D L R L R B A START 
    //    0 1 2 3 4 5 6 7 8 9 10


    if (state & BUTTON_UP)
    {
        if (konami_progress == 0 | konami_progress == 1 ) {
            konami_progress += 1;            
        }
        else konami_progress = 0;
    }
    else if (state & BUTTON_DOWN)
    {
        if (konami_progress == 2 | konami_progress == 3 ) {
            konami_progress += 1;            
        }
        else konami_progress = 0;
    }
    else if (state & BUTTON_LEFT)
    {
        if (konami_progress == 4 | konami_progress == 6) {
            konami_progress += 1;            
        }
        else konami_progress = 0;
    }
    else if (state & BUTTON_RIGHT)
    {
        if (konami_progress == 5 | konami_progress == 7 ) {
            konami_progress += 1;            
        }
        else konami_progress = 0;
    }
    else if (state & BUTTON_A)
    {
        if (konami_progress == 9 ) {
            konami_progress += 1;            
        }
        else konami_progress = 0;
    }
    else if (state & BUTTON_B)
    {
        if (konami_progress == 8 ) konami_progress += 1;
        else konami_progress = 0;
    }
    else if (state & BUTTON_START)
    {
        if (konami_progress == 10 ) konami_progress += 1;
        else konami_progress = 0;
    }
    

    if (konami_progress > 10 ) konami_triggered = TRUE;
    

}

void konamiRoutine(){
    if (konami_timer > 0) konami_timer--;
    if (konami_timer == 0) konami_progress = 0;
}