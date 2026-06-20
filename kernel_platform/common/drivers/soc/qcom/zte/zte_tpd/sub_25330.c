#include "defs.h"

extern __int64 syna_tcm_config_timings(_DWORD *a1, _DWORD *a2, __int64 a3, int a4);

__int64 sub_25330(_DWORD *a1, _DWORD *a2, __int64 a3, int a4)
{
  return syna_tcm_config_timings(a1, a2, a3, a4);
}
