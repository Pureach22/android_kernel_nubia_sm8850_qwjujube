__int64 __fastcall wlan_hdd_cfg80211_register(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_cfg80211_register");
  v10 = wiphy_register(a1);
  if ( (v10 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wiphy register failed %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_hdd_cfg80211_register",
      v10);
    return 4294967291LL;
  }
  else
  {
    qdf_trace_msg(0x33u, 8u, "%s: exit", v11, v12, v13, v14, v15, v16, v17, v18, "wlan_hdd_cfg80211_register");
    return 0;
  }
}
