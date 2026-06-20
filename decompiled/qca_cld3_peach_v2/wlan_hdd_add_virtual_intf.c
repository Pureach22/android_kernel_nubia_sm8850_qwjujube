__int64 __fastcall wlan_hdd_add_virtual_intf(
        __int64 a1,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5)
{
  __int64 v10; // x0
  int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  __int64 *v31; // x20
  int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w0
  __int64 adapter; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x25
  __int64 vdev_by_user; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x26
  unsigned int *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int v71; // w25
  int v72; // w26
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  _DWORD *v90; // x0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned __int8 *v99; // x23
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  int v109; // w1
  __int64 intf_addr; // x0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
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
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  __int64 v151; // x0
  __int64 v152; // x19
  unsigned int *v153; // x8
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  __int64 v162; // [xsp+0h] [xbp-30h] BYREF
  int v163; // [xsp+Ch] [xbp-24h] BYREF
  unsigned int v164; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v165[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _DWORD *v166; // [xsp+18h] [xbp-18h] BYREF
  int v167; // [xsp+20h] [xbp-10h] BYREF
  __int16 v168; // [xsp+24h] [xbp-Ch]
  __int64 v169; // [xsp+28h] [xbp-8h]

  v169 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 488);
  v162 = 0;
  v11 = _osif_vdev_sync_create_and_trans(v10, &v162, "_wlan_hdd_add_virtual_intf");
  if ( v11 )
  {
    v20 = v11;
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return v20;
  }
  if ( a1 )
  {
    v165[0] = 0;
    v164 = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v12, v13, v14, v15, v16, v17, v18, v19, "__wlan_hdd_add_virtual_intf");
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v29 = "%s: Command not allowed in FTM mode";
LABEL_8:
      qdf_trace_msg(0x33u, 2u, v29, v21, v22, v23, v24, v25, v26, v27, v28, "__wlan_hdd_add_virtual_intf");
LABEL_9:
      v20 = -22;
LABEL_10:
      osif_vdev_sync_trans_stop(v162);
      osif_vdev_sync_destroy(v162);
      goto LABEL_11;
    }
    if ( (unsigned int)cds_get_conparam() == 4 )
    {
      v29 = "%s: Concurrency not allowed with standalone monitor mode";
      goto LABEL_8;
    }
    v31 = (__int64 *)(a1 + 1536);
    v32 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_add_virtual_intf",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28);
    if ( v32 )
      goto LABEL_15;
    v41 = hdd_nl_to_qdf_iface_type(a4, &v164, v33, v34, v35, v36, v37, v38, v39, v40);
    if ( v41 )
    {
      v32 = qdf_status_to_os_return(v41);
LABEL_15:
      v20 = v32;
      if ( !v32 )
        goto LABEL_10;
LABEL_16:
      if ( v20 <= 0xFFFFFFFFFFFFF000LL )
      {
        osif_vdev_sync_register(*(_QWORD *)(v20 + 32), v162);
        osif_vdev_sync_trans_stop(v162);
        goto LABEL_11;
      }
      goto LABEL_10;
    }
    if ( v164 == 6 && (*(_BYTE *)a5 & 0x10) == 0 && (os_if_lpc_mon_intf_creation_allowed(*v31) & 1) == 0 )
      goto LABEL_33;
    wlan_hdd_lpc_handle_concurrency();
    if ( (policy_mgr_is_sta_mon_concurrency(*v31) & 1) != 0 && (hdd_lpc_is_work_scheduled(a1 + 1536) & 1) == 0 )
      goto LABEL_9;
    if ( (hdd_allow_new_intf(a1 + 1536, v164) & 1) == 0 )
    {
LABEL_33:
      v20 = -95;
      goto LABEL_10;
    }
    qdf_mtrace(51, 51, 0x17u, 0xFFu, a4);
    if ( v164 >= 4 && v164 != 6 )
      v164 = 0;
    v163 = 8;
    adapter = hdd_get_adapter(a1 + 1536, 0);
    if ( adapter )
    {
      v51 = adapter;
      if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                            *(_BYTE *)(*(_QWORD *)(adapter + 52832) + 8LL),
                            (__int64)"__wlan_hdd_add_virtual_intf",
                            v43,
                            v44,
                            v45,
                            v46,
                            v47,
                            v48,
                            v49,
                            v50) )
      {
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                         *(_QWORD *)(v51 + 52832),
                         0x53u,
                         (__int64)"__wlan_hdd_add_virtual_intf");
        if ( vdev_by_user )
        {
          v61 = vdev_by_user;
          if ( (unsigned int)ucfg_scan_get_vdev_status(vdev_by_user, v53, v54, v55, v56, v57, v58, v59, v60) )
            wlan_abort_scan(
              *(_QWORD *)(a1 + 1544),
              -1,
              *(unsigned __int8 *)(*(_QWORD *)(v51 + 52832) + 8LL),
              0xFFFFFFFF,
              0);
          _hdd_objmgr_put_vdev_by_user(
            v61,
            0x53u,
            (__int64)"__wlan_hdd_add_virtual_intf",
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: vdev is NULL",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "__wlan_hdd_add_virtual_intf");
        }
      }
    }
    v166 = nullptr;
    if ( a4 == 6 )
    {
      v71 = *a5;
      v72 = *a5 & 0x10;
      if ( (!ucfg_dp_is_local_pkt_capture_enabled() || v72)
        && ((wlan_mlme_is_sta_mon_conc_supported(*v31) & 1) == 0 || !v72) )
      {
        v29 = "%s: Adding monitor interface not supported";
        goto LABEL_8;
      }
      if ( (unsigned int)wlan_hdd_add_monitor_check((__int64 *)(a1 + 1536), &v166, a2, 1, a3, (v71 & 0x10) != 0) )
        goto LABEL_9;
      ucfg_dp_set_mon_conf_flags(*v31, *a5);
      if ( v166 )
      {
LABEL_62:
        qdf_trace_msg(0x33u, 8u, "%s: exit", v73, v74, v75, v76, v77, v78, v79, v80, "__wlan_hdd_add_virtual_intf");
        v20 = *(_QWORD *)(*((_QWORD *)v166 + 4) + 992LL);
        if ( !v20 )
          goto LABEL_10;
        goto LABEL_16;
      }
    }
    v81 = *v31;
    v166 = nullptr;
    cfg_p2p_get_device_addr_admin(v81, v165);
    if ( v165[0] == 1 && (v164 & 0xFFFFFFFE) == 2 )
    {
      v168 = *(_WORD *)(a1 + 1818);
      v167 = *(_DWORD *)(a1 + 1814);
      LOBYTE(v168) = v168 ^ 0x80;
      v90 = hdd_open_adapter(
              (__int64 *)(a1 + 1536),
              v164,
              a2,
              (unsigned __int8 *)&v167,
              a3,
              1,
              &v163,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89);
      v99 = nullptr;
      v166 = v90;
    }
    else
    {
      v100 = strnstr(a2, "p2p", 3);
      v109 = v164;
      if ( v100 && !v164 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: change mode to p2p device",
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          "__wlan_hdd_add_virtual_intf");
        v109 = 7;
        v164 = 7;
      }
      intf_addr = wlan_hdd_get_intf_addr(a1 + 1536, v109, v101, v102, v103, v104, v105, v106, v107, v108);
      if ( !intf_addr )
        goto LABEL_9;
      v99 = (unsigned __int8 *)intf_addr;
      if ( (policy_mgr_mlo_sap_concurrency_allow(*v31, v111, v112, v113, v114, v115, v116, v117, v118) & 1) != 0
        && v164 <= 1 )
      {
        v163 |= 4u;
      }
      v90 = hdd_open_adapter(v31, v164, a2, v99, a3, 1, &v163, v119, v120, v121, v122, v123, v124, v125, v126);
      v166 = v90;
      if ( v90 )
        goto LABEL_55;
      wlan_hdd_release_intf_addr((__int64)v31, v99, v127, v128, v129, v130, v131, v132, v133, v134);
      v90 = v166;
    }
    if ( !v90 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_open_adapter failed with iftype %d",
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        "__wlan_hdd_add_virtual_intf",
        a4);
      v20 = -28;
      goto LABEL_10;
    }
LABEL_55:
    *((_BYTE *)v90 + 52796) = 0;
    if ( (unsigned int)hdd_trigger_psoc_idle_restart((__int64)v31) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to start the wlan_modules",
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        v141,
        v142,
        "__wlan_hdd_add_virtual_intf");
      if ( v99 )
        wlan_hdd_release_intf_addr((__int64)v31, v99, v143, v144, v145, v146, v147, v148, v149, v150);
      hdd_close_adapter(v31, (__int64)v166, 1, v143, v144, v145, v146, v147, v148, v149, v150);
      goto LABEL_9;
    }
    v151 = _hdd_objmgr_get_vdev_by_user(*((_QWORD *)v166 + 6604), 0x61u, (__int64)"__wlan_hdd_add_virtual_intf");
    if ( v151 )
    {
      v152 = v151;
      ucfg_dp_try_send_rps_ind(v151, v73, v74, v75, v76, v77, v78, v79, v80);
      _hdd_objmgr_put_vdev_by_user(
        v152,
        0x61u,
        (__int64)"__wlan_hdd_add_virtual_intf",
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        v161);
    }
    goto LABEL_62;
  }
  __break(0x800u);
  return hdd_clean_up_interface();
}
