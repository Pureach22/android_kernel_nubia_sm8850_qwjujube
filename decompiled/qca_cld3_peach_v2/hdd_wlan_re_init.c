__int64 hdd_wlan_re_init()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  _QWORD *context; // x0
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int64 StatusReg; // x8
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x1
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x0
  unsigned __int64 v73; // x23
  char is_interface_up; // w8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x0
  int v84; // w8
  __int64 v85; // x2
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int *v94; // x8
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x8
  unsigned int v104; // w0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  unsigned __int64 v121; // x8
  unsigned int *v122; // x8
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  __int64 v131; // x1
  unsigned int *v132; // x8
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x8
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  __int64 v150; // x0
  unsigned __int64 v151; // x21
  char v152; // w8
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  __int64 v161; // x0
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  unsigned int *v170; // x8
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  __int64 v179; // x8
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  unsigned __int64 v188; // x8
  unsigned int *v189; // x8
  double v190; // d0
  double v191; // d1
  double v192; // d2
  double v193; // d3
  double v194; // d4
  double v195; // d5
  double v196; // d6
  double v197; // d7
  _QWORD *v198; // x1
  unsigned int *v199; // x8
  double v200; // d0
  double v201; // d1
  double v202; // d2
  double v203; // d3
  double v204; // d4
  double v205; // d5
  double v206; // d6
  double v207; // d7
  __int64 v208; // x8
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  _QWORD *v217; // x0
  char v218; // w22
  __int64 v219; // x25
  int v220; // w21
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  char restarted; // w8
  __int64 v238; // x8
  __int64 v239; // x9
  __int64 v240; // x10
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  const void *mld_mac_addr_from_vdev; // x0
  char v250; // w8
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  unsigned int *v259; // x8
  double v260; // d0
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  __int64 v268; // x8
  unsigned __int64 v269; // [xsp+0h] [xbp-30h]
  _BYTE v270[4]; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD *v271; // [xsp+10h] [xbp-20h] BYREF
  _QWORD *v272; // [xsp+18h] [xbp-18h] BYREF
  __int64 v273[2]; // [xsp+20h] [xbp-10h] BYREF

  v273[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v270[0] = 0;
  hdd_prevent_suspend(1u);
  context = _cds_get_context(51, (__int64)"hdd_wlan_re_init", v0, v1, v2, v3, v4, v5, v6, v7);
  if ( !context )
    goto LABEL_6;
  v9 = (__int64)context;
  if ( !hdd_get_first_valid_adapter((__int64)context) )
    qdf_trace_msg(0x33u, 2u, "%s: Failed to get adapter", v10, v11, v12, v13, v14, v15, v16, v17, "hdd_wlan_re_init");
  if ( (unsigned int)hdd_wlan_start_modules((_QWORD *)v9, 1, v10, v11, v12, v13, v14, v15, v16, v17) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to start wlan after error",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_wlan_re_init");
    qdf_dp_trace_deinit();
LABEL_6:
    hdd_allow_suspend(1u);
    result = 0xFFFFFFFFLL;
    goto LABEL_7;
  }
  hdd_update_hw_sw_info((_DWORD *)v9, v18, v19, v20, v21, v22, v23, v24, v25);
  wlan_hdd_send_svc_nlink_msg(*(_DWORD *)(v9 + 1456), 0x100u, nullptr, 0);
  hdd_start_all_adapters((__int64 *)v9, v27, v28, v29, v30, v31, v32, v33, v34);
  hdd_init_scan_reject_params(v9);
  *(_BYTE *)(v9 + 913) = 0;
  hdd_allow_suspend(1u);
  sme_set_chip_pwr_save_fail_cb(*(_QWORD *)(v9 + 16), hdd_chip_pwr_save_fail_detected_cb);
  hdd_restore_thermal_mitigation_config(v9);
  hdd_restore_ddr_bw_mitigation_config(v9);
  if ( *(_QWORD *)(v9 + 3872) && (unsigned int)sme_set_sar_power_limits(*(_QWORD *)(v9 + 16)) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to configured SAR after SSR",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "hdd_restore_sar_config");
  v273[0] = 0;
  v272 = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v9 + 32);
  }
  else
  {
    raw_spin_lock_bh(v9 + 32);
    *(_QWORD *)(v9 + 40) |= 1uLL;
  }
  hdd_get_front_adapter_no_lock(v9, v273);
  if ( v273[0] )
  {
    hdd_adapter_dev_hold_debug(v273[0], 0x35u, v44, v45, v46, v47, v48, v49, v50, v51, v52);
    v53 = v273[0];
  }
  else
  {
    v53 = 0;
  }
  hdd_get_next_adapter_no_lock(v9, v53, &v272);
  if ( v272 )
    hdd_adapter_dev_hold_debug((__int64)v272, 0x35u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
  v63 = *(_QWORD *)(v9 + 40);
  if ( (v63 & 1) != 0 )
  {
    *(_QWORD *)(v9 + 40) = v63 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v9 + 32);
  }
  else
  {
    raw_spin_unlock(v9 + 32);
  }
  v72 = v273[0];
  if ( v273[0] )
  {
    v73 = _ReadStatusReg(SP_EL0);
    do
    {
      while ( 1 )
      {
        is_interface_up = hdd_is_interface_up(v72);
        v83 = v273[0];
        if ( (is_interface_up & 1) != 0 )
        {
          v84 = *(_DWORD *)(v273[0] + 40);
          if ( v84 == 7 || !v84 )
          {
            v85 = *(_QWORD *)(v273[0] + 41680);
            if ( v85 )
            {
              sme_set_default_scan_ie(
                *(_QWORD *)(v9 + 16),
                *(unsigned __int8 *)(*(_QWORD *)(v273[0] + 52832) + 8LL),
                v85,
                *(unsigned __int16 *)(v273[0] + 41688));
              v83 = v273[0];
            }
          }
        }
        hdd_adapter_dev_put_debug(v83, 0x35u, v75, v76, v77, v78, v79, v80, v81, v82);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v73 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v73 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v9 + 32);
        }
        else
        {
          raw_spin_lock_bh(v9 + 32);
          *(_QWORD *)(v9 + 40) |= 1uLL;
        }
        v273[0] = (__int64)v272;
        hdd_get_next_adapter_no_lock(v9, (__int64)v272, &v272);
        hdd_validate_next_adapter(v273, &v272, 0x35u, v86, v87, v88, v89, v90, v91, v92, v93);
        if ( v272 )
          hdd_adapter_dev_hold_debug((__int64)v272, 0x35u, v94, v95, v96, v97, v98, v99, v100, v101, v102);
        v103 = *(_QWORD *)(v9 + 40);
        if ( (v103 & 1) != 0 )
          break;
        raw_spin_unlock(v9 + 32);
        v72 = v273[0];
        if ( !v273[0] )
          goto LABEL_41;
      }
      *(_QWORD *)(v9 + 40) = v103 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v9 + 32);
      v72 = v273[0];
    }
    while ( v273[0] );
  }
LABEL_41:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Restore dual sta config: Primary vdev_id:%d, sta policy:%d",
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    "hdd_restore_dual_sta_config",
    *(unsigned __int8 *)(v9 + 7119),
    *(unsigned __int8 *)(v9 + 7118));
  v104 = wlan_mlme_set_primary_interface(*(_QWORD *)v9, *(_BYTE *)(v9 + 7119));
  if ( v104 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not set primary interface, %d",
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      "hdd_restore_dual_sta_config",
      v104);
  if ( (unsigned int)wlan_mlme_set_dual_sta_policy(*(_QWORD *)v9, *(_BYTE *)(v9 + 7118)) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to set mlme dual sta config",
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      "hdd_restore_dual_sta_config");
  v273[0] = 0;
  v272 = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v121 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v121 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v121 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v9 + 32);
  }
  else
  {
    raw_spin_lock_bh(v9 + 32);
    *(_QWORD *)(v9 + 40) |= 1uLL;
  }
  hdd_get_front_adapter_no_lock(v9, v273);
  if ( v273[0] )
  {
    hdd_adapter_dev_hold_debug(v273[0], 0x19u, v122, v123, v124, v125, v126, v127, v128, v129, v130);
    v131 = v273[0];
  }
  else
  {
    v131 = 0;
  }
  hdd_get_next_adapter_no_lock(v9, v131, &v272);
  if ( v272 )
    hdd_adapter_dev_hold_debug((__int64)v272, 0x19u, v132, v133, v134, v135, v136, v137, v138, v139, v140);
  v141 = *(_QWORD *)(v9 + 40);
  if ( (v141 & 1) != 0 )
  {
    *(_QWORD *)(v9 + 40) = v141 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v9 + 32);
    v150 = v273[0];
    if ( v273[0] )
    {
LABEL_56:
      v151 = _ReadStatusReg(SP_EL0);
      do
      {
        while ( 1 )
        {
          v152 = hdd_is_interface_up(v150);
          v161 = v273[0];
          if ( (v152 & 1) != 0 && *(_BYTE *)(v273[0] + 52825) == 1 )
          {
            hdd_send_dbam_config(v273[0], *(_DWORD *)(v9 + 8216));
            v161 = v273[0];
          }
          hdd_adapter_dev_put_debug(v161, 0x19u, v153, v154, v155, v156, v157, v158, v159, v160);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v151 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v151 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v9 + 32);
          }
          else
          {
            raw_spin_lock_bh(v9 + 32);
            *(_QWORD *)(v9 + 40) |= 1uLL;
          }
          v273[0] = (__int64)v272;
          hdd_get_next_adapter_no_lock(v9, (__int64)v272, &v272);
          hdd_validate_next_adapter(v273, &v272, 0x19u, v162, v163, v164, v165, v166, v167, v168, v169);
          if ( v272 )
            hdd_adapter_dev_hold_debug((__int64)v272, 0x19u, v170, v171, v172, v173, v174, v175, v176, v177, v178);
          v179 = *(_QWORD *)(v9 + 40);
          if ( (v179 & 1) != 0 )
            break;
          raw_spin_unlock(v9 + 32);
          v150 = v273[0];
          if ( !v273[0] )
            goto LABEL_74;
        }
        *(_QWORD *)(v9 + 40) = v179 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v9 + 32);
        v150 = v273[0];
      }
      while ( v273[0] );
    }
  }
  else
  {
    raw_spin_unlock(v9 + 32);
    v150 = v273[0];
    if ( v273[0] )
      goto LABEL_56;
  }
LABEL_74:
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: WLAN host driver reinitiation completed!",
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    "hdd_wlan_re_init");
  wlan_mlme_get_sap_internal_restart(*(_QWORD *)v9, v270);
  if ( v270[0] != 1 )
    goto LABEL_135;
  v271 = nullptr;
  v272 = nullptr;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v180, v181, v182, v183, v184, v185, v186, v187, "hdd_ssr_restart_sap");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v188 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v188 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v188 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v9 + 32);
  }
  else
  {
    raw_spin_lock_bh(v9 + 32);
    *(_QWORD *)(v9 + 40) |= 1uLL;
  }
  hdd_get_front_adapter_no_lock(v9, &v272);
  if ( v272 )
  {
    hdd_adapter_dev_hold_debug((__int64)v272, 0x34u, v189, v190, v191, v192, v193, v194, v195, v196, v197);
    v198 = v272;
  }
  else
  {
    v198 = nullptr;
  }
  hdd_get_next_adapter_no_lock(v9, (__int64)v198, &v271);
  if ( v271 )
    hdd_adapter_dev_hold_debug((__int64)v271, 0x34u, v199, v200, v201, v202, v203, v204, v205, v206, v207);
  v208 = *(_QWORD *)(v9 + 40);
  if ( (v208 & 1) != 0 )
  {
    *(_QWORD *)(v9 + 40) = v208 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v9 + 32);
    v217 = v272;
    if ( !v272 )
      goto LABEL_134;
  }
  else
  {
    raw_spin_unlock(v9 + 32);
    v217 = v272;
    if ( !v272 )
      goto LABEL_134;
  }
  v218 = 0;
  v269 = _ReadStatusReg(SP_EL0);
  do
  {
LABEL_87:
    if ( *((_DWORD *)v217 + 10) != 1 )
      goto LABEL_121;
    do
    {
      if ( (v217[205] & 1) != 0 )
      {
        v219 = (__int64)(v217 + 6605);
      }
      else
      {
        v219 = (__int64)(v217 + 7366);
        if ( v217 == (_QWORD *)-58928LL || (v217[205] & 2) == 0 )
        {
          v219 = (__int64)(v217 + 8127);
          if ( v217 == (_QWORD *)-65016LL || (v217[205] & 4) == 0 )
            goto LABEL_121;
        }
      }
      v220 = 0;
      while ( (*(_QWORD *)(v219 + 5968) & 4) == 0 || (*(_QWORD *)(v219 + 5968) & 2) != 0 )
      {
LABEL_105:
        if ( v217 )
          goto LABEL_106;
LABEL_96:
        if ( !v219 )
          goto LABEL_117;
      }
      if ( (v218 & 1) == 0 )
      {
        LOBYTE(v273[0]) = 0;
        if ( (unsigned int)ucfg_mlme_get_dfs_ignore_cac(*(_QWORD *)v9, v273) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: can't get ignore cac flag",
            v221,
            v222,
            v223,
            v224,
            v225,
            v226,
            v227,
            v228,
            "hdd_restore_ignore_cac");
        wlansap_set_dfs_ignore_cac(*(_QWORD *)(v9 + 16), LOBYTE(v273[0]));
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: ignore_cac=%d",
          v229,
          v230,
          v231,
          v232,
          v233,
          v234,
          v235,
          v236,
          "hdd_restore_ignore_cac",
          LOBYTE(v273[0]));
      }
      restarted = hdd_ssr_restart_sap_cac_link();
      v217 = v272;
      if ( (restarted & 1) != 0 )
      {
        v218 = 1;
        v220 = 1;
        goto LABEL_105;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Restart prev SAP session(vdev %d), event_flags 0x%lx, link_flags 0x%lx(%s)",
        v209,
        v210,
        v211,
        v212,
        v213,
        v214,
        v215,
        v216,
        "hdd_ssr_restart_sap",
        *(unsigned __int8 *)(v219 + 8),
        v272[203],
        *(_QWORD *)(v219 + 5968),
        v272[4] + 296LL);
      wlan_hdd_configure_twt_responder(
        (__int64 *)v9,
        *(_BYTE *)(v272[6604] + 2148LL),
        *(unsigned __int8 *)(v272[6604] + 8LL));
      wlan_hdd_start_sap((_QWORD *)v219, v241, v242, v243, v244, v245, v246, v247, v248);
      v273[0] = 0;
      if ( *(_DWORD *)(v219 + 2644) )
      {
        mld_mac_addr_from_vdev = (const void *)hdd_get_mld_mac_addr_from_vdev(
                                                 *(_QWORD *)(v219 + 32),
                                                 v209,
                                                 v210,
                                                 v211,
                                                 v212,
                                                 v213,
                                                 v214,
                                                 v215,
                                                 v216);
        if ( mld_mac_addr_from_vdev )
          qdf_mem_copy((char *)v273 + 2, mld_mac_addr_from_vdev, 4u);
        v250 = *(_BYTE *)(v219 + 8);
        BYTE1(v273[0]) = 1;
        LOBYTE(v273[0]) = v250;
        wlan_mlme_set_sap_suspend_resume(*(_QWORD *)v9, (unsigned __int8 *)v273);
        *(_DWORD *)(*(_QWORD *)(v219 + 32) + 1416LL) = 1;
      }
      v217 = v272;
      v218 = 1;
      if ( !v272 )
        goto LABEL_96;
LABEL_106:
      if ( (unsigned __int8)(73 * ((unsigned int)(v219 - *(_DWORD *)v219 - 52840) >> 3) + 1) < 3u )
      {
        v238 = (unsigned __int8)(73 * ((unsigned int)(v219 - *(_DWORD *)v219 - 52840) >> 3) + 1);
        v219 = 0;
        v239 = (__int64)&v217[761 * (unsigned int)v238 + 6605];
        do
        {
          if ( v219 )
            break;
          v240 = v217[205] >> v238++;
          v219 = (v240 << 63 >> 63) & v239;
          v239 += 6088;
        }
        while ( v238 != 3 );
        goto LABEL_96;
      }
LABEL_117:
      ;
    }
    while ( v217 && ((v220 ^ 1) & 1) == 0 );
    if ( (v220 & 1) != 0 )
      v217 = nullptr;
LABEL_121:
    hdd_adapter_dev_put_debug((__int64)v217, 0x34u, v209, v210, v211, v212, v213, v214, v215, v216);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v269 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v269 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v9 + 32);
    }
    else
    {
      raw_spin_lock_bh(v9 + 32);
      *(_QWORD *)(v9 + 40) |= 1uLL;
    }
    v272 = v271;
    hdd_get_next_adapter_no_lock(v9, (__int64)v271, &v271);
    hdd_validate_next_adapter((__int64 *)&v272, &v271, 0x34u, v251, v252, v253, v254, v255, v256, v257, v258);
    if ( v271 )
      hdd_adapter_dev_hold_debug((__int64)v271, 0x34u, v259, v260, v261, v262, v263, v264, v265, v266, v267);
    v268 = *(_QWORD *)(v9 + 40);
    if ( (v268 & 1) == 0 )
    {
      raw_spin_unlock(v9 + 32);
      v217 = v272;
      if ( !v272 )
        break;
      goto LABEL_87;
    }
    *(_QWORD *)(v9 + 40) = v268 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v9 + 32);
    v217 = v272;
  }
  while ( v272 );
LABEL_134:
  qdf_trace_msg(0x33u, 8u, "%s: exit", v209, v210, v211, v212, v213, v214, v215, v216, "hdd_ssr_restart_sap", v269);
LABEL_135:
  hdd_tx_powerboost_reinit(v9);
  LODWORD(v273[0]) = 0;
  qdf_mem_set(v273, 4u, 0);
  LODWORD(v273[0]) = 0;
  host_diag_event_report_payload(2876, 4, v273);
  if ( *(_BYTE *)(v9 + 488) == 1 )
    *(_BYTE *)(v9 + 488) = 0;
  result = 0;
  if ( *(_BYTE *)(v9 + 185) == 1 )
    *(_BYTE *)(v9 + 185) = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
