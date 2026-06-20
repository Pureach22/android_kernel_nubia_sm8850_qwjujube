__int64 __fastcall dsi_pll_set_pclk_div(_QWORD *a1, int a2)
{
  int v4; // w0
  int v5; // w20
  __int64 result; // x0
  __int64 v7; // x8
  int v8; // w0
  __int64 v9; // x8
  int v10; // w0
  __int64 v11; // x8
  int v12; // w0

  v4 = readl_relaxed_16(a1[1] + 16LL);
  v5 = 16 * a2;
  result = writel_relaxed_13(v4 & 0xFFFFFF0F | v5, a1[1] + 16LL);
  v7 = a1[15];
  if ( v7 )
  {
    v8 = readl_relaxed_16(*(_QWORD *)(v7 + 8) + 16LL);
    result = writel_relaxed_13(v8 & 0xFFFFFF0F | v5, *(_QWORD *)(a1[15] + 8LL) + 16LL);
  }
  v9 = a1[16];
  if ( v9 )
  {
    v10 = readl_relaxed_16(*(_QWORD *)(v9 + 8) + 16LL);
    result = writel_relaxed_13(v10 & 0xFFFFFF0F | v5, *(_QWORD *)(a1[16] + 8LL) + 16LL);
  }
  v11 = a1[17];
  if ( v11 )
  {
    v12 = readl_relaxed_16(*(_QWORD *)(v11 + 8) + 16LL);
    return writel_relaxed_13(v12 & 0xFFFFFF0F | v5, *(_QWORD *)(a1[17] + 8LL) + 16LL);
  }
  return result;
}
