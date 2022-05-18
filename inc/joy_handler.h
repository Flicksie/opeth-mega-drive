#ifndef JOY_HANDLER_H
#define JOY_HANDLER_H

void joyHandlerTitle(u16 joy, u16 changed, u16 state);
void joyHandlerMenu(u16 joy, u16 changed, u16 state);
void konami(u16 joy, u16 changed, u16 state);

extern int konamiSeq;
extern int konamiTimer;
bool konamiPositive;

#endif