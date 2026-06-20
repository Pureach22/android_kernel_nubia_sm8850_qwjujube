__int64 __fastcall _wlan_hdd_cfg80211_set_wifi_test_config(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v5; // x22
  __int64 v6; // x27
  __int64 v8; // x23
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x0
  __int64 v18; // x20
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
  __int64 *v30; // x21
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
  unsigned int v99; // w24
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  unsigned int v108; // w24
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x0
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  int v134; // w25
  unsigned __int16 *v135; // x26
  __int64 v136; // x8
  unsigned int v137; // w9
  unsigned __int8 v138; // w28
  unsigned __int8 v139; // w28
  unsigned __int8 v140; // w28
  __int64 v141; // x0
  char v142; // w25
  _BOOL4 v143; // w25
  unsigned int v144; // w24
  __int64 v145; // x8
  int v146; // w25
  __int64 v147; // x0
  __int64 v148; // x1
  unsigned int v149; // w25
  unsigned int v150; // w24
  unsigned int v151; // w24
  int v152; // w25
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  unsigned int v161; // w25
  unsigned int v162; // w25
  unsigned int v163; // w25
  int v164; // w25
  unsigned int v165; // w0
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  __int64 v174; // x0
  __int64 v175; // x2
  unsigned int v176; // w0
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  unsigned int v185; // w0
  unsigned int v186; // w4
  const char *v187; // x2
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  unsigned int v196; // w4
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  char v205; // w8
  unsigned __int8 *v206; // x0
  unsigned __int8 v207; // w8
  double v208; // d0
  double v209; // d1
  double v210; // d2
  double v211; // d3
  double v212; // d4
  double v213; // d5
  double v214; // d6
  double v215; // d7
  unsigned int v216; // w4
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  unsigned int v225; // w4
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
  __int64 v243; // x2
  unsigned int v244; // w25
  bool v245; // w26
  double v246; // d0
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  __int64 v254; // x0
  int v255; // w25
  unsigned __int8 v256; // w28
  unsigned __int16 *v257; // x26
  unsigned int v258; // w8
  __int64 v259; // x8
  double v260; // d0
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  int v268; // w24
  __int64 vdev_by_user; // x0
  __int64 v270; // x25
  unsigned int v271; // w24
  const char *v272; // x2
  unsigned int v273; // w25
  unsigned int v274; // w2
  unsigned int v275; // w24
  double v276; // d0
  double v277; // d1
  double v278; // d2
  double v279; // d3
  double v280; // d4
  double v281; // d5
  double v282; // d6
  double v283; // d7
  int v284; // w8
  int v285; // w9
  unsigned __int8 v286; // w8
  unsigned __int16 *v287; // x10
  unsigned int v288; // w11
  __int64 v289; // x11
  int v290; // w26
  __int64 v291; // x21
  _WORD *v292; // x25
  __int64 v293; // x8
  unsigned int v294; // w8
  char *v295; // x27
  __int64 v296; // x8
  const char *v297; // x2
  _BOOL4 v298; // [xsp+Ch] [xbp-354h]
  __int64 v299; // [xsp+10h] [xbp-350h] BYREF
  __int64 v300; // [xsp+18h] [xbp-348h]
  unsigned __int8 *v301; // [xsp+20h] [xbp-340h]
  unsigned int v302; // [xsp+28h] [xbp-338h] BYREF
  char v303[4]; // [xsp+2Ch] [xbp-334h] BYREF
  char v304[4]; // [xsp+30h] [xbp-330h] BYREF
  char v305[4]; // [xsp+34h] [xbp-32Ch] BYREF
  _QWORD v306[3]; // [xsp+38h] [xbp-328h] BYREF
  __int64 v307; // [xsp+50h] [xbp-310h]
  _QWORD v308[2]; // [xsp+58h] [xbp-308h] BYREF
  __int16 v309; // [xsp+68h] [xbp-2F8h]
  __int64 v310; // [xsp+70h] [xbp-2F0h] BYREF
  __int64 v311; // [xsp+78h] [xbp-2E8h]
  __int64 v312; // [xsp+80h] [xbp-2E0h]
  __int64 v313; // [xsp+88h] [xbp-2D8h] BYREF
  __int64 v314; // [xsp+90h] [xbp-2D0h]
  _WORD *v315; // [xsp+98h] [xbp-2C8h]
  __int64 v316; // [xsp+A0h] [xbp-2C0h]
  __int64 v317; // [xsp+A8h] [xbp-2B8h]
  __int64 v318; // [xsp+B0h] [xbp-2B0h]
  __int64 v319; // [xsp+B8h] [xbp-2A8h]
  __int64 v320; // [xsp+C0h] [xbp-2A0h]
  __int64 v321; // [xsp+C8h] [xbp-298h]
  _QWORD s[82]; // [xsp+D0h] [xbp-290h] BYREF

  s[80] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v5 = a1;
    v6 = *(_QWORD *)(a2 + 32);
    memset(s, 0, 0x280u);
    v8 = *(_QWORD *)(v6 + 55512);
    v305[0] = 0;
    v304[0] = 0;
    v303[0] = 0;
    v302 = 0;
    v307 = 0;
    memset(v306, 0, sizeof(v306));
    v300 = 0;
    v301 = nullptr;
    v299 = 0;
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
        if ( (unsigned int)wlan_mlme_get_wmm_mode(*v30, v303) )
        {
          v39 = "%s: Get wmm_mode failed";
          goto LABEL_11;
        }
        v46 = (unsigned __int8)v303[0];
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
            if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*v30, v305) )
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
            if ( v305[0] )
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
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = 0;
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
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  v97,
                  v98,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              else
                sme_set_vdev_ies_per_band(
                  *(_QWORD *)(v5 + 1552),
                  *(unsigned __int8 *)(v8 + 8),
                  *(unsigned int *)(v6 + 2728));
            }
            if ( s[14] )
            {
              v99 = *(unsigned __int8 *)(s[14] + 4LL);
              if ( (unsigned int)wlan_mlme_cfg_get_vht_tx_bfee_ant_supp(*v30, v304) )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: unable to get tx_bfee_ant_supp",
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              if ( v99 >= 8 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: NSTS %d not supported, supp_val %d",
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  "__wlan_hdd_cfg80211_set_wifi_test_config",
                  v99,
                  (unsigned __int8)v304[0]);
                updated = -524;
                goto LABEL_12;
              }
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Set Tx beamformee NSTS to %d",
                v100,
                v101,
                v102,
                v103,
                v104,
                v105,
                v106,
                v107,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v99);
              updated = sme_update_tx_bfee_nsts(
                          *(_QWORD *)(v5 + 1552),
                          *(unsigned __int8 *)(v8 + 8),
                          v99,
                          (unsigned __int8)v304[0]);
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
              v108 = *(unsigned __int8 *)(s[20] + 4LL);
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
                    v109,
                    v110,
                    v111,
                    v112,
                    v113,
                    v114,
                    v115,
                    v116,
                    "__wlan_hdd_cfg80211_set_wifi_test_config");
                sme_set_usr_cfg_mu_edca(*(_QWORD *)(v5 + 1552), 1);
                sme_set_he_mu_edca_def_cfg(*(_QWORD *)(v5 + 1552));
                if ( (unsigned int)sme_update_mu_edca_params(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8)) )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Failed to send mu edca params",
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    v124,
                    "__wlan_hdd_cfg80211_set_wifi_test_config");
              }
              else
              {
                sme_cli_set_command(*(unsigned __int8 *)(v8 + 8), 143, 1, 1);
                sme_set_usr_cfg_mu_edca(*(_QWORD *)(v5 + 1552), 0);
              }
              updated = sme_update_he_trigger_frm_mac_pad(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v108);
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
              v125 = *(unsigned __int8 *)(v8 + 8);
              if ( *(_BYTE *)(s[21] + 4LL) )
              {
                updated = sme_cli_set_command(v125, 143, 0, 1);
                if ( updated )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: MU_EDCA update disable failed",
                    v126,
                    v127,
                    v128,
                    v129,
                    v130,
                    v131,
                    v132,
                    v133,
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
                updated = sme_cli_set_command(v125, 143, 1, 1);
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
            v298 = v44;
            if ( s[33] )
            {
              v320 = 0;
              v321 = 0;
              v318 = 0;
              v319 = 0;
              v316 = 0;
              v317 = 0;
              v314 = 0;
              v315 = nullptr;
              v313 = 0;
              LODWORD(v310) = 0;
              v134 = (unsigned __int16)(*(_WORD *)s[33] - 4);
              if ( (unsigned int)v134 >= 4 )
              {
                v135 = (unsigned __int16 *)(s[33] + 4LL);
                do
                {
                  v137 = *v135;
                  if ( v137 < 4 || v134 < v137 )
                    break;
                  if ( (unsigned int)_nla_parse(
                                       &v313,
                                       8,
                                       v135 + 2,
                                       (unsigned __int16)(v137 - 4),
                                       &qca_wlan_vendor_attr_omi_tx_policy,
                                       31,
                                       0) )
                  {
                    v75 = "%s: Invalid ATTR";
                    goto LABEL_75;
                  }
                  if ( v315 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                2,
                                *((unsigned __int8 *)v315 + 4));
                  if ( v314 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                1,
                                *(unsigned __int8 *)(v314 + 4));
                  if ( v316 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                3,
                                *(unsigned __int8 *)(v316 + 4));
                  if ( v317 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                4,
                                *(unsigned __int8 *)(v317 + 4));
                  if ( v318 )
                    updated = sme_set_he_om_ctrl_param(
                                *(_QWORD *)(v5 + 1552),
                                *(unsigned __int8 *)(v8 + 8),
                                5,
                                *(unsigned __int8 *)(v318 + 4));
                  if ( v319 )
                  {
                    v138 = *(_BYTE *)(v319 + 4);
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
                      v138);
                    LODWORD(v310) = v310 & 0xFFFBFFFF | ((v138 & 1) << 18);
                  }
                  if ( v320 )
                  {
                    v139 = *(_BYTE *)(v320 + 4);
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
                      v139);
                    LODWORD(v310) = v310 & 0xFFF7FFFF | ((v139 & 1) << 19);
                  }
                  if ( v321 )
                  {
                    v140 = *(_BYTE *)(v321 + 4);
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
                      v140);
                    LODWORD(v310) = v310 & 0xFFEFFFFF | ((v140 & 1) << 20);
                  }
                  v136 = (*v135 + 3) & 0x1FFFC;
                  v134 -= v136;
                  v135 = (unsigned __int16 *)((char *)v135 + v136);
                }
                while ( v134 > 3 );
              }
              v141 = *(_QWORD *)(v5 + 1552);
              if ( updated )
              {
                sme_reset_he_om_ctrl(v141);
                goto LABEL_12;
              }
              updated = sme_send_he_om_ctrl_update(v141, *(unsigned __int8 *)(v8 + 8), &v310);
            }
            if ( s[30] )
              sme_reset_he_om_ctrl(*(_QWORD *)(v5 + 1552));
            if ( s[31] )
              sme_config_su_ppdu_queue(*(unsigned __int8 *)(v8 + 8), *(unsigned __int8 *)(s[31] + 4LL) != 0);
            if ( s[35] )
            {
              v142 = *(_BYTE *)(s[35] + 4LL) != 0;
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
              wlan_mlme_set_vht_for_24ghz(*v30, v142);
            }
            if ( s[34] )
            {
              v143 = *(_BYTE *)(s[34] + 4LL) != 0;
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
              sme_update_he_htc_he_supp(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v143);
            }
            if ( s[49] )
            {
              v144 = *(unsigned __int8 *)(s[49] + 4LL);
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
              updated = sme_update_he_capabilities(v18, *(unsigned __int8 *)(v8 + 8), v144, 49);
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
            v145 = s[36];
            if ( s[36] )
            {
              if ( (*(_BYTE *)(v5 + 3216) & 1) == 0 )
              {
                *(_BYTE *)(v5 + 3216) = 1;
                qdf_runtime_pm_prevent_suspend((__int64 *)(v5 + 3208));
                v145 = s[36];
              }
              v146 = *(unsigned __int8 *)(v145 + 4);
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
                *(unsigned __int8 *)(v145 + 4));
              v147 = *(_QWORD *)(v5 + 1552);
              v148 = *(unsigned __int8 *)(v8 + 8);
              if ( v146 )
                sme_set_he_testbed_def(v147, v148);
              else
                sme_reset_he_caps(v147, v148);
            }
            if ( s[32] )
            {
              v149 = *(unsigned __int8 *)(s[32] + 4LL);
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
              sme_config_action_tx_in_tb_ppdu(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v149);
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
              v150 = *(unsigned __int8 *)(s[37] + 4LL);
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
              updated = sme_update_he_twt_req_support(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v150);
            }
            if ( s[45] )
            {
              v151 = *(unsigned __int8 *)(s[45] + 4LL);
              v152 = *(_DWORD *)(cfg_psoc_get_values(*v30) + 7556);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: fullbw_ulmumimo: cfg %d, ini %d",
                v153,
                v154,
                v155,
                v156,
                v157,
                v158,
                v159,
                v160,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v151,
                (unsigned __int8)v152);
              if ( v151 )
              {
                if ( (v152 & 0xFC) == 0 )
                  v151 = 0x3030101u >> (8 * (v152 & 3));
              }
              else
              {
                v151 = 2 * ((v152 & 0xFE) == 2);
              }
              updated = sme_update_he_full_ul_mumimo(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v151);
            }
            if ( s[48] )
            {
              v161 = *(unsigned __int8 *)(s[48] + 4LL);
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
              sme_set_cfg_disable_tx(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v161);
            }
            if ( s[38] )
            {
              v162 = *(unsigned __int8 *)(s[38] + 4LL);
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
              sme_set_pmf_wep_cfg(*(_QWORD *)(v5 + 1552), v162);
            }
            if ( s[46] )
            {
              v302 = *(unsigned __int16 *)(s[46] + 4LL);
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
              sme_set_bss_max_idle_period(*(_QWORD *)(v5 + 1552), v302);
            }
            if ( s[55] )
            {
              if ( *(_BYTE *)(s[55] + 4LL) )
                ucfg_mlme_get_sta_keep_alive_period(*v30, (int *)&v302);
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
                v302);
              sme_set_bss_max_idle_period(*(_QWORD *)(v5 + 1552), v302);
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
              sme_send_disassoc_req_frame(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v8 + 300, 1, 0);
            }
            if ( s[47] )
            {
              v163 = *(unsigned __int8 *)(s[47] + 4LL);
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
              sme_set_ru_242_tone_tx_cfg(*(_QWORD *)(v5 + 1552), v163);
              if ( v163 )
                hdd_update_channel_width(v8, 0, 0, 255, 0);
            }
            if ( s[52] )
            {
              v164 = *(unsigned __int8 *)(s[52] + 4LL);
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
              if ( v164 )
              {
                hdd_update_channel_width(v8, 0, 0, 255, 0);
                hdd_set_tx_stbc(v8, 0);
                hdd_set_11ax_rate(v6 + 2688, 1024, 0);
                v165 = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 107, 1, 1);
                if ( v165 )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: failed to set HE_RANGE_EXT, %d",
                    v166,
                    v167,
                    v168,
                    v169,
                    v170,
                    v171,
                    v172,
                    v173,
                    "__wlan_hdd_cfg80211_set_wifi_test_config",
                    v165);
                v174 = *(unsigned __int8 *)(v8 + 8);
                v175 = 1;
              }
              else
              {
                hdd_update_channel_width(v8, 3, 1, 255, 0);
                hdd_set_tx_stbc(v8, 1);
                hdd_set_11ax_rate(v6 + 2688, 0xFFFF, 0);
                v176 = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 107, 0, 1);
                if ( v176 )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: failed to set HE_RANGE_EXT, %d",
                    v177,
                    v178,
                    v179,
                    v180,
                    v181,
                    v182,
                    v183,
                    v184,
                    "__wlan_hdd_cfg80211_set_wifi_test_config",
                    v176);
                v174 = *(unsigned __int8 *)(v8 + 8);
                v175 = 0;
              }
              v185 = wma_cli_set_command(v174, 165, v175, 1);
              v40 = v185;
              if ( v185 )
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
                  v185);
            }
            if ( s[40] )
            {
              LOBYTE(v299) = *(_BYTE *)(v8 + 8);
              v186 = *(unsigned __int8 *)(s[40] + 4LL);
              HIDWORD(v299) = v186;
              if ( v186 >= 3 )
              {
                v187 = "%s: Invalid RSNXE override %d";
LABEL_312:
                qdf_trace_msg(
                  0x33u,
                  8u,
                  v187,
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
              LODWORD(v300) = 0;
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
                          (__int64)&v299,
                          v188,
                          v189,
                          v190,
                          v191,
                          v192,
                          v193,
                          v194,
                          v195);
            }
            if ( s[41] )
            {
              LOBYTE(v299) = *(_BYTE *)(v8 + 8);
              v196 = *(unsigned __int8 *)(s[41] + 4LL);
              HIDWORD(v299) = v196;
              if ( v196 >= 2 )
              {
                v187 = "%s: Invalid CSA config %d";
                goto LABEL_312;
              }
              LODWORD(v300) = 1;
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
                          (__int64)&v299,
                          v197,
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          v203,
                          v204);
            }
            if ( s[51] )
            {
              updated = hdd_test_config_6ghz_security_test_mode(v5 + 1536);
              if ( updated )
                goto LABEL_12;
            }
            if ( s[42] )
            {
              v314 = 0;
              v315 = nullptr;
              v205 = *(_BYTE *)(v8 + 8);
              v313 = 0;
              LOBYTE(v299) = v205;
              LODWORD(v300) = 2;
              if ( (unsigned int)wlan_cfg80211_nla_parse_nested(
                                   (__int64)&v313,
                                   2,
                                   (_WORD *)s[42],
                                   (__int64)&wlan_oci_override_policy) )
              {
                v187 = "%s: Failed to parse OCI override";
                goto LABEL_312;
              }
              if ( !v314 || !v315 )
              {
                v187 = "%s: Invalid ATTR FRAME_TYPE/FREQUENCY";
                goto LABEL_312;
              }
              v206 = (unsigned __int8 *)_qdf_mem_malloc(8u, "__wlan_hdd_cfg80211_set_wifi_test_config", 17372);
              v301 = v206;
              if ( !v206 )
              {
                v75 = "%s: Failed to alloc memory for ocv param";
                goto LABEL_75;
              }
              v207 = *(_BYTE *)(v314 + 4) - 1;
              if ( v207 >= 4u )
              {
                v272 = "%s: Invalid frame type for ocv test config %d";
              }
              else
              {
                *v206 = 0x8040201u >> (8 * (v207 & 0x1F));
                *((_DWORD *)v301 + 1) = *((_DWORD *)v315 + 1);
                if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v301 + 1))
                  || wlan_reg_is_5ghz_ch_freq(*((_DWORD *)v301 + 1))
                  || wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v301 + 1)) )
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
                    *v301,
                    *((unsigned int *)v301 + 1));
                  updated = wlan_send_wfatest_cmd(
                              *(_QWORD *)(v8 + 32),
                              (__int64)&v299,
                              v208,
                              v209,
                              v210,
                              v211,
                              v212,
                              v213,
                              v214,
                              v215);
                  _qdf_mem_free((__int64)v301);
                  goto LABEL_227;
                }
                v272 = "%s: Invalid Freq %d";
              }
              qdf_trace_msg(
                0x33u,
                8u,
                v272,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              _qdf_mem_free((__int64)v301);
              goto LABEL_12;
            }
LABEL_227:
            if ( s[43] )
            {
              LOBYTE(v299) = *(_BYTE *)(v8 + 8);
              v216 = *(unsigned __int8 *)(s[43] + 4LL);
              HIDWORD(v299) = v216;
              if ( v216 >= 2 )
              {
                v187 = "%s: Invalid SA query timeout config %d";
                goto LABEL_312;
              }
              LODWORD(v300) = 3;
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
                          (__int64)&v299,
                          v217,
                          v218,
                          v219,
                          v220,
                          v221,
                          v222,
                          v223,
                          v224);
            }
            if ( s[44] && *(_DWORD *)(v6 + 2728) == 1 )
            {
              LOBYTE(v299) = *(_BYTE *)(v8 + 8);
              v225 = *(unsigned __int8 *)(s[44] + 4LL);
              HIDWORD(v299) = v225;
              if ( v225 >= 2 )
              {
                v187 = "%s: Invalid FILS_DISCV_FRAMES config %d";
                goto LABEL_312;
              }
              LODWORD(v300) = 4;
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
                          (__int64)&v299,
                          v226,
                          v227,
                          v228,
                          v229,
                          v230,
                          v231,
                          v232,
                          v233);
            }
            if ( s[50] )
            {
              LOBYTE(v299) = *(_BYTE *)(v8 + 8);
              v234 = *(unsigned __int8 *)(s[50] + 4LL);
              HIDWORD(v299) = v234;
              if ( v234 >= 2 )
              {
                v187 = "%s: Invalid RSNXE_IGNORE config %d";
                goto LABEL_312;
              }
              LODWORD(v300) = 5;
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
                          (__int64)&v299,
                          v235,
                          v236,
                          v237,
                          v238,
                          v239,
                          v240,
                          v241,
                          v242);
            }
            if ( s[58] && !*(_DWORD *)(v6 + 2728) )
              updated = 0;
            if ( s[59] )
            {
              if ( *(_BYTE *)(s[59] + 4LL) )
                v243 = 100;
              else
                v243 = 0;
              updated = wma_cli_set_command(*(unsigned __int8 *)(v8 + 8), 97, v243, 2);
            }
            if ( s[60] )
            {
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
              updated = 0;
            }
            if ( s[61] )
            {
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
              updated = 0;
            }
            if ( s[62] )
            {
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
              updated = 0;
            }
            if ( s[63] && !*(_DWORD *)(v6 + 2728) )
            {
              v244 = *(unsigned __int8 *)(s[63] + 4LL);
              v245 = *(_BYTE *)(s[63] + 4LL) != 0;
              wlan_vdev_obj_lock(*(_QWORD *)(v8 + 32));
              *(_DWORD *)(*(_QWORD *)(v8 + 32) + 48LL) = *(_DWORD *)(*(_QWORD *)(v8 + 32) + 48LL) & 0xFFFFF7FF
                                                       | (v245 << 11);
              wlan_vdev_obj_unlock(*(_QWORD *)(v8 + 32));
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Sta profile in Probe req frame: %d",
                v246,
                v247,
                v248,
                v249,
                v250,
                v251,
                v252,
                v253,
                "__wlan_hdd_cfg80211_set_wifi_test_config",
                v244);
            }
            if ( s[64] )
            {
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
              sme_set_vdev_ies_per_band(
                *(_QWORD *)(v5 + 1552),
                *(unsigned __int8 *)(v8 + 8),
                *(unsigned int *)(v6 + 2728));
            }
            if ( s[65] )
              sme_set_vdev_ies_per_band(
                *(_QWORD *)(v5 + 1552),
                *(unsigned __int8 *)(v8 + 8),
                *(unsigned int *)(v6 + 2728));
            if ( s[66] )
            {
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
              updated = 0;
            }
            if ( s[67] )
            {
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
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = 0;
            }
            if ( s[68] && !*(_DWORD *)(v6 + 2728) )
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
            if ( s[69] && !*(_DWORD *)(v6 + 2728) )
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
            if ( s[70] )
            {
              v313 = 0;
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
              v254 = *(unsigned __int8 *)(v8 + 8);
              v313 = 0x1000002A4LL;
              updated = sme_send_unit_test_cmd(v254, 72, 2, &v313);
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
              v255 = (unsigned __int16)(*(_WORD *)s[71] - 4);
              if ( (unsigned int)v255 >= 4 )
              {
                v256 = 0;
                v257 = (unsigned __int16 *)(s[71] + 4LL);
                do
                {
                  v258 = *v257;
                  if ( v258 < 4 || v255 < v258 )
                    break;
                  if ( v258 != 5 )
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
                      v256);
                    goto LABEL_12;
                  }
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
                    v256++,
                    *((unsigned __int8 *)v257 + 4));
                  v259 = (*v257 + 3) & 0x1FFFC;
                  v255 -= v259;
                  v257 = (unsigned __int16 *)((char *)v257 + v259);
                }
                while ( v255 > 3 );
              }
            }
            if ( s[72] )
            {
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
                *(unsigned __int8 *)(s[72] + 4LL));
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to set MLD ID",
                v260,
                v261,
                v262,
                v263,
                v264,
                v265,
                v266,
                v267,
                "__wlan_hdd_cfg80211_set_wifi_test_config");
              updated = 11;
            }
            if ( s[73] )
            {
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
              updated = 0;
            }
            if ( s[74] && *(_DWORD *)(v6 + 2728) == 3 )
            {
              v268 = *(unsigned __int8 *)(s[74] + 4LL);
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
                v270 = vdev_by_user;
                v271 = ucfg_p2p_force_restrict_dfs_go_csa(vdev_by_user, v268 != 0);
                _hdd_objmgr_put_vdev_by_user(v270, 6, "__wlan_hdd_cfg80211_set_wifi_test_config");
              }
              else
              {
                v271 = 4;
              }
              updated = qdf_status_to_os_return(v271);
            }
            if ( s[75] )
            {
              v273 = *(unsigned __int8 *)(s[75] + 4LL);
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
              if ( v273 <= 0xC )
                v274 = v273;
              else
                v274 = 0;
              wlan_crypto_set_vdev_param(*(_QWORD *)(v8 + 32), 9u, v274);
            }
            if ( s[76] )
            {
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
              updated = 0;
            }
            if ( s[77] )
            {
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
              updated = 0;
            }
            if ( s[78] )
            {
              v275 = *(unsigned __int8 *)(s[78] + 4LL);
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
              updated = sme_set_btm_req_reject(*(_QWORD *)(v5 + 1552), *(unsigned __int8 *)(v8 + 8), v275);
              if ( updated )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to set BTM reject config",
                  v276,
                  v277,
                  v278,
                  v279,
                  v280,
                  v281,
                  v282,
                  v283,
                  "__wlan_hdd_cfg80211_set_wifi_test_config");
            }
            if ( !s[79] )
            {
              if ( !v298 )
                goto LABEL_12;
LABEL_348:
              sme_update_config(v18, v19);
              goto LABEL_12;
            }
            v315 = nullptr;
            v316 = 0;
            v313 = 0;
            v314 = 0;
            v311 = 0;
            v312 = 0;
            v310 = 0;
            v309 = 0;
            v308[0] = 0;
            v308[1] = 0;
            qdf_mem_set(v308, 0x12u, 0);
            if ( (unsigned int)wlan_cfg80211_nla_parse_nested(
                                 (__int64)&v313,
                                 3,
                                 (_WORD *)s[79],
                                 (__int64)&wlan_btm_req_resp_policy) )
            {
              v187 = "%s: Failed to parse btm request response";
              goto LABEL_312;
            }
            if ( !v314 )
            {
              v187 = "%s: Response type not found";
              goto LABEL_312;
            }
            v284 = *(unsigned __int8 *)(v314 + 4);
            if ( (unsigned int)(v284 - 2) >= 2 )
            {
              if ( *(_BYTE *)(v314 + 4) )
              {
                if ( v284 == 1 )
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
                qdf_mem_set(v308, 0x12u, 0);
              }
            }
            if ( *(_BYTE *)(v314 + 4) == 1 )
            {
              if ( v315 )
              {
                v285 = (unsigned __int16)(*v315 - 4);
                v286 = v308[0];
                if ( (unsigned int)v285 >= 4 )
                {
                  v287 = v315 + 2;
                  do
                  {
                    v288 = *v287;
                    if ( v288 < 4 )
                      break;
                    if ( v285 < v288 )
                      break;
                    LOBYTE(v308[0]) = ++v286;
                    v289 = (*v287 + 3) & 0x1FFFC;
                    v285 -= v289;
                    v287 = (unsigned __int16 *)((char *)v287 + v289);
                  }
                  while ( v285 > 3 );
                }
                if ( v286 )
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
                    v286);
                  v290 = (unsigned __int16)(*v315 - 4);
                  if ( (unsigned int)v290 >= 4 )
                  {
                    v291 = 0;
                    v292 = v315 + 2;
                    while ( 1 )
                    {
                      v294 = (unsigned __int16)*v292;
                      if ( v294 < 4 || v290 < v294 )
                        break;
                      a1 = wlan_cfg80211_nla_parse_nested(
                             (__int64)&v310,
                             2,
                             v292,
                             (__int64)&wlan_reconfig_frame_info_policy);
                      if ( (_DWORD)a1 )
                      {
                        v75 = "%s: nla_parse failed";
                        goto LABEL_75;
                      }
                      if ( v291 == 4 )
                        goto LABEL_351;
                      v295 = (char *)v308 + 2 * v291;
                      v296 = v311;
                      *((_WORD *)v295 + 1) = 0;
                      *((_WORD *)v295 + 5) = 0;
                      if ( v296 )
                      {
                        *((_WORD *)v295 + 1) = *(_WORD *)(v296 + 4);
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
                          (unsigned int)v291);
                      }
                      if ( v312 )
                      {
                        *((_WORD *)v295 + 5) = *(_WORD *)(v312 + 4);
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
                          (unsigned int)v291);
                      }
                      ++v291;
                      v293 = ((unsigned __int16)*v292 + 3) & 0x1FFFC;
                      v290 -= v293;
                      v292 = (_WORD *)((char *)v292 + v293);
                      if ( v290 <= 3 )
                        goto LABEL_347;
                    }
                  }
                  goto LABEL_347;
                }
                v297 = "%s: reconfig info not found";
              }
              else
              {
                v297 = "%s: QCA_WLAN_VENDOR_ATTR_BTM_REQ_RESP_RECONFIG_FRAME_INFO not present";
              }
              qdf_trace_msg(
                0x33u,
                8u,
                v297,
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
LABEL_347:
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
            if ( !v298 )
              goto LABEL_12;
            goto LABEL_348;
          }
          v76 = 1;
        }
        v77 = *(_QWORD *)(v5 + 1536);
        LOBYTE(v306[0]) = v76;
        ucfg_mlme_get_sta_keep_alive_period(v77, (int *)v306 + 1);
        v78 = *(_QWORD *)(v5 + 1552);
        BYTE4(v307) = *(_BYTE *)(v8 + 8);
        v79 = sme_set_keep_alive(v78, BYTE4(v307), v306);
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
LABEL_351:
  __break(0x5512u);
  return hdd_test_config_6ghz_security_test_mode(a1);
}
