__int64 __fastcall gen7_build_rpmh_tables(_QWORD *a1)
{
  _DWORD *v2; // x20
  int v3; // w0
  _DWORD *v4; // x0
  __int16 v5; // w8
  __int16 v6; // w8
  unsigned int v7; // w9
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x20
  unsigned int v12; // w21
  __int64 acv_perfmode_lvl; // x5
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x6
  unsigned __int64 v17; // x0
  unsigned __int64 v18; // x21
  unsigned __int64 v19; // x22
  __int64 table; // x0
  __int64 v21; // x23
  _QWORD v23[2]; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v25[2]; // [xsp+20h] [xbp-30h] BYREF
  __int64 v26; // [xsp+30h] [xbp-20h] BYREF
  __int64 v27; // [xsp+38h] [xbp-18h]
  _QWORD v28[2]; // [xsp+40h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_DWORD *)to_gen7_gmu((__int64)a1);
  v25[0] = 0;
  v25[1] = 0;
  v24[0] = 0;
  v24[1] = 0;
  v23[0] = 0;
  v23[1] = 0;
  v3 = adreno_rpmh_arc_cmds(v25, "gfx.lvl");
  if ( v3 )
    goto LABEL_20;
  v3 = adreno_rpmh_arc_cmds(v24, "cx.lvl");
  if ( v3 )
    goto LABEL_20;
  v3 = adreno_rpmh_arc_cmds(v23, "mx.lvl");
  if ( v3 )
    goto LABEL_20;
  v4 = (_DWORD *)gen7_gmu_to_adreno((__int64)v2);
  v5 = v4[2098];
  v27 = 0;
  v28[0] = 0;
  v26 = 0;
  WORD1(v28[0]) = v5;
  v6 = v4[2099];
  v2[339] = 3;
  v2[437] = 0;
  v7 = v4[2081];
  WORD2(v28[0]) = v6;
  v2[439] = v7 / 0x3E8;
  v2[441] = v4[2082] / 0x3E8u;
  v3 = adreno_rpmh_setup_volt_dependency_tbl(&v26, v24, v23, v28, 3);
  if ( v3 )
    goto LABEL_20;
  v8 = v2[339];
  if ( !v8
    || (v2[436] = v26, v8 == 1)
    || (v2[438] = HIDWORD(v26), v8 == 2)
    || (v2[440] = v27, v8 == 3)
    || (v2[442] = HIDWORD(v27), v8 == 4) )
  {
    v3 = setup_gx_arc_votes_0(a1, v25, v23, v24);
    if ( !v3 )
    {
      v9 = to_gen7_gmu((__int64)a1);
      v10 = a1[1783];
      v11 = v9;
      v12 = *(_DWORD *)(v10 + 244);
      if ( v12 )
      {
        acv_perfmode_lvl = (unsigned int)kgsl_pwrctrl_get_acv_perfmode_lvl(a1, *(unsigned int *)(v10 + 240));
      }
      else
      {
        acv_perfmode_lvl = 1;
        v12 = 8;
      }
      v14 = a1[1299];
      v15 = *((unsigned int *)a1 + 2600);
      v16 = *((unsigned __int8 *)a1 + 24032);
      LODWORD(v26) = 0;
      v17 = adreno_rpmh_build_bw_votes(&adreno_ddr_bcms_0, 3, v14, v15, v12, acv_perfmode_lvl, v16);
      if ( v17 > 0xFFFFFFFFFFFFF000LL )
      {
        LODWORD(v18) = v17;
LABEL_19:
        dev_err(*a1, "Failed to build bw table\n");
LABEL_23:
        _ReadStatusReg(SP_EL0);
        return (unsigned int)v18;
      }
      v19 = v17;
      table = kgsl_bus_get_table(a1[1396], "qcom,bus-table-cnoc", &v26);
      if ( (_DWORD)v26 )
      {
        v21 = table;
        v18 = adreno_rpmh_build_bw_votes(
                &adreno_cnoc_bcms_0,
                1,
                table,
                (unsigned int)v26,
                0,
                0,
                *((unsigned __int8 *)a1 + 24032));
        kfree(v21);
        if ( v18 >= 0xFFFFFFFFFFFFF001LL )
        {
          adreno_rpmh_free_bw_votes(v19);
          goto LABEL_19;
        }
      }
      else
      {
        kfree(table);
        v18 = 0;
      }
      *(_DWORD *)(v11 + 56) = 3;
      adreno_rpmh_build_bw_table_cmd(v11 + 56, v19, v18);
      adreno_rpmh_free_bw_votes(v19);
      adreno_rpmh_free_bw_votes(v18);
      LODWORD(v18) = 0;
      goto LABEL_23;
    }
LABEL_20:
    LODWORD(v18) = v3;
    dev_err(*a1, "Failed to build dcvs table\n");
    goto LABEL_23;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))setup_gx_arc_votes_0)();
}
