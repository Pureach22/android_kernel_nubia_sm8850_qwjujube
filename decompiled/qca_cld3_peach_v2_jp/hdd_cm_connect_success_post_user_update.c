__int64 __fastcall hdd_cm_connect_success_post_user_update(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10)
{
  __int64 *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int8 v20; // w23
  __int64 *v21; // x20
  __int64 link_info_by_vdev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  __int64 v32; // x23
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w8
  __int64 result; // x0

  context = _cds_get_context(51, (__int64)"hdd_cm_connect_success_post_user_update", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: hdd_ctx is NULL",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "hdd_cm_connect_success_post_user_update");
  v20 = a10[1];
  v21 = context;
  link_info_by_vdev = hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: adapter is NULL for vdev %d",
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             "hdd_cm_connect_success_post_user_update",
             *a10);
  v31 = link_info_by_vdev;
  if ( (v20 & 4) == 0 )
  {
    qdf_runtime_pm_allow_suspend(v21 + 208);
    hdd_allow_suspend(19);
  }
  v32 = *(_QWORD *)v31;
  qdf_mem_set((void *)(*(_QWORD *)(*(_QWORD *)v31 + 52824LL) + 4264LL), 2u, 0);
  if ( (ucfg_cp_stats_is_bcn_rssi_history_report_cfg_enable(*v21) & 1) != 0 )
    wlan_hdd_reset_bcn_rssi_history_stats(v31);
  v41 = *(_DWORD *)(v32 + 40);
  if ( !v41 || v41 == 2 && wlan_vdev_p2p_is_wfd_r2_mode(*v21, *a10, v33, v34, v35, v36, v37, v38, v39, v40) )
    ucfg_twt_init_context(*v21, a10 + 8, 255);
  ucfg_dp_periodic_sta_stats_start();
  result = wlan_twt_concurrency_update(v21);
  *(_QWORD *)(v32 + 57440) = 0;
  return result;
}
