#ifndef KONAMI_CODE_H
#define KONAMI_CODE_H

void konamiInput(u16 joy, u16 changed, u16 state);
void konamiRoutine();

extern int konami_progress;
extern int konami_timer;

bool konami_triggered;

#endif