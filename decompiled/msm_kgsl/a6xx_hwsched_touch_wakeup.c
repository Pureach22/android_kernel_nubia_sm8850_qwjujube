__int64 __fastcall a6xx_hwsched_touch_wakeup(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  unsigned __int64 v11; // x9

  result = to_a6xx_gmu(a1);
  if ( (*(_QWORD *)(result + 1296) & 0x10) == 0 && (*(_QWORD *)(result + 1296) & 1) != 0 )
  {
    if ( (*(_QWORD *)(result + 1296) & 2) != 0 )
    {
LABEL_7:
      _msecs_to_jiffies((unsigned int)adreno_wake_timeout);
      return mod_timer(a1 + 8792);
    }
    v3 = result;
    kgsl_pwrctrl_request_state(a1, 2);
    result = a6xx_hwsched_gmu_boot(a1);
    if ( !(_DWORD)result )
    {
      result = a6xx_hwsched_gpu_boot(a1);
      if ( !(_DWORD)result )
      {
        v4 = kgsl_pwrscale_wake(a1);
        _X8 = (unsigned __int64 *)(v3 + 1296);
        __asm { PRFM            #0x11, [X8] }
        do
          v11 = __ldxr(_X8);
        while ( __stxr(v11 | 2, _X8) );
        *(_QWORD *)(a1 + 10904) = ktime_get(v4);
        kgsl_pwrctrl_set_state(a1, 2);
        goto LABEL_7;
      }
    }
  }
  return result;
}
