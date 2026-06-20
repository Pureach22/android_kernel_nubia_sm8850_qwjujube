__int64 __fastcall gen8_gmu_power_off(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  unsigned int v4; // w8
  int v5; // w20
  int v6; // w20
  __int64 result; // x0
  _DWORD v8[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 13192) & 1) != 0 )
    goto LABEL_9;
  if ( (unsigned int)gen8_gmu_wait_for_lowest_idle(a1) )
    goto LABEL_9;
  v2 = gen8_complete_rpmh_votes(a1 - 1824, 2);
  if ( (_DWORD)v2 )
    goto LABEL_9;
  v4 = *(_DWORD *)(a1 + 10052);
  if ( v4 < 0x20 )
  {
    v5 = *(_DWORD *)(a1 + 28LL * v4 + 9148);
    v8[2] = *(_DWORD *)(a1 - 536) + ~v4;
    v8[1] = adreno_gmu_bus_ab_quantize(a1, 0) | v5;
    gmu_core_regwrite(a1, 130064, 0);
    v8[0] = 33;
    v6 = gen8_hfi_send_generic_req(a1, v8, 12);
    gmu_core_regwrite(a1, 146192, 0);
    gmu_core_regwrite(a1, 129005, 1);
    if ( !v6 && !(unsigned int)gen8_gmu_wait_for_idle(a1) && !(unsigned int)gen8_rscc_sleep_sequence(a1) )
    {
      gmu_core_rdpm_mx_freq_update(a1, 0);
      if ( !(unsigned int)gen8_halt_gbif(a1) )
      {
        gen8_gmu_irq_disable(a1);
        gen8_hfi_stop(a1);
        gmu_core_disable_clks(a1);
        kgsl_pwrctrl_disable_cx_gdsc(a1);
        gmu_core_rdpm_cx_freq_update(a1, 0);
        result = kgsl_pwrctrl_set_state(a1, 0);
        goto LABEL_10;
      }
    }
LABEL_9:
    gen8_gmu_irq_disable(a1);
    gen8_hfi_stop(a1);
    result = gen8_gmu_suspend(a1, 0);
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return gen8_power_off(v2, v3);
}
