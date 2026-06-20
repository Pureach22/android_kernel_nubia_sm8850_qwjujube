__int64 __fastcall hdd_handle_disassociation_event(
        int *a1,
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
  __int64 v10; // x23
  __int64 *v13; // x20
  _QWORD *context; // x19
  __int64 v15; // x5
  __int64 vdev_by_user; // x0
  __int64 v17; // x22
  int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x8
  __int64 (__fastcall *v45)(_QWORD); // x8

  v10 = *(_QWORD *)a1;
  v13 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  context = _cds_get_context(71, (__int64)"hdd_handle_disassociation_event", a3, a4, a5, a6, a7, a8, a9, a10);
  hdd_green_ap_start_state_mc(v13, *(unsigned int *)(v10 + 40), 0);
  v15 = *(unsigned int *)(v10 + 40);
  if ( ((unsigned int)v15 | 2) == 2 )
    os_if_wifi_pos_send_peer_status(a2, 2, 0, *((unsigned __int8 *)a1 + 8), 0, v15);
  hdd_lpass_notify_disconnect(a1);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 97, "hdd_handle_disassociation_event");
  if ( vdev_by_user )
  {
    v17 = vdev_by_user;
    v18 = hdd_convert_cfgdot11mode_to_80211mode(a1[172]);
    ucfg_dp_del_latency_critical_client(v17, v18, v19, v20, v21, v22, v23, v24, v25, v26);
    ucfg_dp_bus_bw_compute_reset_prev_txrx_stats(v17, v27, v28, v29, v30, v31, v32, v33, v34);
    _hdd_objmgr_put_vdev_by_user(v17, 97, "hdd_handle_disassociation_event");
  }
  result = ucfg_dp_bus_bw_compute_timer_try_stop(*v13);
  if ( !context )
    return qdf_trace_msg(
             0x89u,
             8u,
             "%s: Invalid Instance:",
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42,
             v43,
             "cdp_display_txrx_hw_info");
  if ( !*context )
    return qdf_trace_msg(
             0x89u,
             8u,
             "%s: Invalid Instance:",
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42,
             v43,
             "cdp_display_txrx_hw_info");
  v44 = *(_QWORD *)(*context + 64LL);
  if ( !v44 )
    return qdf_trace_msg(
             0x89u,
             8u,
             "%s: Invalid Instance:",
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42,
             v43,
             "cdp_display_txrx_hw_info");
  v45 = *(__int64 (__fastcall **)(_QWORD))(v44 + 280);
  if ( v45 )
  {
    if ( *((_DWORD *)v45 - 1) != 944657148 )
      __break(0x8228u);
    return v45(context);
  }
  return result;
}
