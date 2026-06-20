#include "defs.h"

extern __int64 syna_sysfs_pwr_store(__int64 a1, int a2, char *s1, __int64 a4);

__int64 sub_1F5C0(__int64 a1, int a2, char *s1, __int64 a4)
{
  return syna_sysfs_pwr_store(a1, a2, s1, a4);
}
