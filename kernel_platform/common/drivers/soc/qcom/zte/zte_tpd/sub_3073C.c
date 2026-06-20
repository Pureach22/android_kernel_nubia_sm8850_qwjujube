#include "defs.h"

extern __int64 tpd_set_rotation_limit_level(__int64 a1, int a2, __int64 a3);

__int64 sub_3073C(__int64 a1, int a2, __int64 a3)
{
  return tpd_set_rotation_limit_level(a1, a2, a3);
}
