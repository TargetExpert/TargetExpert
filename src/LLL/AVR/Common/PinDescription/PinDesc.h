/*********************************************************************

          File: PinDesc.h

   Description: AVR Pin Description Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/26

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _PinDesc_h_
#define _PinDesc_h_

#include "TargetDef.h"

// re-define Port & Pin.

// sbi(PORTA, PA0) to PORTA_0 = (0 or 1).
// PORT(Phriperal Alphabat)(Pin Number)

#define DECL_PORT_DDR_WRITE_B(__RegNameA, __RegNameB, __PhriAlpha, __PinNum, __Value) \
  __RegNameA##__RegNameB##__PhriAlpha |= (((__Value) ? 1 : 0) << __RegNameA##__PhriAlpha##__PinNum)

#define DECL_PORT_DDR_PIN_READ_B(__RegNameA, __RegNameB, __PhriAlpha, __PinNum) \
  (bit_is_set(__RegNameA##__RegNameB##__PhriAlpha, __RegNameA##__PhriAlpha##__PinNum) ? 1 : 0)

// Read & Write Definitions for Port & DDR & Pin A.
#if defined(PORTA)
#if defined(PORTA0)
#define PORTA_0R DECL_PORT_DDR_PIN_READ_B(PORT, , A, 0)
#define PORTA_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , A, 0, __Value)
#define DDRA_0R DECL_PORT_DDR_PIN_READ_B(DD, R, A, 0)
#define DDRA_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, A, 0, __Value)
#define PINA_0R DECL_PORT_DDR_PIN_READ_B(PIN, , A, 0)
#endif
#if defined(PORTA1)
#define PORTA_1R DECL_PORT_DDR_PIN_READ_B(PORT, , A, 1)
#define PORTA_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , A, 1, __Value)
#define DDRA_1R DECL_PORT_DDR_PIN_READ_B(DD, R, A, 1)
#define DDRA_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, A, 1, __Value)
#define PINA_1R DECL_PORT_DDR_PIN_READ_B(PIN, , A, 1)
#endif
#if defined(PORTA2)
#define PORTA_2R DECL_PORT_DDR_PIN_READ_B(PORT, , A, 2)
#define PORTA_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , A, 2, __Value)
#define DDRA_2R DECL_PORT_DDR_PIN_READ_B(DD, R, A, 2)
#define DDRA_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, A, 2, __Value)
#define PINA_2R DECL_PORT_DDR_PIN_READ_B(PIN, , A, 2)
#endif
#if defined(PORTA3)
#define PORTA_3R DECL_PORT_DDR_PIN_READ_B(PORT, , A, 3)
#define PORTA_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , A, 3, __Value)
#define DDRA_3R DECL_PORT_DDR_PIN_READ_B(DD, R, A, 3)
#define DDRA_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, A, 3, __Value)
#define PINA_3R DECL_PORT_DDR_PIN_READ_B(PIN, , A, 3)
#endif
#if defined(PORTA4)
#define PORTA_4R DECL_PORT_DDR_PIN_READ_B(PORT, , A, 4)
#define PORTA_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , A, 4, __Value)
#define DDRA_4R DECL_PORT_DDR_PIN_READ_B(DD, R, A, 4)
#define DDRA_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, A, 4, __Value)
#define PINA_4R DECL_PORT_DDR_PIN_READ_B(PIN, , A, 4)
#endif
#if defined(PORTA5)
#define PORTA_5R DECL_PORT_DDR_PIN_READ_B(PORT, , A, 5)
#define PORTA_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , A, 5, __Value)
#define DDRA_5R DECL_PORT_DDR_PIN_READ_B(DD, R, A, 5)
#define DDRA_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, A, 5, __Value)
#define PINA_5R DECL_PORT_DDR_PIN_READ_B(PIN, , A, 5)
#endif
#if defined(PORTA6)
#define PORTA_6R DECL_PORT_DDR_PIN_READ_B(PORT, , A, 6)
#define PORTA_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , A, 6, __Value)
#define DDRA_6R DECL_PORT_DDR_PIN_READ_B(DD, R, A, 6)
#define DDRA_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, A, 6, __Value)
#define PINA_6R DECL_PORT_DDR_PIN_READ_B(PIN, , A, 6)
#endif
#if defined(PORTA7)
#define PORTA_7R DECL_PORT_DDR_PIN_READ_B(PORT, , A, 7)
#define PORTA_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , A, 7, __Value)
#define DDRA_7R DECL_PORT_DDR_PIN_READ_B(DD, R, A, 7)
#define DDRA_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, A, 7, __Value)
#define PINA_7R DECL_PORT_DDR_PIN_READ_B(PIN, , A, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port B
#if defined(PORTB)
#if defined(PORTB0)
#define PORTB_0R DECL_PORT_DDR_PIN_READ_B(PORT, , B, 0)
#define PORTB_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , B, 0, __Value)
#define DDRB_0R DECL_PORT_DDR_PIN_READ_B(DD, R, B, 0)
#define DDRB_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, B, 0, __Value)
#define PINB_0R DECL_PORT_DDR_PIN_READ_B(PIN, , B, 0)
#endif
#if defined(PORTB1)
#define PORTB_1R DECL_PORT_DDR_PIN_READ_B(PORT, , B, 1)
#define PORTB_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , B, 1, __Value)
#define DDRB_1R DECL_PORT_DDR_PIN_READ_B(DD, R, B, 1)
#define DDRB_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, B, 1, __Value)
#define PINB_1R DECL_PORT_DDR_PIN_READ_B(PIN, , B, 1)
#endif
#if defined(PORTB2)
#define PORTB_2R DECL_PORT_DDR_PIN_READ_B(PORT, , B, 2)
#define PORTB_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , B, 2, __Value)
#define DDRB_2R DECL_PORT_DDR_PIN_READ_B(DD, R, B, 2)
#define DDRB_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, B, 2, __Value)
#define PINB_2R DECL_PORT_DDR_PIN_READ_B(PIN, , B, 2)
#endif
#if defined(PORTB3)
#define PORTB_3R DECL_PORT_DDR_PIN_READ_B(PORT, , B, 3)
#define PORTB_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , B, 3, __Value)
#define DDRB_3R DECL_PORT_DDR_PIN_READ_B(DD, R, B, 3)
#define DDRB_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, B, 3, __Value)
#define PINB_3R DECL_PORT_DDR_PIN_READ_B(PIN, , B, 3)
#endif
#if defined(PORTB4)
#define PORTB_4R DECL_PORT_DDR_PIN_READ_B(PORT, , B, 4)
#define PORTB_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , B, 4, __Value)
#define DDRB_4R DECL_PORT_DDR_PIN_READ_B(DD, R, B, 4)
#define DDRB_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, B, 4, __Value)
#define PINB_4R DECL_PORT_DDR_PIN_READ_B(PIN, , B, 4)
#endif
#if defined(PORTB5)
#define PORTB_5R DECL_PORT_DDR_PIN_READ_B(PORT, , B, 5)
#define PORTB_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , B, 5, __Value)
#define DDRB_5R DECL_PORT_DDR_PIN_READ_B(DD, R, B, 5)
#define DDRB_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, B, 5, __Value)
#define PINB_5R DECL_PORT_DDR_PIN_READ_B(PIN, , B, 5)
#endif
#if defined(PORTB6)
#define PORTB_6R DECL_PORT_DDR_PIN_READ_B(PORT, , B, 6)
#define PORTB_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , B, 6, __Value)
#define DDRB_6R DECL_PORT_DDR_PIN_READ_B(DD, R, B, 6)
#define DDRB_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, B, 6, __Value)
#define PINB_6R DECL_PORT_DDR_PIN_READ_B(PIN, , B, 6)
#endif
#if defined(PORTB7)
#define PORTB_7R DECL_PORT_DDR_PIN_READ_B(PORT, , B, 7)
#define PORTB_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , B, 7, __Value)
#define DDRB_7R DECL_PORT_DDR_PIN_READ_B(DD, R, B, 7)
#define DDRB_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, B, 7, __Value)
#define PINB_7R DECL_PORT_DDR_PIN_READ_B(PIN, , B, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port C
#if defined(PORTC)
#if defined(PORTC0)
#define PORTC_0R DECL_PORT_DDR_PIN_READ_B(PORT, , C, 0)
#define PORTC_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , C, 0, __Value)
#define DDRC_0R DECL_PORT_DDR_PIN_READ_B(DD, R, C, 0)
#define DDRC_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, C, 0, __Value)
#define PINC_0R DECL_PORT_DDR_PIN_READ_B(PIN, , C, 0)
#endif
#if defined(PORTC1)
#define PORTC_1R DECL_PORT_DDR_PIN_READ_B(PORT, , C, 1)
#define PORTC_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , C, 1, __Value)
#define DDRC_1R DECL_PORT_DDR_PIN_READ_B(DD, R, C, 1)
#define DDRC_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, C, 1, __Value)
#define PINC_1R DECL_PORT_DDR_PIN_READ_B(PIN, , C, 1)
#endif
#if defined(PORTC2)
#define PORTC_2R DECL_PORT_DDR_PIN_READ_B(PORT, , C, 2)
#define PORTC_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , C, 2, __Value)
#define DDRC_2R DECL_PORT_DDR_PIN_READ_B(DD, R, C, 2)
#define DDRC_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, C, 2, __Value)
#define PINC_2R DECL_PORT_DDR_PIN_READ_B(PIN, , C, 2)
#endif
#if defined(PORTC3)
#define PORTC_3R DECL_PORT_DDR_PIN_READ_B(PORT, , C, 3)
#define PORTC_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , C, 3, __Value)
#define DDRC_3R DECL_PORT_DDR_PIN_READ_B(DD, R, C, 3)
#define DDRC_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, C, 3, __Value)
#define PINC_3R DECL_PORT_DDR_PIN_READ_B(PIN, , C, 3)
#endif
#if defined(PORTC4)
#define PORTC_4R DECL_PORT_DDR_PIN_READ_B(PORT, , C, 4)
#define PORTC_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , C, 4, __Value)
#define DDRC_4R DECL_PORT_DDR_PIN_READ_B(DD, R, C, 4)
#define DDRC_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, C, 4, __Value)
#define PINC_4R DECL_PORT_DDR_PIN_READ_B(PIN, , C, 4)
#endif
#if defined(PORTC5)
#define PORTC_5R DECL_PORT_DDR_PIN_READ_B(PORT, , C, 5)
#define PORTC_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , C, 5, __Value)
#define DDRC_5R DECL_PORT_DDR_PIN_READ_B(DD, R, C, 5)
#define DDRC_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, C, 5, __Value)
#define PINC_5R DECL_PORT_DDR_PIN_READ_B(PIN, , C, 5)
#endif
#if defined(PORTC6)
#define PORTC_6R DECL_PORT_DDR_PIN_READ_B(PORT, , C, 6)
#define PORTC_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , C, 6, __Value)
#define DDRC_6R DECL_PORT_DDR_PIN_READ_B(DD, R, C, 6)
#define DDRC_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, C, 6, __Value)
#define PINC_6R DECL_PORT_DDR_PIN_READ_B(PIN, , C, 6)
#endif
#if defined(PORTC7)
#define PORTC_7R DECL_PORT_DDR_PIN_READ_B(PORT, , C, 7)
#define PORTC_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , C, 7, __Value)
#define DDRC_7R DECL_PORT_DDR_PIN_READ_B(DD, R, C, 7)
#define DDRC_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, C, 7, __Value)
#define PINC_7R DECL_PORT_DDR_PIN_READ_B(PIN, , C, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port D
#if defined(PORTD)
#if defined(PORTD0)
#define PORTD_0R DECL_PORT_DDR_PIN_READ_B(PORT, , D, 0)
#define PORTD_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , D, 0, __Value)
#define DDRD_0R DECL_PORT_DDR_PIN_READ_B(DD, R, D, 0)
#define DDRD_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, D, 0, __Value)
#define PIND_0R DECL_PORT_DDR_PIN_READ_B(PIN, , D, 0)
#endif
#if defined(PORTD1)
#define PORTD_1R DECL_PORT_DDR_PIN_READ_B(PORT, , D, 1)
#define PORTD_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , D, 1, __Value)
#define DDRD_1R DECL_PORT_DDR_PIN_READ_B(DD, R, D, 1)
#define DDRD_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, D, 1, __Value)
#define PIND_1R DECL_PORT_DDR_PIN_READ_B(PIN, , D, 1)
#endif
#if defined(PORTD2)
#define PORTD_2R DECL_PORT_DDR_PIN_READ_B(PORT, , D, 2)
#define PORTD_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , D, 2, __Value)
#define DDRD_2R DECL_PORT_DDR_PIN_READ_B(DD, R, D, 2)
#define DDRD_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, D, 2, __Value)
#define PIND_2R DECL_PORT_DDR_PIN_READ_B(PIN, , D, 2)
#endif
#if defined(PORTD3)
#define PORTD_3R DECL_PORT_DDR_PIN_READ_B(PORT, , D, 3)
#define PORTD_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , D, 3, __Value)
#define DDRD_3R DECL_PORT_DDR_PIN_READ_B(DD, R, D, 3)
#define DDRD_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, D, 3, __Value)
#define PIND_3R DECL_PORT_DDR_PIN_READ_B(PIN, , D, 3)
#endif
#if defined(PORTD4)
#define PORTD_4R DECL_PORT_DDR_PIN_READ_B(PORT, , D, 4)
#define PORTD_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , D, 4, __Value)
#define DDRD_4R DECL_PORT_DDR_PIN_READ_B(DD, R, D, 4)
#define DDRD_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, D, 4, __Value)
#define PIND_4R DECL_PORT_DDR_PIN_READ_B(PIN, , D, 4)
#endif
#if defined(PORTD5)
#define PORTD_5R DECL_PORT_DDR_PIN_READ_B(PORT, , D, 5)
#define PORTD_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , D, 5, __Value)
#define DDRD_5R DECL_PORT_DDR_PIN_READ_B(DD, R, D, 5)
#define DDRD_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, D, 5, __Value)
#define PIND_5R DECL_PORT_DDR_PIN_READ_B(PIN, , D, 5)
#endif
#if defined(PORTD6)
#define PORTD_6R DECL_PORT_DDR_PIN_READ_B(PORT, , D, 6)
#define PORTD_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , D, 6, __Value)
#define DDRD_6R DECL_PORT_DDR_PIN_READ_B(DD, R, D, 6)
#define DDRD_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, D, 6, __Value)
#define PIND_6R DECL_PORT_DDR_PIN_READ_B(PIN, , D, 6)
#endif
#if defined(PORTD7)
#define PORTD_7R DECL_PORT_DDR_PIN_READ_B(PORT, , D, 7)
#define PORTD_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , D, 7, __Value)
#define DDRD_7R DECL_PORT_DDR_PIN_READ_B(DD, R, D, 7)
#define DDRD_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, D, 7, __Value)
#define PIND_7R DECL_PORT_DDR_PIN_READ_B(PIN, , D, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port E
#if defined(PORTE)
#if defined(PORTE0)
#define PORTE_0R DECL_PORT_DDR_PIN_READ_B(PORT, , E, 0)
#define PORTE_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , E, 0, __Value)
#define DDRE_0R DECL_PORT_DDR_PIN_READ_B(DD, R, E, 0)
#define DDRE_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, E, 0, __Value)
#define PINE_0R DECL_PORT_DDR_PIN_READ_B(PIN, , E, 0)
#endif
#if defined(PORTE1)
#define PORTE_1R DECL_PORT_DDR_PIN_READ_B(PORT, , E, 1)
#define PORTE_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , E, 1, __Value)
#define DDRE_1R DECL_PORT_DDR_PIN_READ_B(DD, R, E, 1)
#define DDRE_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, E, 1, __Value)
#define PINE_1R DECL_PORT_DDR_PIN_READ_B(PIN, , E, 1)
#endif
#if defined(PORTE2)
#define PORTE_2R DECL_PORT_DDR_PIN_READ_B(PORT, , E, 2)
#define PORTE_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , E, 2, __Value)
#define DDRE_2R DECL_PORT_DDR_PIN_READ_B(DD, R, E, 2)
#define DDRE_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, E, 2, __Value)
#define PINE_2R DECL_PORT_DDR_PIN_READ_B(PIN, , E, 2)
#endif
#if defined(PORTE3)
#define PORTE_3R DECL_PORT_DDR_PIN_READ_B(PORT, , E, 3)
#define PORTE_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , E, 3, __Value)
#define DDRE_3R DECL_PORT_DDR_PIN_READ_B(DD, R, E, 3)
#define DDRE_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, E, 3, __Value)
#define PINE_3R DECL_PORT_DDR_PIN_READ_B(PIN, , E, 3)
#endif
#if defined(PORTE4)
#define PORTE_4R DECL_PORT_DDR_PIN_READ_B(PORT, , E, 4)
#define PORTE_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , E, 4, __Value)
#define DDRE_4R DECL_PORT_DDR_PIN_READ_B(DD, R, E, 4)
#define DDRE_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, E, 4, __Value)
#define PINE_4R DECL_PORT_DDR_PIN_READ_B(PIN, , E, 4)
#endif
#if defined(PORTE5)
#define PORTE_5R DECL_PORT_DDR_PIN_READ_B(PORT, , E, 5)
#define PORTE_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , E, 5, __Value)
#define DDRE_5R DECL_PORT_DDR_PIN_READ_B(DD, R, E, 5)
#define DDRE_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, E, 5, __Value)
#define PINE_5R DECL_PORT_DDR_PIN_READ_B(PIN, , E, 5)
#endif
#if defined(PORTE6)
#define PORTE_6R DECL_PORT_DDR_PIN_READ_B(PORT, , E, 6)
#define PORTE_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , E, 6, __Value)
#define DDRE_6R DECL_PORT_DDR_PIN_READ_B(DD, R, E, 6)
#define DDRE_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, E, 6, __Value)
#define PINE_6R DECL_PORT_DDR_PIN_READ_B(PIN, , E, 6)
#endif
#if defined(PORTE7)
#define PORTE_7R DECL_PORT_DDR_PIN_READ_B(PORT, , E, 7)
#define PORTE_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , E, 7, __Value)
#define DDRE_7R DECL_PORT_DDR_PIN_READ_B(DD, R, E, 7)
#define DDRE_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, E, 7, __Value)
#define PINE_7R DECL_PORT_DDR_PIN_READ_B(PIN, , E, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port F
#if defined(PORTF)
#if defined(PORTF0)
#define PORTF_0R DECL_PORT_DDR_PIN_READ_B(PORT, , F, 0)
#define PORTF_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , F, 0, __Value)
#define DDRF_0R DECL_PORT_DDR_PIN_READ_B(DD, R, F, 0)
#define DDRF_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, F, 0, __Value)
#define PINF_0R DECL_PORT_DDR_PIN_READ_B(PIN, , F, 0)
#endif
#if defined(PORTF1)
#define PORTF_1R DECL_PORT_DDR_PIN_READ_B(PORT, , F, 1)
#define PORTF_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , F, 1, __Value)
#define DDRF_1R DECL_PORT_DDR_PIN_READ_B(DD, R, F, 1)
#define DDRF_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, F, 1, __Value)
#define PINF_1R DECL_PORT_DDR_PIN_READ_B(PIN, , F, 1)
#endif
#if defined(PORTF2)
#define PORTF_2R DECL_PORT_DDR_PIN_READ_B(PORT, , F, 2)
#define PORTF_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , F, 2, __Value)
#define DDRF_2R DECL_PORT_DDR_PIN_READ_B(DD, R, F, 2)
#define DDRF_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, F, 2, __Value)
#define PINF_2R DECL_PORT_DDR_PIN_READ_B(PIN, , F, 2)
#endif
#if defined(PORTF3)
#define PORTF_3R DECL_PORT_DDR_PIN_READ_B(PORT, , F, 3)
#define PORTF_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , F, 3, __Value)
#define DDRF_3R DECL_PORT_DDR_PIN_READ_B(DD, R, F, 3)
#define DDRF_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, F, 3, __Value)
#define PINF_3R DECL_PORT_DDR_PIN_READ_B(PIN, , F, 3)
#endif
#if defined(PORTF4)
#define PORTF_4R DECL_PORT_DDR_PIN_READ_B(PORT, , F, 4)
#define PORTF_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , F, 4, __Value)
#define DDRF_4R DECL_PORT_DDR_PIN_READ_B(DD, R, F, 4)
#define DDRF_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, F, 4, __Value)
#define PINF_4R DECL_PORT_DDR_PIN_READ_B(PIN, , F, 4)
#endif
#if defined(PORTF5)
#define PORTF_5R DECL_PORT_DDR_PIN_READ_B(PORT, , F, 5)
#define PORTF_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , F, 5, __Value)
#define DDRF_5R DECL_PORT_DDR_PIN_READ_B(DD, R, F, 5)
#define DDRF_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, F, 5, __Value)
#define PINF_5R DECL_PORT_DDR_PIN_READ_B(PIN, , F, 5)
#endif
#if defined(PORTF6)
#define PORTF_6R DECL_PORT_DDR_PIN_READ_B(PORT, , F, 6)
#define PORTF_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , F, 6, __Value)
#define DDRF_6R DECL_PORT_DDR_PIN_READ_B(DD, R, F, 6)
#define DDRF_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, F, 6, __Value)
#define PINF_6R DECL_PORT_DDR_PIN_READ_B(PIN, , F, 6)
#endif
#if defined(PORTF7)
#define PORTF_7R DECL_PORT_DDR_PIN_READ_B(PORT, , F, 7)
#define PORTF_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , F, 7, __Value)
#define DDRF_7R DECL_PORT_DDR_PIN_READ_B(DD, R, F, 7)
#define DDRF_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, F, 7, __Value)
#define PINF_7R DECL_PORT_DDR_PIN_READ_B(PIN, , F, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port G
#if defined(PORTG)
#if defined(PORTG0)
#define PORTG_0R DECL_PORT_DDR_PIN_READ_B(PORT, , G, 0)
#define PORTG_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , G, 0, __Value)
#define DDRG_0R DECL_PORT_DDR_PIN_READ_B(DD, R, G, 0)
#define DDRG_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, G, 0, __Value)
#define PING_0R DECL_PORT_DDR_PIN_READ_B(PIN, , G, 0)
#endif
#if defined(PORTG1)
#define PORTG_1R DECL_PORT_DDR_PIN_READ_B(PORT, , G, 1)
#define PORTG_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , G, 1, __Value)
#define DDRG_1R DECL_PORT_DDR_PIN_READ_B(DD, R, G, 1)
#define DDRG_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, G, 1, __Value)
#define PING_1R DECL_PORT_DDR_PIN_READ_B(PIN, , G, 1)
#endif
#if defined(PORTG2)
#define PORTG_2R DECL_PORT_DDR_PIN_READ_B(PORT, , G, 2)
#define PORTG_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , G, 2, __Value)
#define DDRG_2R DECL_PORT_DDR_PIN_READ_B(DD, R, G, 2)
#define DDRG_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, G, 2, __Value)
#define PING_2R DECL_PORT_DDR_PIN_READ_B(PIN, , G, 2)
#endif
#if defined(PORTG3)
#define PORTG_3R DECL_PORT_DDR_PIN_READ_B(PORT, , G, 3)
#define PORTG_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , G, 3, __Value)
#define DDRG_3R DECL_PORT_DDR_PIN_READ_B(DD, R, G, 3)
#define DDRG_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, G, 3, __Value)
#define PING_3R DECL_PORT_DDR_PIN_READ_B(PIN, , G, 3)
#endif
#if defined(PORTG4)
#define PORTG_4R DECL_PORT_DDR_PIN_READ_B(PORT, , G, 4)
#define PORTG_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , G, 4, __Value)
#define DDRG_4R DECL_PORT_DDR_PIN_READ_B(DD, R, G, 4)
#define DDRG_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, G, 4, __Value)
#define PING_4R DECL_PORT_DDR_PIN_READ_B(PIN, , G, 4)
#endif
#if defined(PORTG5)
#define PORTG_5R DECL_PORT_DDR_PIN_READ_B(PORT, , G, 5)
#define PORTG_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , G, 5, __Value)
#define DDRG_5R DECL_PORT_DDR_PIN_READ_B(DD, R, G, 5)
#define DDRG_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, G, 5, __Value)
#define PING_5R DECL_PORT_DDR_PIN_READ_B(PIN, , G, 5)
#endif
#if defined(PORTG6)
#define PORTG_6R DECL_PORT_DDR_PIN_READ_B(PORT, , G, 6)
#define PORTG_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , G, 6, __Value)
#define DDRG_6R DECL_PORT_DDR_PIN_READ_B(DD, R, G, 6)
#define DDRG_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, G, 6, __Value)
#define PING_6R DECL_PORT_DDR_PIN_READ_B(PIN, , G, 6)
#endif
#if defined(PORTG7)
#define PORTG_7R DECL_PORT_DDR_PIN_READ_B(PORT, , G, 7)
#define PORTG_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , G, 7, __Value)
#define DDRG_7R DECL_PORT_DDR_PIN_READ_B(DD, R, G, 7)
#define DDRG_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, G, 7, __Value)
#define PING_7R DECL_PORT_DDR_PIN_READ_B(PIN, , G, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port H
#if defined(PORTH)
#if defined(PORTH0)
#define PORTH_0R DECL_PORT_DDR_PIN_READ_B(PORT, , H, 0)
#define PORTH_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , H, 0, __Value)
#define DDRH_0R DECL_PORT_DDR_PIN_READ_B(DD, R, H, 0)
#define DDRH_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, H, 0, __Value)
#define PINH_0R DECL_PORT_DDR_PIN_READ_B(PIN, , H, 0)
#endif
#if defined(PORTH1)
#define PORTH_1R DECL_PORT_DDR_PIN_READ_B(PORT, , H, 1)
#define PORTH_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , H, 1, __Value)
#define DDRH_1R DECL_PORT_DDR_PIN_READ_B(DD, R, H, 1)
#define DDRH_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, H, 1, __Value)
#define PINH_1R DECL_PORT_DDR_PIN_READ_B(PIN, , H, 1)
#endif
#if defined(PORTH2)
#define PORTH_2R DECL_PORT_DDR_PIN_READ_B(PORT, , H, 2)
#define PORTH_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , H, 2, __Value)
#define DDRH_2R DECL_PORT_DDR_PIN_READ_B(DD, R, H, 2)
#define DDRH_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, H, 2, __Value)
#define PINH_2R DECL_PORT_DDR_PIN_READ_B(PIN, , H, 2)
#endif
#if defined(PORTH3)
#define PORTH_3R DECL_PORT_DDR_PIN_READ_B(PORT, , H, 3)
#define PORTH_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , H, 3, __Value)
#define DDRH_3R DECL_PORT_DDR_PIN_READ_B(DD, R, H, 3)
#define DDRH_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, H, 3, __Value)
#define PINH_3R DECL_PORT_DDR_PIN_READ_B(PIN, , H, 3)
#endif
#if defined(PORTH4)
#define PORTH_4R DECL_PORT_DDR_PIN_READ_B(PORT, , H, 4)
#define PORTH_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , H, 4, __Value)
#define DDRH_4R DECL_PORT_DDR_PIN_READ_B(DD, R, H, 4)
#define DDRH_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, H, 4, __Value)
#define PINH_4R DECL_PORT_DDR_PIN_READ_B(PIN, , H, 4)
#endif
#if defined(PORTH5)
#define PORTH_5R DECL_PORT_DDR_PIN_READ_B(PORT, , H, 5)
#define PORTH_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , H, 5, __Value)
#define DDRH_5R DECL_PORT_DDR_PIN_READ_B(DD, R, H, 5)
#define DDRH_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, H, 5, __Value)
#define PINH_5R DECL_PORT_DDR_PIN_READ_B(PIN, , H, 5)
#endif
#if defined(PORTH6)
#define PORTH_6R DECL_PORT_DDR_PIN_READ_B(PORT, , H, 6)
#define PORTH_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , H, 6, __Value)
#define DDRH_6R DECL_PORT_DDR_PIN_READ_B(DD, R, H, 6)
#define DDRH_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, H, 6, __Value)
#define PINH_6R DECL_PORT_DDR_PIN_READ_B(PIN, , H, 6)
#endif
#if defined(PORTH7)
#define PORTH_7R DECL_PORT_DDR_PIN_READ_B(PORT, , H, 7)
#define PORTH_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , H, 7, __Value)
#define DDRH_7R DECL_PORT_DDR_PIN_READ_B(DD, R, H, 7)
#define DDRH_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, H, 7, __Value)
#define PINH_7R DECL_PORT_DDR_PIN_READ_B(PIN, , H, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port J
#if defined(PORTJ)
#if defined(PORTJ0)
#define PORTJ_0R DECL_PORT_DDR_PIN_READ_B(PORT, , J, 0)
#define PORTJ_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , J, 0, __Value)
#define DDRJ_0R DECL_PORT_DDR_PIN_READ_B(DD, R, J, 0)
#define DDRJ_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, J, 0, __Value)
#define PINJ_0R DECL_PORT_DDR_PIN_READ_B(PIN, , J, 0)
#endif
#if defined(PORTJ1)
#define PORTJ_1R DECL_PORT_DDR_PIN_READ_B(PORT, , J, 1)
#define PORTJ_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , J, 1, __Value)
#define DDRJ_1R DECL_PORT_DDR_PIN_READ_B(DD, R, J, 1)
#define DDRJ_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, J, 1, __Value)
#define PINJ_1R DECL_PORT_DDR_PIN_READ_B(PIN, , J, 1)
#endif
#if defined(PORTJ2)
#define PORTJ_2R DECL_PORT_DDR_PIN_READ_B(PORT, , J, 2)
#define PORTJ_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , J, 2, __Value)
#define DDRJ_2R DECL_PORT_DDR_PIN_READ_B(DD, R, J, 2)
#define DDRJ_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, J, 2, __Value)
#define PINJ_2R DECL_PORT_DDR_PIN_READ_B(PIN, , J, 2)
#endif
#if defined(PORTJ3)
#define PORTJ_3R DECL_PORT_DDR_PIN_READ_B(PORT, , J, 3)
#define PORTJ_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , J, 3, __Value)
#define DDRJ_3R DECL_PORT_DDR_PIN_READ_B(DD, R, J, 3)
#define DDRJ_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, J, 3, __Value)
#define PINJ_3R DECL_PORT_DDR_PIN_READ_B(PIN, , J, 3)
#endif
#if defined(PORTJ4)
#define PORTJ_4R DECL_PORT_DDR_PIN_READ_B(PORT, , J, 4)
#define PORTJ_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , J, 4, __Value)
#define DDRJ_4R DECL_PORT_DDR_PIN_READ_B(DD, R, J, 4)
#define DDRJ_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, J, 4, __Value)
#define PINJ_4R DECL_PORT_DDR_PIN_READ_B(PIN, , J, 4)
#endif
#if defined(PORTJ5)
#define PORTJ_5R DECL_PORT_DDR_PIN_READ_B(PORT, , J, 5)
#define PORTJ_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , J, 5, __Value)
#define DDRJ_5R DECL_PORT_DDR_PIN_READ_B(DD, R, J, 5)
#define DDRJ_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, J, 5, __Value)
#define PINJ_5R DECL_PORT_DDR_PIN_READ_B(PIN, , J, 5)
#endif
#if defined(PORTJ6)
#define PORTJ_6R DECL_PORT_DDR_PIN_READ_B(PORT, , J, 6)
#define PORTJ_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , J, 6, __Value)
#define DDRJ_6R DECL_PORT_DDR_PIN_READ_B(DD, R, J, 6)
#define DDRJ_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, J, 6, __Value)
#define PINJ_6R DECL_PORT_DDR_PIN_READ_B(PIN, , J, 6)
#endif
#if defined(PORTJ7)
#define PORTJ_7R DECL_PORT_DDR_PIN_READ_B(PORT, , J, 7)
#define PORTJ_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , J, 7, __Value)
#define DDRJ_7R DECL_PORT_DDR_PIN_READ_B(DD, R, J, 7)
#define DDRJ_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, J, 7, __Value)
#define PINJ_7R DECL_PORT_DDR_PIN_READ_B(PIN, , J, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port K
#if defined(PORTK)
#if defined(PORTK0)
#define PORTK_0R DECL_PORT_DDR_PIN_READ_B(PORT, , K, 0)
#define PORTK_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , K, 0, __Value)
#define DDRK_0R DECL_PORT_DDR_PIN_READ_B(DD, R, K, 0)
#define DDRK_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, K, 0, __Value)
#define PINK_0R DECL_PORT_DDR_PIN_READ_B(PIN, , K, 0)
#endif
#if defined(PORTK1)
#define PORTK_1R DECL_PORT_DDR_PIN_READ_B(PORT, , K, 1)
#define PORTK_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , K, 1, __Value)
#define DDRK_1R DECL_PORT_DDR_PIN_READ_B(DD, R, K, 1)
#define DDRK_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, K, 1, __Value)
#define PINK_1R DECL_PORT_DDR_PIN_READ_B(PIN, , K, 1)
#endif
#if defined(PORTK2)
#define PORTK_2R DECL_PORT_DDR_PIN_READ_B(PORT, , K, 2)
#define PORTK_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , K, 2, __Value)
#define DDRK_2R DECL_PORT_DDR_PIN_READ_B(DD, R, K, 2)
#define DDRK_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, K, 2, __Value)
#define PINK_2R DECL_PORT_DDR_PIN_READ_B(PIN, , K, 2)
#endif
#if defined(PORTK3)
#define PORTK_3R DECL_PORT_DDR_PIN_READ_B(PORT, , K, 3)
#define PORTK_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , K, 3, __Value)
#define DDRK_3R DECL_PORT_DDR_PIN_READ_B(DD, R, K, 3)
#define DDRK_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, K, 3, __Value)
#define PINK_3R DECL_PORT_DDR_PIN_READ_B(PIN, , K, 3)
#endif
#if defined(PORTK4)
#define PORTK_4R DECL_PORT_DDR_PIN_READ_B(PORT, , K, 4)
#define PORTK_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , K, 4, __Value)
#define DDRK_4R DECL_PORT_DDR_PIN_READ_B(DD, R, K, 4)
#define DDRK_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, K, 4, __Value)
#define PINK_4R DECL_PORT_DDR_PIN_READ_B(PIN, , K, 4)
#endif
#if defined(PORTK5)
#define PORTK_5R DECL_PORT_DDR_PIN_READ_B(PORT, , K, 5)
#define PORTK_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , K, 5, __Value)
#define DDRK_5R DECL_PORT_DDR_PIN_READ_B(DD, R, K, 5)
#define DDRK_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, K, 5, __Value)
#define PINK_5R DECL_PORT_DDR_PIN_READ_B(PIN, , K, 5)
#endif
#if defined(PORTK6)
#define PORTK_6R DECL_PORT_DDR_PIN_READ_B(PORT, , K, 6)
#define PORTK_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , K, 6, __Value)
#define DDRK_6R DECL_PORT_DDR_PIN_READ_B(DD, R, K, 6)
#define DDRK_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, K, 6, __Value)
#define PINK_6R DECL_PORT_DDR_PIN_READ_B(PIN, , K, 6)
#endif
#if defined(PORTK7)
#define PORTK_7R DECL_PORT_DDR_PIN_READ_B(PORT, , K, 7)
#define PORTK_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , K, 7, __Value)
#define DDRK_7R DECL_PORT_DDR_PIN_READ_B(DD, R, K, 7)
#define DDRK_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, K, 7, __Value)
#define PINK_7R DECL_PORT_DDR_PIN_READ_B(PIN, , K, 7)
#endif
#endif

// Read & Write Definitions for Port & DDR & Port L
#if defined(PORTL)
#if defined(PORTL0)
#define PORTL_0R DECL_PORT_DDR_PIN_READ_B(PORT, , L, 0)
#define PORTL_0W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , L, 0, __Value)
#define DDRL_0R DECL_PORT_DDR_PIN_READ_B(DD, R, L, 0)
#define DDRL_0W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, L, 0, __Value)
#define PINL_0R DECL_PORT_DDR_PIN_READ_B(PIN, , L, 0)
#endif
#if defined(PORTL1)
#define PORTL_1R DECL_PORT_DDR_PIN_READ_B(PORT, , L, 1)
#define PORTL_1W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , L, 1, __Value)
#define DDRL_1R DECL_PORT_DDR_PIN_READ_B(DD, R, L, 1)
#define DDRL_1W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, L, 1, __Value)
#define PINL_1R DECL_PORT_DDR_PIN_READ_B(PIN, , L, 1)
#endif
#if defined(PORTL2)
#define PORTL_2R DECL_PORT_DDR_PIN_READ_B(PORT, , L, 2)
#define PORTL_2W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , L, 2, __Value)
#define DDRL_2R DECL_PORT_DDR_PIN_READ_B(DD, R, L, 2)
#define DDRL_2W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, L, 2, __Value)
#define PINL_2R DECL_PORT_DDR_PIN_READ_B(PIN, , L, 2)
#endif
#if defined(PORTL3)
#define PORTL_3R DECL_PORT_DDR_PIN_READ_B(PORT, , L, 3)
#define PORTL_3W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , L, 3, __Value)
#define DDRL_3R DECL_PORT_DDR_PIN_READ_B(DD, R, L, 3)
#define DDRL_3W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, L, 3, __Value)
#define PINL_3R DECL_PORT_DDR_PIN_READ_B(PIN, , L, 3)
#endif
#if defined(PORTL4)
#define PORTL_4R DECL_PORT_DDR_PIN_READ_B(PORT, , L, 4)
#define PORTL_4W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , L, 4, __Value)
#define DDRL_4R DECL_PORT_DDR_PIN_READ_B(DD, R, L, 4)
#define DDRL_4W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, L, 4, __Value)
#define PINL_4R DECL_PORT_DDR_PIN_READ_B(PIN, , L, 4)
#endif
#if defined(PORTL5)
#define PORTL_5R DECL_PORT_DDR_PIN_READ_B(PORT, , L, 5)
#define PORTL_5W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , L, 5, __Value)
#define DDRL_5R DECL_PORT_DDR_PIN_READ_B(DD, R, L, 5)
#define DDRL_5W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, L, 5, __Value)
#define PINL_5R DECL_PORT_DDR_PIN_READ_B(PIN, , L, 5)
#endif
#if defined(PORTL6)
#define PORTL_6R DECL_PORT_DDR_PIN_READ_B(PORT, , L, 6)
#define PORTL_6W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , L, 6, __Value)
#define DDRL_6R DECL_PORT_DDR_PIN_READ_B(DD, R, L, 6)
#define DDRL_6W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, L, 6, __Value)
#define PINL_6R DECL_PORT_DDR_PIN_READ_B(PIN, , L, 6)
#endif
#if defined(PORTL7)
#define PORTL_7R DECL_PORT_DDR_PIN_READ_B(PORT, , L, 7)
#define PORTL_7W(__Value) DECL_PORT_DDR_WRITE_B(PORT, , L, 7, __Value)
#define DDRL_7R DECL_PORT_DDR_PIN_READ_B(DD, R, L, 7)
#define DDRL_7W(__Value) DECL_PORT_DDR_WRITE_B(DD, R, L, 7, __Value)
#define PINL_7R DECL_PORT_DDR_PIN_READ_B(PIN, , L, 7)
#endif
#endif

// Set Input & Output for DDR A.
#if defined(PORTA)
#if defined(PORTA0)
#define Set_Output_A0 DDRA_0W(true)
#define Set_Input_A0 DDRA_0W(false)
#define Get_IOStat_A0 DDRA_0R
#endif
#if defined(PORTA1)
#define Set_Output_A1 DDRA_1W(true)
#define Set_Input_A1 DDRA_1W(false)
#define Get_IOStat_A1 DDRA_1R
#endif
#if defined(PORTA2)
#define Set_Output_A2 DDRA_2W(true)
#define Set_Input_A2 DDRA_2W(false)
#define Get_IOStat_A2 DDRA_2R
#endif
#if defined(PORTA3)
#define Set_Output_A3 DDRA_3W(true)
#define Set_Input_A3 DDRA_3W(false)
#define Get_IOStat_A3 DDRA_3R
#endif
#if defined(PORTA4)
#define Set_Output_A4 DDRA_4W(true)
#define Set_Input_A4 DDRA_4W(false)
#define Get_IOStat_A4 DDRA_4R
#endif
#if defined(PORTA5)
#define Set_Output_A5 DDRA_5W(true)
#define Set_Input_A5 DDRA_5W(false)
#define Get_IOStat_A5 DDRA_5R
#endif
#if defined(PORTA6)
#define Set_Output_A6 DDRA_6W(true)
#define Set_Input_A6 DDRA_6W(false)
#define Get_IOStat_A6 DDRA_6R
#endif
#if defined(PORTA7)
#define Set_Output_A7 DDRA_7W(true)
#define Set_Input_A7 DDRA_7W(false)
#define Get_IOStat_A7 DDRA_7R
#endif
#endif

// Set Input & Output for DDR B.
#if defined(PORTB)
#if defined(PORTB0)
#define Set_Output_B0 DDRB_0W(true)
#define Set_Input_B0 DDRB_0W(false)
#define Get_IOStat_B0 DDRB_0R
#endif
#if defined(PORTB1)
#define Set_Output_B1 DDRB_1W(true)
#define Set_Input_B1 DDRB_1W(false)
#define Get_IOStat_B1 DDRB_1R
#endif
#if defined(PORTB2)
#define Set_Output_B2 DDRB_2W(true)
#define Set_Input_B2 DDRB_2W(false)
#define Get_IOStat_B2 DDRB_2R
#endif
#if defined(PORTB3)
#define Set_Output_B3 DDRB_3W(true)
#define Set_Input_B3 DDRB_3W(false)
#define Get_IOStat_B3 DDRB_3R
#endif
#if defined(PORTB4)
#define Set_Output_B4 DDRB_4W(true)
#define Set_Input_B4 DDRB_4W(false)
#define Get_IOStat_B4 DDRB_4R
#endif
#if defined(PORTB5)
#define Set_Output_B5 DDRB_5W(true)
#define Set_Input_B5 DDRB_5W(false)
#define Get_IOStat_B5 DDRB_5R
#endif
#if defined(PORTB6)
#define Set_Output_B6 DDRB_6W(true)
#define Set_Input_B6 DDRB_6W(false)
#define Get_IOStat_B6 DDRB_6R
#endif
#if defined(PORTB7)
#define Set_Output_B7 DDRB_7W(true)
#define Set_Input_B7 DDRB_7W(false)
#define Get_IOStat_B7 DDRB_7R
#endif
#endif

// Set Input & Output for DDR C.
#if defined(PORTC)
#if defined(PORTC0)
#define Set_Output_C0 DDRC_0W(true)
#define Set_Input_C0 DDRC_0W(false)
#define Get_IOStat_C0 DDRC_0R
#endif
#if defined(PORTC1)
#define Set_Output_C1 DDRC_1W(true)
#define Set_Input_C1 DDRC_1W(false)
#define Get_IOStat_C1 DDRC_1R
#endif
#if defined(PORTC2)
#define Set_Output_C2 DDRC_2W(true)
#define Set_Input_C2 DDRC_2W(false)
#define Get_IOStat_C2 DDRC_2R
#endif
#if defined(PORTC3)
#define Set_Output_C3 DDRC_3W(true)
#define Set_Input_C3 DDRC_3W(false)
#define Get_IOStat_C3 DDRC_3R
#endif
#if defined(PORTC4)
#define Set_Output_C4 DDRC_4W(true)
#define Set_Input_C4 DDRC_4W(false)
#define Get_IOStat_C4 DDRC_4R
#endif
#if defined(PORTC5)
#define Set_Output_C5 DDRC_5W(true)
#define Set_Input_C5 DDRC_5W(false)
#define Get_IOStat_C5 DDRC_5R
#endif
#if defined(PORTC6)
#define Set_Output_C6 DDRC_6W(true)
#define Set_Input_C6 DDRC_6W(false)
#define Get_IOStat_C6 DDRC_6R
#endif
#if defined(PORTC7)
#define Set_Output_C7 DDRC_7W(true)
#define Set_Input_C7 DDRC_7W(false)
#define Get_IOStat_C7 DDRC_7R
#endif
#endif

// Set Input & Output for DDR D.
#if defined(PORTD)
#if defined(PORTD0)
#define Set_Output_D0 DDRD_0W(true)
#define Set_Input_D0 DDRD_0W(false)
#define Get_IOStat_D0 DDRD_0R
#endif
#if defined(PORTD1)
#define Set_Output_D1 DDRD_1W(true)
#define Set_Input_D1 DDRD_1W(false)
#define Get_IOStat_D1 DDRD_1R
#endif
#if defined(PORTD2)
#define Set_Output_D2 DDRD_2W(true)
#define Set_Input_D2 DDRD_2W(false)
#define Get_IOStat_D2 DDRD_2R
#endif
#if defined(PORTD3)
#define Set_Output_D3 DDRD_3W(true)
#define Set_Input_D3 DDRD_3W(false)
#define Get_IOStat_D3 DDRD_3R
#endif
#if defined(PORTD4)
#define Set_Output_D4 DDRD_4W(true)
#define Set_Input_D4 DDRD_4W(false)
#define Get_IOStat_D4 DDRD_4R
#endif
#if defined(PORTD5)
#define Set_Output_D5 DDRD_5W(true)
#define Set_Input_D5 DDRD_5W(false)
#define Get_IOStat_D5 DDRD_5R
#endif
#if defined(PORTD6)
#define Set_Output_D6 DDRD_6W(true)
#define Set_Input_D6 DDRD_6W(false)
#define Get_IOStat_D6 DDRD_6R
#endif
#if defined(PORTD7)
#define Set_Output_D7 DDRD_7W(true)
#define Set_Input_D7 DDRD_7W(false)
#define Get_IOStat_D7 DDRD_7R
#endif
#endif

// Set Input & Output for DDR E.
#if defined(PORTE)
#if defined(PORTE0)
#define Set_Output_E0 DDRE_0W(true)
#define Set_Input_E0 DDRE_0W(false)
#define Get_IOStat_E0 DDRE_0R
#endif
#if defined(PORTE1)
#define Set_Output_E1 DDRE_1W(true)
#define Set_Input_E1 DDRE_1W(false)
#define Get_IOStat_E1 DDRE_1R
#endif
#if defined(PORTE2)
#define Set_Output_E2 DDRE_2W(true)
#define Set_Input_E2 DDRE_2W(false)
#define Get_IOStat_E2 DDRE_2R
#endif
#if defined(PORTE3)
#define Set_Output_E3 DDRE_3W(true)
#define Set_Input_E3 DDRE_3W(false)
#define Get_IOStat_E3 DDRE_3R
#endif
#if defined(PORTE4)
#define Set_Output_E4 DDRE_4W(true)
#define Set_Input_E4 DDRE_4W(false)
#define Get_IOStat_E4 DDRE_4R
#endif
#if defined(PORTE5)
#define Set_Output_E5 DDRE_5W(true)
#define Set_Input_E5 DDRE_5W(false)
#define Get_IOStat_E5 DDRE_5R
#endif
#if defined(PORTE6)
#define Set_Output_E6 DDRE_6W(true)
#define Set_Input_E6 DDRE_6W(false)
#define Get_IOStat_E6 DDRE_6R
#endif
#if defined(PORTE7)
#define Set_Output_E7 DDRE_7W(true)
#define Set_Input_E7 DDRE_7W(false)
#define Get_IOStat_E7 DDRE_7R
#endif
#endif

// Set Input & Output for DDR F.
#if defined(PORTF)
#if defined(PORTF0)
#define Set_Output_F0 DDRF_0W(true)
#define Set_Input_F0 DDRF_0W(false)
#define Get_IOStat_F0 DDRF_0R
#endif
#if defined(PORTF1)
#define Set_Output_F1 DDRF_1W(true)
#define Set_Input_F1 DDRF_1W(false)
#define Get_IOStat_F1 DDRF_1R
#endif
#if defined(PORTF2)
#define Set_Output_F2 DDRF_2W(true)
#define Set_Input_F2 DDRF_2W(false)
#define Get_IOStat_F2 DDRF_2R
#endif
#if defined(PORTF3)
#define Set_Output_F3 DDRF_3W(true)
#define Set_Input_F3 DDRF_3W(false)
#define Get_IOStat_F3 DDRF_3R
#endif
#if defined(PORTF4)
#define Set_Output_F4 DDRF_4W(true)
#define Set_Input_F4 DDRF_4W(false)
#define Get_IOStat_F4 DDRF_4R
#endif
#if defined(PORTF5)
#define Set_Output_F5 DDRF_5W(true)
#define Set_Input_F5 DDRF_5W(false)
#define Get_IOStat_F5 DDRF_5R
#endif
#if defined(PORTF6)
#define Set_Output_F6 DDRF_6W(true)
#define Set_Input_F6 DDRF_6W(false)
#define Get_IOStat_F6 DDRF_6R
#endif
#if defined(PORTF7)
#define Set_Output_F7 DDRF_7W(true)
#define Set_Input_F7 DDRF_7W(false)
#define Get_IOStat_F7 DDRF_7R
#endif
#endif

// Set Input & Output for DDR G.
#if defined(PORTG)
#if defined(PORTG0)
#define Set_Output_G0 DDRG_0W(true)
#define Set_Input_G0 DDRG_0W(false)
#define Get_IOStat_G0 DDRG_0R
#endif
#if defined(PORTG1)
#define Set_Output_G1 DDRG_1W(true)
#define Set_Input_G1 DDRG_1W(false)
#define Get_IOStat_G1 DDRG_1R
#endif
#if defined(PORTG2)
#define Set_Output_G2 DDRG_2W(true)
#define Set_Input_G2 DDRG_2W(false)
#define Get_IOStat_G2 DDRG_2R
#endif
#if defined(PORTG3)
#define Set_Output_G3 DDRG_3W(true)
#define Set_Input_G3 DDRG_3W(false)
#define Get_IOStat_G3 DDRG_3R
#endif
#if defined(PORTG4)
#define Set_Output_G4 DDRG_4W(true)
#define Set_Input_G4 DDRG_4W(false)
#define Get_IOStat_G4 DDRG_4R
#endif
#if defined(PORTG5)
#define Set_Output_G5 DDRG_5W(true)
#define Set_Input_G5 DDRG_5W(false)
#define Get_IOStat_G5 DDRG_5R
#endif
#if defined(PORTG6)
#define Set_Output_G6 DDRG_6W(true)
#define Set_Input_G6 DDRG_6W(false)
#define Get_IOStat_G6 DDRG_6R
#endif
#if defined(PORTG7)
#define Set_Output_G7 DDRG_7W(true)
#define Set_Input_G7 DDRG_7W(false)
#define Get_IOStat_G7 DDRG_7R
#endif
#endif

// Set Input & Output for DDR J.
#if defined(PORTJ)
#if defined(PORTJ0)
#define Set_Output_J0 DDRJ_0W(true)
#define Set_Input_J0 DDRJ_0W(false)
#define Get_IOStat_J0 DDRJ_0R
#endif
#if defined(PORTJ1)
#define Set_Output_J1 DDRJ_1W(true)
#define Set_Input_J1 DDRJ_1W(false)
#define Get_IOStat_J1 DDRJ_1R
#endif
#if defined(PORTJ2)
#define Set_Output_J2 DDRJ_2W(true)
#define Set_Input_J2 DDRJ_2W(false)
#define Get_IOStat_J2 DDRJ_2R
#endif
#if defined(PORTJ3)
#define Set_Output_J3 DDRJ_3W(true)
#define Set_Input_J3 DDRJ_3W(false)
#define Get_IOStat_J3 DDRJ_3R
#endif
#if defined(PORTJ4)
#define Set_Output_J4 DDRJ_4W(true)
#define Set_Input_J4 DDRJ_4W(false)
#define Get_IOStat_J4 DDRJ_4R
#endif
#if defined(PORTJ5)
#define Set_Output_J5 DDRJ_5W(true)
#define Set_Input_J5 DDRJ_5W(
#define Get_IOStat_J5 DDRJ_5Rfalse)
#endif
#if defined(PORTJ6)
#define Set_Output_J6 DDRJ_6W(true)
#define Set_Input_J6 DDRJ_6W(false)
#define Get_IOStat_J6 DDRJ_6R
#endif
#if defined(PORTJ7)
#define Set_Output_J7 DDRJ_7W(true)
#define Set_Input_J7 DDRJ_7W(false)
#define Get_IOStat_J7 DDRJ_7R
#endif
#endif

// Set Input & Output for DDR K.
#if defined(PORTK)
#if defined(PORTK0)
#define Set_Output_K0 DDRK_0W(true)
#define Set_Input_K0 DDRK_0W(false)
#define Get_IOStat_K0 DDRK_0R
#endif
#if defined(PORTK1)
#define Set_Output_K1 DDRK_1W(true)
#define Set_Input_K1 DDRK_1W(false)
#define Get_IOStat_K1 DDRK_1R
#endif
#if defined(PORTK2)
#define Set_Output_K2 DDRK_2W(true)
#define Set_Input_K2 DDRK_2W(false)
#define Get_IOStat_K2 DDRK_2R
#endif
#if defined(PORTK3)
#define Set_Output_K3 DDRK_3W(true)
#define Set_Input_K3 DDRK_3W(false)
#define Get_IOStat_K3 DDRK_3R
#endif
#if defined(PORTK4)
#define Set_Output_K4 DDRK_4W(true)
#define Set_Input_K4 DDRK_4W(false)
#define Get_IOStat_K4 DDRK_4R
#endif
#if defined(PORTK5)
#define Set_Output_K5 DDRK_5W(true)
#define Set_Input_K5 DDRK_5W(false)
#define Get_IOStat_K5 DDRK_5R
#endif
#if defined(PORTK6)
#define Set_Output_K6 DDRK_6W(true)
#define Set_Input_K6 DDRK_6W(false)
#define Get_IOStat_K6 DDRK_6R
#endif
#if defined(PORTK7)
#define Set_Output_K7 DDRK_7W(true)
#define Set_Input_K7 DDRK_7W(false)
#define Get_IOStat_K7 DDRK_7R
#endif
#endif

// Set Input & Output for DDR L.
#if defined(PORTL)
#if defined(PORTL0)
#define Set_Output_L0 DDRL_0W(true)
#define Set_Input_L0 DDRL_0W(false)
#define Get_IOStat_L0 DDRL_0R
#endif
#if defined(PORTL1)
#define Set_Output_L1 DDRL_1W(true)
#define Set_Input_L1 DDRL_1W(false)
#define Get_IOStat_L1 DDRL_1R
#endif
#if defined(PORTL2)
#define Set_Output_L2 DDRL_2W(true)
#define Set_Input_L2 DDRL_2W(false)
#define Get_IOStat_L2 DDRL_2R
#endif
#if defined(PORTL3)
#define Set_Output_L3 DDRL_3W(true)
#define Set_Input_L3 DDRL_3W(false)
#define Get_IOStat_L3 DDRL_3R
#endif
#if defined(PORTL4)
#define Set_Output_L4 DDRL_4W(true)
#define Set_Input_L4 DDRL_4W(false)
#define Get_IOStat_L4 DDRL_4R
#endif
#if defined(PORTL5)
#define Set_Output_L5 DDRL_5W(true)
#define Set_Input_L5 DDRL_5W(false)
#define Get_IOStat_L5 DDRL_5R
#endif
#if defined(PORTL6)
#define Set_Output_L6 DDRL_6W(true)
#define Set_Input_L6 DDRL_6W(false)
#define Get_IOStat_L6 DDRL_6R
#endif
#if defined(PORTL7)
#define Set_Output_L7 DDRL_7W(true)
#define Set_Input_L7 DDRL_7W(false)
#define Get_IOStat_L7 DDRL_7R
#endif
#endif

#endif // _PinDesc_h_