__int64 __fastcall a6xx_gmu_power_off(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  unsigned int v4; // w8
  int v5; // w21
  int v6; // w25
  unsigned int v7; // w20
  unsigned int v8; // w21
  _BOOL4 v9; // w20
  int v10; // w20
  __int64 v11; // x8
  unsigned int v12; // w9
  __int64 result; // x0
  const char *v14; // x0
  _DWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF
  int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 13192) & 1) != 0 )
    goto LABEL_18;
  if ( (unsigned int)a6xx_gmu_wait_for_lowest_idle(a1) )
    goto LABEL_18;
  a6xx_complete_rpmh_votes(a1, 2u);
  if ( (_DWORD)v2 )
    goto LABEL_18;
  v4 = *(_DWORD *)(a1 + 10052);
  if ( v4 < 0x20 )
  {
    v5 = *(_DWORD *)(a1 - 680);
    v6 = ~v4;
    v16 = 0;
    v7 = *(_DWORD *)(a1 + 28LL * v4 + 9148);
    gmu_core_regwrite(a1, 129088, 0);
    if ( !*(_DWORD *)(a1 - 448) )
      a6xx_gmu_sptprac_disable(a1);
    v8 = v5 + v6;
    if ( (*(_BYTE *)(a1 + 20656) & 0x20) == 0 )
    {
      v15[1] = v7;
      v15[2] = v8;
      v15[0] = 33;
      v9 = a6xx_hfi_send_generic_req(a1, v15, 12) == 0;
      goto LABEL_13;
    }
    gmu_core_regwrite(a1, 117752, 1);
    gmu_core_regwrite(a1, 117753, v8);
    gmu_core_regwrite(a1, 117754, v7);
    v10 = a6xx_gmu_oob_set(a1, 6u);
    a6xx_gmu_oob_clear(a1, 6u);
    if ( !v10 )
    {
      gmu_core_regread(a1, 129260, &v16);
      if ( v16 == 15 )
      {
        v9 = 1;
LABEL_13:
        gmu_core_regwrite(a1, 146192, 0);
        v11 = *(_QWORD *)(a1 + 14264);
        v12 = *(_DWORD *)v11 - 621;
        if ( v12 <= 0x29 && ((1LL << v12) & 0x20000000003LL) != 0
          || (v14 = *(const char **)(v11 + 24)) != nullptr && !strcmp(v14, "qcom,adreno-gpu-a642l") )
        {
          gmu_core_regwrite(a1, 129265, 1);
        }
        if ( v9 && !(unsigned int)a6xx_gmu_wait_for_idle(a1) )
        {
          a6xx_rscc_sleep_sequence(a1);
          gmu_core_rdpm_mx_freq_update(a1, 0);
          if ( **(_DWORD **)(a1 + 14264) != 630 )
          {
            a6xx_halt_gbif(a1);
            kgsl_regmap_write(a1 + 13200, 0);
          }
          a6xx_gmu_irq_disable(a1);
          a6xx_hfi_stop(a1);
          gmu_core_disable_clks(a1);
          a6xx_gmu_disable_gdsc(a1);
          gmu_core_rdpm_cx_freq_update(a1, 0);
          result = kgsl_pwrctrl_set_state(a1, 0);
          goto LABEL_19;
        }
LABEL_18:
        disable_irq(*(unsigned int *)(a1 - 1648));
        disable_irq(*(unsigned int *)(a1 - 1616));
        gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
        gmu_core_regwrite(a1, 146182, 0xFFFFFFFFLL);
        gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
        gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
        a6xx_hfi_stop(a1);
        result = a6xx_gmu_suspend(a1, 0);
LABEL_19:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Failed to prepare for slumber: 0x%x\n", v16);
    }
    v9 = 0;
    goto LABEL_13;
  }
  __break(0x5512u);
  return a6xx_power_off(v2, v3);
}
