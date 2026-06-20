__int64 __fastcall a6xx_hwsched_first_open(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x22
  __int64 result; // x0
  __int64 v5; // x20
  unsigned int fw; // w23
  unsigned int v7; // w8
  unsigned int v8; // w0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 bus_counters; // x0
  unsigned __int64 v18; // x9
  unsigned int v21; // w9
  unsigned __int64 v24; // x9
  unsigned __int64 v27; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v33; // x9

  v2 = to_a6xx_gmu(a1);
  if ( (*(_QWORD *)(v2 + 1296) & 1) != 0 )
  {
    result = a6xx_hwsched_boot((_QWORD *)a1);
    if ( (_DWORD)result )
      return result;
    goto LABEL_38;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 4) != 0 || *(_BYTE *)(a1 + 20443) == 1 )
  {
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 | 0x200, _X8) );
  }
  v3 = v2;
  adreno_hwsched_start(a1);
  result = a6xx_microcode_read((_QWORD *)a1);
  if ( (_DWORD)result )
    return result;
  result = a6xx_init(a1);
  if ( (_DWORD)result )
    return result;
  result = a6xx_gmu_parse_fw(a1);
  if ( (_DWORD)result )
    return result;
  result = a6xx_gmu_memory_init(a1);
  if ( (_DWORD)result )
    return result;
  result = gmu_core_hwsched_memory_init(a1);
  if ( (_DWORD)result )
    return result;
  result = a6xx_hwsched_hfi_init(a1);
  if ( (_DWORD)result )
    return result;
  kgsl_pwrctrl_request_state(a1, 2);
  v5 = to_a6xx_gmu(a1);
  kgsl_pwrctrl_request_state(a1, 32);
  a6xx_gmu_aop_send_acd_state(v5, *(_BYTE *)(a1 + 20433));
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( (_DWORD)result )
    return result;
  fw = gmu_core_enable_clks(a1, (unsigned int)(*(_DWORD *)(a1 + 8388) - 1));
  if ( fw )
  {
LABEL_16:
    a6xx_gmu_disable_gdsc(a1);
    gmu_core_rdpm_cx_freq_update(a1, 0);
    return fw;
  }
  fw = a6xx_gmu_load_fw(a1);
  if ( fw || (fw = a6xx_gmu_itcm_shadow(a1)) != 0 )
  {
LABEL_15:
    gmu_core_disable_clks(a1);
    goto LABEL_16;
  }
  if ( (*(_QWORD *)(v5 + 1296) & 0x20) == 0 )
  {
    fw = a6xx_load_pdc_ucode(a1);
    if ( fw )
      goto LABEL_15;
    a6xx_load_rsc_ucode(a1);
    _X8 = (unsigned __int64 *)(v5 + 1296);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 | 0x20, _X8) );
  }
  a6xx_gmu_register_config(a1);
  a6xx_gmu_version_info(a1);
  if ( (*(_WORD *)(a1 + 8282) & 0xFFE) == 0 )
    goto LABEL_42;
  while ( 1 )
  {
    a6xx_gmu_irq_enable(a1);
    v7 = *(_DWORD *)(a1 + 10052);
    if ( v7 < 0x20 )
      break;
    __break(0x5512u);
LABEL_42:
    _X8 = (unsigned __int64 *)(a1 + 22496);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 | 4, _X8) );
  }
  icc_set_bw(
    *(_QWORD *)(a1 + 10456),
    0,
    *(unsigned int *)(*(_QWORD *)(a1 + 10392) + 4LL * *(int *)(a1 + 28LL * v7 + 9152)));
  *(_DWORD *)(a1 + 24448) = 0;
  __dmb(0xAu);
  fw = a6xx_gmu_device_start(a1);
  if ( !fw )
  {
    fw = a6xx_hwsched_hfi_start(a1);
    if ( !fw )
    {
      v8 = gmu_core_clock_set_rate(a1, 0);
      if ( v8 )
      {
        fw = v8;
        a6xx_hwsched_hfi_stop(a1);
        goto LABEL_28;
      }
      icc_set_bw(*(_QWORD *)(a1 + 10456), 0, 0);
      *(_BYTE *)(a1 + 13192) = 0;
      kgsl_pwrctrl_set_state(a1, 32);
      result = a6xx_hwsched_gpu_boot(a1);
      if ( (_DWORD)result )
        return result;
      bus_counters = adreno_get_bus_counters(a1, v9, v10);
      *(_BYTE *)(a1 + 19673) = (*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x200) != 0;
      _X8 = (unsigned __int64 *)(v3 + 1296);
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr(_X8);
      while ( __stxr(v30 | 1, _X8) );
      _X8 = (unsigned __int64 *)(v3 + 1296);
      __asm { PRFM            #0x11, [X8] }
      do
        v33 = __ldxr(_X8);
      while ( __stxr(v33 | 2, _X8) );
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x10) != 0 )
        *(_BYTE *)(a1 + 20437) = 1;
      *(_BYTE *)(a1 + 12960) = 1;
      *(_QWORD *)(a1 + 10904) = ktime_get(bus_counters);
      kgsl_pwrctrl_set_state(a1, 2);
LABEL_38:
      _X8 = (unsigned int *)(a1 + 11128);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 + 1, _X8) );
      adreno_active_count_put(a1);
      return 0;
    }
  }
LABEL_28:
  a6xx_gmu_irq_disable(a1);
  if ( *(_BYTE *)(a1 + 13192) != 1 )
  {
    adreno_hwsched_reset_hfi_mem(a1);
    goto LABEL_15;
  }
  a6xx_gmu_suspend(a1, 0);
  adreno_hwsched_reset_hfi_mem(a1);
  return fw;
}
