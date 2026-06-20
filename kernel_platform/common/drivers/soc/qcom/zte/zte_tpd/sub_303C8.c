#include "defs.h"

extern __int64 tpd_set_tp_report_rate(__int64 a1, int a2, __int64 a3);

__int64 sub_303C8(__int64 a1, int a2, __int64 a3)
{
  return tpd_set_tp_report_rate(a1, a2, a3);
}
