#include "defs.h"

__int64 suspend_tp_need_awake(void)
{
  __int64 (*v0)(void); // x8

  v0 = *(__int64 (**)(void))(tpd_cdev + 3248);
  if ( !v0 )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -2139014615 )
    __break(0x8228u);
  return v0() & 1;
}
