__int64 __fastcall if_mgr_disconnect_complete(
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
  __int64 v9; // x21
  __int64 v10; // x19
  __int64 ext_hdl; // x0
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  char acs_mode_for_vdev; // w0
  unsigned int v25; // w19

  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 )
    return 16;
  v10 = *(_QWORD *)(v9 + 80);
  if ( !v10 )
    return 16;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !ext_hdl )
    return 16;
  qdf_runtime_pm_allow_suspend((__int64 *)(ext_hdl + 24912));
  if ( (*(_DWORD *)(a1 + 16) | 2) == 2 && (wlan_mlme_is_aux_emlsr_support(v10) & 1) == 0 )
    wlan_handle_emlsr_sta_concurrency(v10, 0, 1);
  v13 = if_mgr_enable_roaming_after_p2p_disconnect(v9, a1, 4);
  if ( v13 )
  {
    v22 = "%s: Failed to enable roaming after p2p disconnect";
  }
  else
  {
    if ( (mlo_is_mld_sta(a1) & 1) == 0 || (mlo_mgr_is_link_switch_in_progress(a1) & 1) == 0 )
    {
      acs_mode_for_vdev = wlan_util_vdev_mgr_get_acs_mode_for_vdev(a1);
      policy_mgr_check_concurrent_intf_and_restart_sap(v10, acs_mode_for_vdev & 1);
    }
    v13 = if_mgr_enable_roaming_on_connected_sta(v9, a1);
    if ( !v13 )
    {
      policy_mgr_sta_post_disconnect_conc_check(v10);
      return 0;
    }
    v22 = "%s: Failed to enable roaming on connected sta";
  }
  v25 = v13;
  qdf_trace_msg(0x78u, 2u, v22, v14, v15, v16, v17, v18, v19, v20, v21, "if_mgr_disconnect_complete");
  return v25;
}
