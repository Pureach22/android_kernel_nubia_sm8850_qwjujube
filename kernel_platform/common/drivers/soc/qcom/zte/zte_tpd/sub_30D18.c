#include "defs.h"

extern __int64 tpd_set_screen_off_awake(__int64 a1, int a2, __int64 a3);

__int64 sub_30D18(__int64 a1, int a2, __int64 a3)
{
  return tpd_set_screen_off_awake(a1, a2, a3);
}
