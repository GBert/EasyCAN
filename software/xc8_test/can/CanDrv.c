/*
 *  This file is part of:
 *
 *   techHomeAutomation - the open home automation platform
 *
 *  'techHomeAutomation' is free software: you can redistribute it 
 *  and/or modify it under the terms of the GNU General Public License 
 *  as published by the Free Software Foundation, either version 3 of 
 *  the License, or (at your option) any later version.
 *
 *  'techHomeAutomation' is distributed in the hope that it will be 
 *  useful, but WITHOUT ANY WARRANTY; without even the implied warranty 
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 'techHomeAutomation'. 
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/** @file CanDrv.c
 */

#include <CommonTypes.h>

#include <CanDrv.h>

#include <p18cxxx.h>

/** can hardware register structure */
typedef struct
{
  uint8  CON;
  uint8  SIDH;
  uint8  SIDL;
  uint8  EIDH;
  uint8  EIDL;
  uint8  DLC;
  uint8  DATA_UB[8];
  uint8  CANSTAT;
  uint8  CANCON;
} CanHwObj;

/** can hardware filter structure */
typedef struct
{
  uint8  SIDH;
  uint8  SIDL;
  uint8  EIDH;
  uint8  EIDL;
} CanIdObj;

/** pointer to tx hardware buffer */
CanHwObj* CanDrv_TxHwObj = (CanHwObj*)&TXB0CON;
/** pointer to filter buffer */
CanIdObj* CanDrv_FilterObj = (CanIdObj*)&RXF0SIDH;
/** filter usage */
uint16 CanDrv_FilterCfg = 0;
/** CAN controller configuration  */
CONST CanDrv_ControllerCfgType CanDrv_Config[CANDRV_BR_LAST] =
{
  { 0x01, 0x00, 0x07, 0x02, 0x07 }, /* CANDRV_BR_1M */
  { 0x02, 0x00, 0x07, 0x02, 0x07 }, /* CANDRV_BR_500k */
  { 0x03, 0x00, 0x07, 0x02, 0x07 }, /* CANDRV_BR_250k */
  { 0x0f, 0x00, 0x01, 0x02, 0x01 }  /* CANDRV_BR_125k */
};

/** local function to get messages from the RX fifo */
static bool CanDrv_GetMessage( void );

void CanDrv_Init( CanDrv_BauderateType br )
{
  uint8 i, buffer;
  
  /* set controller to configuration mode */
  CANCON = 0x80 ;
  while(( CANSTAT & 0xE0) != 0x80  );

  /* set fifo mode, set output to push-pull */
  ECANCON = 0xA0;
  CIOCON  = 0x20;

  /* configure the bauderate */
  buffer  = CanDrv_Config[br].prescale & 0x1f; /* bauderate pre scaler */
  buffer |= (CanDrv_Config[br].sjw << 6);
  BRGCON1 = buffer;
  buffer  = (CanDrv_Config[br].seg1ph << 3) & 0x38;
  buffer |= (CanDrv_Config[br].prseg & 0x7);
  buffer |= 0x80;
  BRGCON2 = buffer;
  buffer  = (CanDrv_Config[br].seg2ph & 0x7);
  BRGCON3 = buffer;

  i = 0;
  while(i < CANDRV_RX_FIFO_SIZE)
  {
    buffer = (ECANCON & 0xe0);
    ECANCON = (buffer|i);
    
    RXB0CON = 0;

    i++;
  }

  {
    /* load the mask values */
    CanIdObj* mask = (CanIdObj*)&RXM0SIDH;
	Com_BusIdType mbuffer = CONFIG_CANDRV_MASK0;
	
#if ((CONFIG_CANDRV_EXTADDR==TRUE) && (CONFIG_CANDRV_MASK0>0x80000000))
    if( ((mbuffer >> 31) & 0x1u) == 1 )
	{
      mask[0].EIDL = (mbuffer & 0xff);
      mbuffer = mbuffer >> 8;
      mask[0].EIDH = (mbuffer & 0xff);
      mbuffer = mbuffer >> 8;
      mask[0].SIDL = (mbuffer & 0x03) | 0x8 /* EXIDE */;
      mbuffer = mbuffer >> 2;
      mask[0].SIDL |= ((mbuffer << 5) & 0xe0);
      mbuffer = mbuffer >> 3;
      mask[0].SIDH = (mbuffer & 0xff);
	}
    else
#endif
    {
      mask[0].SIDL = (mbuffer & 0xe0) << 5;
      mask[0].SIDH = ((mbuffer>>3) & 0xff);
    }

    mbuffer = CONFIG_CANDRV_MASK1;
#if ((CONFIG_CANDRV_EXTADDR==TRUE) && (CONFIG_CANDRV_MASK1>0x80000000))
    if( ((mbuffer >> 31) & 0x1u) == 1 )
	{
      mask[1].EIDL = (mbuffer & 0xff);
      mbuffer = mbuffer >> 8;
      mask[1].EIDH = (mbuffer & 0xff);
      mbuffer = mbuffer >> 8;
      mask[1].SIDL = (mbuffer & 0x03) | 0x8 /* EXIDE */;
      mbuffer = mbuffer >> 2;
      mask[1].SIDL |= ((mbuffer << 5) & 0xe0);
      mbuffer = mbuffer >> 3;
      mask[1].SIDH = (mbuffer & 0xff);
	}
    else
#endif
    {
      mask[1].SIDL = (mbuffer & 0xe0) << 5;
      mask[1].SIDH = ((mbuffer>>3) & 0xff);
    }
  }
  
  RXFCON0 = 0x00;
  RXFCON1 = 0x00;

  MSEL0 = 0x00;
  MSEL1 = 0x00;
  MSEL2 = 0x00;
  MSEL3 = 0x00;

  /* switch to normal mode */
  CANCON = 0x00;
  while((CANSTAT & 0xe0) != 0x00u);
}

void CanDrv_MainFunction( void )
{
  /* poll the receive function */
  while(CanDrv_GetMessage() != TRUE)
  {
    ;
  }
}

static bool CanDrv_GetMessage( void )
{
  bool result = FALSE;

  /* check if a message was received */ 
  if( 0x80 == (COMSTAT & 0x80)) 
  {
    uint8 fifo_ptr;
    uint8 dlc;
    uint8 i;
    Com_BusIdType id;
    Com_PduDataType *dptr;

    /* update the buffer pointer for fifo */
    fifo_ptr = (CANCON & 0x0F);
    fifo_ptr |= (0x10 | (ECANCON & 0xE0));
    ECANCON = fifo_ptr;

    /* get the message ID */
#if (CONFIG_CANDRV_EXTADDR==TRUE)
	if(RXB0SIDLbits.EXID != 0u)
	{
	  id = 0x400;
	  id |= RXB0SIDH;
	  id <<= 3;
	  id |= ((RXB0SIDL >> 5) & 0x07);
	  id <<= 2;
	  id |= (RXB0SIDL & 0x03);
	  id <<= 8;
	  id |= RXB0EIDH;
	  id <<= 8;
	  id |= RXB0EIDL;
	}
	else
#endif
    {
	  /* bit 3..11 */
	  id = RXB0SIDH;
	  id <<= 3;
	  /* bit 0..2 */
	  id |= (RXB0SIDL >> 5) & 0x7;
	}


    /* data length */
    dlc = RXB0DLC;

    /* get the buffer from the upper layer */
    dptr = CanDrv_CB_RequestBuffer( id, dlc );

    /* store the dlc */
    dptr->dlc = dlc;
	/* store the id */
    dptr->id = id;

    /* copy data */
    i = 0;
    while(!(i >= dlc))
    {
      dptr->data[i] = ((uint8*)&RXB0D0)[i];
      i++;
    }
	
	/* return the buffer to upper layer */
	CanDrv_CB_Receive( dptr );
	
    /* ack and free the message buffer */
    RXB0CONbits.RXFUL = 0;
  }
  else
  {
    result = TRUE;
  }

  return result;
}

bool CanDrv_SendMessage( Com_PduDataType* data )
{
  bool result = FALSE;
  uint8 i;
  uint8 dlc;
  Com_BusIdType buffer;
  
  if(TXB0CONbits.TXREQ == 0u)
  {
    CanDrv_TxHwObj = (CanHwObj*)&TXB0CON;
  }
  else if(TXB1CONbits.TXREQ == 0u)
  {
    CanDrv_TxHwObj = (CanHwObj*)&TXB1CON;
  }
  else if(TXB2CONbits.TXREQ == 0u)
  {
    CanDrv_TxHwObj = (CanHwObj*)&TXB2CON;
  }
  else
  {
    result = TRUE;
  }

  if(result == FALSE)
  {
    /* load the id register */
    buffer = data->id;
#if (CONFIG_CANDRV_EXTADDR==TRUE)
    if( ((buffer >> 31) & 0x1) == 1u )
	{
      CanDrv_TxHwObj->EIDL = (buffer & 0xff);
      buffer = buffer >> 8;
      CanDrv_TxHwObj->EIDH = (buffer & 0xff);
      buffer = buffer >> 8;
      CanDrv_TxHwObj->SIDL = (buffer & 0x03) | 0x8 /* EXIDE */;
      buffer = buffer >> 2;
      CanDrv_TxHwObj->SIDL |= ((buffer << 5) & 0xe0);
      buffer = buffer >> 3;
      CanDrv_TxHwObj->SIDH = (buffer & 0xff);
	}
    else
#endif
    {
      CanDrv_TxHwObj->SIDL = (buffer << 5 );
      CanDrv_TxHwObj->SIDH = ( (buffer >> 3) & 0xff);
    }

    /* load the dlc */
	dlc = data->dlc;
	CanDrv_TxHwObj->DLC = dlc;

    /* load the data */
    i = 0;
    while(!(i >= dlc))
    {
      ((uint8*)&CanDrv_TxHwObj->DATA_UB[0])[i] = data->data[i];
      i++;
    }
	
	/* trigger the transmit */
	CanDrv_TxHwObj->CON |= 0x08;

  }
  
  return result;
}

void CanDrv_ResetFilterMask( void )
{
  /* set controller to configuration mode */
  CANCON = 0x80 ;
  while(( CANSTAT & 0xE0) != 0x80  );
  
  RXFCON0 = 0;
  RXFCON1 = 0;
  
  /* switch to normal mode */
  CANCON = 0x00;
  while((CANSTAT & 0xe0) != 0x00u);

  CanDrv_FilterCfg = 0;
}

uint8 CanDrv_SetFilter( Com_BusIdType id, uint8 maskid )
{
  uint16 filter_cfg = CanDrv_FilterCfg;
  uint8 i = 0;
  
  while(((filter_cfg & 0x1) == 1u) && (i<=16u))
  {
    filter_cfg >>= 1;
    i++;
  }
  
  if(i < 16u)
  {
    /* load the id register */
#if (CONFIG_CANDRV_EXTADDR==TRUE)
    if( ((id >> 31) & 0x1) == 1u )
    {
      CanDrv_FilterObj[i].EIDL = (id & 0xff);
      id = id >> 8;
      CanDrv_FilterObj[i].EIDH = (id & 0xff);
      id = id >> 8;
      CanDrv_FilterObj[i].SIDL = (id & 0x03) | 0x8 /* EXIDE */;
      id = id >> 2;
      CanDrv_FilterObj[i].SIDL |= ((id << 5) & 0xe0);
      id = id >> 3;
      CanDrv_FilterObj[i].SIDH = (id & 0xff);
    }
    else
#endif
    {
      CanDrv_FilterObj[i].SIDL = (id & 0xe0) << 5;
      CanDrv_FilterObj[i].SIDH = ((id>>3) & 0xff);
    }
    
    maskid &= 0x03;

    /* set controller to configuration mode */
    CANCON = 0x80 ;
    while(( CANSTAT & 0xE0) != 0x80u  );

    if( i < 4u )
    {
      uint8 lsh = (i*2);
      MSEL0 |= (maskid<<lsh);
    }
    else if( i < 8u )
    {
      uint8 lsh = ((i-4)*2);
      MSEL1 |= (maskid<<lsh);
    }
    else if( i < 12u )
    {
      uint8 lsh = ((i-8)*2);
      MSEL2 |= (maskid<<lsh);
    }
    else
    {
      uint8 lsh = ((i-12)*2);
      MSEL3 = (maskid<<lsh);
    }
    
    if( i < 15u )
    {
      RXFCON0 |= (1 << i);
    }
    else
    {
      RXFCON1 |= (1 << (i-16));
    }
    
    /* switch to normal mode */
    CANCON = 0x00;
    while((CANSTAT & 0xe0) != 0x00u);

    CanDrv_FilterCfg |= (1<<i);
  }
  else
  {
    i = 0xff;
  }
  
  return i;
}

/* EOF */
