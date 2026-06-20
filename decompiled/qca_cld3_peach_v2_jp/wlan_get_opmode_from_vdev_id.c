__int64 __fastcall wlan_get_opmode_from_vdev_id(__int64 a1, unsigned __int8 a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  unsigned int *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19

  if ( a1 && (vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u)) != nullptr )
  {
    v12 = *((_DWORD *)vdev_by_id_from_pdev + 4);
    wlan_objmgr_vdev_release_ref((__int64)vdev_by_id_from_pdev, 7u, v3, v4, v5, v6, v7, v8, v9, v10, v11);
  }
  else
  {
    return 17;
  }
  return v12;
}
