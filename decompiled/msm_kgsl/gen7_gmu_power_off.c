__int64 __fastcall gen7_gmu_power_off(__int64 a1)
{
  unsigned int *v2; // x20
  __int64 v3; // x0
  __int64 v4; // x1
  unsigned int v5; // w8
  int v6; // w21
  int v7; // w21
  __int64 result; // x0
  _DWORD v9[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v2 = (unsigned int *)(a1 - 1776);
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 13192) & 1) != 0 )
    goto LABEL_9;
  if ( (unsigned int)gen7_gmu_wait_for_lowest_idle(a1) )
    goto LABEL_9;
  v3 = gen7_complete_rpmh_votes((__int64)v2, 2);
  if ( (_DWORD)v3 )
    goto LABEL_9;
  v5 = *(_DWORD *)(a1 + 10052);
  if ( v5 < 0x20 )
  {
    v6 = *(_DWORD *)(a1 + 28LL * v5 + 9148);
    v9[2] = *(_DWORD *)(a1 - 424) + ~v5;
    v9[1] = adreno_gmu_bus_ab_quantize(a1, 0) | v6;
    gmu_core_regwrite(a1, 129088, 0);
    v9[0] = 33;
    v7 = gen7_hfi_send_generic_req(a1, v9, 12);
    gmu_core_regwrite(a1, 146192, 0);
    gmu_core_regwrite(a1, 129265, 1);
    if ( !v7 && !(unsigned int)gen7_gmu_wait_for_idle(a1) && !(unsigned int)gen7_rscc_sleep_sequence(a1) )
    {
      gmu_core_rdpm_mx_freq_update(a1, 0);
      if ( !(unsigned int)gen7_halt_gbif(a1) )
      {
        gen7_gmu_irq_disable(a1);
        gen7_hfi_stop(a1);
        gmu_core_disable_clks(a1);
        kgsl_pwrctrl_disable_cx_gdsc(a1);
        gmu_core_rdpm_cx_freq_update(a1, 0);
        result = kgsl_pwrctrl_set_state(a1, 0);
        goto LABEL_10;
      }
    }
LABEL_9:
    disable_irq(*v2);
    disable_irq(*(unsigned int *)(a1 - 1736));
    gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
    gmu_core_regwrite(a1, 146182, 0xFFFFFFFFLL);
    gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
    gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
    gen7_hfi_stop(a1);
    result = gen7_gmu_suspend(a1, 0);
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return gen7_power_off(v3, v4);
}
