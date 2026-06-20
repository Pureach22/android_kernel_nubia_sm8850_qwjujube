__int64 __fastcall _wlan_hdd_cfg80211_set_wifi_test_config(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v5; // x23
  __int64 v6; // x27
  __int64 v8; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x0
  __int64 v18; // x21
  __int64 v19; // x19
  __int64 config_param; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int updated; // w24
  __int64 *v30; // x22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  __int64 v40; // x4
  unsigned int v42; // w24
  unsigned int v43; // w24
  _BOOL4 v44; // w26
  const char *v45; // x24
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // w25
  const char *v56; // x2
  _BOOL4 v57; // w24
  int v58; // w9
  unsigned int v59; // w25
  __int64 v60; // x1
  __int64 v61; // x3
  unsigned int v62; // w0
  unsigned int v63; // w25
  unsigned int v64; // w24
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w25
  int v74; // w25
  const char *v75; // x2
  char v76; // w8
  __int64 v77; // x0
  __int64 v78; // x0
  unsigned int v79; // w0
  unsigned int v80; // w25
  unsigned int v81; // w24
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  unsigned int v90; // w24
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w24
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  unsigned int v116; // w24
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
  __int64 v133; // x0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  int v142; // w25
  unsigned __int16 *v143; // x26
  __int64 v144; // x8
  unsigned int v145; // w9
  unsigned __int8 v146; // w28
  unsigned __int8 v147; // w28
  unsigned __int8 v148; // w28
  __int64 v149; // x0
  unsigned int v150; // w25
  unsigned int i; // w26
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  char v160; // w25
  _BOOL4 v161; // w25
  unsigned int v162; // w24
  __int64 v163; // x8
  int v164; // w25
  __int64 v165; // x0
  __int64 v166; // x1
  unsigned int v167; // w25
  unsigned int v168; // w24
  unsigned int v169; // w24
  int v170; // w25
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  unsigned int v179; // w25
  unsigned int v180; // w25
  unsigned int v181; // w25
  int v182; // w25
  unsigned int v183; // w0
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  __int64 v192; // x0
  __int64 v193; // x2
  unsigned int v194; // w0
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  unsigned int v203; // w0
  unsigned int v204; // w4
  const char *v205; // x2
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  unsigned int v214; // w4
  double v215; // d0
  double v216; // d1
  double v217; // d2
  double v218; // d3
  double v219; // d4
  double v220; // d5
  double v221; // d6
  double v222; // d7
  char v223; // w8
  unsigned __int8 *v224; // x0
  unsigned __int8 v225; // w8
  double v226; // d0
  double v227; // d1
  double v228; // d2
  double v229; // d3
  double v230; // d4
  double v231; // d5
  double v232; // d6
  double v233; // d7
  unsigned int v234; // w4
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  unsigned int v243; // w4
  double v244; // d0
  double v245; // d1
  double v246; // d2
  double v247; // d3
  double v248; // d4
  double v249; // d5
  double v250; // d6
  double v251; // d7
  unsigned int v252; // w4
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  __int64 v261; // x2
  unsigned int v262; // w24
  unsigned int v263; // w24
  unsigned int v264; // w24
  unsigned int v265; // w25
  bool v266; // w26
  double v267; // d0
  double v268; // d1
  double v269; // d2
  double v270; // d3
  double v271; // d4
  double v272; // d5
  double v273; // d6
  double v274; // d7
  int v275; // w25
  __int64 v276; // x0
  __int64 v277; // x1
  unsigned int v278; // w24
  unsigned int v279; // w24
  double v280; // d0
  double v281; // d1
  double v282; // d2
  double v283; // d3
  double v284; // d4
  double v285; // d5
  double v286; // d6
  double v287; // d7
  int v288; // w25
  __int64 v289; // x0
  int v290; // w26
  unsigned __int8 v291; // w25
  unsigned __int16 *v292; // x28
  unsigned int v293; // w8
  __int64 v294; // x8
  unsigned __int8 v295; // w24
  unsigned int v296; // w24
  int v297; // w24
  __int64 vdev_by_user; // x0
  __int64 v299; // x25
  unsigned int v300; // w24
  unsigned int v301; // w25
  unsigned int active_vdev_bitmap; // w26
  unsigned int j; // w28
  const char *v304; // x2
  unsigned int v305; // w25
  unsigned int v306; // w2
  unsigned int v307; // w24
  unsigned int v308; // w24
  unsigned int v309; // w24
  double v310; // d0
  double v311; // d1
  double v312; // d2
  double v313; // d3
  double v314; // d4
  double v315; // d5
  double v316; // d6
  double v317; // d7
  int v318; // w8
  int v319; // w9
  unsigned __int8 v320; // w8
  unsigned __int16 *v321; // x10
  unsigned int v322; // w11
  __int64 v323; // x11
  int v324; // w26
  __int64 v325; // x23
  _WORD *v326; // x27
  __int64 v327; // x8
  unsigned int v328; // w8
  char *v329; // x25
  __int64 v330; // x8
  const char *v331; // x2
  unsigned int v332; // [xsp+8h] [xbp-358h]
  _BOOL4 v333; // [xsp+Ch] [xbp-354h]
  __int64 v334; // [xsp+10h] [xbp-350h] BYREF
  __int64 v335; // [xsp+18h] [xbp-348h]
  unsigned __int8 *v336; // [xsp+20h] [xbp-340h]
  unsigned int v337; // [xsp+28h] [xbp-338h] BYREF
  char v338[4]; // [xsp+2Ch] [xbp-334h] BYREF
  char v339[4]; // [xsp+30h] [xbp-330h] BYREF
  char v340[4]; // [xsp+34h] [xbp-32Ch] BYREF
  _QWORD v341[3]; // [xsp+38h] [xbp-328h] BYREF
  __int64 v342; // [xsp+50h] [xbp-310h]
  _QWORD v343[2]; // [xsp+58h] [xbp-308h] BYREF
  __int16 v344; // [xsp+68h] [xbp-2F8h]
  __int64 v345; // [xsp+70h] [xbp-2F0h] BYREF
  __int64 v346; // [xsp+78h] [xbp-2E8h]
  __int64 v347; // [xsp+80h] [xbp-2E0h]
  __int64 v348; // [xsp+88h] [xbp-2D8h] BYREF
  __int64 v349; // [xsp+90h] [xbp-2D0h]
  _WORD *v350; // [xsp+98h] [xbp-2C8h]
  __int64 v351; // [xsp+A0h] [xbp-2C0h]
  __int64 v352; // [xsp+A8h] [xbp-2B8h]
  __int64 v353; // [xsp+B0h] [xbp-2B0h]
  __int64 v354; // [xsp+B8h] [xbp-2A8h]
  __int64 v355; // [xsp+C0h] [xbp-2A0h]
  __int64 v356; // [xsp+C8h] [xbp-298h]
  _QWORD s[82]; // [xsp+D0h] [xbp-290h] BYREF

  s[80] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v5 = a1;
    v6 = *(_QWORD *)(a2 + 32);
    memset(s, 0, 0x280u);
    v8 = *(_QWORD *)(v6 + 55520);
    v340[0] = 0;
    v339[0] = 0;
    v338[0] = 0;
    v337 = 0;
    v342 = 0;
    memset(v341, 0, sizeof(v341));
    v335 = 0;
    v336 = nullptr;
    v334 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "__wlan_hdd_cfg80211_set_wifi_test_config",
      v6 + 296);
    v17 = _qdf_mem_malloc(0x4E4u, "__wlan_hdd_cfg80211_set_wifi_test_config", 16554);
    if ( !v17 )
    {
      updated = -12;
LABEL_13:
      _ReadStatusReg(SP_EL0);
      return updated;
    }
    v18 = *(_QWORD *)(v5 + 1552);
    v19 = v17;
    config_param = sme_get_config_param(v18, v17);
    if ( (unsigned int)hdd_get_conparam(config_param) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "__wlan_hdd_cfg80211_set_wifi_test_config");
      updated = -1;
LABEL_12:
      _qdf_mem_free(v19);
      goto LABEL_13;
    }
    v30 = (__int64 *)(v5 + 1536);
    updated = _wlan_hdd_validate_context(v5 + 1536, "__wlan_hdd_cfg80211_set_wifi_test_config");
    if ( updated )
      goto LABEL_12;
    if ( *(_DWORD *)(v5 + 3000) == 2 )
    {
      v39 = "%s: Driver Modules are closed, can not start logger";
LABEL_11:
      qdf_trace_msg(0x33u, 2u, v39, v31, v32, v33, v34, v35, v36, v37, v38, "__wlan_hdd_cfg80211_set_wifi_test_config");
      updated = -22;
      goto LABEL_12;
    }
    if ( (unsigned int)_nla_parse(s, 79, a3, a4, &wlan_hdd_wifi_test_config_policy, 31, 0) )
    {
      v39 = "%s: invalid attr";
      goto LABEL_11;
    }
    if ( s[2] )
    {
      v42 = *(unsigned __int8 *)(s[2] + 4LL);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: set addba accept req from peer value %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__wlan_hdd_cfg80211_set_wifi_test_config",
        *(unsigned __int8 *)(s[2] + 4LL));
      updated = sme_set_addba_accept(v18, *(unsigned __int8 *)(v8 + 8), v42);
      if ( updated )
        goto LABEL_12;
    }
    if ( s[5] )
    {
      v43 = *(unsigned __int8 *)(s[5] + 4LL);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: set HE MCS value 0x%0X",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__wlan_hdd_cfg80211_set_wifi_test_config",
        *(unsigned __int8 *)(s[5] + 4LL));
      updated = sme_update_he_mcs(v18, *(unsigned __int8 *)(v8 + 8), v43);
      if ( updated )
        goto LABEL_12;
    }
    v44 = s[1] != 0;
    if ( s[1] )
    {
      if ( *(_BYTE *)(s[1] + 4LL) )
      {
        if ( (unsigned int)wlan_mlme_get_wmm_mode(*v30, v338) )
        {
          v39 = "%s: Get wmm_mode failed";
          goto LABEL_11;
        }
        v46 = (unsigned __int8)v338[0];
        v45 = "%s: using wmm default value";
      }
      else
      {
        v45 = "%s: wmm is disabled";
        v46 = 2;
      }
      *(_DWORD *)(v19 + 16) = hdd_to_csr_wmm_mode(v46);
      qdf_trace_msg(0x33u, 8u, v45, v47, v48, v49, v50, v51, v52, v53, v54, "__wlan_hdd_cfg80211_set_wifi_test_config");
    }
    if ( s[3]
      && ((v55 = *(unsigned __int8 *)(s[3] + 4LL), *(_BYTE *)(s[3] + 4LL))
        ? (v56 = "%s: BA operating mode is set to auto")
        : (v56 = "%s: BA operating mode is set to Manual"),
          qdf_trace_msg(
            0x33u,
            8u,
            v56,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "__wlan_hdd_cfg80211_set_wifi_test_config"),
          wlan_get_opmode_from_vdev_id(*(_QWORD *)(v5 + 1544), *(_BYTE *)(v8 + 8)),
          sme_config_ba_mode_all_vdevs(v18, v55 == 0),
          !v55) )
    {
      updated = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 131, 0, 1);
    }
    else
    {
      updated = 0;
    }
    if ( s[4] )
    {
      v57 = *(unsigned __int8 *)(s[4] + 4LL) != 0;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: set HE fragmention to %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__wlan_hdd_cfg80211_set_wifi_test_config",
        *(unsigned __int8 *)(s[4] + 4LL) != 0);
      updated = sme_update_he_frag_supp(v18, *(unsigned __int8 *)(v8 + 8), v57);
    }
    if ( s[6] )
    {
      *(_BYTE *)(v19 + 1248) = *(_BYTE *)(s[6] + 4LL) != 0;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Set WEP/TKIP allow in HE %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__wlan_hdd_cfg80211_set_wifi_test_config");
      v44 = 1;
    }
    if ( s[7] )
    {
      if ( !s[9] )
      {
        v39 = "%s: TID is not set for ADD/DEL BA cfg";
        goto LABEL_11;
      }
      v58 = *(unsigned __int8 *)(s[7] + 4LL);
      if ( v58 != 1 )
      {
        if ( v58 != 2 )
        {
          v39 = "%s: Invalid BA session cfg";
          goto LABEL_11;
        }
LABEL_57:
        if ( s[10] )
        {
          if ( !s[11] )
          {
            v39 = "%s: AC is not set for NO ACK policy config";
            goto LABEL_11;
          }
          v63 = *(unsigned __int8 *)(s[10] + 4LL);
          v64 = *(unsigned __int8 *)(s[11] + 4LL);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Set NO_ACK to %d for ac %d",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "__wlan_hdd_cfg80211_set_wifi_test_config",
            *(unsigned __int8 *)(s[10] + 4LL),
            *(unsigned __int8 *)(s[11] + 4LL));
          updated = sme_set_no_ack_policy(v18, *(unsigned __int8 *)(v8 + 8), v63, v64);
          if ( v63 )
          {
            if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*v30, v340) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: unable to get vht_enable2x2",
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
            if ( v340[0] )
              v73 = 69;
            else
              v73 = 37;
            if ( (unsigned int)hdd_set_11ax_rate(v6 + 2688, v73, 0) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: HE MCS set failed, MCS val %0x",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v73);
          }
          else if ( (unsigned int)hdd_set_11ax_rate(v6 + 2688, 255, 0) )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: disable fixed rate failed",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "__wlan_hdd_cfg80211_set_wifi_test_config");
          }
        }
        if ( !s[53] )
          goto LABEL_80;
        v74 = *(unsigned __int8 *)(s[53] + 4LL);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Keep alive data type %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "__wlan_hdd_cfg80211_set_wifi_test_config",
          *(unsigned __int8 *)(s[53] + 4LL));
        if ( v74 == 2 )
        {
          v76 = 5;
        }
        else
        {
          if ( v74 == 1 )
          {
            updated = hdd_set_grat_arp_keepalive(v6 + 2688);
            if ( updated )
            {
              v75 = "%s: Keep alive data type set failed";
LABEL_75:
              qdf_trace_msg(
                0x33u,
                2u,
                v75,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              goto LABEL_12;
            }
LABEL_80:
            if ( s[12] )
            {
              v81 = *(unsigned __int8 *)(s[12] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Set HE LTF to %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[12] + 4LL));
              if ( (unsigned int)sme_set_auto_rate_he_ltf(v18, *(unsigned __int8 *)(v8 + 8), v81) )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to set auto rate HE LTF",
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  v88,
                  v89,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 116, v81, 1);
              if ( updated )
                goto LABEL_12;
            }
            if ( s[13] )
            {
              v90 = *(unsigned __int8 *)(s[13] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Set Tx beamformee to %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[13] + 4LL));
              if ( (unsigned int)sme_update_tx_bfee_supp(v18, *(unsigned __int8 *)(v8 + 8), v90) )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update Tx beamformee support",
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  v97,
                  v98,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = sme_update_eht_caps(v18, *(unsigned __int8 *)(v8 + 8), v90, 1, *(unsigned int *)(v6 + 2728));
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to set Tx beamformee cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[56] )
            {
              updated = sme_update_he_capabilities(
                          v18,
                          *(unsigned __int8 *)(v8 + 8),
                          *(unsigned __int8 *)(s[56] + 4LL),
                          56);
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update HE cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[57] )
            {
              updated = sme_update_he_capabilities(
                          v18,
                          *(unsigned __int8 *)(v8 + 8),
                          *(unsigned __int8 *)(s[57] + 4LL),
                          57);
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update HE cap",
                  v99,
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              else
                sme_set_vdev_ies_per_band(
                  *(_QWORD *)(v5 + 1552),
                  *(unsigned __int8 *)(v8 + 8),
                  *(unsigned int *)(v6 + 2728));
            }
            if ( s[14] )
            {
              v107 = *(unsigned __int8 *)(s[14] + 4LL);
              if ( (unsigned int)wlan_mlme_cfg_get_vht_tx_bfee_ant_supp(*v30, v339) )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: unable to get tx_bfee_ant_supp",
                  v108,
                  v109,
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  v115,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              if ( v107 >= 8 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: NSTS %d not supported, supp_val %d",
                  v108,
                  v109,
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  v115,
                  "__wlan_hdd_cfg80211_set_wifi_test_config",
                  v107,
                  (unsigned __int8)v339[0]);
                updated = -524;
                goto LABEL_12;
              }
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Set Tx beamformee NSTS to %d",
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v107);
              updated = sme_update_tx_bfee_nsts(
                          *(_QWORD *)(v5 + 1552),
                          *(unsigned __int8 *)(v8 + 8),
                          v107,
                          (unsigned __int8)v339[0]);
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to set Tx beamformee cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[20] )
            {
              v116 = *(unsigned __int8 *)(s[20] + 4LL);
              if ( *(_BYTE *)(s[20] + 4LL) )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Set HE mac padding dur to %d",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config",
                  *(unsigned __int8 *)(s[20] + 4LL));
                if ( (unsigned int)sme_cli_set_command(*(unsigned __int8 *)(v8 + 8), 143, 0, 1) )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: MU_EDCA update disable failed",
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    v124,
                    "__wlan_hdd_cfg80211_set_wifi_test_config");
                sme_set_usr_cfg_mu_edca(*(_QWORD *)(v5 + 1552), 1);
                sme_set_he_mu_edca_def_cfg(*(_QWORD *)(v5 + 1552));
                if ( (unsigned int)sme_update_mu_edca_params(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8)) )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Failed to send mu edca params",
                    v125,
                    v126,
                    v127,
                    v128,
                    v129,
                    v130,
                    v131,
                    v132,
                    "__wlan_hdd_cfg80211_set_wifi_test_config");
              }
              else
              {
                sme_cli_set_command(*(unsigned __int8 *)(v8 + 8), 143, 1, 1);
                sme_set_usr_cfg_mu_edca(*(_QWORD *)(v5 + 1552), 0);
              }
              updated = sme_update_he_trigger_frm_mac_pad(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v116);
              if ( updated )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to set Trig frame mac padding cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[21] )
            {
              v133 = *(unsigned __int8 *)(v8 + 8);
              if ( *(_BYTE *)(s[21] + 4LL) )
              {
                updated = sme_cli_set_command(v133, 143, 0, 1);
                if ( updated )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: MU_EDCA update disable failed",
                    v134,
                    v135,
                    v136,
                    v137,
                    v138,
                    v139,
                    v140,
                    v141,
                    "__wlan_hdd_cfg80211_set_wifi_test_config");
                sme_set_usr_cfg_mu_edca(*(_QWORD *)(v5 + 1552), 1);
                sme_set_he_mu_edca_def_cfg(*(_QWORD *)(v5 + 1552));
                if ( (unsigned int)sme_update_mu_edca_params(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8)) )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Failed to send mu edca params",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "__wlan_hdd_cfg80211_set_wifi_test_config");
              }
              else
              {
                updated = sme_cli_set_command(v133, 143, 1, 1);
                sme_set_usr_cfg_mu_edca(*(_QWORD *)(v5 + 1552), 0);
              }
            }
            if ( s[22] )
              updated = sme_update_he_om_ctrl_supp(
                          *(_QWORD *)(v5 + 1552),
                          *(unsigned __int8 *)(v8 + 8),
                          *(unsigned __int8 *)(s[22] + 4LL));
            if ( s[54] && (unsigned int)wlan_mlme_set_scan_probe_unicast_ra(*v30, *(_BYTE *)(s[54] + 4LL) != 0) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: unable to set unicat probe ra cfg",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
            v333 = v44;
            if ( s[33] )
            {
              v355 = 0;
              v356 = 0;
              v353 = 0;
              v354 = 0;
              v351 = 0;
              v352 = 0;
              v349 = 0;
              v350 = nullptr;
              v348 = 0;
              LODWORD(v345) = 0;
              v142 = (unsigned __int16)(*(_WORD *)s[33] - 4);
              if ( (unsigned int)v142 >= 4 )
              {
                v143 = (unsigned __int16 *)(s[33] + 4LL);
                do
                {
                  v145 = *v143;
                  if ( v145 < 4 || v142 < v145 )
                    break;
                  if ( (unsigned int)_nla_parse(
                                       &v348,
                                       8,
                                       v143 + 2,
                                       (unsigned __int16)(v145 - 4),
                                       &qca_wlan_vendor_attr_omi_tx_policy,
                                       31,
                                       0) )
                  {
                    v75 = "%s: Invalid ATTR";
                    goto LABEL_75;
                  }
                  if ( v350 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                2,
                                *((unsigned __int8 *)v350 + 4));
                  if ( v349 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                1,
                                *(unsigned __int8 *)(v349 + 4));
                  if ( v351 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                3,
                                *(unsigned __int8 *)(v351 + 4));
                  if ( v352 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                4,
                                *(unsigned __int8 *)(v352 + 4));
                  if ( v353 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                5,
                                *(unsigned __int8 *)(v353 + 4));
                  if ( v354 )
                  {
                    v146 = *(_BYTE *)(v354 + 4);
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: EHT OM ctrl Rx Nss %d",
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      v37,
                      v38,
                      "__wlan_hdd_cfg80211_set_wifi_test_config",
                      v146);
                    LODWORD(v345) = v345 & 0xFFFBFFFF | ((v146 & 1) << 18);
                  }
                  if ( v355 )
                  {
                    v147 = *(_BYTE *)(v355 + 4);
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Set EHT OM ctrl BW to %d",
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      v37,
                      v38,
                      "__wlan_hdd_cfg80211_set_wifi_test_config",
                      v147);
                    LODWORD(v345) = v345 & 0xFFF7FFFF | ((v147 & 1) << 19);
                  }
                  if ( v356 )
                  {
                    v148 = *(_BYTE *)(v356 + 4);
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: EHT OM ctrl Tx Nss %d",
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      v37,
                      v38,
                      "__wlan_hdd_cfg80211_set_wifi_test_config",
                      v148);
                    LODWORD(v345) = v345 & 0xFFEFFFFF | ((v148 & 1) << 20);
                  }
                  v144 = (*v143 + 3) & 0x1FFFC;
                  v142 -= v144;
                  v143 = (unsigned __int16 *)((char *)v143 + v144);
                }
                while ( v142 > 3 );
              }
              v149 = *(_QWORD *)(v5 + 1552);
              if ( updated )
              {
                sme_reset_he_om_ctrl(v149);
                goto LABEL_12;
              }
              updated = sme_send_he_om_ctrl_update(v149, *(unsigned __int8 *)(v8 + 8), &v345);
            }
            if ( s[30] )
              sme_reset_he_om_ctrl(*(_QWORD *)(v5 + 1552));
            if ( s[31] )
            {
              LODWORD(v348) = 0;
              v150 = *(unsigned __int8 *)(s[31] + 4LL);
              wlan_mlme_get_eht_mode(*v30, &v348);
              if ( (unsigned int)(v348 - 2) > 2 )
              {
                sme_config_su_ppdu_queue(*(unsigned __int8 *)(v8 + 8), v150 != 0);
              }
              else
              {
                for ( i = 0; i != 6; ++i )
                {
                  if ( (unsigned __int8)wlan_get_opmode_from_vdev_id(*(_QWORD *)(v5 + 1544), i) )
                  {
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: vdev_id %d is not STA",
                      v152,
                      v153,
                      v154,
                      v155,
                      v156,
                      v157,
                      v158,
                      v159,
                      "__wlan_hdd_cfg80211_set_wifi_test_config",
                      i);
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Tx SU PPDU enable %d, vdev_id %d",
                      v152,
                      v153,
                      v154,
                      v155,
                      v156,
                      v157,
                      v158,
                      v159,
                      "__wlan_hdd_cfg80211_set_wifi_test_config",
                      v150,
                      i);
                    sme_config_su_ppdu_queue(i, v150 != 0);
                  }
                }
              }
            }
            if ( s[35] )
            {
              v160 = *(_BYTE *)(s[35] + 4LL) != 0;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure 2G VHT support %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              wlan_mlme_set_vht_for_24ghz(*v30, v160);
            }
            if ( s[34] )
            {
              v161 = *(_BYTE *)(s[34] + 4LL) != 0;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure +HTC_HE support %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              sme_update_he_htc_he_supp(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v161);
            }
            if ( s[49] )
            {
              v162 = *(unsigned __int8 *)(s[49] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure Punctured preamble Rx %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[49] + 4LL));
              updated = sme_update_he_capabilities(v18, *(unsigned __int8 *)(v8 + 8), v162, 49);
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update HE cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            v163 = s[36];
            if ( s[36] )
            {
              if ( (*(_BYTE *)(v5 + 3216) & 1) == 0 )
              {
                *(_BYTE *)(v5 + 3216) = 1;
                qdf_runtime_pm_prevent_suspend((__int64 *)(v5 + 3208));
                v163 = s[36];
              }
              v164 = *(unsigned __int8 *)(v163 + 4);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure HE testbed defaults %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(v163 + 4));
              v165 = *(_QWORD *)(v5 + 1552);
              v166 = *(unsigned __int8 *)(v8 + 8);
              if ( v164 )
                sme_set_he_testbed_def(v165, v166);
              else
                sme_reset_he_caps(v165, v166);
            }
            if ( s[32] )
            {
              v167 = *(unsigned __int8 *)(s[32] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure Action frame Tx in TB PPDU %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[32] + 4LL));
              sme_config_action_tx_in_tb_ppdu(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v167);
            }
            if ( s[23] )
            {
              updated = hdd_test_config_twt_setup_session(v6 + 2688, s);
              if ( updated )
                goto LABEL_12;
            }
            if ( s[24] )
            {
              updated = hdd_test_config_twt_terminate_session(v6 + 2688, s);
              if ( updated )
                goto LABEL_12;
            }
            if ( s[37] )
            {
              v168 = *(unsigned __int8 *)(s[37] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: twt_request: val %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[37] + 4LL));
              updated = sme_update_he_twt_req_support(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v168);
            }
            if ( s[45] )
            {
              v169 = *(unsigned __int8 *)(s[45] + 4LL);
              v170 = *(_DWORD *)(cfg_psoc_get_values(*v30) + 7648);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: fullbw_ulmumimo: cfg %d, ini %d",
                v171,
                v172,
                v173,
                v174,
                v175,
                v176,
                v177,
                v178,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v169,
                (unsigned __int8)v170);
              if ( v169 )
              {
                if ( (v170 & 0xFC) == 0 )
                  v169 = 0x3030101u >> (8 * (v170 & 3));
              }
              else
              {
                v169 = 2 * ((v170 & 0xFE) == 2);
              }
              updated = sme_update_he_full_ul_mumimo(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v169);
            }
            if ( s[48] )
            {
              v179 = *(unsigned __int8 *)(s[48] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: disable Tx cfg: val %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[48] + 4LL));
              sme_set_cfg_disable_tx(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v179);
            }
            if ( s[38] )
            {
              v180 = *(unsigned __int8 *)(s[38] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: pmf cfg: val %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[38] + 4LL));
              sme_set_pmf_wep_cfg(*(_QWORD *)(v5 + 1552), v180);
            }
            if ( s[46] )
            {
              v337 = *(unsigned __int16 *)(s[46] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: bss max idle period %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              sme_set_bss_max_idle_period(*(_QWORD *)(v5 + 1552), v337);
            }
            if ( s[55] )
            {
              if ( *(_BYTE *)(s[55] + 4LL) )
                ucfg_mlme_get_sta_keep_alive_period(*v30, (int *)&v337);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: bss max idle period %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v337);
              sme_set_bss_max_idle_period(*(_QWORD *)(v5 + 1552), v337);
            }
            if ( s[39] )
            {
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: Send disassoc mgmt frame",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              sme_send_disassoc_req_frame(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v8 + 308, 1, 0);
            }
            if ( s[47] )
            {
              v181 = *(unsigned __int8 *)(s[47] + 4LL);
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: RU 242 tone Tx enable: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[47] + 4LL));
              sme_set_ru_242_tone_tx_cfg(*(_QWORD *)(v5 + 1552), v181);
              if ( v181 )
                hdd_update_channel_width(v8, 0, 0, 255, 0);
            }
            if ( s[52] )
            {
              v182 = *(unsigned __int8 *)(s[52] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: EU SU PPDU type Tx enable: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[52] + 4LL));
              if ( v182 )
              {
                hdd_update_channel_width(v8, 0, 0, 255, 0);
                hdd_set_tx_stbc(v8, 0);
                hdd_set_11ax_rate(v6 + 2688, 1024, 0);
                v183 = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 107, 1, 1);
                if ( v183 )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: failed to set HE_RANGE_EXT, %d",
                    v184,
                    v185,
                    v186,
                    v187,
                    v188,
                    v189,
                    v190,
                    v191,
                    "__wlan_hdd_cfg80211_set_wifi_test_config",
                    v183);
                v192 = *(unsigned __int8 *)(v8 + 8);
                v193 = 1;
              }
              else
              {
                hdd_update_channel_width(v8, 3, 1, 255, 0);
                hdd_set_tx_stbc(v8, 1);
                hdd_set_11ax_rate(v6 + 2688, 0xFFFF, 0);
                v194 = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 107, 0, 1);
                if ( v194 )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: failed to set HE_RANGE_EXT, %d",
                    v195,
                    v196,
                    v197,
                    v198,
                    v199,
                    v200,
                    v201,
                    v202,
                    "__wlan_hdd_cfg80211_set_wifi_test_config",
                    v194);
                v192 = *(unsigned __int8 *)(v8 + 8);
                v193 = 0;
              }
              v203 = wma_cli_set_command(v192, 165, v193, 1);
              v40 = v203;
              if ( v203 )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: fail to set NON_DATA_HE_RANGE_EXT %d",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config",
                  v203);
            }
            if ( s[40] )
            {
              LOBYTE(v334) = *(_BYTE *)(v8 + 8);
              v204 = *(unsigned __int8 *)(s[40] + 4LL);
              HIDWORD(v334) = v204;
              if ( v204 >= 3 )
              {
                v205 = "%s: Invalid RSNXE override %d";
LABEL_337:
                qdf_trace_msg(
                  0x33u,
                  8u,
                  v205,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
                goto LABEL_12;
              }
              LODWORD(v335) = 0;
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: send wfa test config RXNE used %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = wlan_send_wfatest_cmd(
                          *(_QWORD *)(v8 + 32),
                          (__int64)&v334,
                          v206,
                          v207,
                          v208,
                          v209,
                          v210,
                          v211,
                          v212,
                          v213);
            }
            if ( s[41] )
            {
              LOBYTE(v334) = *(_BYTE *)(v8 + 8);
              v214 = *(unsigned __int8 *)(s[41] + 4LL);
              HIDWORD(v334) = v214;
              if ( v214 >= 2 )
              {
                v205 = "%s: Invalid CSA config %d";
                goto LABEL_337;
              }
              LODWORD(v335) = 1;
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: send wfa test config CSA used %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = wlan_send_wfatest_cmd(
                          *(_QWORD *)(v8 + 32),
                          (__int64)&v334,
                          v215,
                          v216,
                          v217,
                          v218,
                          v219,
                          v220,
                          v221,
                          v222);
            }
            if ( s[51] )
            {
              updated = hdd_test_config_6ghz_security_test_mode(v5 + 1536);
              if ( updated )
                goto LABEL_12;
            }
            if ( s[42] )
            {
              v349 = 0;
              v350 = nullptr;
              v223 = *(_BYTE *)(v8 + 8);
              v348 = 0;
              LOBYTE(v334) = v223;
              LODWORD(v335) = 2;
              if ( (unsigned int)wlan_cfg80211_nla_parse_nested(
                                   (__int64)&v348,
                                   2,
                                   (_WORD *)s[42],
                                   (__int64)&wlan_oci_override_policy) )
              {
                v205 = "%s: Failed to parse OCI override";
                goto LABEL_337;
              }
              if ( !v349 || !v350 )
              {
                v205 = "%s: Invalid ATTR FRAME_TYPE/FREQUENCY";
                goto LABEL_337;
              }
              v224 = (unsigned __int8 *)_qdf_mem_malloc(8u, "__wlan_hdd_cfg80211_set_wifi_test_config", 17372);
              v336 = v224;
              if ( !v224 )
              {
                v75 = "%s: Failed to alloc memory for ocv param";
                goto LABEL_75;
              }
              v225 = *(_BYTE *)(v349 + 4) - 1;
              if ( v225 >= 4u )
              {
                v304 = "%s: Invalid frame type for ocv test config %d";
              }
              else
              {
                *v224 = 0x8040201u >> (8 * (v225 & 0x1F));
                *((_DWORD *)v336 + 1) = *((_DWORD *)v350 + 1);
                if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v336 + 1))
                  || wlan_reg_is_5ghz_ch_freq(*((_DWORD *)v336 + 1))
                  || wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v336 + 1)) )
                {
                  qdf_trace_msg(
                    0x33u,
                    4u,
                    "%s: send wfa test config OCV frame type %d freq %d",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "__wlan_hdd_cfg80211_set_wifi_test_config",
                    *v336,
                    *((unsigned int *)v336 + 1));
                  updated = wlan_send_wfatest_cmd(
                              *(_QWORD *)(v8 + 32),
                              (__int64)&v334,
                              v226,
                              v227,
                              v228,
                              v229,
                              v230,
                              v231,
                              v232,
                              v233);
                  _qdf_mem_free((__int64)v336);
                  goto LABEL_234;
                }
                v304 = "%s: Invalid Freq %d";
              }
              qdf_trace_msg(
                0x33u,
                8u,
                v304,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              _qdf_mem_free((__int64)v336);
              goto LABEL_12;
            }
LABEL_234:
            if ( s[43] )
            {
              LOBYTE(v334) = *(_BYTE *)(v8 + 8);
              v234 = *(unsigned __int8 *)(s[43] + 4LL);
              HIDWORD(v334) = v234;
              if ( v234 >= 2 )
              {
                v205 = "%s: Invalid SA query timeout config %d";
                goto LABEL_337;
              }
              LODWORD(v335) = 3;
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: send wfa test config SAquery %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = wlan_send_wfatest_cmd(
                          *(_QWORD *)(v8 + 32),
                          (__int64)&v334,
                          v235,
                          v236,
                          v237,
                          v238,
                          v239,
                          v240,
                          v241,
                          v242);
            }
            if ( s[44] && *(_DWORD *)(v6 + 2728) == 1 )
            {
              LOBYTE(v334) = *(_BYTE *)(v8 + 8);
              v243 = *(unsigned __int8 *)(s[44] + 4LL);
              HIDWORD(v334) = v243;
              if ( v243 >= 2 )
              {
                v205 = "%s: Invalid FILS_DISCV_FRAMES config %d";
                goto LABEL_337;
              }
              LODWORD(v335) = 4;
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: send wfa FILS_DISCV_FRAMES TX config %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = wlan_send_wfatest_cmd(
                          *(_QWORD *)(v8 + 32),
                          (__int64)&v334,
                          v244,
                          v245,
                          v246,
                          v247,
                          v248,
                          v249,
                          v250,
                          v251);
            }
            if ( s[50] )
            {
              LOBYTE(v334) = *(_BYTE *)(v8 + 8);
              v252 = *(unsigned __int8 *)(s[50] + 4LL);
              HIDWORD(v334) = v252;
              if ( v252 >= 2 )
              {
                v205 = "%s: Invalid RSNXE_IGNORE config %d";
                goto LABEL_337;
              }
              LODWORD(v335) = 5;
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: send wfa WFA_IGNORE_H2E_RSNXE config %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = wlan_send_wfatest_cmd(
                          *(_QWORD *)(v8 + 32),
                          (__int64)&v334,
                          v253,
                          v254,
                          v255,
                          v256,
                          v257,
                          v258,
                          v259,
                          v260);
            }
            if ( s[58] && !*(_DWORD *)(v6 + 2728) )
            {
              hdd_test_config_emlsr_mode((__int64 *)(v5 + 1536), *(_BYTE *)(s[58] + 4LL) != 0);
              updated = 0;
            }
            if ( s[59] )
            {
              if ( *(_BYTE *)(s[59] + 4LL) )
                v261 = 100;
              else
                v261 = 0;
              updated = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 97, v261, 2);
            }
            if ( s[60] )
            {
              v262 = *(unsigned __int8 *)(s[60] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure Tx BF < 80 MHz: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[60] + 4LL));
              updated = sme_update_eht_caps(v18, *(unsigned __int8 *)(v8 + 8), v262, 2, *(unsigned int *)(v6 + 2728));
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update EHT Tx BFEE cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[61] )
            {
              v263 = *(unsigned __int8 *)(s[61] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure Tx BF for 160 MHz: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[61] + 4LL));
              updated = sme_update_eht_caps(v18, *(unsigned __int8 *)(v8 + 8), v263, 3, *(unsigned int *)(v6 + 2728));
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update EHT Tx BFEE cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[62] )
            {
              v264 = *(unsigned __int8 *)(s[62] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure Tx BF for 320 MHz: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[62] + 4LL));
              updated = sme_update_eht_caps(v18, *(unsigned __int8 *)(v8 + 8), v264, 4, *(unsigned int *)(v6 + 2728));
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update EHT Tx BFEE cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[63] && !*(_DWORD *)(v6 + 2728) )
            {
              v265 = *(unsigned __int8 *)(s[63] + 4LL);
              v266 = *(_BYTE *)(s[63] + 4LL) != 0;
              wlan_vdev_obj_lock(*(_QWORD *)(v8 + 32));
              *(_DWORD *)(*(_QWORD *)(v8 + 32) + 48LL) = *(_DWORD *)(*(_QWORD *)(v8 + 32) + 48LL) & 0xFFFFF7FF
                                                       | (v266 << 11);
              wlan_vdev_obj_unlock(*(_QWORD *)(v8 + 32));
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Sta profile in Probe req frame: %d",
                v267,
                v268,
                v269,
                v270,
                v271,
                v272,
                v273,
                v274,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v265);
            }
            if ( s[64] )
            {
              v275 = *(unsigned __int8 *)(s[64] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure EHT testbed defaults %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[64] + 4LL));
              v276 = *(_QWORD *)(v5 + 1552);
              v277 = *(unsigned __int8 *)(v8 + 8);
              if ( v275 )
                sme_set_eht_testbed_def(v276, v277);
              else
                sme_reset_eht_caps(v276, v277);
              sme_set_vdev_ies_per_band(
                *(_QWORD *)(v5 + 1552),
                *(unsigned __int8 *)(v8 + 8),
                *(unsigned int *)(v6 + 2728));
            }
            if ( s[65] )
            {
              sme_update_eht_cap_mcs(
                *(_QWORD *)(v5 + 1552),
                *(unsigned __int8 *)(v8 + 8),
                *(unsigned __int8 *)(s[65] + 4LL));
              sme_set_vdev_ies_per_band(
                *(_QWORD *)(v5 + 1552),
                *(unsigned __int8 *)(v8 + 8),
                *(unsigned int *)(v6 + 2728));
            }
            if ( s[66] )
            {
              v278 = *(unsigned __int8 *)(s[66] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure TB sounding feedback rate limit: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[66] + 4LL));
              updated = sme_update_eht_caps(v18, *(unsigned __int8 *)(v8 + 8), v278, 5, *(unsigned int *)(v6 + 2728));
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update EHT Tx BFEE cap",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[67] )
            {
              v279 = *(unsigned __int8 *)(s[67] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: EHT OM control support: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[67] + 4LL));
              if ( (unsigned int)sme_update_he_htc_he_supp(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), 1) )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Could not set htc_he",
                  v280,
                  v281,
                  v282,
                  v283,
                  v284,
                  v285,
                  v286,
                  v287,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = sme_update_eht_om_ctrl_supp(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v279);
              if ( updated )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Could not update EHT OM control fields",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[68] )
            {
              if ( !*(_DWORD *)(v6 + 2728) )
              {
                v288 = *(unsigned __int8 *)(s[68] + 4LL);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Configure EMLSR padding delay subfield to %d",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config",
                  *(unsigned __int8 *)(s[68] + 4LL));
                if ( v288 )
                  wlan_mlme_cfg_set_emlsr_pad_delay(*v30, v288);
              }
            }
            if ( s[69] && !*(_DWORD *)(v6 + 2728) )
            {
              v301 = *(unsigned __int8 *)(s[69] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Send vdev pause on ML sta vdev for %d beacon periods",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[69] + 4LL));
              active_vdev_bitmap = policy_mgr_get_active_vdev_bitmap(*v30);
              for ( j = 0; j != 32; ++j )
              {
                if ( ((active_vdev_bitmap >> j) & 1) != 0 )
                {
                  updated = sme_send_vdev_pause_for_bcn_period(v18, j, v301);
                  if ( updated )
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Failed to send vdev pause",
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      v37,
                      v38,
                      "__wlan_hdd_cfg80211_set_wifi_test_config");
                }
              }
            }
            if ( s[70] )
            {
              v348 = 0;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Send EHT MLO STR TX indication to FW",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v40);
              v289 = *(unsigned __int8 *)(v8 + 8);
              v348 = 0x1000002A4LL;
              updated = sme_send_unit_test_cmd(v289, 72, 2, &v348);
              if ( updated )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to send STR TX indication",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[71] )
            {
              v290 = (unsigned __int16)(*(_WORD *)s[71] - 4);
              if ( (unsigned int)v290 >= 4 )
              {
                v291 = 0;
                v292 = (unsigned __int16 *)(s[71] + 4LL);
                do
                {
                  v293 = *v292;
                  if ( v293 < 4 || v290 < v293 )
                    break;
                  if ( v293 != 5 )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: len is not correct for idx %d",
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      v37,
                      v38,
                      "__wlan_hdd_cfg80211_set_wifi_test_config",
                      v291);
                    goto LABEL_12;
                  }
                  v332 = *((unsigned __int8 *)v292 + 4);
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: link id[%d]: %d",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "__wlan_hdd_cfg80211_set_wifi_test_config",
                    v291);
                  wlan_hdd_set_mlo_ps(v6 + 2688, 1, 0, v332);
                  ++v291;
                  v294 = (*v292 + 3) & 0x1FFFC;
                  v290 -= v294;
                  v292 = (unsigned __int16 *)((char *)v292 + v294);
                }
                while ( v290 > 3 );
              }
              wlan_hdd_set_listen_interval(v5 + 1536, v6 + 2688);
            }
            if ( s[72] )
            {
              v295 = *(_BYTE *)(s[72] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: MLD ID in ML probe request: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v295);
              updated = wlan_mlme_set_eht_mld_id(*v30, v295);
              if ( updated )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to set MLD ID",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[73] )
            {
              v296 = *(unsigned __int8 *)(s[73] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: SCS traffic description support: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[73] + 4LL));
              updated = sme_update_eht_scs_traffic_desc_support(
                          *(_QWORD *)(v5 + 1552),
                          *(unsigned __int8 *)(v8 + 8),
                          v296);
              if ( updated )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to set SCS traffic desc support",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[74] && *(_DWORD *)(v6 + 2728) == 3 )
            {
              v297 = *(unsigned __int8 *)(s[74] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Restrict CSA params %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[74] + 4LL));
              vdev_by_user = _hdd_objmgr_get_vdev_by_user(v8, 6, "__wlan_hdd_cfg80211_set_wifi_test_config");
              if ( vdev_by_user )
              {
                v299 = vdev_by_user;
                v300 = ucfg_p2p_force_restrict_dfs_go_csa(vdev_by_user, v297 != 0);
                _hdd_objmgr_put_vdev_by_user(v299, 6, "__wlan_hdd_cfg80211_set_wifi_test_config");
              }
              else
              {
                v300 = 4;
              }
              updated = qdf_status_to_os_return(v300);
            }
            if ( s[75] )
            {
              v305 = *(unsigned __int8 *)(s[75] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Add %d random PMKID to the assoc request",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[75] + 4LL));
              if ( v305 <= 0xC )
                v306 = v305;
              else
                v306 = 0;
              wlan_crypto_set_vdev_param(*(_QWORD *)(v8 + 32), 9u, v306);
            }
            if ( s[76] )
            {
              v307 = *(unsigned __int8 *)(s[76] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure Triggered SU Beamforming Feedback: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[76] + 4LL));
              updated = sme_update_eht_caps(v18, *(unsigned __int8 *)(v8 + 8), v307, 6, *(unsigned int *)(v6 + 2728));
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update Triggered SU Beamforming Feedback",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[77] )
            {
              v308 = *(unsigned __int8 *)(s[77] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Configure extra EHT-LTF: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[77] + 4LL));
              updated = sme_update_eht_caps(v18, *(unsigned __int8 *)(v8 + 8), v308, 7, *(unsigned int *)(v6 + 2728));
              if ( updated )
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Failed to update extra EHT-LTF",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( s[78] )
            {
              v309 = *(unsigned __int8 *)(s[78] + 4LL);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: BTM request reject: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                *(unsigned __int8 *)(s[78] + 4LL));
              updated = sme_set_btm_req_reject(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v309);
              if ( updated )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to set BTM reject config",
                  v310,
                  v311,
                  v312,
                  v313,
                  v314,
                  v315,
                  v316,
                  v317,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( !s[79] )
            {
              if ( !v333 )
                goto LABEL_12;
LABEL_374:
              sme_update_config(v18, v19);
              goto LABEL_12;
            }
            v350 = nullptr;
            v351 = 0;
            v348 = 0;
            v349 = 0;
            v346 = 0;
            v347 = 0;
            v345 = 0;
            v344 = 0;
            v343[0] = 0;
            v343[1] = 0;
            qdf_mem_set(v343, 0x12u, 0);
            if ( (unsigned int)wlan_cfg80211_nla_parse_nested(
                                 (__int64)&v348,
                                 3,
                                 (_WORD *)s[79],
                                 (__int64)&wlan_btm_req_resp_policy) )
            {
              v205 = "%s: Failed to parse btm request response";
              goto LABEL_337;
            }
            if ( !v349 )
            {
              v205 = "%s: Response type not found";
              goto LABEL_337;
            }
            v318 = *(unsigned __int8 *)(v349 + 4);
            if ( (unsigned int)(v318 - 2) >= 2 )
            {
              if ( *(_BYTE *)(v349 + 4) )
              {
                if ( v318 == 1 )
                {
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: link reconfig response requested",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "__wlan_hdd_cfg80211_set_wifi_test_config");
                  wlan_mlme_set_btm_abridge_flag(*v30, 0);
                  wlan_mlme_set_t2lm_negotiation_supported(*v30, 0);
                }
                else
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Invalid response type",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "__wlan_hdd_cfg80211_set_wifi_test_config");
                }
              }
              else
              {
                qdf_mem_set(v343, 0x12u, 0);
                wlan_mlme_update_mlo_recfg_info(*v30, *(unsigned __int8 *)(v8 + 8), (unsigned __int8 *)v343);
              }
            }
            if ( *(_BYTE *)(v349 + 4) != 1 )
            {
LABEL_373:
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: BTM_REQ_RESP_DONE",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              if ( !v333 )
                goto LABEL_12;
              goto LABEL_374;
            }
            if ( v350 )
            {
              v319 = (unsigned __int16)(*v350 - 4);
              v320 = v343[0];
              if ( (unsigned int)v319 >= 4 )
              {
                v321 = v350 + 2;
                do
                {
                  v322 = *v321;
                  if ( v322 < 4 )
                    break;
                  if ( v319 < v322 )
                    break;
                  LOBYTE(v343[0]) = ++v320;
                  v323 = (*v321 + 3) & 0x1FFFC;
                  v319 -= v323;
                  v321 = (unsigned __int16 *)((char *)v321 + v323);
                }
                while ( v319 > 3 );
              }
              if ( v320 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: number of frames to send Link reconfig request: %d",
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config",
                  v320);
                v324 = (unsigned __int16)(*v350 - 4);
                if ( (unsigned int)v324 >= 4 )
                {
                  v325 = 0;
                  v326 = v350 + 2;
                  while ( 1 )
                  {
                    v328 = (unsigned __int16)*v326;
                    if ( v328 < 4 || v324 < v328 )
                      break;
                    a1 = wlan_cfg80211_nla_parse_nested(
                           (__int64)&v345,
                           2,
                           v326,
                           (__int64)&wlan_reconfig_frame_info_policy);
                    if ( (_DWORD)a1 )
                    {
                      v75 = "%s: nla_parse failed";
                      goto LABEL_75;
                    }
                    if ( v325 == 4 )
                      goto LABEL_377;
                    v329 = (char *)v343 + 2 * v325;
                    v330 = v346;
                    *((_WORD *)v329 + 1) = 0;
                    *((_WORD *)v329 + 5) = 0;
                    if ( v330 )
                    {
                      *((_WORD *)v329 + 1) = *(_WORD *)(v330 + 4);
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: add_link_bm[%d]: %d",
                        v31,
                        v32,
                        v33,
                        v34,
                        v35,
                        v36,
                        v37,
                        v38,
                        "__wlan_hdd_cfg80211_set_wifi_test_config",
                        (unsigned int)v325);
                    }
                    if ( v347 )
                    {
                      *((_WORD *)v329 + 5) = *(_WORD *)(v347 + 4);
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: delete_link_bm[%d]: %d",
                        v31,
                        v32,
                        v33,
                        v34,
                        v35,
                        v36,
                        v37,
                        v38,
                        "__wlan_hdd_cfg80211_set_wifi_test_config",
                        (unsigned int)v325);
                    }
                    ++v325;
                    v327 = ((unsigned __int16)*v326 + 3) & 0x1FFFC;
                    v324 -= v327;
                    v326 = (_WORD *)((char *)v326 + v327);
                    if ( v324 <= 3 )
                      goto LABEL_372;
                  }
                }
                goto LABEL_372;
              }
              v331 = "%s: reconfig info not found";
            }
            else
            {
              v331 = "%s: QCA_WLAN_VENDOR_ATTR_BTM_REQ_RESP_RECONFIG_FRAME_INFO not present";
            }
            qdf_trace_msg(
              0x33u,
              8u,
              v331,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "__wlan_hdd_cfg80211_set_wifi_test_config");
LABEL_372:
            wlan_mlme_update_mlo_recfg_info(*v30, *(unsigned __int8 *)(v8 + 8), (unsigned __int8 *)v343);
            goto LABEL_373;
          }
          v76 = 1;
        }
        v77 = *(_QWORD *)(v5 + 1536);
        LOBYTE(v341[0]) = v76;
        ucfg_mlme_get_sta_keep_alive_period(v77, (int *)v341 + 1);
        v78 = *(_QWORD *)(v5 + 1552);
        BYTE4(v342) = *(_BYTE *)(v8 + 8);
        v79 = sme_set_keep_alive(v78, BYTE4(v342), v341);
        if ( v79 )
        {
          v80 = v79;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to set keepalive",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "__wlan_hdd_cfg80211_set_wifi_test_config");
          updated = qdf_status_to_os_return(v80);
          goto LABEL_12;
        }
        goto LABEL_80;
      }
      if ( s[8] )
        v61 = *(unsigned __int16 *)(s[8] + 4LL);
      else
        v61 = 0;
      v62 = sme_send_addba_req(v18, *(unsigned __int8 *)(v8 + 8), *(unsigned __int8 *)(s[9] + 4LL), v61);
    }
    else
    {
      if ( !s[8] )
        goto LABEL_57;
      v59 = *(unsigned __int16 *)(s[8] + 4LL);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: set buff size to %d for all tids",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__wlan_hdd_cfg80211_set_wifi_test_config",
        *(unsigned __int16 *)(s[8] + 4LL));
      updated = sme_set_ba_buff_size(v18, *(unsigned __int8 *)(v8 + 8), v59);
      if ( updated )
        goto LABEL_12;
      if ( v59 <= 0x200 )
      {
        if ( v59 <= 0x100 )
        {
          if ( v59 <= 0x40 )
            v60 = 2;
          else
            v60 = 3;
        }
        else
        {
          v60 = 5;
        }
      }
      else
      {
        v60 = 6;
      }
      sme_config_ba_mode_all_vdevs(v18, v60);
      v62 = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 1, v59, 3);
    }
    updated = v62;
    goto LABEL_57;
  }
  __break(0x800u);
LABEL_377:
  __break(0x5512u);
  return hdd_test_config_6ghz_security_test_mode(a1);
}
