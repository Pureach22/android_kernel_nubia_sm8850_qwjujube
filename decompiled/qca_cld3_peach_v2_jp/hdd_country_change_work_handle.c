__int64 __fastcall hdd_country_change_work_handle(
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
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 v20; // x20
  unsigned __int64 StatusReg; // x8
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x1
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x0
  __int64 v51; // x26
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x8
  unsigned int link_info_home_channel; // w24
  _BOOL4 is_disable_for_pwrmode; // w27
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int max_phymode; // w28
  __int64 v81; // x23
  void *v82; // x0
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x25
  unsigned int link_info_width; // w0
  unsigned __int16 bw_value; // w0
  unsigned __int64 v94; // x9
  _BOOL4 v95; // w23
  __int64 v96; // x8
  bool v97; // cf
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v106; // x0
  _BOOL4 v107; // w4
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  int peer_phymode; // w0
  unsigned int v117; // w8
  __int64 v118; // x1
  __int64 v119; // x20
  unsigned __int64 v120; // x8
  unsigned int *v121; // x8
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 v130; // x1
  unsigned int *v131; // x8
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x8
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  __int64 v149; // x8
  const char *v150; // x25
  const char *v151; // x22
  const char *v152; // x21
  __int64 v153; // x26
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  unsigned int *v162; // x8
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  __int64 v171; // x8
  unsigned int v172; // w0
  int v173; // w9
  unsigned int v174; // w27
  double v175; // d0
  unsigned int v176; // w0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  __int64 v184; // x0
  int v185; // w0
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  double v194; // d0
  double v195; // d1
  double v196; // d2
  double v197; // d3
  double v198; // d4
  double v199; // d5
  double v200; // d6
  double v201; // d7
  const char *v202; // x23
  __int64 v203; // x21
  const char *v204; // x20
  const char *v205; // x22
  int v206; // w28
  __int64 v207; // x25
  __int64 v208; // x27
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  int v217; // w8
  const char *v218; // x2
  double v219; // d0
  double v220; // d1
  double v221; // d2
  double v222; // d3
  double v223; // d4
  double v224; // d5
  double v225; // d6
  double v226; // d7
  int safe_channel_from_pcl_and_acs_range; // w0
  int v228; // w8
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  int v237; // w27
  unsigned __int64 v238; // [xsp+0h] [xbp-30h]
  unsigned __int64 v239; // [xsp+0h] [xbp-30h]
  __int64 v240; // [xsp+8h] [xbp-28h] BYREF
  int v241; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v242; // [xsp+18h] [xbp-18h] BYREF
  __int64 v243[2]; // [xsp+20h] [xbp-10h] BYREF

  v243[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v240 = 0;
  v10 = _wlan_hdd_validate_context(a1, (__int64)"hdd_country_change_work_handle", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !v10 )
  {
    v10 = _osif_psoc_sync_op_start(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 488LL), &v240, "hdd_country_change_work_handle");
    if ( !v10 )
    {
      if ( *(_DWORD *)(a1 + 1464) != 1 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Driver disabled, ignore country code change",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "hdd_country_change_work_handle");
        goto LABEL_121;
      }
      v20 = *(_QWORD *)(a1 + 8);
      v243[0] = 0;
      v242 = 0;
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
      hdd_get_front_adapter_no_lock(a1, v243);
      if ( v243[0] )
      {
        hdd_adapter_dev_hold_debug(v243[0], 0x37u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
        v31 = v243[0];
      }
      else
      {
        v31 = 0;
      }
      hdd_get_next_adapter_no_lock(a1, v31, &v242);
      if ( v242 )
        hdd_adapter_dev_hold_debug(v242, 0x37u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
      v41 = *(_QWORD *)(a1 + 40);
      if ( (v41 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 40) = v41 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 32);
        v50 = v243[0];
        if ( !v243[0] )
          goto LABEL_68;
      }
      else
      {
        raw_spin_unlock(a1 + 32);
        v50 = v243[0];
        if ( !v243[0] )
          goto LABEL_68;
      }
      v238 = _ReadStatusReg(SP_EL0);
      do
      {
        while ( 1 )
        {
          if ( (*(_QWORD *)(v50 + 1640) & 1) != 0 )
          {
            v51 = v50 + 52832;
            if ( v50 != -52832 )
            {
              do
              {
                link_info_home_channel = hdd_get_link_info_home_channel((_DWORD *)v51);
                if ( link_info_home_channel )
                  is_disable_for_pwrmode = wlan_reg_is_disable_for_pwrmode(
                                             v20,
                                             link_info_home_channel,
                                             0,
                                             v42,
                                             v43,
                                             v44,
                                             v45,
                                             v46,
                                             v47,
                                             v48,
                                             v49);
                else
                  is_disable_for_pwrmode = 0;
                v50 = v243[0];
                if ( (*(_DWORD *)(v243[0] + 40) | 2) == 2 )
                {
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: Update vdev %d CAP IE",
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    "hdd_country_change_update_sta",
                    *(unsigned __int8 *)(v51 + 8));
                  sme_set_vdev_ies_per_band(*(_QWORD *)(a1 + 16), *(unsigned __int8 *)(v51 + 8), 0);
                  max_phymode = wlan_reg_get_max_phymode(
                                  v20,
                                  7u,
                                  link_info_home_channel,
                                  v72,
                                  v73,
                                  v74,
                                  v75,
                                  v76,
                                  v77,
                                  v78,
                                  v79);
                  v81 = *(_QWORD *)(*(_QWORD *)v51 + 24LL);
                  v82 = (void *)_qdf_mem_malloc(0xE58u, "hdd_country_change_bw_check", 1662);
                  if ( v82 )
                  {
                    v91 = (__int64)v82;
                    ucfg_reg_get_current_chan_list(*(_QWORD *)(v81 + 8), v82);
                    link_info_width = hdd_get_link_info_width((_DWORD *)v51);
                    bw_value = wlan_reg_get_bw_value(link_info_width);
                    v94 = 0;
                    v95 = 1;
                    v96 = v91;
                    do
                    {
                      if ( *(_DWORD *)(v96 + 8)
                        && *(_DWORD *)v96 == link_info_home_channel
                        && *(unsigned __int16 *)(v96 + 22) < (unsigned int)bw_value )
                      {
                        break;
                      }
                      v97 = v94++ >= 0x65;
                      v96 += 36;
                      v95 = !v97;
                    }
                    while ( v94 != 102 );
                    _qdf_mem_free(v91);
                  }
                  else
                  {
                    v95 = 0;
                  }
                  if ( (hdd_is_vdev_in_conn_state((_QWORD *)v51, v83, v84, v85, v86, v87, v88, v89, v90) & 1) != 0 )
                  {
                    if ( *(_DWORD *)(v51 + 80) == max_phymode
                      || (v106 = *(_QWORD *)a1, *(_DWORD *)(v51 + 80) = max_phymode, max_phymode == 7) )
                    {
                      v107 = 0;
                    }
                    else
                    {
                      v241 = 0;
                      peer_phymode = mlme_get_peer_phymode(v106, (_BYTE *)(v51 + 300), &v241);
                      v107 = 0;
                      if ( !peer_phymode )
                      {
                        if ( (unsigned int)(v241 - 1) > 0x1D )
                          v117 = 7;
                        else
                          v117 = dword_A07A38[v241 - 1];
                        v107 = v117 > max_phymode;
                      }
                    }
                    if ( v95 || v107 || is_disable_for_pwrmode )
                    {
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: changed: phy %d, freq %d, width %d",
                        v98,
                        v99,
                        v100,
                        v101,
                        v102,
                        v103,
                        v104,
                        v105,
                        "hdd_country_change_update_sta");
                      wlan_hdd_cm_issue_disconnect(v51, 1, 0);
                      hdd_set_vdev_phy_mode(v243[0], 0);
                      *(_DWORD *)(v51 + 80) = max_phymode;
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: Remain on current channel but update tx power",
                        v98,
                        v99,
                        v100,
                        v101,
                        v102,
                        v103,
                        v104,
                        v105,
                        "hdd_country_change_update_sta");
                      wlan_reg_update_tx_power_on_ctry_change(
                        v20,
                        *(unsigned __int8 *)(v51 + 8),
                        v108,
                        v109,
                        v110,
                        v111,
                        v112,
                        v113,
                        v114,
                        v115);
                    }
                  }
                  else
                  {
                    hdd_set_vdev_phy_mode(v243[0], 0);
                  }
                  v50 = v243[0];
                }
                if ( v50 )
                {
                  if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v51 - *(_DWORD *)v51 - 52832) >> 4))
                    || (*(_QWORD *)(v50 + 1640) & 1) == 0 )
                  {
                    break;
                  }
                  v51 = v50 + 52832;
                }
              }
              while ( v51 );
            }
          }
          hdd_adapter_dev_put_debug(v50, 0x37u, v42, v43, v44, v45, v46, v47, v48, v49);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v238 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v238 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a1 + 32);
          }
          else
          {
            raw_spin_lock_bh(a1 + 32);
            *(_QWORD *)(a1 + 40) |= 1uLL;
          }
          v243[0] = v242;
          hdd_get_next_adapter_no_lock(a1, v242, &v242);
          hdd_validate_next_adapter(v243, &v242, 0x37u, v52, v53, v54, v55, v56, v57, v58, v59);
          if ( v242 )
            hdd_adapter_dev_hold_debug(v242, 0x37u, v60, v61, v62, v63, v64, v65, v66, v67, v68);
          v69 = *(_QWORD *)(a1 + 40);
          if ( (v69 & 1) != 0 )
            break;
          raw_spin_unlock(a1 + 32);
          v50 = v243[0];
          if ( !v243[0] )
            goto LABEL_68;
        }
        *(_QWORD *)(a1 + 40) = v69 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 32);
        v50 = v243[0];
      }
      while ( v243[0] );
LABEL_68:
      sme_generic_change_country_code(*(_QWORD *)(a1 + 16), a1 + 618);
      qdf_event_set_all(a1 + 6928, v118);
      qdf_mutex_acquire(a1 + 6968);
      *(_BYTE *)(a1 + 6924) = 0;
      qdf_mutex_release(a1 + 6968);
      v119 = *(_QWORD *)(a1 + 8);
      v243[0] = 0;
      v242 = 0;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v120 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v120 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v120 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 32);
      }
      else
      {
        raw_spin_lock_bh(a1 + 32);
        *(_QWORD *)(a1 + 40) |= 1uLL;
      }
      hdd_get_front_adapter_no_lock(a1, v243);
      if ( v243[0] )
      {
        hdd_adapter_dev_hold_debug(v243[0], 0x38u, v121, v122, v123, v124, v125, v126, v127, v128, v129);
        v130 = v243[0];
      }
      else
      {
        v130 = 0;
      }
      hdd_get_next_adapter_no_lock(a1, v130, &v242);
      if ( v242 )
        hdd_adapter_dev_hold_debug(v242, 0x38u, v131, v132, v133, v134, v135, v136, v137, v138, v139);
      v140 = *(_QWORD *)(a1 + 40);
      if ( (v140 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 40) = v140 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 32);
        v149 = v243[0];
        if ( v243[0] )
        {
LABEL_79:
          v150 = "%s: AP is not started yet";
          v151 = "hdd_country_change_update_sap";
          v152 = "%s: Update tx power due to ctry change";
          v239 = _ReadStatusReg(SP_EL0);
          while ( 1 )
          {
            if ( (*(_QWORD *)(v149 + 1640) & 1) != 0 )
            {
              v153 = v149 + 52832;
              if ( v149 != -52832 )
                break;
            }
LABEL_82:
            hdd_adapter_dev_put_debug(v149, 0x38u, v141, v142, v143, v144, v145, v146, v147, v148);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v239 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v239 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(a1 + 32);
            }
            else
            {
              raw_spin_lock_bh(a1 + 32);
              *(_QWORD *)(a1 + 40) |= 1uLL;
            }
            v243[0] = v242;
            hdd_get_next_adapter_no_lock(a1, v242, &v242);
            hdd_validate_next_adapter(v243, &v242, 0x38u, v154, v155, v156, v157, v158, v159, v160, v161);
            if ( v242 )
              hdd_adapter_dev_hold_debug(v242, 0x38u, v162, v163, v164, v165, v166, v167, v168, v169, v170);
            v171 = *(_QWORD *)(a1 + 40);
            if ( (v171 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 40) = v171 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 32);
              v149 = v243[0];
              if ( !v243[0] )
                goto LABEL_121;
            }
            else
            {
              raw_spin_unlock(a1 + 32);
              v149 = v243[0];
              if ( !v243[0] )
                goto LABEL_121;
            }
          }
          while ( 1 )
          {
            v172 = hdd_get_link_info_home_channel((_DWORD *)v153);
            v149 = v243[0];
            v173 = *(_DWORD *)(v243[0] + 40);
            if ( v173 == 1 )
            {
              if ( (*(_QWORD *)(v153 + 4416) & 4) != 0 )
              {
                v174 = v172;
                v175 = csr_convert_to_reg_phy_mode(*(unsigned int *)(v153 + 316), v172);
                v184 = wlan_reg_get_max_phymode(v119, v176, v174, v175, v177, v178, v179, v180, v181, v182, v183);
                v185 = csr_convert_from_reg_phy_mode(v184);
                if ( v185 == *(_DWORD *)(v153 + 320) )
                {
                  policy_mgr_check_sap_restart(
                    *(_QWORD *)a1,
                    *(unsigned __int8 *)(v153 + 8),
                    v186,
                    v187,
                    v188,
                    v189,
                    v190,
                    v191,
                    v192,
                    v193);
LABEL_107:
                  qdf_trace_msg(0x33u, 8u, v152, v194, v195, v196, v197, v198, v199, v200, v201, v151, v239);
                  wlan_reg_update_tx_power_on_ctry_change(
                    v119,
                    *(unsigned __int8 *)(v153 + 8),
                    v219,
                    v220,
                    v221,
                    v222,
                    v223,
                    v224,
                    v225,
                    v226);
                  goto LABEL_108;
                }
                v202 = v152;
                v203 = v119;
                v204 = v151;
                v205 = v150;
                v206 = v185;
                v207 = *(_QWORD *)(*(_QWORD *)v153 + 24LL);
                v208 = *(_QWORD *)(v153 + 272);
                mutex_lock(v207 + 192);
                if ( (*(_QWORD *)(v153 + 4416) & 2) == 0 )
                {
                  v217 = *(_DWORD *)(v153 + 320);
                  *(_DWORD *)(v153 + 320) = v206;
                  v218 = "%s: Can't restart AP because it is not started";
                  *(_DWORD *)(v153 + 316) = v217;
                  goto LABEL_105;
                }
                qdf_event_reset(v153 + 128);
                if ( (unsigned int)wlansap_stop_bss(v208) )
                {
                  v218 = "%s: SAP Stop Bss fail";
                  goto LABEL_105;
                }
                if ( (unsigned int)qdf_wait_single_event(v153 + 128, 0x4650u) )
                {
                  v218 = "%s: SAP Stop timeout";
LABEL_105:
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    v218,
                    v209,
                    v210,
                    v211,
                    v212,
                    v213,
                    v214,
                    v215,
                    v216,
                    "hdd_restart_sap_with_new_phymode",
                    v239,
                    v240);
                  mutex_unlock(v207 + 192);
                }
                else
                {
                  safe_channel_from_pcl_and_acs_range = wlansap_get_safe_channel_from_pcl_and_acs_range(v208, 0);
                  v228 = *(_DWORD *)(v153 + 320);
                  *(_DWORD *)(v153 + 720) = safe_channel_from_pcl_and_acs_range;
                  *(_DWORD *)(v153 + 320) = v206;
                  *(_DWORD *)(v153 + 316) = v228;
                  qdf_event_reset(v153 + 88);
                  if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64 (__fastcall *)(__int64, int *, double, double, double, double, double, double, double, double), __int64))wlansap_start_bss)(
                                        v208,
                                        hdd_hostapd_sap_event_cb,
                                        v153 + 280) )
                  {
                    v237 = qdf_wait_single_event(v153 + 88, 0x32C8u);
                    mutex_unlock(v207 + 192);
                    v150 = v205;
                    v151 = v204;
                    v119 = v203;
                    v152 = v202;
                    if ( v237 )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: SAP Start timeout",
                        v194,
                        v195,
                        v196,
                        v197,
                        v198,
                        v199,
                        v200,
                        v201,
                        "hdd_restart_sap_with_new_phymode");
                    goto LABEL_107;
                  }
                  mutex_unlock(v207 + 192);
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: SAP Start Bss fail",
                    v229,
                    v230,
                    v231,
                    v232,
                    v233,
                    v234,
                    v235,
                    v236,
                    "hdd_restart_sap_with_new_phymode");
                }
                v150 = v205;
                v151 = v204;
                v119 = v203;
                v152 = v202;
                goto LABEL_107;
              }
              qdf_trace_msg(0x33u, 4u, v150, v141, v142, v143, v144, v145, v146, v147, v148, v151);
            }
            else
            {
              if ( v173 != 3 )
                goto LABEL_109;
              policy_mgr_check_sap_restart(
                *(_QWORD *)a1,
                *(unsigned __int8 *)(v153 + 8),
                v141,
                v142,
                v143,
                v144,
                v145,
                v146,
                v147,
                v148);
            }
LABEL_108:
            v149 = v243[0];
LABEL_109:
            if ( v149 )
            {
              if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v153 - *(_DWORD *)v153 - 52832) >> 4))
                || (*(_QWORD *)(v149 + 1640) & 1) == 0 )
              {
                goto LABEL_82;
              }
              v153 = v149 + 52832;
            }
            if ( !v153 )
              goto LABEL_82;
          }
        }
      }
      else
      {
        raw_spin_unlock(a1 + 32);
        v149 = v243[0];
        if ( v243[0] )
          goto LABEL_79;
      }
LABEL_121:
      result = _osif_psoc_sync_op_stop(v240, "hdd_country_change_work_handle");
      goto LABEL_4;
    }
  }
  result = hdd_handle_country_change_work_error(a1, v10);
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
