unsigned __int8 *__fastcall ucfg_wlan_vdev_mgr_get_param_ssid(__int64 a1, void *a2, _BYTE *a3)
{
  unsigned __int8 *result; // x0
  size_t v6; // x2

  result = (unsigned __int8 *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
  if ( result )
  {
    v6 = result[162];
    *a3 = v6;
    return (unsigned __int8 *)qdf_mem_copy(a2, result + 129, v6);
  }
  return result;
}
