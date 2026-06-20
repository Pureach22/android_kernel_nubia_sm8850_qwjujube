__int64 wlan_cmn_mlme_deinit()
{
  __int64 result; // x0

  if ( glbl_twt_ops_cb )
    glbl_twt_ops = 0;
  if ( glbl_vdev_mgr_ops_cb )
    glbl_vdev_mgr_ops = 0;
  if ( glbl_cm_ops_cb )
    glbl_cm_ops = 0;
  result = wlan_vdev_mlme_deinit();
  if ( !(_DWORD)result )
  {
    result = wlan_pdev_mlme_deinit();
    if ( !(_DWORD)result )
      return wlan_psoc_mlme_deinit();
  }
  return result;
}
