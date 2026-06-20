__int64 __fastcall hdd_start_all_adapters(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x20
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 v23; // x24
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x28
  __int64 v33; // x8
  const char *v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w8
  __int64 v52; // x28
  unsigned int started; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w8
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
  __int64 v95; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x21
  __int64 v105; // x8
  __int64 v106; // x8
  unsigned int *v107; // x8
  unsigned int v108; // w10
  __int64 v109; // x8
  unsigned int v116; // w9
  _QWORD *v117; // x1
  __int64 v118; // x9
  unsigned __int64 v119; // x8
  __int64 v120; // x9
  unsigned int *v121; // x9
  unsigned int v122; // w12
  __int64 v123; // x9
  __int64 v125; // x0
  __int64 v126; // x22
  __int64 v127; // x9
  unsigned __int64 v128; // x8
  __int64 v129; // x9
  unsigned int *v130; // x9
  unsigned int v131; // w12
  __int64 v132; // x9
  unsigned __int64 v134; // x8
  __int64 v135; // x0
  __int64 v136; // x21
  __int64 v137; // x9
  unsigned __int64 v138; // x8
  __int64 v139; // x9
  unsigned int *v140; // x9
  unsigned int v141; // w12
  __int64 v142; // x9
  _QWORD *v144; // x1
  __int64 v145; // x9
  unsigned __int64 v146; // x8
  __int64 v147; // x9
  unsigned int *v148; // x9
  unsigned int v149; // w12
  __int64 v150; // x9
  __int64 v152; // x8
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  unsigned __int64 v161; // x26
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  __int64 v170; // x20
  __int64 v171; // x8
  __int64 v172; // x0
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  __int64 v181; // x21
  __int64 v182; // x8
  __int64 v183; // x8
  unsigned int *v184; // x8
  unsigned int v185; // w10
  __int64 v186; // x8
  unsigned int v189; // w9
  unsigned __int64 v190; // x8
  __int64 v191; // x0
  __int64 v192; // x20
  __int64 v193; // x21
  __int64 v194; // x8
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  unsigned __int64 v203; // x24
  __int64 v204; // x0
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  __int64 v213; // x27
  __int64 v214; // x20
  __int64 v215; // x8
  __int64 v216; // x8
  unsigned int *v217; // x8
  unsigned int v218; // w10
  __int64 v219; // x8
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  __int64 v229; // x8
  unsigned int v231; // w9
  _QWORD *v232; // x1
  __int64 v233; // x9
  unsigned __int64 v234; // x8
  __int64 v235; // x9
  unsigned int *v236; // x9
  unsigned int v237; // w12
  __int64 v238; // x9
  __int64 v240; // x0
  __int64 v241; // x22
  __int64 v242; // x9
  unsigned __int64 v243; // x8
  __int64 v244; // x9
  unsigned int *v245; // x9
  unsigned int v246; // w12
  __int64 v247; // x9
  unsigned __int64 v249; // x8
  __int64 v250; // x0
  __int64 v251; // x25
  __int64 v252; // x22
  __int64 v253; // x8
  double v254; // d0
  double v255; // d1
  double v256; // d2
  double v257; // d3
  double v258; // d4
  double v259; // d5
  double v260; // d6
  double v261; // d7
  unsigned __int64 v262; // x26
  double v263; // d0
  double v264; // d1
  double v265; // d2
  double v266; // d3
  double v267; // d4
  double v268; // d5
  double v269; // d6
  double v270; // d7
  __int64 v271; // x21
  __int64 v272; // x8
  __int64 v273; // x0
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  __int64 v282; // x25
  __int64 v283; // x8
  __int64 v284; // x8
  unsigned int *v285; // x8
  unsigned int v286; // w10
  __int64 v287; // x8
  unsigned int v290; // w9
  _QWORD *v291; // x1
  __int64 v292; // x9
  unsigned __int64 v293; // x8
  __int64 v294; // x9
  unsigned int *v295; // x9
  unsigned int v296; // w12
  __int64 v297; // x9
  __int64 v299; // x0
  __int64 v300; // x21
  __int64 v301; // x9
  unsigned __int64 v302; // x8
  __int64 v303; // x9
  unsigned int *v304; // x9
  unsigned int v305; // w12
  __int64 v306; // x9
  double v308; // d0
  double v309; // d1
  double v310; // d2
  double v311; // d3
  double v312; // d4
  double v313; // d5
  double v314; // d6
  double v315; // d7
  double v316; // d0
  double v317; // d1
  double v318; // d2
  double v319; // d3
  double v320; // d4
  double v321; // d5
  double v322; // d6
  double v323; // d7
  _QWORD *v325; // x20
  _QWORD *v326; // x20
  _QWORD *v327; // x21
  _QWORD *v328; // x21
  unsigned int v330; // w9
  unsigned int v332; // w9
  unsigned int v334; // w9
  unsigned int v336; // w9
  unsigned int v338; // w9
  unsigned int v340; // w9
  unsigned int v342; // w9
  unsigned int v344; // w9
  char v345; // [xsp+8h] [xbp-18h]
  _BYTE v346[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v347[2]; // [xsp+10h] [xbp-10h] BYREF

  v347[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v346[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_start_all_adapters");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 4);
  }
  else
  {
    raw_spin_lock_bh(a1 + 4);
    a1[5] |= 1uLL;
  }
  v347[0] = 0;
  v11 = qdf_list_peek_front(a1 + 6, v347);
  if ( (_DWORD)v11 || (v117 = (_QWORD *)v347[0], v12 = v347[0] - 8LL, v347[0] == 8) )
  {
    v12 = 0;
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
  v118 = *(__int64 *)((char *)&off_18 + v347[0]);
  if ( v118 )
  {
    v119 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v119 + 16);
    v120 = *(_QWORD *)(v118 + 1320);
    v121 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v120);
    do
      v122 = __ldxr(v121);
    while ( __stxr(v122 + 1, v121) );
    v123 = *(_QWORD *)(v119 + 16) - 1LL;
    *(_DWORD *)(v119 + 16) = v123;
    if ( !v123 || !*(_QWORD *)(v119 + 16) )
    {
      v325 = v117;
      preempt_schedule_notrace(v11);
      v117 = v325;
    }
  }
  _X8 = (unsigned int *)(v117 + 6574);
  __asm { PRFM            #0x11, [X8] }
  do
    v332 = __ldxr(_X8);
  while ( __stxr(v332 + 1, _X8) );
  v347[0] = 0;
  v125 = qdf_list_peek_next(a1 + 6, v117, v347);
  if ( (_DWORD)v125 )
    goto LABEL_7;
  v126 = v347[0];
  v13 = v347[0] - 8LL;
  if ( v347[0] != 8 )
  {
    v127 = *(__int64 *)((char *)&off_18 + v347[0]);
    if ( v127 )
    {
      v128 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v128 + 16);
      v129 = *(_QWORD *)(v127 + 1320);
      v130 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v129);
      do
        v131 = __ldxr(v130);
      while ( __stxr(v131 + 1, v130) );
      v132 = *(_QWORD *)(v128 + 16) - 1LL;
      *(_DWORD *)(v128 + 16) = v132;
      if ( !v132 || !*(_QWORD *)(v128 + 16) )
        preempt_schedule_notrace(v125);
    }
    _X8 = (unsigned int *)(v126 + 52592);
    __asm { PRFM            #0x11, [X8] }
    do
      v340 = __ldxr(_X8);
    while ( __stxr(v340 + 1, _X8) );
  }
LABEL_8:
  v14 = a1[5];
  if ( (v14 & 1) != 0 )
  {
    a1[5] = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( v12 )
      goto LABEL_10;
  }
  else
  {
    raw_spin_unlock(a1 + 4);
    if ( v12 )
    {
LABEL_10:
      v23 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (*(_QWORD *)(v12 + 1624) & 4) == 0 && *(_DWORD *)(v12 + 40) != 11 )
          goto LABEL_50;
        v34 = qdf_opmode_str(*(_DWORD *)(v12 + 40));
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: [SSR] start adapter with device mode %s(%d)",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "hdd_start_all_adapters",
          v34,
          *(unsigned int *)(v12 + 40));
        hdd_wmm_dscp_initial_state(v12);
        v51 = *(_DWORD *)(v12 + 40);
        if ( v51 <= 5 )
          break;
        if ( v51 > 10 )
        {
          if ( v51 == 11 )
          {
            hdd_ndi_start(*(_QWORD *)(v12 + 32) + 296LL, 0);
LABEL_47:
            if ( (unsigned int)hdd_set_fw_params(v12, v43, v44, v45, v46, v47, v48, v49, v50) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to set adapter FW params after SSR!",
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                "hdd_start_all_adapters");
            wlan_hdd_cfg80211_register_frames(v12, v79, v80, v81, v82, v83, v84, v85, v86);
            wlan_hdd_update_dbs_scan_and_fw_mode_config(
              *(_BYTE *)(*(_QWORD *)(v12 + 52832) + 8LL),
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              v94);
            hdd_create_adapter_sysfs_files(v12);
            goto LABEL_50;
          }
          if ( v51 != 16 )
            goto LABEL_47;
          goto LABEL_33;
        }
        if ( v51 != 6 )
        {
          if ( v51 != 7 )
            goto LABEL_47;
          if ( (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*a1) & 1) != 0 )
          {
            v52 = jiffies;
            if ( hdd_start_all_adapters___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: Do not create new vdev, use STA vdev for P2P device mode",
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                "hdd_start_all_adapters");
              hdd_start_all_adapters___last_ticks = v52;
            }
            goto LABEL_47;
          }
LABEL_33:
          started = hdd_start_station_adapter(v12, v43, v44, v45, v46, v47, v48, v49, v50);
          if ( !started )
          {
            v62 = *(_DWORD *)(v12 + 40);
            *(_BYTE *)(v12 + 1808) = 0;
            if ( (v62 == 16 || !v62 && (ucfg_nan_is_vdev_creation_allowed(*a1) & 1) == 0)
              && (cds_get_driver_state(v54, v55, v56, v57, v58, v59, v60, v61) & 8) != 0 )
            {
              ucfg_nan_disable_ind_to_userspace(*a1);
            }
            hdd_lpass_notify_start(*(_QWORD *)(v12 + 52832));
            goto LABEL_47;
          }
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: [SSR] Failed to start station adapter: %d",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "hdd_start_all_adapters",
            started);
          goto LABEL_50;
        }
        if ( _cds_get_context(51, (__int64)"wlan_hdd_is_session_type_monitor", v43, v44, v45, v46, v47, v48, v49, v50) )
          cds_get_conparam();
        else
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: HDD context is NULL",
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            "wlan_hdd_is_session_type_monitor");
        hdd_start_station_adapter(v12, v71, v72, v73, v74, v75, v76, v77, v78);
        if ( !(unsigned int)hdd_set_mon_rx_cb(*(_QWORD *)(v12 + 32)) )
        {
          wlan_hdd_set_mon_chan(v12, v15, v16, v17, v18, v19, v20, v21, v22);
          goto LABEL_47;
        }
LABEL_50:
        hdd_adapter_dev_put_debug(v12, 0x13u, v15, v16, v17, v18, v19, v20, v21, v22);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v23 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 4);
          if ( v13 )
            goto LABEL_54;
LABEL_12:
          v32 = 0;
          v12 = 0;
          v33 = a1[5];
          if ( (v33 & 1) == 0 )
            goto LABEL_13;
LABEL_67:
          a1[5] = v33 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 4);
          v13 = v32;
          if ( !v12 )
            goto LABEL_91;
        }
        else
        {
          raw_spin_lock_bh(a1 + 4);
          a1[5] |= 1uLL;
          if ( !v13 )
            goto LABEL_12;
LABEL_54:
          v347[0] = 0;
          v95 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v13 + 8), v347);
          v32 = v347[0] - 8LL;
          if ( (_DWORD)v95 )
            v104 = 0;
          else
            v104 = v347[0] - 8LL;
          if ( v13 == v104 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v13, 0x13u, v24, v25, v26, v27, v28, v29, v30, v31);
            goto LABEL_12;
          }
          if ( v104 )
          {
            v105 = *(_QWORD *)(v104 + 32);
            if ( v105 )
            {
              ++*(_DWORD *)(v23 + 16);
              v106 = *(_QWORD *)(v105 + 1320);
              v107 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v106);
              do
                v108 = __ldxr(v107);
              while ( __stxr(v108 + 1, v107) );
              v109 = *(_QWORD *)(v23 + 16) - 1LL;
              *(_DWORD *)(v23 + 16) = v109;
              if ( !v109 || !*(_QWORD *)(v23 + 16) )
                preempt_schedule_notrace(v95);
            }
            _X8 = (unsigned int *)(v104 + 52600);
            __asm { PRFM            #0x11, [X8] }
            do
              v116 = __ldxr(_X8);
            while ( __stxr(v116 + 1, _X8) );
          }
          else
          {
            v32 = 0;
          }
          v12 = v13;
          v33 = a1[5];
          if ( (v33 & 1) != 0 )
            goto LABEL_67;
LABEL_13:
          raw_spin_unlock(a1 + 4);
          v13 = v32;
          if ( !v12 )
            goto LABEL_91;
        }
      }
      if ( v51 > 1 )
      {
        if ( v51 != 2 )
        {
          if ( v51 == 3 )
          {
            WORD2(v347[0]) = -1;
            LODWORD(v347[0]) = -1;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: [SSR] send restart supplicant",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "hdd_delete_sta");
            cfg80211_del_sta_sinfo(*(_QWORD *)(v12 + 32), v347, 0, 3264);
          }
          goto LABEL_47;
        }
      }
      else if ( v51 )
      {
        if ( v51 == 1 )
        {
          wlan_mlme_get_sap_internal_restart(*a1, v346);
          if ( v346[0] == 1 )
            hdd_start_ap_adapter(v12, v43, v44, v45, v46, v47, v48, v49, v50);
        }
        goto LABEL_47;
      }
      goto LABEL_33;
    }
  }
  v32 = v13;
LABEL_91:
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v134 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v134 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v134 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 4);
  }
  else
  {
    raw_spin_lock_bh(a1 + 4);
    a1[5] |= 1uLL;
  }
  v347[0] = 0;
  v135 = qdf_list_peek_front(a1 + 6, v347);
  if ( (_DWORD)v135 || (v144 = (_QWORD *)v347[0], v136 = v347[0] - 8LL, v347[0] == 8) )
  {
    v136 = 0;
    if ( !v32 )
      goto LABEL_112;
LABEL_97:
    v137 = *(_QWORD *)(v32 + 32);
    if ( v137 )
    {
      v138 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v138 + 16);
      v139 = *(_QWORD *)(v137 + 1320);
      v140 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v139);
      do
        v141 = __ldxr(v140);
      while ( __stxr(v141 + 1, v140) );
      v142 = *(_QWORD *)(v138 + 16) - 1LL;
      *(_DWORD *)(v138 + 16) = v142;
      if ( !v142 || !*(_QWORD *)(v138 + 16) )
        preempt_schedule_notrace(v135);
    }
    _X8 = (unsigned int *)(v32 + 52600);
    __asm { PRFM            #0x11, [X8] }
    do
      v330 = __ldxr(_X8);
    while ( __stxr(v330 + 1, _X8) );
    goto LABEL_112;
  }
  v145 = *(__int64 *)((char *)&off_18 + v347[0]);
  if ( v145 )
  {
    v146 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v146 + 16);
    v147 = *(_QWORD *)(v145 + 1320);
    v148 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v147);
    do
      v149 = __ldxr(v148);
    while ( __stxr(v149 + 1, v148) );
    v150 = *(_QWORD *)(v146 + 16) - 1LL;
    *(_DWORD *)(v146 + 16) = v150;
    if ( !v150 || !*(_QWORD *)(v146 + 16) )
    {
      v326 = v144;
      preempt_schedule_notrace(v135);
      v144 = v326;
    }
  }
  _X8 = (unsigned int *)(v144 + 6574);
  __asm { PRFM            #0x11, [X8] }
  do
    v334 = __ldxr(_X8);
  while ( __stxr(v334 + 1, _X8) );
  v347[0] = 0;
  v135 = qdf_list_peek_next(a1 + 6, v144, v347);
  if ( (_DWORD)v135 )
  {
    v32 = 0;
    goto LABEL_112;
  }
  v32 = v347[0] - 8LL;
  if ( v347[0] != 8 )
    goto LABEL_97;
LABEL_112:
  v152 = a1[5];
  if ( (v152 & 1) != 0 )
  {
    a1[5] = v152 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( v136 )
      goto LABEL_114;
  }
  else
  {
    raw_spin_unlock(a1 + 4);
    if ( v136 )
    {
LABEL_114:
      v161 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (*(_QWORD *)(v136 + 1624) & 4) != 0 && *(_DWORD *)(v136 + 40) == 3 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: [SSR] send stop iface ap to supplicant",
            v153,
            v154,
            v155,
            v156,
            v157,
            v158,
            v159,
            v160,
            "hdd_stop_p2p_go");
          v153 = cfg80211_stop_iface(*(_QWORD *)(*(_QWORD *)(v136 + 24) + 24LL), v136 + 112, 3264);
        }
        hdd_adapter_dev_put_debug(v136, 0x13u, v153, v154, v155, v156, v157, v158, v159, v160);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v161 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v161 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 4);
          if ( v32 )
            goto LABEL_125;
LABEL_116:
          v170 = 0;
          v136 = 0;
          v171 = a1[5];
          if ( (v171 & 1) == 0 )
            goto LABEL_117;
LABEL_138:
          a1[5] = v171 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 4);
          v32 = v170;
          if ( !v136 )
            break;
        }
        else
        {
          raw_spin_lock_bh(a1 + 4);
          a1[5] |= 1uLL;
          if ( !v32 )
            goto LABEL_116;
LABEL_125:
          v347[0] = 0;
          v172 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v32 + 8), v347);
          v170 = v347[0] - 8LL;
          if ( (_DWORD)v172 )
            v181 = 0;
          else
            v181 = v347[0] - 8LL;
          if ( v32 == v181 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v173,
              v174,
              v175,
              v176,
              v177,
              v178,
              v179,
              v180,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v32, 0x13u, v162, v163, v164, v165, v166, v167, v168, v169);
            goto LABEL_116;
          }
          if ( v181 )
          {
            v182 = *(_QWORD *)(v181 + 32);
            if ( v182 )
            {
              ++*(_DWORD *)(v161 + 16);
              v183 = *(_QWORD *)(v182 + 1320);
              v184 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v183);
              do
                v185 = __ldxr(v184);
              while ( __stxr(v185 + 1, v184) );
              v186 = *(_QWORD *)(v161 + 16) - 1LL;
              *(_DWORD *)(v161 + 16) = v186;
              if ( !v186 || !*(_QWORD *)(v161 + 16) )
                preempt_schedule_notrace(v172);
            }
            _X8 = (unsigned int *)(v181 + 52600);
            __asm { PRFM            #0x11, [X8] }
            do
              v189 = __ldxr(_X8);
            while ( __stxr(v189 + 1, _X8) );
          }
          else
          {
            v170 = 0;
          }
          v136 = v32;
          v171 = a1[5];
          if ( (v171 & 1) != 0 )
            goto LABEL_138;
LABEL_117:
          raw_spin_unlock(a1 + 4);
          v32 = v170;
          if ( !v136 )
            break;
        }
      }
    }
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v190 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v190 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v190 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 4);
  }
  else
  {
    raw_spin_lock_bh(a1 + 4);
    a1[5] |= 1uLL;
  }
  v347[0] = 0;
  v191 = qdf_list_peek_front(a1 + 6, v347);
  if ( (_DWORD)v191 || (v232 = (_QWORD *)v347[0], v192 = v347[0] - 8LL, v347[0] == 8) )
  {
    v192 = 0;
LABEL_154:
    v193 = 0;
    goto LABEL_155;
  }
  v233 = *(__int64 *)((char *)&off_18 + v347[0]);
  if ( v233 )
  {
    v234 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v234 + 16);
    v235 = *(_QWORD *)(v233 + 1320);
    v236 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v235);
    do
      v237 = __ldxr(v236);
    while ( __stxr(v237 + 1, v236) );
    v238 = *(_QWORD *)(v234 + 16) - 1LL;
    *(_DWORD *)(v234 + 16) = v238;
    if ( !v238 || !*(_QWORD *)(v234 + 16) )
    {
      v327 = v232;
      preempt_schedule_notrace(v191);
      v232 = v327;
    }
  }
  _X8 = (unsigned int *)(v232 + 6574);
  __asm { PRFM            #0x11, [X8] }
  do
    v336 = __ldxr(_X8);
  while ( __stxr(v336 + 1, _X8) );
  v347[0] = 0;
  v240 = qdf_list_peek_next(a1 + 6, v232, v347);
  if ( (_DWORD)v240 )
    goto LABEL_154;
  v241 = v347[0];
  v193 = v347[0] - 8LL;
  if ( v347[0] != 8 )
  {
    v242 = *(__int64 *)((char *)&off_18 + v347[0]);
    if ( v242 )
    {
      v243 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v243 + 16);
      v244 = *(_QWORD *)(v242 + 1320);
      v245 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v244);
      do
        v246 = __ldxr(v245);
      while ( __stxr(v246 + 1, v245) );
      v247 = *(_QWORD *)(v243 + 16) - 1LL;
      *(_DWORD *)(v243 + 16) = v247;
      if ( !v247 || !*(_QWORD *)(v243 + 16) )
        preempt_schedule_notrace(v240);
    }
    _X8 = (unsigned int *)(v241 + 52592);
    __asm { PRFM            #0x11, [X8] }
    do
      v342 = __ldxr(_X8);
    while ( __stxr(v342 + 1, _X8) );
  }
LABEL_155:
  v194 = a1[5];
  if ( (v194 & 1) != 0 )
  {
    a1[5] = v194 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( v192 )
      goto LABEL_157;
LABEL_208:
    v345 = 1;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_211;
    goto LABEL_209;
  }
  raw_spin_unlock(a1 + 4);
  if ( !v192 )
    goto LABEL_208;
LABEL_157:
  v203 = _ReadStatusReg(SP_EL0);
  while ( (*(_QWORD *)(v192 + 1624) & 4) == 0 || *(_DWORD *)(v192 + 40) )
  {
    hdd_adapter_dev_put_debug(v192, 0x13u, v195, v196, v197, v198, v199, v200, v201, v202);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v203 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v203 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4);
      if ( v193 )
        goto LABEL_164;
    }
    else
    {
      raw_spin_lock_bh(a1 + 4);
      a1[5] |= 1uLL;
      if ( v193 )
      {
LABEL_164:
        v347[0] = 0;
        v204 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v193 + 8), v347);
        v213 = v347[0] - 8LL;
        if ( (_DWORD)v204 )
          v214 = 0;
        else
          v214 = v347[0] - 8LL;
        if ( v193 == v214 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v205,
            v206,
            v207,
            v208,
            v209,
            v210,
            v211,
            v212,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v193, 0x13u, v221, v222, v223, v224, v225, v226, v227, v228);
          v192 = 0;
          v193 = 0;
        }
        else if ( v214 )
        {
          v215 = *(_QWORD *)(v214 + 32);
          if ( v215 )
          {
            ++*(_DWORD *)(v203 + 16);
            v216 = *(_QWORD *)(v215 + 1320);
            v217 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v216);
            do
              v218 = __ldxr(v217);
            while ( __stxr(v218 + 1, v217) );
            v219 = *(_QWORD *)(v203 + 16) - 1LL;
            *(_DWORD *)(v203 + 16) = v219;
            if ( !v219 || !*(_QWORD *)(v203 + 16) )
              preempt_schedule_notrace(v204);
          }
          _X8 = (unsigned int *)(v214 + 52600);
          __asm { PRFM            #0x11, [X8] }
          do
            v231 = __ldxr(_X8);
          while ( __stxr(v231 + 1, _X8) );
          v192 = v193;
          v193 = v213;
        }
        else
        {
          v192 = v193;
          v193 = 0;
        }
        goto LABEL_179;
      }
    }
    v192 = 0;
LABEL_179:
    v229 = a1[5];
    if ( (v229 & 1) != 0 )
    {
      a1[5] = v229 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      if ( !v192 )
        goto LABEL_208;
    }
    else
    {
      raw_spin_unlock(a1 + 4);
      if ( !v192 )
        goto LABEL_208;
    }
  }
  if ( !v193 )
  {
    v345 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      goto LABEL_209;
    goto LABEL_211;
  }
  hdd_adapter_dev_put_debug(v193, 0x13u, v195, v196, v197, v198, v199, v200, v201, v202);
  v345 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    goto LABEL_211;
LABEL_209:
  v249 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v249 + 16) & 0xF0000) != 0 || (*(_DWORD *)(v249 + 16) & 0xFF00) != 0 )
  {
LABEL_211:
    raw_spin_lock(a1 + 4);
  }
  else
  {
    raw_spin_lock_bh(a1 + 4);
    a1[5] |= 1uLL;
  }
  v347[0] = 0;
  v250 = qdf_list_peek_front(a1 + 6, v347);
  if ( (_DWORD)v250 || (v291 = (_QWORD *)v347[0], v251 = v347[0] - 8LL, v347[0] == 8) )
  {
    v251 = 0;
LABEL_214:
    v252 = 0;
    goto LABEL_215;
  }
  v292 = *(__int64 *)((char *)&off_18 + v347[0]);
  if ( v292 )
  {
    v293 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v293 + 16);
    v294 = *(_QWORD *)(v292 + 1320);
    v295 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v294);
    do
      v296 = __ldxr(v295);
    while ( __stxr(v296 + 1, v295) );
    v297 = *(_QWORD *)(v293 + 16) - 1LL;
    *(_DWORD *)(v293 + 16) = v297;
    if ( !v297 || !*(_QWORD *)(v293 + 16) )
    {
      v328 = v291;
      preempt_schedule_notrace(v250);
      v291 = v328;
    }
  }
  _X8 = (unsigned int *)(v291 + 6574);
  __asm { PRFM            #0x11, [X8] }
  do
    v338 = __ldxr(_X8);
  while ( __stxr(v338 + 1, _X8) );
  v347[0] = 0;
  v299 = qdf_list_peek_next(a1 + 6, v291, v347);
  if ( (_DWORD)v299 )
    goto LABEL_214;
  v300 = v347[0];
  v252 = v347[0] - 8LL;
  if ( v347[0] != 8 )
  {
    v301 = *(__int64 *)((char *)&off_18 + v347[0]);
    if ( v301 )
    {
      v302 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v302 + 16);
      v303 = *(_QWORD *)(v301 + 1320);
      v304 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v303);
      do
        v305 = __ldxr(v304);
      while ( __stxr(v305 + 1, v304) );
      v306 = *(_QWORD *)(v302 + 16) - 1LL;
      *(_DWORD *)(v302 + 16) = v306;
      if ( !v306 || !*(_QWORD *)(v302 + 16) )
        preempt_schedule_notrace(v299);
    }
    _X8 = (unsigned int *)(v300 + 52592);
    __asm { PRFM            #0x11, [X8] }
    do
      v344 = __ldxr(_X8);
    while ( __stxr(v344 + 1, _X8) );
  }
LABEL_215:
  v253 = a1[5];
  if ( (v253 & 1) != 0 )
  {
    a1[5] = v253 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    if ( !v251 )
      goto LABEL_267;
  }
  else
  {
    raw_spin_unlock(a1 + 4);
    if ( !v251 )
      goto LABEL_267;
  }
  v262 = _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    if ( (*(_QWORD *)(v251 + 1624) & 4) == 0
      || *(_DWORD *)(v251 + 40) != 7
      || (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*a1) & 1) == 0 )
    {
      hdd_adapter_dev_put_debug(v251, 0x13u, v254, v255, v256, v257, v258, v259, v260, v261);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v262 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v262 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 4);
        if ( v252 )
          goto LABEL_228;
LABEL_219:
        v271 = 0;
        v251 = 0;
        v272 = a1[5];
        if ( (v272 & 1) == 0 )
          goto LABEL_220;
      }
      else
      {
        raw_spin_lock_bh(a1 + 4);
        a1[5] |= 1uLL;
        if ( !v252 )
          goto LABEL_219;
LABEL_228:
        v347[0] = 0;
        v273 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v252 + 8), v347);
        v271 = v347[0] - 8LL;
        if ( (_DWORD)v273 )
          v282 = 0;
        else
          v282 = v347[0] - 8LL;
        if ( v252 == v282 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v274,
            v275,
            v276,
            v277,
            v278,
            v279,
            v280,
            v281,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v252, 0x13u, v263, v264, v265, v266, v267, v268, v269, v270);
          goto LABEL_219;
        }
        if ( v282 )
        {
          v283 = *(_QWORD *)(v282 + 32);
          if ( v283 )
          {
            ++*(_DWORD *)(v262 + 16);
            v284 = *(_QWORD *)(v283 + 1320);
            v285 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v284);
            do
              v286 = __ldxr(v285);
            while ( __stxr(v286 + 1, v285) );
            v287 = *(_QWORD *)(v262 + 16) - 1LL;
            *(_DWORD *)(v262 + 16) = v287;
            if ( !v287 || !*(_QWORD *)(v262 + 16) )
              preempt_schedule_notrace(v273);
          }
          _X8 = (unsigned int *)(v282 + 52600);
          __asm { PRFM            #0x11, [X8] }
          do
            v290 = __ldxr(_X8);
          while ( __stxr(v290 + 1, _X8) );
        }
        else
        {
          v271 = 0;
        }
        v251 = v252;
        v272 = a1[5];
        if ( (v272 & 1) == 0 )
        {
LABEL_220:
          raw_spin_unlock(a1 + 4);
          v252 = v271;
          if ( !v251 )
            goto LABEL_267;
          continue;
        }
      }
      a1[5] = v272 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      v252 = v271;
      if ( !v251 )
        goto LABEL_267;
      continue;
    }
    break;
  }
  ucfg_p2p_psoc_priv_set_sta_vdev_id(*a1, *(_BYTE *)(*(_QWORD *)(v192 + 52832) + 8LL));
  if ( (unsigned int)wlan_mlme_set_p2p_device_mac_addr(
                       *(_QWORD *)(*(_QWORD *)(v192 + 52832) + 32LL),
                       (int *)(v251 + 1617),
                       v308,
                       v309,
                       v310,
                       v311,
                       v312,
                       v313,
                       v314,
                       v315) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set p2p mac addr",
      v316,
      v317,
      v318,
      v319,
      v320,
      v321,
      v322,
      v323,
      "hdd_cache_p2p_macaddr_in_vdev");
  *(_BYTE *)(*(_QWORD *)(v251 + 52832) + 8LL) = *(_BYTE *)(*(_QWORD *)(v192 + 52832) + 8LL);
  hdd_adapter_dev_put_debug(v251, 0x13u, v316, v317, v318, v319, v320, v321, v322, v323);
  if ( v252 )
    hdd_adapter_dev_put_debug(v252, 0x13u, v254, v255, v256, v257, v258, v259, v260, v261);
LABEL_267:
  if ( (v345 & 1) == 0 )
    hdd_adapter_dev_put_debug(v192, 0x13u, v254, v255, v256, v257, v258, v259, v260, v261);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v254, v255, v256, v257, v258, v259, v260, v261, "hdd_start_all_adapters");
  _ReadStatusReg(SP_EL0);
  return 0;
}
