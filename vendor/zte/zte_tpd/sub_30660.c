#include "defs.h"

extern __int64 tpd_set_stability_level(__int64 a1, int a2, __int64 a3);

__int64 sub_30660(__int64 a1, int a2, __int64 a3)
{
  return tpd_set_stability_level(a1, a2, a3);
}
