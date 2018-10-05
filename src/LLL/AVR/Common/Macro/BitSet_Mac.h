/*********************************************************************

          File: BitSet_Mac.h

   Description: AVR Bit set macro Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/02/09

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _BitSet_Mac_h_
#define _BitSet_Mac_h_

#pragma __FunX_Section Begin

#pragma __FunX_InLevel_Except Begin

#define lsv(__Value, __TargetBit) __Value << __TargetBit
#define rsv(__Value, __TargetBit) __Value >> __TargetBit

#define slbv(__Reg, __Value, __TargetBit) __Reg | (lsv(__Value, __TargetBit))
#define clbv(__Reg, __Value, __TargetBit) __Reg & ~(lsv(__Value, __TargetBit))

#define srbv(__Reg, __Value, __TargetBit) __Reg | (rsv(__Value, __TargetBit))
#define crbv(__Reg, __Value, __TargetBit) __Reg & ~(rsv(__Value, __TargetBit))

#define sclb(__Reg, __Enable, __TargetBit) \
  __Reg = (__Enable) ? (slbv(__Reg, 1, __TargetBit)) : (clbv(__Reg, 1, __TargetBit))
#define scrb(__Reg, __Enable, __TargetBit) \
  __Reg = (__Enable) ? (srbv(__Reg, 1, __TargetBit)) : (crbv(__Reg, 1, __TargetBit))

#define sbv_reg(__Reg, __Value, __TargetBit) slbv(__Reg, __Value, __TargetBit)
#define sclb_reg(__Reg, __Enable, __TargetBit) sclb(__Reg, __Enable, __TargetBit)

#define sbv_reg_common(__Reg, __RegPeriNum, __RegChan, __Value, __TargetBit, __TargetBitPeriNum, __TargetBitChan) \
  sbv_reg(__Reg##__RegPeriNum##__RegChan, __Value, __TargetBit##__TargetBitPeriNum##__TargetBitChan)
#define sclb_reg_rap(__Reg, __RegPeriNum, __RegChan, __Enable, __TargetBit, __TargetBitPeriNum, __TargetBitChan) \
  sclb_reg(__Reg##__RegPeriNum##__RegChan, __Enable, __TargetBit##__TargetBitPeriNum##__TargetBitChan)
#define sclb_reg_common(__Reg, __RegPeriNum, __RegChan, __Enable, __TargetBit, __TargetBitPeriNum, __TargetBitChan) \
  sclb_reg_rap(__Reg, __RegPeriNum, __RegChan, __Enable, __TargetBit, __TargetBitPeriNum, __TargetBitChan)

#pragma __FunX_InLevel_Except End

#pragma __FunX_Section End

#endif // _BitSet_Mac_h_
