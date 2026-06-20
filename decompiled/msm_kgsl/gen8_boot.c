__int64 __fastcall gen8_boot(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v4; // x21
  __int64 v5; // x0
  unsigned __int64 v11; // x8

  _X20 = a1 - 98;
  if ( (*(a1 - 98) & 2) != 0 )
  {
    __break(0x800u);
    return 0;
  }
  else
  {
    kgsl_pwrctrl_request_state(a1, 2);
    result = gen8_gmu_boot(a1);
    if ( !(_DWORD)result )
    {
      result = gen8_gpu_boot(a1);
      if ( !(_DWORD)result )
      {
        v4 = jiffies;
        a1[1768] = _msecs_to_jiffies(a1[1260]) + v4;
        mod_timer(a1 + 1099);
        v5 = kgsl_pwrscale_wake(a1);
        __asm { PRFM            #0x11, [X20] }
        do
          v11 = __ldxr(_X20);
        while ( __stxr(v11 | 2, _X20) );
        a1[1363] = ktime_get(v5);
        kgsl_pwrctrl_set_state(a1, 2);
        return 0;
      }
    }
  }
  return result;
}
