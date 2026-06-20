__int64 __fastcall dsi_pll_3nm_program_slave(__int64 a1, __int64 a2, double a3)
{
  unsigned int v3; // w8
  _QWORD *v5; // x20
  int v6; // w0
  double v7; // d0
  int v8; // w21
  double v9; // d0
  unsigned __int8 v10; // w22
  double v11; // d0
  char v12; // w20
  int v13; // w8
  unsigned int v14; // w21
  _QWORD *v15; // x8
  _QWORD *v16; // x8
  unsigned int v17; // w22
  _QWORD *v18; // x8
  double v19; // d0
  int v20; // w0

  v3 = *(_DWORD *)(a1 + 100);
  if ( !v3 )
  {
    printk(&unk_2441E5, a2);
    return 0;
  }
  if ( v3 <= 3 )
  {
    v5 = (_QWORD *)pll_rsc_db_1[0];
    *(_QWORD *)(pll_rsc_db_1[0] + 8LL * (v3 - 1) + 120) = a1;
    if ( (a2 & 1) == 0 )
    {
      v6 = readl_relaxed_18(*(_QWORD *)(a1 + 8) + 36LL, a3);
      writel_relaxed_15(v6 | 0x20u, *(_QWORD *)(a1 + 8) + 36LL);
      writel_relaxed_15(192, *(_QWORD *)a1 + 40LL);
      _const_udelay(1250);
      v8 = readl_relaxed_18(*v5 + 340LL, v7);
      v10 = readl_relaxed_18(v5[1] + 16LL, v9);
      v12 = readl_relaxed_18(v5[1] + 20LL, v11);
      v13 = v8 == 1;
      if ( v8 == 2 )
        v13 = 2;
      if ( v8 == 3 )
        v14 = 3;
      else
        v14 = v13;
      writel_relaxed_15(v14, *(_QWORD *)a1 + 340LL);
      v15 = *(_QWORD **)(a1 + 120);
      if ( v15 )
        writel_relaxed_15(v14, *v15 + 340LL);
      v16 = *(_QWORD **)(a1 + 128);
      v17 = v10 >> 4;
      if ( v16 )
        writel_relaxed_15(v14, *v16 + 340LL);
      v18 = *(_QWORD **)(a1 + 136);
      if ( v18 )
        writel_relaxed_15(v14, *v18 + 340LL);
      dsi_pll_set_phy_post_div_1(a1, 1);
      dsi_pll_set_dsiclk_sel_1(a1, v12 & 3);
      dsi_pll_set_pclk_div_1(a1, v17);
      writel_relaxed_15(34, *(_QWORD *)a1 + 608LL);
      __dsb(0xEu);
      writel_relaxed_15(1, *(_QWORD *)(a1 + 8) + 296LL);
      __dsb(0xEu);
      writel_relaxed_15(0, *(_QWORD *)(a1 + 8) + 296LL);
      __dsb(0xEu);
      writel_relaxed_15(4, *(_QWORD *)(a1 + 8) + 48LL);
      v20 = readl_relaxed_18(*(_QWORD *)(a1 + 8) + 20LL, v19);
      writel_relaxed_15(v20 | 0x30u, *(_QWORD *)(a1 + 8) + 20LL);
    }
    return 0;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))dsi_pll_set_phy_post_div_1)();
}
