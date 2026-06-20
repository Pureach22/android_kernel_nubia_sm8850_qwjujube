#include "defs.h"

extern __int64 syna_pm_suspend(__int64 a1, __int64 a2, __int64 a3);

__int64 sub_18D90(__int64 a1, __int64 a2, __int64 a3)
{
  return syna_pm_suspend(a1, a2, a3);
}
