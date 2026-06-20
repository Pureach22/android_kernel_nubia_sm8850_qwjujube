__int64 __fastcall a6xx_gmu_touch_wakeup(__int64 result)
{
  __int64 v2; // x19
  __int64 v3; // x0
  unsigned __int64 v9; // x8

  _X20 = (unsigned __int64 *)(result - 352);
  if ( (*(_QWORD *)(result - 352) & 0x10) == 0 && (*_X20 & 1) != 0 )
  {
    v2 = result;
    if ( (*_X20 & 2) != 0 )
    {
LABEL_7:
      _msecs_to_jiffies((unsigned int)adreno_wake_timeout);
      return mod_timer(v2 + 8792);
    }
    kgsl_pwrctrl_request_state(result, 2);
    result = a6xx_gmu_boot(v2);
    if ( !(_DWORD)result )
    {
      result = a6xx_gpu_boot(v2);
      if ( !(_DWORD)result )
      {
        v3 = kgsl_pwrscale_wake(v2);
        __asm { PRFM            #0x11, [X20] }
        do
          v9 = __ldxr(_X20);
        while ( __stxr(v9 | 2, _X20) );
        *(_QWORD *)(v2 + 10904) = ktime_get(v3);
        kgsl_pwrctrl_set_state(v2, 2);
        goto LABEL_7;
      }
    }
  }
  return result;
}
