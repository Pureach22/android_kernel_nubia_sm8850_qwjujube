#include "defs.h"

extern __int64 tpd_set_display_rotation(__int64 a1, int a2, __int64 a3);

__int64 sub_30808(__int64 a1, int a2, __int64 a3)
{
  return tpd_set_display_rotation(a1, a2, a3);
}
