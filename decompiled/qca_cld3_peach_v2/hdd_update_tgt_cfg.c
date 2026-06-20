__int64 __fastcall hdd_update_tgt_cfg(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w20
  unsigned int v31; // w0
  double updated; // d0
  __int64 v33; // x21
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _QWORD *context; // x0
  double v42; // d0
  unsigned int v43; // w22
  __int64 v44; // x23
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w21
  const char *v62; // x2
  __int64 v63; // x4
  unsigned int v64; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  const char *v73; // x2
  unsigned int band_capability; // w0
  unsigned int band; // w0
  int v76; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w10
  __int64 v86; // x9
  unsigned int v87; // w1
  char v88; // w8
  unsigned int v89; // w0
  char v90; // w8
  __int64 v91; // x9
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // w4
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // x0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  unsigned int v142; // w8
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  char v167; // w8
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  __int64 v176; // x0
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  __int64 v185; // x4
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  int v194; // w1
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v203; // x0
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  __int64 v212; // x0
  __int64 v213; // x1
  __int64 v214; // x0
  char v215; // w1
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  __int64 v240; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int8 v241[4]; // [xsp+8h] [xbp-18h] BYREF
  char v242[4]; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v243; // [xsp+10h] [xbp-10h] BYREF
  int v244; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v245; // [xsp+18h] [xbp-8h]

  v245 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v244 = 0;
  v243 = 0;
  v242[0] = 0;
  v241[0] = 0;
  HIDWORD(v240) = 0;
  LOBYTE(v240) = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: HDD context is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_update_tgt_cfg");
    result = 4294967274LL;
    goto LABEL_20;
  }
  if ( (unsigned int)hdd_objmgr_create_and_store_pdev() )
  {
    result = 4294967274LL;
    goto LABEL_20;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: New pdev has been created with pdev_id = %u",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "hdd_update_tgt_cfg",
    *(unsigned __int8 *)(a1[1] + 40));
  v21 = dispatcher_pdev_open(a1[1]);
  if ( v21 )
  {
    v30 = qdf_status_to_os_return(v21);
LABEL_19:
    hdd_objmgr_release_and_destroy_pdev(a1);
    result = v30;
    goto LABEL_20;
  }
  v31 = ucfg_mlme_pdev_open(a1[1], v22, v23, v24, v25, v26, v27, v28, v29);
  if ( v31 )
  {
    v30 = qdf_status_to_os_return(v31);
    dispatcher_pdev_close(a1[1]);
LABEL_18:
    ucfg_mlme_pdev_close();
    goto LABEL_19;
  }
  ucfg_mlme_cfg_chan_to_freq(a1[1]);
  updated = hdd_objmgr_update_tgt_max_vdev_psoc(a1, *(unsigned __int8 *)(a2 + 164));
  v33 = *a1;
  context = _cds_get_context(71, (__int64)"hdd_update_tgt_cfg", updated, v34, v35, v36, v37, v38, v39, v40);
  v42 = ucfg_ipa_set_dp_handle(v33, context);
  v43 = *(unsigned __int8 *)(a2 + 173);
  v44 = a1[13];
  v52 = cds_set_sub_20_support(*(_BYTE *)(a2 + 173), v42, v45, v46, v47, v48, v49, v50, v51);
  if ( v52 )
  {
    v61 = v52;
    v62 = "%s: Failed to set sub20MHz channel width support";
LABEL_16:
    qdf_trace_msg(0x33u, 2u, v62, v53, v54, v55, v56, v57, v58, v59, v60, "hdd_update_sub_20_config", v240);
    v73 = "%s: Failed to update sub20MHz channel width config";
LABEL_17:
    qdf_trace_msg(0x33u, 2u, v73, v65, v66, v67, v68, v69, v70, v71, v72, "hdd_update_tgt_cfg");
    v30 = qdf_status_to_os_return(v61);
    goto LABEL_18;
  }
  if ( v43 )
  {
    v63 = *(unsigned int *)(v44 + 208);
  }
  else
  {
    v63 = 0;
    *(_DWORD *)(v44 + 208) = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: sub20MHz channel width %u (fw support %u)",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "hdd_update_sub_20_config",
    v63,
    v43,
    v240);
  v64 = wlan_mlme_set_sub_20_chan_width(*a1, *(_DWORD *)(v44 + 208));
  if ( v64 )
  {
    v61 = v64;
    v62 = "%s: Failed to set sub20MHz channel width config";
    goto LABEL_16;
  }
  band_capability = wlan_mlme_get_band_capability(*a1, &v243);
  if ( band_capability )
  {
    v61 = band_capability;
    v73 = "%s: Failed to get MLME band capability";
    goto LABEL_17;
  }
  band = ucfg_reg_get_band(a1[1], &v244, v65, v66, v67, v68, v69, v70, v71, v72);
  if ( band )
  {
    v61 = band;
    v73 = "%s: Failed to get REG band capability";
    goto LABEL_17;
  }
  v243 &= v244;
  v76 = hdd_update_band_cap_from_dot11mode(a1);
  v85 = *(_DWORD *)(a2 + 8);
  *((_BYTE *)a1 + 3264) = *(_BYTE *)(a2 + 72);
  v86 = a1[13];
  v87 = v85 & v76;
  v88 = *(_BYTE *)(a2 + 74);
  v243 = v85;
  v244 = v85 & v76;
  *(_BYTE *)(v86 + 15) = v88;
  if ( (v85 & v76) != 0 )
  {
    v243 = v85 & v76;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: ini BandCapability not supported by the target",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "hdd_update_tgt_cfg");
    v87 = v243;
  }
  v89 = wlan_mlme_set_band_capability(*a1, v87);
  if ( v89 )
  {
    v61 = v89;
    v73 = "%s: Failed to set MLME Band Capability";
    goto LABEL_17;
  }
  v90 = v243;
  v91 = *a1;
  *((_DWORD *)a1 + 813) = v243;
  *(_BYTE *)(v91 + 45) = v90;
  if ( (unsigned int)wlan_hdd_update_wiphy_supported_band(a1) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to update wiphy band info",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      "hdd_update_tgt_cfg");
    v30 = 0;
    goto LABEL_18;
  }
  if ( (unsigned int)ucfg_reg_set_band(a1[1], v243, v92, v93, v94, v95, v96, v97, v98, v99) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to update regulatory band info",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "hdd_update_tgt_cfg");
  if ( (cds_get_driver_state(v100, v101, v102, v103, v104, v105, v106, v107) & 8) == 0
    || (cds_get_driver_state(v108, v109, v110, v111, v112, v113, v114, v115) & 0x10) != 0 )
  {
    *((_DWORD *)a1 + 152) = *(_DWORD *)(a2 + 12);
    *((_DWORD *)a1 + 153) = *(_DWORD *)(a2 + 16);
  }
  if ( !(unsigned int)_wlan_hdd_validate_mac_address(
                        a2 + 20,
                        (__int64)"hdd_update_tgt_cfg",
                        v108,
                        v109,
                        v110,
                        v111,
                        v112,
                        v113,
                        v114,
                        v115) )
    qdf_mem_copy((char *)a1 + 3753, (const void *)(a2 + 20), 6u);
  *((_DWORD *)a1 + 133) = *(_DWORD *)a2;
  *((_DWORD *)a1 + 134) = *(_DWORD *)(a2 + 4);
  hdd_extract_fw_version_info(a1);
  *((_DWORD *)a1 + 875) = *(_DWORD *)(a2 + 420);
  qdf_mem_copy(a1 + 438, (const void *)(a2 + 424), 0x14u);
  v124 = *(unsigned __int8 *)(a2 + 164);
  if ( v124 >= 7 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: fw max vdevs (%u) > host max vdevs (%u); using %u",
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      "hdd_update_tgt_cfg");
    LOBYTE(v124) = 6;
  }
  *((_BYTE *)a1 + 852) = v124;
  *((_DWORD *)a1 + 922) = *(_DWORD *)(a2 + 444);
  *((_DWORD *)a1 + 923) = *(_DWORD *)(a2 + 448);
  hdd_lpass_target_config(a1, a2);
  *((_BYTE *)a1 + 854) = *(_BYTE *)(a2 + 166);
  hdd_update_tgt_services(a1, a2 + 28);
  hdd_update_tgt_ht_cap(a1, a2 + 88);
  sme_update_bfer_caps_as_per_nss_chains(a1[2], a2);
  hdd_update_tgt_vht_cap(a1, a2 + 108);
  wlan_mlme_cfg_get_vht_tx_bfee_ant_supp(*a1, v241);
  if ( v241[0] >= 4u && (*(_BYTE *)(a2 + 413) & 1) == 0 )
  {
    v133 = *a1;
    v241[0] = 3;
    if ( (unsigned int)wlan_mlme_cfg_set_vht_tx_bfee_ant_supp(v133, 3) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: set tx_bfee_ant_supp failed",
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        "hdd_update_tgt_cfg");
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: txBFCsnValue %d 8ss %d",
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    "hdd_update_tgt_cfg",
    v241[0],
    *(unsigned __int8 *)(a2 + 413));
  if ( *(_BYTE *)(a2 + 70) == 1 )
  {
    v142 = *(_DWORD *)a1[13];
    if ( v142 <= 0xC && ((1 << v142) & 0x1801) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: 11AX: 11ax is enabled - update HDD config",
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        v141,
        "hdd_update_tgt_cfg");
      hdd_update_tgt_he_cap(a1, a2);
      hdd_update_wiphy_he_cap(a1);
    }
  }
  hdd_update_tgt_twt_cap(a1, a2);
  hdd_update_tgt_eht_cap(a1, a2);
  v143 = hdd_update_wiphy_eht_cap(a1);
  mlme_update_tgt_mlo_caps_in_cfg(*a1, v143, v144, v145, v146, v147, v148, v149, v150);
  wlan_mlme_update_dual_sap_sta_cap(*a1, v151, v152, v153, v154, v155, v156, v157, v158);
  sme_modify_nss_chains_tgt_cfg(a1[2], 0, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 1, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 2, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 3, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 7, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 8, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 15, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 5, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 16, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 11, 0);
  sme_modify_nss_chains_tgt_cfg(a1[2], 0, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 1, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 2, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 3, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 7, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 8, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 15, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 5, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 16, 1);
  sme_modify_nss_chains_tgt_cfg(a1[2], 11, 1);
  hdd_update_vdev_nss(a1);
  if ( (unsigned int)wlan_mlme_get_enable_dynamic_nss_chains_cfg(*a1, &v240) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to get enable dynamic config",
      v159,
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      "hdd_update_tgt_cfg");
    v167 = 0;
    *((_BYTE *)a1 + 3752) = 0;
  }
  else
  {
    *((_BYTE *)a1 + 3752) = v240 & *(_BYTE *)(a2 + 414);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Dynamic nss chain support FW %d driver %d",
      v159,
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      "hdd_update_tgt_cfg",
      *(unsigned __int8 *)(a2 + 414));
    v167 = *((_BYTE *)a1 + 3752);
  }
  if ( (unsigned int)wlan_mlme_cfg_set_dynamic_nss_chains_support(*a1, v167 & 1) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to set dynamic_nss_chains_support",
      v168,
      v169,
      v170,
      v171,
      v172,
      v173,
      v174,
      v175,
      "hdd_update_tgt_cfg");
  ucfg_mlme_get_fine_time_meas_cap(*a1, (int *)&v240 + 1);
  v176 = *a1;
  HIDWORD(v240) &= *(_DWORD *)(a2 + 168);
  if ( (unsigned int)ucfg_mlme_set_fine_time_meas_cap(v176, SHIDWORD(v240)) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to set fine_time_meas_cap, 0x%x, ox%x",
      v177,
      v178,
      v179,
      v180,
      v181,
      v182,
      v183,
      v184,
      "hdd_update_tgt_cfg",
      HIDWORD(v240),
      *(unsigned int *)(a2 + 168));
    ucfg_mlme_get_fine_time_meas_cap(*a1, (int *)&v240 + 1);
  }
  v185 = HIDWORD(v240);
  *((_DWORD *)a1 + 362) = *(_DWORD *)(a2 + 168);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: fine_time_meas_cap: 0x%x",
    v177,
    v178,
    v179,
    v180,
    v181,
    v182,
    v183,
    v184,
    "hdd_update_tgt_cfg",
    v185);
  if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*a1, v242) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to get vht_enable2x2",
      v186,
      v187,
      v188,
      v189,
      v190,
      v191,
      v192,
      v193,
      "hdd_update_tgt_cfg");
  if ( v242[0] )
    v194 = 2;
  else
    v194 = 1;
  hdd_update_smps_antenna_mode((__int64)a1, v194);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Init current antenna mode: %d",
    v195,
    v196,
    v197,
    v198,
    v199,
    v200,
    v201,
    v202,
    "hdd_update_tgt_cfg",
    *((unsigned int *)a1 + 363));
  v203 = *a1;
  *((_BYTE *)a1 + 1819) = *(_BYTE *)(a2 + 415);
  if ( (unsigned int)ucfg_mlme_set_restricted_80p80_bw_supp(v203, *(_BYTE *)(a2 + 457)) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set MLME restircted 80p80 BW support",
      v204,
      v205,
      v206,
      v207,
      v208,
      v209,
      v210,
      v211,
      "hdd_update_tgt_cfg");
  if ( (*(_BYTE *)(a2 + 87) & 1) == 0 )
    wlan_mlme_set_t2lm_negotiation_supported(*a1, 0);
  hdd_update_wiphy_vhtcap(a1);
  hdd_update_vhtcap_2g(a1);
  v212 = a1[3];
  v213 = *a1;
  *((_WORD *)a1 + 812) = *(_WORD *)(a2 + 174);
  wlan_config_sched_scan_plans_to_wiphy(v212, v213);
  hdd_runtime_suspend_context_init(a1);
  hdd_tx_powerboost_target_config(a1, a2);
  hdd_nan_datapath_target_config(a1, a2);
  ucfg_nan_set_tgt_caps(*a1, a2 + 452);
  v214 = *a1;
  *((_BYTE *)a1 + 1817) = *(_BYTE *)(a2 + 412);
  *((_BYTE *)a1 + 3488) = *(_DWORD *)(a2 + 56) != 0;
  v215 = *(_BYTE *)(a2 + 77);
  *((_BYTE *)a1 + 3489) = v215;
  ucfg_scan_set_obss_scan_offload(v214, v215);
  if ( (unsigned int)ucfg_mlme_set_obss_detection_offload_enabled(*a1, *(_BYTE *)(a2 + 416)) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Couldn't pass WNI_CFG_OBSS_DETECTION_OFFLOAD to CFG",
      v216,
      v217,
      v218,
      v219,
      v220,
      v221,
      v222,
      v223,
      "hdd_update_tgt_cfg");
  if ( (unsigned int)ucfg_mlme_set_obss_color_collision_offload_enabled(*a1, *(_BYTE *)(a2 + 417)) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set WNI_CFG_OBSS_COLOR_COLLISION_OFFLOAD",
      v224,
      v225,
      v226,
      v227,
      v228,
      v229,
      v230,
      v231,
      "hdd_update_tgt_cfg");
  ucfg_mlme_set_bss_color_collision_det_support(*a1, *(_BYTE *)(a2 + 417));
  if ( (*(_BYTE *)(a2 + 417) & 1) == 0 && (unsigned int)ucfg_mlme_set_bss_color_collision_det_sta(*a1, 0) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set CFG_BSS_CLR_COLLISION_DET_STA",
      v232,
      v233,
      v234,
      v235,
      v236,
      v237,
      v238,
      v239,
      "hdd_update_tgt_cfg");
  hdd_update_score_config(a1);
  hdd_update_multi_client_thermal_support(a1);
  ucfg_psoc_mlme_set_11be_capab(*a1, *(_BYTE *)(a2 + 84));
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
