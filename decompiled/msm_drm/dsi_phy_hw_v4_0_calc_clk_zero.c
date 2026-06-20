__int64 __fastcall dsi_phy_hw_v4_0_calc_clk_zero(__int64 a1, __int64 a2)
{
  return (unsigned int)((__int64)((a2 + a1 / 8 - 1) / (unsigned __int64)(unsigned int)a2 * a2) / (int)a2) - 1;
}
