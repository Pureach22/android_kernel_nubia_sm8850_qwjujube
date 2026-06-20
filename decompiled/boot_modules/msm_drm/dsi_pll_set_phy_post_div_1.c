__int64 __fastcall dsi_pll_set_phy_post_div_1(_QWORD *a1, int a2, double a3)
{
  int v5; // w0
  __int64 result; // x0
  double v7; // d0
  int v8; // w0
  int v9; // w0
  int v10; // w0

  v5 = readl_relaxed_18(a1[1] + 16LL, a3);
  result = writel_relaxed_15(v5 & 0xFFFFFFF0 | a2, a1[1] + 16LL);
  if ( a1[15] )
  {
    v8 = readl_relaxed_18(a1[1] + 16LL, v7);
    result = writel_relaxed_15(v8 & 0xFFFFFFF0 | 1, *(_QWORD *)(a1[15] + 8LL) + 16LL);
  }
  if ( a1[16] )
  {
    v9 = readl_relaxed_18(a1[1] + 16LL, v7);
    result = writel_relaxed_15(v9 & 0xFFFFFFF0 | 1, *(_QWORD *)(a1[16] + 8LL) + 16LL);
  }
  if ( a1[17] )
  {
    v10 = readl_relaxed_18(a1[1] + 16LL, v7);
    return writel_relaxed_15(v10 & 0xFFFFFFF0 | 1, *(_QWORD *)(a1[17] + 8LL) + 16LL);
  }
  return result;
}
