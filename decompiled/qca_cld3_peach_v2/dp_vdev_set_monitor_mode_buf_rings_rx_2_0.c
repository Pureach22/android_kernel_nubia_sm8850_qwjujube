__int64 __fastcall dp_vdev_set_monitor_mode_buf_rings_rx_2_0(
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
  __int64 *v9; // x21
  __int64 v10; // x20
  int dp_soc_rx_mon_buf_ring_size; // w19
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  __int64 result; // x0

  v9 = *(__int64 **)(a1 + 8);
  v10 = v9[2514];
  if ( v10 )
  {
    dp_soc_rx_mon_buf_ring_size = wlan_cfg_get_dp_soc_rx_mon_buf_ring_size(v9[5]);
    hal_set_low_threshold(v9[60], 256);
    v12 = htt_srng_setup(v9[6], 0, v9[60], 16);
    if ( v12 )
    {
      v21 = v12;
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: Failed to send htt srng setup message for Rx mon buf ring",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "dp_vdev_set_monitor_mode_buf_rings_rx_2_0");
      return v21;
    }
    else
    {
      result = 0;
      if ( dp_soc_rx_mon_buf_ring_size > *(unsigned __int16 *)(v10 + 840) )
        *(_WORD *)(v10 + 840) = dp_soc_rx_mon_buf_ring_size;
    }
  }
  else
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: DP MON SOC is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_vdev_set_monitor_mode_buf_rings_rx_2_0");
    return 16;
  }
  return result;
}
