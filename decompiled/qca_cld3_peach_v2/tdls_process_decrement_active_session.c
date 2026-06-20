__int64 __fastcall tdls_process_decrement_active_session(
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
  unsigned int v18; // w20
  unsigned int v19; // w0
  __int64 v20; // x0
  __int64 v21; // x19
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  qdf_trace_msg(0, 8u, "%s: Enter", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_decrement_active_session");
  if ( !a1 )
    return 29;
  if ( policy_mgr_is_hw_dbs_2x2_capable(a1)
    || policy_mgr_is_hw_dbs_required_for_band(a1, 1)
    || (policy_mgr_is_current_hwmode_dbs(a1) & 1) == 0 )
  {
    v18 = policy_mgr_mode_specific_vdev_id(a1, 0);
    if ( v18 == 255 )
    {
      v19 = policy_mgr_mode_specific_vdev_id(a1, 2);
      if ( v19 == 255 )
        return 16;
      v18 = v19;
      if ( (unsigned int)policy_mgr_get_connection_count_with_mlo(a1) != 1 )
        return 16;
    }
    v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v18, 17);
    if ( !v20 )
      return 16;
    v21 = v20;
    if ( (tdls_check_is_tdls_allowed(v20) & 1) != 0 )
    {
      qdf_trace_msg(
        0,
        8u,
        "%s: Enable TDLS as active sta/p2p_cli interface is present",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "tdls_process_decrement_active_session");
      if ( (wlan_vdev_mlme_is_mlo_vdev(v21, v31, v32, v33, v34, v35, v36, v37, v38) & 1) != 0 )
        tdls_process_enable_disable_for_ml_vdev(v21, 1);
      else
        tdls_process_enable_for_vdev(v21);
    }
    wlan_objmgr_vdev_release_ref(v21, 0x11u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
  }
  else
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: Current HW mode is 1*1 DBS. Wait for Opportunistic timer to expire to enable TDLS in FW",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "tdls_process_decrement_active_session");
  }
  return 0;
}
