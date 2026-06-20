#include "defs.h"

extern __int64 syna_dev_isr(__int64 a1, __int64 *a2);

__int64 sub_184B0(__int64 a1, __int64 *a2)
{
  return syna_dev_isr(a1, a2);
}
