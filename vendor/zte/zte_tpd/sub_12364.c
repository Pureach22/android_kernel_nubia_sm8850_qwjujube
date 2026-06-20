#include "defs.h"

extern __int64 tpd_sysfs_fwimage_store(__int64 a1, __int64 a2, __int64 a3, const void *a4, __int64 a5, size_t a6);

__int64 sub_12364(__int64 a1, __int64 a2, __int64 a3, const void *a4, __int64 a5, size_t a6)
{
  return tpd_sysfs_fwimage_store(a1, a2, a3, a4, a5, a6);
}
