__int64 __fastcall dsi_pll_set_pclk_div_0(_QWORD *a1, int a2, double a3)
{
  int v5; // w0
  int v6; // w20
  __int64 result; // x0
  double v8; // d0
  __int64 v9; // x8
  int v10; // w0
  __int64 v11; // x8
  int v12; // w0
  __int64 v13; // x8
  int v14; // w0

  v5 = readl_relaxed_17(a1[1] + 16LL, a3);
  v6 = 16 * a2;
  result = writel_relaxed_14(v5 & 0xFFFFFF0F | v6, a1[1] + 16LL);
  v9 = a1[15];
  if ( v9 )
  {
    v10 = readl_relaxed_17(*(_QWORD *)(v9 + 8) + 16LL, v8);
    result = writel_relaxed_14(v10 & 0xFFFFFF0F | v6, *(_QWORD *)(a1[15] + 8LL) + 16LL);
  }
  v11 = a1[16];
  if ( v11 )
  {
    v12 = readl_relaxed_17(*(_QWORD *)(v11 + 8) + 16LL, v8);
    result = writel_relaxed_14(v12 & 0xFFFFFF0F | v6, *(_QWORD *)(a1[16] + 8LL) + 16LL);
  }
  v13 = a1[17];
  if ( v13 )
  {
    v14 = readl_relaxed_17(*(_QWORD *)(v13 + 8) + 16LL, v8);
    return writel_relaxed_14(v14 & 0xFFFFFF0F | v6, *(_QWORD *)(a1[17] + 8LL) + 16LL);
  }
  return result;
}
