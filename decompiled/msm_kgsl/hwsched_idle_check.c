__int64 __fastcall hwsched_idle_check(__int64 a1)
{
  __int64 v2; // x21
  __int64 v4; // x20
  __int64 (__fastcall *v5)(_QWORD); // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 5504) + 40LL);
  rt_mutex_lock(a1 + 2328);
  if ( (*(_QWORD *)(a1 - 7232) & 0x40) == 0 )
  {
    if ( *(_DWORD *)(a1 + 2368) || (__int64)(jiffies - *(_QWORD *)(a1 + 5384)) < 0 )
    {
      kgsl_pwrscale_update(a1 - 8760);
    }
    else
    {
      raw_spin_lock(a1 + 2320);
      if ( *(_DWORD *)(a1 + 2316) )
      {
        raw_spin_unlock(a1 + 2320);
        kgsl_pwrscale_update(a1 - 8760);
        v4 = jiffies;
        *(_QWORD *)(a1 + 5384) = _msecs_to_jiffies(*(_QWORD *)(a1 + 1320)) + v4;
        mod_timer(a1 + 32);
      }
      else
      {
        *(_BYTE *)(a1 + 2324) = 1;
        raw_spin_unlock(a1 + 2320);
        v5 = *(__int64 (__fastcall **)(_QWORD))(v2 + 120);
        if ( *((_DWORD *)v5 - 1) != -1780529452 )
          __break(0x8228u);
        if ( (v5(a1 - 8760) & 1) == 0 )
        {
          dev_err(*(_QWORD *)(a1 - 8760), "GPU isn't idle before SLUMBER\n");
          gmu_core_fault_snapshot(a1 - 8760, 0);
        }
        a6xx_hwsched_power_off(a1 - 8760);
      }
    }
  }
  return rt_mutex_unlock(a1 + 2328);
}
