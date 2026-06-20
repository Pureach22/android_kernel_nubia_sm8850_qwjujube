__int64 __fastcall dsi_phy_hw_v3_0_calc_clk_trail_rec_min(__int64 a1, __int64 a2, __int64 a3)
{
  return (unsigned int)((__int64)((a3 + (a2 + a1) / 8 - 1) / (unsigned __int64)(unsigned int)a3 * a3) / (int)a3) - 1;
}
