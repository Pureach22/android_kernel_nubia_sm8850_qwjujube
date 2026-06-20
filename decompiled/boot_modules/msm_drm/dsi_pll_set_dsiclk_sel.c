__int64 __fastcall dsi_pll_set_dsiclk_sel(_QWORD *a1, int a2)
{
  int v4; // w0
  __int64 result; // x0
  __int64 v6; // x8
  int v7; // w0
  __int64 v8; // x8
  int v9; // w0
  __int64 v10; // x8
  int v11; // w0

  v4 = readl_relaxed_16(a1[1] + 20LL);
  result = writel_relaxed_13(v4 & 0xFFFFFFFC | a2, a1[1] + 20LL);
  v6 = a1[15];
  if ( v6 )
  {
    v7 = readl_relaxed_16(*(_QWORD *)(v6 + 8) + 20LL);
    result = writel_relaxed_13(v7 & 0xFFFFFFFC | a2, *(_QWORD *)(a1[15] + 8LL) + 20LL);
  }
  v8 = a1[16];
  if ( v8 )
  {
    v9 = readl_relaxed_16(*(_QWORD *)(v8 + 8) + 20LL);
    result = writel_relaxed_13(v9 & 0xFFFFFFFC | a2, *(_QWORD *)(a1[16] + 8LL) + 20LL);
  }
  v10 = a1[17];
  if ( v10 )
  {
    v11 = readl_relaxed_16(*(_QWORD *)(v10 + 8) + 20LL);
    return writel_relaxed_13(v11 & 0xFFFFFFFC | a2, *(_QWORD *)(a1[17] + 8LL) + 20LL);
  }
  return result;
}
