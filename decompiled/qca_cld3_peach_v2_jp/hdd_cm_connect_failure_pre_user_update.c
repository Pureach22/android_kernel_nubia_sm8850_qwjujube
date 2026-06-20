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
  _QWORD *v21; // x21
  _QWORD *link_info_by_vdev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  _DWORD *v32; // x23
  int v33; // w9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w6
  int v51; // w7
  const void *v52; // x4
  unsigned __int8 v53; // w2
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7

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
  v21 = context;
  link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: adapter is NULL vdev %d",
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             "hdd_cm_connect_failure_pre_user_update",
             (unsigned __int8)*a2);
  v31 = *link_info_by_vdev;
  v32 = link_info_by_vdev;
  qdf_mem_set((char *)link_info_by_vdev + 908, 0x18u, 0);
  hdd_init_scan_reject_params(v21);
  v33 = *((_DWORD *)a2 + 15);
  *(_DWORD *)(*(_QWORD *)v32 + 52404LL) = v33;
  v32[209] = v33;
  v32[379] = v33;
  hdd_conn_remove_connect_info((__int64)(v32 + 20));
  v34 = hdd_adapter_reset_station_ctx(v31);
  ucfg_dp_remove_conn_info(a1, v34, v35, v36, v37, v38, v39, v40, v41);
  hdd_cm_update_rssi_snr_by_bssid(v32, v42, v43, v44, v45, v46, v47, v48, v49);
  v50 = *((_DWORD *)a2 + 1);
  if ( (a2[1] & 4) != 0 )
  {
    v52 = a2 + 8;
    v53 = 21;
    v51 = 0;
  }
  else
  {
    v51 = *((_DWORD *)a2 + 15);
    v52 = a2 + 8;
    v53 = 18;
    v50 = *((_DWORD *)a2 + 14) | (v50 << 16);
  }
  wlan_rec_debug_log((char *)&off_0 + 1, *a2, v53, 0, v52, 0, v50, v51);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Invoking packetdump deregistration API",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "hdd_cm_connect_failure_pre_user_update");
  return wlan_deregister_txrx_packetdump();
}
