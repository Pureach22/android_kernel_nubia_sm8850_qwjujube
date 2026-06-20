#include "defs.h"

extern __int64 syna_charger_notify_call(__int64 a1, __int64 a2, __int64 **a3);

__int64 sub_30D90(__int64 a1, __int64 a2, __int64 **a3)
{
  register unsigned __int64 v0 asm("x27") = 0;
  __asm__ __volatile__("msr s3_2_c7_c10_1, %0" : : "r"(v0));
  return syna_charger_notify_call(a1, a2, a3);
}
