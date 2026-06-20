__int64 __fastcall a6xx_boot_0(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  unsigned __int64 v11; // x9

  if ( (*(a1 - 2) & 2) != 0 )
    return 0;
  kgsl_pwrctrl_request_state(a1, 2);
  result = a6xx_rgmu_boot(a1);
  if ( !(_DWORD)result )
  {
    result = a6xx_gpu_boot_0(a1);
    if ( !(_DWORD)result )
    {
      v3 = jiffies;
      a1[1768] = _msecs_to_jiffies(a1[1260]) + v3;
      mod_timer(a1 + 1099);
      v4 = kgsl_pwrscale_wake(a1);
      _X8 = a1 - 2;
      __asm { PRFM            #0x11, [X8] }
      do
        v11 = __ldxr(_X8);
      while ( __stxr(v11 | 2, _X8) );
      a1[1363] = ktime_get(v4);
      kgsl_pwrctrl_set_state(a1, 2);
      return 0;
    }
  }
  return result;
}
