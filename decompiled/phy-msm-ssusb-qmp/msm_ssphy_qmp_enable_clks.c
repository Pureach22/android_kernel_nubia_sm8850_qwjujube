__int64 __fastcall msm_ssphy_qmp_enable_clks(__int64 result, char a2)
{
  char v2; // w8
  _QWORD *v4; // x19
  __int64 v5; // x21
  int v6; // w0
  int v7; // w0
  int v8; // w22
  __int64 v9; // x21
  int v10; // w0
  int v11; // w0
  int v12; // w22
  __int64 v13; // x21
  int v14; // w0
  int v15; // w0
  int v16; // w22
  __int64 v17; // x21
  int v18; // w0
  int v19; // w0
  int v20; // w22
  __int64 v21; // x21
  int v22; // w0
  int v23; // w0
  int v24; // w22
  __int64 v25; // x21
  unsigned int v26; // w22
  __int64 v27; // x20
  __int64 v28; // x20
  __int64 v29; // x20
  __int64 v30; // x20
  __int64 v31; // x20
  __int64 v32; // x20

  v2 = *(_BYTE *)(result + 545);
  v4 = (_QWORD *)result;
  if ( (a2 & 1) != 0 && (*(_BYTE *)(result + 545) & 1) == 0 )
  {
    v5 = *(_QWORD *)(result + 456);
    if ( !v5 )
      goto LABEL_8;
    v6 = clk_prepare(*(_QWORD *)(result + 456));
    if ( !v6 )
    {
      v7 = clk_enable(v5);
      if ( !v7 )
        goto LABEL_8;
      v8 = v7;
      clk_unprepare(v5);
      v6 = v8;
    }
    if ( v6 < 0 )
    {
      dev_err(*v4, "%s: ref_clk_src enable failed\n", "msm_ssphy_qmp_enable_clks");
      v9 = v4[58];
      if ( !v9 )
        goto LABEL_14;
      goto LABEL_9;
    }
LABEL_8:
    v9 = v4[58];
    if ( !v9 )
      goto LABEL_14;
LABEL_9:
    v10 = clk_prepare(v9);
    if ( !v10 )
    {
      v11 = clk_enable(v9);
      if ( !v11 )
        goto LABEL_14;
      v12 = v11;
      clk_unprepare(v9);
      v10 = v12;
    }
    if ( v10 < 0 )
      dev_err(*v4, "%s: ref_clk enable failed\n", "msm_ssphy_qmp_enable_clks");
LABEL_14:
    v13 = v4[60];
    if ( !v13 )
      goto LABEL_20;
    v14 = clk_prepare(v4[60]);
    if ( !v14 )
    {
      v15 = clk_enable(v13);
      if ( !v15 )
        goto LABEL_20;
      v16 = v15;
      clk_unprepare(v13);
      v14 = v16;
    }
    if ( v14 < 0 )
      dev_err(*v4, "%s: com_aux enable failed\n", "msm_ssphy_qmp_enable_clks");
LABEL_20:
    v17 = v4[59];
    v18 = clk_prepare(v17);
    if ( v18 )
    {
      if ( v18 < 0 )
        goto LABEL_54;
    }
    else
    {
      v19 = clk_enable(v17);
      if ( v19 )
      {
        v20 = v19;
        clk_unprepare(v17);
        if ( v20 < 0 )
        {
LABEL_54:
          dev_err(*v4, "%s: aux_clk enable failed\n", "msm_ssphy_qmp_enable_clks");
          v21 = v4[61];
          if ( !v21 )
            goto LABEL_31;
          goto LABEL_26;
        }
      }
    }
    v21 = v4[61];
    if ( !v21 )
      goto LABEL_31;
LABEL_26:
    v22 = clk_prepare(v21);
    if ( !v22 )
    {
      v23 = clk_enable(v21);
      if ( !v23 )
        goto LABEL_31;
      v24 = v23;
      clk_unprepare(v21);
      v22 = v24;
    }
    if ( v22 < 0 )
      dev_err(*v4, "%s: cfg_ahb_clk enable failed\n", "msm_ssphy_qmp_enable_clks");
LABEL_31:
    if ( (clk_set_parent(v4[63], v4[64]) & 0x80000000) != 0 )
      dev_err(*v4, "%s: pipe_clk set_parent enable failed\n", "msm_ssphy_qmp_enable_clks");
    v25 = v4[62];
    result = clk_prepare(v25);
    if ( (_DWORD)result )
    {
      if ( (result & 0x80000000) == 0 )
      {
LABEL_38:
        v2 = 1;
        *((_BYTE *)v4 + 545) = 1;
        goto LABEL_39;
      }
    }
    else
    {
      result = clk_enable(v25);
      if ( !(_DWORD)result )
        goto LABEL_38;
      v26 = result;
      clk_unprepare(v25);
      result = v26;
      if ( (v26 & 0x80000000) == 0 )
        goto LABEL_38;
    }
    result = dev_err(*v4, "%s: pipe_clk enable failed\n", "msm_ssphy_qmp_enable_clks");
    goto LABEL_38;
  }
LABEL_39:
  if ( (v2 & 1) == 0 || (a2 & 1) != 0 )
    return result;
  v27 = v4[62];
  clk_disable(v27);
  clk_unprepare(v27);
  if ( (clk_set_parent(v4[63], v4[57]) & 0x80000000) != 0 )
  {
    dev_err(*v4, "%s: pipe_clk set_parent disable failed\n", "msm_ssphy_qmp_enable_clks");
    v28 = v4[61];
    if ( !v28 )
      goto LABEL_44;
    goto LABEL_43;
  }
  v28 = v4[61];
  if ( v28 )
  {
LABEL_43:
    clk_disable(v28);
    clk_unprepare(v28);
  }
LABEL_44:
  v29 = v4[59];
  clk_disable(v29);
  result = clk_unprepare(v29);
  v30 = v4[60];
  if ( v30 )
  {
    clk_disable(v4[60]);
    result = clk_unprepare(v30);
  }
  v31 = v4[58];
  if ( v31 )
  {
    clk_disable(v4[58]);
    result = clk_unprepare(v31);
  }
  v32 = v4[57];
  if ( v32 )
  {
    clk_disable(v4[57]);
    result = clk_unprepare(v32);
  }
  *((_BYTE *)v4 + 545) = 0;
  return result;
}
