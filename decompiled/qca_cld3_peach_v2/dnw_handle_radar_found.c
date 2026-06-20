__int64 __fastcall dnw_handle_radar_found(
        __int64 a1,
        char a2,
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
  __int64 v12; // x19
  __int64 priv_fl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int *v22; // x8
  __int64 comp_private_obj; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x4
  __int64 v33; // x20
  const char *v34; // x6
  const char *v35; // x2
  unsigned int v36; // w20
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x2
  __int64 v46; // x0

  if ( a1 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x60u);
    if ( vdev_by_id_from_pdev )
    {
      v12 = (__int64)vdev_by_id_from_pdev;
      priv_fl = pre_cac_vdev_get_priv_fl((__int64)vdev_by_id_from_pdev, (__int64)"wlan_get_dnw_vdev_info", 0x24u);
      if ( priv_fl )
      {
        v22 = (unsigned int *)*(unsigned __int8 *)(priv_fl + 32);
        if ( (_DWORD)v22 != 1 )
        {
          v36 = 16;
LABEL_17:
          wlan_objmgr_vdev_release_ref(v12, 0x60u, v22, v14, v15, v16, v17, v18, v19, v20, v21);
          return v36;
        }
        comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x2Du);
        if ( comp_private_obj )
        {
          v32 = *(unsigned int *)(comp_private_obj + 36);
          v33 = comp_private_obj;
          if ( (unsigned int)v32 > 3 )
            v34 = "UNKNOWN";
          else
            v34 = off_B2D690[v32];
          qdf_trace_msg(
            0x98u,
            8u,
            "%s: old %d new %d, %s->%s",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "wlan_dnw_set_state",
            v32,
            2,
            v34,
            "DNW_STATE_RADAR_FOUND");
          v46 = *(_QWORD *)(v33 + 8);
          *(_DWORD *)(v33 + 36) = 2;
          wlan_objmgr_pdev_iterate_obj_list(
            v46,
            2,
            (void (__fastcall *)(__int64, __int64, __int64))dnw_find_vdev_handler,
            v33 + 8,
            0,
            0x60u);
          v36 = 0;
          goto LABEL_17;
        }
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: NULL pre cac pdev priv",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_get_dnw_pdev_info");
        v45 = "%s: NULL dnw pdev info";
      }
      else
      {
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: NULL pre cac vdev priv",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_get_dnw_vdev_info");
        v45 = "%s: NULL dnw vdev info";
      }
      qdf_trace_msg(0x98u, 2u, v45, v37, v38, v39, v40, v41, v42, v43, v44, "dnw_handle_radar_found");
      v36 = 4;
      goto LABEL_17;
    }
    v35 = "%s: null vdev";
  }
  else
  {
    v35 = "%s: null pdev";
  }
  qdf_trace_msg(0x98u, 2u, v35, a3, a4, a5, a6, a7, a8, a9, a10, "dnw_handle_radar_found");
  return 4;
}
