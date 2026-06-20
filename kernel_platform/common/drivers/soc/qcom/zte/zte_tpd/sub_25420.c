#include "defs.h"

extern __int64 syna_tcm_allocate_device(__int64 *a1, __int64 a2, __int64 a3);

__int64 sub_25420(__int64 *a1, __int64 a2, __int64 a3)
{
  return syna_tcm_allocate_device(a1, a2, a3);
}
