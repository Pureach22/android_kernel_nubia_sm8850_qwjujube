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
  __int64 v81; // x22
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
  _BOOL4 v95; // w22
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
  int v108; // w0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  __int64 v117; // x8
  __int64 v118; // x9
  __int64 v119; // x10
  int peer_phymode; // w0
  unsigned int v121; // w8
  __int64 v122; // x1
  __int64 v123; // x20
  unsigned __int64 v124; // x8
  unsigned int *v125; // x8
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  __int64 v134; // x1
  unsigned int *v135; // x8
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  __int64 v144; // x8
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  __int64 v153; // x8
  const char *v154; // x24
  const char *v155; // x23
  __int64 v156; // x26
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  unsigned int *v165; // x8
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  __int64 v174; // x8
  unsigned int v175; // w0
  int v176; // w9
  unsigned int v177; // w27
  double v178; // d0
  unsigned int v179; // w0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  __int64 v187; // x0
  int v188; // w0
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  const char *v205; // x25
  const char *v206; // x23
  __int64 v207; // x24
  int v208; // w28
  __int64 v209; // x27
  __int64 v210; // x20
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  int v219; // w8
  const char *v220; // x2
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  __int64 v229; // x9
  __int64 v230; // x10
  __int64 v231; // x11
  int safe_channel_from_pcl_and_acs_range; // w0
  int v233; // w8
  double v234; // d0
  double v235; // d1
  double v236; // d2
  double v237; // d3
  double v238; // d4
  double v239; // d5
  double v240; // d6
  double v241; // d7
  int v242; // w27
  unsigned __int64 v243; // [xsp+0h] [xbp-30h]
  unsigned __int64 v244; // [xsp+0h] [xbp-30h]
  __int64 v245; // [xsp+8h] [xbp-28h] BYREF
  int v246; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v247; // [xsp+18h] [xbp-18h] BYREF
  __int64 v248[2]; // [xsp+20h] [xbp-10h] BYREF

  v248[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v245 = 0;
  v10 = _wlan_hdd_validate_context(a1, (__int64)"hdd_country_change_work_handle", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !v10 )
  {
    v10 = _osif_psoc_sync_op_start(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 488LL), &v245, "hdd_country_change_work_handle");
    if ( !v10 )
    {
      if ( *(_DWORD *)(a1 + 1464) == 1 )
      {
        v20 = *(_QWORD *)(a1 + 8);
        v248[0] = 0;
        v247 = 0;
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
        hdd_get_front_adapter_no_lock(a1, v248);
        if ( v248[0] )
        {
          hdd_adapter_dev_hold_debug(v248[0], 0x37u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
          v31 = v248[0];
        }
        else
        {
          v31 = 0;
        }
        hdd_get_next_adapter_no_lock(a1, v31, &v247);
        if ( v247 )
          hdd_adapter_dev_hold_debug(v247, 0x37u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
        v41 = *(_QWORD *)(a1 + 40);
        if ( (v41 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 40) = v41 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 32);
        }
        else
        {
          raw_spin_unlock(a1 + 32);
        }
        v50 = v248[0];
        if ( v248[0] )
        {
          v243 = _ReadStatusReg(SP_EL0);
          do
          {
            while ( 1 )
            {
              if ( (*(_QWORD *)(v50 + 1640) & 1) != 0 && (v51 = v50 + 52840, v50 != -52840)
                || (v51 = v50 + 58928, v50 != -58928) && (*(_QWORD *)(v50 + 1640) & 2) != 0
                || (v51 = v50 + 65016, v50 != -65016) && (*(_QWORD *)(v50 + 1640) & 4) != 0 )
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
                  v50 = v248[0];
                  if ( (*(_DWORD *)(v248[0] + 40) | 2) == 2 )
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
                                    8u,
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
                        || (v106 = *(_QWORD *)a1, *(_DWORD *)(v51 + 80) = max_phymode, max_phymode == 8) )
                      {
                        v107 = 0;
                      }
                      else
                      {
                        v246 = 0;
                        peer_phymode = mlme_get_peer_phymode(v106, (_BYTE *)(v51 + 308), &v246);
                        v107 = 0;
                        if ( !peer_phymode )
                        {
                          if ( (unsigned int)(v246 - 1) > 0x27 )
                            v121 = 8;
                          else
                            v121 = dword_AF9A98[v246 - 1];
                          v107 = v121 > max_phymode;
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
                        v108 = mlo_mgr_link_switch_defer_disconnect_req(*(_QWORD *)(v51 + 32), 5, 1);
                        if ( v108 && v108 != 6 )
                          wlan_hdd_cm_issue_disconnect(v51, 1, 0);
                        hdd_set_vdev_phy_mode(v248[0], 0);
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
                          v109,
                          v110,
                          v111,
                          v112,
                          v113,
                          v114,
                          v115,
                          v116);
                      }
                    }
                    else
                    {
                      hdd_set_vdev_phy_mode(v248[0], 0);
                    }
                    v50 = v248[0];
                  }
                  if ( v50 )
                  {
                    if ( (unsigned __int8)(73 * ((unsigned int)(v51 - *(_DWORD *)v51 - 52840) >> 3) + 1) > 2u )
                      break;
                    v117 = (unsigned __int8)(73 * ((unsigned int)(v51 - *(_DWORD *)v51 - 52840) >> 3) + 1);
                    v51 = 0;
                    v118 = v50 + 6088LL * (unsigned int)v117 + 52840;
                    do
                    {
                      if ( v51 )
                        break;
                      v119 = *(_QWORD *)(v50 + 1640) >> v117++;
                      v51 = (v119 << 63 >> 63) & v118;
                      v118 += 6088;
                    }
                    while ( v117 != 3 );
                  }
                }
                while ( v51 );
              }
              hdd_adapter_dev_put_debug(v50, 0x37u, v42, v43, v44, v45, v46, v47, v48, v49);
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v243 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v243 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(a1 + 32);
              }
              else
              {
                raw_spin_lock_bh(a1 + 32);
                *(_QWORD *)(a1 + 40) |= 1uLL;
              }
              v248[0] = v247;
              hdd_get_next_adapter_no_lock(a1, v247, &v247);
              hdd_validate_next_adapter(v248, &v247, 0x37u, v52, v53, v54, v55, v56, v57, v58, v59);
              if ( v247 )
                hdd_adapter_dev_hold_debug(v247, 0x37u, v60, v61, v62, v63, v64, v65, v66, v67, v68);
              v69 = *(_QWORD *)(a1 + 40);
              if ( (v69 & 1) != 0 )
                break;
              raw_spin_unlock(a1 + 32);
              v50 = v248[0];
              if ( !v248[0] )
                goto LABEL_77;
            }
            *(_QWORD *)(a1 + 40) = v69 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 32);
            v50 = v248[0];
          }
          while ( v248[0] );
        }
LABEL_77:
        sme_generic_change_country_code(*(_QWORD *)(a1 + 16), a1 + 618);
        qdf_event_set_all(a1 + 6952, v122);
        qdf_mutex_acquire(a1 + 6992);
        *(_BYTE *)(a1 + 6948) = 0;
        qdf_mutex_release(a1 + 6992);
        v123 = *(_QWORD *)(a1 + 8);
        v248[0] = 0;
        v247 = 0;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v124 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v124 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v124 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 32);
        }
        else
        {
          raw_spin_lock_bh(a1 + 32);
          *(_QWORD *)(a1 + 40) |= 1uLL;
        }
        hdd_get_front_adapter_no_lock(a1, v248);
        if ( v248[0] )
        {
          hdd_adapter_dev_hold_debug(v248[0], 0x38u, v125, v126, v127, v128, v129, v130, v131, v132, v133);
          v134 = v248[0];
        }
        else
        {
          v134 = 0;
        }
        hdd_get_next_adapter_no_lock(a1, v134, &v247);
        if ( v247 )
          hdd_adapter_dev_hold_debug(v247, 0x38u, v135, v136, v137, v138, v139, v140, v141, v142, v143);
        v144 = *(_QWORD *)(a1 + 40);
        if ( (v144 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 40) = v144 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 32);
          v153 = v248[0];
          if ( v248[0] )
          {
LABEL_88:
            v154 = "%s: AP is not started yet";
            v155 = "hdd_country_change_update_sap";
            v244 = _ReadStatusReg(SP_EL0);
            while ( 1 )
            {
              if ( (*(_QWORD *)(v153 + 1640) & 1) != 0 )
              {
                v156 = v153 + 52840;
                if ( v153 != -52840 )
                  break;
              }
              v156 = v153 + 58928;
              if ( v153 != -58928 && (*(_QWORD *)(v153 + 1640) & 2) != 0 )
                break;
              v156 = v153 + 65016;
              if ( v153 != -65016 && (*(_QWORD *)(v153 + 1640) & 4) != 0 )
                break;
LABEL_95:
              hdd_adapter_dev_put_debug(v153, 0x38u, v145, v146, v147, v148, v149, v150, v151, v152);
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v244 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v244 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(a1 + 32);
              }
              else
              {
                raw_spin_lock_bh(a1 + 32);
                *(_QWORD *)(a1 + 40) |= 1uLL;
              }
              v248[0] = v247;
              hdd_get_next_adapter_no_lock(a1, v247, &v247);
              hdd_validate_next_adapter(v248, &v247, 0x38u, v157, v158, v159, v160, v161, v162, v163, v164);
              if ( v247 )
                hdd_adapter_dev_hold_debug(v247, 0x38u, v165, v166, v167, v168, v169, v170, v171, v172, v173);
              v174 = *(_QWORD *)(a1 + 40);
              if ( (v174 & 1) != 0 )
              {
                *(_QWORD *)(a1 + 40) = v174 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(a1 + 32);
                v153 = v248[0];
                if ( !v248[0] )
                  goto LABEL_137;
              }
              else
              {
                raw_spin_unlock(a1 + 32);
                v153 = v248[0];
                if ( !v248[0] )
                  goto LABEL_137;
              }
            }
            while ( 1 )
            {
              v175 = hdd_get_link_info_home_channel((_DWORD *)v156);
              v153 = v248[0];
              v176 = *(_DWORD *)(v248[0] + 40);
              if ( v176 == 1 )
              {
                if ( (*(_QWORD *)(v156 + 5968) & 4) != 0 )
                {
                  v177 = v175;
                  v178 = csr_convert_to_reg_phy_mode(*(unsigned int *)(v156 + 316), v175);
                  v187 = wlan_reg_get_max_phymode(v123, v179, v177, v178, v180, v181, v182, v183, v184, v185, v186);
                  v188 = csr_convert_from_reg_phy_mode(v187);
                  if ( v188 == *(_DWORD *)(v156 + 320) )
                  {
                    policy_mgr_check_sap_restart(
                      *(_QWORD *)a1,
                      *(unsigned __int8 *)(v156 + 8),
                      v189,
                      v190,
                      v191,
                      v192,
                      v193,
                      v194,
                      v195,
                      v196);
LABEL_120:
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Update tx power due to ctry change",
                      v197,
                      v198,
                      v199,
                      v200,
                      v201,
                      v202,
                      v203,
                      v204,
                      v155,
                      v244);
                    wlan_reg_update_tx_power_on_ctry_change(
                      v123,
                      *(unsigned __int8 *)(v156 + 8),
                      v221,
                      v222,
                      v223,
                      v224,
                      v225,
                      v226,
                      v227,
                      v228);
                    goto LABEL_121;
                  }
                  v205 = v155;
                  v206 = v154;
                  v207 = v123;
                  v208 = v188;
                  v209 = *(_QWORD *)(v156 + 272);
                  v210 = *(_QWORD *)(*(_QWORD *)v156 + 24LL);
                  mutex_lock(v210 + 192);
                  if ( (*(_QWORD *)(v156 + 5968) & 2) == 0 )
                  {
                    v219 = *(_DWORD *)(v156 + 320);
                    *(_DWORD *)(v156 + 320) = v208;
                    v220 = "%s: Can't restart AP because it is not started";
                    *(_DWORD *)(v156 + 316) = v219;
                    goto LABEL_118;
                  }
                  qdf_event_reset(v156 + 128);
                  if ( (unsigned int)wlansap_stop_bss(v209) )
                  {
                    v220 = "%s: SAP Stop Bss fail";
                    goto LABEL_118;
                  }
                  if ( (unsigned int)qdf_wait_single_event(v156 + 128, 0x4650u) )
                  {
                    v220 = "%s: SAP Stop timeout";
LABEL_118:
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      v220,
                      v211,
                      v212,
                      v213,
                      v214,
                      v215,
                      v216,
                      v217,
                      v218,
                      "hdd_restart_sap_with_new_phymode",
                      v244,
                      v245);
                    mutex_unlock(v210 + 192);
                  }
                  else
                  {
                    safe_channel_from_pcl_and_acs_range = wlansap_get_safe_channel_from_pcl_and_acs_range(v209, 0);
                    v233 = *(_DWORD *)(v156 + 320);
                    *(_DWORD *)(v156 + 720) = safe_channel_from_pcl_and_acs_range;
                    *(_DWORD *)(v156 + 320) = v208;
                    *(_DWORD *)(v156 + 316) = v233;
                    qdf_event_reset(v156 + 88);
                    if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64 (__fastcall *)(__int64, int *, double, double, double, double, double, double, double, double), __int64))wlansap_start_bss)(
                                          v209,
                                          hdd_hostapd_sap_event_cb,
                                          v156 + 280) )
                    {
                      v242 = qdf_wait_single_event(v156 + 88, 0x32C8u);
                      mutex_unlock(v210 + 192);
                      v123 = v207;
                      v154 = v206;
                      v155 = v205;
                      if ( v242 )
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: SAP Start timeout",
                          v197,
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          v203,
                          v204,
                          "hdd_restart_sap_with_new_phymode");
                      goto LABEL_120;
                    }
                    mutex_unlock(v210 + 192);
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: SAP Start Bss fail",
                      v234,
                      v235,
                      v236,
                      v237,
                      v238,
                      v239,
                      v240,
                      v241,
                      "hdd_restart_sap_with_new_phymode");
                  }
                  v123 = v207;
                  v154 = v206;
                  v155 = v205;
                  goto LABEL_120;
                }
                qdf_trace_msg(0x33u, 4u, v154, v145, v146, v147, v148, v149, v150, v151, v152, v155);
              }
              else
              {
                if ( v176 != 3 )
                  goto LABEL_122;
                policy_mgr_check_sap_restart(
                  *(_QWORD *)a1,
                  *(unsigned __int8 *)(v156 + 8),
                  v145,
                  v146,
                  v147,
                  v148,
                  v149,
                  v150,
                  v151,
                  v152);
              }
LABEL_121:
              v153 = v248[0];
LABEL_122:
              if ( v153 )
              {
                if ( (unsigned __int8)(73 * ((unsigned int)(v156 - *(_DWORD *)v156 - 52840) >> 3) + 1) > 2u )
                  goto LABEL_95;
                v229 = (unsigned __int8)(73 * ((unsigned int)(v156 - *(_DWORD *)v156 - 52840) >> 3) + 1);
                v156 = 0;
                v230 = v153 + 6088LL * (unsigned int)v229 + 52840;
                do
                {
                  if ( v156 )
                    break;
                  v231 = *(_QWORD *)(v153 + 1640) >> v229++;
                  v156 = (v231 << 63 >> 63) & v230;
                  v230 += 6088;
                }
                while ( v229 != 3 );
              }
              if ( !v156 )
                goto LABEL_95;
            }
          }
        }
        else
        {
          raw_spin_unlock(a1 + 32);
          v153 = v248[0];
          if ( v248[0] )
            goto LABEL_88;
        }
      }
      else
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
      }
LABEL_137:
      result = _osif_psoc_sync_op_stop(v245, "hdd_country_change_work_handle");
      goto LABEL_4;
    }
  }
  result = hdd_handle_country_change_work_error(a1, v10);
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
