__int64 __fastcall wlan_hdd_state_ctrl_param_write(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        signed __int64 a10,
        __int64 a11)
{
  unsigned __int64 StatusReg; // x23
  char v14; // w8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v21; // x9
  size_t v22; // x2
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int64 v31; // x8
  unsigned __int64 v33; // x9
  int v39; // w21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x1
  __int64 v49; // x2
  __int64 v50; // x3
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x21
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 *context; // x0
  __int64 v86; // x8
  _QWORD *v87; // x20
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  const char *v99; // x1
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  __int64 v108; // x1
  __int64 v109; // x2
  __int64 v110; // x3
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  char v119; // w22
  char driver_state; // w20
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  unsigned int v129; // w0
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
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  _QWORD *v162; // x20
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  int v171; // w0
  __int64 v172; // x1
  __int64 v173; // x2
  __int64 v174; // x3
  __int64 v175; // x20
  __int64 v176; // x0
  _QWORD *v177; // x20
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  __int64 v194; // x8
  __int64 v195; // x21
  __int64 v196; // x21
  __int64 v197; // x21
  __int64 v198; // x0
  __int64 v199; // x22
  __int64 v200; // x21
  __int64 v201; // x8
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  __int64 v210; // x28
  __int64 v211; // x8
  int cfg_wlm_level; // w0
  __int16 v213; // w8
  double v214; // d0
  double v215; // d1
  double v216; // d2
  double v217; // d3
  double v218; // d4
  double v219; // d5
  double v220; // d6
  double v221; // d7
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  __int64 v238; // x0
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  __int64 v247; // x22
  __int64 v248; // x8
  __int64 v249; // x8
  unsigned int *v250; // x8
  unsigned int v251; // w10
  __int64 v252; // x8
  unsigned int v255; // w9
  __int64 v257; // x22
  _QWORD *v258; // x1
  __int64 v259; // x8
  __int64 v260; // x8
  unsigned int *v261; // x8
  unsigned int v262; // w11
  __int64 v263; // x8
  __int64 v265; // x0
  __int64 v266; // x24
  __int64 v267; // x8
  __int64 v268; // x8
  unsigned int *v269; // x8
  unsigned int v270; // w11
  __int64 v271; // x8
  _QWORD *v273; // x21
  unsigned int v275; // w9
  unsigned int v277; // w9
  __int64 v278; // [xsp+8h] [xbp-28h] BYREF
  char v279[4]; // [xsp+10h] [xbp-20h] BYREF
  char v280[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _QWORD v281[3]; // [xsp+18h] [xbp-18h] BYREF

  v281[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "wlan_hdd_state_ctrl_param_write");
  StatusReg = _ReadStatusReg(SP_EL0);
  v14 = *(_BYTE *)(StatusReg + 70);
  memset(v281, 0, 15);
  if ( (v14 & 0x20) != 0 || (v15 = a10, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v15 = a10 & (a10 << 8 >> 8);
  if ( v15 > 0x7FFFFFFFF1LL )
  {
    v22 = 15;
    goto LABEL_74;
  }
  v16 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v21 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v21);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v16);
  v22 = _arch_copy_from_user(v281, a10 & 0xFF7FFFFFFFFFFFFFLL, 15);
  v31 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v33 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v33 - 4096);
  _WriteStatusReg(TTBR1_EL1, v33);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v31);
  if ( v22 )
  {
LABEL_74:
    if ( v22 < 0x10 )
    {
      memset((char *)&v281[1] - v22 + 7, 0, v22);
      printk(&unk_938956, v172, v173, v174);
      goto LABEL_76;
    }
    _fortify_panic(15, 0, v22);
    goto LABEL_174;
  }
  if ( LOWORD(v281[0]) == 17999 && BYTE2(v281[0]) == 70 )
  {
    v39 = 0;
    goto LABEL_30;
  }
  if ( LOWORD(v281[0]) == 20047 )
  {
    v39 = 1;
    goto LABEL_30;
  }
  if ( LODWORD(v281[0]) == 1111576133 && WORD2(v281[0]) == 17740 )
  {
    v39 = 2;
LABEL_30:
    if ( v39 )
    {
      if ( v39 == 1 )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: Wifi Turning On from UI\n",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wlan_hdd_state_ctrl_param_write");
      }
      else
      {
        qdf_trace_msg(0x33u, 8u, "Received WiFi enable from framework\n", v23, v24, v25, v26, v27, v28, v29, v30);
        if ( (cds_get_driver_state(v40, v41, v42, v43, v44, v45, v46, v47) & 1) == 0 )
        {
          v59 = qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: \nEnabling CNSS WLAN HW",
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  "hdd_wlan_soft_driver_load");
          pld_wlan_hw_enable(v59);
          goto LABEL_151;
        }
        if ( (g_soft_unload & 1) != 0 )
        {
          hdd_driver_load();
          g_soft_unload = 0;
          goto LABEL_151;
        }
        v257 = jiffies;
        if ( hdd_wlan_soft_driver_load___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Enabling WiFi\n",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "hdd_wlan_soft_driver_load");
          hdd_wlan_soft_driver_load___last_ticks = v257;
        }
        printk(&unk_9E7054, v48, v49, v50);
      }
      goto LABEL_55;
    }
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Wifi turning off from UI\n",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_hdd_state_ctrl_param_write");
    context = _cds_get_context(51, (__int64)"hdd_inform_wifi_off", v77, v78, v79, v80, v81, v82, v83, v84);
    if ( !context )
      goto LABEL_151;
    v86 = context[3];
    a10 = (signed __int64)context;
    v278 = 0;
    if ( (unsigned int)_osif_psoc_sync_op_start(*(_QWORD *)(v86 + 488), &v278, "hdd_inform_wifi_off") )
      goto LABEL_151;
    if ( curr_con_mode == 5 )
      goto LABEL_46;
    v280[0] = 0;
    v279[0] = 0;
    if ( (unsigned int)_wlan_hdd_validate_context(
                         a10,
                         (__int64)"hdd_set_adapter_wlm_def_level",
                         v60,
                         v61,
                         v62,
                         v63,
                         v64,
                         v65,
                         v66,
                         v67) )
      goto LABEL_46;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a10 + 32);
LABEL_101:
      v281[0] = 0;
      v198 = qdf_list_peek_front((_QWORD *)(a10 + 48), v281);
      if ( (_DWORD)v198 || (v258 = (_QWORD *)v281[0], v199 = v281[0] - 8LL, v281[0] == 8) )
      {
        v199 = 0;
      }
      else
      {
        v259 = *(__int64 *)((char *)&off_18 + v281[0]);
        if ( v259 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          v260 = *(_QWORD *)(v259 + 1320);
          v261 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v260);
          do
            v262 = __ldxr(v261);
          while ( __stxr(v262 + 1, v261) );
          v263 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v263;
          if ( !v263 || !*(_QWORD *)(StatusReg + 16) )
          {
            v273 = v258;
            preempt_schedule_notrace(v198);
            v258 = v273;
          }
        }
        _X8 = (unsigned int *)(v258 + 6577);
        __asm { PRFM            #0x11, [X8] }
        do
          v275 = __ldxr(_X8);
        while ( __stxr(v275 + 1, _X8) );
        v281[0] = 0;
        v265 = qdf_list_peek_next((_QWORD *)(a10 + 48), v258, v281);
        if ( !(_DWORD)v265 )
        {
          v266 = v281[0];
          v200 = v281[0] - 8LL;
          if ( v281[0] != 8 )
          {
            v267 = *(__int64 *)((char *)&off_18 + v281[0]);
            if ( v267 )
            {
              ++*(_DWORD *)(StatusReg + 16);
              v268 = *(_QWORD *)(v267 + 1320);
              v269 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v268);
              do
                v270 = __ldxr(v269);
              while ( __stxr(v270 + 1, v269) );
              v271 = *(_QWORD *)(StatusReg + 16) - 1LL;
              *(_DWORD *)(StatusReg + 16) = v271;
              if ( !v271 || !*(_QWORD *)(StatusReg + 16) )
                preempt_schedule_notrace(v265);
            }
            _X8 = (unsigned int *)(v266 + 52616);
            __asm { PRFM            #0x11, [X8] }
            do
              v277 = __ldxr(_X8);
            while ( __stxr(v277 + 1, _X8) );
          }
LABEL_104:
          v201 = *(_QWORD *)(a10 + 40);
          if ( (v201 & 1) == 0 )
          {
            raw_spin_unlock(a10 + 32);
            if ( v199 )
              goto LABEL_110;
            goto LABEL_46;
          }
          *(_QWORD *)(a10 + 40) = v201 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a10 + 32);
          if ( !v199 )
          {
LABEL_46:
            v87 = _cds_get_context(51, (__int64)"__hdd_inform_wifi_off", v60, v61, v62, v63, v64, v65, v66, v67);
            if ( !(unsigned int)_wlan_hdd_validate_context(
                                  (__int64)v87,
                                  (__int64)"__hdd_inform_wifi_off",
                                  v88,
                                  v89,
                                  v90,
                                  v91,
                                  v92,
                                  v93,
                                  v94,
                                  v95) )
            {
              ucfg_dlm_wifi_off(v87[1]);
              v96 = hdd_txpb_wifi_off_app_stop(v87);
              if ( (unsigned int)rtnl_trylock(v96) )
              {
                v97 = wlan_hdd_lpc_del_monitor_interface((__int64)v87, 0);
                rtnl_unlock(v97);
              }
            }
            v98 = v278;
            v99 = "hdd_inform_wifi_off";
            goto LABEL_50;
          }
          while ( 1 )
          {
LABEL_110:
            cfg_wlm_level = mlme_get_cfg_wlm_level(*(_QWORD *)a10, v280);
            v213 = (unsigned __int8)v280[0];
            *(_WORD *)(v199 + 52100) = 0;
            if ( cfg_wlm_level )
              v213 = 1;
            *(_WORD *)(v199 + 52098) = v213;
            if ( (unsigned int)mlme_get_cfg_wlm_reset(*(_QWORD *)a10, v279) )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: could not get the wlm reset flag",
                v214,
                v215,
                v216,
                v217,
                v218,
                v219,
                v220,
                v221,
                "hdd_set_adapter_wlm_def_level");
              v279[0] = 0;
            }
            if ( (hdd_get_multi_client_ll_support(v199) & 1) != 0 && (v279[0] & 1) == 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: deinitializing the client info table",
                v222,
                v223,
                v224,
                v225,
                v226,
                v227,
                v228,
                v229,
                "wlan_hdd_deinit_multi_client_info_table");
              if ( *(_BYTE *)(v199 + 52112) == 1 )
              {
                *(_WORD *)(v199 + 52114) = 0;
                *(_BYTE *)(v199 + 52116) = 0;
                *(_QWORD *)(v199 + 52104) = 0;
                *(_BYTE *)(v199 + 52112) = 0;
              }
              if ( *(_BYTE *)(v199 + 52128) == 1 )
              {
                *(_QWORD *)(v199 + 52120) = 1;
                *(_BYTE *)(v199 + 52128) = 0;
                *(_WORD *)(v199 + 52130) = 0;
                *(_BYTE *)(v199 + 52132) = 0;
              }
              if ( *(_BYTE *)(v199 + 52144) == 1 )
              {
                *(_BYTE *)(v199 + 52144) = 0;
                *(_QWORD *)(v199 + 52136) = 2;
                *(_WORD *)(v199 + 52146) = 0;
                *(_BYTE *)(v199 + 52148) = 0;
              }
              if ( *(_BYTE *)(v199 + 52160) == 1 )
              {
                *(_BYTE *)(v199 + 52160) = 0;
                *(_QWORD *)(v199 + 52152) = 3;
                *(_WORD *)(v199 + 52162) = 0;
                *(_BYTE *)(v199 + 52164) = 0;
              }
              if ( *(_BYTE *)(v199 + 52176) == 1 )
              {
                *(_BYTE *)(v199 + 52176) = 0;
                *(_QWORD *)(v199 + 52168) = 4;
                *(_WORD *)(v199 + 52178) = 0;
                *(_BYTE *)(v199 + 52180) = 0;
              }
            }
            *(_BYTE *)(v199 + 42083) = 1;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: UDP packets qos reset to: %d",
              v222,
              v223,
              v224,
              v225,
              v226,
              v227,
              v228,
              v229,
              "hdd_set_adapter_wlm_def_level",
              1);
            hdd_adapter_dev_put_debug(v199, 0x19u, v230, v231, v232, v233, v234, v235, v236, v237);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(a10 + 32);
              if ( v200 )
                goto LABEL_130;
LABEL_108:
              v210 = 0;
              v199 = 0;
              v211 = *(_QWORD *)(a10 + 40);
              if ( (v211 & 1) == 0 )
                goto LABEL_109;
LABEL_143:
              *(_QWORD *)(a10 + 40) = v211 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a10 + 32);
              v200 = v210;
              if ( !v199 )
                goto LABEL_46;
            }
            else
            {
              raw_spin_lock_bh(a10 + 32);
              *(_QWORD *)(a10 + 40) |= 1uLL;
              if ( !v200 )
                goto LABEL_108;
LABEL_130:
              v281[0] = 0;
              v238 = qdf_list_peek_next((_QWORD *)(a10 + 48), (_QWORD *)(v200 + 8), v281);
              v210 = v281[0] - 8LL;
              if ( (_DWORD)v238 )
                v247 = 0;
              else
                v247 = v281[0] - 8LL;
              if ( v200 == v247 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Validation failed",
                  v239,
                  v240,
                  v241,
                  v242,
                  v243,
                  v244,
                  v245,
                  v246,
                  "hdd_validate_next_adapter");
                hdd_adapter_dev_put_debug(v200, 0x19u, v202, v203, v204, v205, v206, v207, v208, v209);
                goto LABEL_108;
              }
              if ( v247 )
              {
                v248 = *(_QWORD *)(v247 + 32);
                if ( v248 )
                {
                  ++*(_DWORD *)(StatusReg + 16);
                  v249 = *(_QWORD *)(v248 + 1320);
                  v250 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v249);
                  do
                    v251 = __ldxr(v250);
                  while ( __stxr(v251 + 1, v250) );
                  v252 = *(_QWORD *)(StatusReg + 16) - 1LL;
                  *(_DWORD *)(StatusReg + 16) = v252;
                  if ( !v252 || !*(_QWORD *)(StatusReg + 16) )
                    preempt_schedule_notrace(v238);
                }
                _X8 = (unsigned int *)(v247 + 52624);
                __asm { PRFM            #0x11, [X8] }
                do
                  v255 = __ldxr(_X8);
                while ( __stxr(v255 + 1, _X8) );
              }
              else
              {
                v210 = 0;
              }
              v199 = v200;
              v211 = *(_QWORD *)(a10 + 40);
              if ( (v211 & 1) != 0 )
                goto LABEL_143;
LABEL_109:
              raw_spin_unlock(a10 + 32);
              v200 = v210;
              if ( !v199 )
                goto LABEL_46;
            }
          }
        }
      }
      v200 = 0;
      goto LABEL_104;
    }
LABEL_174:
    raw_spin_lock_bh(a10 + 32);
    *(_QWORD *)(a10 + 40) |= 1uLL;
    goto LABEL_101;
  }
  if ( LODWORD(v281[0]) == 1095977284 && *(_DWORD *)((char *)v281 + 3) == 1162625601 )
  {
    v39 = 3;
  }
  else if ( v281[0] == 0x524F465F54494157LL && *(_QWORD *)((char *)v281 + 6) == 0x59444145525F524FLL )
  {
    v39 = 4;
  }
  else
  {
    if ( v281[0] != 0x49445F4543524F46LL || *(_QWORD *)((char *)v281 + 5) != 0x454C42415349445FLL )
    {
LABEL_76:
      v175 = jiffies;
      if ( wlan_hdd_state_ctrl_param_write___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid value received from framework",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wlan_hdd_state_ctrl_param_write");
        wlan_hdd_state_ctrl_param_write___last_ticks = v175;
      }
      a11 = -22;
      goto LABEL_152;
    }
    v39 = 5;
  }
  if ( v39 == 3 )
  {
    qdf_trace_msg(0x33u, 8u, "Received WiFi disable from framework\n", v23, v24, v25, v26, v27, v28, v29, v30);
    if ( (cds_get_driver_state(v100, v101, v102, v103, v104, v105, v106, v107) & 1) == 0 || (g_soft_unload & 1) != 0 )
      goto LABEL_151;
    printk(&unk_A24F24, v108, v109, v110);
LABEL_55:
    v119 = 0;
    goto LABEL_57;
  }
  if ( v39 != 4 )
  {
    qdf_trace_msg(0x33u, 8u, "Received Force WiFi disable from framework\n", v23, v24, v25, v26, v27, v28, v29, v30);
    if ( (cds_get_driver_state(v68, v69, v70, v71, v72, v73, v74, v75) & 1) != 0 )
    {
      if ( g_soft_unload == 1 )
      {
        v76 = jiffies;
        if ( hdd_wlan_soft_driver_unload___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: WiFi is already disabled",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "hdd_wlan_soft_driver_unload");
          hdd_wlan_soft_driver_unload___last_ticks = v76;
        }
      }
      else
      {
        v176 = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: Initiating soft driver unload\n",
                 v60,
                 v61,
                 v62,
                 v63,
                 v64,
                 v65,
                 v66,
                 v67,
                 "hdd_wlan_soft_driver_unload");
        g_soft_unload = 1;
        hdd_driver_unload(v176);
      }
    }
    goto LABEL_151;
  }
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: Wifi wait for ready from UI\n",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wlan_hdd_state_ctrl_param_write");
  v119 = 1;
LABEL_57:
  driver_state = cds_get_driver_state(v111, v112, v113, v114, v115, v116, v117, v118);
  v129 = cds_get_driver_state(v121, v122, v123, v124, v125, v126, v127, v128);
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: is_driver_loaded %d is_driver_recovering %d",
    v130,
    v131,
    v132,
    v133,
    v134,
    v135,
    v136,
    v137,
    "wlan_hdd_state_ctrl_param_write",
    driver_state & 1,
    (v129 >> 3) & 1);
  if ( ((cds_get_driver_state(v138, v139, v140, v141, v142, v143, v144, v145) & 1) == 0
     || (cds_get_driver_state(v146, v147, v148, v149, v150, v151, v152, v153) & 8) != 0)
    && !wait_for_completion_timeout(&wlan_start_comp, 5000) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Driver Loading Timed-out!!",
      v154,
      v155,
      v156,
      v157,
      v158,
      v159,
      v160,
      v161,
      "wlan_hdd_state_ctrl_param_write");
    a11 = -22;
    goto LABEL_152;
  }
  if ( (v119 & 1) == 0 )
  {
    v162 = _cds_get_context(
             51,
             (__int64)"wlan_hdd_state_ctrl_param_write",
             v154,
             v155,
             v156,
             v157,
             v158,
             v159,
             v160,
             v161);
    if ( v162 )
    {
      _qdf_delayed_work_stop_sync();
      qdf_wake_lock_release((__int64)&wlan_wake_lock, 0x15u);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Stopped psoc idle timer",
        v163,
        v164,
        v165,
        v166,
        v167,
        v168,
        v169,
        v170,
        "hdd_psoc_idle_timer_stop");
    }
    if ( v39 != 1 )
    {
      if ( v39 == 2 )
      {
        if ( v162 )
        {
          if ( (*((_BYTE *)v162 + 7123) & 1) != 0 )
          {
            *((_BYTE *)v162 + 7123) = 0;
          }
          else
          {
            v197 = jiffies;
            if ( wlan_hdd_state_ctrl_param_write___last_ticks_879 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: WiFi is already enabled",
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                "wlan_hdd_state_ctrl_param_write");
              wlan_hdd_state_ctrl_param_write___last_ticks_879 = v197;
            }
          }
        }
        else
        {
          v195 = jiffies;
          if ( wlan_hdd_state_ctrl_param_write___last_ticks_878 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: hdd_ctx is Null",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "wlan_hdd_state_ctrl_param_write");
            wlan_hdd_state_ctrl_param_write___last_ticks_878 = v195;
          }
        }
      }
      else if ( v39 == 3 )
      {
        if ( v162 )
        {
          v171 = hdd_disable_wifi(v162);
          if ( v171 )
          {
            a11 = v171;
            goto LABEL_152;
          }
        }
        else
        {
          v196 = jiffies;
          if ( wlan_hdd_state_ctrl_param_write___last_ticks_876 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: hdd_ctx is Null",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "wlan_hdd_state_ctrl_param_write");
            wlan_hdd_state_ctrl_param_write___last_ticks_876 = v196;
          }
        }
      }
LABEL_151:
      qdf_trace_msg(0x33u, 8u, "%s: exit", v60, v61, v62, v63, v64, v65, v66, v67, "wlan_hdd_state_ctrl_param_write");
      goto LABEL_152;
    }
    v177 = _cds_get_context(51, (__int64)"hdd_inform_wifi_on", v60, v61, v62, v63, v64, v65, v66, v67);
    v281[0] = 0;
    qdf_trace_msg(0x33u, 8u, "inform regdomain for wifi on", v178, v179, v180, v181, v182, v183, v184, v185);
    if ( (unsigned int)_wlan_hdd_validate_context(
                         (__int64)v177,
                         (__int64)"hdd_inform_wifi_on",
                         v186,
                         v187,
                         v188,
                         v189,
                         v190,
                         v191,
                         v192,
                         v193) )
      goto LABEL_151;
    if ( *((_DWORD *)v177 + 366) != 1 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Modules not enabled, Present status: %d",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "wlan_hdd_validate_modules_state");
      goto LABEL_151;
    }
    v194 = v177[3];
    if ( !v194 || (unsigned int)_osif_psoc_sync_op_start(*(_QWORD *)(v194 + 488), v281, "hdd_inform_wifi_on") )
      goto LABEL_151;
    if ( *(_BYTE *)(v177[3] + 1304LL) == 1 )
      hdd_send_wiphy_regd_sync_event(v177, 0);
    v98 = v281[0];
    v99 = "hdd_inform_wifi_on";
LABEL_50:
    _osif_psoc_sync_op_stop(v98, v99);
    goto LABEL_151;
  }
LABEL_152:
  _ReadStatusReg(SP_EL0);
  return a11;
}
