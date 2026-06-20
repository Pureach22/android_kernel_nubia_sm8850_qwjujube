__int64 __fastcall hdd_init_ap_mode(
        __int64 *a1,
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
  __int64 v12; // x24
  __int64 *v13; // x23
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x25
  __int64 v31; // x26
  __int64 v32; // x20
  __int64 link_mac_addr; // x0
  __int64 v34; // x22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int enable_sifs_burst; // w22
  unsigned int inited; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  const char *v88; // x2
  unsigned int v89; // w0
  unsigned int v90; // w0
  unsigned int v91; // w0
  unsigned int v92; // w0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned int v101; // w0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 vdev_by_user; // x0
  __int64 v111; // x8
  __int64 v112; // x23
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  _BYTE v121[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v122[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v123; // [xsp+8h] [xbp-8h]

  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v122[0] = 0;
  v121[0] = 0;
  v13 = *(__int64 **)(v12 + 24);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_init_ap_mode");
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: SSR in progress: %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "hdd_init_ap_mode",
    a2 & 1);
  *((_DWORD *)a1 + 586) = 0;
  v30 = *a1;
  if ( !*a1 )
  {
    v43 = "%s: invalid adapter";
LABEL_11:
    qdf_trace_msg(0x33u, 2u, v43, v22, v23, v24, v25, v26, v27, v28, v29, "hdd_hostapd_init_sap_session");
LABEL_12:
    qdf_trace_msg(0x33u, 2u, "%s: Invalid sap_ctx", v44, v45, v46, v47, v48, v49, v50, v51, "hdd_init_ap_mode");
    enable_sifs_burst = 16;
    goto LABEL_13;
  }
  v31 = *(_QWORD *)(v30 + 24);
  if ( !v31 )
  {
    v43 = "%s: hdd_ctx is null";
    goto LABEL_11;
  }
  v32 = a1[34];
  if ( !v32 )
  {
    v43 = "%s: can't allocate the sap_ctx";
    goto LABEL_11;
  }
  link_mac_addr = hdd_adapter_get_link_mac_addr(a1);
  if ( !link_mac_addr )
  {
    v43 = "%s: invalid link_mac";
    goto LABEL_11;
  }
  v34 = link_mac_addr;
  if ( (unsigned int)sap_acquire_vdev_ref(*(_QWORD *)v31, v32, *((unsigned __int8 *)a1 + 8)) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get vdev ref for sap for session_id: %u",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "hdd_hostapd_init_sap_session",
      *((unsigned __int8 *)a1 + 8));
LABEL_16:
    wlansap_context_put(v32);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: releasing the sap context for session-id:%d",
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      "hdd_hostapd_init_sap_session",
      *((unsigned __int8 *)a1 + 8));
    goto LABEL_12;
  }
  inited = sap_init_ctx(
             v32,
             *(unsigned int *)(v30 + 40),
             v34,
             *((unsigned __int8 *)a1 + 8),
             *(unsigned __int8 *)(v31 + 1817),
             a2 & 1);
  if ( inited )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wlansap_start failed!! status: %d",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "hdd_hostapd_init_sap_session",
      inited);
    a1[34] = 0;
    wlansap_release_vdev_ref(v32);
    goto LABEL_16;
  }
  if ( (a2 & 1) == 0 )
  {
    *((_DWORD *)a1 + 180) = *((_DWORD *)v13 + 405);
    *((_DWORD *)a1 + 529) = wlan_hdd_get_dfs_mode(*((unsigned int *)v13 + 404));
  }
  if ( *(_DWORD *)(v12 + 40) == 1 )
  {
    v79 = hdd_vdev_configure_rtt_params(*(_QWORD *)(v32 + 16));
    if ( v79 )
    {
      enable_sifs_burst = v79;
      v88 = "%s: vdev rtt configure failed";
LABEL_30:
      qdf_trace_msg(0x33u, 2u, v88, v80, v81, v82, v83, v84, v85, v86, v87, "hdd_init_ap_mode");
      hdd_hostapd_deinit_sap_session(a1);
      goto LABEL_13;
    }
  }
  a1[30] = 0;
  a1[31] = 0;
  a1[28] = 0;
  a1[29] = 0;
  a1[26] = 0;
  a1[27] = 0;
  a1[24] = 0;
  a1[25] = 0;
  a1[22] = 0;
  a1[23] = 0;
  a1[20] = 0;
  a1[21] = 0;
  a1[18] = 0;
  a1[19] = 0;
  a1[16] = 0;
  a1[17] = 0;
  a1[14] = 0;
  a1[15] = 0;
  a1[12] = 0;
  a1[13] = 0;
  a1[10] = 0;
  a1[11] = 0;
  v89 = qdf_event_create((_DWORD *)a1 + 22);
  if ( v89 )
  {
    enable_sifs_burst = v89;
    v88 = "%s: Hostapd HDD qdf event init failed!!";
    goto LABEL_30;
  }
  v90 = qdf_event_create((_DWORD *)a1 + 32);
  if ( v90 )
  {
    enable_sifs_burst = v90;
    v88 = "%s: Hostapd HDD stop bss event init failed!!";
    goto LABEL_30;
  }
  v91 = qdf_event_create((_DWORD *)a1 + 42);
  if ( v91 )
  {
    enable_sifs_burst = v91;
    v88 = "%s: Hostapd HDD sta disassoc event init failed!!";
    goto LABEL_30;
  }
  v92 = qdf_event_create((_DWORD *)a1 + 52);
  if ( v92 )
  {
    enable_sifs_burst = v92;
    v88 = "%s: Hostapd HDD sta eap frm done event init failed!!";
    goto LABEL_30;
  }
  enable_sifs_burst = ucfg_get_enable_sifs_burst(*v13, v122);
  if ( enable_sifs_burst )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get sifs burst value, use default",
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      "hdd_init_ap_mode");
  v101 = wma_cli_set_command(*((unsigned __int8 *)a1 + 8), 48, v122[0], 2);
  if ( v101 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wmi_pdev_param_burst_enable set failed: %d",
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      "hdd_init_ap_mode",
      v101);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_init_ap_mode");
  v111 = *v13;
  v112 = vdev_by_user;
  wlan_mlme_is_6g_sap_fd_enabled(v111, v121);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: 6g sap fd enabled %d",
    v113,
    v114,
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    "hdd_init_ap_mode",
    v121[0]);
  if ( v121[0] == 1 && v112 )
  {
    *(_DWORD *)(v112 + 56) |= 0x80000000;
LABEL_39:
    _hdd_objmgr_put_vdev_by_user(v112, 6, "hdd_init_ap_mode");
    goto LABEL_40;
  }
  if ( v112 )
    goto LABEL_39;
LABEL_40:
  if ( (a2 & 1) == 0 )
  {
    *((_BYTE *)a1 + 1416) = 0;
    wlansap_dcs_set_vdev_wlan_interference_mitigation(v32, 0);
    wlansap_dcs_set_vdev_starting(v32, 0);
    qdf_mem_set(a1 + 177, 0x260u, 0);
    *((_DWORD *)a1 + 592) = 0;
  }
  a1[562] = 0xFFFFFFFE00000LL;
  a1[563] = (__int64)(a1 + 563);
  a1[564] = (__int64)(a1 + 563);
  a1[565] = (__int64)hdd_stop_sap_due_to_invalid_channel;
LABEL_13:
  qdf_trace_msg(0x33u, 8u, "%s: exit", v52, v53, v54, v55, v56, v57, v58, v59, "hdd_init_ap_mode");
  _ReadStatusReg(SP_EL0);
  return enable_sifs_burst;
}
