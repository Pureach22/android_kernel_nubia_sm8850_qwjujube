__int64 __fastcall wlan_cm_get_country_code(__int64 a1, char a2, void *a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int *v13; // x8
  unsigned int v14; // w20
  _QWORD *v15; // x21
  __int64 ext_hdl_fl; // x0

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( vdev_by_id_from_pdev )
  {
    v13 = (unsigned int *)*((unsigned int *)vdev_by_id_from_pdev + 4);
    if ( ((unsigned int)v13 & 0xFFFFFFFD) != 0 )
    {
      v14 = 4;
    }
    else
    {
      v15 = vdev_by_id_from_pdev;
      ext_hdl_fl = cm_get_ext_hdl_fl(
                     (__int64)vdev_by_id_from_pdev,
                     (__int64)"wlan_cm_get_country_code",
                     0x454u,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12);
      v14 = 4;
      wlan_cm_get_country_code_rso_cfg = ext_hdl_fl;
      if ( a3 )
      {
        v13 = (unsigned int *)ext_hdl_fl;
        vdev_by_id_from_pdev = v15;
        if ( v13 )
        {
          qdf_mem_copy(a3, v13 + 22, 3u);
          vdev_by_id_from_pdev = v15;
          v14 = 0;
        }
      }
      else
      {
        vdev_by_id_from_pdev = v15;
      }
    }
    wlan_objmgr_vdev_release_ref((__int64)vdev_by_id_from_pdev, 0x4Du, v13, v5, v6, v7, v8, v9, v10, v11, v12);
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_cm_get_country_code");
    return 4;
  }
  return v14;
}
