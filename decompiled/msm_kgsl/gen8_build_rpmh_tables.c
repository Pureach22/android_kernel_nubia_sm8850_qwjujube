__int64 __fastcall gen8_build_rpmh_tables(_QWORD *a1)
{
  _DWORD *v2; // x20
  int v3; // w0
  _DWORD *v4; // x0
  unsigned int v5; // w8
  __int64 v6; // x4
  __int64 v7; // x9
  unsigned int *v8; // x10
  unsigned int v9; // w12
  int v10; // w8
  _QWORD *v11; // x0
  _QWORD *v12; // x3
  unsigned __int64 v13; // x21
  __int64 v14; // x20
  unsigned int acv_perfmode_lvl; // w0
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x6
  unsigned __int64 v19; // x0
  unsigned __int64 v20; // x22
  __int64 table; // x0
  __int64 v22; // x23
  _QWORD v24[2]; // [xsp+8h] [xbp-A8h] BYREF
  _QWORD v25[2]; // [xsp+18h] [xbp-98h] BYREF
  _QWORD v26[2]; // [xsp+28h] [xbp-88h] BYREF
  _QWORD v27[2]; // [xsp+38h] [xbp-78h] BYREF
  __int64 v28; // [xsp+48h] [xbp-68h] BYREF
  __int64 v29; // [xsp+50h] [xbp-60h]
  __int64 v30; // [xsp+58h] [xbp-58h]
  __int64 v31; // [xsp+60h] [xbp-50h]
  __int64 v32; // [xsp+68h] [xbp-48h]
  __int64 v33; // [xsp+70h] [xbp-40h]
  __int64 v34; // [xsp+78h] [xbp-38h]
  __int64 v35; // [xsp+80h] [xbp-30h]
  __int16 v36; // [xsp+88h] [xbp-28h] BYREF
  __int64 v37; // [xsp+8Ah] [xbp-26h]
  __int64 v38; // [xsp+92h] [xbp-1Eh]
  _WORD v39[7]; // [xsp+9Ah] [xbp-16h] BYREF
  __int64 v40; // [xsp+A8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_DWORD *)to_gen8_gmu((__int64)a1);
  v27[0] = 0;
  v27[1] = 0;
  v26[0] = 0;
  v26[1] = 0;
  v25[0] = 0;
  v25[1] = 0;
  v24[0] = 0;
  v24[1] = 0;
  v3 = adreno_rpmh_arc_cmds(v27, "gfx.lvl");
  if ( v3 )
    goto LABEL_53;
  v3 = adreno_rpmh_arc_cmds(v26, "cx.lvl");
  if ( v3 )
    goto LABEL_53;
  v3 = adreno_rpmh_arc_cmds(v25, "mx.lvl");
  if ( v3 )
    goto LABEL_53;
  v4 = (_DWORD *)gen8_gmu_to_adreno((__int64)v2);
  v5 = v4[2097];
  memset(v39, 0, sizeof(v39));
  v38 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v36 = 0;
  if ( (int)v5 >= 1 )
  {
    LOWORD(v37) = v4[2098];
    if ( v5 != 1 )
    {
      WORD1(v37) = v4[2099];
      if ( v5 >= 3 )
      {
        WORD2(v37) = v4[2100];
        if ( v5 != 3 )
        {
          HIWORD(v37) = v4[2101];
          if ( v5 >= 5 )
          {
            LOWORD(v38) = v4[2102];
            if ( v5 != 5 )
            {
              WORD1(v38) = v4[2103];
              if ( v5 >= 7 )
              {
                WORD2(v38) = v4[2104];
                if ( v5 != 7 )
                {
                  HIWORD(v38) = v4[2105];
                  if ( v5 >= 9 )
                  {
                    v39[0] = v4[2106];
                    if ( v5 != 9 )
                    {
                      v39[1] = v4[2107];
                      if ( v5 >= 0xB )
                      {
                        v39[2] = v4[2108];
                        if ( v5 != 11 )
                        {
                          v39[3] = v4[2109];
                          if ( v5 >= 0xD )
                          {
                            v39[4] = v4[2110];
                            if ( v5 != 13 )
                            {
                              v39[5] = v4[2111];
                              if ( v5 >= 0xF )
                              {
                                v39[6] = v4[2112];
                                if ( v5 != 15 )
                                  goto LABEL_58;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v6 = v5 + 1;
  v2[421] = 0;
  v2[323] = v6;
  if ( (int)v4[2097] >= 1 )
  {
    v7 = 0;
    v8 = v2 + 423;
    while ( v7 != 15 )
    {
      v9 = v4[v7++ + 2081];
      *v8 = v9 / 0x3E8;
      v8 += 2;
      if ( v7 >= (int)v4[2097] )
        goto LABEL_24;
    }
LABEL_58:
    __break(0x5512u);
  }
LABEL_24:
  v3 = adreno_rpmh_setup_volt_dependency_tbl(&v28, v26, v25, &v36, v6);
  if ( v3 )
  {
LABEL_53:
    LODWORD(v13) = v3;
LABEL_54:
    dev_err(*a1, "Failed to build dcvs table\n");
    goto LABEL_57;
  }
  v10 = v2[323];
  if ( v10 )
  {
    v2[420] = v28;
    if ( v10 != 1 )
    {
      v2[422] = HIDWORD(v28);
      if ( v10 != 2 )
      {
        v2[424] = v29;
        if ( v10 != 3 )
        {
          v2[426] = HIDWORD(v29);
          if ( v10 != 4 )
          {
            v2[428] = v30;
            if ( v10 != 5 )
            {
              v2[430] = HIDWORD(v30);
              if ( v10 != 6 )
              {
                v2[432] = v31;
                if ( v10 != 7 )
                {
                  v2[434] = HIDWORD(v31);
                  if ( v10 != 8 )
                  {
                    v2[436] = v32;
                    if ( v10 != 9 )
                    {
                      v2[438] = HIDWORD(v32);
                      if ( v10 != 10 )
                      {
                        v2[440] = v33;
                        if ( v10 != 11 )
                        {
                          v2[442] = HIDWORD(v33);
                          if ( v10 != 12 )
                          {
                            v2[444] = v34;
                            if ( v10 != 13 )
                            {
                              v2[446] = HIDWORD(v34);
                              if ( v10 != 14 )
                              {
                                v2[448] = v35;
                                if ( v10 != 15 )
                                {
                                  v2[450] = HIDWORD(v35);
                                  if ( v10 != 16 )
                                    goto LABEL_58;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (unsigned int)cmd_db_read_addr("gmxc.lvl") && (unsigned int)adreno_rpmh_arc_cmds(v24, "gmxc.lvl") != -61 )
  {
    v12 = v24;
    v11 = a1;
  }
  else
  {
    v11 = a1;
    v12 = nullptr;
  }
  LODWORD(v13) = setup_gx_arc_votes_1(v11, v27, v25, v12, v26);
  if ( (_DWORD)v13 )
    goto LABEL_54;
  v14 = to_gen8_gmu((__int64)a1);
  acv_perfmode_lvl = kgsl_pwrctrl_get_acv_perfmode_lvl(a1, *(unsigned int *)(a1[1783] + 224LL));
  v16 = a1[1299];
  v17 = *((unsigned int *)a1 + 2600);
  v18 = *((unsigned __int8 *)a1 + 24032);
  LODWORD(v28) = 0;
  v19 = adreno_rpmh_build_bw_votes(&adreno_ddr_bcms_1, 3, v16, v17, 4, acv_perfmode_lvl, v18);
  if ( v19 <= 0xFFFFFFFFFFFFF000LL )
  {
    v20 = v19;
    table = kgsl_bus_get_table(a1[1396], "qcom,bus-table-cnoc", &v28);
    if ( (_DWORD)v28 )
    {
      v22 = table;
      v13 = adreno_rpmh_build_bw_votes(
              &adreno_cnoc_bcms_1,
              1,
              table,
              (unsigned int)v28,
              0,
              0,
              *((unsigned __int8 *)a1 + 24032));
      kfree(v22);
      if ( v13 >= 0xFFFFFFFFFFFFF001LL )
      {
        adreno_rpmh_free_bw_votes(v20);
        goto LABEL_52;
      }
    }
    else
    {
      kfree(table);
      v13 = 0;
    }
    *(_DWORD *)(v14 + 56) = 3;
    adreno_rpmh_build_bw_table_cmd(v14 + 56, v20, v13);
    adreno_rpmh_free_bw_votes(v20);
    adreno_rpmh_free_bw_votes(v13);
    LODWORD(v13) = 0;
    goto LABEL_57;
  }
  LODWORD(v13) = v19;
LABEL_52:
  dev_err(*a1, "Failed to build bw table\n");
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v13;
}
