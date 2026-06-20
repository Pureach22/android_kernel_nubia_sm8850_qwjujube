__int64 __fastcall gen8_gmu_suspend(__int64 result, char a2)
{
  _QWORD *v2; // x19
  __int64 region; // x0
  __int64 v4; // x20
  __int64 (**v5)(void); // x8
  __int64 (*v6)(void); // x8
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x21
  int v10; // w2
  __int64 v11; // x21
  __int64 v12; // x8
  _DWORD *v13; // x8
  __int64 v14; // x8
  _DWORD *v15; // x8
  int v16; // w0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v2 = (_QWORD *)result;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 || (*(_QWORD *)(result + 14240) & 0x40000) == 0 )
  {
    gmu_core_regwrite(result, 129005, 1);
    gen8_complete_rpmh_votes(v2 - 228, 1);
    gmu_core_regwrite(v2, 146196, 7);
    gmu_core_regwrite(v2, 146192, 0);
    __dsb(0xEu);
    gmu_core_regwrite(v2, 129024, 1);
    v17 = 0;
    kgsl_regmap_write(v2 + 1650, 1);
    kgsl_regmap_write(v2 + 1650, 0);
    region = kgsl_regmap_get_region(v2 + 1650, 15434);
    v4 = region;
    if ( region )
    {
      v5 = *(__int64 (***)(void))(region + 16);
      if ( v5 )
      {
        v6 = *v5;
        if ( v6 )
        {
          if ( *((_DWORD *)v6 - 1) != -664046789 )
            __break(0x8228u);
          region = v6();
        }
      }
    }
    v7 = ktime_get(region);
    v8 = kgsl_regmap_poll_read(v4, 15434, &v17);
    if ( (_DWORD)v8 )
    {
LABEL_15:
      v10 = v17;
LABEL_16:
      dev_err(*v2, "GBIF reinit timed out: ack = 0x%x\n", v10);
    }
    else
    {
      v9 = v7 + 100000000;
      while ( (v17 & 1) == 0 )
      {
        if ( ktime_get(v8) > v9 )
        {
          v16 = kgsl_regmap_poll_read(v4, 15434, &v17);
          v10 = v17;
          if ( !v16 && (v17 & 1) != 0 )
            break;
          goto LABEL_16;
        }
        usleep_range_state(26, 100, 2);
        __yield();
        v8 = kgsl_regmap_poll_read(v4, 15434, &v17);
        if ( (_DWORD)v8 )
          goto LABEL_15;
      }
    }
    kgsl_regmap_write(v2 + 1650, 2);
    v11 = jiffies + 25LL;
    while ( (kgsl_regmap_read(v2 + 1650) & 2) == 0 )
    {
      v12 = v2[11];
      if ( v12 )
      {
        v13 = *(_DWORD **)(v12 + 32);
        if ( v13 )
        {
          if ( *(v13 - 1) != -1954538307 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, _QWORD))v13)(v2 + 7, 0);
        }
      }
      usleep_range_state(10, 100, 2);
      if ( v11 - jiffies < 0 )
      {
        v14 = v2[11];
        if ( v14 )
        {
          v15 = *(_DWORD **)(v14 + 32);
          if ( v15 )
          {
            if ( *(v15 - 1) != -1954538307 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, _QWORD))v15)(v2 + 7, 0);
          }
        }
        if ( (kgsl_regmap_read(v2 + 1650) & 2) == 0 )
          dev_err(*v2, "%s GBIF halt timed out\n", "CX");
        break;
      }
    }
    v17 = 0;
    gmu_core_regread(v2, 129000, &v17);
    if ( (v17 & 3) == 0 )
    {
      kgsl_pwrctrl_enable_gx_gdsc(v2);
      kgsl_pwrctrl_disable_gx_gdsc(v2);
    }
    gen8_rscc_sleep_sequence((__int64)v2);
    v17 = 0;
    gmu_core_regread(v2, 129000, &v17);
    if ( (v17 & 3) == 0 )
      dev_err(v2[193] + 16LL, "gx is stuck on\n");
    gmu_core_disable_clks(v2);
    kgsl_pwrctrl_disable_cx_gdsc(v2);
    gmu_core_rdpm_cx_freq_update(v2, 0);
    dev_err(v2[193] + 16LL, "Suspended GMU\n");
    result = kgsl_pwrctrl_set_state(v2, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
