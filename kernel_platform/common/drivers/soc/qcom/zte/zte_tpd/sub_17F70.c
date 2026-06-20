#include "defs.h"

extern __int64 syna_dev_process_touch_report(unsigned __int8 a1, const void *a2, __int64 a3, __int64 a4);

__int64 sub_17F70(unsigned __int8 a1, const void *a2, __int64 a3, __int64 a4)
{
  return syna_dev_process_touch_report(a1, a2, a3, a4);
}
