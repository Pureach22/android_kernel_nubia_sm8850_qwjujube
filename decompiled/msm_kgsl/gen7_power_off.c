__int64 __fastcall gen7_power_off(_QWORD *a1)
{
  _QWORD *v3; // x22
  unsigned int v4; // w20
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v14; // x9

  _X21 = a1 - 85;
  v3 = a1 + 2552;
  if ( (*(a1 - 85) & 2) == 0 )
    __break(0x800u);
  adreno_check_idle(a1);
  kgsl_pwrctrl_request_state(a1, 128);
  v4 = gen7_gmu_oob_set((__int64)a1, 0);
  if ( !v4 )
  {
    if ( ((_DWORD)v3[59] & (unsigned int)kgsl_regmap_read(a1 + 1650)) != 0 || *(_DWORD *)v3 )
    {
      gmu_core_regwrite(a1, 129428, 0x80000000LL);
      return (unsigned int)-16;
    }
    kgsl_pwrscale_update_stats(a1);
    adreno_coresight_stop(a1);
    adreno_irqctrl((__int64)a1, 0);
  }
  gmu_core_regwrite(a1, 129428, 0x80000000LL);
  kgsl_pwrctrl_irq(a1, 0);
  gen7_gmu_power_off((__int64)a1);
  adreno_set_active_ctxs_null((__int64)a1);
  adreno_dispatcher_stop((__int64)a1);
  adreno_ringbuffer_stop(a1);
  if ( *((_BYTE *)v3 + 416) == 1 )
  {
    v5 = a1[2603];
    if ( v5 )
    {
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *((_BYTE *)v3 + 432) == 1 )
  {
    v6 = a1[2605];
    if ( v6 )
    {
      if ( v6 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *((_BYTE *)v3 + 448) == 1 )
  {
    v7 = a1[2607];
    if ( v7 )
    {
      if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  __asm { PRFM            #0x11, [X21] }
  do
    v14 = __ldxr(_X21);
  while ( __stxr(v14 & 0xFFFFFFFFFFFFFFFDLL, _X21) );
  timer_delete_sync(a1 + 1099);
  kgsl_pwrscale_sleep(a1);
  kgsl_pwrctrl_clear_l3_vote(a1);
  gen7_reset_preempt_records(a1);
  kgsl_pwrctrl_set_state(a1, 128);
  return v4;
}
