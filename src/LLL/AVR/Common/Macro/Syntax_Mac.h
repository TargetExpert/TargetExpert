/*********************************************************************

          File: Syntax_Mac.h

   Description: Basic Syntax macro Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/02/28

 Copyright (c) 2017, MinLC(Minimalist Library Collections) Project,
 All rights reserved.

 ** The "MinLC" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _Syntax_Mac_h_
#define _Syntax_Mac_h_

#pragma __FunX_Section Begin

// Syntax of "Null Parameter"
#define Null_
#define Null_Param_ Null_

#define Null_Syntax_ Null_

// Syntax of "Brace".
#define BBegin_ {
#define BEnd_ }
#define Begin_ BBegin_
#define End_ BEnd_

// Syntax of "Syntax Controls"
#define Break_ break
#define Continue_ continue

// The definition of "Safe Contents".
#define Syntax_Contents_(__Syntax) \
  __Syntax

#define Contents_Safe_(__Syntax) \
  Begin_ \
  Syntax_Contents_(__Syntax) \
  End_

#define Contents_(__Syntax) \
  Contents_Safe_(__Syntax)

// It's not find well known name.
#define C_(__Syntax) \
  Contents_(__Syntax)

// Syntax of "Branchs".
#define If_(__Expr) \
  if (__Expr)
#define ElseIf_(__Expr) \
  else if (__Expr)
#define Else_ \
  else

#define IfSafe_(__Expr, __Syntax) \
  If_(__Expr) \
  C_(__Syntax)
#define ElseIfSafe_(__Expr, __Syntax) \
  ElseIf_(__Expr) \
  C_(__Syntax)
#define ElseSafe_(__Syntax) \
  Else_ \
  C_(__Syntax)

#define Switch_(__SwitchVar) \
  switch (__SwitchVar)
#define Case_(__CaseConst) \
  case __CaseConst :
#define Default_ \
  default :

#define SwitchSafe_(__SwitchVar, __Syntax) \
  Switch_(__SwitchVar) \
  C_( \
    __Syntax \
  )

#define CaseSafe_(__CaseConst, __Syntax) \
  Case_(__CaseConst) \
  C_( \
    __Syntax \
    Break_; \
  )
#define DefaultSafe_(__Syntax) \
  Default_ \
  C_( \
    __Syntax \
    Break_; \
  )

// Syntax of "Loops".
#define For_(__Expr1, __Expr2, __Expr3) \
  for (__Expr1; __Expr2; __Expr3)

#define ForSafe_(__Expr1, __Expr2, __Expr3, __Syntax) \
  For_(__Expr1, __Expr2, __Expr3) \
  C_(__Syntax)

#define Do_ \
  do
#define While_(__Expr) \
  while(__Expr)

#define WhileSafe_(__Expr, __Syntax) \
  While_(__Expr) \
  C_(__Syntax)

#define DoWhileSafe_(__Expr, __Syntax) \
  Do_ \
  C_(__Syntax) \
  While_(__Expr)

#pragma __FunX_Section End

#endif // _Syntax_Mac_h_
