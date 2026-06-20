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
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w8
  __int64 v82; // x9
  __int64 v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // w1
  __int64 v118; // x0
  __int64 *v120; // x0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  const char *v161; // x2
  unsigned int v166; // w20
  unsigned int v167; // w20
  unsigned int v170; // w20
  unsigned int v171; // w20

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
  if ( !v31 )
  {
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
          goto LABEL_34;
        }
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to allocate request. vdev_id %d",
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          "wma_delete_sta_req_ap_mode",
          *(unsigned __int8 *)(a2 + 10));
        result = wma_remove_req(a1, *(_BYTE *)(a2 + 10), 2u, v73, v74, v75, v76, v77, v78, v79, v80);
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
LABEL_34:
    if ( v12 )
      goto LABEL_35;
    result = wmi_service_enabled(*(_QWORD *)a1, 0x6Eu, v48, v49, v50, v51, v52, v53, v54, v55);
    if ( (result & 1) != 0 && !*(_DWORD *)(a2 + 4) )
      goto LABEL_35;
    goto LABEL_25;
  }
  if ( v31 == 3 )
  {
    result = wma_delete_sta_req_ndi_mode(a1, a2);
    v56 = result == 0;
    goto LABEL_36;
  }
  if ( wlan_cm_is_roam_sync_in_progress(*(_QWORD *)(a1 + 24), v11)
    || (unsigned int)mlme_get_roam_state(*(_QWORD *)(a1 + 24), v11) == 6
    || (mlo_is_roaming_in_progress(*(_QWORD *)(a1 + 24), v11) & 1) != 0 )
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
  result = wma_delete_sta_req_sta_mode(a1, a2);
  if ( !v12 )
LABEL_25:
    result = _qdf_mem_free(a2);
LABEL_35:
  v56 = 1;
LABEL_36:
  v81 = *(unsigned __int16 *)(a1 + 162);
  if ( v81 > v11 )
  {
    v82 = *(_QWORD *)(a1 + 520) + 488LL * v11;
    if ( *(_DWORD *)(v82 + 164) == 1 && !*(_DWORD *)(v82 + 168) )
    {
      if ( (wlan_pmo_get_sap_mode_bus_suspend(*(_QWORD *)(a1 + 24)) & 1) != 0
        && (wmi_service_enabled(*(_QWORD *)a1, 0xE7u, v121, v122, v123, v124, v125, v126, v127, v128) & 1) != 0 )
      {
        qdf_trace_msg(0x31u, 8u, "%s: sap d3 wow", v129, v130, v131, v132, v133, v134, v135, v136, "wma_delete_sta");
        _X8 = (unsigned int *)(a1 + 3976);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v170 = __ldxr(_X8);
          v171 = v170 - 1;
        }
        while ( __stlxr(v171, _X8) );
        __dmb(0xBu);
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: sap d3 wow %d client connected",
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          "wma_sap_d3_wow_client_disconnect",
          v171);
        if ( v171 != 8 )
          goto LABEL_66;
        qdf_trace_msg(
          0x31u,
          4u,
          "%s: max clients disconnected release sap d3 wow wake lock",
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          "wma_sap_d3_wow_client_disconnect");
        v118 = a1 + 3984;
        v117 = 27;
LABEL_62:
        qdf_wake_lock_release(v118, v117);
LABEL_66:
        v120 = (__int64 *)(a1 + 3336);
        return qdf_runtime_pm_allow_suspend(v120);
      }
      htc_vote_link_down(v23, 1);
      v161 = "%s: sap d0 wow";
LABEL_65:
      qdf_trace_msg(0x31u, 4u, v161, v153, v154, v155, v156, v157, v158, v159, v160, "wma_delete_sta");
      goto LABEL_66;
    }
    if ( v81 > v11 )
      goto LABEL_40;
LABEL_48:
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
    goto LABEL_49;
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
    goto LABEL_48;
LABEL_40:
  v83 = *(_QWORD *)(a1 + 520) + 488LL * v11;
  if ( *(_DWORD *)(v83 + 164) == 1 && *(_DWORD *)(v83 + 168) == 3 )
  {
    if ( (wlan_pmo_get_go_mode_bus_suspend(*(_QWORD *)(a1 + 24)) & 1) != 0
      && (wmi_service_enabled(*(_QWORD *)a1, 0xE8u, v84, v85, v86, v87, v88, v89, v90, v91) & 1) != 0 )
    {
      qdf_trace_msg(0x31u, 4u, "%s: p2p go d3 wow", v92, v93, v94, v95, v96, v97, v98, v99, "wma_delete_sta");
      _X8 = (unsigned int *)(a1 + 3980);
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v166 = __ldxr(_X8);
        v167 = v166 - 1;
      }
      while ( __stlxr(v167, _X8) );
      __dmb(0xBu);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: go d3 wow %d client connected",
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        "wma_go_d3_wow_client_disconnect",
        v167);
      if ( v167 != 8 )
        goto LABEL_66;
      qdf_trace_msg(
        0x31u,
        4u,
        "%s: max clients disconnected release go d3 wow wake lock",
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        "wma_go_d3_wow_client_disconnect");
      v117 = 28;
      v118 = a1 + 4184;
      goto LABEL_62;
    }
    htc_vote_link_down(v23, 2);
    v161 = "%s: p2p go d0 wow";
    goto LABEL_65;
  }
LABEL_49:
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
    v120 = (__int64 *)(a1 + 3344);
    return qdf_runtime_pm_allow_suspend(v120);
  }
  return result;
}
