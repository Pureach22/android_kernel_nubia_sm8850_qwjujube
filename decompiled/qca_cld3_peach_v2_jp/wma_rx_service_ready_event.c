__int64 __fastcall wma_rx_service_ready_event(
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
  _QWORD *context; // x23
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x20
  unsigned int *v31; // x25
  _QWORD *v32; // x21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w4
  const char *v50; // x2
  __int64 v52; // x0
  int v53; // w1
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  char v95; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  char v168; // w0
  double wakeup_packet; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  char v177; // w0
  __int64 v178; // x8
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  char v187; // w0
  __int64 v188; // x8
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  char v197; // w0
  __int64 v198; // x8
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  double v207; // d0
  double v208; // d1
  double v209; // d2
  double v210; // d3
  double v211; // d4
  double v212; // d5
  double v213; // d6
  double v214; // d7

  context = _cds_get_context(71, (__int64)"wma_rx_service_ready_event", a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", v13, v14, v15, v16, v17, v18, v19, v20, "wma_rx_service_ready_event");
  if ( !a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "__wma_validate_handle",
      "wma_rx_service_ready_event");
    return 4294967274LL;
  }
  v29 = *(_QWORD *)(a1 + 24);
  if ( !v29 || (v30 = *(_QWORD *)(v29 + 2800)) == 0 )
  {
    v50 = "%s: target psoc info is NULL";
LABEL_10:
    qdf_trace_msg(0x36u, 2u, v50, v21, v22, v23, v24, v25, v26, v27, v28, "wma_rx_service_ready_event");
    return 4294967274LL;
  }
  if ( !a2 )
  {
    v50 = "%s: Invalid arguments";
    goto LABEL_10;
  }
  v31 = *(unsigned int **)a2;
  if ( !*(_QWORD *)a2 )
  {
    v50 = "%s: Invalid buffer";
    goto LABEL_10;
  }
  v32 = *(_QWORD **)(v30 + 16);
  if ( (unsigned int)_wmi_validate_handle(
                       (__int64)v32,
                       (__int64)"wma_rx_service_ready_event",
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28) )
    return 4294967274LL;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMA <-- WMI_SERVICE_READY_EVENTID",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "wma_rx_service_ready_event");
  v49 = v31[29];
  if ( v49 > *(_DWORD *)(a2 + 72) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: FW dbs_hw_mode entry %d more than value %d in TLV hdr",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "wma_rx_service_ready_event");
    return 4294967274LL;
  }
  policy_mgr_init_dbs_hw_mode(*(_QWORD *)(a1 + 24), v49, *(const void **)(a2 + 64));
  wma_init_scan_fw_mode_config(*(_QWORD *)(a1 + 24), 0, 0);
  qdf_mem_copy((void *)(a1 + 456), *(const void **)(a2 + 16), 0x3Cu);
  v52 = *(_QWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 616) = v31[13];
  v53 = *(_DWORD *)(v30 + 740);
  *(_DWORD *)(a1 + 2916) = v53;
  policy_mgr_update_new_hw_mode_index(v52, v53);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Firmware default hw mode index : %d",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "wma_rx_service_ready_event",
    *(unsigned int *)(v30 + 740));
  qdf_trace_msg(
    0x36u,
    4u,
    "%s: Firmware build version : %08x",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    "wma_rx_service_ready_event",
    v31[1]);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: FW fine time meas cap: 0x%x",
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    "wma_rx_service_ready_event",
    *(unsigned int *)(v30 + 732));
  *(_DWORD *)(a1 + 2712) = v31[21];
  *(_DWORD *)(a1 + 2716) = v31[22];
  *(_DWORD *)(a1 + 2720) = v31[23];
  *(_DWORD *)(a1 + 2724) = v31[24];
  *(_DWORD *)(a1 + 2728) = v31[25];
  v78 = v31[26];
  *(_DWORD *)(a1 + 2732) = v78;
  qdf_trace_msg(
    0x36u,
    4u,
    "%s: Board version: %x %x %x %x %x",
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    "wma_rx_service_ready_event",
    v78);
  qdf_mem_copy((void *)(a1 + 192), (const void *)(v30 + 552), 0x80u);
  v95 = wmi_service_enabled((__int64)v32, 0x5Bu, v87, v88, v89, v90, v91, v92, v93, v94);
  cdp_cfg_tx_set_is_mgmt_over_wmi_enabled(context, v95 & 1);
  v96 = cdp_set_desc_global_pool_size(context, v31[32]);
  if ( (unsigned int)wmi_unified_register_event_handler(
                       *(_QWORD **)a1,
                       0xCu,
                       (__int64)wma_beacon_swba_handler,
                       2u,
                       v96,
                       v97,
                       v98,
                       v99,
                       v100,
                       v101,
                       v102,
                       v103) )
  {
    v50 = "%s: Failed to register swba beacon event cb";
    goto LABEL_10;
  }
  *(_BYTE *)(a1 + 176) = wmi_service_enabled((__int64)v32, 0x4Bu, v21, v22, v23, v24, v25, v26, v27, v28) & 1;
  if ( (wmi_service_enabled((__int64)v32, 0xDBu, v104, v105, v106, v107, v108, v109, v110, v111) & 1) != 0 )
    wlan_dp_set_fst_in_cmem();
  if ( (wmi_service_enabled((__int64)v32, 0x125u, v112, v113, v114, v115, v116, v117, v118, v119) & 1) != 0 )
    wlan_dp_set_fisa_dynamic_aggr_size_support();
  *(_BYTE *)(a1 + 177) = wmi_service_enabled((__int64)v32, 0x57u, v120, v121, v122, v123, v124, v125, v126, v127) & 1;
  if ( (wmi_service_enabled((__int64)v32, 0x15u, v128, v129, v130, v131, v132, v133, v134, v135) & 1) != 0 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: FW support CSA offload capability",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wma_rx_service_ready_event");
    if ( (unsigned int)wmi_unified_register_event_handler(
                         v32,
                         0x23u,
                         (__int64)wma_csa_offload_handler,
                         2u,
                         v136,
                         v137,
                         v138,
                         v139,
                         v140,
                         v141,
                         v142,
                         v143) )
    {
      v50 = "%s: Failed to register CSA offload event cb";
      goto LABEL_10;
    }
  }
  if ( (wmi_service_enabled((__int64)v32, 0x5Bu, v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Firmware supports management TX over WMI,use WMI interface instead of HTT for management Tx",
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      "wma_rx_service_ready_event");
    if ( (unsigned int)wmi_unified_register_event_handler(
                         v32,
                         0x48u,
                         (__int64)wma_mgmt_tx_completion_handler,
                         2u,
                         v152,
                         v153,
                         v154,
                         v155,
                         v156,
                         v157,
                         v158,
                         v159)
      || (unsigned int)wmi_unified_register_event_handler(
                         v32,
                         0xB5u,
                         (__int64)wma_mgmt_tx_bundle_completion_handler,
                         2u,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28) )
    {
      v50 = "%s: Failed to register MGMT over WMI completion handler";
      goto LABEL_10;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: FW does not support WMI_SERVICE_MGMT_TX_WMI, Use HTT interface for Management Tx",
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      "wma_rx_service_ready_event");
  }
  if ( (unsigned int)wma_register_gtk_offload_event(a1) )
  {
    v50 = "%s: Failed to register GTK offload event cb";
    goto LABEL_10;
  }
  if ( (unsigned int)wmi_unified_register_event_handler(
                       v32,
                       0xDu,
                       (__int64)&wma_tbttoffset_update_event_handler,
                       2u,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28) )
  {
    v50 = "%s: Failed to register WMI_TBTTOFFSET_UPDATE_EVENTID callback";
    goto LABEL_10;
  }
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0x80u, v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
  {
    if ( (unsigned int)wmi_unified_register_event_handler(
                         v32,
                         0x9Bu,
                         (__int64)wma_rcpi_event_handler,
                         2u,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28) )
    {
      v50 = "%s: Failed to register RCPI event handler";
      goto LABEL_10;
    }
    *(_BYTE *)(a1 + 3800) = 1;
  }
  *(_DWORD *)(v30 + 316) = wmi_service_enabled((__int64)v32, 0x73u, v21, v22, v23, v24, v25, v26, v27, v28) & 1;
  *(_DWORD *)(v30 + 320) = 7;
  if ( (unsigned int)wmi_unified_register_event_handler(
                       v32,
                       0x5Bu,
                       (__int64)wma_log_supported_evt_handler,
                       2u,
                       v160,
                       v161,
                       v162,
                       v163,
                       v164,
                       v165,
                       v166,
                       v167) )
  {
    v50 = "%s: Failed to register log supported event cb";
    goto LABEL_10;
  }
  v168 = wmi_service_enabled((__int64)v32, 0x79u, v21, v22, v23, v24, v25, v26, v27, v28);
  wakeup_packet = cdp_mark_first_wakeup_packet(context, v168 & 1);
  v177 = wmi_service_enabled((__int64)v32, 0x7Fu, wakeup_packet, v170, v171, v172, v173, v174, v175, v176);
  v178 = *(_QWORD *)a1;
  *(_BYTE *)(a1 + 3779) = v177 & 1;
  v187 = wmi_service_enabled(v178, 0x70u, v179, v180, v181, v182, v183, v184, v185, v186);
  v188 = *(_QWORD *)a1;
  *(_BYTE *)(a1 + 3776) = v187 & 1;
  v197 = wmi_service_enabled(v188, 0x23u, v189, v190, v191, v192, v193, v194, v195, v196);
  v198 = *(_QWORD *)(a1 + 24);
  *(_BYTE *)(a1 + 3952) = v197 & 1;
  wma_set_component_caps(v198);
  wma_update_fw_config(*(_QWORD *)(a1 + 24), v30);
  if ( (unsigned int)wmi_unified_save_fw_version_cmd((__int64)v32) )
  {
    v50 = "%s: Failed to send WMI_INIT_CMDID command";
    goto LABEL_10;
  }
  if ( (wmi_service_enabled((__int64)v32, 0x5Cu, v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
  {
    if ( (unsigned int)qdf_mc_timer_start(a1 + 2928, 0x1770u) )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to start the service ready ext timer",
        v199,
        v200,
        v201,
        v202,
        v203,
        v204,
        v205,
        v206,
        "wma_rx_service_ready_event");
  }
  *(_BYTE *)(a1 + 3948) = wmi_service_enabled((__int64)v32, 0x8Fu, v199, v200, v201, v202, v203, v204, v205, v206) & 1;
  *(_BYTE *)(a1 + 3950) = wmi_service_enabled((__int64)v32, 0xA1u, v207, v208, v209, v210, v211, v212, v213, v214) & 1;
  *(_BYTE *)(v30 + 487) = 1;
  return 0;
}
