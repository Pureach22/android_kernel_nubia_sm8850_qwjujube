__int64 __fastcall p2p_execute_roc_req(
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
  __int64 v10; // x19
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w22
  const char *v21; // x2
  __int64 *v22; // x24
  __int64 v23; // x1
  __int64 v24; // x0
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  unsigned int v35; // w25
  __int64 *v36; // x0
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 *v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w9
  int v64; // w9
  int v65; // w9
  void *v66; // x0
  _QWORD *v67; // x1
  int v68; // w8
  unsigned int v69; // w23
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  char is_hw_dbs_capable; // w0
  int v79; // w8
  unsigned int v80; // w8
  int v81; // w4
  unsigned int v82; // w4
  char v83; // w25
  char is_sta_vdev_usage_allowed_for_p2p_dev; // w8
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
  unsigned int *v101; // x8
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  int v127; // w8
  __int64 v128; // x20
  __int64 v129; // x4
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  _BYTE v146[4]; // [xsp+30h] [xbp-20h] BYREF
  _BYTE v147[4]; // [xsp+34h] [xbp-1Ch] BYREF
  _QWORD v148[3]; // [xsp+38h] [xbp-18h] BYREF

  v148[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 16);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: p2p soc obj:%pK, roc ctx:%pK, vdev_id:%d, scan_id:%d, tx ctx:%pK, freq:%d, phy_mode:%d, duration:%d, roc_type:%d, roc_state:%d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_execute_roc_req",
    v10,
    a1,
    *(unsigned int *)(a1 + 24),
    *(unsigned int *)(a1 + 28),
    *(_QWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 40),
    *(unsigned __int8 *)(a1 + 44),
    *(_DWORD *)(a1 + 48),
    *(_DWORD *)(a1 + 52),
    *(_DWORD *)(a1 + 224));
  qdf_runtime_pm_prevent_suspend((__int64 *)(v10 + 176));
  v11 = qdf_mc_timer_init(a1 + 56, 0, (__int64)p2p_roc_timeout, v10);
  if ( v11 )
  {
    v20 = v11;
    v21 = "%s: failed to init roc timer, status:%d";
LABEL_42:
    qdf_trace_msg(0x4Eu, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "p2p_execute_roc_req", v20);
    p2p_destroy_roc_ctx(a1, 1, 1, v118, v119, v120, v121, v122, v123, v124, v125);
    qdf_runtime_pm_allow_suspend((__int64 *)(v10 + 176));
    goto LABEL_43;
  }
  v22 = *(__int64 **)(a1 + 16);
  WORD2(v148[0]) = 0;
  *(_DWORD *)(a1 + 224) = 1;
  v23 = *(unsigned int *)(a1 + 24);
  LODWORD(v148[0]) = 0;
  v24 = *v22;
  v147[0] = 0;
  v146[0] = 0;
  v25 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v24, v23, 15);
  if ( !v25 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: vdev is NULL", v26, v27, v28, v29, v30, v31, v32, v33, "p2p_scan_start");
    v20 = 4;
LABEL_41:
    qdf_mc_timer_destroy(a1 + 56);
    v21 = "%s: Failed to start scan, status:%d";
    goto LABEL_42;
  }
  v34 = v25;
  v35 = *(_DWORD *)(v25 + 16);
  v36 = (__int64 *)_qdf_mem_malloc(0x8F0u, "p2p_scan_start", 103);
  if ( !v36 )
  {
    wlan_objmgr_vdev_release_ref(v34, 0xFu, v37, v38, v39, v40, v41, v42, v43, v44, v45);
    v20 = 2;
    goto LABEL_41;
  }
  v46 = v36;
  wlan_scan_init_default_params(v34, v36, v38, v39, v40, v41, v42, v43, v44, v45);
  if ( !*(_DWORD *)(a1 + 48) )
  {
    *(_DWORD *)(a1 + 48) = 200;
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: use default duration %d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "p2p_scan_start",
      200);
  }
  *(_DWORD *)(a1 + 28) = wlan_scan_get_scan_id(*v22, v47, v48, v49, v50, v51, v52, v53, v54);
  *v46 = v34;
  v63 = *(_DWORD *)(a1 + 28);
  *((_DWORD *)v46 + 7) = 2;
  *((_DWORD *)v46 + 2) = v63;
  v64 = *((unsigned __int16 *)v22 + 40);
  *((_BYTE *)v46 + 120) = 1;
  *((_DWORD *)v46 + 3) = v64;
  *((_DWORD *)v46 + 31) = *(_DWORD *)(a1 + 40);
  v65 = *(_DWORD *)(a1 + 48);
  *((_DWORD *)v46 + 27) = 1;
  *((_DWORD *)v46 + 6) = 3;
  *((_DWORD *)v46 + 9) = 0;
  *((_WORD *)v46 + 940) = -1;
  *((_DWORD *)v46 + 11) = v65;
  *((_DWORD *)v46 + 469) = -1;
  if ( *(_DWORD *)(a1 + 240) == 7 && (p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*v22) & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 52) == 1 )
    {
      v66 = (char *)v46 + 1901;
      v67 = (_QWORD *)(a1 + 232);
    }
    else
    {
      wlan_mlme_get_p2p_device_mac_addr(*v46, (__int64)v148, v55, v56, v57, v58, v59, v60, v61, v62);
      v66 = (char *)v46 + 1901;
      v67 = v148;
    }
    qdf_mem_copy(v66, v67, 6u);
    v68 = *((_DWORD *)v46 + 518);
    *((_BYTE *)v46 + 1900) = 1;
    *((_DWORD *)v46 + 518) = v68 | 0x100000;
  }
  if ( *((_DWORD *)v46 + 11) <= 0x5DBu )
  {
    v69 = policy_mgr_mode_specific_connection_count(*v22, 3, nullptr);
    ((void (__fastcall *)(__int64, __int64, _BYTE *))policy_mgr_mode_specific_num_active_sessions)(*v22, 11, v147);
    ((void (__fastcall *)(__int64, __int64, _BYTE *))policy_mgr_mode_specific_num_active_sessions)(*v22, 16, v146);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: present go number:%d, NDP number:%d, NAN number:%d",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "p2p_scan_start",
      v69,
      v147[0],
      v146[0]);
    is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(*v22);
    if ( v35 <= 7 && ((1 << v35) & 0x8C) != 0
      || *(_DWORD *)(a1 + 240) == 7
      && (v83 = is_hw_dbs_capable,
          is_sta_vdev_usage_allowed_for_p2p_dev = p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*v22),
          is_hw_dbs_capable = v83,
          (is_sta_vdev_usage_allowed_for_p2p_dev & 1) != 0) )
    {
      v79 = *((_DWORD *)v46 + 11);
      if ( !v69 )
      {
        *((_DWORD *)v46 + 11) = 10 * v79;
        goto LABEL_22;
      }
      v80 = v79 + 300;
      *((_DWORD *)v46 + 11) = v80;
      if ( v80 <= 0x258 )
        goto LABEL_22;
    }
    else if ( !v69 || *((_DWORD *)v46 + 11) <= 0x258u )
    {
LABEL_22:
      if ( v147[0] )
      {
        v82 = *((_DWORD *)v46 + 11);
        if ( (is_hw_dbs_capable & 1) == 0 )
        {
          if ( v82 <= 0xFA )
            goto LABEL_40;
          v81 = 250;
          goto LABEL_39;
        }
      }
      else
      {
        v82 = *((_DWORD *)v46 + 11);
        if ( !v146[0] )
        {
          if ( v82 < 0x5DD )
            goto LABEL_40;
          v81 = 1500;
          goto LABEL_39;
        }
        if ( (is_hw_dbs_capable & 1) == 0 )
        {
          if ( v82 <= 0x12C )
            goto LABEL_40;
          v81 = 300;
          goto LABEL_39;
        }
      }
      if ( v82 <= 0x15E )
        goto LABEL_40;
      v81 = 350;
      goto LABEL_39;
    }
    v81 = 600;
LABEL_39:
    *((_DWORD *)v46 + 11) = v81;
  }
LABEL_40:
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: FW requested roc duration is:%d",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "p2p_scan_start");
  v20 = wlan_scan_start(v46, v85, v86, v87, v88, v89, v90, v91, v92);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: start scan, scan req id:%d, scan id:%d, status:%d",
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    "p2p_scan_start",
    *((unsigned __int16 *)v22 + 40),
    *(unsigned int *)(a1 + 28),
    v20);
  wlan_objmgr_vdev_release_ref(v34, 0xFu, v101, v102, v103, v104, v105, v106, v107, v108, v109);
  if ( v20 )
    goto LABEL_41;
  v127 = *(_DWORD *)(a1 + 24);
  v128 = *(_QWORD *)v10;
  v129 = *(_QWORD *)v10;
  *(_DWORD *)(v10 + 216) = v127;
  v148[0] = 4;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: psoc:%pK, is register rx:%d",
    v110,
    v111,
    v112,
    v113,
    v114,
    v115,
    v116,
    v117,
    "p2p_mgmt_rx_ops",
    v129,
    1);
  v148[1] = tgt_p2p_mgmt_frame_rx_cb;
  v20 = wlan_mgmt_txrx_register_rx_cb(v128, 5u, (__int64)v148, 1u, v130, v131, v132, v133, v134, v135, v136, v137);
  if ( v20 )
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Failed to register mgmt rx callback, status:%d",
      v138,
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      "p2p_execute_roc_req",
      v20);
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v20;
}
