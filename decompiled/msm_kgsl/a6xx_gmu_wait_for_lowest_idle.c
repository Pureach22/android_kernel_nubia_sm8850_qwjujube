__int64 __fastcall a6xx_gmu_wait_for_lowest_idle(__int64 a1)
{
  __int64 v2; // x23
  unsigned __int64 alwayson; // x20
  _DWORD *v4; // x25
  __int64 v5; // x22
  __int64 result; // x0
  unsigned __int64 v7; // x21
  unsigned __int64 v8; // x22
  const char *v9; // x9
  const char *v10; // x2
  int *v11; // x8
  int v12; // w20
  const char *v13; // x0
  int v14; // w20
  int v15; // w21
  int v16; // w22
  int v17; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v18; // [xsp+10h] [xbp-20h] BYREF
  int v19; // [xsp+18h] [xbp-18h] BYREF
  int v20; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+20h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 1544);
  v21[0] = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  alwayson = a6xx_read_alwayson(a1);
  v4 = (_DWORD *)(a1 - 448);
  v5 = jiffies + 25LL;
  while ( 1 )
  {
    gmu_core_regread(a1, 129260, (char *)v21 + 4);
    gmu_core_regread(a1, 129232, v21);
    if ( *v4 == HIDWORD(v21[0]) )
    {
      result = 0;
      if ( *v4 != 3 || (v21[0] & 0xC0) != 0 )
        break;
    }
    usleep_range_state(10, 100, 2);
    if ( v5 - jiffies < 0 )
    {
      v7 = a6xx_read_alwayson(a1);
      gmu_core_regread(a1, 129260, (char *)v21 + 4);
      gmu_core_regread(a1, 129232, v21);
      if ( *v4 != HIDWORD(v21[0]) || (result = 0, *v4 == 3) && (v21[0] & 0xC0) == 0 )
      {
        v8 = a6xx_read_alwayson(a1);
        gmu_core_regread(a1, 146188, &v20);
        gmu_core_regread(a1, 146197, &v19);
        gmu_core_regread(a1, 129219, (char *)&v18 + 4);
        gmu_core_regread(a1, 146198, &v18);
        dev_err(v2 + 16, "----------------------[ GMU error ]----------------------\n");
        v9 = (const char *)&unk_13C708;
        if ( *v4 == 3 )
          v9 = "GPU_HW_IFPC";
        if ( *v4 )
          v10 = v9;
        else
          v10 = "GPU_HW_ACTIVE";
        dev_err(v2 + 16, "Timeout waiting for lowest idle level %s\n", v10);
        dev_err(v2 + 16, "Start: %llx (absolute ticks)\n", alwayson);
        dev_err(v2 + 16, "Poll: %llx (ticks relative to start)\n", v7 - alwayson);
        dev_err(v2 + 16, "Retry: %llx (ticks relative to poll)\n", v8 - v7);
        dev_err(v2 + 16, "RPMH_POWER_STATE=%x SPTPRAC_PWR_CLK_STATUS=%x\n", HIDWORD(v21[0]), LODWORD(v21[0]));
        dev_err(v2 + 16, "CX_BUSY_STATUS=%x\n", v20);
        dev_err(v2 + 16, "RBBM_INT_UNMASKED_STATUS=%x PWR_COL_KEEPALIVE=%x\n", v19, HIDWORD(v18));
        dev_err(v2 + 16, "A6XX_GMU_AO_SPARE_CNTL=%x\n", v18);
        v11 = *(int **)(a1 + 14264);
        v12 = *v11;
        if ( *v11 == 660
          || (v13 = *((const char **)v11 + 3)) != nullptr && !strcmp(v13, "qcom,adreno-gpu-a642l")
          || v12 == 662
          || v12 == 643 )
        {
          v17 = 0;
          gmu_core_regread(a1, 129220, &v17);
          dev_err(v2 + 16, "PWR_COL_PREEMPT_KEEPALIVE=%x\n", v17);
        }
        if ( (v21[0] & 0xC0) == 0 )
        {
          v14 = kgsl_regmap_read(a1 + 13200);
          v15 = kgsl_regmap_read(a1 + 13200);
          v16 = kgsl_regmap_read(a1 + 13200);
          dev_err(v2 + 16, "A6XX_CP_STATUS_1=%x\n", v14);
          dev_err(v2 + 16, "CP2GMU_STATUS=%x CONTEXT_SWITCH_CNTL=%x\n", v15, v16);
        }
        __break(0x800u);
        gmu_core_fault_snapshot(a1, 12);
        result = 4294967186LL;
      }
      break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
