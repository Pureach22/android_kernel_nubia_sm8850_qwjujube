#include "defs.h"

extern __int64 tpd_enable_wakegesture(__int64 a1, int a2, __int64 a3);

__int64 sub_2FE48(__int64 a1, int a2, __int64 a3)
{
  return tpd_enable_wakegesture(a1, a2, a3);
}
