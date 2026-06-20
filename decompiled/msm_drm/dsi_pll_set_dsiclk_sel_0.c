__int64 __fastcall dsi_pll_set_dsiclk_sel_0(_QWORD *a1, int a2, double a3)
{
  int v5; // w0
  __int64 result; // x0
  double v7; // d0
  __int64 v8; // x8
  int v9; // w0
  __int64 v10; // x8
  int v11; // w0
  __int64 v12; // x8
  int v13; // w0

  v5 = readl_relaxed_17(a1[1] + 20LL, a3);
  result = writel_relaxed_14(v5 & 0xFFFFFFFC | a2, a1[1] + 20LL);
  v8 = a1[15];
  if ( v8 )
  {
    v9 = readl_relaxed_17(*(_QWORD *)(v8 + 8) + 20LL, v7);
    result = writel_relaxed_14(v9 & 0xFFFFFFFC | a2, *(_QWORD *)(a1[15] + 8LL) + 20LL);
  }
  v10 = a1[16];
  if ( v10 )
  {
    v11 = readl_relaxed_17(*(_QWORD *)(v10 + 8) + 20LL, v7);
    result = writel_relaxed_14(v11 & 0xFFFFFFFC | a2, *(_QWORD *)(a1[16] + 8LL) + 20LL);
  }
  v12 = a1[17];
  if ( v12 )
  {
    v13 = readl_relaxed_17(*(_QWORD *)(v12 + 8) + 20LL, v7);
    return writel_relaxed_14(v13 & 0xFFFFFFFC | a2, *(_QWORD *)(a1[17] + 8LL) + 20LL);
  }
  return result;
}
