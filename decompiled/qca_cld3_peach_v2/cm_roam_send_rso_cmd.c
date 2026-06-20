__int64 __fastcall cm_roam_send_rso_cmd(__int64 a1, __int64 a2, unsigned __int8 a3, unsigned int a4)
{
  unsigned int v6; // w19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x24
  unsigned int v18; // w27
  __int64 psoc_ext_obj_fl; // x0
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x25
  __int64 rso_config_fl; // x0
  __int64 v31; // x26
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w0
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w25
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  unsigned int v68; // w1
  _BOOL4 v70; // w25
  unsigned int *v71; // x8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  _BOOL4 v88; // w8
  const char *v89; // x4
  unsigned __int64 v90; // x8
  bool is_vdev_disconnected; // w0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  const char *v100; // x2
  __int64 v101; // x4
  _BYTE *v102; // x0
  _DWORD *v103; // x24
  _DWORD *v104; // x0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  int v113; // w6
  int v114; // w7
  int v115; // w8
  int v116; // w9
  int v117; // w10
  int v118; // w11
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7

  v6 = a2;
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( !v8 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_id: %d: vdev not found",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "cm_is_rso_allowed",
      (unsigned __int8)v6);
LABEL_16:
    v58 = 16;
    goto LABEL_17;
  }
  v17 = v8;
  v18 = *(unsigned __int8 *)(v8 + 168);
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl
    || (v29 = psoc_ext_obj_fl, (rso_config_fl = wlan_cm_get_rso_config_fl(v17, "cm_roam_cmd_allowed", 4286)) == 0) )
  {
LABEL_15:
    wlan_objmgr_vdev_release_ref(v17, 0x4Du, v20, v21, v22, v23, v24, v25, v26, v27, v28);
    goto LABEL_16;
  }
  v31 = rso_config_fl;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: RSO Command %d, vdev %d, Reason %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "cm_roam_cmd_allowed",
    a3,
    v18,
    (unsigned __int8)a4);
  if ( !cm_is_vdev_connected(v17, v32, v33, v34, v35, v36, v37, v38, v39) && a3 <= 4u && ((1 << a3) & 0x1A) != 0 )
  {
    v67 = "%s: vdev not in connected state and command %d ";
    v68 = 8;
LABEL_14:
    qdf_trace_msg(0x68u, v68, v67, v40, v41, v42, v43, v44, v45, v46, v47, "cm_roam_cmd_allowed", a3);
    goto LABEL_15;
  }
  if ( *(_BYTE *)(v31 + 831) == 1 && (*(_BYTE *)(v29 + 1979) & 1) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: Adaptive 11r Roaming not suppprted by fw",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "cm_roam_cmd_allowed");
    wlan_objmgr_vdev_release_ref(v17, 0x4Du, v71, v72, v73, v74, v75, v76, v77, v78, v79);
    return 0;
  }
  v48 = cm_akm_roam_allowed(a1, v17);
  if ( !v48 )
  {
    if ( (cfg_p2p_is_roam_config_disabled(a1) & 1) != 0 )
    {
      if ( (unsigned int)policy_mgr_mode_specific_connection_count(a1, 2, nullptr) )
        v70 = 1;
      else
        v70 = policy_mgr_mode_specific_connection_count(a1, 3, nullptr) != 0;
    }
    else
    {
      v70 = 0;
    }
    v88 = (cfg_nan_is_roam_config_disabled(a1) & 1) != 0
       && policy_mgr_mode_specific_connection_count(a1, 4, nullptr) != 0;
    if ( (a3 == 4 || a3 == 1) && (v70 || v88) )
    {
      if ( v70 )
        v89 = "p2p";
      else
        v89 = "ndi";
      qdf_trace_msg(
        0x68u,
        4u,
        "%s: roaming not supported for active %s connection",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "cm_roam_cmd_allowed",
        v89);
      goto LABEL_15;
    }
    if ( cm_is_vdev_disconnecting(v17, v80, v81, v82, v83, v84, v85, v86, v87) )
    {
      v90 = a3;
      if ( a3 == 2 || (v90 = (unsigned __int8)a4, (unsigned __int8)a4 == 29) )
      {
LABEL_43:
        wlan_objmgr_vdev_release_ref(v17, 0x4Du, (unsigned int *)v90, v40, v41, v42, v43, v44, v45, v46, v47);
        if ( (wlan_vdev_mlme_get_is_mlo_link(a1, v6) & 1) != 0 )
        {
          v100 = "%s: MLO ROAM: skip RSO cmd for link vdev %d";
          v101 = (unsigned __int8)v6;
        }
        else
        {
          if ( a3 != 2 )
          {
            if ( (cm_roam_is_per_roam_allowed(a1, v6) & 1) != 0 )
            {
              v102 = (_BYTE *)_qdf_mem_malloc(0x30u, "cm_roam_offload_per_config", 4106);
              if ( v102 )
              {
                v103 = v102;
                *v102 = v6;
                v104 = (_DWORD *)mlme_get_psoc_ext_obj_fl(a1);
                if ( v104 )
                {
                  v103[1] = v104[458];
                  v113 = v104[459];
                  v103[2] = v113;
                  v103[3] = v113;
                  v114 = v104[460];
                  v103[4] = v114;
                  v103[5] = v114;
                  v115 = v104[462];
                  v103[8] = v115;
                  v116 = v104[463];
                  v103[9] = v116;
                  v103[10] = v116;
                  v117 = v104[461];
                  v103[6] = v117;
                  v103[7] = v117;
                  v118 = v104[464];
                  v103[11] = v118;
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: PER based roaming configuration enable: %d vdev: %d high_rate_thresh: %d low_rate_thresh: %d rat"
                    "e_thresh_percnt: %d per_rest_time: %d monitor_time: %d min cand rssi: %d",
                    v105,
                    v106,
                    v107,
                    v108,
                    v109,
                    v110,
                    v111,
                    v112,
                    "cm_roam_fill_per_roam_request",
                    v117,
                    v115,
                    v116,
                    v118);
                  if ( (unsigned int)wlan_cm_tgt_send_roam_per_config(a1, v6, v103) )
                    qdf_trace_msg(
                      0x68u,
                      8u,
                      "%s: fail to send roam stop",
                      v119,
                      v120,
                      v121,
                      v122,
                      v123,
                      v124,
                      v125,
                      v126,
                      "cm_roam_offload_per_config");
                  _qdf_mem_free((__int64)v103);
                }
                else
                {
                  _qdf_mem_free((__int64)v103);
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: fail to fill per config",
                    v127,
                    v128,
                    v129,
                    v130,
                    v131,
                    v132,
                    v133,
                    v134,
                    "cm_roam_offload_per_config");
                }
              }
            }
            if ( a3 > 3u )
            {
              if ( a3 == 4 )
                return (unsigned int)cm_roam_update_config_req(a1, v6, a4);
              if ( a3 == 5 )
                return (unsigned int)cm_roam_abort_req(a1, v6);
            }
            else
            {
              if ( a3 == 1 )
                return (unsigned int)cm_roam_start_req(a1, v6, a4);
              if ( a3 == 3 )
                return (unsigned int)cm_roam_restart_req(a1, v6, a4);
            }
          }
          v100 = "%s: ROAM: invalid RSO command %d";
          v101 = a3;
        }
        qdf_trace_msg(0x68u, 8u, v100, v92, v93, v94, v95, v96, v97, v98, v99, "cm_roam_send_rso_cmd", v101);
        return 0;
      }
    }
    else
    {
      is_vdev_disconnected = cm_is_vdev_disconnected(v17, v40, v41, v42, v43, v44, v45, v46, v47);
      v90 = (unsigned __int8)a4;
      if ( (unsigned __int8)a4 == 29 )
        goto LABEL_43;
      v90 = a3;
      if ( a3 == 2 || !is_vdev_disconnected )
        goto LABEL_43;
    }
    v67 = "%s: Scan Command not sent to FW and cmd=%d";
    v68 = 4;
    goto LABEL_14;
  }
  v58 = v48;
  wlan_objmgr_vdev_release_ref(v17, 0x4Du, v49, v50, v51, v52, v53, v54, v55, v56, v57);
  if ( v58 == 11 )
    return 0;
LABEL_17:
  qdf_trace_msg(0x68u, 8u, "%s: ROAM: not allowed", v59, v60, v61, v62, v63, v64, v65, v66, "cm_roam_send_rso_cmd");
  return v58;
}
