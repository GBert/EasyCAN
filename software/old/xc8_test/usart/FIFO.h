#ifndef _FIFO_
#define _FIFO_

#include "HardwareProfile.h"

#define NUMBER_OF_BUFFERS 1

#define FIFO_START  0
#define FIFO_LEN    64
#define FIFO_MASK   0x3F

extern BYTE bFIFOBuffer[NUMBER_OF_BUFFERS][FIFO_LEN];

extern WORD wHeadPtr[NUMBER_OF_BUFFERS];
extern WORD wTailPtr[NUMBER_OF_BUFFERS];
extern WORD wUsedSpace[NUMBER_OF_BUFFERS];

extern void FIFOInit(void);
extern void FIFOClear(WORD bNum);
extern void FIFOPut(WORD bNum, BYTE b);
extern BYTE FIFOGet(WORD bNum);
extern void FIFOPutPacket(WORD bNum, BYTE *pBuffer, WORD wLen);
extern void FIFOGetPacket(WORD bNum, BYTE *pBuffer, WORD wLen);
extern WORD FIFOUsedSpace(WORD bNum);
extern WORD FIFOFreeSpace(WORD bNum);

#endif
