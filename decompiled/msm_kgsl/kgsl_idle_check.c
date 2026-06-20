__int64 __fastcall kgsl_idle_check(__int64 a1)
{
  int v2; // w20
  __int64 v3; // x20
  int v5; // w0

  rt_mutex_lock(a1 + 2328);
  v2 = *(_DWORD *)(a1 + 2364);
  if ( v2 )
  {
    if ( *(_DWORD *)(a1 + 2360) != 2 )
    {
LABEL_9:
      kgsl_pwrscale_update(a1 - 8760);
      return rt_mutex_unlock(a1 + 2328);
    }
    if ( !*(_DWORD *)(a1 + 2368) )
    {
      raw_spin_lock(a1 + 2320);
      if ( *(_DWORD *)(a1 + 2316) )
      {
        raw_spin_unlock(a1 + 2320);
      }
      else
      {
        if ( v2 == 128 )
          *(_BYTE *)(a1 + 2324) = 1;
        raw_spin_unlock(a1 + 2320);
        v5 = kgsl_pwrctrl_change_state(a1 - 8760, *(unsigned int *)(a1 + 2364));
        if ( v5 )
        {
          if ( v5 == -16 )
          {
            if ( v2 == 128 )
            {
              raw_spin_lock(a1 + 2320);
              *(_BYTE *)(a1 + 2324) = 0;
              raw_spin_unlock(a1 + 2320);
            }
            *(_DWORD *)(a1 + 2364) = v2;
            queue_work_on(32, qword_3A900, a1);
          }
          goto LABEL_7;
        }
      }
    }
    *(_DWORD *)(a1 + 2364) = 0;
LABEL_7:
    if ( *(_DWORD *)(a1 + 2360) == 2 )
    {
      v3 = jiffies;
      *(_QWORD *)(a1 + 5384) = _msecs_to_jiffies(*(_QWORD *)(a1 + 1320)) + v3;
      mod_timer(a1 + 32);
    }
    goto LABEL_9;
  }
  return rt_mutex_unlock(a1 + 2328);
}
