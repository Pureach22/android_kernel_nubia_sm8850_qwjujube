__int64 __fastcall gen7_gmu_suspend(__int64 result, char a2)
{
  __int64 v2; // x19
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v2 = result;
  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 || (*(_QWORD *)(result + 14240) & 0x40000) == 0 )
  {
    gmu_core_regwrite(result, 129265, 1);
    gen7_complete_rpmh_votes(v2 - 1776, 1);
    gmu_core_regwrite(v2, 146196, 7);
    gmu_core_regwrite(v2, 146192, 0);
    __dsb(0xEu);
    gmu_core_regwrite(v2, 129024, 1);
    v3 = 0;
    gmu_core_regread(v2, 129232, &v3);
    if ( (v3 & 3) == 0 )
      do_gbif_halt(v2, 22, 23, 1, "GX");
    do_gbif_halt(v2, 15429, 15430, 2, "CX");
    v3 = 0;
    gmu_core_regread(v2, 129232, &v3);
    if ( (v3 & 3) == 0 )
    {
      v3 = 0;
      gmu_core_regread(v2, 129260, &v3);
      if ( !v3 )
        kgsl_regmap_write(v2 + 13200, 1);
    }
    __dsb(0xEu);
    _const_udelay(429500);
    v3 = 0;
    gmu_core_regread(v2, 129232, &v3);
    if ( (v3 & 3) == 0 )
    {
      kgsl_pwrctrl_enable_gx_gdsc(v2);
      kgsl_pwrctrl_disable_gx_gdsc(v2);
      v3 = 0;
      gmu_core_regread(v2, 129232, &v3);
      if ( (v3 & 3) == 0 )
        dev_err(*(_QWORD *)(v2 + 1544) + 16LL, "gx is stuck on\n");
    }
    gmu_core_disable_clks(v2);
    kgsl_pwrctrl_disable_cx_gdsc(v2);
    gmu_core_rdpm_cx_freq_update(v2, 0);
    dev_err(*(_QWORD *)(v2 + 1544) + 16LL, "Suspended GMU\n");
    result = kgsl_pwrctrl_set_state(v2, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
