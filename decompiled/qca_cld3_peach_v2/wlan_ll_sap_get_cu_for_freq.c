__int64 __fastcall wlan_ll_sap_get_cu_for_freq(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *channel_status; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w8
  unsigned int v21; // w5
  unsigned int v22; // w9
  unsigned int v23; // w19
  const char *v24; // x2
  unsigned int v25; // w1

  channel_status = ucfg_mc_cp_stats_get_channel_status(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !channel_status )
  {
    v24 = "%s: Stats not found for freq %d";
    v25 = 2;
LABEL_8:
    qdf_trace_msg(0xA1u, v25, v24, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_ll_sap_get_cu_for_freq", a2);
    return 0;
  }
  v20 = channel_status[3];
  if ( !v20 )
  {
    v24 = "%s: Stats not valid for freq %d as cc is 0";
    v25 = 8;
    goto LABEL_8;
  }
  v21 = channel_status[2];
  v22 = channel_status[7] + channel_status[9];
  if ( v21 <= v22 )
    v22 = 0;
  v23 = 100 * (v21 - v22) / v20;
  qdf_trace_msg(
    0xA1u,
    8u,
    "%s: cu: %u, rx_cc %u, tx_fc %u, bss_rx_cc %u cc %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_ll_sap_get_cu_for_freq",
    v23,
    channel_status[3]);
  return v23;
}
