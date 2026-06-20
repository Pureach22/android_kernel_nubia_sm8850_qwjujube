__int64 __fastcall a6xx_power_off_0(__int64 a1)
{
  unsigned int v2; // w20
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v13; // x10

  adreno_check_idle((_QWORD *)a1);
  kgsl_pwrctrl_request_state(a1, 128);
  v2 = a6xx_rgmu_oob_set(a1, 0);
  if ( v2 )
  {
    gmu_core_regwrite(a1, 129428, 0x1000000);
  }
  else
  {
    if ( a6xx_irq_pending(a1) )
    {
      a6xx_gmu_oob_clear(a1, 0);
      return (unsigned int)-16;
    }
    kgsl_pwrscale_update_stats(a1);
    adreno_coresight_stop(a1);
    adreno_perfcounter_save(a1);
    adreno_irqctrl(a1, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    gmu_core_regwrite(a1, 129428, 0x1000000);
  }
  kgsl_regmap_write(a1 + 13200, 1);
  adreno_wait_for_halt_ack_1(a1, 1);
  kgsl_pwrctrl_irq(a1, 0);
  a6xx_rgmu_power_off(a1);
  adreno_set_active_ctxs_null(a1);
  adreno_dispatcher_stop(a1);
  adreno_ringbuffer_stop(a1);
  if ( *(_BYTE *)(a1 + 20832) == 1 )
  {
    v3 = *(_QWORD *)(a1 + 20824);
    if ( v3 )
    {
      if ( v3 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20848) == 1 )
  {
    v4 = *(_QWORD *)(a1 + 20840);
    if ( v4 )
    {
      if ( v4 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20864) == 1 )
  {
    v5 = *(_QWORD *)(a1 + 20856);
    if ( v5 )
    {
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  _X8 = (unsigned __int64 *)(a1 - 16);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  timer_delete_sync(a1 + 8792);
  kgsl_pwrscale_sleep(a1);
  kgsl_pwrctrl_set_state(a1, 128);
  return v2;
}
