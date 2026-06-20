__int64 __fastcall dp_setup_ipa_rx_refill_buf_ring(_QWORD *a1)
{
  unsigned int dp_soc_rxdma_refill_ring_size; // w0
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  if ( (wlan_cfg_is_ipa_enabled(a1[5]) & 1) == 0 )
    return 0;
  dp_soc_rxdma_refill_ring_size = wlan_cfg_get_dp_soc_rxdma_refill_ring_size(a1[5]);
  result = dp_srng_alloc(a1, (__int64)(a1 + 2318), 0xEu, dp_soc_rxdma_refill_ring_size, 0);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: dp_srng_alloc failed secondrx refill ring",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_setup_ipa_rx_refill_buf_ring",
      a1);
    return 16;
  }
  return result;
}
