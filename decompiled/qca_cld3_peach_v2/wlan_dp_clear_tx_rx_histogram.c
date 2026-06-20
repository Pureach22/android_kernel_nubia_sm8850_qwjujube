void *__fastcall wlan_dp_clear_tx_rx_histogram(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  void *result; // x0

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
    return (void *)qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: Unable to get DP context",
                     v2,
                     v3,
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     "wlan_dp_clear_tx_rx_histogram");
  v10 = comp_private_obj;
  result = *(void **)(comp_private_obj + 1144);
  *(_WORD *)(v10 + 1136) = 0;
  if ( result )
    return qdf_mem_set(result, 0x1400u, 0);
  return result;
}
