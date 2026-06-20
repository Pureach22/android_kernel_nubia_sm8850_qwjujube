__int64 **__fastcall dp_rx_oor_handle(__int64 a1, __int64 a2, unsigned __int16 a3, __int64 a4)
{
  char special_frame_cfg; // w22
  __int64 **result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22

  special_frame_cfg = wlan_cfg_get_special_frame_cfg(*(_QWORD *)(a1 + 40));
  result = (__int64 **)dp_peer_get_ref_by_id_2(a1, a3);
  if ( !result )
  {
LABEL_8:
    v27 = jiffies;
    if ( dp_rx_oor_handle___last_ticks - jiffies + 125 < 0 )
    {
      result = (__int64 **)qdf_trace_msg(
                             0x45u,
                             5u,
                             "%s: peer not found",
                             v10,
                             v11,
                             v12,
                             v13,
                             v14,
                             v15,
                             v16,
                             v17,
                             "dp_rx_oor_handle");
      dp_rx_oor_handle___last_ticks = v27;
    }
    if ( !a1 )
      goto LABEL_12;
    goto LABEL_11;
  }
  if ( !*result )
  {
    result = (__int64 **)dp_peer_unref_delete((__int64)result, 4u, v10, v11, v12, v13, v14, v15, v16, v17);
    goto LABEL_8;
  }
  v18 = (__int64)result;
  if ( (dp_rx_deliver_special_frame(a1, *result, a2, special_frame_cfg, a4) & 1) != 0 )
  {
    if ( a1 )
      ++*(_DWORD *)(a1 + 14084);
    return (__int64 **)dp_txrx_peer_unref_delete(v18, 4u, v19, v20, v21, v22, v23, v24, v25, v26);
  }
  result = (__int64 **)dp_txrx_peer_unref_delete(v18, 4u, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( a1 )
LABEL_11:
    ++*(_DWORD *)(a1 + 14080);
LABEL_12:
  if ( a2 )
    return (__int64 **)_qdf_nbuf_free(a2);
  return result;
}
