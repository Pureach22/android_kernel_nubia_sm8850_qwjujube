bool __fastcall hdd_cm_is_vdev_associated(_DWORD *a1)
{
  bool is_vdev_active; // w19
  __int64 vdev_by_user; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20

  if ( *(_DWORD *)(*(_QWORD *)a1 + 40LL) == 11 )
  {
    return a1[74] == 2;
  }
  else
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 88, "hdd_cm_is_vdev_associated");
    if ( vdev_by_user )
    {
      if ( (*(_DWORD *)(vdev_by_user + 16) & 0xFFFFFFFD) == 0 )
      {
        v11 = vdev_by_user;
        is_vdev_active = ucfg_cm_is_vdev_active(vdev_by_user, v3, v4, v5, v6, v7, v8, v9, v10);
        _hdd_objmgr_put_vdev_by_user(v11, 88, "hdd_cm_is_vdev_associated");
        return is_vdev_active;
      }
      _hdd_objmgr_put_vdev_by_user(vdev_by_user, 88, "hdd_cm_is_vdev_associated");
    }
    return 0;
  }
}
