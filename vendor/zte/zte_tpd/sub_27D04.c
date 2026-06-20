#include "defs.h"

extern __int64 syna_tcm_get_features(__int64 a1, void *a2, __int64 a3);

__int64 sub_27D04(__int64 a1)
{
  char v1 = 0;
  *(_BYTE *)(a1 + 2456) = v1;
  return syna_tcm_get_features(a1, 0, 0);
}
