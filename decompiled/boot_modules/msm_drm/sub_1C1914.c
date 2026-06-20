__int64 __fastcall sub_1C1914(long double a1, long double a2, long double a3, long double a4)
{
  float64x2_t v4; // q26
  double v5; // d28

  return dsi_phy_hw_v7_2_lane_reset(a1, a2, a3, a4, vmulxd_lane_f64(v5, v4, 1));
}
