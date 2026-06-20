__int64 __fastcall gmu_idle_check_1(__int64 a1)
{
  __int64 v3; // x20
  __int64 v4; // x1

  rt_mutex_lock(a1 + 2328);
  if ( (*(_QWORD *)(a1 - 7232) & 0x40) == 0 )
  {
    if ( *(_DWORD *)(a1 + 2368) || (__int64)(jiffies - *(_QWORD *)(a1 + 5384)) < 0 )
    {
      kgsl_pwrscale_update(a1 - 8760);
    }
    else if ( (*(_QWORD *)(a1 - 9544) & 2) != 0 )
    {
      raw_spin_lock(a1 + 2320);
      if ( *(_DWORD *)(a1 + 2316) )
      {
        raw_spin_unlock(a1 + 2320);
        kgsl_pwrscale_update(a1 - 8760);
        v3 = jiffies;
        *(_QWORD *)(a1 + 5384) = _msecs_to_jiffies(*(_QWORD *)(a1 + 1320)) + v3;
        mod_timer(a1 + 32);
      }
      else
      {
        *(_BYTE *)(a1 + 2324) = 1;
        raw_spin_unlock(a1 + 2320);
        if ( (unsigned int)gen8_power_off(a1 - 8760, v4) == -16 )
        {
          kgsl_pwrscale_update(a1 - 8760);
          kgsl_start_idle_timer_1(a1 - 8760);
        }
      }
    }
  }
  return rt_mutex_unlock(a1 + 2328);
}
