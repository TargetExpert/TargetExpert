/*********************************************************************

          File: PinDesc.h

   Description: PIC Pin Description Header Part.

        Author: Jinseong Jeon (aimer120@nate.com)

       Created: 2019/10/08

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _PINDESC_H_
#define _PINDESC_H_

#include "Target.def.h"
#include "BitSet.mac.h"
#include "PIC_BitSet.mac.h"

/*
#define DECL_PORT_TRIS_WRITE_B(__RegName, __BitName, __PhriAlpha, __PinNum, __Value) \
  __RegName##__PhriAlpha |= (((__Value) ? 1 : 0) << __BitName##__PhriAlpha##__PinNum)
*/

#define DECL_PORT_TRIS_WRITE_B(__RegName, __BitName, __PhriAlpha, __PinNum, __Value) \
  slcb_reg_common(__RegName, , __PhriAlpha, __Value, __BitName##__PhriAlpha, , __PinNum)

#define DECL_PORT_TRIS_READ_B(__RegName, __BitName, __PhriAlpha, __PinNum) \
  (bit_is_set(__RegName##__PhriAlpha, __BitName##__PhriAlpha##__PinNum) ? 1 : 0)

// Read & Write Definitions for Port & TRIS A.
#if defined(PORTA)
#if defined(_RA0)
#define PORTA_0R DECL_PORT_TRIS_READ_B(PORT, _R, A, 0)
#define PORTA_0W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, A, 0, __Value)
#define TRISA_0R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, A, 0)
#define TRISA_0W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, A, 0, __Value)
#endif
#if defined(_RA1)
#define PORTA_1R DECL_PORT_TRIS_READ_B(PORT, _R, A, 1)
#define PORTA_1W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, A, 1, __Value)
#define TRISA_1R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, A, 1)
#define TRISA_1W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, A, 1, __Value)
#endif
#if defined(_RA2)
#define PORTA_2R DECL_PORT_TRIS_READ_B(PORT, _R, A, 2)
#define PORTA_2W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, A, 2, __Value)
#define TRISA_2R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, A, 2)
#define TRISA_2W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, A, 2, __Value)
#endif
#if defined(_RA3)
#define PORTA_3R DECL_PORT_TRIS_READ_B(PORT, _R, A, 3)
#define PORTA_3W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, A, 3, __Value)
#define TRISA_3R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, A, 3)
#define TRISA_3W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, A, 3, __Value)
#endif
#if defined(_RA4)
#define PORTA_4R DECL_PORT_TRIS_READ_B(PORT, _R, A, 4)
#define PORTA_4W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, A, 4, __Value)
#define TRISA_4R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, A, 4)
#define TRISA_4W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, A, 4, __Value)
#endif
#if defined(_RA5)
#define PORTA_5R DECL_PORT_TRIS_READ_B(PORT, _R, A, 5)
#define PORTA_5W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, A, 5, __Value)
#define TRISA_5R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, A, 5)
#define TRISA_5W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, A, 5, __Value)
#endif
#endif

// Read & Write Definitions for Port & TRIS B
#if defined(PORTB)
#if defined(_RB0)
#define PORTB_0R DECL_PORT_TRIS_READ_B(PORT, _R, B, 0)
#define PORTB_0W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, B, 0, __Value)
#define TRISB_0R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, B, 0)
#define TRISB_0W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, B, 0, __Value)
#endif
#if defined(_RB1)
#define PORTB_1R DECL_PORT_TRIS_READ_B(PORT, _R, B, 1)
#define PORTB_1W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, B, 1, __Value)
#define TRISB_1R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, B, 1)
#define TRISB_1W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, B, 1, __Value)
#endif
#if defined(_RB2)
#define PORTB_2R DECL_PORT_TRIS_READ_B(PORT, _R, B, 2)
#define PORTB_2W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, B, 2, __Value)
#define TRISB_2R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, B, 2)
#define TRISB_2W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, B, 2, __Value)
#endif
#if defined(_RB3)
#define PORTB_3R DECL_PORT_TRIS_READ_B(PORT, _R, B, 3)
#define PORTB_3W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, B, 3, __Value)
#define TRISB_3R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, B, 3)
#define TRISB_3W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, B, 3, __Value)
#endif
#if defined(_RB4)
#define PORTB_4R DECL_PORT_TRIS_READ_B(PORT, _R, B, 4)
#define PORTB_4W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, B, 4, __Value)
#define TRISB_4R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, B, 4)
#define TRISB_4W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, B, 4, __Value)
#endif
#if defined(_RB5)
#define PORTB_5R DECL_PORT_TRIS_READ_B(PORT, _R, B, 5)
#define PORTB_5W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, B, 5, __Value)
#define TRISB_5R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, B, 5)
#define TRISB_5W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, B, 5, __Value)
#endif
#if defined(_RB6)
#define PORTB_6R DECL_PORT_TRIS_READ_B(PORT, _R, B, 6)
#define PORTB_6W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, B, 6, __Value)
#define TRISB_6R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, B, 6)
#define TRISB_6W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, B, 6, __Value)
#endif
#if defined(_RB7)
#define PORTB_7R DECL_PORT_TRIS_READ_B(PORT, _R, B, 7)
#define PORTB_7W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, B, 7, __Value)
#define TRISB_7R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, B, 7)
#define TRISB_7W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, B, 7, __Value)
#endif
#endif

// Read & Write Definitions for Port & TRIS C
#if defined(PORTC)
#if defined(_RC0)
#define PORTC_0R DECL_PORT_TRIS_READ_B(PORT, _R, C, 0)
#define PORTC_0W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, C, 0, __Value)
#define TRISC_0R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, C, 0)
#define TRISC_0W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, C, 0, __Value)
#endif
#if defined(_RC1)
#define PORTC_1R DECL_PORT_TRIS_READ_B(PORT, _R, C, 1)
#define PORTC_1W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, C, 1, __Value)
#define TRISC_1R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, C, 1)
#define TRISC_1W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, C, 1, __Value)
#endif
#if defined(_RC2)
#define PORTC_2R DECL_PORT_TRIS_READ_B(PORT, _R, C, 2)
#define PORTC_2W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, C, 2, __Value)
#define TRISC_2R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, C, 2)
#define TRISC_2W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, C, 2, __Value)
#endif
#if defined(_RC3)
#define PORTC_3R DECL_PORT_TRIS_READ_B(PORT, _R, C, 3)
#define PORTC_3W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, C, 3, __Value)
#define TRISC_3R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, C, 3)
#define TRISC_3W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, C, 3, __Value)
#endif
#if defined(_RC4)
#define PORTC_4R DECL_PORT_TRIS_READ_B(PORT, _R, C, 4)
#define PORTC_4W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, C, 4, __Value)
#define TRISC_4R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, C, 4)
#define TRISC_4W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, C, 4, __Value)
#endif
#if defined(_RC5)
#define PORTC_5R DECL_PORT_TRIS_READ_B(PORT, _R, C, 5)
#define PORTC_5W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, C, 5, __Value)
#define TRISC_5R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, C, 5)
#define TRISC_5W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, C, 5, __Value)
#endif
#if defined(_RC6)
#define PORTC_6R DECL_PORT_TRIS_READ_B(PORT, _R, C, 6)
#define PORTC_6W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, C, 6, __Value)
#define TRISC_6R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, C, 6)
#define TRISC_6W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, C, 6, __Value)
#endif
#if defined(_RC7)
#define PORTC_7R DECL_PORT_TRIS_READ_B(PORT, _R, C, 7)
#define PORTC_7W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, C, 7, __Value)
#define TRISC_7R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, C, 7)
#define TRISC_7W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, C, 7, __Value)
#endif
#endif

// Read & Write Definitions for Port & TRIS D
#if defined(PORTD)
#if defined(_RD0)
#define PORTD_0R DECL_PORT_TRIS_READ_B(PORT, _R, D, 0)
#define PORTD_0W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, D, 0, __Value)
#define TRISD_0R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, D, 0)
#define TRISD_0W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, D, 0, __Value)
#endif
#if defined(_RD1)
#define PORTD_1R DECL_PORT_TRIS_READ_B(PORT, _R, D, 1)
#define PORTD_1W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, D, 1, __Value)
#define TRISD_1R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, D, 1)
#define TRISD_1W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, D, 1, __Value)
#endif
#if defined(_RD2)
#define PORTD_2R DECL_PORT_TRIS_READ_B(PORT, _R, D, 2)
#define PORTD_2W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, D, 2, __Value)
#define TRISD_2R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, D, 2)
#define TRISD_2W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, D, 2, __Value)
#endif
#if defined(_RD3)
#define PORTD_3R DECL_PORT_TRIS_READ_B(PORT, _R, D, 3)
#define PORTD_3W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, D, 3, __Value)
#define TRISD_3R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, D, 3)
#define TRISD_3W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, D, 3, __Value)
#endif
#if defined(_RD4)
#define PORTD_4R DECL_PORT_TRIS_READ_B(PORT, _R, D, 4)
#define PORTD_4W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, D, 4, __Value)
#define TRISD_4R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, D, 4)
#define TRISD_4W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, D, 4, __Value)
#endif
#if defined(_RD5)
#define PORTD_5R DECL_PORT_TRIS_READ_B(PORT, _R, D, 5)
#define PORTD_5W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, D, 5, __Value)
#define TRISD_5R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, D, 5)
#define TRISD_5W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, D, 5, __Value)
#endif
#if defined(_RD6)
#define PORTD_6R DECL_PORT_TRIS_READ_B(PORT, _R, D, 6)
#define PORTD_6W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, D, 6, __Value)
#define TRISD_6R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, D, 6)
#define TRISD_6W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, D, 6, __Value)
#endif
#if defined(_RD7)
#define PORTD_7R DECL_PORT_TRIS_READ_B(PORT, _R, D, 7)
#define PORTD_7W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, D, 7, __Value)
#define TRISD_7R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, D, 7)
#define TRISD_7W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, D, 7, __Value)
#endif
#endif

// Read & Write Definitions for Port & TRIS E
#if defined(PORTE)
#if defined(_RE0)
#define PORTE_0R DECL_PORT_TRIS_READ_B(PORT, _R, E, 0)
#define PORTE_0W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, E, 0, __Value)
#define TRISE_0R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, E, 0)
#define TRISE_0W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, E, 0, __Value)
#endif
#if defined(_RE1)
#define PORTE_1R DECL_PORT_TRIS_READ_B(PORT, _R, E, 1)
#define PORTE_1W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, E, 1, __Value)
#define TRISE_1R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, E, 1)
#define TRISE_1W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, E, 1, __Value)
#endif
#if defined(_RE2)
#define PORTE_2R DECL_PORT_TRIS_READ_B(PORT, _R, E, 2)
#define PORTE_2W(__Value) DECL_PORT_TRIS_WRITE_B(PORT, _R, E, 2, __Value)
#define TRISE_2R DECL_PORT_TRIS_READ_B(TRIS, _TRIS, E, 2)
#define TRISE_2W(__Value) DECL_PORT_TRIS_WRITE_B(TRIS, _TRIS, E, 2, __Value)
#endif
#endif


// Set Input & Output for TRIS A.
#if defined(PORTA)
#if defined(_RA0)
#define Set_Output_A0 TRISA_0W(false)
#define Set_Input_A0 TRISA_0W(true)
#define Get_IOStat_A0 TRISA_0R
#endif
#if defined(_RA1)
#define Set_Output_A1 TRISA_1W(false)
#define Set_Input_A1 TRISA_1W(true)
#define Get_IOStat_A1 TRISA_1R
#endif
#if defined(_RA2)
#define Set_Output_A2 TRISA_2W(false)
#define Set_Input_A2 TRISA_2W(true)
#define Get_IOStat_A2 TRISA_2R
#endif
#if defined(_RA3)
#define Set_Output_A3 TRISA_3W(false)
#define Set_Input_A3 TRISA_3W(true)
#define Get_IOStat_A3 TRISA_3R
#endif
#if defined(_RA4)
#define Set_Output_A4 TRISA_4W(false)
#define Set_Input_A4 TRISA_4W(true)
#define Get_IOStat_A4 TRISA_4R
#endif
#if defined(_RA5)
#define Set_Output_A5 TRISA_5W(false)
#define Set_Input_A5 TRISA_5W(true)
#define Get_IOStat_A5 TRISA_5R
#endif
#endif

// Set Input & Output for TRIS B.
#if defined(PORTB)
#if defined(_RB0)
#define Set_Output_B0 TRISB_0W(false)
#define Set_Input_B0 TRISB_0W(true)
#define Get_IOStat_B0 TRISB_0R
#endif
#if defined(_RB1)
#define Set_Output_B1 TRISB_1W(false)
#define Set_Input_B1 TRISB_1W(true)
#define Get_IOStat_B1 TRISB_1R
#endif
#if defined(_RB2)
#define Set_Output_B2 TRISB_2W(false)
#define Set_Input_B2 TRISB_2W(true)
#define Get_IOStat_B2 TRISB_2R
#endif
#if defined(_RB3)
#define Set_Output_B3 TRISB_3W(false)
#define Set_Input_B3 TRISB_3W(true)
#define Get_IOStat_B3 TRISB_3R
#endif
#if defined(_RB4)
#define Set_Output_B4 TRISB_4W(false)
#define Set_Input_B4 TRISB_4W(true)
#define Get_IOStat_B4 TRISB_4R
#endif
#if defined(_RB5)
#define Set_Output_B5 TRISB_5W(false)
#define Set_Input_B5 TRISB_5W(true)
#define Get_IOStat_B5 TRISB_5R
#endif
#if defined(_RB6)
#define Set_Output_B6 TRISB_6W(false)
#define Set_Input_B6 TRISB_6W(true)
#define Get_IOStat_B6 TRISB_6R
#endif
#if defined(_RB7)
#define Set_Output_B7 TRISB_7W(false)
#define Set_Input_B7 TRISB_7W(true)
#define Get_IOStat_B7 TRISB_7R
#endif
#endif

// Set Input & Output for TRIS C.
#if defined(PORTC)
#if defined(_RC0)
#define Set_Output_C0 TRISC_0W(false)
#define Set_Input_C0 TRISC_0W(true)
#define Get_IOStat_C0 TRISC_0R
#endif
#if defined(_RC1)
#define Set_Output_C1 TRISC_1W(false)
#define Set_Input_C1 TRISC_1W(true)
#define Get_IOStat_C1 TRISC_1R
#endif
#if defined(_RC2)
#define Set_Output_C2 TRISC_2W(false)
#define Set_Input_C2 TRISC_2W(true)
#define Get_IOStat_C2 TRISC_2R
#endif
#if defined(_RC3)
#define Set_Output_C3 TRISC_3W(false)
#define Set_Input_C3 TRISC_3W(true)
#define Get_IOStat_C3 TRISC_3R
#endif
#if defined(_RC4)
#define Set_Output_C4 TRISC_4W(false)
#define Set_Input_C4 TRISC_4W(true)
#define Get_IOStat_C4 TRISC_4R
#endif
#if defined(_RC5)
#define Set_Output_C5 TRISC_5W(false)
#define Set_Input_C5 TRISC_5W(true)
#define Get_IOStat_C5 TRISC_5R
#endif
#if defined(_RC6)
#define Set_Output_C6 TRISC_6W(false)
#define Set_Input_C6 TRISC_6W(true)
#define Get_IOStat_C6 TRISC_6R
#endif
#if defined(_RC7)
#define Set_Output_C7 TRISC_7W(false)
#define Set_Input_C7 TRISC_7W(true)
#define Get_IOStat_C7 TRISC_7R
#endif
#endif

// Set Input & Output for TRIS D.
#if defined(PORTD)
#if defined(_RD0)
#define Set_Output_D0 TRISD_0W(false)
#define Set_Input_D0 TRISD_0W(true)
#define Get_IOStat_D0 TRISD_0R
#endif
#if defined(_RD1)
#define Set_Output_D1 TRISD_1W(false)
#define Set_Input_D1 TRISD_1W(true)
#define Get_IOStat_D1 TRISD_1R
#endif
#if defined(_RD2)
#define Set_Output_D2 TRISD_2W(false)
#define Set_Input_D2 TRISD_2W(true)
#define Get_IOStat_D2 TRISD_2R
#endif
#if defined(_RD3)
#define Set_Output_D3 TRISD_3W(false)
#define Set_Input_D3 TRISD_3W(true)
#define Get_IOStat_D3 TRISD_3R
#endif
#if defined(_RD4)
#define Set_Output_D4 TRISD_4W(false)
#define Set_Input_D4 TRISD_4W(true)
#define Get_IOStat_D4 TRISD_4R
#endif
#if defined(_RD5)
#define Set_Output_D5 TRISD_5W(false)
#define Set_Input_D5 TRISD_5W(true)
#define Get_IOStat_D5 TRISD_5R
#endif
#if defined(_RD6)
#define Set_Output_D6 TRISD_6W(false)
#define Set_Input_D6 TRISD_6W(true)
#define Get_IOStat_D6 TRISD_6R
#endif
#if defined(_RD7)
#define Set_Output_D7 TRISD_7W(false)
#define Set_Input_D7 TRISD_7W(true)
#define Get_IOStat_D7 TRISD_7R
#endif
#endif

// Set Input & Output for TRIS E.
#if defined(PORTE)
#if defined(_RE0)
#define Set_Output_E0 TRISE_0W(false)
#define Set_Input_E0 TRISE_0W(true)
#define Get_IOStat_E0 TRISE_0R
#endif
#if defined(_RE1)
#define Set_Output_E1 TRISE_1W(false)
#define Set_Input_E1 TRISE_1W(true)
#define Get_IOStat_E1 TRISE_1R
#endif
#if defined(_RE2)
#define Set_Output_E2 TRISE_2W(false)
#define Set_Input_E2 TRISE_2W(true)
#define Get_IOStat_E2 TRISE_2R
#endif
#endif

#endif // _PINDESC_H_
