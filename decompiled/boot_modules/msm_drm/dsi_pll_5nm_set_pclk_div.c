void __fastcall dsi_pll_5nm_set_pclk_div(__int64 a1, char a2)
{
  unsigned __int64 v4; // x21
  __int64 v5; // x9
  unsigned __int64 v6; // x21
  char v7; // w0
  int v8; // w5
  unsigned int v9; // w6
  int v10; // w8
  unsigned __int64 v11; // t2
  unsigned int v12; // w9
  unsigned int v13; // w8
  int v14; // w7
  unsigned __int64 v15; // x23
  unsigned __int64 v16; // x8
  unsigned int v17; // w5
  unsigned int v18; // w6
  int v19; // w7
  unsigned int v20; // w9
  int v21; // w4
  unsigned int v22; // w21
  unsigned int v23; // w22
  int v24; // w4
  unsigned __int64 v25; // x5
  int v26; // w4
  double v27; // d0

  v4 = *(_QWORD *)(a1 + 56) >> readl_relaxed_16(*(_QWORD *)a1 + 340LL);
  if ( *(_DWORD *)(a1 + 176) )
  {
    v5 = (2 * v4 * (unsigned __int128)0x2492492492492493uLL) >> 64;
    v6 = v5 + ((2 * v4 - v5) >> 1);
    v7 = readl_relaxed_16(*(_QWORD *)(a1 + 8) + 16LL);
    v8 = *(_DWORD *)(a1 + 164);
    v9 = *(_DWORD *)(a1 + 168);
    HIDWORD(v11) = v8 - 16;
    LODWORD(v11) = v8 - 16;
    v10 = v11 >> 1;
    if ( v10 > 3 )
    {
      if ( v10 == 7 )
      {
        if ( v9 == 1 )
          v13 = 15;
        else
          v13 = 35;
        if ( v9 == 1 )
          v14 = 4;
        else
          v14 = 16;
        v15 = v6 >> 2;
        if ( !a1 )
          goto LABEL_31;
        goto LABEL_23;
      }
      if ( v10 == 4 && v9 == 2 )
      {
        v13 = 3;
        v14 = 2;
        v15 = v6 >> 2;
        if ( !a1 )
          goto LABEL_31;
        goto LABEL_23;
      }
    }
    else if ( v10 )
    {
      if ( v10 == 1 )
      {
        v12 = v9 - 1;
        if ( v9 - 1 < 3 )
        {
          v13 = dword_28FB40[v12];
          v14 = dword_28FB4C[v12];
          v15 = v6 >> 2;
          if ( !a1 )
            goto LABEL_31;
          goto LABEL_23;
        }
      }
    }
    else if ( v9 == 3 )
    {
      v13 = 7;
      v14 = 3;
      v15 = v6 >> 2;
      if ( !a1 )
        goto LABEL_31;
      goto LABEL_23;
    }
    v13 = 1;
    v14 = 1;
    v15 = v6 >> 2;
    if ( !a1 )
    {
LABEL_31:
      v21 = -1;
      goto LABEL_32;
    }
LABEL_23:
    v21 = *(_DWORD *)(a1 + 100);
LABEL_32:
    v22 = (((unsigned __int16)(v8 * (v7 & 0xFu) % v13 * v14) / (unsigned int)(unsigned __int16)v13
          + v8 * (v7 & 0xFu) / v13 * v14) >> 3)
        / v9;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_PLL_%d: bpp: %d, lanes: %d, m_val: %u, n_val: %u, phy_post_div: %u pclk_div: %u\n",
      v21,
      v8,
      v9,
      v14,
      v13,
      v7 & 0xF,
      v22);
    v23 = 3;
    goto LABEL_45;
  }
  v16 = v4 / (readl_relaxed_16(*(_QWORD *)(a1 + 8) + 16LL) & 0xFuLL);
  v17 = *(_DWORD *)(a1 + 164);
  v18 = *(_DWORD *)(a1 + 168);
  if ( v17 == 16 )
  {
    if ( v18 == 3 )
    {
      v20 = 8;
      v19 = 3;
      v15 = v16 >> 1;
      if ( !a1 )
        goto LABEL_43;
      goto LABEL_41;
    }
    goto LABEL_40;
  }
  if ( v17 == 18 )
  {
    if ( v18 == 2 )
    {
      v20 = 9;
      v19 = 2;
      v15 = v16 >> 1;
      if ( a1 )
        goto LABEL_41;
      goto LABEL_43;
    }
    if ( v18 == 4 )
    {
      v20 = 9;
      v19 = 4;
      v15 = v16 >> 1;
      if ( !a1 )
        goto LABEL_43;
      goto LABEL_41;
    }
LABEL_40:
    v20 = 1;
    v19 = 1;
    v15 = v16 >> 1;
    if ( a1 )
      goto LABEL_41;
LABEL_43:
    v24 = -1;
    goto LABEL_44;
  }
  if ( v17 != 30 || v18 != 4 )
    goto LABEL_40;
  v19 = 2;
  v20 = 3;
  v15 = v16 >> 1;
  if ( !a1 )
    goto LABEL_43;
LABEL_41:
  v24 = *(_DWORD *)(a1 + 100);
LABEL_44:
  v22 = (((unsigned __int8)(v17 % v20 * v19) / v20 + v17 / v20 * v19) >> 1) / v18;
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: DSI_PLL_%d: bpp: %d, lanes: %d, m_val: %u, n_val: %u, pclk_div: %u\n",
    v24,
    v17,
    v18,
    v19,
    v20,
    v22);
  v23 = 1;
LABEL_45:
  v25 = v15 / v22;
  *(_QWORD *)(a1 + 72) = v25;
  if ( a1 )
    v26 = *(_DWORD *)(a1 + 100);
  else
    v26 = -1;
  v27 = _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dsi-debug]: DSI_PLL_%d: pclk rate: %llu, dsiclk_sel: %d, pclk_div: %d\n",
          v26,
          v25,
          v23,
          v22);
  if ( (a2 & 1) != 0 )
  {
    dsi_pll_set_dsiclk_sel(a1, v23, v27);
    dsi_pll_set_pclk_div(a1, v22);
  }
}
