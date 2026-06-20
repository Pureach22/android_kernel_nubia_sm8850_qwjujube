#include "defs.h"

extern __int64 syna_tcm_do_fw_update(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, char a5);

__int64 sub_2AAAC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return syna_tcm_do_fw_update(a1, a2, a3, (unsigned int)a4, *(char *)(a3 + 836));
}
