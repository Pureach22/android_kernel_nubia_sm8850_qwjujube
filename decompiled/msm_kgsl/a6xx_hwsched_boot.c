__int64 __fastcall a6xx_hwsched_boot(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v5; // x21
  __int64 v6; // x0
  unsigned __int64 v13; // x9

  v2 = to_a6xx_gmu((__int64)a1);
  if ( (*(_QWORD *)(v2 + 1296) & 2) != 0 )
    return 0;
  v3 = v2;
  kgsl_pwrctrl_request_state(a1, 2);
  adreno_hwsched_start(a1);
  result = a6xx_hwsched_gmu_boot(a1);
  if ( !(_DWORD)result )
  {
    result = a6xx_hwsched_gpu_boot(a1);
    if ( !(_DWORD)result )
    {
      v5 = jiffies;
      a1[1768] = _msecs_to_jiffies(a1[1260]) + v5;
      mod_timer(a1 + 1099);
      v6 = kgsl_pwrscale_wake(a1);
      _X8 = (unsigned __int64 *)(v3 + 1296);
      __asm { PRFM            #0x11, [X8] }
      do
        v13 = __ldxr(_X8);
      while ( __stxr(v13 | 2, _X8) );
      a1[1363] = ktime_get(v6);
      kgsl_pwrctrl_set_state(a1, 2);
      return 0;
    }
  }
  return result;
}
