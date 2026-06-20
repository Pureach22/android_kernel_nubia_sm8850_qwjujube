#include "defs.h"

extern __int64 syna_dev_disconnect(__int64 a1, __int64 a2, __int64 a3);

__int64 sub_16E00(__int64 a1, __int64 a2, __int64 a3)
{
  return syna_dev_disconnect(a1, a2, a3);
}
