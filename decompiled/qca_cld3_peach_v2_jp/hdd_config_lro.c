__int64 __fastcall hdd_config_lro(__int64 a1)
{
  __int64 vdev_by_user; // x0
  unsigned int v2; // w0

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 97, "hdd_config_lro");
  if ( vdev_by_user )
  {
    _hdd_objmgr_put_vdev_by_user(vdev_by_user, 97, "hdd_config_lro");
    v2 = 0;
  }
  else
  {
    v2 = 5;
  }
  return qdf_status_to_os_return(v2);
}
