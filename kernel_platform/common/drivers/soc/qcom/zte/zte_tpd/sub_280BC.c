#include "defs.h"

extern __int64 syna_tcm_send_command(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, _BYTE *a5, __int64 a6, unsigned int a7);

__int64 sub_280BC(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, _BYTE *a5, __int64 a6, unsigned int a7)
{
  return syna_tcm_send_command(a1, a2, a3, a4, a5, a6, a7);
}
