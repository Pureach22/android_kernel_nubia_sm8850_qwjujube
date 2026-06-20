char *__fastcall ucfg_wlan_vdev_mgr_get_trans_bssid(__int64 a1, void *a2)
{
  char *result; // x0

  result = (char *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
  if ( result )
    return (char *)qdf_mem_copy(a2, result + 481, 6u);
  return result;
}
