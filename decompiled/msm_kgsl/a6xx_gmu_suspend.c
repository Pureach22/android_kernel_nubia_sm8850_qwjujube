__int64 __fastcall a6xx_gmu_suspend(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  unsigned int v4; // w9
  bool v5; // cc
  __int64 v6; // x9
  bool v7; // zf
  int *v8; // x8
  int v9; // w20
  int *v10; // x8
  int v11; // w20
  const char *v12; // x0
  const char *v13; // x0
  const char *v14; // x0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v2 = result;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) == 0 && (*(_QWORD *)(result + 14240) & 0x40000) != 0 )
    goto LABEL_3;
  a6xx_gmu_sptprac_disable(result);
  v3 = *(_QWORD *)(v2 + 14264);
  v4 = *(_DWORD *)v3 - 621;
  v5 = v4 > 0x29;
  v6 = (1LL << v4) & 0x20000000003LL;
  v7 = v5 || v6 == 0;
  if ( !v7 || (v12 = *(const char **)(v3 + 24)) != nullptr && !strcmp(v12, "qcom,adreno-gpu-a642l") )
    gmu_core_regwrite(v2, 129265, 1);
  ((void (__fastcall *)(__int64, __int64))a6xx_complete_rpmh_votes)(v2, 1);
  gmu_core_regwrite(v2, 146196, 7);
  gmu_core_regwrite(v2, 146192, 0);
  __dsb(0xEu);
  gmu_core_regwrite(v2, 129024, 1);
  if ( **(_DWORD **)(v2 + 14264) != 630 )
  {
    v15 = 0;
    gmu_core_regread(v2, 129232, &v15);
    if ( (v15 & 0xC0) == 0 )
    {
      kgsl_regmap_write(v2 + 13200, 1);
      adreno_wait_for_halt_ack_0(v2, 23, 1);
    }
    kgsl_regmap_write(v2 + 13200, 1);
    adreno_wait_for_halt_ack_0(v2, 15430, 1);
    kgsl_regmap_write(v2 + 13200, 2);
    adreno_wait_for_halt_ack_0(v2, 15430, 2);
    kgsl_regmap_write(v2 + 13200, 0);
  }
  v15 = 0;
  gmu_core_regread(v2, 129232, &v15);
  if ( (v15 & 0xC0) == 0 )
  {
    v15 = 0;
    gmu_core_regread(v2, 129260, &v15);
    if ( !v15 )
      kgsl_regmap_write(v2 + 13200, 1);
  }
  __dsb(0xEu);
  _const_udelay(429500);
  v15 = 0;
  gmu_core_regread(v2, 129232, &v15);
  if ( (v15 & 0xC0) == 0 )
  {
    kgsl_pwrctrl_enable_gx_gdsc(v2);
    v8 = *(int **)(v2 + 14264);
    v9 = *v8;
    if ( *v8 == 660
      || (v13 = *((const char **)v8 + 3)) != nullptr && !strcmp(v13, "qcom,adreno-gpu-a642l")
      || v9 == 662
      || v9 == 643 )
    {
      gmu_core_regrmw(v2, 157697, 1, 0);
      _const_udelay(2600);
    }
    kgsl_pwrctrl_disable_gx_gdsc(v2);
    v10 = *(int **)(v2 + 14264);
    v11 = *v10;
    if ( *v10 == 660
      || (v14 = *((const char **)v10 + 3)) != nullptr && !strcmp(v14, "qcom,adreno-gpu-a642l")
      || v11 == 662
      || v11 == 643 )
    {
      gmu_core_regrmw(v2, 157697, 1, 1);
    }
    v15 = 0;
    gmu_core_regread(v2, 129232, &v15);
    if ( (v15 & 0xC0) == 0 )
      dev_err(*(_QWORD *)(v2 + 1544) + 16LL, "gx is stuck on\n");
  }
  gmu_core_disable_clks(v2);
  if ( *(_QWORD *)(v2 + 9024) && (*(_BYTE *)(v2 + 20657) & 2) != 0 )
  {
    __break(0x800u);
    if ( *(_QWORD *)(v2 + 9000) )
    {
LABEL_26:
      if ( (*(_BYTE *)(v2 + 20657) & 2) != 0 )
        regulator_set_mode();
    }
  }
  else if ( *(_QWORD *)(v2 + 9000) )
  {
    goto LABEL_26;
  }
  kgsl_pwrctrl_disable_cx_gdsc(v2);
  if ( *(_QWORD *)(v2 + 9000) && (*(_BYTE *)(v2 + 20657) & 2) != 0 )
    regulator_set_mode();
  gmu_core_rdpm_cx_freq_update(v2, 0);
  dev_err(*(_QWORD *)(v2 + 1544) + 16LL, "Suspended GMU\n");
  result = kgsl_pwrctrl_set_state(v2, 0);
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
