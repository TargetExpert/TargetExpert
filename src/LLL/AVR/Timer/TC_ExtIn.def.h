/*********************************************************************

          File: TC_ExtIn.def.h

   Description: AVR T/C syntax definition for internal of
                extended functions Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/13

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_ExtIn_def_h_
#define _TC_ExtIn_def_h_

#include "TC_Basic.var.h"
#include "TC_Ext.var.h"

#pragma __FunCX_InLevel_Except Begin
/*
#define _InitTCOVArr(__PeriNum) \
  TCFreqOptiValueStoreage _TTCOVInfo = InitialFormFreqOptiValues; \
  _TCOVInfo[__PeriNum] = _TTCOVInfo;
*/
#pragma __FunCX_InLevel_Except End

#pragma __FunCX_InLevel_Except Begin
/*
#define _InitTCOptArr(__PeriNum) \
  C_( \
    _TOptInfo[__PeriNum].IsToggleMode = false; \
    _TOptInfo[__PeriNum].IsInvertPWM = false; \
    _TOptInfo[__PeriNum].IsICFTop = false; \
    _TOptInfo[__PeriNum].DiffMarginFreqValue = TC_DEFAULT_FREQERR_MARGIN; \
  )
  */
#pragma __FunCX_InLevel_Except End

#pragma __FunCX_InLevel_Except Begin
/*
#define _ExecCalcPeriod(__PeriNum) \
  unsigned char _TCOMode = 0; \
  IfSafe_(_TCOVInfo[__PeriNum].TCWGMNBitPeriInfo.WGMValue == NORMODE, \
    _TCOMode = COM_NORMAL; \
  ) \
  ElseSafe_( \
    _TCOMode = COM_NONINV; \
  )
  */
/*
#define _ExecCalcPeriod(__PeriNum) \
  C_( \
    unsigned char _TCOMode = 0; \
    IfSafe_(_TCOVInfo[__PeriNum].TCWGMNBitPeriInfo.WGMValue == NORMODE, \
      _TCOMode = COM_NORMAL; \
    ) \
    ElseSafe_( \
      _TCOMode = COM_NONINV; \
    ) \
    Set_COMode_TC##__PeriNum(_TCOMode, ChanA); \
    Set_WGMode_TC##__PeriNum(_TCOVInfo[__PeriNum].TCWGMNBitPeriInfo.WGMValue); \
    Set_TCReg_TC##__PeriNum(_TCOVInfo[__PeriNum].TCCalcValInfo.TCnt); \
    Set_ClockSelect_TC##__PeriNum(_TCOVInfo[__PeriNum].TCCalcValInfo.NBit); \
  )
  */
#pragma __FunCX_InLevel_Except End

#pragma __FunCX_InLevel_Except Begin
/*
#define _UptadeTCInformations_D_Proto(__PeriNum, __TCOptiValue) \
  _TCOVInfo[__PeriNum] = __TCOptiValue;
  */
/*
#define _UptadeTCInformations_D_Proto(__PeriNum, __TCOptiValue) \
  _InitTCOVArr(__PeriNum) \
  _TCOVInfo[__PeriNum] = __TCOptiValue;
*/
#pragma __FunCX_InLevel_Except End

#endif // _TC_ExtIn_def_h_
