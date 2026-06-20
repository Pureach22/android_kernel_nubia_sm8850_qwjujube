bool __fastcall cm_is_vdevid_active(__int64 a1, unsigned __int8 a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int *v12; // x8
  bool is_vdev_active; // w19
  __int64 v14; // x20
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( vdev_by_id_from_pdev )
  {
    v12 = (unsigned int *)*((unsigned int *)vdev_by_id_from_pdev + 4);
    if ( ((unsigned int)v12 & 0xFFFFFFFD) != 0 )
    {
      wlan_objmgr_vdev_release_ref((__int64)vdev_by_id_from_pdev, 0x4Du, v12, v4, v5, v6, v7, v8, v9, v10, v11);
      return 0;
    }
    else
    {
      v14 = (__int64)vdev_by_id_from_pdev;
      is_vdev_active = cm_is_vdev_active((__int64)vdev_by_id_from_pdev, v4, v5, v6, v7, v8, v9, v10, v11);
      wlan_objmgr_vdev_release_ref(v14, 0x4Du, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev %d: vdev not found", v4, v5, v6, v7, v8, v9, v10, v11, "cm_is_vdevid_active", a2);
    return 0;
  }
  return is_vdev_active;
}
