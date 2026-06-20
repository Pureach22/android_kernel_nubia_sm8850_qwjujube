__int64 __fastcall a6xx_hwsched_pm_suspend(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned int v4; // w0
  unsigned int v5; // w20
  unsigned int v13; // w9
  unsigned __int64 v16; // x9

  v2 = to_a6xx_gmu(a1);
  if ( (*(_QWORD *)(v2 + 1296) & 0x10) == 0 )
  {
    v3 = v2;
    kgsl_pwrctrl_request_state(a1, 16);
    v4 = adreno_hwsched_drain_and_idle(a1);
    if ( v4 )
    {
      v5 = v4;
      adreno_hwsched_start(a1);
      return v5;
    }
    a6xx_hwsched_power_off(a1);
    _X8 = (unsigned int *)(a1 + 20412);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 + 1, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 1296);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 | 0x10, _X8) );
    kgsl_pwrctrl_set_state(a1, 16);
  }
  return 0;
}
