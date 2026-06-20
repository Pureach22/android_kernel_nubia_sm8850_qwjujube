__int64 __fastcall dsi_phy_hw_v4_0_reset_clk_en_sel(__int64 a1)
{
  int v2; // w0
  __int64 result; // x0

  v2 = readl_relaxed_13((unsigned int *)(*(_QWORD *)a1 + 20LL));
  result = writel_relaxed_10(v2 & 0xFFFFFFEF, (unsigned int *)(*(_QWORD *)a1 + 20LL));
  __dsb(0xEu);
  return result;
}
