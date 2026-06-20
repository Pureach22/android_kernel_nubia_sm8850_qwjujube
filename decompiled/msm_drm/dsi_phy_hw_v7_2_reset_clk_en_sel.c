_BYTE *__fastcall dsi_phy_hw_v7_2_reset_clk_en_sel(_BYTE *result)
{
  _BYTE *v1; // x19
  int v2; // w0

  if ( (result[32] & 1) == 0 )
  {
    v1 = result;
    v2 = readl_relaxed_15((unsigned int *)(*(_QWORD *)result + 20LL));
    result = (_BYTE *)writel_relaxed_12(v2 & 0xFFFFFFEF, (unsigned int *)(*(_QWORD *)v1 + 20LL));
    __dsb(0xEu);
  }
  return result;
}
