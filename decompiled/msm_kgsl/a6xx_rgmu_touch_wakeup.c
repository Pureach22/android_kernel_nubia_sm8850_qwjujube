__int64 __fastcall a6xx_rgmu_touch_wakeup(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned __int64 v9; // x9

  if ( (*(_QWORD *)(result - 16) & 4) == 0 )
  {
    v1 = result;
    if ( (*(_QWORD *)(result - 16) & 1) != 0 )
    {
      if ( (*(_QWORD *)(result - 16) & 2) != 0 )
      {
LABEL_7:
        _msecs_to_jiffies((unsigned int)adreno_wake_timeout);
        return mod_timer(v1 + 8792);
      }
      kgsl_pwrctrl_request_state(result, 2);
      result = a6xx_rgmu_boot(v1);
      if ( !(_DWORD)result )
      {
        result = a6xx_gpu_boot_0(v1);
        if ( !(_DWORD)result )
        {
          v2 = kgsl_pwrscale_wake(v1);
          _X8 = (unsigned __int64 *)(v1 - 16);
          __asm { PRFM            #0x11, [X8] }
          do
            v9 = __ldxr(_X8);
          while ( __stxr(v9 | 2, _X8) );
          *(_QWORD *)(v1 + 10904) = ktime_get(v2);
          kgsl_pwrctrl_set_state(v1, 2);
          goto LABEL_7;
        }
      }
    }
  }
  return result;
}
