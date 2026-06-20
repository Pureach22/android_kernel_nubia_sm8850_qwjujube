__int64 __fastcall wlan_hdd_cfg80211_suspend_wlan(
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
  __int64 *v9; // x20
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x21
  unsigned int conparam; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // w0
  int v56; // w20
  const char *v57; // x2
  const char *v58; // x3
  unsigned int v59; // w19
  int suspend_mode; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x21
  __int64 v70; // x21
  __int64 v71; // x21
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _QWORD *v81; // x1
  unsigned int *v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  _QWORD *v99; // x0
  unsigned __int64 v100; // x25
  __int64 v101; // x23
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int *v110; // x8
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int64 v119; // x8
  int v120; // w8
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 vdev_by_user; // x0
  __int64 v130; // x24
  double v131; // d0
  unsigned int *v132; // x8
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  __int64 v164; // x21
  unsigned int *v165; // x8
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  _QWORD *v174; // x1
  const char *v175; // x2
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
  unsigned int *v192; // x8
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  _QWORD *v209; // x0
  unsigned __int64 StatusReg; // x24
  _QWORD *v211; // x27
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  unsigned int *v220; // x8
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  __int64 v229; // x8
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  double v238; // d0
  double v239; // d1
  double v240; // d2
  double v241; // d3
  double v242; // d4
  double v243; // d5
  double v244; // d6
  double v245; // d7
  double v246; // d0
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  double v254; // d0
  double v255; // d1
  double v256; // d2
  double v257; // d3
  double v258; // d4
  double v259; // d5
  double v260; // d6
  double v261; // d7
  double v262; // d0
  double v263; // d1
  double v264; // d2
  double v265; // d3
  double v266; // d4
  double v267; // d5
  double v268; // d6
  double v269; // d7
  double v270; // d0
  double v271; // d1
  double v272; // d2
  double v273; // d3
  double v274; // d4
  double v275; // d5
  double v276; // d6
  double v277; // d7
  __int64 v278; // x0
  __int64 v279; // x0
  __int64 v280; // x0
  double v281; // d0
  double v282; // d1
  double v283; // d2
  double v284; // d3
  double v285; // d4
  double v286; // d5
  double v287; // d6
  double v288; // d7
  __int64 v289; // x0
  __int64 v290; // x0
  double v291; // d0
  __int64 v292; // [xsp+0h] [xbp-30h] BYREF
  _QWORD *v293; // [xsp+8h] [xbp-28h] BYREF
  _QWORD *v294; // [xsp+10h] [xbp-20h] BYREF
  _QWORD v295[3]; // [xsp+18h] [xbp-18h] BYREF

  v295[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v292 = 0;
  if ( !a1 )
  {
    __break(0x800u);
    return wlan_hdd_cfg80211_set_power_mgmt();
  }
  v9 = (__int64 *)(a1 + 1536);
  result = _wlan_hdd_validate_context(
             a1 + 1536,
             (__int64)"wlan_hdd_cfg80211_suspend_wlan",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9);
  if ( (_DWORD)result )
    goto LABEL_17;
  hdd_psoc_idle_timer_stop();
  result = _osif_psoc_sync_op_start(*(_QWORD *)(a1 + 488), &v292, "wlan_hdd_cfg80211_suspend_wlan");
  if ( (_DWORD)result )
    goto LABEL_17;
  if ( *(_DWORD *)(a1 + 3000) != 1 )
  {
    v57 = "%s: Driver Modules not Enabled ";
    v58 = "_wlan_hdd_cfg80211_suspend_wlan";
LABEL_15:
    qdf_trace_msg(0x33u, 8u, v57, v12, v13, v14, v15, v16, v17, v18, v19, v58, v292);
    v20 = 0;
    goto LABEL_16;
  }
  v20 = _wlan_hdd_validate_context(
          (__int64)v9,
          (__int64)"_wlan_hdd_cfg80211_suspend_wlan",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19);
  if ( v20 )
    goto LABEL_16;
  if ( !_cds_get_context(61, (__int64)"_wlan_hdd_cfg80211_suspend_wlan", v21, v22, v23, v24, v25, v26, v27, v28) )
  {
    v20 = -22;
    goto LABEL_16;
  }
  v20 = qdf_runtime_pm_prevent_suspend_sync((__int64 *)(a1 + 3240));
  if ( v20 )
    goto LABEL_16;
  v293 = nullptr;
  v294 = nullptr;
  v295[0] = 0xFFFFFFFFFFFFLL;
  v295[1] = 0xC000300000000LL;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "__wlan_hdd_cfg80211_suspend_wlan",
    v292);
  if ( (unsigned int)hdd_get_conparam() == 5 || (unsigned int)hdd_get_conparam() == 4 )
  {
    v45 = jiffies;
    if ( _wlan_hdd_cfg80211_suspend_wlan___last_ticks - jiffies + 125 < 0 )
    {
      conparam = hdd_get_conparam();
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in mode %d",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "__wlan_hdd_cfg80211_suspend_wlan",
        conparam);
      _wlan_hdd_cfg80211_suspend_wlan___last_ticks = v45;
    }
LABEL_12:
    v55 = -22;
    goto LABEL_13;
  }
  v55 = _wlan_hdd_validate_context(
          (__int64)v9,
          (__int64)"__wlan_hdd_cfg80211_suspend_wlan",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44);
  if ( v55 )
    goto LABEL_13;
  if ( *(_DWORD *)(a1 + 3000) != 1 )
  {
    v57 = "%s: Driver Modules not Enabled ";
LABEL_26:
    v58 = "__wlan_hdd_cfg80211_suspend_wlan";
    goto LABEL_15;
  }
  suspend_mode = ucfg_pmo_get_suspend_mode(*v9);
  if ( suspend_mode == 3 )
  {
    v70 = jiffies;
    if ( _wlan_hdd_cfg80211_suspend_wlan___last_ticks_113 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: shutdown suspend should complete in prepare",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "__wlan_hdd_cfg80211_suspend_wlan");
      _wlan_hdd_cfg80211_suspend_wlan___last_ticks_113 = v70;
    }
    goto LABEL_12;
  }
  if ( !suspend_mode )
  {
    v69 = jiffies;
    if ( _wlan_hdd_cfg80211_suspend_wlan___last_ticks_112 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Suspend is not supported",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "__wlan_hdd_cfg80211_suspend_wlan");
      _wlan_hdd_cfg80211_suspend_wlan___last_ticks_112 = v69;
    }
    goto LABEL_12;
  }
  v71 = *(_QWORD *)(a1 + 1552);
  qdf_spin_lock_bh_7(a1 + 1568);
  hdd_get_front_adapter_no_lock((__int64)v9, &v294);
  if ( v294 )
  {
    hdd_adapter_dev_hold_debug((__int64)v294, 0x36u, v72, v73, v74, v75, v76, v77, v78, v79, v80);
    v81 = v294;
  }
  else
  {
    v81 = nullptr;
  }
  hdd_get_next_adapter_no_lock((__int64)v9, (__int64)v81, &v293);
  if ( v293 )
    hdd_adapter_dev_hold_debug((__int64)v293, 0x36u, v82, v83, v84, v85, v86, v87, v88, v89, v90);
  qdf_spin_unlock_bh_5(a1 + 1568);
  v99 = v294;
  if ( !v294 )
  {
LABEL_71:
    ucfg_p2p_cleanup_tx_by_psoc(*v9, v91, v92, v93, v94, v95, v96, v97, v98);
    ucfg_p2p_cleanup_roc_by_psoc(*v9, v140, v141, v142, v143, v144, v145, v146, v147);
    if ( (hdd_is_connection_in_progress(nullptr, nullptr, v148, v149, v150, v151, v152, v153, v154, v155) & 1) != 0 )
    {
      v164 = jiffies;
      if ( _wlan_hdd_cfg80211_suspend_wlan___last_ticks_118 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Connection is in progress, rejecting suspend",
          v156,
          v157,
          v158,
          v159,
          v160,
          v161,
          v162,
          v163,
          "__wlan_hdd_cfg80211_suspend_wlan");
        _wlan_hdd_cfg80211_suspend_wlan___last_ticks_118 = v164;
      }
      goto LABEL_12;
    }
    qdf_spin_lock_bh_7(a1 + 1568);
    hdd_get_front_adapter_no_lock((__int64)v9, &v294);
    if ( v294 )
    {
      hdd_adapter_dev_hold_debug((__int64)v294, 0x36u, v165, v166, v167, v168, v169, v170, v171, v172, v173);
      v174 = v294;
    }
    else
    {
      v174 = nullptr;
    }
    hdd_get_next_adapter_no_lock((__int64)v9, (__int64)v174, &v293);
    if ( v293 )
      hdd_adapter_dev_hold_debug((__int64)v293, 0x36u, v192, v193, v194, v195, v196, v197, v198, v199, v200);
    qdf_spin_unlock_bh_5(a1 + 1568);
    v209 = v294;
    if ( v294 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      do
      {
        while ( 1 )
        {
          if ( (v209[205] & 1) != 0 )
          {
            v211 = v209 + 6604;
            if ( v209 != (_QWORD *)-52832LL )
            {
              do
              {
                if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                                      *((_BYTE *)v211 + 8),
                                      (__int64)"__wlan_hdd_cfg80211_suspend_wlan",
                                      v201,
                                      v202,
                                      v203,
                                      v204,
                                      v205,
                                      v206,
                                      v207,
                                      v208) )
                  sme_ps_timer_flush_sync(v71, *((unsigned __int8 *)v211 + 8));
                v209 = v294;
                if ( v294 )
                {
                  if ( (unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v211 - *(_DWORD *)v211 - 52832) >> 4))
                    || (v294[205] & 1) == 0 )
                  {
                    break;
                  }
                  v211 = v294 + 6604;
                }
              }
              while ( v211 );
            }
          }
          hdd_adapter_dev_put_debug((__int64)v209, 0x36u, v201, v202, v203, v204, v205, v206, v207, v208);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a1 + 1568);
          }
          else
          {
            raw_spin_lock_bh(a1 + 1568);
            *(_QWORD *)(a1 + 1576) |= 1uLL;
          }
          v294 = v293;
          hdd_get_next_adapter_no_lock((__int64)v9, (__int64)v293, &v293);
          hdd_validate_next_adapter((__int64 *)&v294, &v293, 0x36u, v212, v213, v214, v215, v216, v217, v218, v219);
          if ( v293 )
            hdd_adapter_dev_hold_debug((__int64)v293, 0x36u, v220, v221, v222, v223, v224, v225, v226, v227, v228);
          v229 = *(_QWORD *)(a1 + 1576);
          if ( (v229 & 1) != 0 )
            break;
          raw_spin_unlock(a1 + 1568);
          v209 = v294;
          if ( !v294 )
            goto LABEL_107;
        }
        *(_QWORD *)(a1 + 1576) = v229 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 1568);
        v209 = v294;
      }
      while ( v294 );
    }
LABEL_107:
    hdd_pause_ns(v9);
    if ( (unsigned int)ucfg_pmo_suspend_all_components(*v9, 0) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Some components not ready to suspend!",
        v230,
        v231,
        v232,
        v233,
        v234,
        v235,
        v236,
        v237,
        "__wlan_hdd_cfg80211_suspend_wlan");
      v55 = -11;
      goto LABEL_13;
    }
    wlan_hdd_suspend_pmo_twt(v9);
    if ( (unsigned int)ucfg_ipa_suspend(*(_QWORD *)(a1 + 1544)) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: IPA not ready to suspend!",
        v238,
        v239,
        v240,
        v241,
        v242,
        v243,
        v244,
        v245,
        "__wlan_hdd_cfg80211_suspend_wlan");
      wlan_hdd_inc_suspend_stats((unsigned int *)v9, 0, v246, v247, v248, v249, v250, v251, v252, v253);
LABEL_121:
      v291 = ucfg_pmo_resume_all_components(*v9, 0);
      hdd_unpause_ns(v9, v291);
      v55 = -62;
      goto LABEL_13;
    }
    scheduler_register_hdd_suspend_callback((__int64)hdd_suspend_cb);
    v278 = scheduler_set_event_mask(2);
    scheduler_wake_up_controller_thread(v278);
    if ( (unsigned int)wait_for_completion_timeout(a1 + 1688, 300) )
    {
      v279 = *(_QWORD *)(a1 + 1536);
      *(_BYTE *)(a1 + 1720) = 1;
      ucfg_dp_is_rx_common_thread_enabled(v279);
      v280 = qdf_mtrace(51, 51, 0x42u, 0xFFu, *(unsigned __int8 *)(a1 + 2024));
      if ( (hdd_suspend_wlan(v280) & 0x80000000) == 0 )
      {
        v57 = "%s: exit";
        *(_BYTE *)(a1 + 2024) = 1;
        goto LABEL_26;
      }
      v290 = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Failed to suspend WLAN",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "__wlan_hdd_cfg80211_suspend_wlan");
      v289 = scheduler_resume(v290);
      *(_BYTE *)(a1 + 1720) = 0;
    }
    else
    {
      scheduler_clear_event_mask(2);
      v289 = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Failed to stop mc thread",
               v281,
               v282,
               v283,
               v284,
               v285,
               v286,
               v287,
               v288,
               "__wlan_hdd_cfg80211_suspend_wlan");
    }
    hdd_resume_wlan(v289);
    goto LABEL_121;
  }
  v100 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (v99[205] & 1) != 0 )
    {
      v101 = (__int64)(v99 + 6604);
      if ( v99 != (_QWORD *)-52832LL )
        break;
    }
LABEL_38:
    hdd_adapter_dev_put_debug((__int64)v99, 0x36u, v91, v92, v93, v94, v95, v96, v97, v98);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v100 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v100 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1568);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1568);
      *(_QWORD *)(a1 + 1576) |= 1uLL;
    }
    v294 = v293;
    hdd_get_next_adapter_no_lock((__int64)v9, (__int64)v293, &v293);
    hdd_validate_next_adapter((__int64 *)&v294, &v293, 0x36u, v102, v103, v104, v105, v106, v107, v108, v109);
    if ( v293 )
      hdd_adapter_dev_hold_debug((__int64)v293, 0x36u, v110, v111, v112, v113, v114, v115, v116, v117, v118);
    v119 = *(_QWORD *)(a1 + 1576);
    if ( (v119 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1576) = v119 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1568);
      v99 = v294;
      if ( !v294 )
        goto LABEL_71;
    }
    else
    {
      raw_spin_unlock(a1 + 1568);
      v99 = v294;
      if ( !v294 )
        goto LABEL_71;
    }
  }
  while ( 1 )
  {
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(_BYTE *)(v101 + 8),
                         (__int64)"__wlan_hdd_cfg80211_suspend_wlan",
                         v91,
                         v92,
                         v93,
                         v94,
                         v95,
                         v96,
                         v97,
                         v98) )
      goto LABEL_50;
    v99 = v294;
    v120 = *((_DWORD *)v294 + 10);
    if ( v120 == 15 )
    {
      if ( (ucfg_pmo_get_disconnect_sap_tdls_in_wow(*v9) & 1) != 0 )
      {
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(v101, 0x11u, (__int64)"__wlan_hdd_cfg80211_suspend_wlan");
        if ( vdev_by_user )
        {
          v130 = vdev_by_user;
          v131 = ucfg_tdls_teardown_links_sync(*v9, vdev_by_user);
          _hdd_objmgr_put_vdev_by_user(
            v130,
            0x11u,
            (__int64)"__wlan_hdd_cfg80211_suspend_wlan",
            v132,
            v131,
            v133,
            v134,
            v135,
            v136,
            v137,
            v138,
            v139);
        }
      }
      goto LABEL_50;
    }
    if ( v120 == 3 )
    {
      if ( (ucfg_pmo_get_enable_sap_suspend(*v9) & 1) == 0 )
      {
        v175 = "%s: GO does not support suspend!!";
        goto LABEL_77;
      }
LABEL_63:
      if ( (ucfg_pmo_get_disconnect_sap_tdls_in_wow(*v9) & 1) != 0 )
        hdd_softap_deauth_all_sta(v294, v295, v91, v92, v93, v94, v95, v96, v97, v98);
LABEL_50:
      v99 = v294;
      goto LABEL_51;
    }
    if ( v120 == 1 )
      break;
LABEL_51:
    if ( v99 )
    {
      if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v101 - *(_DWORD *)v101 - 52832) >> 4)) || (v99[205] & 1) == 0 )
        goto LABEL_38;
      v101 = (__int64)(v99 + 6604);
    }
    if ( !v101 )
      goto LABEL_38;
  }
  if ( *(_DWORD *)(v101 + 80) != 1 || *(_BYTE *)(v101 + 256) != 1 )
  {
    if ( (ucfg_pmo_get_enable_sap_suspend(*v9) & 1) == 0 )
    {
      v175 = "%s: SAP does not support suspend!!";
LABEL_77:
      qdf_trace_msg(0x33u, 2u, v175, v121, v122, v123, v124, v125, v126, v127, v128, "__wlan_hdd_cfg80211_suspend_wlan");
      hdd_adapter_dev_put_debug((__int64)v294, 0x36u, v176, v177, v178, v179, v180, v181, v182, v183);
      if ( v293 )
        hdd_adapter_dev_put_debug((__int64)v293, 0x36u, v184, v185, v186, v187, v188, v189, v190, v191);
      v55 = -95;
      goto LABEL_13;
    }
    goto LABEL_63;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: RADAR detection in progress, do not allow suspend",
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    "__wlan_hdd_cfg80211_suspend_wlan");
  wlan_hdd_inc_suspend_stats((unsigned int *)v9, 1u, v254, v255, v256, v257, v258, v259, v260, v261);
  hdd_adapter_dev_put_debug((__int64)v294, 0x36u, v262, v263, v264, v265, v266, v267, v268, v269);
  if ( v293 )
    hdd_adapter_dev_put_debug((__int64)v293, 0x36u, v270, v271, v272, v273, v274, v275, v276, v277);
  v55 = -11;
LABEL_13:
  v56 = v55;
  qdf_runtime_pm_allow_suspend((__int64 *)(a1 + 3240));
  v20 = v56;
LABEL_16:
  v59 = v20;
  _osif_psoc_sync_op_stop(v292, "wlan_hdd_cfg80211_suspend_wlan");
  result = v59;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
