/*********************************************************************

          File: atmega328x.h

   Description: AVR atmega328 series Machine map Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/27

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _atmega328x_h_
#define _atmega328x_h_

#include "PinDesc.h"

// External interrupt Pins.

// INT0
#define INT0_DDR_R DDRD_2R
#define INT0_DDR_W(__Value) DDRD_2W(__Value)
#define INT0_PORT_R PORTD_2R
#define INT0_PORT_W PORTD_2W(__Value)
#define INT0_PIN_R PIND_2R

// INT1
#define INT1_DDR_R DDRD_3R
#define INT1_DDR_W(__Value) DDRD_3W(__Value)
#define INT1_PORT_R PORTD_3R
#define INT1_PORT_W PORTD_3W(__Value)
#define INT1_PIN_R PIND_3R

// Pin Change Interrupt Pins.

// PCINT0
#define PCINT0_DDR_R DDRB_0R
#define PCINT0_DDR_W(__Value) DDRB_0W(__Value)
#define PCINT0_PORT_R PORTB_0R
#define PCINT0_PORT_W PORTB_0W(__Value)
#define PCINT0_PIN_R PINB_0R

// PCINT1
#define PCINT1_DDR_R DDRB_1R
#define PCINT1_DDR_W(__Value) DDRB_1W(__Value)
#define PCINT1_PORT_R PORTB_1R
#define PCINT1_PORT_W PORTB_1W(__Value)
#define PCINT1_PIN_R PINB_1R

// PCINT2
#define PCINT2_DDR_R DDRB_2R
#define PCINT2_DDR_W(__Value) DDRB_2W(__Value)
#define PCINT2_PORT_R PORTB_2R
#define PCINT2_PORT_W PORTB_2W(__Value)
#define PCINT2_PIN_R PINB_2R

// PCINT3
#define PCINT3_DDR_R DDRB_3R
#define PCINT3_DDR_W(__Value) DDRB_3W(__Value)
#define PCINT3_PORT_R PORTB_3R
#define PCINT3_PORT_W PORTB_3W(__Value)
#define PCINT3_PIN_R PINB_3R

// PCINT4
#define PCINT4_DDR_R DDRB_4R
#define PCINT4_DDR_W(__Value) DDRB_4W(__Value)
#define PCINT4_PORT_R PORTB_4R
#define PCINT4_PORT_W PORTB_4W(__Value)
#define PCINT4_PIN_R PINB_4R

// PCINT5
#define PCINT5_DDR_R DDRB_5R
#define PCINT5_DDR_W(__Value) DDRB_5W(__Value)
#define PCINT5_PORT_R PORTB_5R
#define PCINT5_PORT_W PORTB_5W(__Value)
#define PCINT5_PIN_R PINB_5R

// PCINT6
#define PCINT6_DDR_R DDRB_6R
#define PCINT6_DDR_W(__Value) DDRB_6W(__Value)
#define PCINT6_PORT_R PORTB_6R
#define PCINT6_PORT_W PORTB_6W(__Value)
#define PCINT6_PIN_R PINB_6R

// PCINT7
#define PCINT7_DDR_R DDRB_7R
#define PCINT7_DDR_W(__Value) DDRB_7W(__Value)
#define PCINT7_PORT_R PORTB_7R
#define PCINT7_PORT_W PORTB_7W(__Value)
#define PCINT7_PIN_R PINB_7R

// PCINT8
#define PCINT8_DDR_R DDRC_0R
#define PCINT8_DDR_W(__Value) DDRC_0W(__Value)
#define PCINT8_PORT_R PORTC_0R
#define PCINT8_PORT_W PORTC_0W(__Value)
#define PCINT8_PIN_R PINC_0R

// PCINT9
#define PCINT9_DDR_R DDRC_1R
#define PCINT9_DDR_W(__Value) DDRC_1W(__Value)
#define PCINT9_PORT_R PORTC_1R
#define PCINT9_PORT_W PORTC_1W(__Value)
#define PCINT9_PIN_R PINC_1R

// PCINT10
#define PCINT10_DDR_R DDRC_2R
#define PCINT10_DDR_W(__Value) DDRC_2W(__Value)
#define PCINT10_PORT_R PORTC_2R
#define PCINT10_PORT_W PORTC_2W(__Value)
#define PCINT10_PIN_R PINC_2R

// PCINT11
#define PCINT11_DDR_R DDRC_3R
#define PCINT11_DDR_W(__Value) DDRC_3W(__Value)
#define PCINT11_PORT_R PORTC_3R
#define PCINT11_PORT_W PORTC_3W(__Value)
#define PCINT11_PIN_R PINC_3R

// PCINT12
#define PCINT12_DDR_R DDRC_4R
#define PCINT12_DDR_W(__Value) DDRC_4W(__Value)
#define PCINT12_PORT_R PORTC_4R
#define PCINT12_PORT_W PORTC_4W(__Value)
#define PCINT12_PIN_R PINC_4R

// PCINT13
#define PCINT13_DDR_R DDRC_5R
#define PCINT13_DDR_W(__Value) DDRC_5W(__Value)
#define PCINT13_PORT_R PORTC_5R
#define PCINT13_PORT_W PORTC_5W(__Value)
#define PCINT13_PIN_R PINC_5R

// PCINT14
#define PCINT14_DDR_R DDRC_6R
#define PCINT14_DDR_W(__Value) DDRC_6W(__Value)
#define PCINT14_PORT_R PORTC_6R
#define PCINT14_PORT_W PORTC_6W(__Value)
#define PCINT14_PIN_R PINC_6R

// PCINT16
#define PCINT16_DDR_R DDRD_0R
#define PCINT16_DDR_W(__Value) DDRD_0W(__Value)
#define PCINT16_PORT_R PORTD_0R
#define PCINT16_PORT_W PORTD_0W(__Value)
#define PCINT16_PIN_R PIND_0R

// PCINT17
#define PCINT17_DDR_R DDRD_1R
#define PCINT17_DDR_W(__Value) DDRD_1W(__Value)
#define PCINT17_PORT_R PORTD_1R
#define PCINT17_PORT_W PORTD_1W(__Value)
#define PCINT17_PIN_R PIND_1R

// PCINT18
#define PCINT18_DDR_R DDRD_2R
#define PCINT18_DDR_W(__Value) DDRD_2W(__Value)
#define PCINT18_PORT_R PORTD_2R
#define PCINT18_PORT_W PORTD_2W(__Value)
#define PCINT18_PIN_R PIND_2R

// PCINT19
#define PCINT19_DDR_R DDRD_3R
#define PCINT19_DDR_W(__Value) DDRD_3W(__Value)
#define PCINT19_PORT_R PORTD_3R
#define PCINT19_PORT_W PORTD_3W(__Value)
#define PCINT19_PIN_R PIND_3R

// PCINT20
#define PCINT20_DDR_R DDRD_4R
#define PCINT20_DDR_W(__Value) DDRD_4W(__Value)
#define PCINT20_PORT_R PORTD_4R
#define PCINT20_PORT_W PORTD_4W(__Value)
#define PCINT20_PIN_R PIND_4R

// PCINT21
#define PCINT21_DDR_R DDRD_5R
#define PCINT21_DDR_W(__Value) DDRD_5W(__Value)
#define PCINT21_PORT_R PORTD_5R
#define PCINT21_PORT_W PORTD_5W(__Value)
#define PCINT21_PIN_R PIND_5R

// PCINT22
#define PCINT22_DDR_R DDRD_6R
#define PCINT22_DDR_W(__Value) DDRD_6W(__Value)
#define PCINT22_PORT_R PORTD_6R
#define PCINT22_PORT_W PORTD_6W(__Value)
#define PCINT22_PIN_R PIND_6R

// PCINT23
#define PCINT23_DDR_R DDRD_7R
#define PCINT23_DDR_W(__Value) DDRD_7W(__Value)
#define PCINT23_PORT_R PORTD_7R
#define PCINT23_PORT_W PORTD_7W(__Value)
#define PCINT23_PIN_R PIND_7R




#endif // _atmega328x_h_
