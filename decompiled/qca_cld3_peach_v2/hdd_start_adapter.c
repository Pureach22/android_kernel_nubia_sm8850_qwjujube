__int64 __fastcall hdd_start_adapter(
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
  int v10; // w20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x25
  unsigned __int64 StatusReg; // x8
  __int64 v29; // x0
  __int64 v30; // x24
  __int64 v31; // x22
  __int64 v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int8 v41; // w26
  unsigned __int64 v42; // x27
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x21
  __int64 v52; // x8
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x24
  __int64 v63; // x8
  __int64 v64; // x8
  unsigned int *v65; // x8
  unsigned int v66; // w10
  __int64 v67; // x8
  unsigned int v74; // w9
  const char *v75; // x2
  __int64 v76; // x4
  _QWORD *v77; // x1
  __int64 v78; // x9
  unsigned __int64 v79; // x8
  __int64 v80; // x9
  unsigned int *v81; // x9
  unsigned int v82; // w12
  __int64 v83; // x9
  __int64 v85; // x0
  __int64 v86; // x21
  __int64 v87; // x9
  unsigned __int64 v88; // x8
  __int64 v89; // x9
  unsigned int *v90; // x9
  unsigned int v91; // w12
  __int64 v92; // x9
  __int64 *v94; // x21
  int v95; // w22
  __int64 adapter; // x0
  __int64 v97; // x1
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  unsigned int v114; // w0
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x21
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 result; // x0
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  _QWORD *v151; // x21
  unsigned int v153; // w9
  unsigned int v155; // w9
  _QWORD v156[2]; // [xsp+0h] [xbp-10h] BYREF

  v156[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 40);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_start_adapter",
    *(_QWORD *)(a1 + 32) + 296LL);
  if ( v10 > 3 )
  {
    if ( v10 > 6 )
    {
      if ( v10 != 7 )
      {
        if ( v10 == 8 || v10 == 16 )
          goto LABEL_81;
        goto LABEL_61;
      }
      v94 = *(__int64 **)(a1 + 24);
      v95 = *(_DWORD *)(a1 + 40);
      adapter = hdd_get_adapter((__int64)v94, 0);
      if ( !adapter || (*(_QWORD *)(adapter + 1624) & 4) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: sta interface is not up, do not use sta vdev for p2p device",
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          "hdd_use_sta_vdev_for_p2p_device_operations");
        goto LABEL_81;
      }
      if ( v95 == 7 && (ucfg_is_sta_vdev_for_p2p_device_supported(*v94, v97) & 1) != 0 )
      {
        ucfg_p2p_set_sta_vdev_for_p2p_dev_operations(*v94, 1);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Do not create new vdev, use STA vdev for P2P device mode",
          v143,
          v144,
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          "hdd_start_adapter");
      }
      else
      {
LABEL_81:
        if ( (unsigned int)hdd_start_station_adapter(a1) )
        {
LABEL_98:
          result = 4294967274LL;
          goto LABEL_99;
        }
      }
      goto LABEL_82;
    }
    if ( v10 == 4 )
      goto LABEL_95;
    if ( v10 == 6 )
    {
      if ( (unsigned int)hdd_start_station_adapter(a1) )
        goto LABEL_98;
      hdd_set_idle_ps_config(*(_QWORD *)(a1 + 24), 0, v19, v20, v21, v22, v23, v24, v25, v26);
      goto LABEL_82;
    }
LABEL_61:
    v75 = "%s: Invalid session type %d";
    v76 = (unsigned int)v10;
LABEL_97:
    qdf_trace_msg(0x33u, 2u, v75, v11, v12, v13, v14, v15, v16, v17, v18, "hdd_start_adapter", v76);
    goto LABEL_98;
  }
  if ( v10 > 1 )
  {
    if ( v10 != 2 )
      goto LABEL_12;
LABEL_18:
    v27 = *(_QWORD *)(a1 + 24);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v27 + 32);
    }
    else
    {
      raw_spin_lock_bh(v27 + 32);
      *(_QWORD *)(v27 + 40) |= 1uLL;
    }
    v156[0] = 0;
    v29 = qdf_list_peek_front((_QWORD *)(v27 + 48), v156);
    if ( (_DWORD)v29 || (v77 = (_QWORD *)v156[0], v30 = v156[0] - 8LL, v156[0] == 8) )
    {
      v30 = 0;
    }
    else
    {
      v78 = *(__int64 *)((char *)&off_18 + v156[0]);
      if ( v78 )
      {
        v79 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v79 + 16);
        v80 = *(_QWORD *)(v78 + 1320);
        v81 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v80);
        do
          v82 = __ldxr(v81);
        while ( __stxr(v82 + 1, v81) );
        v83 = *(_QWORD *)(v79 + 16) - 1LL;
        *(_DWORD *)(v79 + 16) = v83;
        if ( !v83 || !*(_QWORD *)(v79 + 16) )
        {
          v151 = v77;
          preempt_schedule_notrace(v29);
          v77 = v151;
        }
      }
      _X8 = (unsigned int *)(v77 + 6570);
      __asm { PRFM            #0x11, [X8] }
      do
        v153 = __ldxr(_X8);
      while ( __stxr(v153 + 1, _X8) );
      v156[0] = 0;
      v85 = qdf_list_peek_next((_QWORD *)(v27 + 48), v77, v156);
      if ( !(_DWORD)v85 )
      {
        v86 = v156[0];
        v31 = v156[0] - 8LL;
        if ( v156[0] != 8 )
        {
          v87 = *(__int64 *)((char *)&off_18 + v156[0]);
          if ( v87 )
          {
            v88 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v88 + 16);
            v89 = *(_QWORD *)(v87 + 1320);
            v90 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v89);
            do
              v91 = __ldxr(v90);
            while ( __stxr(v91 + 1, v90) );
            v92 = *(_QWORD *)(v88 + 16) - 1LL;
            *(_DWORD *)(v88 + 16) = v92;
            if ( !v92 || !*(_QWORD *)(v88 + 16) )
              preempt_schedule_notrace(v85);
          }
          _X8 = (unsigned int *)(v86 + 52560);
          __asm { PRFM            #0x11, [X8] }
          do
            v155 = __ldxr(_X8);
          while ( __stxr(v155 + 1, _X8) );
        }
        goto LABEL_25;
      }
    }
    v31 = 0;
LABEL_25:
    v32 = *(_QWORD *)(v27 + 40);
    if ( (v32 & 1) != 0 )
    {
      *(_QWORD *)(v27 + 40) = v32 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v27 + 32);
      if ( !v30 )
        goto LABEL_81;
    }
    else
    {
      raw_spin_unlock(v27 + 32);
      if ( !v30 )
        goto LABEL_81;
    }
    v41 = 0;
    v42 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( v30 != a1 && (*(_BYTE *)(*(_QWORD *)(v30 + 32) + 176LL) & 1) != 0 && (*(_DWORD *)(v30 + 40) | 2) == 2 )
        ++v41;
      hdd_adapter_dev_put_debug(v30, 0xBu, v33, v34, v35, v36, v37, v38, v39, v40);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v42 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v42 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v27 + 32);
        if ( v31 )
          goto LABEL_39;
LABEL_29:
        v51 = 0;
        v30 = 0;
        v52 = *(_QWORD *)(v27 + 40);
        if ( (v52 & 1) == 0 )
          goto LABEL_30;
LABEL_52:
        *(_QWORD *)(v27 + 40) = v52 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v27 + 32);
        v31 = v51;
        if ( !v30 )
        {
LABEL_59:
          if ( v41 >= 4u )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Max limit reached sta vdev-current %d max %d",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "hdd_max_sta_interface_up_count_reached");
            goto LABEL_98;
          }
          goto LABEL_81;
        }
      }
      else
      {
        raw_spin_lock_bh(v27 + 32);
        *(_QWORD *)(v27 + 40) |= 1uLL;
        if ( !v31 )
          goto LABEL_29;
LABEL_39:
        v156[0] = 0;
        v53 = qdf_list_peek_next((_QWORD *)(v27 + 48), (_QWORD *)(v31 + 8), v156);
        v51 = v156[0] - 8LL;
        if ( (_DWORD)v53 )
          v62 = 0;
        else
          v62 = v156[0] - 8LL;
        if ( v31 == v62 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v31, 0xBu, v43, v44, v45, v46, v47, v48, v49, v50);
          goto LABEL_29;
        }
        if ( v62 )
        {
          v63 = *(_QWORD *)(v62 + 32);
          if ( v63 )
          {
            ++*(_DWORD *)(v42 + 16);
            v64 = *(_QWORD *)(v63 + 1320);
            v65 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v64);
            do
              v66 = __ldxr(v65);
            while ( __stxr(v66 + 1, v65) );
            v67 = *(_QWORD *)(v42 + 16) - 1LL;
            *(_DWORD *)(v42 + 16) = v67;
            if ( !v67 || !*(_QWORD *)(v42 + 16) )
              preempt_schedule_notrace(v53);
          }
          _X8 = (unsigned int *)(v62 + 52568);
          __asm { PRFM            #0x11, [X8] }
          do
            v74 = __ldxr(_X8);
          while ( __stxr(v74 + 1, _X8) );
        }
        else
        {
          v51 = 0;
        }
        v30 = v31;
        v52 = *(_QWORD *)(v27 + 40);
        if ( (v52 & 1) != 0 )
          goto LABEL_52;
LABEL_30:
        raw_spin_unlock(v27 + 32);
        v31 = v51;
        if ( !v30 )
          goto LABEL_59;
      }
    }
  }
  if ( !v10 )
    goto LABEL_18;
  if ( v10 != 1 )
    goto LABEL_61;
LABEL_12:
  if ( (unsigned int)hdd_start_ap_adapter(a1, 0) )
    goto LABEL_98;
LABEL_82:
  if ( (unsigned int)hdd_set_fw_params(a1) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set the FW params for the adapter!",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "hdd_start_adapter");
  if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL) == 255 )
  {
    v115 = 255;
  }
  else
  {
    v114 = wlan_hdd_cfg80211_register_frames(a1, v106, v107, v108, v109, v110, v111, v112, v113);
    if ( (v114 & 0x80000000) != 0 )
    {
      v76 = v114;
      v75 = "%s: Failed to register frames - ret %d";
      goto LABEL_97;
    }
    v115 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL);
  }
  wlan_hdd_update_dbs_scan_and_fw_mode_config(v115);
  v116 = hdd_get_adapter(*(_QWORD *)(a1 + 24), 0);
  if ( v116 )
  {
    v117 = v116;
    if ( (*(_QWORD *)(v116 + 1624) & 4) != 0
      && v10 == 7
      && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(**(_QWORD **)(a1 + 24)) & 1) != 0 )
    {
      ucfg_p2p_psoc_priv_set_sta_vdev_id(**(_QWORD **)(a1 + 24), *(_BYTE *)(*(_QWORD *)(v117 + 52832) + 8LL));
      if ( (unsigned int)wlan_mlme_set_p2p_device_mac_addr(
                           *(_QWORD *)(*(_QWORD *)(v117 + 52832) + 32LL),
                           (int *)(a1 + 1617),
                           v118,
                           v119,
                           v120,
                           v121,
                           v122,
                           v123,
                           v124,
                           v125) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to set p2p mac addr",
          v126,
          v127,
          v128,
          v129,
          v130,
          v131,
          v132,
          v133,
          "hdd_cache_p2p_macaddr_in_vdev");
      *(_BYTE *)(*(_QWORD *)(a1 + 52832) + 8LL) = *(_BYTE *)(*(_QWORD *)(v117 + 52832) + 8LL);
    }
  }
LABEL_95:
  hdd_create_adapter_sysfs_files(a1);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v134, v135, v136, v137, v138, v139, v140, v141, "hdd_start_adapter");
  result = 0;
LABEL_99:
  _ReadStatusReg(SP_EL0);
  return result;
}
