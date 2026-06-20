__int64 __fastcall wma_delete_sta(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w21
  int v12; // w25
  __int64 htc_hdl; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 *v23; // x20
  __int64 v24; // x9
  _BOOL4 v25; // w8
  int v26; // w9
  bool v28; // w9
  __int64 result; // x0
  int v30; // w24
  unsigned int v31; // w23
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
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  _BOOL4 v56; // w22
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x23
  unsigned int *v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x23
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned __int8 v84; // w1
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  int v101; // w8
  int v102; // w4
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  int v111; // w8
  unsigned int v112; // w8
  __int64 v113; // x9
  __int64 v114; // x8
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  unsigned int v147; // w1
  __int64 v148; // x0
  __int64 *v150; // x0
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  const char *v192; // x2
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  unsigned int v206; // w20
  unsigned int v207; // w20
  unsigned int v209; // w20
  unsigned int v210; // w20

  v11 = *(unsigned __int8 *)(a2 + 10);
  v12 = *(unsigned __int8 *)(a2 + 8);
  htc_hdl = lmac_get_htc_hdl(*(_QWORD *)(a1 + 24), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !htc_hdl )
    return qdf_trace_msg(0x36u, 2u, "%s: HTC handle is NULL", v15, v16, v17, v18, v19, v20, v21, v22, "wma_delete_sta");
  v23 = (__int64 *)htc_hdl;
  if ( *(unsigned __int16 *)(a1 + 162) <= v11 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid vdev_id %hu",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_is_vdev_in_ap_mode",
      v11);
    v25 = 1;
  }
  else
  {
    v24 = *(_QWORD *)(a1 + 520) + 488LL * v11;
    v25 = 1;
    if ( *(_DWORD *)(v24 + 164) == 1 )
    {
      v26 = *(_DWORD *)(v24 + 168);
      v28 = v26 == 3 || v26 == 0;
      v25 = !v28;
    }
  }
  v30 = *(unsigned __int8 *)(a2 + 11);
  if ( v30 == 5 )
    v31 = 3;
  else
    v31 = v25;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev %d oper_mode %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wma_delete_sta",
    v11,
    v31);
  if ( v31 )
  {
    if ( v31 == 3 )
    {
      result = wma_delete_sta_req_ndi_mode(a1, a2);
      v56 = result == 0;
      goto LABEL_56;
    }
    if ( wlan_cm_is_roam_sync_in_progress(*(_QWORD *)(a1 + 24), v11) )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: LFR3: Del STA on vdev_id %d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "wma_delete_sta",
        v11);
      return _qdf_mem_free(a2);
    }
    result = wmi_service_enabled(*(_QWORD *)a1, 0x9Cu, v40, v41, v42, v43, v44, v45, v46, v47);
    if ( (result & 1) != 0 )
    {
      result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                 *(_QWORD *)(a1 + 24),
                 *(unsigned __int8 *)(a2 + 10),
                 8);
      if ( result )
      {
        v65 = result;
        if ( (ucfg_pmo_get_moddtim_user_enable(result) & 1) != 0 )
          v67 = ucfg_pmo_set_moddtim_user_enable(v65, 0);
        result = wlan_objmgr_vdev_release_ref(v65, 8u, v66, v67, v68, v69, v70, v71, v72, v73, v74);
      }
    }
    *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * *(unsigned __int8 *)(a2 + 10) + 212) = 0;
    if ( *(_BYTE *)(a2 + 11) == 4 )
    {
      result = _qdf_mem_malloc(0x444u, "wma_del_tdls_sta", 6068);
      if ( result )
      {
        v75 = result;
        *(_DWORD *)(result + 12) = 2;
        *(_DWORD *)result = *(unsigned __int8 *)(a2 + 10);
        *(_BYTE *)(result + 1088) = *(_BYTE *)(a2 + 8) != 0;
        qdf_mem_copy((void *)(result + 4), (const void *)(a2 + 12), 6u);
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: sending tdls_peer_state for peer mac: %02x:%02x:%02x:**:**:%02x, peerState: %d",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "wma_del_tdls_sta",
          *(unsigned __int8 *)(v75 + 4),
          *(unsigned __int8 *)(v75 + 5),
          *(unsigned __int8 *)(v75 + 6),
          *(unsigned __int8 *)(v75 + 9),
          *(_DWORD *)(v75 + 12));
        result = wma_update_tdls_peer_state(a1, v75);
        if ( (result & 0x80000000) != 0 )
        {
          result = qdf_trace_msg(
                     0x36u,
                     2u,
                     "%s: wma_update_tdls_peer_state returned failure",
                     v48,
                     v49,
                     v50,
                     v51,
                     v52,
                     v53,
                     v54,
                     v55,
                     "wma_del_tdls_sta");
          v102 = 16;
        }
        else
        {
          if ( !*(_BYTE *)(a2 + 8)
            || (result = wmi_service_enabled(*(_QWORD *)a1, 0x6Eu, v48, v49, v50, v51, v52, v53, v54, v55),
                (result & 1) == 0) )
          {
LABEL_54:
            if ( v12 )
              goto LABEL_55;
            goto LABEL_23;
          }
          v84 = *(_BYTE *)(a2 + 10);
          *(_DWORD *)(a2 + 4) = 0;
          if ( wma_fill_hold_req((__int64 *)a1, v84, 0x1023u, 2u, (const void *)(a2 + 12), a2, 0x1F40u) )
          {
            result = wma_acquire_wakelock(a1 + 3128, 3000);
            if ( v12 )
              goto LABEL_55;
            goto LABEL_23;
          }
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Failed to allocate vdev_id %d",
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            "wma_del_tdls_sta",
            *(unsigned __int8 *)(a2 + 10));
          result = wma_remove_req(a1, *(_BYTE *)(a2 + 10), 2u, v193, v194, v195, v196, v197, v198, v199, v200);
          v102 = 2;
        }
      }
      else
      {
        v102 = 2;
      }
      v111 = *(unsigned __int8 *)(a2 + 8);
      *(_DWORD *)(a2 + 4) = v102;
      if ( !v111 )
        goto LABEL_54;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Sending del rsp to umac (status: %d)",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wma_del_tdls_sta");
    }
    else
    {
      v101 = *(unsigned __int8 *)(a2 + 8);
      *(_DWORD *)(a2 + 4) = 0;
      if ( !v101 )
        goto LABEL_54;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: vdev_id %d status %d",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wma_delete_sta_req_sta_mode",
        *(unsigned __int8 *)(a2 + 10),
        0);
    }
    result = wma_send_msg_high_priority(a1, 4132, a2, 0);
    goto LABEL_54;
  }
  if ( (unsigned int)wma_remove_peer(
                       (__int64 *)a1,
                       (const void *)(a2 + 12),
                       *(unsigned __int8 *)(a2 + 10),
                       0,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38,
                       v39) )
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: wma_remove_peer failed",
               v57,
               v58,
               v59,
               v60,
               v61,
               v62,
               v63,
               v64,
               "wma_delete_sta_req_ap_mode");
    *(_DWORD *)(a2 + 4) = 16;
  }
  else
  {
    *(_DWORD *)(a2 + 4) = 0;
    result = wmi_service_enabled(*(_QWORD *)a1, 0x6Eu, v57, v58, v59, v60, v61, v62, v63, v64);
    if ( (result & 1) != 0 )
    {
      if ( wma_fill_hold_req((__int64 *)a1, *(_BYTE *)(a2 + 10), 0x1023u, 2u, (const void *)(a2 + 12), a2, 0x1F40u) )
      {
        result = wma_acquire_wakelock(a1 + 3128, 3000);
        goto LABEL_46;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to allocate request. vdev_id %d",
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        "wma_delete_sta_req_ap_mode",
        *(unsigned __int8 *)(a2 + 10));
      result = wma_remove_req(a1, *(_BYTE *)(a2 + 10), 2u, v103, v104, v105, v106, v107, v108, v109, v110);
      *(_DWORD *)(a2 + 4) = 2;
    }
  }
  if ( *(_BYTE *)(a2 + 8) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Sending del rsp to umac (status: %d)",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "wma_delete_sta_req_ap_mode",
      *(unsigned int *)(a2 + 4));
    result = wma_send_msg_high_priority(a1, 4132, a2, 0);
  }
LABEL_46:
  if ( v12 )
    goto LABEL_55;
  result = wmi_service_enabled(*(_QWORD *)a1, 0x6Eu, v48, v49, v50, v51, v52, v53, v54, v55);
  if ( (result & 1) != 0 && !*(_DWORD *)(a2 + 4) )
    goto LABEL_55;
LABEL_23:
  result = _qdf_mem_free(a2);
LABEL_55:
  v56 = 1;
LABEL_56:
  v112 = *(unsigned __int16 *)(a1 + 162);
  if ( v112 > v11 )
  {
    v113 = *(_QWORD *)(a1 + 520) + 488LL * v11;
    if ( *(_DWORD *)(v113 + 164) == 1 && !*(_DWORD *)(v113 + 168) )
    {
      if ( (wlan_pmo_get_sap_mode_bus_suspend(*(_QWORD *)(a1 + 24)) & 1) != 0
        && (wmi_service_enabled(*(_QWORD *)a1, 0xE7u, v151, v152, v153, v154, v155, v156, v157, v158) & 1) != 0 )
      {
        qdf_trace_msg(0x31u, 8u, "%s: sap d3 wow", v159, v160, v161, v162, v163, v164, v165, v166, "wma_delete_sta");
        _X8 = (unsigned int *)(a1 + 3956);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v209 = __ldxr(_X8);
          v210 = v209 - 1;
        }
        while ( __stlxr(v210, _X8) );
        __dmb(0xBu);
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: sap d3 wow %d client connected",
          v167,
          v168,
          v169,
          v170,
          v171,
          v172,
          v173,
          v174,
          "wma_sap_d3_wow_client_disconnect",
          v210);
        if ( v210 != 8 )
          goto LABEL_83;
        qdf_trace_msg(
          0x31u,
          4u,
          "%s: max clients disconnected release sap d3 wow wake lock",
          v176,
          v177,
          v178,
          v179,
          v180,
          v181,
          v182,
          v183,
          "wma_sap_d3_wow_client_disconnect");
        v148 = a1 + 3968;
        v147 = 27;
LABEL_79:
        qdf_wake_lock_release(v148, v147);
LABEL_83:
        v150 = (__int64 *)(a1 + 3336);
        return qdf_runtime_pm_allow_suspend(v150);
      }
      htc_vote_link_down(v23, 1);
      v192 = "%s: sap d0 wow";
LABEL_82:
      qdf_trace_msg(0x31u, 4u, v192, v184, v185, v186, v187, v188, v189, v190, v191, "wma_delete_sta");
      goto LABEL_83;
    }
    if ( v112 > v11 )
      goto LABEL_60;
LABEL_68:
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Invalid vdev_id %hu",
               v48,
               v49,
               v50,
               v51,
               v52,
               v53,
               v54,
               v55,
               "wma_is_vdev_in_go_mode",
               v11);
    goto LABEL_69;
  }
  result = qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid vdev_id %hu",
             v48,
             v49,
             v50,
             v51,
             v52,
             v53,
             v54,
             v55,
             "wma_is_vdev_in_sap_mode",
             v11);
  if ( *(unsigned __int16 *)(a1 + 162) <= v11 )
    goto LABEL_68;
LABEL_60:
  v114 = *(_QWORD *)(a1 + 520) + 488LL * v11;
  if ( *(_DWORD *)(v114 + 164) == 1 && *(_DWORD *)(v114 + 168) == 3 )
  {
    if ( (wlan_pmo_get_go_mode_bus_suspend(*(_QWORD *)(a1 + 24)) & 1) != 0
      && (wmi_service_enabled(*(_QWORD *)a1, 0xE8u, v115, v116, v117, v118, v119, v120, v121, v122) & 1) != 0 )
    {
      qdf_trace_msg(0x31u, 4u, "%s: p2p go d3 wow", v123, v124, v125, v126, v127, v128, v129, v130, "wma_delete_sta");
      _X8 = (unsigned int *)(a1 + 3960);
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v206 = __ldxr(_X8);
        v207 = v206 - 1;
      }
      while ( __stlxr(v207, _X8) );
      __dmb(0xBu);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: go d3 wow %d client connected",
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        "wma_go_d3_wow_client_disconnect",
        v207);
      if ( v207 != 8 )
        goto LABEL_83;
      qdf_trace_msg(
        0x31u,
        4u,
        "%s: max clients disconnected release go d3 wow wake lock",
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        "wma_go_d3_wow_client_disconnect");
      v147 = 28;
      v148 = a1 + 4168;
      goto LABEL_79;
    }
    htc_vote_link_down(v23, 2);
    v192 = "%s: p2p go d0 wow";
    goto LABEL_82;
  }
LABEL_69:
  if ( v30 == 5 && v56 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: allow runtime pm and vote for link down",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "wma_delete_sta");
    htc_vote_link_down(v23, 3);
    v150 = (__int64 *)(a1 + 3344);
    return qdf_runtime_pm_allow_suspend(v150);
  }
  return result;
}
