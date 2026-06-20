bool __fastcall dsi_phy_hw_v4_0_is_lanes_in_ulps(int a1, int a2)
{
  return (a2 & a1) == 0;
}
