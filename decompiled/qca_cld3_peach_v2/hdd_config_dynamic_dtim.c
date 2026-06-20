__int64 __fastcall hdd_config_dynamic_dtim(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 vdev_by_user; // x0
  __int64 v4; // x20
  unsigned int v5; // w19

  v2 = *(_DWORD *)(a2 + 4);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_config_dynamic_dtim");
  if ( !vdev_by_user )
    return 4294967274LL;
  v4 = vdev_by_user;
  v5 = ucfg_pmo_config_modulated_dtim(vdev_by_user, v2);
  _hdd_objmgr_put_vdev_by_user(v4, 6, "hdd_config_dynamic_dtim");
  return qdf_status_to_os_return(v5);
}
