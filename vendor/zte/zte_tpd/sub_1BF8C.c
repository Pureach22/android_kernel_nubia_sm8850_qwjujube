#include "defs.h"

extern __int64 syna_cdev_process_reports(__int64 a1, _QWORD *a2, __int64 a3, __int64 *a4);

__int64 sub_1BF8C(__int64 a1, _QWORD *a2, __int64 a3, __int64 *a4)
{
  return syna_cdev_process_reports(a1, a2, a3, a4);
}
