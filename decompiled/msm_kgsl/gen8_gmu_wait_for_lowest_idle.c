__int64 __fastcall gen8_gmu_wait_for_lowest_idle(__int64 a1)
{
  __int64 v2; // x8
  int v3; // w9
  __int64 v4; // x22
  __int64 v5; // x21
  __int64 (*v6)(void); // x10
  int v7; // w25
  __int64 v8; // x20
  _DWORD *v9; // x23
  __int64 v10; // x27
  __int64 result; // x0
  __int64 (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x21
  __int64 v14; // x9
  const char *v15; // x2
  const char *v16; // x3
  int v17; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  int v19; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 14264);
  v3 = *(unsigned __int8 *)(a1 + 20442);
  v4 = *(_QWORD *)(a1 + 1544);
  v20 = 0;
  v5 = *(_QWORD *)(v2 + 40);
  v19 = 0;
  v6 = *(__int64 (**)(void))(v5 + 152);
  v18 = 0;
  if ( v3 )
    v7 = 6;
  else
    v7 = 3;
  v17 = 0;
  if ( *((_DWORD *)v6 - 1) != -944375624 )
    __break(0x822Au);
  v8 = v6();
  v9 = (_DWORD *)(a1 - 816);
  v10 = jiffies + 25LL;
  do
  {
    gmu_core_regread(a1, 129001, &v20);
    gmu_core_regread(a1, 129000, &v19);
    if ( *v9 == v20 && (*v9 != v7 || (v19 & 3) != 0) )
      goto LABEL_15;
    usleep_range_state(10, 100, 2);
  }
  while ( v10 - jiffies >= 0 );
  gmu_core_regread(a1, 129001, &v20);
  gmu_core_regread(a1, 129000, &v19);
  if ( *v9 == v20 && (*v9 != v7 || (v19 & 3) != 0) )
  {
LABEL_15:
    result = 0;
    goto LABEL_16;
  }
  v12 = *(__int64 (__fastcall **)(_QWORD))(v5 + 152);
  if ( *((_DWORD *)v12 - 1) != -944375624 )
    __break(0x8228u);
  v13 = v12(a1);
  gmu_core_regread(a1, 146188, (char *)&v18 + 4);
  gmu_core_regread(a1, 146197, &v18);
  gmu_core_regread(a1, 128996, &v17);
  dev_err(v4 + 16, "----------------------[ GMU error ]----------------------\n");
  v14 = (unsigned int)*v9;
  if ( (unsigned int)v14 > 6 )
    v15 = "(Unknown)";
  else
    v15 = off_166A08[v14];
  if ( v20 > 6 )
    v16 = "(Unknown)";
  else
    v16 = off_166A08[v20];
  dev_err(v4 + 16, "Timeout waiting for lowest idle level %s : wait level %s\n", v15, v16);
  dev_err(v4 + 16, "Start: %llx (absolute ticks)\n", v8);
  dev_err(v4 + 16, "Poll: %llx (ticks relative to start)\n", v13 - v8);
  dev_err(v4 + 16, "RPMH_POWER_STATE=%x GFX_PWR_CLK_STATUS=%x\n", v20, v19);
  dev_err(v4 + 16, "CX_BUSY_STATUS=%x\n", HIDWORD(v18));
  dev_err(v4 + 16, "RBBM_INT_UNMASKED_STATUS=%x PWR_COL_KEEPALIVE=%x\n", v18, v17);
  if ( (v19 & 3) == 0 )
  {
    gen8_regread_aperture(a1, 2233, &v20, 2, 0, 0);
    gen8_regread_aperture(a1, 2233, &v19, 1, 0, 0);
    gen8_host_aperture_set(a1, 0, 0, 0);
    HIDWORD(v18) = kgsl_regmap_read(a1 + 13200);
    LODWORD(v18) = kgsl_regmap_read(a1 + 13200);
    dev_err(v4 + 16, "GEN8_CP_PIPE_STATUS_PIPE BV:%x BR:%x\n", v20, v19);
    dev_err(v4 + 16, "CP2GMU_STATUS=%x CONTEXT_SWITCH_CNTL=%x\n", HIDWORD(v18), v18);
  }
  __break(0x800u);
  gmu_core_fault_snapshot(a1, 12);
  result = 4294967186LL;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
