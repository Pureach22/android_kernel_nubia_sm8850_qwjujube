#include "defs.h"

extern __int64 tp_ghost_check(void);

__attribute__((target("arch=armv8.2-a+fp16fml")))
__int64 sub_1371C(void)
{
  asm volatile("fmlal2 v22.2s, v20.2h, v13.h[6]");
  return tp_ghost_check();
}
