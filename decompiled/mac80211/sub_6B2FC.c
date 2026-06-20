__int64 __fastcall sub_6B2FC(long double a1, long double a2, long double a3, long double a4)
{
  const double *v4; // x11
  float64x1x2_t v6; // 0:kr00_16.16

  v6 = vld2_dup_f64(v4);
  *(double *)&a3 = v6.val[0];
  *(double *)&a4 = v6.val[1];
  return ieee80211_rate_control_unregister(a1, a2, a3, a4);
}
