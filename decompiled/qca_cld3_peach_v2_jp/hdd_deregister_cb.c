__int64 __fastcall hdd_deregister_cb(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  unsigned int v19; // w1
  __int64 v20; // x20
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_deregister_cb");
  if ( curr_con_mode == 5 )
  {
    v18 = "%s: in ftm mode, no need to deregister callbacks";
    v19 = 2;
  }
  else
  {
    v20 = *(_QWORD *)(a1 + 16);
    sme_deregister_disconnect_cb(v20);
    sme_deregister_ssr_on_pagefault_cb(v20);
    sme_smem_oem_event_deinit(v20);
    sme_async_oem_event_deinit(v20);
    sme_deregister_tx_queue_cb(v20);
    sme_reset_link_layer_stats_ind_cb(v20);
    sme_reset_rssi_threshold_breached_cb(v20);
    sme_stats_ext_deregister_callback(v20);
    v21 = sme_reset_tsfcb(v20);
    if ( v21 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to de-register tsfcb the callback:%d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_deregister_cb",
        v21);
    if ( (unsigned int)hdd_deregister_data_stall_detect_cb(v22, v23, v24, v25, v26, v27, v28, v29) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to de-register data stall detect event callback",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "hdd_deregister_cb");
    hdd_thermal_unregister_callbacks(a1);
    sme_multi_client_ll_rsp_deregister_callback(v20);
    v18 = "%s: exit";
    v19 = 8;
  }
  return qdf_trace_msg(0x33u, v19, v18, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_deregister_cb");
}
