__int64 __fastcall is_dnw_in_progress(
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
  _QWORD *vdev_by_id_from_pdev; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 priv_fl; // x0
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char v30; // w20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  if ( a1 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x60u);
    if ( vdev_by_id_from_pdev )
    {
      v19 = (__int64)vdev_by_id_from_pdev;
      priv_fl = pre_cac_vdev_get_priv_fl((__int64)vdev_by_id_from_pdev, (__int64)"wlan_get_dnw_vdev_info", 0x24u);
      if ( priv_fl )
      {
        v30 = *(_BYTE *)(priv_fl + 32);
      }
      else
      {
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: NULL pre cac vdev priv",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wlan_get_dnw_vdev_info");
        qdf_trace_msg(0x98u, 2u, "%s: NULL dnw vdev info", v31, v32, v33, v34, v35, v36, v37, v38, "is_dnw_in_progress");
        v30 = 0;
      }
      wlan_objmgr_vdev_release_ref(v19, 0x60u, v21, v22, v23, v24, v25, v26, v27, v28, v29);
    }
    else
    {
      qdf_trace_msg(0x98u, 2u, "%s: null vdev", v11, v12, v13, v14, v15, v16, v17, v18, "is_dnw_in_progress");
      v30 = 1;
    }
  }
  else
  {
    qdf_trace_msg(0x98u, 2u, "%s: null pdev", a3, a4, a5, a6, a7, a8, a9, a10, "is_dnw_in_progress");
    v30 = 0;
  }
  return v30 & 1;
}
