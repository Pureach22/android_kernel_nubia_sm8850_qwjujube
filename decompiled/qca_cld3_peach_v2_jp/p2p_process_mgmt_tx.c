__int64 __fastcall p2p_process_mgmt_tx(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x20
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  unsigned int v29; // w1
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 result; // x0
  unsigned __int8 *v56; // x8
  __int64 v57; // x9
  char *v58; // x4
  int v59; // w10
  unsigned int v60; // w8
  int v61; // w8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  const char *v70; // x2
  __int64 v71; // x23
  __int64 v72; // x0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w22
  __int64 v82; // x21
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned __int64 v91; // x8
  __int64 v92; // x5
  char v93; // w23
  unsigned int *v94; // x8
  unsigned int *v95; // x8
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x0
  unsigned int *v105; // x8
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  int v114; // w23
  bool is_vdev_connected; // w21
  int v116; // w8
  _DWORD *current_roc_ctx; // x0
  __int64 v118; // x1
  int v119; // w8
  _DWORD *v120; // x21
  unsigned int v121; // w8
  unsigned int restarted; // w0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  unsigned int v131; // w21
  const char *v132; // x2
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  const char *v141; // x2
  unsigned int v142; // w1
  __int64 v143; // x23
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  _DWORD *v152; // x21
  __int64 v153; // x8
  __int64 v154; // x22
  __int64 v155; // [xsp+0h] [xbp-40h]

  if ( !a1 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: null tx action context", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_tx_context_check_valid");
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: invalid tx action context",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "p2p_process_mgmt_tx");
    return 4;
  }
  v9 = *(_QWORD **)(a1 + 16);
  if ( !v9 )
  {
    v38 = "%s: null p2p soc private object";
LABEL_11:
    qdf_trace_msg(0x4Eu, 2u, v38, a2, a3, a4, a5, a6, a7, a8, a9, "p2p_tx_context_check_valid");
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: invalid tx action context",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "p2p_process_mgmt_tx");
    if ( *(_QWORD *)(a1 + 48) )
    {
      p2p_send_tx_conf(a1, 0, v47, v48, v49, v50, v51, v52, v53, v54);
      _qdf_mem_free(*(_QWORD *)(a1 + 48));
    }
    _qdf_mem_free(a1);
    return 4;
  }
  if ( !*v9 )
  {
    v38 = "%s: null p2p soc object";
    goto LABEL_11;
  }
  v11 = *(_QWORD *)(a1 + 48);
  if ( !v11 )
  {
    v38 = "%s: null tx buffer";
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, tx_ctx:%pK, vdev_id:%d, scan_id:%d, roc_cookie:%llx, freq:%d, buf:%pK, len:%d, off_chan:%d, cck:%d, ack"
    ":%d, duration:%d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_process_mgmt_tx",
    *(_QWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 44),
    v11,
    *(_DWORD *)(a1 + 56),
    *(unsigned __int8 *)(a1 + 60),
    *(unsigned __int8 *)(a1 + 61),
    *(unsigned __int8 *)(a1 + 62),
    *(_DWORD *)(a1 + 64));
  if ( (unsigned int)p2p_get_frame_info(
                       *(unsigned __int8 **)(a1 + 48),
                       *(_DWORD *)(a1 + 56),
                       a1 + 240,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19) )
  {
    v28 = "%s: unsupported frame";
    v29 = 2;
LABEL_77:
    qdf_trace_msg(0x4Eu, v29, v28, v20, v21, v22, v23, v24, v25, v26, v27, "p2p_process_mgmt_tx");
    v131 = 4;
LABEL_78:
    p2p_send_tx_conf(a1, 0, v133, v134, v135, v136, v137, v138, v139, v140);
    qdf_idr_remove((__int64)(v9 + 28), *(_DWORD *)(a1 + 40));
    _qdf_mem_free(*(_QWORD *)(a1 + 48));
    _qdf_mem_free(a1);
    return v131;
  }
  v56 = *(unsigned __int8 **)(a1 + 48);
  if ( v56 == (unsigned __int8 *)-4LL )
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: invalid p2p_soc_obj:%pK or tx_frame_info:%pK or mac_to:%pK",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "p2p_tx_update_connection_status",
      v9,
      a1 + 240,
      0);
    goto LABEL_36;
  }
  v57 = *(unsigned int *)(a1 + 248);
  if ( (_DWORD)v57 != 17 )
  {
    if ( *(_DWORD *)(a1 + 240) == 1 )
    {
      v58 = "Not support frame";
    }
    else if ( *(_DWORD *)(a1 + 244) == 14 )
    {
      v58 = "Not support sub frame";
    }
    else
    {
      v59 = *(_DWORD *)(a1 + 252);
      if ( v59 == 1 )
      {
        v58 = "P2P action presence request";
      }
      else if ( v59 == 2 )
      {
        v58 = "P2P action presence response";
      }
      else
      {
        v58 = (unsigned int)v57 > 0x10 ? "Other frame" : off_9FDC68[v57];
      }
    }
    LODWORD(v155) = v56[9];
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: %s ---> OTA to %02x:%02x:%02x:**:**:%02x",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "p2p_tx_update_connection_status",
      v58,
      v56[4],
      v56[5],
      v56[6],
      v155);
    v60 = *(_DWORD *)(a1 + 248);
    if ( v60 <= 7 )
    {
      v61 = 1 << v60;
      if ( (v61 & 0x8B) != 0 )
      {
        p2p_status_update((__int64)v9, 1);
        v70 = "%s: [P2P State]Inactive state to GO negotiation progress state";
      }
      else
      {
        if ( (v61 & 0x14) == 0 )
          goto LABEL_36;
        p2p_status_update((__int64)v9, 2);
        v70 = "%s: [P2P State]GO nego progress to GO nego completed state";
      }
      qdf_trace_msg(0x4Eu, 8u, v70, v62, v63, v64, v65, v66, v67, v68, v69, "p2p_tx_update_connection_status");
    }
  }
LABEL_36:
  v71 = **(_QWORD **)(a1 + 16);
  v72 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          v71,
          *(unsigned int *)(a1 + 24),
          15);
  if ( !v72 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: null vdev object", v73, v74, v75, v76, v77, v78, v79, v80, "p2p_vdev_check_valid");
LABEL_76:
    v28 = "%s: invalid vdev or vdev mode";
    v29 = 8;
    goto LABEL_77;
  }
  v81 = *(_DWORD *)(v72 + 16);
  v82 = v72;
  qdf_trace_msg(0x4Eu, 8u, "%s: vdev mode:%d", v73, v74, v75, v76, v77, v78, v79, v80, "p2p_vdev_check_valid", v81);
  if ( !v81 )
  {
    v94 = (unsigned int *)*(unsigned int *)(a1 + 244);
    if ( (_DWORD)v94 == 5 )
    {
      if ( *(_DWORD *)(a1 + 264) != 7 )
      {
        v92 = 5;
        goto LABEL_50;
      }
      if ( (p2p_is_sta_vdev_usage_allowed_for_p2p_dev(v71) & 1) == 0 )
      {
        v92 = *(unsigned int *)(a1 + 244);
        goto LABEL_50;
      }
    }
    wlan_objmgr_vdev_release_ref(v82, 0xFu, v94, v83, v84, v85, v86, v87, v88, v89, v90);
    goto LABEL_59;
  }
  v91 = v81 & 0xFFFFFFFD;
  if ( (_DWORD)v91 != 1 )
  {
    v93 = 1;
    goto LABEL_51;
  }
  v92 = *(unsigned int *)(a1 + 244);
  v93 = 1;
  if ( (unsigned int)v92 > 0xC )
    goto LABEL_51;
  v91 = (unsigned int)(1 << v92);
  if ( (v91 & 0x1420) == 0 )
    goto LABEL_51;
LABEL_50:
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: drop frame, mode:%d, sub type:%d",
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    "p2p_vdev_check_valid",
    v81,
    v92);
  v93 = 0;
LABEL_51:
  if ( v81 == 1 )
  {
    v91 = *(unsigned int *)(a1 + 244);
    if ( (_DWORD)v91 == 13 )
    {
      v91 = *(unsigned int *)(a1 + 248);
      if ( (_DWORD)v91 == 17 )
      {
        v91 = *(unsigned int *)(a1 + 252);
        if ( (_DWORD)v91 == 3 )
        {
          if ( (*(_BYTE *)(v82 + 55) & 0x40) == 0 || (v91 = *(unsigned __int8 *)(a1 + 60), (_DWORD)v91 == 1) )
          {
            qdf_trace_msg(
              0x4Eu,
              8u,
              "%s: drop action frame for SAP",
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              "p2p_vdev_check_valid");
            wlan_objmgr_vdev_release_ref(v82, 0xFu, v95, v96, v97, v98, v99, v100, v101, v102, v103);
            goto LABEL_76;
          }
        }
      }
    }
  }
  wlan_objmgr_vdev_release_ref(v82, 0xFu, (unsigned int *)v91, v83, v84, v85, v86, v87, v88, v89, v90);
  if ( (v93 & 1) == 0 )
    goto LABEL_76;
LABEL_59:
  if ( *(_DWORD *)(a1 + 244) == 5 && (*(_BYTE *)(a1 + 62) & 1) == 0 )
  {
    qdf_trace_msg(0x4Eu, 8u, "%s: Force set no ack to 1", v20, v21, v22, v23, v24, v25, v26, v27, "p2p_process_mgmt_tx");
    *(_BYTE *)(a1 + 62) = 1;
  }
  v104 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           *v9,
           *(unsigned int *)(a1 + 24),
           15);
  if ( !v104 )
  {
    v141 = "%s: null vdev object";
    v142 = 2;
    goto LABEL_87;
  }
  v114 = *(_DWORD *)(v104 + 16);
  if ( v114 || (v105 = (unsigned int *)*(unsigned int *)(a1 + 264), (_DWORD)v105 == 7) )
  {
    is_vdev_connected = 0;
  }
  else
  {
    v154 = v104;
    is_vdev_connected = wlan_cm_is_vdev_connected(v104, v106, v107, v108, v109, v110, v111, v112, v113);
    v104 = v154;
  }
  wlan_objmgr_vdev_release_ref(v104, 0xFu, v105, v106, v107, v108, v109, v110, v111, v112, v113);
  v116 = *(_DWORD *)(a1 + 44);
  if ( *(_BYTE *)(a1 + 60) != 1 )
  {
    if ( v116 )
    {
LABEL_82:
      if ( (v116 | v114) != 0 || is_vdev_connected )
      {
        result = p2p_execute_tx_action_frame(a1, v106, v107, v108, v109, v110, v111, v112, v113);
        if ( (_DWORD)result )
        {
          v131 = result;
          v143 = jiffies;
          if ( p2p_process_mgmt_tx___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: execute tx fail",
              v133,
              v134,
              v135,
              v136,
              v137,
              v138,
              v139,
              v140,
              "p2p_process_mgmt_tx");
            p2p_process_mgmt_tx___last_ticks = v143;
          }
          goto LABEL_78;
        }
        return result;
      }
      v141 = "%s: chan freq is zero, drop tx mgmt frame";
      v142 = 8;
LABEL_87:
      qdf_trace_msg(0x4Eu, v142, v141, v106, v107, v108, v109, v110, v111, v112, v113, "p2p_process_mgmt_tx");
      v131 = 0;
      goto LABEL_78;
    }
LABEL_81:
    p2p_check_and_update_channel(a1);
    v116 = *(_DWORD *)(a1 + 44);
    goto LABEL_82;
  }
  if ( !v116 )
    goto LABEL_81;
  current_roc_ctx = (_DWORD *)p2p_find_current_roc_ctx(v9);
  v118 = *(unsigned int *)(a1 + 44);
  if ( current_roc_ctx && current_roc_ctx[10] == (_DWORD)v118 )
  {
    v119 = current_roc_ctx[56];
    if ( (unsigned int)(v119 - 1) < 2 )
      goto LABEL_98;
    if ( v119 == 3 )
    {
      v120 = current_roc_ctx;
      p2p_adjust_tx_wait(a1);
      v121 = *(_DWORD *)(a1 + 64);
      if ( v120[12] < v121 )
        v120[12] = v121;
      restarted = p2p_restart_roc_timer(v120);
      *((_QWORD *)v120 + 4) = a1;
      if ( restarted )
      {
        v131 = restarted;
        v132 = "%s: restart roc timer fail";
LABEL_100:
        qdf_trace_msg(0x4Eu, 2u, v132, v123, v124, v125, v126, v127, v128, v129, v130, "p2p_process_mgmt_tx");
        goto LABEL_78;
      }
      result = p2p_execute_tx_action_frame(a1, v123, v124, v125, v126, v127, v128, v129, v130);
      if ( (_DWORD)result )
      {
        v131 = result;
        v132 = "%s: execute tx fail";
        goto LABEL_100;
      }
      return result;
    }
  }
  current_roc_ctx = (_DWORD *)p2p_find_roc_by_chan_freq(v9, v118);
  if ( current_roc_ctx && !current_roc_ctx[56] )
  {
LABEL_98:
    *(_QWORD *)(a1 + 32) = current_roc_ctx;
    result = qdf_list_insert_back(v9 + 4, (_QWORD *)a1);
    if ( (_DWORD)result )
    {
      v131 = result;
      v132 = "%s: Failed to insert off chan tx context to wait roc req queue";
      goto LABEL_100;
    }
    return result;
  }
  if ( !*(_DWORD *)(a1 + 64) )
  {
    v152 = current_roc_ctx;
    *(_DWORD *)(a1 + 64) = 200;
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: use default wait %d",
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      "p2p_process_mgmt_tx",
      200);
    current_roc_ctx = v152;
  }
  if ( current_roc_ctx )
  {
    v153 = *(_QWORD *)(a1 + 48);
    if ( v153 != -10 )
      qdf_mem_copy(current_roc_ctx + 58, (const void *)(v153 + 10), 6u);
  }
  result = p2p_roc_req_for_tx_action(a1);
  if ( (_DWORD)result )
  {
    v131 = result;
    v132 = "%s: Failed to request roc before off chan tx";
    goto LABEL_100;
  }
  return result;
}
