__int64 __fastcall wlan_cm_get_ese_assoc(__int64 a1, char a2)
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
  __int64 ext_hdl_fl; // x8
  char v12; // w19
  _QWORD *v13; // x19

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( vdev_by_id_from_pdev )
  {
    ext_hdl_fl = *((unsigned int *)vdev_by_id_from_pdev + 4);
    if ( (ext_hdl_fl & 0xFFFFFFFD) != 0
      || (v13 = vdev_by_id_from_pdev,
          ext_hdl_fl = cm_get_ext_hdl_fl(
                         (__int64)vdev_by_id_from_pdev,
                         (__int64)"wlan_cm_get_ese_assoc",
                         0x485u,
                         v3,
                         v4,
                         v5,
                         v6,
                         v7,
                         v8,
                         v9,
                         v10),
          vdev_by_id_from_pdev = v13,
          (wlan_cm_get_ese_assoc_rso_cfg = ext_hdl_fl) == 0) )
    {
      wlan_objmgr_vdev_release_ref(
        (__int64)vdev_by_id_from_pdev,
        0x4Du,
        (unsigned int *)ext_hdl_fl,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10);
      v12 = 0;
    }
    else
    {
      v12 = *(_BYTE *)(ext_hdl_fl + 678);
      wlan_objmgr_vdev_release_ref(
        (__int64)vdev_by_id_from_pdev,
        0x4Du,
        (unsigned int *)ext_hdl_fl,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10);
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "wlan_cm_get_ese_assoc");
    v12 = 0;
  }
  return v12 & 1;
}
