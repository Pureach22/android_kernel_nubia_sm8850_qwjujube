#include "defs.h"

extern __int64 tpd_sysfs_fwimage_show(__int64 a1, __int64 a2, __int64 a3, void *a4, __int64 a5, size_t a6);

__int64 sub_12250(__int64 a1, __int64 a2, __int64 a3, void *a4, __int64 a5, size_t a6)
{
  return tpd_sysfs_fwimage_show(a1, a2, a3, a4, a5, a6);
}
