__int64 __fastcall gen8_gmu_pm_suspend(__int64 *a1)
{
  unsigned int v3; // w0
  __int64 v4; // x1
  unsigned int v5; // w20
  unsigned __int64 v13; // x8
  unsigned int v15; // w9

  _X20 = (unsigned __int64 *)(a1 - 98);
  if ( (*(a1 - 98) & 0x10) == 0 )
  {
    kgsl_pwrctrl_request_state(a1, 16);
    v3 = adreno_drain_and_idle(a1);
    if ( v3 )
    {
      v5 = v3;
      adreno_dispatcher_start((__int64)a1);
      return v5;
    }
    if ( (*_X20 & 2) != 0 )
      gen8_power_off(a1, v4);
    __asm { PRFM            #0x11, [X20] }
    do
      v13 = __ldxr(_X20);
    while ( __stxr(v13 | 0x10, _X20) );
    _X8 = (unsigned int *)a1 + 5103;
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 + 1, _X8) );
    kgsl_pwrctrl_set_state(a1, 16);
  }
  return 0;
}
