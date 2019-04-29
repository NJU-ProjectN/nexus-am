#ifndef PSG_H
#define PSG_H

#include "common.h"

extern unsigned char psg_joy1[8];

byte psg_io_read(word address);
void psg_io_write(word address, byte data);

#endif
