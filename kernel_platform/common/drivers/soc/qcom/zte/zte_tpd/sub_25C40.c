#include "defs.h"

extern __int64 syna_tcm_detect_device(__int64 a1, char a2, __int64 a3);

__attribute__((target("arch=armv8.2-a+bf16")))
__int64 sub_25C40(__int64 a1, __int64 a2, __int64 a3)
{
  __asm__ __volatile__ ("bfmlalb v26.4s, v25.8h, v22.8h");
  return syna_tcm_detect_device(a1, a2, a3);
}
