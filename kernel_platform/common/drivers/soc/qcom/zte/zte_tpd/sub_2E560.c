#include "defs.h"

extern __int64 syna_tcm_set_touch_report_config(__int64 a1, void *a2, __int64 a3, unsigned int a4);

__int64 sub_2E560(__int64 a1, void *a2, __int64 a3, unsigned int a4)
{
  return syna_tcm_set_touch_report_config(a1, a2, a3, a4);
}
