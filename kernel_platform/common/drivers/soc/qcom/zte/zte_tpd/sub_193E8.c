#include "defs.h"

extern __int64 syna_cdev_ioctls(__int64 a1, unsigned __int8 a2, unsigned __int64 a3);

__int64 sub_193E8(__int64 a1, unsigned __int8 a2, unsigned __int64 a3)
{
  return syna_cdev_ioctls(a1, a2, a3);
}
