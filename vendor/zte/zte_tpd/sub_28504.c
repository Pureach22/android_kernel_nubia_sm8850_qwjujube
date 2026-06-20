#include "defs.h"

extern __int64 syna_tcm_read_flash_address(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, unsigned int a5);

__int64 sub_28504(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, unsigned int a5)
{
  return syna_tcm_read_flash_address(a1, a2, a3, a4, a5);
}
