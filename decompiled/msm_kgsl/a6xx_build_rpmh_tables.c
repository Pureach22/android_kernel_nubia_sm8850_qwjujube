unsigned __int64 __fastcall a6xx_build_rpmh_tables(__int64 a1)
{
  unsigned __int64 result; // x0
  _DWORD *v3; // x0
  int v4; // w9
  int v5; // w10
  _DWORD *v6; // x20
  unsigned int v7; // w8
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x6
  __int64 v13; // x20
  unsigned __int64 v14; // x21
  __int64 table; // x0
  __int64 v16; // x22
  unsigned __int64 v17; // x19
  _QWORD v18[2]; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v20[2]; // [xsp+20h] [xbp-30h] BYREF
  __int64 v21; // [xsp+30h] [xbp-20h] BYREF
  __int64 v22; // [xsp+38h] [xbp-18h]
  _QWORD v23[2]; // [xsp+40h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(to_a6xx_gmu(a1) + 964) = 4;
  v20[0] = 0;
  v20[1] = 0;
  v19[0] = 0;
  v19[1] = 0;
  v18[0] = 0;
  v18[1] = 0;
  result = adreno_rpmh_arc_cmds(v20, "gfx.lvl");
  if ( (_DWORD)result )
    goto LABEL_17;
  result = adreno_rpmh_arc_cmds(v19, "cx.lvl");
  if ( (_DWORD)result )
    goto LABEL_17;
  result = adreno_rpmh_arc_cmds(v18, "mx.lvl");
  if ( (_DWORD)result )
    goto LABEL_17;
  v3 = (_DWORD *)to_a6xx_gmu(a1);
  v4 = *(_DWORD *)(a1 + 8392);
  v5 = *(_DWORD *)(a1 + 8396);
  v3[243] = 3;
  v6 = v3;
  v3[293] = 0;
  v7 = *(_DWORD *)(a1 + 8324);
  v22 = 0;
  v23[0] = 0;
  WORD1(v23[0]) = v4;
  WORD2(v23[0]) = v5;
  v21 = 0;
  v3[295] = v7 / 0x3E8;
  v3[297] = *(_DWORD *)(a1 + 8328) / 0x3E8u;
  result = adreno_rpmh_setup_volt_dependency_tbl(&v21, v19, v18, v23, 3);
  if ( (_DWORD)result )
    goto LABEL_17;
  v8 = v6[243];
  if ( !v8
    || (v6[292] = v21, v8 == 1)
    || (v6[294] = HIDWORD(v21), v8 == 2)
    || (v6[296] = v22, v8 == 3)
    || (v6[298] = HIDWORD(v22), v8 == 4) )
  {
    result = setup_gx_arc_votes(a1, v20, v18, v19);
    if ( (_DWORD)result )
      goto LABEL_17;
    v9 = to_a6xx_gmu(a1);
    v10 = *(_QWORD *)(a1 + 10392);
    v11 = *(unsigned int *)(a1 + 10400);
    v12 = *(unsigned __int8 *)(a1 + 24032);
    v13 = v9;
    LODWORD(v21) = 0;
    result = adreno_rpmh_build_bw_votes(&adreno_ddr_bcms, 3, v10, v11, 8, 0, v12);
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_17;
    v14 = result;
    table = kgsl_bus_get_table(*(_QWORD *)(a1 + 11168), "qcom,bus-table-cnoc", &v21);
    if ( (_DWORD)v21 )
    {
      v16 = table;
      v17 = adreno_rpmh_build_bw_votes(
              &adreno_cnoc_bcms,
              1,
              table,
              (unsigned int)v21,
              0,
              0,
              *(unsigned __int8 *)(a1 + 24032));
      kfree(v16);
      if ( v17 >= 0xFFFFFFFFFFFFF001LL )
      {
        adreno_rpmh_free_bw_votes(v14);
        result = (unsigned int)v17;
LABEL_17:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
    else
    {
      kfree(table);
      v17 = 0;
    }
    *(_DWORD *)(v13 + 48) = 3;
    adreno_rpmh_build_bw_table_cmd(v13 + 48, v14, v17);
    adreno_rpmh_free_bw_votes(v14);
    adreno_rpmh_free_bw_votes(v17);
    result = 0;
    goto LABEL_17;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))setup_gx_arc_votes)();
}
