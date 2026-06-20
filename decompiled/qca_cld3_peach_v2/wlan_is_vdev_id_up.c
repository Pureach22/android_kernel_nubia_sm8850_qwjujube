bool __fastcall wlan_is_vdev_id_up(__int64 a1, char a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v3; // x20
  _BOOL4 v4; // w19
  unsigned int *v5; // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  if ( a1 && (vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u)) != nullptr )
  {
    v3 = (__int64)vdev_by_id_from_pdev;
    v4 = wlan_vdev_is_up() == 0;
    wlan_objmgr_vdev_release_ref(v3, 7u, v5, v6, v7, v8, v9, v10, v11, v12, v13);
  }
  else
  {
    return 0;
  }
  return v4;
}
