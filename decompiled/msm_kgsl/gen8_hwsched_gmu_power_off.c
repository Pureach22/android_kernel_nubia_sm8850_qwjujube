__int64 __fastcall gen8_hwsched_gmu_power_off(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w8
  int v4; // w9
  int v5; // w20
  int v6; // w20
  __int64 result; // x0
  _DWORD v8[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 13192) & 1) != 0 || (unsigned int)gen8_gmu_wait_for_lowest_idle(a1) )
    goto LABEL_6;
  v2 = to_gen8_gmu(a1);
  v3 = *(_DWORD *)(a1 + 10052);
  v4 = *(_DWORD *)(v2 + 1288);
  v8[0] = 33;
  v8[2] = v4 + ~v3;
  if ( v3 < 0x20 )
  {
    v5 = *(_DWORD *)(a1 + 28LL * v3 + 9148);
    v8[1] = adreno_gmu_bus_ab_quantize(a1, 0) | v5;
    gmu_core_regwrite(a1, 130064, 0);
    v6 = gen8_hfi_send_cmd_async(a1, v8, 12);
    gen8_scm_gpu_tsens_default(a1, 0);
    gmu_core_regwrite(a1, 129005, 1);
    if ( !v6 && !(unsigned int)gen8_gmu_wait_for_idle(a1) )
    {
      gen8_rscc_sleep_sequence(a1);
      gmu_core_rdpm_mx_freq_update(a1, 0);
      gen8_halt_gbif(a1);
      gen8_gmu_irq_disable(a1);
      gen8_hwsched_hfi_stop(a1);
      gmu_core_disable_clks(a1);
      kgsl_pwrctrl_disable_cx_gdsc(a1);
      gmu_core_rdpm_cx_freq_update(a1, 0);
      kgsl_pwrctrl_set_state(a1, 0);
      goto LABEL_7;
    }
LABEL_6:
    gen8_gmu_irq_disable(a1);
    gen8_hwsched_hfi_stop(a1);
    gen8_gmu_suspend(a1, 0);
LABEL_7:
    result = adreno_hwsched_reset_hfi_mem(a1);
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return get_guilty_context_0(v2);
}
