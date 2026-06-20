bool __fastcall hdd_cm_is_vdev_connected(_DWORD *a1)
{
  int v1; // w8
  bool is_vdev_connected; // w19
  __int64 vdev_by_user; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20

  v1 = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
  if ( v1 == 11 )
  {
    return a1[74] == 2;
  }
  else if ( (v1 & 0xFFFFFFFD) != 0
         || (vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 88, "hdd_cm_is_vdev_connected")) == 0 )
  {
    return 0;
  }
  else
  {
    v12 = vdev_by_user;
    is_vdev_connected = ucfg_cm_is_vdev_connected(vdev_by_user, v4, v5, v6, v7, v8, v9, v10, v11);
    _hdd_objmgr_put_vdev_by_user(v12, 88, "hdd_cm_is_vdev_connected");
  }
  return is_vdev_connected;
}
