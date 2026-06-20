#include "defs.h"

extern __int64 syna_spi_read(__int64 **a1, void *a2, __int64 a3);

__int64 sub_1DAFC(_DWORD *a1, int a2)
{
  *a1 = 0;
  a1[1] = a2;
  return syna_spi_read((__int64 **)(a1 - 56), 0, 0); // Corrected syntax to match prototype
}

