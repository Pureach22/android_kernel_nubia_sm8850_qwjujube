__int64 __fastcall if_mgr_disconnect_start(
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
  __int64 v9; // x8
  __int64 ext_hdl; // x0

  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 )
    return 16;
  if ( !*(_QWORD *)(v9 + 80) )
    return 16;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !ext_hdl )
    return 16;
  qdf_runtime_pm_prevent_suspend((__int64 *)(ext_hdl + 24912));
  if ( (mlo_mgr_is_link_switch_in_progress(a1) & 1) != 0 )
    wlan_tdls_delete_all_peers(a1, 2);
  return 0;
}
