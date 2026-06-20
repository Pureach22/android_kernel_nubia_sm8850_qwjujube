__int64 __fastcall dsi_pll_set_phy_post_div(_QWORD *a1, int a2)
{
  int v4; // w0
  __int64 result; // x0
  int v6; // w0
  int v7; // w0
  int v8; // w0

  v4 = readl_relaxed_16(a1[1] + 16LL);
  result = writel_relaxed_13(v4 & 0xFFFFFFF0 | a2, a1[1] + 16LL);
  if ( a1[15] )
  {
    v6 = readl_relaxed_16(a1[1] + 16LL);
    result = writel_relaxed_13(v6 & 0xFFFFFFF0 | 1, *(_QWORD *)(a1[15] + 8LL) + 16LL);
  }
  if ( a1[16] )
  {
    v7 = readl_relaxed_16(a1[1] + 16LL);
    result = writel_relaxed_13(v7 & 0xFFFFFFF0 | 1, *(_QWORD *)(a1[16] + 8LL) + 16LL);
  }
  if ( a1[17] )
  {
    v8 = readl_relaxed_16(a1[1] + 16LL);
    return writel_relaxed_13(v8 & 0xFFFFFFF0 | 1, *(_QWORD *)(a1[17] + 8LL) + 16LL);
  }
  return result;
}
