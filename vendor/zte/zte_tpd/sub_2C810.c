#include "defs.h"

extern __int64 syna_tcm_get_touch_data(__int64 a1, int a2, __int64 a3, unsigned int a4, unsigned int *a5);

__int64 sub_2C810(__int64 a1, int a2, __int64 a3, unsigned int a4, unsigned int *a5)
{
  return syna_tcm_get_touch_data(a1, a2, a3, a4, a5);
}
