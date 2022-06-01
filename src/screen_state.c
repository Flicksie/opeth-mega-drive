#include "screen_state.h"

void seedUpdate() {
    if (globalSeed > 65000) globalSeed = 0;
    globalSeed+= 1;
}