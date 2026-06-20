__int64 __fastcall a6xx_hwsched_gmu_power_off(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w0
  __int64 v8; // x8
  int v9; // w20
  unsigned int v10; // w9
  __int64 result; // x0
  const char *v12; // x0
  _DWORD v13[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 13192) & 1) != 0 || (unsigned int)a6xx_gmu_wait_for_lowest_idle(a1) )
    goto LABEL_9;
  v2 = to_a6xx_gmu(a1);
  v5 = *(_DWORD *)(a1 + 10052);
  v6 = *(_DWORD *)(v2 + 968);
  v13[0] = 33;
  v13[2] = v6 + ~v5;
  if ( v5 < 0x20 )
  {
    v13[1] = *(_DWORD *)(a1 + 28LL * v5 + 9148);
    gmu_core_regwrite(a1, 129088, 0);
    v7 = a6xx_hfi_send_cmd_async(a1, v13, 12);
    v8 = *(_QWORD *)(a1 + 14264);
    v9 = v7;
    v10 = *(_DWORD *)v8 - 621;
    if ( v10 <= 0x29 && ((1LL << v10) & 0x20000000003LL) != 0
      || (v12 = *(const char **)(v8 + 24)) != nullptr && !strcmp(v12, "qcom,adreno-gpu-a642l") )
    {
      gmu_core_regwrite(a1, 129265, 1);
    }
    if ( !v9 && !(unsigned int)a6xx_gmu_wait_for_idle(a1) )
    {
      a6xx_rscc_sleep_sequence(a1);
      gmu_core_rdpm_mx_freq_update(a1, 0);
      a6xx_halt_gbif(a1);
      kgsl_regmap_write(a1 + 13200, 0);
      a6xx_gmu_irq_disable(a1);
      a6xx_hwsched_hfi_stop(a1);
      gmu_core_disable_clks(a1);
      a6xx_gmu_disable_gdsc(a1);
      gmu_core_rdpm_cx_freq_update(a1, 0);
      kgsl_pwrctrl_set_state(a1, 0);
      goto LABEL_10;
    }
LABEL_9:
    a6xx_gmu_irq_disable(a1);
    a6xx_hwsched_hfi_stop(a1);
    a6xx_gmu_suspend(a1, 0);
LABEL_10:
    result = adreno_hwsched_reset_hfi_mem(a1);
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return a6xx_hwsched_dcvs_set(v2, v3, v4);
}
