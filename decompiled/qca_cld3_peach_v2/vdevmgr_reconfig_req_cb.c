__int64 __fastcall vdevmgr_reconfig_req_cb(
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
  __int64 v10; // x8
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  unsigned int *v21; // x8
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v30; // x2

  v9 = *(_QWORD *)(a1 + 8);
  if ( !v9 )
  {
    v30 = "%s: vdev null";
    goto LABEL_9;
  }
  v10 = *(_QWORD *)(v9 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v30 = "%s: Failed to get psoc";
LABEL_9:
    qdf_trace_msg(0x68u, 2u, v30, a2, a3, a4, a5, a6, a7, a8, a9, "vdevmgr_reconfig_req_cb");
    return 4;
  }
  if ( (wlan_get_vdev_link_removed_flag_by_vdev_id(v11, *(unsigned __int8 *)(v9 + 168)) & 1) == 0 )
    mlme_cm_osif_link_reconfig_notify();
  policy_mgr_handle_link_removal_on_vdev(v9, v12, v13, v14, v15, v16, v17, v18, v19);
  v20 = mlo_sta_stop_reconfig_timer_by_vdev(v9);
  wlan_objmgr_vdev_release_ref(v9, 0x4Du, v21, v20, v22, v23, v24, v25, v26, v27, v28);
  return 0;
}
