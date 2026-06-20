__int64 __fastcall dsi_pll_5nm_program_slave(__int64 a1, __int64 a2, double a3)
{
  unsigned int v3; // w8
  _QWORD *v5; // x20
  int v6; // w0
  int v7; // w21
  unsigned __int8 v8; // w22
  char v9; // w20
  int v10; // w8
  unsigned int v11; // w21
  _QWORD *v12; // x8
  _QWORD *v13; // x8
  unsigned int v14; // w22
  _QWORD *v15; // x8
  double v16; // d0
  int v17; // w0

  v3 = *(_DWORD *)(a1 + 100);
  if ( !v3 )
  {
    printk(&unk_2441E5, a2);
    return 0;
  }
  if ( v3 <= 3 )
  {
    v5 = (_QWORD *)pll_rsc_db[0];
    *(_QWORD *)(pll_rsc_db[0] + 8LL * (v3 - 1) + 120) = a1;
    if ( (a2 & 1) == 0 )
    {
      v6 = readl_relaxed_16(*(_QWORD *)(a1 + 8) + 36LL);
      writel_relaxed_13(v6 | 0x20u, *(_QWORD *)(a1 + 8) + 36LL);
      writel_relaxed_13(192, *(_QWORD *)a1 + 40LL);
      _const_udelay(1250);
      v7 = readl_relaxed_16(*v5 + 340LL);
      v8 = readl_relaxed_16(v5[1] + 16LL);
      v9 = readl_relaxed_16(v5[1] + 20LL);
      v10 = v7 == 1;
      if ( v7 == 2 )
        v10 = 2;
      if ( v7 == 3 )
        v11 = 3;
      else
        v11 = v10;
      writel_relaxed_13(v11, *(_QWORD *)a1 + 340LL);
      v12 = *(_QWORD **)(a1 + 120);
      if ( v12 )
        writel_relaxed_13(v11, *v12 + 340LL);
      v13 = *(_QWORD **)(a1 + 128);
      v14 = v8 >> 4;
      if ( v13 )
        writel_relaxed_13(v11, *v13 + 340LL);
      v15 = *(_QWORD **)(a1 + 136);
      if ( v15 )
        writel_relaxed_13(v11, *v15 + 340LL);
      dsi_pll_set_phy_post_div(a1, 1);
      dsi_pll_set_dsiclk_sel(a1, v9 & 3, v16);
      dsi_pll_set_pclk_div(a1, v14);
      writel_relaxed_13(34, *(_QWORD *)a1 + 608LL);
      __dsb(0xEu);
      writel_relaxed_13(1, *(_QWORD *)(a1 + 8) + 296LL);
      __dsb(0xEu);
      writel_relaxed_13(0, *(_QWORD *)(a1 + 8) + 296LL);
      __dsb(0xEu);
      writel_relaxed_13(4, *(_QWORD *)(a1 + 8) + 48LL);
      v17 = readl_relaxed_16(*(_QWORD *)(a1 + 8) + 20LL);
      writel_relaxed_13(v17 | 0x30u, *(_QWORD *)(a1 + 8) + 20LL);
    }
    return 0;
  }
  __break(0x5512u);
  return dsi_pll_set_pll_post_div(a1, a2, a3);
}
