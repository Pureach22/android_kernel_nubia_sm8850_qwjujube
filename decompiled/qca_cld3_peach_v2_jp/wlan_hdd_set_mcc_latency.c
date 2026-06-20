__int64 __fastcall wlan_hdd_set_mcc_latency(
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
  __int64 *v10; // x20
  int concurrency_mode; // w0
  const char *v14; // x2
  unsigned int v15; // w1
  unsigned int operating_chan_freq; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int8 v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w1

  if ( !a1 )
  {
    v14 = "%s: Invalid adapter";
LABEL_8:
    v15 = 2;
    return qdf_trace_msg(0x33u, v15, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_set_mcc_latency");
  }
  v10 = *(__int64 **)(a1 + 24);
  if ( !v10 )
  {
    v14 = "%s: HDD context is null";
    goto LABEL_8;
  }
  concurrency_mode = policy_mgr_get_concurrency_mode(*v10);
  if ( (~concurrency_mode & 5) != 0 && (concurrency_mode & 9) != 9 )
  {
    v14 = "%s: MCC is not active. Exit w/o setting latency";
    v15 = 4;
    return qdf_trace_msg(0x33u, v15, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_set_mcc_latency");
  }
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: STA & P2P are both enabled",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_set_mcc_latency");
  operating_chan_freq = hdd_get_operating_chan_freq((__int64)v10, *(_DWORD *)(a1 + 40));
  if ( operating_chan_freq )
  {
    v26 = wlan_reg_freq_to_chan(v10[1], operating_chan_freq, v18, v19, v20, v21, v22, v23, v24, v25);
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: First connection channel No.:%d and quota:%dms",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "set_first_connection_operating_channel",
      v26,
      a2);
    v43 = v26 | (a2 << 8);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s:  First adapter operating channel is invalid",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "set_first_connection_operating_channel");
    v43 = a2;
  }
  return wlan_hdd_send_mcc_latency(a1, v43, v35, v36, v37, v38, v39, v40, v41, v42);
}
