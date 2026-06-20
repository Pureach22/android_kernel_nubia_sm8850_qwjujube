__int64 __fastcall dnw_handle_bss_stop(
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
  __int64 v23; // x21
  __int64 comp_private_obj; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  unsigned __int8 v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x4
  const char *v44; // x6
  const char *v45; // x2
  unsigned int v46; // w20
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  const char *v55; // x2
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7

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
          v46 = 16;
LABEL_20:
          wlan_objmgr_vdev_release_ref(v12, 0x60u, v22, v14, v15, v16, v17, v18, v19, v20, v21);
          return v46;
        }
        v23 = priv_fl;
        comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x2Du);
        if ( comp_private_obj )
        {
          *(_BYTE *)(v23 + 32) = 0;
          v33 = comp_private_obj;
          *(_QWORD *)(v23 + 24) = 0;
          v34 = *(_BYTE *)(comp_private_obj + 19);
          if ( v34 )
          {
            *(_BYTE *)(comp_private_obj + 19) = --v34;
            if ( !v34 )
            {
              *(_BYTE *)(comp_private_obj + 17) = 0;
              stop_dnw_timer(comp_private_obj + 8, v25, v26, v27, v28, v29, v30, v31, v32);
              v34 = *(_BYTE *)(v33 + 19);
            }
          }
          qdf_trace_msg(
            0x98u,
            8u,
            "%s: dnw count %d, vdev %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "wlan_dnw_reset",
            v34,
            *(unsigned __int8 *)(v12 + 168));
          v43 = *(unsigned int *)(v33 + 36);
          if ( (unsigned int)v43 > 3 )
            v44 = "UNKNOWN";
          else
            v44 = off_B2D690[v43];
          qdf_trace_msg(
            0x98u,
            8u,
            "%s: old %d new %d, %s->%s",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "wlan_dnw_set_state",
            v43,
            3,
            v44,
            "DNW_STATE_END");
          *(_DWORD *)(v33 + 36) = 3;
          qdf_trace_msg(
            0x98u,
            8u,
            "%s: reset dnw since dnw in progress, vdev %d",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "dnw_handle_bss_stop",
            *(unsigned __int8 *)(v12 + 168));
          v46 = 0;
          goto LABEL_20;
        }
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: NULL pre cac pdev priv",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wlan_get_dnw_pdev_info");
        v55 = "%s: NULL dnw pdev info";
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
        v55 = "%s: NULL dnw vdev info";
      }
      qdf_trace_msg(0x98u, 2u, v55, v47, v48, v49, v50, v51, v52, v53, v54, "dnw_handle_bss_stop");
      v46 = 4;
      goto LABEL_20;
    }
    v45 = "%s: null vdev";
  }
  else
  {
    v45 = "%s: null pdev";
  }
  qdf_trace_msg(0x98u, 2u, v45, a3, a4, a5, a6, a7, a8, a9, a10, "dnw_handle_bss_stop");
  return 4;
}
