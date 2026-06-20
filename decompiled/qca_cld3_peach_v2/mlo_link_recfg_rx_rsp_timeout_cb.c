__int64 __fastcall mlo_link_recfg_rx_rsp_timeout_cb(
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
  __int64 result; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: Failed to get the Link Reconfig RX response",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "mlo_link_recfg_rx_rsp_timeout_cb");
  v11 = *(_QWORD *)(a1 + 8);
  if ( v11 )
  {
    qdf_mutex_acquire(*(_QWORD *)(v11 + 3888) + 760LL);
    wlan_sm_dispatch(*(_QWORD *)(*(_QWORD *)(v11 + 3888) + 824LL), 0x12u, 0, 0, v12, v13, v14, v15, v16, v17, v18, v19);
    return qdf_mutex_release(*(_QWORD *)(v11 + 3888) + 760LL);
  }
  return result;
}
