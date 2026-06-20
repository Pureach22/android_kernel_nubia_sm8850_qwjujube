__int64 __fastcall gen7_gmu_wait_for_lowest_idle(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x22
  __int64 v4; // x21
  __int64 (*v5)(void); // x8
  __int64 v6; // x20
  _DWORD *v7; // x23
  __int64 v8; // x26
  __int64 result; // x0
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x21
  const char *v12; // x9
  const char *v13; // x2
  int v14; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  int v16; // [xsp+10h] [xbp-10h] BYREF
  int v17; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 14264);
  v3 = *(_QWORD *)(a1 + 1544);
  v17 = 0;
  v16 = 0;
  v4 = *(_QWORD *)(v2 + 40);
  v15 = 0;
  v14 = 0;
  v5 = *(__int64 (**)(void))(v4 + 152);
  if ( *((_DWORD *)v5 - 1) != -944375624 )
    __break(0x8228u);
  v6 = v5();
  v7 = (_DWORD *)(a1 - 768);
  v8 = jiffies + 25LL;
  do
  {
    gmu_core_regread(a1, 129260, &v17);
    gmu_core_regread(a1, 129232, &v16);
    if ( *v7 == v17 && (*v7 != 3 || (v16 & 3) != 0) )
      goto LABEL_12;
    usleep_range_state(10, 100, 2);
  }
  while ( v8 - jiffies >= 0 );
  gmu_core_regread(a1, 129260, &v17);
  gmu_core_regread(a1, 129232, &v16);
  if ( *v7 == v17 && (*v7 != 3 || (v16 & 3) != 0) )
  {
LABEL_12:
    result = 0;
    goto LABEL_13;
  }
  v10 = *(__int64 (__fastcall **)(_QWORD))(v4 + 152);
  if ( *((_DWORD *)v10 - 1) != -944375624 )
    __break(0x8228u);
  v11 = v10(a1);
  gmu_core_regread(a1, 146188, (char *)&v15 + 4);
  gmu_core_regread(a1, 146197, &v15);
  gmu_core_regread(a1, 129219, &v14);
  dev_err(v3 + 16, "----------------------[ GMU error ]----------------------\n");
  v12 = "(Unknown)";
  if ( *v7 == 3 )
    v12 = "GPU_HW_IFPC";
  if ( *v7 )
    v13 = v12;
  else
    v13 = "GPU_HW_ACTIVE";
  dev_err(v3 + 16, "Timeout waiting for lowest idle level %s\n", v13);
  dev_err(v3 + 16, "Start: %llx (absolute ticks)\n", v6);
  dev_err(v3 + 16, "Poll: %llx (ticks relative to start)\n", v11 - v6);
  dev_err(v3 + 16, "RPMH_POWER_STATE=%x GFX_PWR_CLK_STATUS=%x\n", v17, v16);
  dev_err(v3 + 16, "CX_BUSY_STATUS=%x\n", HIDWORD(v15));
  dev_err(v3 + 16, "RBBM_INT_UNMASKED_STATUS=%x PWR_COL_KEEPALIVE=%x\n", v15, v14);
  if ( (v16 & 3) == 0 )
  {
    HIDWORD(v15) = kgsl_regmap_read(a1 + 13200);
    LODWORD(v15) = kgsl_regmap_read(a1 + 13200);
    v14 = kgsl_regmap_read(a1 + 13200);
    dev_err(v3 + 16, "GEN7_CP_STATUS_1=%x\n", HIDWORD(v15));
    dev_err(v3 + 16, "CP2GMU_STATUS=%x CONTEXT_SWITCH_CNTL=%x\n", v15, v14);
  }
  __break(0x800u);
  gmu_core_fault_snapshot(a1, 12);
  result = 4294967186LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
