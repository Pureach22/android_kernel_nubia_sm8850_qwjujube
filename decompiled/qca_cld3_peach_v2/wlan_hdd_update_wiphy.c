__int64 __fastcall wlan_hdd_update_wiphy(
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
  __int64 v9; // x23
  __int64 *v10; // x26
  __int64 v11; // x9
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x19
  __int64 v23; // x21
  unsigned int v24; // w8
  __int64 result; // x0
  char v26; // w8
  unsigned int v27; // w8
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  __int64 v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x21
  int v72; // w19
  int v73; // w20
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x13
  __int64 v83; // x8
  __int64 v84; // x14
  __int64 v85; // x11
  __int64 v86; // x12
  unsigned int v87; // w14
  __int64 v88; // x13
  unsigned int v89; // w14
  bool v90; // cc
  __int64 v91; // x14
  bool v92; // zf
  int v93; // w25
  int v94; // w27
  char is_dual_sap_sta_enabled; // w22
  bool v96; // zf
  __int64 v97; // x28
  unsigned __int8 v98; // w19
  char v99; // w8
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  _WORD *v108; // x8
  _UNKNOWN **v109; // x27
  unsigned __int64 v110; // x8
  int v111; // w9
  int v112; // w10
  __int64 v113; // x12
  unsigned __int16 *v114; // x11
  int v115; // w13
  int v116; // t1
  unsigned __int16 *v117; // x8
  int v118; // w9
  int v119; // w8
  char v120; // w9
  char v121; // w11
  __int64 v122; // x12
  unsigned __int16 *v123; // x9
  unsigned __int16 *v124; // x13
  int v125; // w14
  int v126; // t1
  int v127; // w10
  int v128; // w11
  unsigned __int16 *v129; // x12
  __int64 v130; // x13
  int v131; // w14
  int v132; // t1
  int v133; // w10
  int v134; // w11
  int v135; // w12
  __int64 v136; // x13
  int v137; // w14
  int v138; // t1
  unsigned __int64 v139; // x9
  unsigned __int16 *v140; // x10
  int v141; // t1
  _UNKNOWN **v142; // x20
  __int64 v143; // x8
  int v144; // w10
  int v145; // w11
  __int64 v146; // x13
  unsigned __int16 *v147; // x9
  unsigned __int16 *v148; // x12
  int v149; // w14
  int v150; // t1
  int v151; // w9
  int v152; // w10
  int v153; // w11
  unsigned __int16 *v154; // x12
  int v155; // w13
  int v156; // t1
  char v157; // w0
  __int64 v158; // x8
  int v159; // w9
  int v160; // w10
  int v161; // w11
  __int64 v162; // x13
  unsigned __int16 *v163; // x12
  int v164; // w14
  int v165; // t1
  int v166; // w9
  int v167; // w10
  int v168; // w11
  unsigned __int16 *v169; // x12
  int v170; // w13
  int v171; // t1
  _QWORD *v172; // x8
  unsigned __int64 v173; // x9
  _QWORD *v174; // x10
  _QWORD *v175; // x15
  __int64 v176; // x12
  int v177; // w13
  int v178; // w14
  unsigned __int16 *v179; // x15
  int v180; // w16
  int v181; // t1
  char v182; // w9
  unsigned __int8 v183; // w9
  unsigned __int64 v184; // x10
  _QWORD *v185; // x11
  _QWORD *v186; // x16
  __int64 v187; // x13
  int v188; // w14
  int v189; // w15
  unsigned __int16 *v190; // x16
  int v191; // w17
  int v192; // t1
  char v193; // w10
  _QWORD *v194; // x8
  int v195; // w10
  int v196; // w11
  int v197; // w12
  int v198; // t1
  unsigned __int64 v199; // x11
  _QWORD *v200; // x8
  __int64 v201; // x13
  __int64 v202; // x14
  __int64 v203; // t1
  unsigned __int64 v204; // x12
  _QWORD *v205; // x8
  __int64 v206; // x14
  __int64 v207; // x15
  __int64 v208; // t1
  __int64 v209; // x9
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  __int64 v218; // x21
  __int64 *v219; // x26
  unsigned __int8 v220; // w9
  __int64 v221; // x8
  __int64 v222; // x20
  unsigned __int8 v223; // w23
  int v224; // w21
  const char *v225; // x3
  char v226; // w0
  int v227; // w9
  const char *v228; // x2
  __int64 v229; // x0
  int v230; // w8
  double v231; // d0
  double v232; // d1
  double v233; // d2
  double v234; // d3
  double v235; // d4
  double v236; // d5
  double v237; // d6
  double v238; // d7
  char is_sta_p2p_ndp_supported; // [xsp+4h] [xbp-CCh]
  int v240; // [xsp+8h] [xbp-C8h]
  __int64 *v241; // [xsp+8h] [xbp-C8h]
  __int64 v242; // [xsp+10h] [xbp-C0h]
  int is_allowed; // [xsp+18h] [xbp-B8h]
  char v244; // [xsp+20h] [xbp-B0h]
  __int64 v245; // [xsp+20h] [xbp-B0h]
  char v246; // [xsp+28h] [xbp-A8h]
  __int64 v247; // [xsp+28h] [xbp-A8h]
  char v248[4]; // [xsp+30h] [xbp-A0h] BYREF
  char v249[4]; // [xsp+34h] [xbp-9Ch] BYREF
  char v250[4]; // [xsp+38h] [xbp-98h] BYREF
  char v251[4]; // [xsp+3Ch] [xbp-94h] BYREF
  char v252[4]; // [xsp+40h] [xbp-90h] BYREF
  char v253[4]; // [xsp+44h] [xbp-8Ch] BYREF
  int v254; // [xsp+48h] [xbp-88h] BYREF
  char v255[4]; // [xsp+4Ch] [xbp-84h] BYREF
  char v256[4]; // [xsp+50h] [xbp-80h] BYREF
  _BYTE v257[4]; // [xsp+54h] [xbp-7Ch] BYREF
  _QWORD v258[12]; // [xsp+58h] [xbp-78h] BYREF
  int v259; // [xsp+B8h] [xbp-18h]
  __int64 v260; // [xsp+C0h] [xbp-10h]

  v260 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[3];
  v254 = 0;
  v253[0] = 0;
  v252[0] = 0;
  v251[0] = 0;
  v250[0] = 0;
  v249[0] = 0;
  v248[0] = 0;
  if ( !v9 )
  {
    result = qdf_trace_msg(0x33u, 2u, "%s: Invalid wiphy", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_update_wiphy");
    goto LABEL_309;
  }
  v10 = a1;
  wlan_mlme_get_sap_max_peers(*a1, &v254);
  v11 = v10[3];
  *(_WORD *)v255 = 0;
  *(_WORD *)(v11 + 1392) = v254;
  v12 = *v10;
  LODWORD(v258[0]) = 0;
  if ( (unsigned int)wlan_mlme_get_ht_cap_info(v12, v255) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not get HT capability info",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_hdd_update_ht_cap");
  v21 = v10[3];
  v22 = *(_QWORD *)(v21 + 328);
  v23 = *(_QWORD *)(v21 + 336);
  if ( v22 )
  {
    if ( v255[0] < 0 )
      *(_WORD *)(v22 + 28) |= 0x80u;
    if ( (sme_is_feature_supported_by_fw(2) & 1) != 0 )
    {
      if ( (v255[0] & 0x20) != 0 )
        goto LABEL_9;
    }
    else
    {
      *(_BYTE *)(v22 + 52) = 0;
      *(_DWORD *)(v22 + 56) = 0;
      if ( (v255[0] & 0x20) != 0 )
      {
LABEL_9:
        v24 = *((_DWORD *)v10 + 312);
        if ( !v24 )
          goto LABEL_25;
        goto LABEL_14;
      }
    }
    *(_WORD *)(v22 + 28) &= ~0x20u;
    v24 = *((_DWORD *)v10 + 312);
    if ( !v24 )
    {
LABEL_25:
      *(_WORD *)(v22 + 43) = v24;
      goto LABEL_26;
    }
LABEL_14:
    *(_BYTE *)(v22 + 33) = -1;
    v24 = *((_DWORD *)v10 + 312);
    if ( v24 >= 2 )
    {
      *(_BYTE *)(v22 + 34) = -1;
      v24 = *((_DWORD *)v10 + 312);
      if ( v24 >= 3 )
      {
        *(_BYTE *)(v22 + 35) = -1;
        v24 = *((_DWORD *)v10 + 312);
        if ( v24 >= 4 )
        {
          *(_BYTE *)(v22 + 36) = -1;
          v24 = *((_DWORD *)v10 + 312);
          if ( v24 >= 5 )
          {
            *(_BYTE *)(v22 + 37) = -1;
            v24 = *((_DWORD *)v10 + 312);
            if ( v24 >= 6 )
            {
              *(_BYTE *)(v22 + 38) = -1;
              v24 = *((_DWORD *)v10 + 312);
              if ( v24 >= 7 )
              {
                *(_BYTE *)(v22 + 39) = -1;
                v24 = *((_DWORD *)v10 + 312);
                if ( v24 >= 8 )
                {
                  *(_BYTE *)(v22 + 40) = -1;
                  v24 = *((_DWORD *)v10 + 312);
                  if ( v24 >= 9 )
                  {
                    *(_BYTE *)(v22 + 41) = -1;
                    v24 = *((_DWORD *)v10 + 312);
                    if ( v24 >= 0xA )
                    {
                      *(_BYTE *)(v22 + 42) = -1;
                      v24 = *((_DWORD *)v10 + 312);
                      if ( v24 > 0xA )
                        goto LABEL_310;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    LOWORD(v24) = 150 * v24;
    goto LABEL_25;
  }
LABEL_26:
  if ( !v23 )
    goto LABEL_52;
  if ( v255[0] < 0 )
    *(_WORD *)(v23 + 28) |= 0x80u;
  if ( (sme_is_feature_supported_by_fw(2) & 1) != 0 )
  {
    v26 = v255[0];
    if ( (v255[0] & 0x20) != 0 )
      goto LABEL_31;
  }
  else
  {
    *(_BYTE *)(v23 + 52) = 0;
    *(_DWORD *)(v23 + 56) = 0;
    v26 = v255[0];
    if ( (v255[0] & 0x20) != 0 )
    {
LABEL_31:
      if ( (v26 & 0x40) != 0 )
        goto LABEL_33;
      goto LABEL_32;
    }
  }
  *(_WORD *)(v23 + 28) &= ~0x20u;
  if ( (v26 & 0x40) == 0 )
LABEL_32:
    *(_WORD *)(v23 + 28) &= ~0x40u;
LABEL_33:
  ucfg_mlme_get_channel_bonding_5ghz(*v10, (int *)v258);
  if ( LODWORD(v258[0]) )
  {
    v27 = *((_DWORD *)v10 + 312);
    if ( !v27 )
      goto LABEL_51;
LABEL_40:
    *(_BYTE *)(v23 + 33) = -1;
    v27 = *((_DWORD *)v10 + 312);
    if ( v27 < 2 )
      goto LABEL_50;
    *(_BYTE *)(v23 + 34) = -1;
    v27 = *((_DWORD *)v10 + 312);
    if ( v27 < 3 )
      goto LABEL_50;
    *(_BYTE *)(v23 + 35) = -1;
    v27 = *((_DWORD *)v10 + 312);
    if ( v27 < 4 )
      goto LABEL_50;
    *(_BYTE *)(v23 + 36) = -1;
    v27 = *((_DWORD *)v10 + 312);
    if ( v27 < 5 )
      goto LABEL_50;
    *(_BYTE *)(v23 + 37) = -1;
    v27 = *((_DWORD *)v10 + 312);
    if ( v27 < 6 )
      goto LABEL_50;
    *(_BYTE *)(v23 + 38) = -1;
    v27 = *((_DWORD *)v10 + 312);
    if ( v27 < 7 )
      goto LABEL_50;
    *(_BYTE *)(v23 + 39) = -1;
    v27 = *((_DWORD *)v10 + 312);
    if ( v27 < 8
      || (*(_BYTE *)(v23 + 40) = -1, v27 = *((_DWORD *)v10 + 312), v27 < 9)
      || (*(_BYTE *)(v23 + 41) = -1, v27 = *((_DWORD *)v10 + 312), v27 < 0xA)
      || (*(_BYTE *)(v23 + 42) = -1, v27 = *((_DWORD *)v10 + 312), v27 <= 0xA) )
    {
LABEL_50:
      LOWORD(v27) = 150 * v27;
      goto LABEL_51;
    }
LABEL_310:
    __break(0x5512u);
  }
  *(_WORD *)(v23 + 28) &= ~2u;
  v27 = *((_DWORD *)v10 + 312);
  if ( v27 )
    goto LABEL_40;
LABEL_51:
  *(_WORD *)(v23 + 43) = v27;
LABEL_52:
  v28 = *v10;
  LODWORD(v258[0]) = 0;
  if ( !(unsigned int)wlan_mlme_get_band_capability(v28, v258) )
  {
    v82 = v10[3];
    v83 = 0;
    while ( 1 )
    {
      if ( *(_QWORD *)(v82 + 8 * v83 + 328) )
      {
        v84 = *(_QWORD *)(v82 + 8 * v83 + 328);
        if ( *(int *)(v84 + 20) >= 1 )
          break;
      }
LABEL_83:
      if ( ++v83 == 6 )
        goto LABEL_54;
    }
    v85 = 0;
    v86 = 0;
    while ( 1 )
    {
      if ( v83 || LODWORD(v258[0]) != 2 )
      {
        if ( v83 != 1 || LODWORD(v258[0]) != 1 )
          goto LABEL_89;
        v88 = *(_QWORD *)v84 + v85;
      }
      else
      {
        v88 = *(_QWORD *)v84 + v85;
        v89 = *(_DWORD *)(v88 + 4) - 2412;
        v90 = v89 > 0x32;
        v91 = (1LL << v89) & 0x4000002000001LL;
        v92 = v90 || v91 == 0;
        if ( !v92 )
        {
          v87 = *(_DWORD *)(v88 + 12) & 0xFFFFFFFE;
          goto LABEL_88;
        }
      }
      v87 = *(_DWORD *)(v88 + 12) | 1;
LABEL_88:
      *(_DWORD *)(v88 + 12) = v87;
LABEL_89:
      v82 = v10[3];
      ++v86;
      v85 += 64;
      v84 = *(_QWORD *)(v82 + 8 * v83 + 328);
      if ( v86 >= *(int *)(v84 + 20) )
        goto LABEL_83;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Failed to get MLME Band Capability",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "wlan_hdd_update_band_cap_in_wiphy");
LABEL_54:
  v37 = *v10;
  LOBYTE(v258[0]) = 0;
  v255[0] = 0;
  v257[0] = 0;
  v256[0] = 0;
  ucfg_mlme_is_fast_transition_enabled(v37, (char *)v258);
  ucfg_mlme_is_lfr_enabled(*v10, v255);
  ucfg_mlme_is_ese_enabled(*v10, v257);
  ucfg_mlme_get_roaming_offload(*v10, v256);
  if ( (v258[0] & 1) != 0 || (v255[0] & 1) != 0 || (v257[0] & 1) != 0 || v256[0] == 1 )
    *(_DWORD *)(v10[3] + 100) |= 0x2000u;
  v38 = v10[3];
  v253[0] = 0;
  *(_DWORD *)(v38 + 124) |= 1u;
  if ( (unsigned int)wlan_mlme_get_fils_enabled_info(*v10, v253) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not get fils enabled info",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "wlan_hdd_update_wiphy");
  if ( v253[0] == 1 )
    *(_BYTE *)(v9 + 113) |= 0x40u;
  *(_BYTE *)(v9 + 115) |= 2u;
  if ( !(unsigned int)wlan_mlme_get_bigtk_support(*v10, v249) && v249[0] == 1 )
    *(_BYTE *)(v9 + 117) |= 2u;
  if ( !(unsigned int)wlan_mlme_get_ocv_support(*v10, v248) && v248[0] == 1 )
    *(_BYTE *)(v9 + 118) |= 2u;
  if ( (unsigned int)wlan_mlme_get_oce_sta_enabled_info(*v10, v252) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not get OCE STA enable info",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "wlan_hdd_update_wiphy");
  if ( v252[0] == 1 )
    *(_BYTE *)(v9 + 114) |= 0x1Eu;
  if ( (ucfg_fwol_get_sae_enable(*(_QWORD *)(v9 + 1536)) & 1) != 0 )
    *(_DWORD *)(v9 + 108) |= 0x20u;
  if ( (unsigned int)ucfg_policy_mgr_get_allow_mcc_go_diff_bi(*v10, v251) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: can't get mcc_go_diff_bi value, use default",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "wlan_hdd_update_wiphy");
  if ( (unsigned int)wlan_mlme_get_mcc_feature(*v10, v250) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: can't get enable_mcc value, use default",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "wlan_hdd_update_wiphy");
  if ( *(_BYTE *)(v10[13] + 9) != 1 )
    goto LABEL_299;
  v71 = *v10;
  v72 = (unsigned __int8)v251[0];
  v73 = (unsigned __int8)v250[0];
  v255[0] = 0;
  v257[0] = 0;
  if ( (unsigned int)ucfg_policy_mgr_get_dbs_hw_modes(v71, v255, v257) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HW mode failure",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "wlan_hdd_update_iface_combination");
    goto LABEL_299;
  }
  v93 = *(unsigned __int8 *)(cfg_psoc_get_values(v71) + 3994);
  v94 = *(unsigned __int8 *)(cfg_psoc_get_values(v71) + 3997);
  is_dual_sap_sta_enabled = wlan_mlme_is_dual_sap_sta_enabled(v71);
  v246 = *(_BYTE *)(cfg_psoc_get_values(v71) + 3993);
  is_sta_p2p_ndp_supported = ucfg_nan_is_sta_p2p_ndp_supported(v71);
  is_allowed = ucfg_nan_is_allowed(v71);
  if ( (is_allowed & 1) != 0 )
    *(_WORD *)(v9 + 96) |= 0x1000u;
  v242 = v9;
  if ( v72 )
    v96 = 1;
  else
    v96 = v73 == 0;
  v97 = 0;
  v98 = 0;
  v99 = v96;
  v244 = v99;
  v240 = v94;
  do
  {
    if ( (ucfg_policy_mgr_is_fw_supports_dbs(v71) & 1) == 0 )
    {
      if ( *((unsigned __int16 *)&wlan_hdd_iface_combination + 12 * v97 + 6) > 2u )
        goto LABEL_110;
      v117 = (unsigned __int16 *)*(&wlan_hdd_iface_combination + 3 * v97);
      v118 = v117[1];
      v119 = *v117;
      if ( (v118 == 8 || v118 == 4 || v118 == 768) && v119 == 2 )
        goto LABEL_110;
    }
    if ( v255[0] == 1 && (v257[0] & 1) == 0 && *((unsigned __int16 *)&wlan_hdd_iface_combination + 12 * v97 + 6) > 2u )
      goto LABEL_110;
    if ( (is_dual_sap_sta_enabled & 1) == 0 )
    {
      v108 = *(&wlan_hdd_iface_combination + 3 * v97);
      if ( v108[1] == 4 && *v108 == 1 && v108[3] == 8 && v108[2] == 2 )
        goto LABEL_110;
    }
    v109 = &wlan_hdd_iface_combination + 3 * v97;
    if ( v93 )
    {
      v110 = *((unsigned __int8 *)v109 + 14);
      if ( *((_WORD *)v109 + 6) == 2 )
      {
        if ( !*((_BYTE *)v109 + 14) )
        {
LABEL_154:
          v110 = 0;
          v120 = 1;
          goto LABEL_173;
        }
        v111 = 0;
        v112 = 0;
        v113 = *((unsigned __int8 *)v109 + 14);
        v114 = (unsigned __int16 *)((char *)*v109 + 2);
        do
        {
          v116 = *v114;
          v114 += 2;
          v115 = v116;
          if ( v116 == 768 )
          {
            v112 = 1;
          }
          else if ( v115 == 4 )
          {
            v111 = 1;
          }
          --v113;
        }
        while ( v113 );
        if ( (v112 & v111 & 1) != 0 )
          goto LABEL_166;
      }
      if ( *((_BYTE *)v109 + 14) )
      {
        v121 = 0;
        v122 = 0;
        v123 = (unsigned __int16 *)((char *)*v109 + 2);
LABEL_141:
        v124 = &v123[2 * v122];
        do
        {
          v126 = *v124;
          v124 += 2;
          v125 = v126;
          if ( v126 == 256 || v125 == 512 || v125 == 768 )
          {
            v92 = v110 - 1 == v122++;
            v121 = 1;
            if ( !v92 )
              goto LABEL_141;
            goto LABEL_147;
          }
          ++v122;
        }
        while ( v110 != v122 );
        if ( (v121 & 1) == 0 )
          goto LABEL_166;
LABEL_147:
        if ( !v240 )
          goto LABEL_165;
        v127 = 0;
        v128 = 0;
        v129 = (unsigned __int16 *)((char *)*v109 + 2);
        v130 = *((unsigned __int8 *)v109 + 14);
        do
        {
          v132 = *v129;
          v129 += 2;
          v131 = v132;
          if ( v132 == 4 )
          {
            v127 = 1;
          }
          else if ( v131 == 8 )
          {
            v128 = 1;
          }
          --v130;
        }
        while ( v130 );
        if ( (v127 & v128 & 1) == 0 )
        {
LABEL_165:
          if ( (is_sta_p2p_ndp_supported & 1) == 0 )
            goto LABEL_110;
          v133 = 0;
          v134 = 0;
          v135 = 0;
          v136 = *((unsigned __int8 *)v109 + 14);
          do
          {
            v138 = *v123;
            v123 += 2;
            v137 = v138;
            if ( v138 == 4 )
            {
              v135 = 1;
            }
            else if ( v137 == 4096 )
            {
              v134 = 1;
            }
            else if ( v137 == 768 )
            {
              v133 = 1;
            }
            --v136;
          }
          while ( v136 );
          if ( (v134 & v133 & v135 & 1) == 0 )
            goto LABEL_110;
        }
LABEL_166:
        v109 = &wlan_hdd_iface_combination + 3 * v97;
LABEL_167:
        v139 = 0;
        v140 = (unsigned __int16 *)((char *)*v109 + 2);
        while ( 1 )
        {
          v141 = *v140;
          v140 += 2;
          if ( v141 == 4096 )
            break;
          if ( v110 == ++v139 )
            goto LABEL_172;
        }
        if ( ((v139 < v110) & ~is_allowed) != 0 )
          goto LABEL_110;
LABEL_172:
        v120 = 0;
        goto LABEL_173;
      }
      goto LABEL_154;
    }
    v110 = *((unsigned __int8 *)v109 + 14);
    if ( *((_BYTE *)v109 + 14) )
      goto LABEL_167;
    v120 = 1;
LABEL_173:
    v142 = &wlan_hdd_iface_combination + 3 * v97;
    if ( (v246 & 1) != 0 )
    {
      if ( (ucfg_policy_mgr_is_fw_supports_dbs(v71) & 1) != 0
        && *((_WORD *)&wlan_hdd_iface_combination + 12 * v97 + 6) == 2 )
      {
        v143 = *((unsigned __int8 *)v142 + 14);
        if ( *((_BYTE *)v142 + 14) )
        {
          v144 = 0;
          v145 = 0;
          v146 = *((unsigned __int8 *)v142 + 14);
          v147 = (unsigned __int16 *)((char *)*v109 + 2);
          v148 = v147;
          do
          {
            v150 = *v148;
            v148 += 2;
            v149 = v150;
            if ( v150 == 4096 )
            {
              v145 = 1;
            }
            else if ( v149 == 4 )
            {
              v144 = 1;
            }
            --v146;
          }
          while ( v146 );
          if ( (v145 & v144 & 1) != 0 )
            goto LABEL_110;
          v195 = 0;
          v196 = 0;
          do
          {
            v198 = *v147;
            v147 += 2;
            v197 = v198;
            if ( v198 == 4096 )
            {
              v196 = 1;
            }
            else if ( v197 == 8 )
            {
              v195 = 1;
            }
            --v143;
          }
          while ( v143 );
          if ( (v196 & v195 & 1) != 0 )
            goto LABEL_110;
        }
      }
    }
    else
    {
      if ( *((_WORD *)&wlan_hdd_iface_combination + 12 * v97 + 6) != 4 )
        v120 = 1;
      if ( (v120 & 1) == 0 )
      {
        v151 = 0;
        v152 = 0;
        v153 = 0;
        v154 = (unsigned __int16 *)((char *)*v109 + 2);
        do
        {
          v156 = *v154;
          v154 += 2;
          v155 = v156;
          if ( v156 == 4 )
          {
            v151 = 1;
          }
          else if ( v155 == 4096 )
          {
            v153 = 1;
          }
          else if ( v155 == 8 )
          {
            v152 = 1;
          }
          --v110;
        }
        while ( v110 );
        if ( (v153 & v152 & v151 & 1) != 0 )
          goto LABEL_110;
      }
    }
    v157 = ucfg_nan_is_sta_p2p_ndp_supported(*v10);
    v158 = *((unsigned __int8 *)v142 + 14);
    if ( (v157 & 1) != 0 )
      goto LABEL_206;
    if ( !*((_BYTE *)v142 + 14) )
      goto LABEL_215;
    v159 = 0;
    v160 = 0;
    v161 = 0;
    v162 = *((unsigned __int8 *)v142 + 14);
    v163 = (unsigned __int16 *)((char *)*v109 + 2);
    do
    {
      v165 = *v163;
      v163 += 2;
      v164 = v165;
      if ( v165 == 4 )
      {
        v161 = 1;
      }
      else if ( v164 == 4096 )
      {
        v160 = 1;
      }
      else if ( v164 == 768 )
      {
        v159 = 1;
      }
      --v162;
    }
    while ( v162 );
    if ( (v160 & v159 & v161 & 1) == 0 )
    {
LABEL_206:
      if ( *((_BYTE *)v142 + 14) )
      {
        v166 = 0;
        v167 = 0;
        v168 = 0;
        v169 = (unsigned __int16 *)((char *)*v109 + 2);
        do
        {
          v171 = *v169;
          v169 += 2;
          v170 = v171;
          if ( v171 == 4 )
          {
            v168 = 1;
          }
          else if ( v170 == 4096 )
          {
            v167 = 1;
          }
          else if ( v170 == 768 )
          {
            v166 = 1;
          }
          --v158;
        }
        while ( v158 );
        v172 = (_QWORD *)v10[1040];
        if ( (v167 & v166 & v168 & 1) != 0 )
        {
          if ( v98 )
          {
            v173 = 0;
            v174 = (_QWORD *)v10[1040];
            while ( 1 )
            {
              v175 = &v172[3 * v173];
              if ( *((_WORD *)v175 + 6) == 2 )
              {
                v176 = *((unsigned __int8 *)v175 + 14);
                if ( *((_BYTE *)v175 + 14) )
                {
                  v177 = 0;
                  v178 = 0;
                  v179 = (unsigned __int16 *)(*v175 + 2LL);
                  do
                  {
                    v181 = *v179;
                    v179 += 2;
                    v180 = v181;
                    if ( v181 == 4096 )
                    {
                      v178 = 1;
                    }
                    else if ( v180 == 4 )
                    {
                      v177 = 1;
                    }
                    --v176;
                  }
                  while ( v176 );
                  if ( (v178 & v177 & 1) != 0 )
                    break;
                }
              }
              ++v173;
              v174 += 3;
              if ( v173 == v98 )
                goto LABEL_229;
            }
            v199 = (unsigned int)v98 - 1;
            if ( (int)v199 > (unsigned __int8)v173 )
            {
              v200 = v174;
              do
              {
                v201 = v174[4];
                v202 = v174[5];
                ++v173;
                v203 = v200[3];
                v200 += 3;
                *v174 = v203;
                v174[1] = v201;
                v174[2] = v202;
                v174 = v200;
              }
              while ( v173 < v199 );
              v172 = (_QWORD *)v10[1040];
            }
            v182 = -1;
          }
          else
          {
LABEL_229:
            v182 = 0;
          }
          v183 = v182 + v98;
          if ( v183 )
          {
            v184 = 0;
            v185 = v172;
            while ( 1 )
            {
              v186 = &v172[3 * v184];
              if ( *((_WORD *)v186 + 6) == 2 )
              {
                v187 = *((unsigned __int8 *)v186 + 14);
                if ( *((_BYTE *)v186 + 14) )
                {
                  v188 = 0;
                  v189 = 0;
                  v190 = (unsigned __int16 *)(*v186 + 2LL);
                  do
                  {
                    v192 = *v190;
                    v190 += 2;
                    v191 = v192;
                    if ( v192 == 768 )
                    {
                      v189 = 1;
                    }
                    else if ( v191 == 4 )
                    {
                      v188 = 1;
                    }
                    --v187;
                  }
                  while ( v187 );
                  if ( (v189 & v188 & 1) != 0 )
                    break;
                }
              }
              ++v184;
              v185 += 3;
              if ( v184 == v183 )
                goto LABEL_242;
            }
            v204 = (unsigned int)v183 - 1;
            if ( (int)v204 > (unsigned __int8)v184 )
            {
              v205 = v185;
              do
              {
                v206 = v185[4];
                v207 = v185[5];
                ++v184;
                v208 = v205[3];
                v205 += 3;
                *v185 = v208;
                v185[1] = v206;
                v185[2] = v207;
                v185 = v205;
              }
              while ( v184 < v204 );
              v172 = (_QWORD *)v10[1040];
            }
            v193 = -1;
          }
          else
          {
LABEL_242:
            v193 = 0;
          }
          v98 = v193 + v183;
        }
      }
      else
      {
LABEL_215:
        v172 = (_QWORD *)v10[1040];
      }
      v194 = &v172[3 * v98];
      *v194 = *v109;
      v194[1] = v109[1];
      v194[2] = v109[2];
      if ( (v244 & 1) == 0 )
        *(_BYTE *)(v10[1040] + 24LL * v98 + 15) = 1;
      ++v98;
    }
LABEL_110:
    ++v97;
  }
  while ( v97 != 15 );
  v209 = v10[1040];
  v241 = v10;
  *(_DWORD *)(v9 + 88) = v98;
  v245 = v209;
  *(_QWORD *)(v9 + 80) = v209;
  v259 = 0;
  memset(v258, 0, sizeof(v258));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: max combinations %d",
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    "wlan_hdd_dump_iface_combinations",
    v98);
  if ( v98 )
  {
    v218 = 0;
    while ( 1 )
    {
      v247 = v218;
      v219 = (__int64 *)(v245 + 24 * v218);
      v220 = *((_BYTE *)v219 + 14);
      if ( v220 )
        break;
LABEL_267:
      qdf_trace_msg(
        0x33u,
        8u,
        "iface combination[%d]: %s",
        v210,
        v211,
        v212,
        v213,
        v214,
        v215,
        v216,
        v217,
        (unsigned int)v247,
        v258);
      v218 = v247 + 1;
      if ( v247 + 1 == v98 )
        goto LABEL_298;
    }
    v221 = *v219;
    v222 = 0;
    v223 = 0;
    while ( !*(_WORD *)(v221 + 4 * v222) )
    {
LABEL_271:
      if ( ++v222 >= (unsigned __int64)v220 )
        goto LABEL_267;
    }
    v224 = 0;
    while ( 2 )
    {
      v227 = *(unsigned __int16 *)(v221 + 4 * v222 + 2);
      if ( *(_WORD *)(v221 + 4 * v222 + 2) )
      {
        if ( v223 >= 0x65u )
          goto LABEL_310;
        if ( v224 | (unsigned int)v222 )
          v228 = "+%s";
        else
          v228 = "%s";
        if ( *(unsigned __int16 *)(v221 + 4 * v222 + 2) <= 0xFFu )
        {
          switch ( v227 )
          {
            case 4:
              v225 = "STA";
              break;
            case 8:
              v225 = "SAP";
              break;
            case 64:
              v225 = "MONITOR";
              break;
            default:
              goto LABEL_294;
          }
        }
        else if ( *(unsigned __int16 *)(v221 + 4 * v222 + 2) > 0x2FFu )
        {
          if ( v227 == 768 )
          {
            v225 = "(P2P_CLI or P2P_GO)";
          }
          else
          {
            if ( v227 != 4096 )
              goto LABEL_294;
            v225 = "NAN";
          }
        }
        else if ( v227 == 256 )
        {
          v225 = "P2P_CLIENT";
        }
        else
        {
          if ( v227 == 512 )
          {
            v225 = "P2P_GO";
            goto LABEL_275;
          }
LABEL_294:
          v225 = "invalid iface";
        }
LABEL_275:
        v210 = scnprintf((char *)v258 + v223, 100LL - v223, v228, v225);
        v221 = *v219;
        v223 += v226;
      }
      if ( ++v224 >= (unsigned int)*(unsigned __int16 *)(v221 + 4 * v222) )
      {
        v220 = *((_BYTE *)v219 + 14);
        goto LABEL_271;
      }
      continue;
    }
  }
LABEL_298:
  v10 = v241;
  v9 = v242;
LABEL_299:
  if ( (ucfg_scan_is_mac_spoofing_enabled(*v10) & 1) != 0 )
    *(_DWORD *)(v9 + 108) |= 0x60000000u;
  wlan_wifi_pos_cfg80211_set_wiphy_ext_feature(v9, *v10);
  v229 = *v10;
  LOBYTE(v258[0]) = 0;
  wlan_psoc_mlme_get_11be_capab(v229, (bool *)v258);
  if ( LOBYTE(v258[0]) )
    v230 = *(_DWORD *)(v9 + 100) | 2;
  else
    v230 = *(_DWORD *)(v9 + 100);
  *(_DWORD *)(v9 + 100) = v230 | 0x801;
  if ( (sme_is_feature_supported_by_fw(15) & 1) != 0 )
    *(_BYTE *)(v9 + 119) |= 0x80u;
  result = wlan_mlme_is_multipass_sap(*v10, v231, v232, v233, v234, v235, v236, v237, v238);
  if ( (result & 1) != 0 )
    *(_BYTE *)(v10[3] + 116) |= 0x80u;
  *(_BYTE *)(v9 + 114) |= 0x20u;
LABEL_309:
  _ReadStatusReg(SP_EL0);
  return result;
}
