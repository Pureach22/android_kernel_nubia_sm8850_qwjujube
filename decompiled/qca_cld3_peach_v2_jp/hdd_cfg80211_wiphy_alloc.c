__int64 __fastcall hdd_cfg80211_wiphy_alloc(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8

  qdf_trace_msg(0x33u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "hdd_cfg80211_wiphy_alloc");
  v8 = wiphy_new_nm(&wlan_hdd_cfg80211_ops, 8880, 0);
  if ( v8 )
  {
    v17 = v8;
    *(_QWORD *)(v17 + 1560) = v17;
    return v8 + 1536;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to allocate wiphy!",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "hdd_cfg80211_wiphy_alloc");
    return 0;
  }
}
