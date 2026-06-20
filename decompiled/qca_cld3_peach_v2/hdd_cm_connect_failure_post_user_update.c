__int64 __fastcall hdd_cm_connect_failure_post_user_update(
        __int64 a1,
        unsigned __int8 *a2,
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
  unsigned __int8 v21; // w23
  _QWORD *v22; // x20
  __int64 link_info_by_vdev; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  __int64 v33; // x23
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

  context = _cds_get_context(51, (__int64)"hdd_cm_connect_failure_post_user_update", a3, a4, a5, a6, a7, a8, a9, a10);
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
             "hdd_cm_connect_failure_post_user_update");
  v21 = a2[1];
  v22 = context;
  link_info_by_vdev = hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: adapter is NULL for vdev %d",
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             "hdd_cm_connect_failure_post_user_update",
             *a2);
  v32 = link_info_by_vdev;
  if ( (v21 & 4) == 0 )
  {
    qdf_runtime_pm_allow_suspend(v22 + 208);
    hdd_allow_suspend(19);
  }
  v33 = *(_QWORD *)v32;
  v34 = wlan_hdd_connectivity_fail_event(a1, a2);
  hdd_clear_roam_profile_ie(v33, v34, v35, v36, v37, v38, v39, v40, v41);
  ucfg_cm_reset_key(v22[1], *(_BYTE *)(v32 + 8));
  hdd_wmm_dscp_initial_state(v33);
  if ( (wlan_cm_is_link_switch_connect_resp((__int64)a2) & 1) == 0
    && (wlan_cm_is_link_add_connect_resp((__int64)a2) & 1) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d Disabling queues",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "hdd_cm_connect_failure_post_user_update",
      *(unsigned __int8 *)(v32 + 8));
    wlan_hdd_netif_queue_control(v33, 4, 1);
  }
  ucfg_dp_periodic_sta_stats_start();
  return wlan_twt_concurrency_update(v22);
}
