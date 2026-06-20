#include "defs.h"

extern __int64 syna_tcm_wait_for_report(__int64 a1, unsigned __int8 a2, __int64 a3, int a4, unsigned int a5);

__int64 sub_26788(__int64 a1, unsigned __int8 a2, __int64 a3, int a4, unsigned int a5)
{
  return syna_tcm_wait_for_report(a1, a2, a3, a4, a5);
}
