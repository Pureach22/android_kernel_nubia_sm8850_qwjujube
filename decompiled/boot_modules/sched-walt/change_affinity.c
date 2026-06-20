__int64 __fastcall change_affinity(__int64 result, _DWORD *a2, char a3)
{
  unsigned int v5; // w19
  __int64 vpid; // x0
  _BYTE *v7; // x23
  __int64 v9; // x20
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x21
  char v13; // w8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x22
  _QWORD *v16; // x9
  __int64 v17; // x23
  int v23; // w9

  if ( (int)result >= 1 )
  {
    if ( (a3 & 1) != 0 || *a2 )
    {
      v5 = result;
      vpid = find_vpid(result);
      result = get_pid_task(vpid, 0);
      if ( result )
      {
        if ( (_UNKNOWN *)result == &init_task )
          v7 = &vendor_data_pad;
        else
          v7 = (_BYTE *)(result + 5184);
        if ( v7 )
        {
          if ( (a3 & 1) != 0 )
          {
            v9 = result;
            v10 = sched_nbia_debug;
            v7[457] = 0;
            *((_DWORD *)v7 + 115) = -1;
            if ( v10 )
            {
              v13 = 0;
              do
              {
                v14 = (unsigned int)(-1LL << v13) & *((_DWORD *)v7 + 118);
                if ( !(_DWORD)v14 )
                  break;
                v15 = __clz(__rbit64(v14));
                printk(&unk_635CB);
                v13 = v15 + 1;
              }
              while ( v15 < 0x1F );
            }
            if ( (unsigned int)set_cpus_allowed_ptr(v9, v7 + 472) )
            {
              printk(&unk_653EA);
              q_affinity_work(v5, (_DWORD *)v7 + 118);
            }
            printk(&unk_64309);
            result = v9;
          }
          else
          {
            v7[457] = 1;
            *((_DWORD *)v7 + 115) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
            v11 = *(_QWORD *)a2;
            *((_QWORD *)v7 + 58) = *(_QWORD *)a2;
            if ( (_DWORD)v11 )
            {
              v16 = *(_QWORD **)(result + 1384);
              if ( v16 )
                *v16 = v11;
              v17 = result;
              if ( (unsigned int)((__int64 (*)(void))set_cpus_allowed_ptr)() )
              {
                printk(&unk_62452);
                q_affinity_work(v5, a2);
              }
              printk(&unk_65FA2);
              result = v17;
            }
            else
            {
              v12 = result;
              printk(&unk_65C1E);
              q_affinity_work(v5, a2);
              result = v12;
            }
          }
        }
        _X8 = (unsigned int *)(result + 64);
        __asm { PRFM            #0x11, [X8] }
        do
          v23 = __ldxr(_X8);
        while ( __stlxr(v23 - 1, _X8) );
        if ( v23 == 1 )
        {
          __dmb(9u);
          return _put_task_struct(result);
        }
        else if ( v23 <= 0 )
        {
          return refcount_warn_saturate(result + 64, 3);
        }
      }
      else
      {
        return printk(&unk_6639C);
      }
    }
    else
    {
      return printk(&unk_63FFD);
    }
  }
  return result;
}
