__int64 __fastcall hdd_wlan_clear_stats(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w0
  _QWORD *context; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 (**v31)(void); // x8
  __int64 (*v32)(void); // x8
  unsigned int v33; // w20

  v12 = qdf_trace_msg(
          0x33u,
          8u,
          "%s: stats_id %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_wlan_clear_stats",
          (unsigned int)a2);
  if ( a2 <= 3 )
  {
    if ( !a2 )
    {
      ucfg_dp_clear_net_dev_stats(*(_QWORD *)(a1 + 32));
      memset((void *)(*(_QWORD *)(a1 + 52832) + 2704LL), 0, 0x790u);
      v21 = 0;
      return qdf_status_to_os_return(v21);
    }
    if ( a2 == 2 )
    {
      ucfg_wlan_dp_clear_tx_rx_histogram(**(_QWORD **)(a1 + 24));
      v21 = 0;
      return qdf_status_to_os_return(v21);
    }
  }
  else
  {
    switch ( a2 )
    {
      case 4:
        wlan_hdd_clear_netif_queue_history(*(_QWORD *)(a1 + 24));
        v21 = 0;
        return qdf_status_to_os_return(v21);
      case 7:
        hdd_clear_hif_stats(v12);
        v21 = 0;
        return qdf_status_to_os_return(v21);
      case 9:
        hdd_clear_napi_stats(v12);
        v21 = 0;
        return qdf_status_to_os_return(v21);
    }
  }
  context = _cds_get_context(71, (__int64)"hdd_wlan_clear_stats", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !context || !*context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v23, v24, v25, v26, v27, v28, v29, v30, "cdp_clear_stats");
LABEL_21:
    v21 = 4;
LABEL_22:
    v33 = v21;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Failed to dump stats for stats_id: %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_wlan_clear_stats",
      (unsigned int)a2);
    v21 = v33;
    return qdf_status_to_os_return(v21);
  }
  v31 = *(__int64 (***)(void))(*context + 88LL);
  if ( !v31 )
    goto LABEL_21;
  v32 = *v31;
  if ( !v32 )
    goto LABEL_21;
  if ( *((_DWORD *)v32 - 1) != -254072184 )
    __break(0x8228u);
  v21 = v32();
  if ( v21 )
    goto LABEL_22;
  return qdf_status_to_os_return(v21);
}
