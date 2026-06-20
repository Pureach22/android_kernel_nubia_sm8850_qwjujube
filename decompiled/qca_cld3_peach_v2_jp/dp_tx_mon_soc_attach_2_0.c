__int64 __fastcall dp_tx_mon_soc_attach_2_0(_QWORD *a1)
{
  __int64 v2; // x21
  unsigned int dp_soc_tx_mon_buf_ring_size; // w20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v2 = a1[2507];
  dp_soc_tx_mon_buf_ring_size = wlan_cfg_get_dp_soc_tx_mon_buf_ring_size(a1[5]);
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: %s:%d tx mon buf entries: %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "dp_tx_mon_soc_attach_2_0",
    "dp_tx_mon_soc_attach_2_0",
    2682,
    dp_soc_tx_mon_buf_ring_size);
  return dp_srng_alloc(a1, v2 + 456, 0x18u, dp_soc_tx_mon_buf_ring_size, 0);
}
