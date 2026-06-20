#include "defs.h"

extern __int64 syna_dev_do_reflash(__int64 *a1, char a2);

__int64 sub_156F8(__int64 *a1, char a2)
{
  return syna_dev_do_reflash(a1, a2);
}
