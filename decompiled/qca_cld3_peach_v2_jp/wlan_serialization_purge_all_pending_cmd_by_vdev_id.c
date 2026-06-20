__int64 __fastcall wlan_serialization_purge_all_pending_cmd_by_vdev_id(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  __int64 v13; // x20
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v15; // x21
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v26; // x2

  if ( a1 )
  {
    pdev_obj = wlan_serialization_get_pdev_obj(a1);
    if ( pdev_obj )
    {
      v13 = pdev_obj;
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 9u);
      if ( vdev_by_id_from_pdev )
      {
        v15 = (__int64)vdev_by_id_from_pdev;
        wlan_ser_cancel_scan_cmd(v13, a1, vdev_by_id_from_pdev, 0, 0, 0);
        wlan_ser_cancel_non_scan_cmd(v13, a1, v15, 0, 1, 0, 0);
        return wlan_objmgr_vdev_release_ref(v15, 9u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
      }
      v26 = "%s: Invalid vdev";
    }
    else
    {
      v26 = "%s: invalid ser_pdev_obj";
    }
  }
  else
  {
    v26 = "%s: Invalid pdev";
  }
  return qdf_trace_msg(
           0x4Cu,
           2u,
           v26,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "wlan_serialization_purge_all_pending_cmd_by_vdev_id");
}
