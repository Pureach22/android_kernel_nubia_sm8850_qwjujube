__int64 __fastcall t2lm_handle_rx_teardown(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v29; // x2

  if ( a2 )
  {
    if ( a1 )
    {
      v10 = *(_QWORD *)(a1 + 1360);
      if ( v10 )
      {
        wlan_t2lm_clear_peer_negotiation(a2, a3, a4, a5, a6, a7, a8, a9, a10);
        wlan_mlo_dev_t2lm_notify_link_update(a1, v10 + 2244, v12, v13, v14, v15, v16, v17, v18, v19);
        wlan_send_tid_to_link_mapping(a1, v10 + 2244, v20, v21, v22, v23, v24, v25, v26, v27);
        return 0;
      }
      v29 = "%s: mlo dev ctx is null";
    }
    else
    {
      v29 = "%s: vdev is null";
    }
  }
  else
  {
    v29 = "%s: peer is null";
  }
  qdf_trace_msg(0x99u, 2u, v29, a3, a4, a5, a6, a7, a8, a9, a10, "t2lm_handle_rx_teardown");
  return 29;
}
