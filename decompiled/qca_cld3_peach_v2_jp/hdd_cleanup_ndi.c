__int64 __fastcall hdd_cleanup_ndi(
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
  __int64 v9; // x19
  __int64 *v11; // x22
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
  __int64 vdev_by_user; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x19
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7

  if ( *(_DWORD *)(a1 + 296) != 2 )
    return qdf_trace_msg(0x33u, 8u, "%s: NDI has no NDPs", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_cleanup_ndi");
  v9 = *(_QWORD *)a1;
  v11 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  *(_DWORD *)(a1 + 296) = 1;
  hdd_conn_set_connection_state(v9, 1u, a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev %d Disabling queues",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "hdd_cleanup_ndi",
    *(unsigned __int8 *)(a1 + 8));
  wlan_hdd_netif_queue_control(v9, 4u, 1u, v20, v21, v22, v23, v24, v25, v26, v27);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x61u, (__int64)"hdd_cleanup_ndi");
  if ( vdev_by_user )
  {
    v37 = vdev_by_user;
    ucfg_dp_bus_bw_compute_reset_prev_txrx_stats(vdev_by_user, v29, v30, v31, v32, v33, v34, v35, v36);
    _hdd_objmgr_put_vdev_by_user(v37, 0x61u, (__int64)"hdd_cleanup_ndi", v38, v39, v40, v41, v42, v43, v44, v45, v46);
  }
  ucfg_dp_bus_bw_compute_timer_try_stop(*v11);
  result = ucfg_dp_is_ol_enabled(*v11);
  if ( (result & 1) != 0 )
  {
    result = ucfg_is_nan_dbs_supported(*v11, v48, v49, v50, v51, v52, v53, v54, v55);
    if ( (result & 1) == 0 )
    {
      result = ucfg_is_nan_conc_control_supported(*v11, v56, v57, v58, v59, v60, v61, v62, v63);
      if ( (result & 1) == 0 )
      {
        if ( !(unsigned int)policy_mgr_get_connection_count(*v11)
          || (result = policy_mgr_get_connection_count(*v11), (_DWORD)result == 1)
          && (result = policy_mgr_mode_specific_connection_count(*v11, 0, nullptr), (_DWORD)result == 1) )
        {
          qdf_trace_msg(0x33u, 8u, "%s: Enable LRO/GRO", v64, v65, v66, v67, v68, v69, v70, v71, "hdd_cleanup_ndi");
          return ucfg_dp_rx_handle_concurrency(*v11, 0);
        }
      }
    }
  }
  return result;
}
