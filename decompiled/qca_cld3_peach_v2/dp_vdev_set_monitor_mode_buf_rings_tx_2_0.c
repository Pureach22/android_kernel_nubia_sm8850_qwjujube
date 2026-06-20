__int64 __fastcall dp_vdev_set_monitor_mode_buf_rings_tx_2_0(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x19
  __int64 v11; // x21
  int dp_soc_tx_mon_buf_ring_size; // w0
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  __int64 result; // x0
  unsigned int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v10 = *(__int64 **)(a1 + 8);
  v11 = v10[2514];
  if ( !v11 )
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: DP MON SOC is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_vdev_set_monitor_mode_buf_rings_tx_2_0");
    return 16;
  }
  dp_soc_tx_mon_buf_ring_size = wlan_cfg_get_dp_soc_tx_mon_buf_ring_size(v10[5]);
  hal_set_low_threshold(*(_QWORD *)(v11 + 456), dp_soc_tx_mon_buf_ring_size >> 2);
  v14 = htt_srng_setup(v10[6], 0, *(_QWORD *)(v11 + 456), 24);
  if ( v14 )
  {
    v23 = v14;
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: Failed to send htt srng setup message for Tx mon buf ring",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_vdev_set_monitor_mode_buf_rings_tx_2_0");
    return v23;
  }
  v25 = *(unsigned __int16 *)(v11 + 842);
  if ( v25 >= a2 )
    return 0;
  result = dp_tx_mon_buffers_alloc(v10, a2 - v25);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %pK: Tx mon buffers allocation failed",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "dp_vdev_set_monitor_mode_buf_rings_tx_2_0",
      v10);
    return 16;
  }
  return result;
}
