__int64 __fastcall wlan_hdd_cfg80211_start_bss(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        const void *a11,
        __int64 a12,
        unsigned int a13,
        char a14)
{
  __int64 v17; // x23
  __int64 *v20; // x20
  __int64 v21; // x21
  __int64 vdev_by_user; // x0
  __int64 v23; // x19
  __int64 link_mac_addr; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const void *v33; // x27
  __int64 v34; // x21
  const char *v35; // x2
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int *v60; // x9
  const char *v61; // x2
  int v62; // w8
  int v63; // w8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v72; // w0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w19
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x4
  const char *v99; // x2
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
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  bool v141; // w8
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  unsigned int v151; // w4
  int v152; // w8
  _BYTE *v153; // x21
  unsigned __int8 *ie_ptr_from_eid; // x1
  __int64 v155; // x8
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  _QWORD *context; // x0
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  unsigned __int8 *v173; // x0
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  __int64 v182; // x8
  __int64 v183; // x9
  unsigned __int16 v184; // w8
  unsigned __int8 *v185; // x19
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  _QWORD *v194; // x0
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  unsigned __int64 v203; // x8
  unsigned int v204; // w21
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  unsigned __int8 *v221; // x0
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  __int64 v230; // x4
  unsigned __int8 *v231; // x8
  _BYTE *v232; // x9
  __int64 v233; // x10
  char v234; // w11
  int v235; // t1
  unsigned __int8 *v236; // x0
  __int64 v237; // x4
  unsigned __int8 *v238; // x8
  _BYTE *v239; // x9
  __int64 v240; // x10
  char v241; // w11
  int v242; // t1
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  int v259; // w8
  int v260; // w8
  int v261; // w8
  __int64 v262; // x0
  __int64 v263; // x1
  double v264; // d0
  unsigned int v265; // w0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  __int64 max_phymode; // x0
  unsigned int v274; // w0
  double v275; // d0
  double v276; // d1
  double v277; // d2
  double v278; // d3
  double v279; // d4
  double v280; // d5
  double v281; // d6
  double v282; // d7
  __int64 v283; // x5
  unsigned int v284; // w8
  int v285; // w8
  __int64 v286; // x0
  double v287; // d0
  double v288; // d1
  double v289; // d2
  double v290; // d3
  double v291; // d4
  double v292; // d5
  double v293; // d6
  double v294; // d7
  char v295; // w0
  int v296; // w9
  int v297; // w8
  double v298; // d0
  double v299; // d1
  double v300; // d2
  double v301; // d3
  double v302; // d4
  double v303; // d5
  double v304; // d6
  double v305; // d7
  double v306; // d0
  double v307; // d1
  double v308; // d2
  double v309; // d3
  double v310; // d4
  double v311; // d5
  double v312; // d6
  double v313; // d7
  const char *v314; // x2
  __int64 v315; // x4
  __int64 v316; // x5
  __int64 v317; // x6
  __int64 v318; // x7
  double v319; // d0
  double v320; // d1
  double v321; // d2
  double v322; // d3
  double v323; // d4
  double v324; // d5
  double v325; // d6
  double v326; // d7
  double v327; // d0
  double v328; // d1
  double v329; // d2
  double v330; // d3
  double v331; // d4
  double v332; // d5
  double v333; // d6
  double v334; // d7
  __int64 v335; // x19
  unsigned int v336; // w21
  unsigned int conc_ext_flags; // w0
  double v338; // d0
  double v339; // d1
  double v340; // d2
  double v341; // d3
  double v342; // d4
  double v343; // d5
  double v344; // d6
  double v345; // d7
  int v346; // w8
  __int64 v347; // x19
  double v348; // d0
  double v349; // d1
  double v350; // d2
  double v351; // d3
  double v352; // d4
  double v353; // d5
  double v354; // d6
  double v355; // d7
  double v356; // d0
  double v357; // d1
  double v358; // d2
  double v359; // d3
  double v360; // d4
  double v361; // d5
  double v362; // d6
  double v363; // d7
  unsigned int v364; // w19
  double v365; // d0
  double v366; // d1
  double v367; // d2
  double v368; // d3
  double v369; // d4
  double v370; // d5
  double v371; // d6
  double v372; // d7
  __int64 v373; // x4
  const char *v374; // x2
  __int64 v375; // x5
  double v376; // d0
  double v377; // d1
  double v378; // d2
  double v379; // d3
  double v380; // d4
  double v381; // d5
  double v382; // d6
  double v383; // d7
  double v384; // d0
  double v385; // d1
  double v386; // d2
  double v387; // d3
  double v388; // d4
  double v389; // d5
  double v390; // d6
  double v391; // d7
  double started; // d0
  double v393; // d1
  double v394; // d2
  double v395; // d3
  double v396; // d4
  double v397; // d5
  double v398; // d6
  double v399; // d7
  unsigned __int64 v402; // x10
  unsigned __int64 v409; // x9
  unsigned __int64 v412; // x9
  unsigned int v413; // [xsp+7Ch] [xbp-B4h]
  __int64 v414; // [xsp+80h] [xbp-B0h]
  __int64 v415; // [xsp+88h] [xbp-A8h]
  __int64 v416; // [xsp+90h] [xbp-A0h]
  int v417; // [xsp+9Ch] [xbp-94h]
  __int64 v418; // [xsp+A0h] [xbp-90h]
  char v419; // [xsp+A8h] [xbp-88h]
  _DWORD *v420; // [xsp+B0h] [xbp-80h]
  char v421[4]; // [xsp+B8h] [xbp-78h] BYREF
  char v422[4]; // [xsp+BCh] [xbp-74h] BYREF
  char v423[4]; // [xsp+C0h] [xbp-70h] BYREF
  char v424[4]; // [xsp+C4h] [xbp-6Ch] BYREF
  char v425[4]; // [xsp+C8h] [xbp-68h] BYREF
  char v426[4]; // [xsp+CCh] [xbp-64h] BYREF
  _BYTE v427[4]; // [xsp+D0h] [xbp-60h] BYREF
  _BYTE v428[4]; // [xsp+D4h] [xbp-5Ch] BYREF
  char v429[4]; // [xsp+D8h] [xbp-58h] BYREF
  char v430[4]; // [xsp+DCh] [xbp-54h] BYREF
  __int64 v431; // [xsp+E0h] [xbp-50h] BYREF
  _QWORD v432[9]; // [xsp+E8h] [xbp-48h] BYREF

  v432[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)a1;
  v431 = 0;
  v20 = *(__int64 **)(v17 + 24);
  v430[0] = 0;
  v429[0] = 0;
  v428[0] = 0;
  v427[0] = 0;
  v426[0] = 0;
  v425[0] = 0;
  v424[0] = 0;
  v423[0] = 0;
  v422[0] = 0;
  v421[0] = 1;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_cfg80211_start_bss");
  LODWORD(v21) = _wlan_hdd_validate_context(v20, "wlan_hdd_cfg80211_start_bss");
  if ( !(_DWORD)v21 )
  {
    if ( (policy_mgr_is_sta_mon_concurrency(*v20) & 1) == 0 )
    {
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "wlan_hdd_cfg80211_start_bss");
      if ( vdev_by_user )
      {
        v23 = vdev_by_user;
        link_mac_addr = hdd_adapter_get_link_mac_addr(a1);
        if ( !link_mac_addr )
        {
          v35 = "%s: Invalid link_mac";
          goto LABEL_18;
        }
        v33 = (const void *)link_mac_addr;
        wlan_mlme_get_sap_force_11n_for_11ac(*v20, v424);
        wlan_mlme_get_go_force_11n_for_11ac(*v20, v423);
        v34 = *(_QWORD *)(a1 + 5968);
        if ( (v34 & 2) == 0 && (unsigned int)if_mgr_deliver_event(v23, 5u, 0, v25, v26, v27, v28, v29, v30, v31, v32) )
        {
          v35 = "%s: start bss failed!!";
LABEL_18:
          qdf_trace_msg(0x33u, 2u, v35, v25, v26, v27, v28, v29, v30, v31, v32, "wlan_hdd_cfg80211_start_bss");
          LODWORD(v21) = -22;
LABEL_58:
          _hdd_objmgr_put_vdev_by_user(v23, 5, "wlan_hdd_cfg80211_start_bss");
          goto LABEL_59;
        }
        hdd_abort_ongoing_sta_sae_connection((__int64)v20, v25, v26, v27, v28, v29, v30, v31, v32);
        v418 = v20[2];
        v419 = v34;
        v420 = (_DWORD *)_qdf_mem_malloc(0x4E4u, "wlan_hdd_cfg80211_start_bss", 7419);
        if ( !v420 )
        {
          LODWORD(v21) = -12;
          goto LABEL_54;
        }
        if ( !*(_DWORD *)(a1 + 720) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid channel",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "wlan_hdd_cfg80211_start_bss");
          LODWORD(v21) = -22;
          goto LABEL_54;
        }
        v417 = *(_DWORD *)(a1 + 720);
        if ( (unsigned int)ucfg_policy_mgr_get_indoor_chnl_marking(*v20, v425) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: can't get indoor channel marking, using default",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "wlan_hdd_cfg80211_start_bss");
        if ( v425[0] && *(_DWORD *)(v17 + 40) == 1 )
        {
          hdd_update_indoor_channel(v20, 1);
          if ( (unsigned int)sme_update_channel_list(v418) )
          {
            hdd_update_indoor_channel(v20, 0);
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: vdev %d Can't start BSS: update channel list failed",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "wlan_hdd_cfg80211_start_bss",
              *(unsigned __int8 *)(a1 + 8));
            LODWORD(v21) = -22;
            goto LABEL_54;
          }
          if ( policy_mgr_is_force_scc(*v20) )
            hdd_check_and_disconnect_sta_on_invalid_channel((__int64)v20, 65523);
        }
        v60 = *(int **)(a1 + 2432);
        if ( v60[8] <= 35 )
        {
          v61 = "%s: Invalid beacon head len";
LABEL_25:
          qdf_trace_msg(0x33u, 2u, v61, v44, v45, v46, v47, v48, v49, v50, v51, "wlan_hdd_cfg80211_start_bss");
LABEL_49:
          LODWORD(v21) = -22;
          goto LABEL_50;
        }
        v416 = *(_QWORD *)(a1 + 2432);
        v414 = *(_QWORD *)v60;
        *(_DWORD *)(a1 + 1412) = *(unsigned __int16 *)(*(_QWORD *)v60 + 32LL);
        v62 = *(unsigned __int8 *)(a1 + 1424);
        *(_BYTE *)(a1 + 756) = v60[12];
        if ( v62 == 1 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: acs_chan_freq %u, acs_dfs_mode %u",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "wlan_hdd_cfg80211_start_bss",
            *((unsigned int *)v20 + 405),
            *((unsigned int *)v20 + 404));
          v63 = *((_DWORD *)v20 + 405);
          if ( v63 )
            *(_DWORD *)(a1 + 720) = v63;
          *(_DWORD *)(a1 + 2132) = wlan_hdd_get_dfs_mode(*((unsigned int *)v20 + 404));
        }
        else
        {
          wlan_sap_set_acs_band_mask(*(_QWORD *)(a1 + 32), 7, v44, v45, v46, v47, v48, v49, v50, v51);
        }
        ucfg_util_vdev_mgr_set_acs_mode_for_vdev();
        ucfg_policy_mgr_get_mcc_scc_switch(*v20, v430);
        wlan_hdd_set_sap_beacon_protection(v20, a1, v416);
        if ( (policy_mgr_is_hw_dbs_capable(*v20) & 1) != 0 && wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 720)) )
        {
          LODWORD(v21) = 0;
        }
        else
        {
          LODWORD(v21) = wlan_hdd_sap_cfg_dfs_override((__int64 *)a1, v64, v65, v66, v67, v68, v69, v70, v71);
          if ( (v21 & 0x80000000) != 0 )
          {
LABEL_50:
            wlan_hdd_mlo_reset(a1);
            if ( v425[0] && *(_DWORD *)(v17 + 40) == 1 )
            {
              hdd_update_indoor_channel(v20, 0);
              sme_update_channel_list(v418);
            }
LABEL_208:
            _X8 = (unsigned __int64 *)(a1 + 5968);
            __asm { PRFM            #0x11, [X8] }
            do
              v402 = __ldxr(_X8);
            while ( __stxr(v402 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
            *(_DWORD *)(a1 + 2616) = 0;
            wlansap_reset_sap_config_add_ie(a1 + 280, 6);
            goto LABEL_54;
          }
        }
        v415 = v23;
        v72 = wlan_ll_lt_sap_override_freq(*v20, *(unsigned __int8 *)(a1 + 8), *(unsigned int *)(a1 + 720));
        *(_DWORD *)(a1 + 720) = v72;
        v81 = v72;
        if ( *(_DWORD *)(v17 + 40) == 1 )
        {
          if ( (wlan_nan_is_sta_sap_nan_allowed(*v20) & 1) != 0
            && (unsigned int)policy_mgr_mode_specific_connection_count(*v20, 5, nullptr) )
          {
            v81 = wlan_nan_sap_override_freq(*v20, *(unsigned __int8 *)(a1 + 8), *(unsigned int *)(a1 + 720));
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: vdev %d, update SAP freq from %d to %d due to NAN",
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              "wlan_hdd_cfg80211_start_bss",
              *(unsigned __int8 *)(a1 + 8),
              *(unsigned int *)(a1 + 720),
              v81);
            *(_DWORD *)(a1 + 720) = v81;
          }
          else
          {
            v81 = *(_DWORD *)(a1 + 720);
          }
        }
        if ( !v81 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: vdev %d invalid ch_freq: %d",
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            "wlan_hdd_cfg80211_start_bss",
            *(unsigned __int8 *)(a1 + 8),
            0);
          goto LABEL_48;
        }
        if ( !(_DWORD)v21 && (wlan_reg_is_dfs_for_freq(v20[1], v81, v73, v74, v75, v76, v77, v78, v79, v80) & 1) != 0 )
          *((_BYTE *)v20 + 912) = 0;
        if ( (unsigned int)wlan_hdd_validate_operation_channel(v20, *(_DWORD *)(a1 + 720)) )
        {
          v98 = *(unsigned int *)(a1 + 720);
          v99 = "%s: Invalid Ch_freq: %d";
LABEL_46:
          qdf_trace_msg(0x33u, 2u, v99, v90, v91, v92, v93, v94, v95, v96, v97, "wlan_hdd_cfg80211_start_bss", v98);
LABEL_48:
          v23 = v415;
          goto LABEL_49;
        }
        wlan_scan_cfg_get_dfs_chan_scan_allowed(*v20, v421);
        v23 = v415;
        if ( (v421[0] & 1) == 0
          && (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                             v20[1],
                             *(_DWORD *)(a1 + 720),
                             v117,
                             v118,
                             v119,
                             v120,
                             v121,
                             v122,
                             v123,
                             v124) == 2 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: No SAP start on DFS channel",
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            "wlan_hdd_cfg80211_start_bss");
          LODWORD(v21) = -95;
          goto LABEL_50;
        }
        if ( (unsigned int)ucfg_mlme_get_dfs_ignore_cac(*v20, v426) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: can't get ignore cac flag",
            v133,
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            "wlan_hdd_cfg80211_start_bss");
        wlansap_set_dfs_ignore_cac(v418, (unsigned __int8)v426[0]);
        wlansap_set_dfs_preferred_channel_location(v418);
        tgt_dfs_set_tx_leakage_threshold(v20[1]);
        v141 = (*(_BYTE *)(v414 + 34) & 0x10) != 0;
        *(_BYTE *)(a1 + 1408) = v141;
        *(_BYTE *)(a1 + 260) = v141;
        vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                   &unk_AF7AD8,
                                   4u,
                                   *(unsigned __int8 **)(v416 + 8),
                                   *(_DWORD *)(v416 + 36));
        if ( vendor_ie_ptr_from_oui )
        {
          v151 = vendor_ie_ptr_from_oui[1];
          if ( v151 <= 0xD )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Wps Ie Length(%hhu) is too small",
              v143,
              v144,
              v145,
              v146,
              v147,
              v148,
              v149,
              v150,
              "wlan_hdd_cfg80211_start_bss");
            goto LABEL_49;
          }
          if ( *(_DWORD *)(vendor_ie_ptr_from_oui + 2) != 82989056 )
          {
LABEL_71:
            v153 = (_BYTE *)(a1 + 762);
            *(_DWORD *)(a1 + 264) = 0;
            *(_WORD *)(a1 + 1410) = 0;
            memset((void *)(a1 + 762), 0, 0x202u);
            ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x30u, *(unsigned __int8 **)(v416 + 8), *(_DWORD *)(v416 + 36));
            if ( ie_ptr_from_eid
              || (ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(
                                      0x44u,
                                      *(unsigned __int8 **)(v416 + 8),
                                      *(_DWORD *)(v416 + 36))) != nullptr )
            {
              v155 = ie_ptr_from_eid[1];
              if ( ie_ptr_from_eid[1] )
              {
                *(_WORD *)(a1 + 1410) = v155 + 2;
                memcpy((void *)(a1 + 762), ie_ptr_from_eid, v155 + 2);
                context = _cds_get_context(
                            52,
                            (__int64)"wlan_hdd_cfg80211_start_bss",
                            v156,
                            v157,
                            v158,
                            v159,
                            v160,
                            v161,
                            v162,
                            v163);
                if ( (unsigned int)hdd_softap_unpack_ie(
                                     context,
                                     (char *)&v431 + 4,
                                     &v431,
                                     a1 + 1280,
                                     v428,
                                     v427,
                                     (unsigned int)*(unsigned __int8 *)(a1 + 763) + 2,
                                     a1 + 762) )
                  goto LABEL_49;
                *(_DWORD *)(a1 + 264) = HIDWORD(v431);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: CSR Encryption: %d mcEncryption: %d num_akm_suites:%d",
                  v165,
                  v166,
                  v167,
                  v168,
                  v169,
                  v170,
                  v171,
                  v172,
                  "wlan_hdd_cfg80211_start_bss");
                ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
                  51,
                  8,
                  a1 + 1284,
                  *(unsigned int *)(a1 + 1280));
                hdd_softap_update_pasn_vdev_params(v20, *(unsigned __int8 *)(a1 + 8), v416, v428[0], v427[0]);
              }
            }
            v173 = wlan_get_vendor_ie_ptr_from_oui(
                     &unk_AF7ADD,
                     4u,
                     *(unsigned __int8 **)(v416 + 8),
                     *(_DWORD *)(v416 + 36));
            if ( v173 )
            {
              v182 = v173[1];
              if ( v173[1] )
              {
                if ( *v173 == 221 )
                {
                  if ( *v153 )
                  {
                    v183 = *(unsigned __int16 *)(a1 + 1410);
                    v184 = v182 + v183 + 2;
                    *(_WORD *)(a1 + 1410) = v184;
                    if ( v184 > 0x201u )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: RSNWPA IE MAX Length exceeded; length: %d",
                        v174,
                        v175,
                        v176,
                        v177,
                        v178,
                        v179,
                        v180,
                        v181,
                        "wlan_hdd_cfg80211_start_bss");
                    else
                      memcpy(&v153[v183], v173, v173[1] + 2LL);
                  }
                  else
                  {
                    *(_WORD *)(a1 + 1410) = v182 + 2;
                    memcpy((void *)(a1 + 762), v173, v182 + 2);
                    v194 = _cds_get_context(
                             52,
                             (__int64)"wlan_hdd_cfg80211_start_bss",
                             v186,
                             v187,
                             v188,
                             v189,
                             v190,
                             v191,
                             v192,
                             v193);
                    if ( (unsigned int)hdd_softap_unpack_ie(
                                         v194,
                                         (char *)&v431 + 4,
                                         &v431,
                                         a1 + 1280,
                                         v428,
                                         v427,
                                         (unsigned int)*(unsigned __int8 *)(a1 + 763) + 2,
                                         a1 + 762) )
                      goto LABEL_48;
                    *(_DWORD *)(a1 + 264) = HIDWORD(v431);
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: CSR Encryption: %d mcEncryption: %d num_akm_suites:%d",
                      v195,
                      v196,
                      v197,
                      v198,
                      v199,
                      v200,
                      v201,
                      v202,
                      "wlan_hdd_cfg80211_start_bss");
                    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
                      51,
                      8,
                      a1 + 1284,
                      *(unsigned int *)(a1 + 1280));
                  }
                }
              }
            }
            v203 = *(unsigned int *)(a1 + 1280);
            if ( (_DWORD)v203 )
            {
              v23 = 0;
              v21 = a1 + 1284;
              while ( v23 != 31 )
              {
                if ( *(_DWORD *)(v21 + 4 * v23) == 23 )
                {
                  wlan_sap_set_owe_connection_support(v415, 1, v174, v175, v176, v177, v178, v179, v180, v181);
                  v203 = *(unsigned int *)(a1 + 1280);
                }
                if ( ++v23 >= v203 )
                  goto LABEL_95;
              }
              __break(0x5512u);
              goto LABEL_208;
            }
LABEL_95:
            v204 = policy_mgr_qdf_opmode_to_pm_con_mode(
                     *v20,
                     *(_DWORD *)(v17 + 40),
                     *(_BYTE *)(a1 + 8),
                     v174,
                     v175,
                     v176,
                     v177,
                     v178,
                     v179,
                     v180,
                     v181);
            if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))policy_mgr_is_multi_sap_allowed_on_same_band)(
                    v20[1],
                    v204,
                    *(unsigned int *)(a1 + 720),
                    *(unsigned __int8 *)(a1 + 8))
                & 1) == 0 )
              goto LABEL_48;
            v23 = v415;
            if ( *(unsigned __int16 *)(a1 + 1410) >= 0x203u )
            {
              v61 = "%s: RSNWPAReqIELength is too large";
              goto LABEL_25;
            }
            v413 = v204;
            *(_BYTE *)(a1 + 313) = 0;
            if ( a11 )
            {
              qdf_mem_copy((void *)(a1 + 281), a11, (unsigned int)a12);
              *(_BYTE *)(a1 + 280) = a12;
              if ( a13 == 2 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: HIDDEN_SSID_ZERO_CONTENTS",
                  v205,
                  v206,
                  v207,
                  v208,
                  v209,
                  v210,
                  v211,
                  v212,
                  "wlan_hdd_cfg80211_start_bss");
                *(_BYTE *)(a1 + 313) = 2;
              }
              else if ( a13 == 1 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: HIDDEN_SSID_ZERO_LEN",
                  v205,
                  v206,
                  v207,
                  v208,
                  v209,
                  v210,
                  v211,
                  v212,
                  "wlan_hdd_cfg80211_start_bss");
                *(_BYTE *)(a1 + 313) = 1;
              }
              else if ( a13 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Wrong hidden_ssid param: %d",
                  v205,
                  v206,
                  v207,
                  v208,
                  v209,
                  v210,
                  v211,
                  v212,
                  "wlan_hdd_cfg80211_start_bss",
                  a13);
              }
              else
              {
                *(_BYTE *)(a1 + 313) = 0;
              }
              v23 = v415;
            }
            wlan_hdd_set_multipass(v23);
            qdf_mem_copy((void *)(a1 + 712), v33, 6u);
            *(_DWORD *)(a1 + 324) = 0;
            *(_DWORD *)(a1 + 758) = 0;
            if ( (unsigned int)ucfg_policy_mgr_get_conc_rule1(*v20, v429) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: can't get ucfg_policy_mgr_get_conc_rule1, use def",
                v213,
                v214,
                v215,
                v216,
                v217,
                v218,
                v219,
                v220,
                "wlan_hdd_cfg80211_start_bss");
            if ( !v429[0] || *(_DWORD *)(v17 + 40) == 1 )
              *(_BYTE *)(a1 + 1421) = v430[0];
            if ( !a11 || a12 != 12 || (unsigned int)qdf_mem_cmp(a11, "pre_cac_ssid", 0xCu) )
            {
              v221 = wlan_get_ie_ptr_from_eid(1u, (unsigned __int8 *)(v414 + 36), *(_WORD *)(v416 + 32) - 36);
              if ( v221 )
              {
                v230 = v221[1];
                if ( (unsigned int)v230 >= 0xD )
                {
LABEL_125:
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Invalid supported rates %d",
                    v222,
                    v223,
                    v224,
                    v225,
                    v226,
                    v227,
                    v228,
                    v229,
                    "wlan_hdd_cfg80211_start_bss");
                  goto LABEL_48;
                }
                *(_BYTE *)(a1 + 2104) = v230;
                if ( (_DWORD)v230 )
                {
                  v231 = v221 + 2;
                  v232 = (_BYTE *)(a1 + 2105);
                  v233 = v230;
                  do
                  {
                    v235 = *v231++;
                    v234 = v235;
                    if ( v235 )
                      *v232 = v234;
                    --v233;
                    ++v232;
                  }
                  while ( v233 );
                }
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Configured Num Supported rates: %d",
                  v222,
                  v223,
                  v224,
                  v225,
                  v226,
                  v227,
                  v228,
                  v229,
                  "wlan_hdd_cfg80211_start_bss");
                ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
                  51,
                  8,
                  a1 + 2105,
                  *(unsigned __int8 *)(a1 + 2104));
              }
              v236 = wlan_get_ie_ptr_from_eid(0x32u, *(unsigned __int8 **)(v416 + 8), *(_DWORD *)(v416 + 36));
              if ( v236 )
              {
                v237 = v236[1];
                if ( (unsigned int)v237 >= 0xD )
                  goto LABEL_125;
                *(_BYTE *)(a1 + 2117) = v237;
                if ( (_DWORD)v237 )
                {
                  v238 = v236 + 2;
                  v239 = (_BYTE *)(a1 + 2118);
                  v240 = v237;
                  do
                  {
                    v242 = *v238++;
                    v241 = v242;
                    if ( v242 )
                      *v239 = v241;
                    --v240;
                    ++v239;
                  }
                  while ( v240 );
                }
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Configured Num Extended rates: %d",
                  v222,
                  v223,
                  v224,
                  v225,
                  v226,
                  v227,
                  v228,
                  v229,
                  "wlan_hdd_cfg80211_start_bss");
                ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
                  51,
                  8,
                  a1 + 2118,
                  *(unsigned __int8 *)(a1 + 2117));
              }
              *(_BYTE *)(a1 + 2130) = 0;
              wlan_hdd_check_h2e(a1 + 2104, a1 + 2130);
              wlan_hdd_check_h2e(a1 + 2117, a1 + 2130);
            }
            v23 = v415;
            LODWORD(v21) = wlan_hdd_update_rnrie(v416, a1 + 280, a1);
            if ( (_DWORD)v21 )
              goto LABEL_50;
            if ( !cds_is_sub_20_mhz_enabled(v243, v244, v245, v246, v247, v248, v249, v250) )
              wlan_hdd_set_sap_hwmode(a1);
            if ( (unsigned int)wlan_hdd_mlo_update(a1) )
              goto LABEL_48;
            if ( (unsigned int)wlan_mlme_get_vht_for_24ghz(*v20, v422) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to get vht_for_24ghz",
                v251,
                v252,
                v253,
                v254,
                v255,
                v256,
                v257,
                v258,
                "wlan_hdd_cfg80211_start_bss");
            if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 720)) && v422[0] == 1 )
            {
              v259 = *(_DWORD *)(a1 + 320);
              if ( v259 == 64 || v259 == 16 )
                *(_DWORD *)(a1 + 320) = 256;
            }
            v260 = *(_DWORD *)(v17 + 40);
            if ( v260 == 3 )
            {
              if ( v423[0] != 1 )
                goto LABEL_152;
            }
            else if ( v260 != 1 || (v424[0] & 1) == 0 )
            {
              goto LABEL_152;
            }
            v261 = *(_DWORD *)(a1 + 320);
            if ( v261 == 512 || v261 == 256 )
              *(_DWORD *)(a1 + 320) = 16;
LABEL_152:
            if ( policy_mgr_is_vdev_ll_lt_sap(*v20, *(unsigned __int8 *)(a1 + 8)) )
            {
              v262 = 16;
              *(_DWORD *)(a1 + 752) = 0;
              *(_DWORD *)(a1 + 320) = 16;
            }
            else
            {
              v262 = *(unsigned int *)(a1 + 320);
            }
            v263 = *(unsigned int *)(a1 + 720);
            *(_DWORD *)(a1 + 316) = v262;
            v264 = csr_convert_to_reg_phy_mode(v262, v263);
            max_phymode = wlan_reg_get_max_phymode(
                            v20[1],
                            v265,
                            *(_DWORD *)(a1 + 720),
                            v264,
                            v266,
                            v267,
                            v268,
                            v269,
                            v270,
                            v271,
                            v272);
            v274 = csr_convert_from_reg_phy_mode(max_phymode);
            v283 = *(unsigned int *)(a1 + 316);
            *(_DWORD *)(a1 + 320) = v274;
            if ( (_DWORD)v283 != v274 )
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: Vdev %d orig phymode %d new phymode %d",
                v275,
                v276,
                v277,
                v278,
                v279,
                v280,
                v281,
                v282,
                "wlan_hdd_cfg80211_start_bss",
                *(unsigned __int8 *)(a1 + 8),
                v283,
                v274);
            qdf_mem_set(v420, 0x4E4u, 0);
            sme_get_config_param(v418, v420);
            v420[4] = 0;
            if ( !wlan_get_vendor_ie_ptr_from_oui(
                    &unk_AF7AE2,
                    5u,
                    *(unsigned __int8 **)(v416 + 8),
                    *(_DWORD *)(v416 + 36)) )
            {
              v284 = *(_DWORD *)(a1 + 320);
              if ( v284 <= 8 && ((1 << v284) & 0x114) != 0 )
                v420[4] = 2;
            }
            sme_update_config(v418, v420);
            v285 = *(_DWORD *)(v17 + 40);
            if ( v285 == 3 )
            {
              if ( v423[0] != 1 )
                goto LABEL_168;
            }
            else if ( v285 != 1 || (v424[0] & 1) == 0 )
            {
              goto LABEL_168;
            }
            if ( *(_DWORD *)(a1 + 752) >= 2u )
              *(_DWORD *)(a1 + 752) = 1;
LABEL_168:
            wlan_hdd_setup_driver_overrides(v17);
            v286 = *(unsigned int *)(a1 + 320);
            *(_DWORD *)(a1 + 728) = *(_DWORD *)(a1 + 752);
            v287 = sap_phymode_is_eht(v286);
            if ( (v295 & 1) != 0 )
              wlan_reg_set_create_punc_bitmap(a1 + 728, 1);
            if ( *(_DWORD *)(a1 + 728) != 4 || (ucfg_mlme_get_restricted_80p80_bw_supp(*v20) & 1) == 0 )
              goto LABEL_178;
            v296 = *(unsigned __int8 *)(a1 + 733);
            v297 = *(unsigned __int8 *)(a1 + 734);
            if ( v296 == 138 )
            {
              if ( v297 == 155 )
                goto LABEL_178;
            }
            else if ( v296 == 155 && v297 == 138 )
            {
              goto LABEL_178;
            }
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Falling back to 80 from 80p80 as non supported freq_seq0 %d and freq_seq1 %d",
              v287,
              v288,
              v289,
              v290,
              v291,
              v292,
              v293,
              v294,
              "wlan_hdd_cfg80211_start_bss",
              *(unsigned int *)(a1 + 736),
              *(unsigned int *)(a1 + 740));
            *(_BYTE *)(a1 + 734) = 0;
            *(_DWORD *)(a1 + 740) = 0;
            *(_DWORD *)(a1 + 752) = 2;
            *(_DWORD *)(a1 + 728) = 2;
LABEL_178:
            wlan_reg_set_channel_params_for_pwrmode(
              v20[1],
              *(_DWORD *)(a1 + 720),
              *(_DWORD *)(a1 + 724),
              a1 + 728,
              0,
              v287,
              v288,
              v289,
              v290,
              v291,
              v292,
              v293,
              v294);
            if ( (unsigned int)wlan_hdd_cfg80211_update_apies(
                                 (__int64 *)a1,
                                 v298,
                                 v299,
                                 v300,
                                 v301,
                                 v302,
                                 v303,
                                 v304,
                                 v305) )
            {
              v314 = "%s: SAP Not able to set AP IEs";
              goto LABEL_194;
            }
            if ( v17 == -1617 )
            {
              v317 = 0;
              v315 = 0;
              v316 = 0;
              v318 = 0;
            }
            else
            {
              v315 = *(unsigned __int8 *)(v17 + 1617);
              v316 = *(unsigned __int8 *)(v17 + 1618);
              v317 = *(unsigned __int8 *)(v17 + 1619);
              v318 = *(unsigned __int8 *)(v17 + 1622);
            }
            qdf_trace_msg(
              0x33u,
              8u,
              "Vdev %d SAP mac:%02x:%02x:%02x:**:**:%02x SSID: %.*s BCNINTV:%d Freq:%d freq_seg0:%d freq_seg1:%d ch_width"
              ":%d HW mode:%d privacy:%d akm:%d acs_mode:%d acs_dfs_mode %d dtim period:%d MFPC %d, MFPR %d",
              v306,
              v307,
              v308,
              v309,
              v310,
              v311,
              v312,
              v313,
              *(unsigned __int8 *)(a1 + 8),
              v315,
              v316,
              v317,
              v318,
              *(unsigned __int8 *)(a1 + 280),
              a1 + 281,
              *(_DWORD *)(a1 + 1412),
              *(_DWORD *)(a1 + 720),
              *(_DWORD *)(a1 + 736),
              *(_DWORD *)(a1 + 740),
              *(_DWORD *)(a1 + 728),
              *(_DWORD *)(a1 + 320),
              *(unsigned __int8 *)(a1 + 1408),
              *(_DWORD *)(a1 + 1276),
              *(unsigned __int8 *)(a1 + 1424),
              *(_DWORD *)(a1 + 2132),
              *(unsigned __int8 *)(a1 + 756),
              v428[0],
              v427[0]);
            mutex_lock(v20 + 24);
            if ( (cds_get_driver_state(v319, v320, v321, v322, v323, v324, v325, v326) & 4) != 0 )
            {
              mutex_unlock(v20 + 24);
              v314 = "%s: The driver is unloading, ignore the bss starting";
              goto LABEL_194;
            }
            if ( (*(_QWORD *)(a1 + 5968) & 2) == 0 )
            {
              if ( (a14 & 1) == 0
                || (unsigned int)policy_mgr_mode_specific_connection_count(*v20, 5, nullptr)
                || (v335 = *v20,
                    v336 = *(_DWORD *)(a1 + 720),
                    conc_ext_flags = policy_mgr_get_conc_ext_flags(
                                       v415,
                                       0,
                                       v327,
                                       v328,
                                       v329,
                                       v330,
                                       v331,
                                       v332,
                                       v333,
                                       v334),
                    (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
                       v335,
                       v413,
                       v336,
                       3,
                       conc_ext_flags,
                       *(unsigned __int8 *)(a1 + 8))
                   & 1) != 0) )
              {
                if ( (hdd_set_connection_in_progress(1) & 1) != 0 )
                {
                  v346 = *(_DWORD *)(v17 + 40);
                  *(_BYTE *)(a1 + 256) = 1;
                  *(_DWORD *)(a1 + 1416) = v346;
                  _X8 = (unsigned __int64 *)(a1 + 5968);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v409 = __ldxr(_X8);
                  while ( __stxr(v409 | 4, _X8) );
                  ucfg_dp_set_dfs_cac_tx(v415, 1, v338, v339, v340, v341, v342, v343, v344, v345);
                  qdf_event_reset(a1 + 88);
                  v347 = *(_QWORD *)(a1 + 272);
                  if ( !v347 )
                    goto LABEL_48;
                  hdd_abort_non_sap_scan_all_adapters(v20);
                  if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64 (__fastcall *)(__int64, int *, double, double, double, double, double, double, double, double), __int64))wlansap_start_bss)(
                                        v347,
                                        hdd_hostapd_sap_event_cb,
                                        a1 + 280) )
                  {
                    v364 = qdf_wait_single_event(a1 + 88, 0x32C8u);
                    wlansap_reset_sap_config_add_ie(a1 + 280, 6);
                    if ( v364 )
                    {
                      mutex_unlock(v20 + 24);
                      v373 = *(unsigned __int8 *)(a1 + 8);
                      v374 = "%s: vdev %d, Wait for start BSS failed status %d";
                      v375 = v364;
                    }
                    else
                    {
                      if ( !*(_DWORD *)(a1 + 248) )
                      {
                        _X8 = (unsigned __int64 *)(a1 + 5968);
                        __asm { PRFM            #0x11, [X8] }
                        do
                          v412 = __ldxr(_X8);
                        while ( __stxr(v412 | 2, _X8) );
                        mutex_unlock(v20 + 24);
                        hdd_wmm_dscp_initial_state(v17);
                        if ( *(_DWORD *)(a1 + 80) == 1 )
                        {
                          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))policy_mgr_incr_active_session)(
                            *v20,
                            *(unsigned int *)(v17 + 40),
                            *(unsigned __int8 *)(a1 + 8),
                            1);
                          started = hdd_green_ap_start_state_mc(v20, *(unsigned int *)(v17 + 40), 1);
                          wlan_set_sap_user_config_freq(v415, v417, started, v393, v394, v395, v396, v397, v398, v399);
                        }
                        v23 = v415;
                        ucfg_p2p_status_start_bss(v415, v384, v385, v386, v387, v388, v389, v390, v391);
                        hdd_unsafe_channel_restart_sap(v20);
                        hdd_set_connection_in_progress(0);
                        policy_mgr_process_force_scc_for_nan(*v20);
                        LODWORD(v21) = 0;
                        goto LABEL_54;
                      }
                      mutex_unlock(v20 + 24);
                      v373 = *(unsigned __int8 *)(a1 + 8);
                      v375 = *(unsigned int *)(a1 + 248);
                      v374 = "%s: Vdev %d Start BSS failed status %d";
                    }
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      v374,
                      v365,
                      v366,
                      v367,
                      v368,
                      v369,
                      v370,
                      v371,
                      v372,
                      "wlan_hdd_cfg80211_start_bss",
                      v373,
                      v375);
                    hdd_set_connection_in_progress(0);
                    sme_get_command_q_status(v418);
                    wlansap_stop_bss(*(_QWORD *)(a1 + 272));
                    cds_get_driver_state(v376, v377, v378, v379, v380, v381, v382, v383);
                    goto LABEL_48;
                  }
                  mutex_unlock(v20 + 24);
                  hdd_set_connection_in_progress(0);
                  v98 = *(unsigned __int8 *)(a1 + 8);
                  v99 = "%s: SAP (%d) Start Bss fail";
                }
                else
                {
                  mutex_unlock(v20 + 24);
                  v98 = *(unsigned __int8 *)(a1 + 8);
                  v99 = "%s: Vdev %d Can't start BSS: set connection in progress failed";
                }
                goto LABEL_46;
              }
              mutex_unlock(v20 + 24);
              v314 = "%s: This concurrency combination is not allowed";
LABEL_194:
              qdf_trace_msg(
                0x33u,
                2u,
                v314,
                v306,
                v307,
                v308,
                v309,
                v310,
                v311,
                v312,
                v313,
                "wlan_hdd_cfg80211_start_bss");
              goto LABEL_48;
            }
            mutex_unlock(v20 + 24);
            wlansap_reset_sap_config_add_ie(a1 + 280, 6);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Vdev %d Bss Already started...Ignore the request",
              v348,
              v349,
              v350,
              v351,
              v352,
              v353,
              v354,
              v355,
              "wlan_hdd_cfg80211_start_bss",
              *(unsigned __int8 *)(a1 + 8));
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: exit",
              v356,
              v357,
              v358,
              v359,
              v360,
              v361,
              v362,
              v363,
              "wlan_hdd_cfg80211_start_bss");
            v23 = v415;
            LODWORD(v21) = 0;
LABEL_54:
            wlan_twt_concurrency_update(v20);
            if ( (v419 & 2) == 0 )
            {
              memset(&v432[1], 0, 48);
              v432[0] = ((unsigned int)v21 >> 27) & 0x10;
              if ( (unsigned int)if_mgr_deliver_event(
                                   v23,
                                   6u,
                                   (__int64)v432,
                                   v100,
                                   v101,
                                   v102,
                                   v103,
                                   v104,
                                   v105,
                                   v106,
                                   v107) )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: start bss complete failed!!",
                  v108,
                  v109,
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  v115,
                  "wlan_hdd_cfg80211_start_bss");
                LODWORD(v21) = -22;
              }
            }
            _qdf_mem_free((__int64)v420);
            goto LABEL_58;
          }
          v185 = vendor_ie_ptr_from_oui;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: WPS IE(len %d)",
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            v149,
            v150,
            "wlan_hdd_cfg80211_start_bss",
            v151 + 2);
          v152 = v185[15];
          if ( v152 == 1 )
          {
            v23 = v415;
          }
          else
          {
            v23 = v415;
            if ( v152 != 2 )
              goto LABEL_71;
          }
        }
        else
        {
          LOBYTE(v152) = 0;
        }
        *(_BYTE *)(a1 + 1409) = v152;
        goto LABEL_71;
      }
    }
    LODWORD(v21) = -22;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v21;
}
