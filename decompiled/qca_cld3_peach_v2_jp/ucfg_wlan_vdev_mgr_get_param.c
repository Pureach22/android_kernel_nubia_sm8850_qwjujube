__int64 __fastcall ucfg_wlan_vdev_mgr_get_param(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0

  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
  if ( result )
    return wlan_util_vdev_mlme_get_param(result, a2, a3);
  return result;
}
