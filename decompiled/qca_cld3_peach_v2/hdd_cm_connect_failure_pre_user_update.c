__int64 __fastcall hdd_cm_connect_failure_pre_user_update(
        __int64 a1,
        char *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w24
  _QWORD *v22; // x23
  _QWORD *link_info_by_vdev; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _DWORD *v32; // x21
  __int64 v33; // x22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w9
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w6
  int v52; // w7
  const void *v53; // x4
  unsigned __int8 v54; // w2
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7

  context = _cds_get_context(51, (__int64)"hdd_cm_connect_failure_pre_user_update", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: hdd_ctx is NULL",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "hdd_cm_connect_failure_pre_user_update");
  v21 = *(_DWORD *)(a1 + 64);
  v22 = context;
  link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: adapter is NULL vdev %d",
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             "hdd_cm_connect_failure_pre_user_update",
             (unsigned __int8)*a2);
  v32 = link_info_by_vdev;
  v33 = *link_info_by_vdev;
  qdf_mem_set((char *)link_info_by_vdev + 916, 0x18u, 0);
  hdd_init_scan_reject_params(v22);
  v42 = *((_DWORD *)a2 + 15);
  *(_DWORD *)(*(_QWORD *)v32 + 52404LL) = v42;
  v32[211] = v42;
  v32[385] = v42;
  if ( (v21 & 0x2000000) == 0 )
  {
    hdd_conn_remove_connect_info((__int64)(v32 + 20));
    v34 = hdd_adapter_reset_station_ctx(v33);
  }
  ucfg_dp_remove_conn_info(a1, v34, v35, v36, v37, v38, v39, v40, v41);
  hdd_cm_update_rssi_snr_by_bssid(v32, v43, v44, v45, v46, v47, v48, v49, v50);
  v51 = *((_DWORD *)a2 + 1);
  if ( (a2[1] & 4) != 0 )
  {
    v53 = a2 + 8;
    v54 = 21;
    v52 = 0;
  }
  else
  {
    v52 = *((_DWORD *)a2 + 15);
    v53 = a2 + 8;
    v54 = 18;
    v51 = *((_DWORD *)a2 + 14) | (v51 << 16);
  }
  wlan_rec_debug_log((char *)&off_0 + 1, *a2, v54, 0, v53, 0, v51, v52);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Invoking packetdump deregistration API",
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    "hdd_cm_connect_failure_pre_user_update");
  return wlan_deregister_txrx_packetdump();
}
