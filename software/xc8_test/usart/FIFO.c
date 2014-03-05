#include "FIFO.h"

BYTE bFIFOBuffer[NUMBER_OF_BUFFERS][FIFO_LEN];

WORD wHeadPtr[NUMBER_OF_BUFFERS];
WORD wTailPtr[NUMBER_OF_BUFFERS];
WORD wUsedSpace[NUMBER_OF_BUFFERS];

void FIFOInit(void)
{
    WORD i;

    for (i = 0; i < NUMBER_OF_BUFFERS; i++)
    {
        wHeadPtr[i] = 0;
        wTailPtr[i] = 0;
        wUsedSpace[i] = 0;
    }
}

void FIFOClear(WORD bNum)
{
	wHeadPtr[bNum] = 0;
	wTailPtr[bNum] = 0;
	wUsedSpace[bNum] = 0;
}

void FIFOPut(WORD bNum, BYTE b)
{
    WORD wHeadPtrShadow;
    WORD wUsedSpaceShadow;

    wHeadPtrShadow = wHeadPtr[bNum];
    wUsedSpaceShadow = wUsedSpace[bNum];

    bFIFOBuffer[bNum][wHeadPtrShadow] = b;

    wUsedSpaceShadow++;
    wHeadPtrShadow++;
    wHeadPtrShadow &= FIFO_MASK;

    wHeadPtr[bNum] = wHeadPtrShadow;
    wUsedSpace[bNum] = wUsedSpaceShadow;
}

BYTE FIFOGet(WORD bNum)
{
    BYTE res;
    WORD wTailPtrShadow;
    WORD wUsedSpaceShadow;

    wTailPtrShadow = wTailPtr[bNum];
    wUsedSpaceShadow = wUsedSpace[bNum];

    res = bFIFOBuffer[bNum][wTailPtrShadow];

    wUsedSpaceShadow--;
    wTailPtrShadow++;
    wTailPtrShadow &= FIFO_MASK;

    wTailPtr[bNum] = wTailPtrShadow;
    wUsedSpace[bNum] = wUsedSpaceShadow;

    return res;
}

void FIFOPutPacket(WORD bNum, BYTE *pBuffer, WORD wLen)
{
    WORD wHeadPtrShadow;
    WORD wUsedSpaceShadow;
    WORD wLenShadow;

    wLenShadow = wLen;

    wHeadPtrShadow = wHeadPtr[bNum];
    wUsedSpaceShadow = wUsedSpace[bNum];

    while (wLen--)
    {
        bFIFOBuffer[bNum][wHeadPtrShadow] = *pBuffer++;
        wHeadPtrShadow++;
        wHeadPtrShadow &= FIFO_MASK;
    }

    wUsedSpaceShadow += wLenShadow; 

    wHeadPtr[bNum] = wHeadPtrShadow;
    wUsedSpace[bNum] = wUsedSpaceShadow;
}

void FIFOGetPacket(WORD bNum, BYTE *pBuffer, WORD wLen)
{
    WORD wTailPtrShadow;
    WORD wUsedSpaceShadow;
    WORD wLenShadow;

    wLenShadow = wLen;

    wTailPtrShadow = wTailPtr[bNum];
    wUsedSpaceShadow = wUsedSpace[bNum];

    while (wLen--)
    {
        *pBuffer++ = bFIFOBuffer[bNum][wTailPtrShadow];
        wTailPtrShadow++;
        wTailPtrShadow &= FIFO_MASK;
    }

    wUsedSpaceShadow -= wLenShadow;
    
    wTailPtr[bNum] = wTailPtrShadow;
    wUsedSpace[bNum] = wUsedSpaceShadow;
}

WORD FIFOFreeSpace(WORD bNum)
{
    return FIFO_LEN - wUsedSpace[bNum];
}

WORD FIFOUsedSpace(WORD bNum)
{
    return wUsedSpace[bNum];
}
