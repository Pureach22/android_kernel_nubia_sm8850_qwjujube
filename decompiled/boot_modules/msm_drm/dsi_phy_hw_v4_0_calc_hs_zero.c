__int64 __fastcall dsi_phy_hw_v4_0_calc_hs_zero(__int64 a1, __int64 a2)
{
  return (__int64)(((a2 + a1 / 8 - 1) / (unsigned __int64)(unsigned int)a2 - 1) * a2) / (int)a2;
}
