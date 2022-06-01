#ifndef _INC_DEBUG_
#define _INC_DEBUG_


extern void Debug_Halt( );
extern void Debug_Alert(char *str);
extern void Debug_AlertNumber(ulong nVal);
extern void Debug_StartTimer( );
extern void Debug_StopTimer( );


#endif