bool __fastcall wlan_cm_roaming_in_progress(__int64 a1, unsigned __int8 a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int *v11; // x8
  bool is_vdev_roaming; // w19
  _QWORD *v13; // x20

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( vdev_by_id_from_pdev )
  {
    v11 = (unsigned int *)*((unsigned int *)vdev_by_id_from_pdev + 4);
    if ( ((unsigned int)v11 & 0xFFFFFFFD) != 0 )
    {
      is_vdev_roaming = 0;
    }
    else
    {
      v13 = vdev_by_id_from_pdev;
      is_vdev_roaming = wlan_cm_is_vdev_roaming((__int64)vdev_by_id_from_pdev, v3, v4, v5, v6, v7, v8, v9, v10);
      vdev_by_id_from_pdev = v13;
    }
    wlan_objmgr_vdev_release_ref((__int64)vdev_by_id_from_pdev, 0x4Du, v11, v3, v4, v5, v6, v7, v8, v9, v10);
  }
  else
  {
    return 0;
  }
  return is_vdev_roaming;
}
