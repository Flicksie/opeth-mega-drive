****************************************************************
*
* Gens KMod debugging stuff
*
* history
*		041206: initial release
*		061029: added AlertNumber
*
****************************************************************

* Important note :
* m68k calling convention says that, between function calls,
* d0,d1,a0,a1 can be used as scratch registers, however,
* others should be preserved and
* return value -if there is- is placed in d0

#define PORT_VDP_DATA        0xc00000
#define PORT_VDP_CNTL        0xc00004


**************
* Pause Gens *
**************
	.globl	Debug_Halt
Debug_Halt:
	move.w	#0x9D00, 0xC00004
	rts

**************************************
* Show a text on Gens Message window *
**************************************
	.globl	Debug_Alert
Debug_Alert:
* %a0 = uchar *string
	movea.l  4(%sp), %a0             | get the first parameter (note that (%sp) is the return address)
	move.w   #0x9e00, %d0
	move.b   (%a0)+, %d0             | write null-termiated string byte by byte to port #0x1e
	beq.s    1f                      | zero length string? no, thanks.
	movea.l  #PORT_VDP_CNTL, %a1

0:
	move.w   %d0, (%a1)
	move.b   (%a0)+, %d0
	bne.s    0b

	move.w   %d0, (%a1)              | session ends with a 0 write to port #0x1e
1:
	rts

****************************************
* Show a number on Gens Message window *
****************************************
	.globl	Debug_AlertNumber
Debug_AlertNumber:
* %a0 = ulong number
	move.l   4(%sp), %a0
	move.w	 #7, %d1								| DBRA only deal with signed word

numLoop:	
	move.l   	%a0, %d0
	lsr.l			#8, %d0
	lsr.l			#8, %d0
	lsr.l			#8, %d0
	lsr.l			#4, %d0								| lsr.l #28,%d0 => hint to avoid %d2 use, needed for +8 shift
	and.l			#0xF, %d0

* number or hexa-letter needed ?	
	cmp.l			#9,	%d0
	bhi.s			letter

number:	
	addi.l		#48, %d0
	bra.s			ascii	
	
letter:
	addi.l		#55, %d0

* write it on special debug register	
ascii:
	add.w			#0x9e00, %d0
	move.w    %d0, (PORT_VDP_CNTL)

* 
	move.l   	%a0, %d0
	lsl.l		 	#4, %d0
	move.l   	%d0, %a0


	dbra 		 	%d1, numLoop

	move.w   #0x9e00, %d0
	move.w    %d0, (PORT_VDP_CNTL)
1:
	rts


***************
* Start Timer *
***************
	.globl	Debug_StartTimer
Debug_StartTimer:
	move.w	#0x9F80, PORT_VDP_CNTL

	rts
	
**************
* Stop Timer *
**************
	.globl	Debug_StopTimer
Debug_StopTimer:
	move.w	#0x9F40, PORT_VDP_CNTL
	rts
