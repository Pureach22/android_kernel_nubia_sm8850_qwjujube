__int64 __fastcall wlan_dp_lapb_display_stats(
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
  unsigned int *v9; // x20
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v9 = (unsigned int *)(a1 + 0x4000);
  qdf_trace_msg(0x45u, 5u, "%s: LAPB stats", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dp_lapb_display_stats");
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Packet received: %u",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_dp_lapb_display_stats",
    v9[894]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Timer expired: %u",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_dp_lapb_display_stats",
    v9[895]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: App ind received: %u",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_dp_lapb_display_stats",
    v9[896]);
  return 0;
}
