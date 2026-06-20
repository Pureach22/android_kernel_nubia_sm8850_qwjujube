__int64 __fastcall wlan_mlme_get_mac_vdev_id(__int64 a1, char a2, void *a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v5; // x20
  unsigned int *v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  if ( !a1 )
    return 4;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u);
  if ( !vdev_by_id_from_pdev )
    return 4;
  v5 = (__int64)vdev_by_id_from_pdev;
  qdf_mem_copy(a3, (char *)vdev_by_id_from_pdev + 74, 6u);
  wlan_objmgr_vdev_release_ref(v5, 7u, v6, v7, v8, v9, v10, v11, v12, v13, v14);
  return 0;
}
