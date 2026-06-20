#include "defs.h"

__int64 __fastcall syna_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  _DWORD *v4; // x20
  __int64 v15; // x0
  __int64 result; // x0
  _QWORD v28[5]; // [xsp+8h] [xbp-38h] BYREF
  int v29; // [xsp+34h] [xbp-Ch] BYREF

  v4 = *(_DWORD **)(a1 + 32);
  v29 = 0;
  switch ( a2 )
  {
    case -1073451005:
      v29 = v4[270];
      mutex_lock((struct mutex *)(v4 + 284));
      v15 = copy_to_user((void __user *)a3, &v29, 4);
LABEL_20:
      if ( !v15 )
      {
        mutex_unlock((struct mutex *)(v4 + 284));
        result = 0;
        break;
      }
      mutex_unlock((struct mutex *)(v4 + 284));
      result = -14;
      break;

    case -1073451006:
      v29 = v4[376];
      mutex_lock((struct mutex *)(v4 + 284));
      v15 = copy_to_user((void __user *)a3, &v29, 4);
      goto LABEL_20;

    case -1073451007:
      if ( v4[376] )
      {
        if ( !v4[282] )
        {
          memset(v28, 0, sizeof(v28));
          init_wait_entry((struct wait_queue_entry *)v28, 0);
          while ( 1 )
          {
            v15 = prepare_to_wait_event((struct wait_queue_head *)(v4 + 274), (struct wait_queue_entry *)v28, 1);
            if ( v4[282] )
              break;
            if ( v15 )
              goto LABEL_26;
            schedule();
          }
          finish_wait((struct wait_queue_head *)(v4 + 274), (struct wait_queue_entry *)v28);
        }
LABEL_26:
        result = 0;
        v4[282] = 0;
      }
      else
      {
        result = -11;
      }
      break;
    default:
      result = -25;
      break;
  }
  return result;
}
