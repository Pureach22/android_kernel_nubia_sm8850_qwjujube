__int64 __fastcall dsi_phy_hw_v7_2_set_continuous_clk(__int64 a1, char a2)
{
  char v4; // w0
  char v5; // w21
  int v6; // w10
  int v7; // w8
  __int64 result; // x0
  int v9; // w10
  int v10; // w8

  v4 = readl_relaxed_15((unsigned int *)(*(_QWORD *)a1 + 24LL));
  __dsb(0xFu);
  v5 = v4;
  v6 = readl_relaxed_15((unsigned int *)(*(_QWORD *)a1 + 164LL)) & 0xFFFFFF9F;
  if ( (a2 & 1) != 0 )
    v7 = 96;
  else
    v7 = 0;
  result = writel_relaxed_12(v6 | (unsigned int)v7, (unsigned int *)(*(_QWORD *)a1 + 164LL));
  if ( (v5 & 0x20) != 0 )
  {
    v9 = readl_relaxed_15((unsigned int *)(*(_QWORD *)a1 + 436LL)) & 0xFFFFFFFB;
    if ( (a2 & 1) != 0 )
      v10 = 4;
    else
      v10 = 0;
    result = writel_relaxed_12(v9 | (unsigned int)v10, (unsigned int *)(*(_QWORD *)a1 + 436LL));
  }
  __dsb(0xEu);
  return result;
}
