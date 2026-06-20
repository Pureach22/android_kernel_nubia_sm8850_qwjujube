__int64 __fastcall ufs_qcom_phy_power_off(__int64 a1)
{
  __int64 v1; // x19
  void (*v2)(void); // x8
  __int64 v3; // x0
  __int64 v4; // x21
  int v5; // w0
  __int64 v6; // x20
  __int64 v7; // x20
  __int64 v8; // x20
  __int64 v9; // x20
  __int64 v10; // x20
  __int64 v11; // x20
  __int64 v12; // x20
  __int64 v13; // x21
  int v14; // w0
  const char **v15; // x20
  __int64 v16; // x21
  int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x21
  int v20; // w0
  __int64 v21; // x0
  __int64 v22; // x21
  int v23; // w0

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(void (**)(void))(*(_QWORD *)(v1 + 416) + 32LL);
  if ( *((_DWORD *)v2 - 1) != 578657965 )
    __break(0x8228u);
  v2();
  v3 = *(_QWORD *)(v1 + 232);
  if ( v3 && v1 != -224 && *(_BYTE *)(v1 + 252) == 1 )
  {
    v4 = *(_QWORD *)(v1 + 16);
    v5 = regulator_disable(v3);
    if ( v5 )
    {
      dev_err(v4, "%s: %s disable failed, err=%d\n", "ufs_qcom_phy_disable_vreg", *(const char **)(v1 + 224), v5);
    }
    else
    {
      ufs_qcom_phy_cfg_vreg(v4, v1 + 224, 0);
      *(_BYTE *)(v1 + 252) = 0;
    }
  }
  if ( *(_BYTE *)(v1 + 152) == 1 )
  {
    v6 = *(_QWORD *)(v1 + 88);
    if ( v6 )
    {
      clk_disable(*(_QWORD *)(v1 + 88));
      clk_unprepare(v6);
    }
    v7 = *(_QWORD *)(v1 + 80);
    if ( v7 )
    {
      clk_disable(*(_QWORD *)(v1 + 80));
      clk_unprepare(v7);
    }
    v8 = *(_QWORD *)(v1 + 72);
    if ( v8 )
    {
      clk_disable(*(_QWORD *)(v1 + 72));
      clk_unprepare(v8);
    }
    v9 = *(_QWORD *)(v1 + 64);
    clk_disable(v9);
    clk_unprepare(v9);
    v10 = *(_QWORD *)(v1 + 96);
    if ( v10 )
    {
      clk_disable(*(_QWORD *)(v1 + 96));
      clk_unprepare(v10);
    }
    *(_BYTE *)(v1 + 152) = 0;
  }
  v11 = *(_QWORD *)(v1 + 40);
  if ( v11 && *(_BYTE *)(v1 + 56) == 1 )
  {
    clk_disable(*(_QWORD *)(v1 + 40));
    clk_unprepare(v11);
    v12 = *(_QWORD *)(v1 + 48);
    clk_disable(v12);
    clk_unprepare(v12);
    *(_BYTE *)(v1 + 56) = 0;
  }
  if ( v1 == -160 || *(_BYTE *)(v1 + 188) != 1 )
  {
LABEL_25:
    v15 = (const char **)(v1 + 192);
    if ( v1 == -192 )
      goto LABEL_29;
    goto LABEL_26;
  }
  v13 = *(_QWORD *)(v1 + 16);
  v14 = regulator_disable(*(_QWORD *)(v1 + 168));
  if ( !v14 )
  {
    ufs_qcom_phy_cfg_vreg(v13, v1 + 160, 0);
    *(_BYTE *)(v1 + 188) = 0;
    goto LABEL_25;
  }
  dev_err(v13, "%s: %s disable failed, err=%d\n", "ufs_qcom_phy_disable_vreg", *(const char **)(v1 + 160), v14);
  v15 = (const char **)(v1 + 192);
  if ( v1 == -192 )
    goto LABEL_29;
LABEL_26:
  if ( *(_BYTE *)(v1 + 220) == 1 )
  {
    v16 = *(_QWORD *)(v1 + 16);
    v17 = regulator_disable(*(_QWORD *)(v1 + 200));
    if ( v17 )
    {
      dev_err(v16, "%s: %s disable failed, err=%d\n", "ufs_qcom_phy_disable_vreg", *v15, v17);
    }
    else
    {
      ufs_qcom_phy_cfg_vreg(v16, (__int64)v15, 0);
      *(_BYTE *)(v1 + 220) = 0;
    }
  }
LABEL_29:
  v18 = *(_QWORD *)(v1 + 296);
  if ( !v18 || v1 == -288 || *(_BYTE *)(v1 + 316) != 1 )
  {
LABEL_34:
    v21 = *(_QWORD *)(v1 + 328);
    if ( !v21 )
      return 0;
    goto LABEL_35;
  }
  v19 = *(_QWORD *)(v1 + 16);
  v20 = regulator_disable(v18);
  if ( !v20 )
  {
    ufs_qcom_phy_cfg_vreg(v19, v1 + 288, 0);
    *(_BYTE *)(v1 + 316) = 0;
    goto LABEL_34;
  }
  dev_err(v19, "%s: %s disable failed, err=%d\n", "ufs_qcom_phy_disable_vreg", *(const char **)(v1 + 288), v20);
  v21 = *(_QWORD *)(v1 + 328);
  if ( !v21 )
    return 0;
LABEL_35:
  if ( v1 != -320 && *(_BYTE *)(v1 + 348) == 1 )
  {
    v22 = *(_QWORD *)(v1 + 16);
    v23 = regulator_disable(v21);
    if ( v23 )
    {
      dev_err(v22, "%s: %s disable failed, err=%d\n", "ufs_qcom_phy_disable_vreg", *(const char **)(v1 + 320), v23);
    }
    else
    {
      ufs_qcom_phy_cfg_vreg(v22, v1 + 320, 0);
      *(_BYTE *)(v1 + 348) = 0;
    }
  }
  return 0;
}
