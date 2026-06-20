__int64 __fastcall cnss_driver_event_work(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char **v8; // x19
  unsigned __int64 v9; // x23
  __int64 v10; // x24
  unsigned __int64 v11; // x8
  const char *v12; // x1
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  __int64 result; // x0
  __int16 v18; // w9
  const char *v19; // x8
  __int64 v20; // x21
  __int64 v21; // x26
  unsigned __int64 v22; // x28
  _QWORD *v23; // x20
  _QWORD *v24; // x22
  _QWORD *v26; // x8
  __int64 v27; // x9
  const char *v28; // x1
  __int64 v29; // x8
  const char *v30; // x6
  const char *v31; // x7
  __int64 v32; // x7
  __int64 v33; // x6
  unsigned int v34; // w0
  unsigned int m3; // w27
  __int64 v36; // x0
  int v37; // w8
  const char *v38; // x1
  int *v39; // x26
  const char *v40; // x1
  const char *v41; // x1
  __int64 v42; // x1
  int v43; // w19
  __int64 v44; // x6
  const char *v45; // x1
  _DWORD *v46; // x26
  __int64 v47; // x6
  __int64 v48; // x0
  const char *v49; // x1
  __int64 v50; // x26
  __int64 v51; // x6
  __int64 v52; // x8
  __int64 v53; // x15
  __int64 v54; // x6
  int v55; // w8
  char *v56; // x9
  __int64 v57; // x3
  char **v58; // x11
  char *v59; // x13
  __int64 v61; // x12
  char *v62; // x13
  __int64 v63; // x0
  __int64 v64; // x25
  __int64 v65; // x7
  _BYTE *v66; // x0
  __int64 v67; // x6
  __int64 v68; // x7
  unsigned __int64 v69; // x0
  unsigned __int64 v70; // x8
  unsigned int v71; // w0
  __int64 v72; // x7
  unsigned int v73; // w0
  unsigned int v74; // w26
  __int64 v75; // x0
  const char *v76; // x1
  char *v77; // x0
  char v78; // w19
  char v79; // w9
  const char *v80; // x1
  __int64 v81; // x0
  const char *v82; // x1
  const char *v83; // x1
  __int64 v84; // x7
  const char *v85; // x6
  __int64 v86; // x7
  __int64 v87; // x6
  __int64 v88; // x8
  __int64 v89; // x0
  const char *v90; // x1
  const char *v91; // x1
  const char *v92; // x1
  const char *v93; // x1
  const char *v94; // x1
  __int64 v95; // x0
  __int64 v96; // x6
  __int64 v97; // x7
  int v98; // w19
  __int64 v99; // x6
  __int64 v100; // x7
  const char *v101; // x1
  const char *v102; // x2
  const char *v103; // x5
  const char *v104; // x5
  const char *v105; // x1
  const char *v106; // x5
  const char *v107; // x1
  const char *v108; // x1
  const char *v109; // x1
  __int64 v110; // x7
  const char *v111; // x1
  unsigned __int64 v112; // x0
  __int64 v113; // x1
  const char *v114; // x5
  unsigned int v115; // w3
  unsigned int v116; // w4
  unsigned int v117; // w0
  const char *v118; // x1
  __int64 v119; // x7
  const char *v120; // x1
  __int64 v121; // x6
  __int64 v122; // x7
  char *v123; // x1
  __int64 v124; // x6
  __int64 v125; // x7
  const char *v126; // x5
  __int64 v127; // x9
  int v128; // w10
  const char *v129; // x1
  char *v130; // x1
  const char *v131; // x1
  __int64 v132; // x1
  __int64 v133; // x2
  __int64 v134; // x3
  __int64 v135; // x4
  __int64 v136; // x5
  __int64 v137; // x6
  __int64 v138; // x7
  const char *v139; // x1
  __int64 v140; // x6
  int qmi_timeout; // w0
  __int64 v143; // x7
  char *v144; // x1
  __int64 v145; // x0
  const char *v146; // x1
  const char *v147; // x1
  __int64 v148; // x7
  const char *v149; // x1
  __int64 v150; // x7
  __int64 v151; // x6
  const char *v152; // x1
  __int64 v153; // x7
  const char *v154; // x1
  __int64 v155; // x7
  const char *v156; // x1
  __int64 v157; // x6
  __int64 v158; // x7
  const char *v159; // x1
  const char *v160; // x5
  unsigned int v161; // w26
  __int64 v162; // x0
  __int64 v163; // x6
  __int64 v164; // x7
  __int64 v165; // x8
  char *v166; // x1
  int v167; // w0
  const char *v168; // x1
  const char *v169; // x1
  const char *v170; // x8
  unsigned __int64 v172; // x9
  unsigned __int64 v174; // x8
  unsigned __int64 v176; // x8
  unsigned __int64 v178; // x8
  unsigned __int64 v180; // x8
  unsigned __int64 v182; // x9
  unsigned __int64 v184; // x9
  unsigned __int64 v186; // x9
  unsigned __int64 v188; // x9
  unsigned __int64 v190; // x8
  unsigned __int64 v195; // x9
  unsigned __int64 v197; // x9
  unsigned __int64 v199; // x9
  unsigned __int64 v201; // x8
  unsigned __int64 v203; // x9
  unsigned __int64 v205; // x8
  unsigned __int64 v207; // x8
  unsigned __int64 v209; // x8
  unsigned __int64 v211; // x9
  unsigned __int64 v214; // x10
  unsigned __int64 v216; // x9
  unsigned __int64 v218; // x9
  unsigned __int64 v220; // x9
  const char *v221; // x1
  unsigned int v224; // w8
  unsigned int v225; // w8
  unsigned int v228; // w8
  unsigned int v229; // w8
  char v230; // [xsp+0h] [xbp-60h]
  char v231; // [xsp+0h] [xbp-60h]
  char v232; // [xsp+0h] [xbp-60h]
  char v233; // [xsp+0h] [xbp-60h]
  char v234; // [xsp+0h] [xbp-60h]
  __int64 v235; // [xsp+20h] [xbp-40h]
  unsigned __int64 *v236; // [xsp+28h] [xbp-38h]
  int v237; // [xsp+28h] [xbp-38h]
  unsigned __int64 v238; // [xsp+30h] [xbp-30h]
  __int64 v239; // [xsp+38h] [xbp-28h]
  _BYTE *v240; // [xsp+40h] [xbp-20h]
  unsigned int v241; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v242; // [xsp+58h] [xbp-8h]

  v8 = &off_5B000;
  v9 = a1 - 648;
  v242 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 648 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(StatusReg + 16);
      v16 = (const char *)(StatusReg + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v16;
    }
    result = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v14,
               "cnss_driver_event_work",
               3u,
               3u,
               "plat_priv is NULL!\n",
               a7,
               a8,
               v230);
  }
  else
  {
    v10 = a1;
    while ( 1 )
    {
      _X9 = (unsigned int *)(v10 + 5616);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v224 = __ldxr(_X9);
        v225 = v224 + 1;
      }
      while ( __stlxr(v225, _X9) );
      __dmb(0xBu);
      if ( v225 == 1 )
      {
        v11 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
        {
          v12 = "irq";
        }
        else
        {
          v18 = *(_DWORD *)(v11 + 16);
          v19 = (const char *)(v11 + 2320);
          if ( (v18 & 0xFF00) != 0 )
            v12 = "soft_irq";
          else
            v12 = v19;
        }
        cnss_debug_ipc_log_print(
          (__int64)v8[490],
          v12,
          "cnss_pm_stay_awake",
          7u,
          7u,
          "PM stay awake, state: 0x%lx, count: %d\n",
          *(_QWORD *)(v10 - 96),
          *(unsigned int *)(v10 + 5616),
          v230);
        pm_stay_awake(*(_QWORD *)v9 + 16LL);
      }
      v20 = v10 - 8;
      v21 = raw_spin_lock_irqsave(v10 - 8);
      v22 = _ReadStatusReg(SP_EL0);
      v23 = (_QWORD *)(v10 - 88);
      v24 = *(_QWORD **)(v10 - 88);
      *(_QWORD *)(v10 + 7216) = v22;
      if ( v24 == (_QWORD *)(v10 - 88) )
        break;
      _X25 = (unsigned __int64 *)(v10 - 96);
      v240 = (_BYTE *)(v10 + 4096);
      v238 = v9;
      v239 = v10;
      while ( 2 )
      {
        v26 = (_QWORD *)v24[1];
        if ( (_QWORD *)*v26 == v24 && (v27 = *v24, *(_QWORD **)(*v24 + 8LL) == v24) )
        {
          *(_QWORD *)(v27 + 8) = v26;
          *v26 = v27;
        }
        else
        {
          _list_del_entry_valid_or_report(v24);
        }
        *v24 = 0xDEAD000000000100LL;
        v24[1] = 0xDEAD000000000122LL;
        raw_spin_unlock_irqrestore(v20, v21);
        v28 = "irq";
        if ( (*(_DWORD *)(v22 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
            v28 = "soft_irq";
          else
            v28 = (const char *)(v22 + 2320);
        }
        v29 = *((unsigned int *)v24 + 4);
        v30 = "UNKNOWN";
        if ( (unsigned int)v29 <= 0x19 )
          v30 = off_5ADF0[v29];
        if ( *((_BYTE *)v24 + 20) )
          v31 = "-sync";
        else
          v31 = (const char *)&unk_4DEF5;
        cnss_debug_ipc_log_print(
          (__int64)v8[490],
          v28,
          "cnss_driver_event_work",
          7u,
          7u,
          "Processing driver event: %s%s(%d), state: 0x%lx\n",
          (__int64)v30,
          (__int64)v31,
          v29);
        v33 = *((unsigned int *)v24 + 4);
        switch ( (int)v33 )
        {
          case 0:
            v34 = cnss_wlfw_server_arrive(v9, v24[8]);
            goto LABEL_385;
          case 1:
            v34 = cnss_wlfw_server_exit(v9);
            goto LABEL_385;
          case 2:
            m3 = cnss_bus_alloc_fw_mem(v9);
            if ( m3 )
              goto LABEL_386;
            v34 = cnss_wlfw_respond_mem_send_sync(v9);
            goto LABEL_385;
          case 3:
            __asm { PRFM            #0x11, [X25] }
            do
              v176 = __ldxr(_X25);
            while ( __stxr(v176 | 2, _X25) );
            m3 = cnss_wlfw_tgt_cap_send_sync(v9);
            if ( !m3 )
            {
              cnss_bus_load_tme_patch(v9);
              cnss_wlfw_tme_patch_dnld_send_sync(v9, 0);
              if ( (*_X25 & 0x80000000) != 0 )
              {
                cnss_bus_load_tme_opt_file(v9);
                cnss_wlfw_tme_opt_file_dnld_send_sync(v9, 1);
                __asm { PRFM            #0x11, [X25] }
                do
                  v195 = __ldxr(_X25);
                while ( __stxr(v195 & 0xFFFFFFFF7FFFFFFFLL, _X25) );
              }
              if ( !(unsigned int)cnss_bus_load_sku_license(v9) )
                cnss_wlfw_soft_sku_dnld_send_sync(v9);
              if ( *(_BYTE *)(v10 - 102) )
                cnss_wlfw_bdf_dnld_send_sync(v9, 6);
              cnss_wlfw_bdf_dnld_send_sync(v9, 4);
              if ( *(_QWORD *)(v10 - 120) == 4354 )
              {
                v42 = 0;
                *(_DWORD *)(v10 + 6052) = 0;
              }
              else
              {
                v42 = *(unsigned int *)(v10 + 6052);
              }
              m3 = cnss_wlfw_bdf_dnld_send_sync(v9, v42);
              if ( !m3 )
              {
                if ( *(_QWORD *)(v10 - 120) == 4354 )
                {
                  m3 = 0;
                }
                else
                {
                  m3 = cnss_bus_load_m3(v9);
                  if ( !m3 )
                  {
                    m3 = cnss_wlfw_m3_dnld_send_sync(v9);
                    if ( !m3
                      && ((cnss_is_aux_support_enabled(v9) & 1) == 0
                       || (m3 = cnss_bus_load_aux(v9)) == 0 && (m3 = cnss_wlfw_aux_dnld_send_sync(v9)) == 0) )
                    {
                      cnss_wlfw_qdss_dnld_send_sync(v9);
                      __asm { PRFM            #0x11, [X25] }
                      do
                        v216 = __ldxr(_X25);
                      while ( __stxr(v216 & 0xFFFFFFFFBFFFFFFFLL, _X25) );
                      m3 = 0;
                    }
                  }
                }
              }
            }
            goto LABEL_386;
          case 4:
            v241 = 0;
            v36 = (__int64)v8[490];
            v37 = *(_DWORD *)(v22 + 16) & 0xF0000;
            if ( (*_X25 & 0x10000) == 0 )
            {
              if ( v37 )
              {
                v38 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v38 = "soft_irq";
              }
              else
              {
                v38 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                v36,
                v38,
                "cnss_fw_ready_hdlr",
                7u,
                7u,
                "Processing FW Init Done..\n",
                v33,
                v32,
                v230);
              timer_delete((timer_t)(v10 + 5624));
              __asm { PRFM            #0x11, [X25] }
              do
                v180 = __ldxr(_X25);
              while ( __stxr(v180 | 4, _X25) );
              __asm { PRFM            #0x11, [X25] }
              do
                v182 = __ldxr(_X25);
              while ( __stxr(v182 & 0xFFFFFFFFFFFFF7FFLL, _X25) );
              cnss_wlfw_send_pcie_gen_speed_sync(v9);
              cnss_send_subsys_restart_level_msg(v9);
              if ( (*_X25 & 0x400) != 0 )
              {
                __asm { PRFM            #0x11, [X25] }
                do
                  v184 = __ldxr(_X25);
                while ( __stxr(v184 & 0xFFFFFFFFFFFFFBFFLL, _X25) );
                __asm { PRFM            #0x11, [X25] }
                do
                  v186 = __ldxr(_X25);
                while ( __stxr(v186 & 0xFFFFFFFFFFFFFDFFLL, _X25) );
                if ( (*(_QWORD *)(v10 + 6032) & 0x20) != 0 )
                {
LABEL_533:
                  v112 = v9;
                  v113 = 3;
LABEL_534:
                  m3 = cnss_wlfw_wlan_mode_send_sync(v112, v113);
                  if ( !m3 )
                  {
LABEL_308:
                    cnss_vreg_unvote_type(v9, 0);
                    v8 = &off_5B000;
                    goto LABEL_386;
                  }
LABEL_535:
                  if ( (*_X25 & 0x800) != 0 )
                  {
                    v8 = &off_5B000;
                  }
                  else
                  {
                    cnss_bus_dev_shutdown(v9);
                    v8 = &off_5B000;
                    __asm { PRFM            #0x11, [X25] }
                    do
                      v197 = __ldxr(_X25);
                    while ( __stxr(v197 & 0xFFFFFFFFFFFFFFFBLL, _X25) );
                    __asm { PRFM            #0x11, [X25] }
                    do
                      v199 = __ldxr(_X25);
                    while ( __stxr(v199 & 0xFFFFFFFFFFFFFFFDLL, _X25) );
                  }
                  goto LABEL_386;
                }
              }
              else if ( (*(_QWORD *)(v10 + 6032) & 0x20) != 0 )
              {
                goto LABEL_533;
              }
              if ( (*_X25 & 8) != 0 )
              {
                if ( (*(_QWORD *)(v10 + 6096) || !(unsigned int)cnss_wlfw_antenna_switch_send_sync(v9))
                  && ((*_X25 & 0x2000) == 0 || !(unsigned int)coex_antenna_switch_to_wlan_send_sync_msg(v9)) )
                {
                  cnss_wlfw_antenna_grant_send_sync(v9);
                }
                v241 = **(_QWORD **)(v10 + 3400);
                cnss_cal_db_mem_update(v9, 1, &v241);
                cnss_wlfw_cal_report_req_send_sync(v9, v241);
                v112 = v9;
                v113 = 7;
                *(_QWORD *)(v10 + 3448) = jiffies;
                goto LABEL_534;
              }
              if ( !(unsigned int)cnss_qmi_get_dms_mac(v9) && *(_DWORD *)(v10 + 6908) )
              {
LABEL_306:
                cnss_wlfw_wlan_mac_req_send_sync(v9, v10 + 6912, 6);
              }
              else if ( v240[2746] )
              {
                v95 = cnss_plat_ipc_qmi_daemon_config();
                if ( !v95 || *(_BYTE *)(v95 + 1) )
                {
                  v98 = 200;
                  while ( !*(_DWORD *)(v10 + 6908) )
                  {
                    if ( (unsigned int)cnss_qmi_get_dms_mac(v9) )
                    {
                      msleep(50);
                      if ( --v98 )
                        continue;
                    }
                    if ( *(_DWORD *)(v10 + 6908) )
                      goto LABEL_306;
                    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                    {
                      v101 = "irq";
                    }
                    else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                    {
                      v101 = "soft_irq";
                    }
                    else
                    {
                      v101 = (const char *)(v22 + 2320);
                    }
                    cnss_debug_ipc_log_print(
                      cnss_ipc_log_context,
                      v101,
                      "cnss_setup_dms_mac",
                      3u,
                      3u,
                      "Unable to get MAC from DMS after retries\n",
                      v99,
                      v100,
                      v230);
                    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                    {
                      v154 = "irq";
                    }
                    else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                    {
                      v154 = "soft_irq";
                    }
                    else
                    {
                      v154 = (const char *)(v22 + 2320);
                    }
                    cnss_debug_ipc_log_print(
                      cnss_ipc_log_context,
                      v154,
                      "cnss_setup_dms_mac",
                      3u,
                      3u,
                      "ASSERT at line %d\n",
                      1312,
                      v153,
                      v233);
                    __break(0x800u);
                    goto LABEL_307;
                  }
                  goto LABEL_306;
                }
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v131 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v131 = "soft_irq";
                }
                else
                {
                  v131 = (const char *)(v22 + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v131,
                  "cnss_setup_dms_mac",
                  3u,
                  3u,
                  "DMS MAC address not supported\n",
                  v96,
                  v97,
                  v230);
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v149 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v149 = "soft_irq";
                }
                else
                {
                  v149 = (const char *)(v22 + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v149,
                  "cnss_setup_dms_mac",
                  3u,
                  3u,
                  "ASSERT at line %d\n",
                  1297,
                  v148,
                  v232);
                __break(0x800u);
              }
              else if ( *(_DWORD *)(v10 + 6908) )
              {
                goto LABEL_306;
              }
LABEL_307:
              m3 = cnss_bus_call_driver_probe(v9);
              if ( !m3 )
                goto LABEL_308;
              goto LABEL_535;
            }
            if ( v37 )
            {
              v41 = "irq";
            }
            else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
            {
              v41 = "soft_irq";
            }
            else
            {
              v41 = (const char *)(v22 + 2320);
            }
            v102 = "cnss_fw_ready_hdlr";
            v103 = "Reboot is in progress, ignore FW ready\n";
LABEL_206:
            cnss_debug_ipc_log_print(v36, v41, v102, 3u, 3u, v103, v33, v32, v230);
            m3 = -22;
            goto LABEL_386;
          case 5:
            if ( (*_X25 & 0x20000) != 0 )
            {
              v81 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v82 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v82 = "soft_irq";
              }
              else
              {
                v82 = (const char *)(v22 + 2320);
              }
              v104 = "Calibration complete. Ignore calibration req\n";
              goto LABEL_273;
            }
            if ( (*_X25 & 8) != 0 )
            {
              v81 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v82 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v82 = "soft_irq";
              }
              else
              {
                v82 = (const char *)(v22 + 2320);
              }
              v104 = "Calibration in progress. Ignore new calibration req\n";
              goto LABEL_273;
            }
            if ( (*_X25 & 0x1000000) != 0 )
            {
              v81 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v82 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v82 = "soft_irq";
              }
              else
              {
                v82 = (const char *)(v22 + 2320);
              }
              v104 = "Calibration deferred as WLAN device disabled\n";
LABEL_273:
              cnss_debug_ipc_log_print(v81, v82, "cnss_cold_boot_cal_start_hdlr", 7u, 7u, v104, v33, v32, v230);
              m3 = 0;
              goto LABEL_386;
            }
            if ( (*_X25 & 0x10) != 0 || (*_X25 & 0x100) != 0 || (*_X25 & 4) != 0 )
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v108 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v108 = "soft_irq";
              }
              else
              {
                v108 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v108,
                "cnss_cold_boot_cal_start_hdlr",
                3u,
                3u,
                "WLAN in mission mode before cold boot calibration\n",
                v33,
                v32,
                v230);
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v120 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v120 = "soft_irq";
              }
              else
              {
                v120 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v120,
                "cnss_cold_boot_cal_start_hdlr",
                3u,
                3u,
                "ASSERT at line %d\n",
                3585,
                v119,
                v231);
              __break(0x800u);
              m3 = -22;
            }
            else
            {
              v43 = 100;
              while ( (*_X25 & 0x400000) == 0 )
              {
                msleep(500);
                if ( !--v43 )
                {
                  v8 = &off_5B000;
                  if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                  {
                    v45 = "irq";
                  }
                  else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                  {
                    v45 = "soft_irq";
                  }
                  else
                  {
                    v45 = (const char *)(v22 + 2320);
                  }
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_context,
                    v45,
                    "cnss_cold_boot_cal_start_hdlr",
                    3u,
                    3u,
                    "Calibration start failed as PCI probe not complete\n",
                    v44,
                    v32,
                    v230);
                  if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                  {
                    v156 = "irq";
                  }
                  else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                  {
                    v156 = "soft_irq";
                  }
                  else
                  {
                    v156 = (const char *)(v22 + 2320);
                  }
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_context,
                    v156,
                    "cnss_cold_boot_cal_start_hdlr",
                    3u,
                    3u,
                    "ASSERT at line %d\n",
                    3596,
                    v155,
                    v234);
                  __break(0x800u);
                  m3 = -22;
                  goto LABEL_471;
                }
              }
              v140 = *(_QWORD *)(v10 - 120);
              v8 = &off_5B000;
              if ( (unsigned __int64)(v140 - 4352) > 0x12 || ((1LL << v140) & 0x6448B) == 0 )
              {
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v169 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v169 = "soft_irq";
                }
                else
                {
                  v169 = (const char *)(v22 + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v169,
                  "cnss_cold_boot_cal_start_hdlr",
                  3u,
                  3u,
                  "Not supported for device ID 0x%lx\n",
                  v140,
                  v32,
                  v230);
                m3 = -22;
LABEL_471:
                complete(v10 + 5696);
                __asm { PRFM            #0x11, [X25] }
                do
                  v203 = __ldxr(_X25);
                while ( __stxr(v203 & 0xFFFFFFFFFFFFFFF7LL, _X25) );
                v240[1768] = 2;
                __asm { PRFM            #0x11, [X25] }
                do
                  v205 = __ldxr(_X25);
                while ( __stxr(v205 | 0x20000, _X25) );
                v165 = *(_QWORD *)(v10 - 120);
                if ( (v165 == 4354 || v165 == 62) && (*_X25 & 0x800000) != 0 )
                {
                  if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                    v166 = "irq";
                  else
                    v166 = (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(v22 + 2320);
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_context,
                    v166,
                    "cnss_cold_boot_cal_start_hdlr",
                    6u,
                    6u,
                    "Schedule WLAN driver load\n",
                    v163,
                    v164,
                    v230);
                  if ( (cancel_delayed_work_sync(v10 + 72) & 1) != 0 )
                    queue_delayed_work_on(32, system_wq, v10 + 72, 0);
                }
                goto LABEL_386;
              }
              __asm { PRFM            #0x11, [X25] }
              do
                v209 = __ldxr(_X25);
              while ( __stxr(v209 | 8, _X25) );
              if ( (*_X25 & 0x800000) != 0 )
              {
                qmi_timeout = cnss_get_qmi_timeout(v9);
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                  v144 = "irq";
                else
                  v144 = (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(v22 + 2320);
                v161 = qmi_timeout + 120000;
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v144,
                  "cnss_cold_boot_cal_start_hdlr",
                  7u,
                  7u,
                  "Restarting calibration %ds timeout\n",
                  (unsigned int)(qmi_timeout + 120000) / 0x3E8uLL,
                  v143,
                  v230);
                if ( (cancel_delayed_work_sync(v10 + 72) & 1) != 0 )
                {
                  v162 = _msecs_to_jiffies(v161);
                  queue_delayed_work_on(32, system_wq, v10 + 72, v162);
                }
              }
              *(_DWORD *)(v10 + 5696) = 0;
              m3 = cnss_bus_dev_powerup(v9);
              if ( m3 )
                goto LABEL_471;
            }
            goto LABEL_386;
          case 6:
            v46 = (_DWORD *)v24[8];
            if ( (*_X25 & 8) == 0 || (*_X25 & 0x20000) != 0 )
              goto LABEL_356;
            v47 = (unsigned int)*v46;
            if ( (unsigned int)(v47 - 1) < 2 )
            {
              v48 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v49 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v49 = "soft_irq";
              }
              else
              {
                v49 = (const char *)(v22 + 2320);
              }
              v114 = "Calibration failed. Status: %d, force shutdown\n";
              v115 = 7;
              v116 = 7;
LABEL_321:
              cnss_debug_ipc_log_print(v48, v49, "cnss_cold_boot_cal_done_hdlr", v115, v116, v114, v47, v32, v230);
              goto LABEL_322;
            }
            if ( (_DWORD)v47 )
            {
              v48 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v49 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v49 = "soft_irq";
              }
              else
              {
                v49 = (const char *)(v22 + 2320);
              }
              v114 = "Unknown calibration status: %u\n";
              v115 = 3;
              v116 = 3;
              goto LABEL_321;
            }
            if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
            {
              v107 = "irq";
            }
            else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
            {
              v107 = "soft_irq";
            }
            else
            {
              v107 = (const char *)(v22 + 2320);
            }
            cnss_debug_ipc_log_print(
              (__int64)v8[490],
              v107,
              "cnss_cold_boot_cal_done_hdlr",
              7u,
              7u,
              "Calibration completed successfully\n",
              v47,
              v32,
              v230);
            v240[1768] = 1;
LABEL_322:
            cnss_wlfw_wlan_mode_send_sync(v9, 4);
            cnss_bus_free_qdss_mem(v9);
            if ( (*_X25 & 0x2000) != 0 )
              coex_antenna_switch_to_mdm_send_sync_msg(v9);
            if ( *(_QWORD *)(v10 - 120) != 4354 )
            {
              cnss_bus_dev_shutdown(v9);
              msleep(100);
            }
            complete(v10 + 5696);
            __asm { PRFM            #0x11, [X25] }
            do
              v188 = __ldxr(_X25);
            while ( __stxr(v188 & 0xFFFFFFFFFFFFFFF7LL, _X25) );
            __asm { PRFM            #0x11, [X25] }
            do
              v190 = __ldxr(_X25);
            while ( __stxr(v190 | 0x20000, _X25) );
            if ( !*v46 )
            {
              if ( **(_QWORD **)(v10 + 3400) >= (unsigned __int64)*(unsigned int *)(v10 + 3460) )
              {
                cnss_cal_db_mem_update(v9, 0, v10 + 3460);
              }
              else
              {
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                  v123 = "irq";
                else
                  v123 = (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(v22 + 2320);
                cnss_debug_ipc_log_print(
                  (__int64)v8[490],
                  v123,
                  "cnss_cal_mem_upload_to_file",
                  3u,
                  3u,
                  "Cal file size is larger than Cal DB Mem size\n",
                  v121,
                  v122,
                  v230);
              }
              if ( (*_X25 & 0x800000) != 0 )
              {
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                  v130 = "irq";
                else
                  v130 = (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(v22 + 2320);
                cnss_debug_ipc_log_print(
                  (__int64)v8[490],
                  v130,
                  "cnss_cold_boot_cal_done_hdlr",
                  7u,
                  7u,
                  "Schedule WLAN driver load\n",
                  v124,
                  v125,
                  v230);
                if ( (cancel_delayed_work_sync(v10 + 72) & 1) != 0 )
                  queue_delayed_work_on(32, system_wq, v10 + 72, 0);
              }
            }
LABEL_356:
            kfree(v46);
            m3 = 0;
            goto LABEL_386;
          case 7:
            v34 = cnss_bus_register_driver_hdlr(v9);
            goto LABEL_385;
          case 8:
            v34 = cnss_bus_unregister_driver_hdlr(v9);
            goto LABEL_385;
          case 9:
            v39 = (int *)v24[8];
            if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
            {
              v40 = "irq";
            }
            else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
            {
              v40 = "soft_irq";
            }
            else
            {
              v40 = (const char *)(v22 + 2320);
            }
            v84 = (unsigned int)*v39;
            v85 = "UNKNOWN";
            if ( (unsigned int)v84 <= 5 )
              v85 = off_5AEC0[v84];
            cnss_debug_ipc_log_print(
              (__int64)v8[490],
              v40,
              "cnss_driver_recovery_hdlr",
              7u,
              7u,
              "Driver recovery is triggered with reason: %s(%d)\n",
              (__int64)v85,
              v84,
              v230);
            v87 = *_X25;
            if ( !*_X25 )
            {
              v89 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v90 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v90 = "soft_irq";
              }
              else
              {
                v90 = (const char *)(v22 + 2320);
              }
              v106 = "Improper driver state, ignore recovery\n";
LABEL_282:
              cnss_debug_ipc_log_print(v89, v90, "cnss_driver_recovery_hdlr", 3u, 3u, v106, v87, v86, v230);
LABEL_283:
              m3 = -22;
              goto LABEL_284;
            }
            if ( (*_X25 & 0x10000) != 0 )
            {
              v89 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v90 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v90 = "soft_irq";
              }
              else
              {
                v90 = (const char *)(v22 + 2320);
              }
              v106 = "Reboot is in progress, ignore recovery\n";
              goto LABEL_282;
            }
            if ( (*_X25 & 0x200) != 0 )
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v105 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v105 = "soft_irq";
              }
              else
              {
                v105 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v105,
                "cnss_driver_recovery_hdlr",
                3u,
                3u,
                "Recovery is already in progress, driver state 0x%lx\n",
                v87,
                v86,
                v230);
              if ( *v39 != 1 )
              {
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v111 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v111 = "soft_irq";
                }
                else
                {
                  v111 = (const char *)(v22 + 2320);
                }
                cnss_debug_ipc_log_print(
                  (__int64)v8[490],
                  v111,
                  "cnss_driver_recovery_hdlr",
                  3u,
                  3u,
                  "ASSERT at line %d\n",
                  3331,
                  v110,
                  v230);
                __break(0x800u);
              }
              goto LABEL_283;
            }
            if ( (*_X25 & 0x20) != 0 || (*_X25 & 0x80) != 0 )
            {
              v89 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v90 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v90 = "soft_irq";
              }
              else
              {
                v90 = (const char *)(v22 + 2320);
              }
              v106 = "Driver unload or idle shutdown is in progress, ignore recovery\n";
              goto LABEL_282;
            }
            v88 = *(_QWORD *)(v10 - 96);
            if ( *(_QWORD *)(v10 - 120) == 62 )
            {
              if ( (v88 & 0x10) != 0 || (*_X25 & 0x40) != 0 )
              {
                v89 = (__int64)v8[490];
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v90 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v90 = "soft_irq";
                }
                else
                {
                  v90 = (const char *)(v22 + 2320);
                }
                v106 = "Driver load or idle restart is in progress, ignore recovery\n";
                goto LABEL_282;
              }
            }
            else if ( (v88 & 4) == 0 )
            {
              __asm { PRFM            #0x11, [X25] }
              do
                v207 = __ldxr(_X25);
              while ( __stxr(v207 | 0x400, _X25) );
            }
            __asm { PRFM            #0x11, [X25] }
            do
              v201 = __ldxr(_X25);
            while ( __stxr(v201 | 0x200, _X25) );
            v127 = *(_QWORD *)(v10 - 120);
            v128 = *v39;
            ++*(_DWORD *)(v10 - 108);
            if ( v127 == 62 )
              goto LABEL_342;
            if ( (*(_QWORD *)(v10 + 6032) & 8) != 0 )
            {
              v145 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v146 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v146 = "soft_irq";
              }
              else
              {
                v146 = (const char *)(v22 + 2320);
              }
              v160 = "Skip device recovery\n";
LABEL_460:
              cnss_debug_ipc_log_print(v145, v146, "cnss_do_recovery", 7u, 7u, v160, v87, v86, v230);
              goto LABEL_513;
            }
            v237 = v128;
            v235 = *(_QWORD *)(v10 + 6792);
            cnss_get_qmi_timeout(v9);
            pm_wakeup_ws_event(v235, 60000, 1);
            v138 = (unsigned int)v237;
            if ( v237 > 1 )
            {
              if ( v237 == 2 )
              {
                v167 = cnss_bus_collect_dump_info(v9, 0);
                if ( v167 == -11 )
                  goto LABEL_513;
                if ( v167 )
                  goto LABEL_511;
              }
              else
              {
                if ( v237 != 3 )
                {
                  if ( v237 == 5 )
                  {
                    cnss_bus_soc_reset_cause_reg_dump(v9);
                  }
                  else
                  {
LABEL_486:
                    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                    {
                      v168 = "irq";
                    }
                    else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                    {
                      v168 = "soft_irq";
                    }
                    else
                    {
                      v168 = (const char *)(v22 + 2320);
                    }
                    v170 = "FW_ASSERTION_FAIL";
                    if ( v237 != 4 )
                      v170 = "UNKNOWN";
                    cnss_debug_ipc_log_print(
                      (__int64)v8[490],
                      v168,
                      "cnss_do_recovery",
                      3u,
                      3u,
                      "Unsupported recovery reason: %s(%d)\n",
                      (__int64)v170,
                      (unsigned int)v237,
                      v230);
                  }
                  goto LABEL_512;
                }
LABEL_511:
                cnss_xdump_wl_over_bt_req(v9, v132, v133, v134, v135, v136, v137, v138);
              }
LABEL_512:
              cnss_bus_device_crashed(v9);
              goto LABEL_513;
            }
            if ( !v237 )
              goto LABEL_512;
            if ( v237 != 1 )
              goto LABEL_486;
            if ( !(unsigned int)cnss_bus_check_link_status(v9) )
            {
              v145 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v146 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v146 = "soft_irq";
              }
              else
              {
                v146 = (const char *)(v22 + 2320);
              }
              v160 = "Skip link down recovery as link is already up\n";
              goto LABEL_460;
            }
            if ( (*(_QWORD *)(v10 + 6032) & 1) != 0 )
            {
LABEL_342:
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v129 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v129 = "soft_irq";
              }
              else
              {
                v129 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v129,
                "cnss_do_recovery",
                7u,
                7u,
                "Going for self recovery\n",
                v87,
                v86,
                v230);
              cnss_bus_dev_shutdown(v9);
              if ( (*_X25 & 0x8000) != 0 )
              {
                __asm { PRFM            #0x11, [X25] }
                do
                  v211 = __ldxr(_X25);
                while ( __stxr(v211 & 0xFFFFFFFFFFFF7FFFLL, _X25) );
                if ( (*(_QWORD *)(v10 + 6032) & 1) != 0 )
                  goto LABEL_564;
LABEL_418:
                v151 = *_X25;
                if ( (*_X25 & 0x800000) != 0 )
                  goto LABEL_422;
LABEL_423:
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v152 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v152 = "soft_irq";
                }
                else
                {
                  v152 = (const char *)(v22 + 2320);
                }
                cnss_debug_ipc_log_print(
                  (__int64)v8[490],
                  v152,
                  "cnss_do_recovery",
                  7u,
                  7u,
                  "Host driver not registered yet, ignore Device Power Up, 0x%lx\n",
                  v151,
                  v150,
                  v230);
              }
              else
              {
                if ( (*(_QWORD *)(v10 + 6032) & 1) == 0 )
                  goto LABEL_418;
LABEL_564:
                _X8 = (unsigned __int64 *)(v10 + 6032);
                __asm { PRFM            #0x11, [X8] }
                do
                  v214 = __ldxr(_X8);
                while ( __stxr(v214 & 0xFFFFFFFFFFFFFFFELL, _X8) );
                v151 = *_X25;
                if ( (*_X25 & 0x800000) == 0 )
                  goto LABEL_423;
LABEL_422:
                v151 = *_X25;
                if ( (*_X25 & 0x4000000) == 0 )
                  goto LABEL_423;
                if ( (unsigned int)cnss_bus_dev_powerup(v9) )
                {
                  __asm { PRFM            #0x11, [X25] }
                  do
                    v218 = __ldxr(_X25);
                  while ( __stxr(v218 & 0xFFFFFFFFFFFFFDFFLL, _X25) );
                }
              }
LABEL_513:
              m3 = 0;
              goto LABEL_284;
            }
            if ( (unsigned int)cnss_bus_recover_link_down(v9) )
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v159 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v159 = "soft_irq";
              }
              else
              {
                v159 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v159,
                "cnss_do_recovery",
                3u,
                3u,
                "Link recovery fail\n",
                v157,
                v158,
                v230);
              v9 = v238;
              v8 = &off_5B000;
              goto LABEL_511;
            }
            __asm { PRFM            #0x11, [X25] }
            do
              v220 = __ldxr(_X25);
            while ( __stxr(v220 & 0xFFFFFFFFFFFFFDFFLL, _X25) );
            v9 = v238;
            m3 = 0;
            v8 = &off_5B000;
LABEL_284:
            kfree(v39);
            goto LABEL_386;
          case 10:
            v34 = cnss_bus_force_fw_assert_hdlr(v9);
            goto LABEL_385;
          case 11:
            goto LABEL_74;
          case 12:
            goto LABEL_35;
          case 13:
            __asm { PRFM            #0x11, [X25] }
            do
              v178 = __ldxr(_X25);
            while ( __stxr(v178 | 0x40, _X25) );
LABEL_74:
            m3 = cnss_bus_dev_powerup(v9);
            if ( m3 )
            {
              __asm { PRFM            #0x11, [X25] }
              do
                v172 = __ldxr(_X25);
              while ( __stxr(v172 & 0xFFFFFFFFFFFFFFBFLL, _X25) );
            }
            goto LABEL_386;
          case 14:
            __asm { PRFM            #0x11, [X25] }
            do
              v174 = __ldxr(_X25);
            while ( __stxr(v174 | 0x80, _X25) );
LABEL_35:
            cnss_bus_dev_shutdown(v9);
            m3 = 0;
            goto LABEL_386;
          case 15:
            v34 = cnss_process_wfc_call_ind_event(v9, v24[8]);
            goto LABEL_385;
          case 16:
            v34 = cnss_process_twt_cfg_ind_event(v9, v24[8]);
            goto LABEL_385;
          case 17:
            v34 = cnss_bus_alloc_qdss_mem(v9);
            if ( (v34 & 0x80000000) == 0 )
              v34 = cnss_wlfw_qdss_trace_mem_info_send_sync(v9);
            goto LABEL_385;
          case 18:
            v50 = v24[8];
            v51 = *(unsigned int *)(v50 + 8);
            if ( (_DWORD)v51 == 6 )
            {
              v10 = *(unsigned int *)(v10 + 3496);
              if ( (_DWORD)v10 )
              {
                v52 = 4152;
                if ( *(_DWORD *)(v50 + 4) )
                  goto LABEL_85;
LABEL_149:
                m3 = 0;
                goto LABEL_241;
              }
              goto LABEL_150;
            }
            if ( (_DWORD)v51 != 1 || (v10 = *(unsigned int *)(v239 + 1072), !(_DWORD)v10) )
            {
LABEL_150:
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v92 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v92 = "soft_irq";
              }
              else
              {
                v92 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v92,
                "cnss_fw_mem_file_save_hdlr",
                3u,
                3u,
                "FW Mem type %d not allocated. Invalid save request\n",
                v51,
                v32,
                v230);
LABEL_240:
              m3 = -22;
LABEL_241:
              kfree(v50);
              v9 = v238;
              v10 = v239;
              v8 = &off_5B000;
LABEL_386:
              v21 = raw_spin_lock_irqsave(v20);
              if ( *((_BYTE *)v24 + 20) == 1 )
              {
                *((_DWORD *)v24 + 14) = m3;
                complete(v24 + 3);
              }
              else
              {
                raw_spin_unlock_irqrestore(v20, v21);
LABEL_388:
                kfree(v24);
                v21 = raw_spin_lock_irqsave(v20);
              }
              v24 = (_QWORD *)*v23;
              if ( (_QWORD *)*v23 == v23 )
                goto LABEL_574;
              continue;
            }
            v52 = 1728;
            if ( !*(_DWORD *)(v50 + 4) )
              goto LABEL_149;
LABEL_85:
            v9 = 0;
            v53 = v50 + 16;
            v8 = (char **)(v238 + v52);
            while ( v9 != 52 )
            {
              v54 = v53 + 16 * v9;
              v55 = 0;
              v56 = *(char **)v54;
              v57 = *(unsigned int *)(v54 + 8);
              while ( 1 )
              {
                if ( v55 != 11 )
                {
                  v58 = &v8[5 * v55];
                  v59 = v58[2];
                  if ( v56 == v59 && (unsigned int)v57 <= (unsigned int)*v58 )
                  {
                    v63 = (__int64)v58[1];
                    goto LABEL_99;
                  }
                  v61 = v56 - v59;
                  if ( v56 > v59 )
                  {
                    v62 = &v59[(unsigned int)*v58];
                    if ( v62 > v56 && *(_QWORD *)v54 + v57 <= (unsigned __int64)v62 )
                      break;
                  }
                }
                if ( (_DWORD)v10 == ++v55 )
                  goto LABEL_156;
              }
              v63 = (__int64)&v58[1][v61];
LABEL_99:
              if ( !v63 )
              {
LABEL_156:
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v93 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v93 = "soft_irq";
                }
                else
                {
                  v93 = (const char *)(v22 + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v93,
                  "cnss_fw_mem_file_save_hdlr",
                  3u,
                  3u,
                  "Fail to find matching va of pa %pa for mem type: %d\n",
                  v54,
                  *(unsigned int *)(v50 + 8),
                  v230);
                goto LABEL_240;
              }
              v236 = _X25;
              v64 = v53;
              m3 = cnss_genl_send_msg(v63, 1u, (const char *)(v50 + 848), v57);
              if ( (m3 & 0x80000000) != 0 )
              {
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v147 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v147 = "soft_irq";
                }
                else
                {
                  v147 = (const char *)(v22 + 2320);
                }
                _X25 = v236;
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v147,
                  "cnss_fw_mem_file_save_hdlr",
                  3u,
                  3u,
                  "Fail to save fw mem data: %d\n",
                  m3,
                  v65,
                  v230);
                goto LABEL_241;
              }
              ++v9;
              v53 = v64;
              _X25 = v236;
              if ( v9 >= *(unsigned int *)(v50 + 4) )
                goto LABEL_241;
            }
            __break(0x5512u);
            break;
          case 19:
            cnss_bus_free_qdss_mem(v9);
            m3 = 0;
            goto LABEL_386;
          case 20:
            v39 = (int *)v24[8];
            m3 = cnss_wlfw_qdss_data_send_sync(v9, v39 + 212, (unsigned int)*v39);
            goto LABEL_284;
          case 21:
            v46 = (_DWORD *)v24[8];
            cnss_bus_recover_link_post_sol(v9);
            goto LABEL_356;
          case 22:
            v66 = (_BYTE *)v24[8];
            if ( !v66 )
            {
              v74 = -22;
              goto LABEL_384;
            }
            v240[3200] = *v66;
            kfree(v66);
            v69 = *(_QWORD *)(v10 + 7280);
            if ( v69
              && v69 <= 0xFFFFFFFFFFFFF000LL
              && (v70 = *(_QWORD *)(v10 + 7288)) != 0
              && v70 < 0xFFFFFFFFFFFFF001LL )
            {
              v71 = nvmem_cell_write();
              if ( (v71 & 0x80000000) != 0 )
              {
                v74 = v71;
                v75 = (__int64)v8[490];
                if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                {
                  v76 = "irq";
                }
                else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                {
                  v76 = "soft_irq";
                }
                else
                {
                  v76 = (const char *)(v22 + 2320);
                }
                v126 = "Fail to write xo_calib_reg, ret = %d\n";
              }
              else
              {
                v73 = regulator_enable(*(_QWORD *)(v10 + 7288));
                if ( v73 )
                {
                  v74 = v73;
                  v75 = (__int64)v8[490];
                  if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                  {
                    v76 = "irq";
                  }
                  else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                  {
                    v76 = "soft_irq";
                  }
                  else
                  {
                    v76 = (const char *)(v22 + 2320);
                  }
                  v126 = "Fail to enable wcal_pbs: %d\n";
                }
                else
                {
                  v74 = regulator_disable(*(_QWORD *)(v10 + 7288));
                  if ( !v74 )
                    goto LABEL_378;
                  v75 = (__int64)v8[490];
                  if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
                  {
                    v76 = "irq";
                  }
                  else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                  {
                    v76 = "soft_irq";
                  }
                  else
                  {
                    v76 = (const char *)(v22 + 2320);
                  }
                  v126 = "Fail to disable wcal_pbs: %d\n";
                }
              }
              cnss_debug_ipc_log_print(v75, v76, "cnss_xo_trim_perform", 3u, 3u, v126, v74, v72, v230);
            }
            else
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v83 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v83 = "soft_irq";
              }
              else
              {
                v83 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v83,
                "cnss_xo_trim_perform",
                3u,
                3u,
                "Invalid xo trim config\n",
                v67,
                v68,
                v230);
              v74 = -22;
            }
LABEL_378:
            if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
            {
              v139 = "irq";
            }
            else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
            {
              v139 = "soft_irq";
            }
            else
            {
              v139 = (const char *)(v22 + 2320);
            }
            cnss_debug_ipc_log_print(
              (__int64)v8[490],
              v139,
              "cnss_xo_trim_ind_hdlr",
              7u,
              7u,
              "XO trim result with value(%u): %d\n",
              (unsigned __int8)v240[3200],
              v74,
              v230);
LABEL_384:
            v34 = cnss_wlfw_xo_trim_result_send_sync(v9, v74);
            goto LABEL_385;
          case 23:
            v77 = (char *)v24[8];
            v78 = *v77;
            kfree(v77);
            v79 = v78 & 6;
            v8 = &off_5B000;
            v240[3210] = v79 | v240[3210] & 0xF8 | 1;
            cnss_xdump_update_config((_BYTE *)v9);
            v34 = cnss_genl_send_xdump_wlan_arrival(
                    (v240[3209] & 2) != 0,
                    (v240[3209] & 4) != 0,
                    0,
                    *(_DWORD *)(v10 + 5952));
            goto LABEL_385;
          case 24:
            if ( !v240[3212] )
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v91 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v91 = "soft_irq";
              }
              else
              {
                v91 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v91,
                "cnss_xdump_bt_over_wl_req_hdlr",
                6u,
                6u,
                "XDUMP: bt_over_wlan NOT enabled, bt_cap(%d: %d) wl_cap(%d: %d) user_config(%d: %d)\n",
                v240[3210] & 1,
                ((unsigned __int8)v240[3210] >> 2) & 1,
                v240[3209] & 1);
              v34 = cnss_genl_send_xdump_bt_over_wl_resp(0xFFFFFFA1);
              goto LABEL_385;
            }
            if ( v240[3213] )
            {
              v36 = (__int64)v8[490];
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v41 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v41 = "soft_irq";
              }
              else
              {
                v41 = (const char *)(v22 + 2320);
              }
              v102 = "cnss_xdump_bt_over_wl_req_hdlr";
              v103 = "Collect WLAN dump over BT is in progress\n";
              goto LABEL_206;
            }
            if ( v240[3214] )
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v94 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v94 = "soft_irq";
              }
              else
              {
                v94 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v94,
                "cnss_xdump_bt_over_wl_req_hdlr",
                3u,
                3u,
                "Collect BT dump over WLAN is in progress\n",
                v33,
                v32,
                v230);
              v34 = cnss_genl_send_xdump_bt_over_wl_resp(0xFFFFFF8E);
              goto LABEL_385;
            }
            if ( (*_X25 & 4) == 0 )
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v109 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v109 = "soft_irq";
              }
              else
              {
                v109 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v109,
                "cnss_xdump_bt_over_wl_req_hdlr",
                3u,
                3u,
                "FW not ready\n",
                v33,
                v32,
                v230);
              v34 = cnss_genl_send_xdump_bt_over_wl_resp(0xFFFFFFF3);
              goto LABEL_385;
            }
            if ( (*_X25 & 0x200) != 0 || (*_X25 & 0x800) != 0 || (*_X25 & 0x20) != 0 || (*_X25 & 0x80) != 0 )
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
              {
                v118 = "irq";
              }
              else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                v118 = "soft_irq";
              }
              else
              {
                v118 = (const char *)(v22 + 2320);
              }
              cnss_debug_ipc_log_print(
                (__int64)v8[490],
                v118,
                "cnss_xdump_bt_over_wl_req_hdlr",
                7u,
                7u,
                "Ignore BT dump request\n",
                v33,
                v32,
                v230);
              v34 = cnss_genl_send_xdump_bt_over_wl_resp(0xFFFFFFF0);
              goto LABEL_385;
            }
            v240[3214] = 1;
            v117 = cnss_wlfw_req_bt_dump_send_sync(v9);
            if ( v117 )
            {
              v240[3214] = 0;
              v34 = cnss_genl_send_xdump_bt_over_wl_resp(v117);
LABEL_385:
              m3 = v34;
              goto LABEL_386;
            }
            cnss_bus_start_xdump_timer(v9);
            m3 = 0;
            goto LABEL_386;
          default:
            v80 = "irq";
            if ( (*(_DWORD *)(v22 + 16) & 0xF0000) == 0 )
            {
              if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
                v80 = "soft_irq";
              else
                v80 = (const char *)(v22 + 2320);
            }
            cnss_debug_ipc_log_print(
              (__int64)v8[490],
              v80,
              "cnss_driver_event_work",
              3u,
              3u,
              "Invalid driver event type: %d",
              v33,
              v32,
              v230);
            goto LABEL_388;
        }
        break;
      }
    }
LABEL_574:
    result = raw_spin_unlock_irqrestore(v20, v21);
    _X9 = (unsigned int *)(v10 + 5616);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v228 = __ldxr(_X9);
      v229 = v228 - 1;
    }
    while ( __stlxr(v229, _X9) );
    __dmb(0xBu);
    if ( (v229 & 0x80000000) != 0 )
    {
      __break(0x800u);
    }
    else if ( !v229 )
    {
      if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
      {
        v221 = "irq";
      }
      else if ( (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
      {
        v221 = "soft_irq";
      }
      else
      {
        v221 = (const char *)(v22 + 2320);
      }
      cnss_debug_ipc_log_print(
        (__int64)v8[490],
        v221,
        "cnss_pm_relax",
        7u,
        7u,
        "PM relax, state: 0x%lx, count: %d\n",
        *(_QWORD *)(v10 - 96),
        *(unsigned int *)(v10 + 5616),
        v230);
      result = pm_relax(*(_QWORD *)v9 + 16LL);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
