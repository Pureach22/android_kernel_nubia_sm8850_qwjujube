#include "defs.h"

__int64 __fastcall syna_charger_notify_call(__int64 a1, __int64 a2, __int64 **a3)
{
  __int64 v5; // x20

  if ( a2 )
    return 0;
  v5 = **a3;
  if ( !strcmp((const char *)v5, "usb") || *(_BYTE *)v5 == 97 && *(_BYTE *)(v5 + 1) == 99 && !*(_BYTE *)(v5 + 2) )
    queue_delayed_work_on(32, *(_QWORD *)(a1 - 8), a1 - 112, 125);
  return 0;
}
