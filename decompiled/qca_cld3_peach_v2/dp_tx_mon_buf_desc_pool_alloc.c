__int64 __fastcall dp_tx_mon_buf_desc_pool_alloc(__int64 a1)
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v2 = *(_QWORD *)(a1 + 20112);
  dp_soc_tx_mon_buf_ring_size = wlan_cfg_get_dp_soc_tx_mon_buf_ring_size(*(_QWORD *)(a1 + 40));
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: %s:%d tx mon buf desc pool entries: %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "dp_tx_mon_buf_desc_pool_alloc",
    "dp_tx_mon_buf_desc_pool_alloc",
    449,
    dp_soc_tx_mon_buf_ring_size);
  return dp_mon_desc_pool_alloc(a1, 0xDu, dp_soc_tx_mon_buf_ring_size, v2 + 696, v12, v13, v14, v15, v16, v17, v18, v19);
}
