/*********************************************************************

          File: FakeCallee.h

   Description: AVR Fake Callee util Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/05/01

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _FakeCallee_h_
#define _FakeCallee_h_

#include "BasicFunc_Mac.h"

#define __FakeCallee \
  DECL_FUNC(static, void *, FakeCallee, HELPER_PARAM_VAR()) {}\

__FakeCallee

/*
static void *FakeCallee(void *, ...);

static void *FakeCallee(void *fuck, ...) {}
*/
#endif // _FakeCallee_h_
