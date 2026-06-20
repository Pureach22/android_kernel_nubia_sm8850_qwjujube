#include "defs.h"

extern __int64 syna_sysfs_fw_update_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4);

__int64 sub_1F6AC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return syna_sysfs_fw_update_store(a1, a2, a3, a4);
}
