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

/** @file CanDrv.h
 */

#ifndef CANDRV_H_
#define CANDRV_H_

#include <CommonTypes.h>

#include <ComStackTypes.h>

#if (CONFIG_CANDRV_EXTADDR == TRUE)
/** flag to mark a CAN ID as a 29bit Identifier */
#  define CANDRV_ID_IS_29BIT 0x80000000
#endif

/** configure the number of buffers used for the fifo */
#define CANDRV_RX_FIFO_SIZE 8u

/** Interrupt service routine for CAN Interrupts. */
#define CANDRV_ISR() CanDrv_MainFunction()

typedef enum CanDrv_BauderateEnum 
{
  CANDRV_BR_1M = 0,
  CANDRV_BR_500k,
  CANDRV_BR_250k,
  CANDRV_BR_125k,
  CANDRV_BR_LAST
}CanDrv_BauderateType;

/* configuration settings for the CAN */
typedef struct CanDrv_ControllerCfgSt 
{
  uint8 prescale;
  uint8 sjw;
  uint8 prseg;
  uint8 seg1ph;
  uint8 seg2ph;
} CanDrv_ControllerCfgType;

/** Init the CAN controller. */
void CanDrv_Init( CanDrv_BauderateType br );

/** Function can be called cyclically (in polling mode) or
   in the interrupt context as a ISR handler. */
void CanDrv_MainFunction( void );

/** Send a message via CAN. */
bool CanDrv_SendMessage( Com_PduDataType* data );

/** Reset all CAN message filters */
void CanDrv_ResetFilterMask( void );

/** Add a new CAN message filter. */
uint8 CanDrv_SetFilter( Com_BusIdType id, uint8 maskid );

/** Callback function prototype. */
Com_PduDataType* CanDrv_CB_RequestBuffer( Com_BusIdType id, uint8 dlc );

/** Callback function prototype. */
void CanDrv_CB_Receive( Com_PduDataType* dptr );

#endif /* CANDRV_H_ */
