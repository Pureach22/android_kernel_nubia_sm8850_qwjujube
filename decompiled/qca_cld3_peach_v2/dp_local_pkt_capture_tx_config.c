__int64 __fastcall dp_local_pkt_capture_tx_config(__int64 a1)
{
  unsigned __int16 dp_soc_tx_mon_buf_ring_size; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19

  dp_soc_tx_mon_buf_ring_size = wlan_cfg_get_dp_soc_tx_mon_buf_ring_size(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL));
  result = dp_vdev_set_monitor_mode_buf_rings_tx_2_0(a1, dp_soc_tx_mon_buf_ring_size, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( (_DWORD)result )
  {
    v20 = result;
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: Tx monitor buffer allocation failed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_local_pkt_capture_tx_config");
    return v20;
  }
  return result;
}
