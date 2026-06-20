__int64 __fastcall a6xx_rgmu_pm_suspend(__int64 a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w20
  unsigned __int64 v12; // x9
  unsigned int v14; // w9

  if ( (*(_QWORD *)(a1 - 16) & 4) == 0 )
  {
    kgsl_pwrctrl_request_state(a1, 16);
    v2 = adreno_drain_and_idle(a1);
    if ( v2 )
    {
      v3 = v2;
      adreno_dispatcher_start(a1);
      return v3;
    }
    a6xx_power_off_0(a1);
    _X8 = (unsigned __int64 *)(a1 - 16);
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 | 4, _X8) );
    _X8 = (unsigned int *)(a1 + 20412);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 + 1, _X8) );
    kgsl_pwrctrl_set_state(a1, 16);
  }
  return 0;
}
