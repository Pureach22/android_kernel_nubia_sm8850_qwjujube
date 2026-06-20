void __fastcall dsi_pll_5nm_set_byteclk_div(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  char *v3; // x13
  unsigned __int64 v4; // x12
  int v5; // w16
  char v6; // w20
  unsigned __int64 v8; // x14
  char *v9; // x9
  unsigned __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x10
  unsigned __int64 v13; // x21
  __int64 v14; // x11
  unsigned __int64 v15; // x10
  char *v16; // x8
  unsigned int v17; // w22
  unsigned int v18; // w23
  int v19; // w4
  double v20; // d0

  v2 = *(_QWORD *)(a1 + 64);
  v3 = (char *)&pll_5nm_cphy_lb;
  v4 = 8 * v2;
  v5 = *(_DWORD *)(a1 + 176);
  v6 = a2;
  v8 = 7 * v2;
  v9 = (char *)&pll_5nm_dphy_hb;
  v10 = 0;
  if ( v8 >= 0x59682F01 )
    v3 = (char *)&pll_5nm_cphy_hb;
  v11 = 19;
  if ( v4 < 0x59682F01 )
    v9 = (char *)&pll_5nm_dphy_lb;
  if ( v5 )
  {
    v11 = 11;
    v9 = v3;
  }
  v12 = 3 * v11;
  if ( v5 )
    v13 = v8;
  else
    v13 = v4;
  v14 = 8 * v12;
  if ( v5 )
    v15 = 264;
  else
    v15 = 456;
  do
  {
    if ( v15 <= v10 )
      goto LABEL_27;
    if ( *(_QWORD *)&v9[v10] <= v13 )
    {
      if ( v15 <= v10 + 8 )
        goto LABEL_27;
      if ( v13 <= *(_QWORD *)&v9[v10 + 8] )
      {
        if ( v15 <= v10 + 16 || v15 < v10 + 20 )
        {
LABEL_27:
          __break(1u);
          dsi_pll_5nm_set_pclk_div(a1, a2);
          return;
        }
        v16 = &v9[v10];
        v17 = *((_DWORD *)v16 + 4);
        v18 = *((_DWORD *)v16 + 5);
        if ( a1 )
          goto LABEL_23;
LABEL_21:
        v19 = -1;
        goto LABEL_24;
      }
    }
    v10 += 24LL;
  }
  while ( v14 != v10 );
  v17 = 0;
  v18 = 0;
  if ( !a1 )
    goto LABEL_21;
LABEL_23:
  v19 = *(_DWORD *)(a1 + 100);
LABEL_24:
  v20 = _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dsi-debug]: DSI_PLL_%d: bit clk rate: %llu, pll_post_div: %d, phy_post_div: %d\n",
          v19,
          v13,
          v17,
          v18);
  if ( (v6 & 1) != 0 )
  {
    dsi_pll_set_pll_post_div(a1, v17, v20);
    dsi_pll_set_phy_post_div(a1, v18);
  }
  *(_QWORD *)(a1 + 56) = v13 * v17 * v18;
}
