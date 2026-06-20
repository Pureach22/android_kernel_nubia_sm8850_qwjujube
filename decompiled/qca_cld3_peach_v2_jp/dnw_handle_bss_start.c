__int64 __fastcall dnw_handle_bss_start(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  __int64 priv_fl; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  __int64 v34; // x23
  __int64 comp_private_obj; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x20
  const char *v45; // x4
  __int64 active_channel; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x4
  unsigned int v56; // w21
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  const char *v65; // x2
  unsigned __int8 v67; // w8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x4
  const char *v77; // x6
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7

  if ( a1 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x60u);
    if ( vdev_by_id_from_pdev )
    {
      v23 = (__int64)vdev_by_id_from_pdev;
      priv_fl = pre_cac_vdev_get_priv_fl((__int64)vdev_by_id_from_pdev, (__int64)"wlan_get_dnw_vdev_info", 0x24u);
      if ( priv_fl )
      {
        v33 = (unsigned int *)*(unsigned __int8 *)(priv_fl + 32);
        if ( (_DWORD)v33 != 1 )
        {
          v56 = 16;
          goto LABEL_21;
        }
        v34 = priv_fl;
        comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x2Du);
        if ( comp_private_obj )
        {
          v44 = comp_private_obj;
          if ( (a3 & 1) != 0 )
            v45 = "success";
          else
            v45 = "fail";
          qdf_trace_msg(
            0x98u,
            8u,
            "%s: start bss %s, dnw in progress, vdev %d",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "dnw_handle_bss_start",
            v45,
            a2);
          active_channel = wlan_vdev_get_active_channel(v23);
          if ( active_channel )
          {
            if ( *(_DWORD *)(v44 + 24) == *(_DWORD *)(active_channel + 24) )
            {
              if ( (a3 & 1) != 0 )
              {
                v55 = *(unsigned int *)(v44 + 36);
                if ( (_DWORD)v55 )
                {
                  qdf_trace_msg(
                    0x98u,
                    8u,
                    "%s: dnw state %d vdev %d",
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    "dnw_handle_bss_start",
                    v55,
                    a2);
                }
                else
                {
                  start_dnw_timer(v44 + 8, v47, v48, v49, v50, v51, v52, v53, v54);
                  wlan_dnw_set_state(v44 + 8, 1u, v78, v79, v80, v81, v82, v83, v84, v85);
                }
                v56 = 0;
                goto LABEL_21;
              }
            }
            else
            {
              qdf_trace_msg(
                0x98u,
                8u,
                "%s: Updated BW %d -> %d",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "dnw_handle_bss_start");
            }
            *(_BYTE *)(v34 + 32) = 0;
            *(_QWORD *)(v34 + 24) = 0;
            v67 = *(_BYTE *)(v44 + 19);
            if ( v67 )
            {
              *(_BYTE *)(v44 + 19) = --v67;
              if ( !v67 )
              {
                *(_BYTE *)(v44 + 17) = 0;
                stop_dnw_timer(v44 + 8, v47, v48, v49, v50, v51, v52, v53, v54);
                v67 = *(_BYTE *)(v44 + 19);
              }
            }
            qdf_trace_msg(
              0x98u,
              8u,
              "%s: dnw count %d, vdev %d",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "wlan_dnw_reset",
              v67,
              *(unsigned __int8 *)(v23 + 104));
            v76 = *(unsigned int *)(v44 + 36);
            if ( (unsigned int)v76 > 3 )
              v77 = "UNKNOWN";
            else
              v77 = off_A2B308[v76];
            qdf_trace_msg(
              0x98u,
              8u,
              "%s: old %d new %d, %s->%s",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "wlan_dnw_set_state",
              v76,
              3,
              v77,
              "DNW_STATE_END");
            v56 = 0;
            *(_DWORD *)(v44 + 36) = 3;
            goto LABEL_21;
          }
          qdf_trace_msg(
            0x98u,
            8u,
            "%s: Couldn't get vdev active channel",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "dnw_handle_bss_start");
          v56 = 16;
LABEL_21:
          wlan_objmgr_vdev_release_ref(v23, 0x60u, v33, v25, v26, v27, v28, v29, v30, v31, v32);
          return v56;
        }
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: NULL pre cac pdev priv",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "wlan_get_dnw_pdev_info");
        v65 = "%s: NULL dnw pdev info";
      }
      else
      {
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: NULL pre cac vdev priv",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wlan_get_dnw_vdev_info");
        v65 = "%s: NULL dnw vdev info";
      }
      qdf_trace_msg(0x98u, 2u, v65, v57, v58, v59, v60, v61, v62, v63, v64, "dnw_handle_bss_start");
      v56 = 4;
      goto LABEL_21;
    }
    qdf_trace_msg(0x98u, 2u, "%s: null vdev", v15, v16, v17, v18, v19, v20, v21, v22, "dnw_handle_bss_start");
    return 16;
  }
  else
  {
    qdf_trace_msg(0x98u, 2u, "%s: null pdev", a4, a5, a6, a7, a8, a9, a10, a11, "dnw_handle_bss_start");
    return 4;
  }
}
