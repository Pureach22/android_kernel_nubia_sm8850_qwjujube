#include "defs.h"

extern __int64 syna_ioctl(__int64 a1, int a2, unsigned __int64 a3);

__int64 sub_1887C(__int64 a1, int a2, unsigned __int64 a3)
{
  return syna_ioctl(a1, a2, a3);
}
