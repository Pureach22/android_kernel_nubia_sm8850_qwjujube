#include "defs.h"

extern __int64 tpd_set_fake_sleep(__int64 a1, int a2, __int64 a3);

__int64 sub_30CA0(__int64 a1, int a2, __int64 a3)
{
  return tpd_set_fake_sleep(a1, a2, a3);
}
