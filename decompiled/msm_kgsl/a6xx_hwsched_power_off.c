__int64 __fastcall a6xx_hwsched_power_off(__int64 a1)
{
  __int64 v2; // x0
  __int64 v4; // x20
  unsigned int v5; // w21
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v15; // x10

  v2 = to_a6xx_gmu(a1);
  if ( (*(_QWORD *)(v2 + 1296) & 2) == 0 )
    return 0;
  v4 = v2;
  kgsl_pwrctrl_request_state(a1, 128);
  v5 = a6xx_gmu_oob_set(a1, 0);
  if ( !v5 )
  {
    kgsl_pwrscale_update_stats(a1);
    adreno_coresight_stop(a1);
    adreno_perfcounter_save(a1);
    adreno_irqctrl(a1, 0);
  }
  a6xx_gmu_oob_clear(a1, 0);
  kgsl_pwrctrl_irq(a1, 0);
  a6xx_hwsched_gmu_power_off(a1);
  adreno_hwsched_unregister_contexts(a1);
  if ( *(_BYTE *)(a1 + 20832) == 1 )
  {
    v6 = *(_QWORD *)(a1 + 20824);
    if ( v6 )
    {
      if ( v6 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20848) == 1 )
  {
    v7 = *(_QWORD *)(a1 + 20840);
    if ( v7 )
    {
      if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20864) == 1 )
  {
    v8 = *(_QWORD *)(a1 + 20856);
    if ( v8 )
    {
      if ( v8 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  _X8 = (unsigned __int64 *)(v4 + 1296);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  timer_delete_sync(a1 + 8792);
  kgsl_pwrscale_sleep(a1);
  kgsl_pwrctrl_clear_l3_vote(a1);
  kgsl_pwrctrl_set_state(a1, 128);
  return v5;
}
