__int64 __fastcall cm_roam_scan_filter(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        char a4,
        unsigned __int8 a5,
        __int64 a6)
{
  __int64 result; // x0
  __int64 v13; // x21
  __int64 v14; // x19
  unsigned __int8 *rso_user_config_fl; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int8 *v25; // x22
  int v26; // w26
  int v27; // w8
  int v28; // w25
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned __int64 v93; // x24
  unsigned __int8 *v94; // x25
  __int64 v95; // x4
  __int64 v96; // x5
  __int64 v97; // x6
  __int64 v98; // x7
  unsigned __int64 v99; // x22
  unsigned __int8 *v100; // x25
  __int64 v101; // x7
  __int64 v102; // x5
  __int64 v103; // x6
  int v104; // w8
  _BOOL4 v105; // w27
  unsigned __int8 bssid_reject_list; // w0
  __int64 v107; // [xsp+0h] [xbp-10h]
  __int64 v108; // [xsp+8h] [xbp-8h]

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    v13 = result;
    *(_BYTE *)a6 = a5;
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 77);
    if ( result )
    {
      v14 = result;
      rso_user_config_fl = (unsigned __int8 *)wlan_cm_get_rso_user_config_fl(result, "cm_roam_scan_filter", 2790);
      if ( !rso_user_config_fl )
        return wlan_objmgr_vdev_release_ref(v14, 0x4Du, v16, v17, v18, v19, v20, v21, v22, v23, v24);
      v25 = rso_user_config_fl;
      if ( a4 == 2 )
      {
        if ( a5 == 26 )
          v26 = *rso_user_config_fl;
        else
          v26 = 0;
        v27 = *(unsigned __int8 *)(v13 + 2568);
        v28 = 6;
        goto LABEL_13;
      }
      if ( a5 > 0x1Cu )
      {
        if ( a5 == 40 )
        {
          if ( a4 != 1 )
          {
LABEL_55:
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: Roam Filter need not be sent, no need to fill parameters",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "cm_roam_scan_filter");
            return wlan_objmgr_vdev_release_ref(v14, 0x4Du, v16, v17, v18, v19, v20, v21, v22, v23, v24);
          }
          v26 = *rso_user_config_fl;
          v105 = *rso_user_config_fl != 0;
          cm_add_denylist_ap_list(a2, a6 + 8);
          v28 = (*(_DWORD *)(a6 + 16) != 0) | (2 * v105);
          *(_BYTE *)(a6 + 500) = 1;
          bssid_reject_list = dlm_get_bssid_reject_list(a2, a6 + 520, 10, 4);
          v27 = 0;
          *(_DWORD *)(a6 + 516) = bssid_reject_list;
LABEL_13:
          *(_BYTE *)(a6 + 12) = a3;
          *(_DWORD *)(a6 + 8) = v28;
          *(_DWORD *)(a6 + 20) = v26;
          *(_DWORD *)(a6 + 24) = v27;
          *(_DWORD *)(a6 + 1480) = dlm_get_rssi_denylist_threshold(a2);
          if ( v26 )
          {
            qdf_mem_copy((void *)(a6 + 125), v25 + 2, v25[1]);
            *(_BYTE *)(a6 + 124) = v25[1];
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: SSID %d: %.*s",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "cm_roam_scan_filter",
              0);
            if ( v26 != 1 )
            {
              qdf_mem_copy((void *)(a6 + 158), v25 + 35, v25[34]);
              *(_BYTE *)(a6 + 157) = v25[34];
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: SSID %d: %.*s",
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                "cm_roam_scan_filter",
                1);
              if ( v26 != 2 )
              {
                qdf_mem_copy((void *)(a6 + 191), v25 + 68, v25[67]);
                *(_BYTE *)(a6 + 190) = v25[67];
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "%s: SSID %d: %.*s",
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  "cm_roam_scan_filter",
                  2);
                if ( v26 != 3 )
                {
                  qdf_mem_copy((void *)(a6 + 224), v25 + 101, v25[100]);
                  *(_BYTE *)(a6 + 223) = v25[100];
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: SSID %d: %.*s",
                    v53,
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    "cm_roam_scan_filter",
                    3);
                  if ( v26 != 4 )
                  {
                    qdf_mem_copy((void *)(a6 + 257), v25 + 134, v25[133]);
                    *(_BYTE *)(a6 + 256) = v25[133];
                    qdf_trace_msg(
                      0x68u,
                      8u,
                      "%s: SSID %d: %.*s",
                      v61,
                      v62,
                      v63,
                      v64,
                      v65,
                      v66,
                      v67,
                      v68,
                      "cm_roam_scan_filter",
                      4);
                    if ( v26 != 5 )
                    {
                      qdf_mem_copy((void *)(a6 + 290), v25 + 167, v25[166]);
                      *(_BYTE *)(a6 + 289) = v25[166];
                      qdf_trace_msg(
                        0x68u,
                        8u,
                        "%s: SSID %d: %.*s",
                        v69,
                        v70,
                        v71,
                        v72,
                        v73,
                        v74,
                        v75,
                        v76,
                        "cm_roam_scan_filter",
                        5);
                      if ( v26 != 6 )
                      {
                        qdf_mem_copy((void *)(a6 + 323), v25 + 200, v25[199]);
                        *(_BYTE *)(a6 + 322) = v25[199];
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "%s: SSID %d: %.*s",
                          v77,
                          v78,
                          v79,
                          v80,
                          v81,
                          v82,
                          v83,
                          v84,
                          "cm_roam_scan_filter",
                          6);
                        if ( v26 != 7 )
                        {
                          qdf_mem_copy((void *)(a6 + 356), v25 + 233, v25[232]);
                          *(_BYTE *)(a6 + 355) = v25[232];
                          qdf_trace_msg(
                            0x68u,
                            8u,
                            "%s: SSID %d: %.*s",
                            v85,
                            v86,
                            v87,
                            v88,
                            v89,
                            v90,
                            v91,
                            v92,
                            "cm_roam_scan_filter",
                            7);
                          if ( v26 != 8 )
                            goto LABEL_56;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( *(_DWORD *)(a6 + 24) )
          {
            qdf_mem_copy((void *)(a6 + 388), (const void *)(v13 + 2569), 0x60u);
            qdf_mem_copy((void *)(a6 + 484), (const void *)(v13 + 2665), 0x10u);
          }
          if ( *(_DWORD *)(a6 + 516) )
          {
            v93 = 0;
            v94 = (unsigned __int8 *)(a6 + 520);
            while ( v93 != 10 )
            {
              if ( v94 )
              {
                v95 = *v94;
                v96 = v94[1];
                v97 = v94[2];
                v98 = v94[5];
              }
              else
              {
                v97 = 0;
                v95 = 0;
                v96 = 0;
                v98 = 0;
              }
              LODWORD(v108) = *((_DWORD *)v94 + 16);
              LODWORD(v107) = *((_DWORD *)v94 + 17);
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: RSSI reject BSSID %02x:%02x:%02x:**:**:%02x expected rssi %d remaining duration %d",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "cm_roam_scan_filter",
                v95,
                v96,
                v97,
                v98,
                v107,
                v108);
              ++v93;
              v94 += 96;
              if ( v93 >= *(unsigned int *)(a6 + 516) )
                goto LABEL_31;
            }
LABEL_56:
            __break(0x5512u);
            JUMPOUT(0x2EC774);
          }
LABEL_31:
          if ( *(_DWORD *)(a6 + 24) )
          {
            v99 = 0;
            v100 = (unsigned __int8 *)(a6 + 388);
            while ( v99 != 16 )
            {
              if ( v100 )
              {
                v102 = *v100;
                v103 = v100[1];
                v101 = v100[2];
                v104 = v100[5];
              }
              else
              {
                v101 = 0;
                v102 = 0;
                v103 = 0;
                v104 = 0;
              }
              LODWORD(v108) = *(unsigned __int8 *)(a6 + 484 + v99);
              LODWORD(v107) = v104;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: Preferred Bssid[%d]:%02x:%02x:%02x:**:**:%02x score: %d",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "cm_roam_scan_filter",
                (unsigned int)v99++,
                v102,
                v103,
                v101,
                v107,
                v108);
              v100 += 6;
              if ( v99 >= *(unsigned int *)(a6 + 24) )
                goto LABEL_38;
            }
            goto LABEL_56;
          }
LABEL_38:
          v16 = (unsigned int *)*(unsigned __int8 *)(a6 + 500);
          if ( *(_BYTE *)(a6 + 500) )
          {
            *(_DWORD *)(a6 + 504) = *(_DWORD *)(v13 + 1860);
            *(_DWORD *)(a6 + 508) = *(_DWORD *)(v13 + 1864);
            *(_DWORD *)(a6 + 512) = *(_DWORD *)(v13 + 1868);
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: disallow_dur %d rssi_chan_pen %d num_disallowed_aps %d",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "cm_roam_scan_filter");
          }
          return wlan_objmgr_vdev_release_ref(v14, 0x4Du, v16, v17, v18, v19, v20, v21, v22, v23, v24);
        }
        if ( a5 == 29 )
        {
          cm_add_denylist_ap_list(a2, a6 + 8);
          v26 = 0;
          v27 = 0;
          v28 = 1;
          goto LABEL_13;
        }
      }
      else
      {
        if ( a5 == 26 )
        {
          v26 = *rso_user_config_fl;
LABEL_51:
          v27 = 0;
          v28 = 2;
          goto LABEL_13;
        }
        if ( a5 == 27 )
        {
          v27 = *(unsigned __int8 *)(v13 + 2568);
          v26 = 0;
          v28 = 4;
          goto LABEL_13;
        }
      }
      if ( a4 != 1 )
        goto LABEL_55;
      v26 = *rso_user_config_fl;
      cm_add_denylist_ap_list(a2, a6 + 8);
      if ( *(_DWORD *)(a6 + 16) )
      {
        v27 = 0;
        if ( v26 )
          v28 = 3;
        else
          v28 = 1;
        goto LABEL_13;
      }
      if ( !v26 )
        goto LABEL_55;
      goto LABEL_51;
    }
  }
  return result;
}
