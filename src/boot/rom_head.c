#include "genesis.h"

__attribute__((externally_visible))
const ROMHeader rom_header = {
#if (ENABLE_BANK_SWITCH != 0)
    "SEGA SSF        ",
#else
    "SEGA MEGA DRIVE ",
#endif
    "(C)FLK 2022.MAY ",
    "OPETH MUSIC CARTRIDGE                           ",
    "OPETH MUSIC CARTRIDGE                           ",
    "GM 05502205-12",
//       ID YR # REV
    0x000,
    "J6              ",
    0x00000000,
#if (ENABLE_BANK_SWITCH != 0)
    0x003FFFFF,
#else
    0x000FFFFF,
#endif
    0xE0FF0000,
    0xE0FFFFFF,
    "RA",
    0xF820,
    0x00200000,
    0x0020FFFF,
    "            ",
    "DEMO DEMO WAWA                          ",
    "JUE             "
};