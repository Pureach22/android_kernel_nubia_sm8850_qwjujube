bool __fastcall hdd_cm_is_connecting(__int64 a1)
{
  __int64 vdev_by_user; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  bool is_vdev_connecting; // w19
  __int64 v11; // x20

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 88, "hdd_cm_is_connecting");
  if ( vdev_by_user )
  {
    if ( (*(_DWORD *)(vdev_by_user + 16) & 0xFFFFFFFD) != 0 )
    {
      is_vdev_connecting = 0;
    }
    else
    {
      v11 = vdev_by_user;
      is_vdev_connecting = ucfg_cm_is_vdev_connecting(vdev_by_user, v2, v3, v4, v5, v6, v7, v8, v9);
      vdev_by_user = v11;
    }
    _hdd_objmgr_put_vdev_by_user(vdev_by_user, 88, "hdd_cm_is_connecting");
  }
  else
  {
    return 0;
  }
  return is_vdev_connecting;
}
