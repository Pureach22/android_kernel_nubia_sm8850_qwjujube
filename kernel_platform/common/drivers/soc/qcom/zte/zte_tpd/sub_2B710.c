#include "defs.h"

extern __int64 syna_tcm_update_cs_config(__int64 a1, char *a2, __int64 a3, int a4, unsigned int a5);

__attribute__((target("arch=armv8.5-a+mte")))
__int64 sub_2B710(__int64 a1, char *a2, __int64 a3, int a4, unsigned int a5)
{
  register __int64 x9 asm("x9");
  register char *x14 asm("x14");
  __asm__ __volatile__ ("stzg %0, [%1], #0x6a0" : "+r"(x9), "+r"(x14));
  return syna_tcm_update_cs_config(a1, a2, a3, a4, a5);
}
