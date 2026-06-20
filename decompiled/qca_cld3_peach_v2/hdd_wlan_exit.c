__int64 __fastcall hdd_wlan_exit(
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
  __int64 v10; // x20
  __int64 v11; // x0
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
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v37; // x0
  __int64 v38; // x22
  __int64 v39; // x21
  __int64 v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int64 v49; // x20
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x27
  __int64 v59; // x8
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x22
  __int64 v70; // x8
  __int64 v71; // x8
  unsigned int *v72; // x8
  unsigned int v73; // w10
  __int64 v74; // x8
  unsigned int v81; // w9
  _QWORD *v82; // x1
  __int64 v83; // x9
  unsigned __int64 v84; // x8
  __int64 v85; // x9
  unsigned int *v86; // x9
  unsigned int v87; // w12
  __int64 v88; // x9
  __int64 v90; // x0
  __int64 v91; // x20
  __int64 v92; // x9
  unsigned __int64 v93; // x8
  __int64 v94; // x9
  unsigned int *v95; // x9
  unsigned int v96; // w12
  __int64 v97; // x9
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned __int64 v107; // x8
  __int64 v108; // x0
  __int64 v109; // x25
  __int64 v110; // x22
  __int64 v111; // x8
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  unsigned __int64 v120; // x27
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // x21
  __int64 v130; // x8
  unsigned int v131; // w8
  __int64 v132; // x0
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x25
  __int64 v142; // x8
  __int64 v143; // x8
  unsigned int *v144; // x8
  unsigned int v145; // w10
  __int64 v146; // x8
  unsigned int v149; // w9
  _QWORD *v150; // x1
  __int64 v151; // x9
  unsigned __int64 v152; // x8
  __int64 v153; // x9
  unsigned int *v154; // x9
  unsigned int v155; // w12
  __int64 v156; // x9
  __int64 v158; // x0
  __int64 v159; // x20
  __int64 v160; // x9
  unsigned __int64 v161; // x8
  __int64 v162; // x9
  unsigned int *v163; // x9
  unsigned int v164; // w12
  __int64 v165; // x9
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  __int64 v175; // x0
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
  __int64 v192; // x0
  __int64 result; // x0
  _QWORD *v194; // x20
  _QWORD *v195; // x20
  unsigned int v197; // w9
  unsigned int v199; // w9
  unsigned int v201; // w9
  unsigned int v203; // w9
  __int64 v204; // [xsp+8h] [xbp-18h]
  _QWORD v205[2]; // [xsp+10h] [xbp-10h] BYREF

  v205[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 24);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_wlan_exit");
  v11 = ucfg_dp_wait_complete_tasks();
  wlan_hdd_destroy_mib_stats_lock(v11);
  hdd_debugfs_ini_config_deinit(a1);
  hdd_debugfs_mws_coex_info_deinit(a1);
  _qdf_delayed_work_stop_sync();
  qdf_wake_lock_release((__int64)&wlan_wake_lock, 0x15u);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Stopped psoc idle timer",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "hdd_psoc_idle_timer_stop");
  v20 = hdd_regulatory_deinit(a1);
  hdd_set_idle_ps_config(a1, 0, v20, v21, v22, v23, v24, v25, v26, v27);
  wlan_cfg80211_cleanup_scan_queue(*(_QWORD *)(a1 + 8), 0);
  if ( *(_DWORD *)(a1 + 1464) == 2 )
    goto LABEL_113;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v28, v29, v30, v31, v32, v33, v34, v35, "hdd_unregister_wext_all_adapters");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 32);
  }
  else
  {
    raw_spin_lock_bh(a1 + 32);
    *(_QWORD *)(a1 + 40) |= 1uLL;
  }
  v204 = v10;
  v205[0] = 0;
  v37 = qdf_list_peek_front((_QWORD *)(a1 + 48), v205);
  if ( (_DWORD)v37 || (v82 = (_QWORD *)v205[0], v38 = v205[0] - 8LL, v205[0] == 8) )
  {
    v38 = 0;
LABEL_8:
    v39 = 0;
    goto LABEL_9;
  }
  v83 = *(_QWORD *)(v205[0] + 24LL);
  if ( v83 )
  {
    v84 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v84 + 16);
    v85 = *(_QWORD *)(v83 + 1320);
    v86 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v85);
    do
      v87 = __ldxr(v86);
    while ( __stxr(v87 + 1, v86) );
    v88 = *(_QWORD *)(v84 + 16) - 1LL;
    *(_DWORD *)(v84 + 16) = v88;
    if ( !v88 || !*(_QWORD *)(v84 + 16) )
    {
      v194 = v82;
      preempt_schedule_notrace(v37);
      v82 = v194;
    }
  }
  _X8 = (unsigned int *)(v82 + 6578);
  __asm { PRFM            #0x11, [X8] }
  do
    v197 = __ldxr(_X8);
  while ( __stxr(v197 + 1, _X8) );
  v205[0] = 0;
  v90 = qdf_list_peek_next((_QWORD *)(a1 + 48), v82, v205);
  if ( (_DWORD)v90 )
    goto LABEL_8;
  v91 = v205[0];
  v39 = v205[0] - 8LL;
  if ( v205[0] != 8 )
  {
    v92 = *(__int64 *)((char *)&off_18 + v205[0]);
    if ( v92 )
    {
      v93 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v93 + 16);
      v94 = *(_QWORD *)(v92 + 1320);
      v95 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v94);
      do
        v96 = __ldxr(v95);
      while ( __stxr(v96 + 1, v95) );
      v97 = *(_QWORD *)(v93 + 16) - 1LL;
      *(_DWORD *)(v93 + 16) = v97;
      if ( !v97 || !*(_QWORD *)(v93 + 16) )
        preempt_schedule_notrace(v90);
    }
    _X8 = (unsigned int *)(v91 + 52624);
    __asm { PRFM            #0x11, [X8] }
    do
      v201 = __ldxr(_X8);
    while ( __stxr(v201 + 1, _X8) );
  }
LABEL_9:
  v40 = *(_QWORD *)(a1 + 40);
  if ( (v40 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v40 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v38 )
      goto LABEL_11;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    if ( v38 )
    {
LABEL_11:
      v49 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        hdd_adapter_dev_put_debug(v38, 0x1Bu, v41, v42, v43, v44, v45, v46, v47, v48);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v49 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v49 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 32);
          if ( v39 )
            goto LABEL_19;
LABEL_13:
          v58 = 0;
          v38 = 0;
          v59 = *(_QWORD *)(a1 + 40);
          if ( (v59 & 1) == 0 )
            goto LABEL_14;
LABEL_32:
          *(_QWORD *)(a1 + 40) = v59 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 32);
          v39 = v58;
          if ( !v38 )
            break;
        }
        else
        {
          raw_spin_lock_bh(a1 + 32);
          *(_QWORD *)(a1 + 40) |= 1uLL;
          if ( !v39 )
            goto LABEL_13;
LABEL_19:
          v205[0] = 0;
          v60 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v39 + 8), v205);
          v58 = v205[0] - 8LL;
          if ( (_DWORD)v60 )
            v69 = 0;
          else
            v69 = v205[0] - 8LL;
          if ( v39 == v69 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v39, 0x1Bu, v50, v51, v52, v53, v54, v55, v56, v57);
            goto LABEL_13;
          }
          if ( v69 )
          {
            v70 = *(_QWORD *)(v69 + 32);
            if ( v70 )
            {
              ++*(_DWORD *)(v49 + 16);
              v71 = *(_QWORD *)(v70 + 1320);
              v72 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v71);
              do
                v73 = __ldxr(v72);
              while ( __stxr(v73 + 1, v72) );
              v74 = *(_QWORD *)(v49 + 16) - 1LL;
              *(_DWORD *)(v49 + 16) = v74;
              if ( !v74 || !*(_QWORD *)(v49 + 16) )
                preempt_schedule_notrace(v60);
            }
            _X8 = (unsigned int *)(v69 + 52632);
            __asm { PRFM            #0x11, [X8] }
            do
              v81 = __ldxr(_X8);
            while ( __stxr(v81 + 1, _X8) );
          }
          else
          {
            v58 = 0;
          }
          v38 = v39;
          v59 = *(_QWORD *)(a1 + 40);
          if ( (v59 & 1) != 0 )
            goto LABEL_32;
LABEL_14:
          raw_spin_unlock(a1 + 32);
          v39 = v58;
          if ( !v38 )
            break;
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v41, v42, v43, v44, v45, v46, v47, v48, "hdd_unregister_wext_all_adapters");
  hdd_abort_mac_scan_all_adapters((__int64 *)a1, v99, v100, v101, v102, v103, v104, v105, v106);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v107 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v107 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v107 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 32);
  }
  else
  {
    raw_spin_lock_bh(a1 + 32);
    *(_QWORD *)(a1 + 40) |= 1uLL;
  }
  v205[0] = 0;
  v108 = qdf_list_peek_front((_QWORD *)(a1 + 48), v205);
  if ( (_DWORD)v108 || (v150 = (_QWORD *)v205[0], v109 = v205[0] - 8LL, v205[0] == 8) )
  {
    v109 = 0;
  }
  else
  {
    v151 = *(__int64 *)((char *)&off_18 + v205[0]);
    if ( v151 )
    {
      v152 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v152 + 16);
      v153 = *(_QWORD *)(v151 + 1320);
      v154 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v153);
      do
        v155 = __ldxr(v154);
      while ( __stxr(v155 + 1, v154) );
      v156 = *(_QWORD *)(v152 + 16) - 1LL;
      *(_DWORD *)(v152 + 16) = v156;
      if ( !v156 || !*(_QWORD *)(v152 + 16) )
      {
        v195 = v150;
        preempt_schedule_notrace(v108);
        v150 = v195;
      }
    }
    _X8 = (unsigned int *)(v150 + 6579);
    __asm { PRFM            #0x11, [X8] }
    do
      v199 = __ldxr(_X8);
    while ( __stxr(v199 + 1, _X8) );
    v205[0] = 0;
    v158 = qdf_list_peek_next((_QWORD *)(a1 + 48), v150, v205);
    if ( !(_DWORD)v158 )
    {
      v159 = v205[0];
      v110 = v205[0] - 8LL;
      if ( v205[0] != 8 )
      {
        v160 = *(__int64 *)((char *)&off_18 + v205[0]);
        if ( v160 )
        {
          v161 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v161 + 16);
          v162 = *(_QWORD *)(v160 + 1320);
          v163 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v162);
          do
            v164 = __ldxr(v163);
          while ( __stxr(v164 + 1, v163) );
          v165 = *(_QWORD *)(v161 + 16) - 1LL;
          *(_DWORD *)(v161 + 16) = v165;
          if ( !v165 || !*(_QWORD *)(v161 + 16) )
            preempt_schedule_notrace(v158);
        }
        _X8 = (unsigned int *)(v159 + 52632);
        __asm { PRFM            #0x11, [X8] }
        do
          v203 = __ldxr(_X8);
        while ( __stxr(v203 + 1, _X8) );
      }
      goto LABEL_62;
    }
  }
  v110 = 0;
LABEL_62:
  v111 = *(_QWORD *)(a1 + 40);
  if ( (v111 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v111 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v109 )
      goto LABEL_64;
  }
  else
  {
    raw_spin_unlock(a1 + 32);
    if ( v109 )
    {
LABEL_64:
      v120 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v131 = *(_DWORD *)(v109 + 40);
        if ( (v131 < 4 || v131 == 7) && (unsigned int)wlan_hdd_sched_scan_stop(*(_QWORD *)(v109 + 32)) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Unable to stop scheduled scan",
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            v119,
            "hdd_abort_sched_scan_all_adapters");
        hdd_adapter_dev_put_debug(v109, 0x1Du, v112, v113, v114, v115, v116, v117, v118, v119);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v120 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v120 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 32);
          if ( v110 )
            goto LABEL_76;
LABEL_66:
          v129 = 0;
          v109 = 0;
          v130 = *(_QWORD *)(a1 + 40);
          if ( (v130 & 1) == 0 )
            goto LABEL_67;
LABEL_89:
          *(_QWORD *)(a1 + 40) = v130 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 32);
          v110 = v129;
          if ( !v109 )
            break;
        }
        else
        {
          raw_spin_lock_bh(a1 + 32);
          *(_QWORD *)(a1 + 40) |= 1uLL;
          if ( !v110 )
            goto LABEL_66;
LABEL_76:
          v205[0] = 0;
          v132 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v110 + 8), v205);
          v129 = v205[0] - 8LL;
          if ( (_DWORD)v132 )
            v141 = 0;
          else
            v141 = v205[0] - 8LL;
          if ( v110 == v141 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v133,
              v134,
              v135,
              v136,
              v137,
              v138,
              v139,
              v140,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v110, 0x1Du, v121, v122, v123, v124, v125, v126, v127, v128);
            goto LABEL_66;
          }
          if ( v141 )
          {
            v142 = *(_QWORD *)(v141 + 32);
            if ( v142 )
            {
              ++*(_DWORD *)(v120 + 16);
              v143 = *(_QWORD *)(v142 + 1320);
              v144 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v143);
              do
                v145 = __ldxr(v144);
              while ( __stxr(v145 + 1, v144) );
              v146 = *(_QWORD *)(v120 + 16) - 1LL;
              *(_DWORD *)(v120 + 16) = v146;
              if ( !v146 || !*(_QWORD *)(v120 + 16) )
                preempt_schedule_notrace(v132);
            }
            _X8 = (unsigned int *)(v141 + 52640);
            __asm { PRFM            #0x11, [X8] }
            do
              v149 = __ldxr(_X8);
            while ( __stxr(v149 + 1, _X8) );
          }
          else
          {
            v129 = 0;
          }
          v109 = v110;
          v130 = *(_QWORD *)(a1 + 40);
          if ( (v130 & 1) != 0 )
            goto LABEL_89;
LABEL_67:
          raw_spin_unlock(a1 + 32);
          v110 = v129;
          if ( !v109 )
            break;
        }
      }
    }
  }
  hdd_stop_all_adapters((__int64 *)a1, v112, v113, v114, v115, v116, v117, v118, v119);
  hdd_deinit_all_adapters(a1, v167, v168, v169, v170, v171, v172, v173, v174);
  v10 = v204;
LABEL_113:
  unregister_netdevice_notifier(&hdd_netdev_notifier);
  qdf_dp_trace_deinit();
  v175 = hdd_wlan_stop_modules(a1, 0);
  hdd_driver_memdump_deinit(v175);
  _qdf_nbuf_deinit_replenish_timer();
  if ( curr_con_mode == 4 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Release wakelock for monitor mode!",
      v176,
      v177,
      v178,
      v179,
      v180,
      v181,
      v182,
      v183,
      "hdd_wlan_exit");
    qdf_wake_lock_release(a1 + 3288, 0x16u);
  }
  qdf_mutex_destroy(a1 + 3624);
  osif_request_manager_deinit();
  v192 = hdd_close_all_adapters((__int64 *)a1, 0, v184, v185, v186, v187, v188, v189, v190, v191);
  wlansap_global_deinit(v192);
  if ( v10 && *(_BYTE *)(v10 + 1304) == 1 )
  {
    wiphy_unregister(v10);
    ((void (__fastcall *)(__int64))wlan_hdd_cfg80211_deinit)(v10);
    hdd_lpass_notify_stop(a1);
  }
  wlan_hdd_free_iface_combination_mem(a1);
  result = hdd_deinit_regulatory_update_event(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
