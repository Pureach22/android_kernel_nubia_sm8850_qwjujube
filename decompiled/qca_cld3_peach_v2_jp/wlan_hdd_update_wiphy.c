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
  __int64 v9; // x22
  __int64 *v10; // x23
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
  int v93; // w26
  char v94; // w24
  char is_sta_p2p_ndp_supported; // w25
  __int64 v96; // x27
  bool v97; // zf
  char v98; // w8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  _UNKNOWN **v107; // x22
  _WORD *v108; // x9
  unsigned __int64 v109; // x8
  int v110; // w10
  int v111; // w11
  unsigned __int16 *v112; // x12
  __int64 v113; // x13
  int v114; // w14
  int v115; // t1
  unsigned __int16 *v116; // x8
  int v117; // w9
  int v118; // w8
  char v119; // w10
  char v120; // w12
  __int64 v121; // x13
  unsigned __int16 *v122; // x10
  unsigned __int16 *v123; // x14
  int v124; // w15
  int v125; // t1
  int v126; // w11
  int v127; // w12
  unsigned __int16 *v128; // x13
  __int64 v129; // x14
  int v130; // w15
  int v131; // t1
  int v132; // w10
  int v133; // w11
  int v134; // w12
  unsigned __int16 *v135; // x9
  int v136; // w13
  int v137; // t1
  int v138; // w11
  int v139; // w12
  int v140; // w13
  __int64 v141; // x14
  int v142; // w15
  int v143; // t1
  unsigned __int64 v144; // x10
  unsigned __int16 *v145; // x11
  int v146; // t1
  __int64 v147; // x8
  int v148; // w10
  int v149; // w11
  __int64 v150; // x13
  unsigned __int16 *v151; // x9
  unsigned __int16 *v152; // x12
  int v153; // w14
  int v154; // t1
  int v155; // w10
  int v156; // w11
  int v157; // w12
  int v158; // t1
  char v159; // w0
  __int64 v160; // x8
  int v161; // w9
  int v162; // w10
  int v163; // w11
  __int64 v164; // x13
  unsigned __int16 *v165; // x12
  int v166; // w14
  int v167; // t1
  int v168; // w9
  int v169; // w10
  int v170; // w11
  unsigned __int16 *v171; // x12
  int v172; // w13
  int v173; // t1
  _QWORD *v174; // x8
  unsigned __int64 v175; // x9
  _QWORD *v176; // x10
  _QWORD *v177; // x15
  __int64 v178; // x12
  int v179; // w13
  int v180; // w14
  unsigned __int16 *v181; // x15
  int v182; // w16
  int v183; // t1
  char v184; // w9
  unsigned __int8 v185; // w9
  unsigned __int64 v186; // x10
  _QWORD *v187; // x11
  _QWORD *v188; // x16
  __int64 v189; // x13
  int v190; // w14
  int v191; // w15
  unsigned __int16 *v192; // x16
  int v193; // w17
  int v194; // t1
  char v195; // w10
  _QWORD *v196; // x8
  unsigned __int64 v197; // x11
  _QWORD *v198; // x8
  __int64 v199; // x13
  __int64 v200; // x14
  __int64 v201; // t1
  unsigned __int64 v202; // x12
  _QWORD *v203; // x8
  __int64 v204; // x14
  __int64 v205; // x15
  __int64 v206; // t1
  unsigned __int8 v207; // w19
  __int64 v208; // x9
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  __int64 v217; // x20
  __int64 *v218; // x23
  unsigned __int8 v219; // w9
  __int64 v220; // x8
  __int64 v221; // x20
  unsigned __int8 v222; // w24
  int v223; // w21
  const char *v224; // x3
  char v225; // w0
  int v226; // w9
  const char *v227; // x2
  __int64 v228; // x0
  int v229; // w8
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  int v238; // [xsp+8h] [xbp-C8h]
  __int64 *v239; // [xsp+8h] [xbp-C8h]
  __int64 v240; // [xsp+10h] [xbp-C0h]
  int is_allowed; // [xsp+18h] [xbp-B8h]
  char v242; // [xsp+20h] [xbp-B0h]
  __int64 v243; // [xsp+20h] [xbp-B0h]
  unsigned __int8 v244; // [xsp+28h] [xbp-A8h]
  __int64 v245; // [xsp+28h] [xbp-A8h]
  char v246[4]; // [xsp+30h] [xbp-A0h] BYREF
  char v247[4]; // [xsp+34h] [xbp-9Ch] BYREF
  char v248[4]; // [xsp+38h] [xbp-98h] BYREF
  char v249[4]; // [xsp+3Ch] [xbp-94h] BYREF
  char v250[4]; // [xsp+40h] [xbp-90h] BYREF
  char v251[4]; // [xsp+44h] [xbp-8Ch] BYREF
  int v252; // [xsp+48h] [xbp-88h] BYREF
  char v253[4]; // [xsp+4Ch] [xbp-84h] BYREF
  char v254[4]; // [xsp+50h] [xbp-80h] BYREF
  _BYTE v255[4]; // [xsp+54h] [xbp-7Ch] BYREF
  _QWORD v256[12]; // [xsp+58h] [xbp-78h] BYREF
  int v257; // [xsp+B8h] [xbp-18h]
  __int64 v258; // [xsp+C0h] [xbp-10h]

  v258 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[3];
  v252 = 0;
  v251[0] = 0;
  v250[0] = 0;
  v249[0] = 0;
  v248[0] = 0;
  v247[0] = 0;
  v246[0] = 0;
  if ( !v9 )
  {
    result = qdf_trace_msg(0x33u, 2u, "%s: Invalid wiphy", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_update_wiphy");
    goto LABEL_306;
  }
  v10 = a1;
  wlan_mlme_get_sap_max_peers(*a1, &v252);
  v11 = v10[3];
  *(_WORD *)v253 = 0;
  *(_WORD *)(v11 + 1392) = v252;
  v12 = *v10;
  LODWORD(v256[0]) = 0;
  if ( (unsigned int)wlan_mlme_get_ht_cap_info(v12, v253) )
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
    if ( v253[0] < 0 )
      *(_WORD *)(v22 + 28) |= 0x80u;
    if ( (sme_is_feature_supported_by_fw(2) & 1) != 0 )
    {
      if ( (v253[0] & 0x20) != 0 )
        goto LABEL_9;
    }
    else
    {
      *(_BYTE *)(v22 + 52) = 0;
      *(_DWORD *)(v22 + 56) = 0;
      if ( (v253[0] & 0x20) != 0 )
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
                        goto LABEL_307;
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
  if ( v253[0] < 0 )
    *(_WORD *)(v23 + 28) |= 0x80u;
  if ( (sme_is_feature_supported_by_fw(2) & 1) != 0 )
  {
    v26 = v253[0];
    if ( (v253[0] & 0x20) != 0 )
      goto LABEL_31;
  }
  else
  {
    *(_BYTE *)(v23 + 52) = 0;
    *(_DWORD *)(v23 + 56) = 0;
    v26 = v253[0];
    if ( (v253[0] & 0x20) != 0 )
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
  ucfg_mlme_get_channel_bonding_5ghz(*v10, (int *)v256);
  if ( LODWORD(v256[0]) )
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
LABEL_307:
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
  LODWORD(v256[0]) = 0;
  if ( !(unsigned int)wlan_mlme_get_band_capability(v28, v256) )
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
      if ( v83 || LODWORD(v256[0]) != 2 )
      {
        if ( v83 != 1 || LODWORD(v256[0]) != 1 )
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
  LOBYTE(v256[0]) = 0;
  v253[0] = 0;
  v255[0] = 0;
  v254[0] = 0;
  ucfg_mlme_is_fast_transition_enabled(v37, (char *)v256);
  ucfg_mlme_is_lfr_enabled(*v10, v253);
  ucfg_mlme_is_ese_enabled(*v10, v255);
  ucfg_mlme_get_roaming_offload(*v10, v254);
  if ( (v256[0] & 1) != 0 || (v253[0] & 1) != 0 || (v255[0] & 1) != 0 || v254[0] == 1 )
    *(_DWORD *)(v10[3] + 100) |= 0x2000u;
  v38 = v10[3];
  v251[0] = 0;
  *(_DWORD *)(v38 + 124) |= 1u;
  if ( (unsigned int)wlan_mlme_get_fils_enabled_info(*v10, v251) )
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
  if ( v251[0] == 1 )
    *(_BYTE *)(v9 + 113) |= 0x40u;
  *(_BYTE *)(v9 + 115) |= 2u;
  if ( !(unsigned int)wlan_mlme_get_bigtk_support(*v10, v247) && v247[0] == 1 )
    *(_BYTE *)(v9 + 117) |= 2u;
  if ( !(unsigned int)wlan_mlme_get_ocv_support(*v10, v246) && v246[0] == 1 )
    *(_BYTE *)(v9 + 118) |= 2u;
  if ( (unsigned int)wlan_mlme_get_oce_sta_enabled_info(*v10, v250) )
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
  if ( v250[0] == 1 )
    *(_BYTE *)(v9 + 114) |= 0x1Eu;
  if ( (ucfg_fwol_get_sae_enable(*(_QWORD *)(v9 + 1536)) & 1) != 0 )
    *(_DWORD *)(v9 + 108) |= 0x20u;
  if ( (unsigned int)ucfg_policy_mgr_get_allow_mcc_go_diff_bi(*v10, v249) )
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
  if ( (unsigned int)wlan_mlme_get_mcc_feature(*v10, v248) )
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
    goto LABEL_296;
  v71 = *v10;
  v72 = (unsigned __int8)v249[0];
  v73 = (unsigned __int8)v248[0];
  v253[0] = 0;
  v255[0] = 0;
  if ( (unsigned int)ucfg_policy_mgr_get_dbs_hw_modes(v71, v253, v255) )
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
    goto LABEL_296;
  }
  v238 = *(unsigned __int8 *)(cfg_psoc_get_values(v71) + 3911);
  v93 = *(unsigned __int8 *)(cfg_psoc_get_values(v71) + 3914);
  v94 = *(_BYTE *)(cfg_psoc_get_values(v71) + 3910);
  is_sta_p2p_ndp_supported = ucfg_nan_is_sta_p2p_ndp_supported(v71);
  is_allowed = ucfg_nan_is_allowed(v71);
  if ( (is_allowed & 1) != 0 )
    *(_WORD *)(v9 + 96) |= 0x1000u;
  v96 = 0;
  if ( v72 )
    v97 = 1;
  else
    v97 = v73 == 0;
  v98 = v97;
  v240 = v9;
  v244 = 0;
  v242 = v98;
  do
  {
    if ( (ucfg_policy_mgr_is_fw_supports_dbs(v71) & 1) == 0 )
    {
      if ( *((unsigned __int16 *)&wlan_hdd_iface_combination + 12 * v96 + 6) > 2u )
        goto LABEL_110;
      v116 = (unsigned __int16 *)*(&wlan_hdd_iface_combination + 3 * v96);
      v117 = v116[1];
      v118 = *v116;
      if ( (v117 == 8 || v117 == 4 || v117 == 768) && v118 == 2 )
        goto LABEL_110;
    }
    if ( v253[0] == 1 && (v255[0] & 1) == 0 && *((unsigned __int16 *)&wlan_hdd_iface_combination + 12 * v96 + 6) > 2u )
      goto LABEL_110;
    v107 = &wlan_hdd_iface_combination + 3 * v96;
    v108 = *v107;
    if ( *((_WORD *)*v107 + 1) == 4 && *v108 == 1 && v108[3] == 8 && v108[2] == 2 )
      goto LABEL_110;
    if ( v238 )
    {
      v109 = *((unsigned __int8 *)v107 + 14);
      if ( *((_WORD *)v107 + 6) != 2 )
        goto LABEL_137;
      if ( !*((_BYTE *)v107 + 14) )
        goto LABEL_153;
      v110 = 0;
      v111 = 0;
      v112 = v108 + 1;
      v113 = *((unsigned __int8 *)v107 + 14);
      do
      {
        v115 = *v112;
        v112 += 2;
        v114 = v115;
        if ( v115 == 768 )
        {
          v111 = 1;
        }
        else if ( v114 == 4 )
        {
          v110 = 1;
        }
        --v113;
      }
      while ( v113 );
      if ( (v111 & v110 & 1) == 0 )
      {
LABEL_137:
        if ( !*((_BYTE *)v107 + 14) )
        {
LABEL_153:
          v109 = 0;
          v119 = 1;
          if ( (v94 & 1) == 0 )
            goto LABEL_154;
          goto LABEL_184;
        }
        v120 = 0;
        v121 = 0;
        v122 = v108 + 1;
LABEL_140:
        v123 = &v122[2 * v121];
        do
        {
          v125 = *v123;
          v123 += 2;
          v124 = v125;
          if ( v125 == 256 || v124 == 512 || v124 == 768 )
          {
            v92 = v109 - 1 == v121++;
            v120 = 1;
            if ( !v92 )
              goto LABEL_140;
            goto LABEL_146;
          }
          ++v121;
        }
        while ( v109 != v121 );
        if ( (v120 & 1) == 0 )
          goto LABEL_178;
LABEL_146:
        if ( !v93 )
          goto LABEL_177;
        v126 = 0;
        v127 = 0;
        v128 = v108 + 1;
        v129 = *((unsigned __int8 *)v107 + 14);
        do
        {
          v131 = *v128;
          v128 += 2;
          v130 = v131;
          if ( v131 == 4 )
          {
            v126 = 1;
          }
          else if ( v130 == 8 )
          {
            v127 = 1;
          }
          --v129;
        }
        while ( v129 );
        if ( (v126 & v127 & 1) == 0 )
        {
LABEL_177:
          if ( (is_sta_p2p_ndp_supported & 1) == 0 )
            goto LABEL_110;
          v138 = 0;
          v139 = 0;
          v140 = 0;
          v141 = *((unsigned __int8 *)v107 + 14);
          do
          {
            v143 = *v122;
            v122 += 2;
            v142 = v143;
            if ( v143 == 4 )
            {
              v140 = 1;
            }
            else if ( v142 == 4096 )
            {
              v139 = 1;
            }
            else if ( v142 == 768 )
            {
              v138 = 1;
            }
            --v141;
          }
          while ( v141 );
          if ( (v139 & v138 & v140 & 1) == 0 )
            goto LABEL_110;
        }
      }
    }
    else
    {
      v109 = *((unsigned __int8 *)v107 + 14);
      if ( !*((_BYTE *)v107 + 14) )
      {
        v119 = 1;
LABEL_154:
        if ( *((_WORD *)v107 + 6) != 4 )
          v119 = 1;
        if ( (v119 & 1) == 0 )
        {
          v132 = 0;
          v133 = 0;
          v134 = 0;
          v135 = v108 + 1;
          do
          {
            v137 = *v135;
            v135 += 2;
            v136 = v137;
            if ( v137 == 4 )
            {
              v132 = 1;
            }
            else if ( v136 == 4096 )
            {
              v134 = 1;
            }
            else if ( v136 == 8 )
            {
              v133 = 1;
            }
            --v109;
          }
          while ( v109 );
          if ( (v134 & v133 & v132 & 1) != 0 )
            goto LABEL_110;
        }
        goto LABEL_201;
      }
    }
LABEL_178:
    v144 = 0;
    v145 = v108 + 1;
    while ( 1 )
    {
      v146 = *v145;
      v145 += 2;
      if ( v146 == 4096 )
        break;
      if ( v109 == ++v144 )
        goto LABEL_183;
    }
    if ( ((v144 < v109) & ~is_allowed) != 0 )
      goto LABEL_110;
LABEL_183:
    v119 = 0;
    if ( (v94 & 1) == 0 )
      goto LABEL_154;
LABEL_184:
    if ( (ucfg_policy_mgr_is_fw_supports_dbs(v71) & 1) != 0 && *((_WORD *)v107 + 6) == 2 )
    {
      v147 = *((unsigned __int8 *)v107 + 14);
      if ( *((_BYTE *)v107 + 14) )
      {
        v148 = 0;
        v149 = 0;
        v150 = *((unsigned __int8 *)v107 + 14);
        v151 = (unsigned __int16 *)((char *)*v107 + 2);
        v152 = v151;
        do
        {
          v154 = *v152;
          v152 += 2;
          v153 = v154;
          if ( v154 == 4096 )
          {
            v149 = 1;
          }
          else if ( v153 == 4 )
          {
            v148 = 1;
          }
          --v150;
        }
        while ( v150 );
        if ( (v149 & v148 & 1) != 0 )
          goto LABEL_110;
        v155 = 0;
        v156 = 0;
        do
        {
          v158 = *v151;
          v151 += 2;
          v157 = v158;
          if ( v158 == 4096 )
          {
            v156 = 1;
          }
          else if ( v157 == 8 )
          {
            v155 = 1;
          }
          --v147;
        }
        while ( v147 );
        if ( (v156 & v155 & 1) != 0 )
          goto LABEL_110;
      }
    }
LABEL_201:
    v159 = ucfg_nan_is_sta_p2p_ndp_supported(*v10);
    v160 = *((unsigned __int8 *)v107 + 14);
    if ( (v159 & 1) != 0 )
      goto LABEL_212;
    if ( !*((_BYTE *)v107 + 14) )
      goto LABEL_221;
    v161 = 0;
    v162 = 0;
    v163 = 0;
    v164 = *((unsigned __int8 *)v107 + 14);
    v165 = (unsigned __int16 *)((char *)*v107 + 2);
    do
    {
      v167 = *v165;
      v165 += 2;
      v166 = v167;
      if ( v167 == 4 )
      {
        v163 = 1;
      }
      else if ( v166 == 4096 )
      {
        v162 = 1;
      }
      else if ( v166 == 768 )
      {
        v161 = 1;
      }
      --v164;
    }
    while ( v164 );
    if ( (v162 & v161 & v163 & 1) == 0 )
    {
LABEL_212:
      if ( *((_BYTE *)v107 + 14) )
      {
        v168 = 0;
        v169 = 0;
        v170 = 0;
        v171 = (unsigned __int16 *)((char *)*v107 + 2);
        do
        {
          v173 = *v171;
          v171 += 2;
          v172 = v173;
          if ( v173 == 4 )
          {
            v170 = 1;
          }
          else if ( v172 == 4096 )
          {
            v169 = 1;
          }
          else if ( v172 == 768 )
          {
            v168 = 1;
          }
          --v160;
        }
        while ( v160 );
        v174 = (_QWORD *)v10[1036];
        if ( (v169 & v168 & v170 & 1) != 0 )
        {
          if ( v244 )
          {
            v175 = 0;
            v176 = (_QWORD *)v10[1036];
            while ( 1 )
            {
              v177 = &v174[3 * v175];
              if ( *((_WORD *)v177 + 6) == 2 )
              {
                v178 = *((unsigned __int8 *)v177 + 14);
                if ( *((_BYTE *)v177 + 14) )
                {
                  v179 = 0;
                  v180 = 0;
                  v181 = (unsigned __int16 *)(*v177 + 2LL);
                  do
                  {
                    v183 = *v181;
                    v181 += 2;
                    v182 = v183;
                    if ( v183 == 4096 )
                    {
                      v180 = 1;
                    }
                    else if ( v182 == 4 )
                    {
                      v179 = 1;
                    }
                    --v178;
                  }
                  while ( v178 );
                  if ( (v180 & v179 & 1) != 0 )
                    break;
                }
              }
              ++v175;
              v176 += 3;
              if ( v175 == v244 )
                goto LABEL_235;
            }
            v197 = (unsigned int)v244 - 1;
            if ( (int)v197 > (unsigned __int8)v175 )
            {
              v198 = v176;
              do
              {
                v199 = v176[4];
                v200 = v176[5];
                ++v175;
                v201 = v198[3];
                v198 += 3;
                *v176 = v201;
                v176[1] = v199;
                v176[2] = v200;
                v176 = v198;
              }
              while ( v175 < v197 );
              v174 = (_QWORD *)v10[1036];
            }
            v184 = -1;
          }
          else
          {
LABEL_235:
            v184 = 0;
          }
          v185 = v184 + v244;
          if ( v185 )
          {
            v186 = 0;
            v187 = v174;
            while ( 1 )
            {
              v188 = &v174[3 * v186];
              if ( *((_WORD *)v188 + 6) == 2 )
              {
                v189 = *((unsigned __int8 *)v188 + 14);
                if ( *((_BYTE *)v188 + 14) )
                {
                  v190 = 0;
                  v191 = 0;
                  v192 = (unsigned __int16 *)(*v188 + 2LL);
                  do
                  {
                    v194 = *v192;
                    v192 += 2;
                    v193 = v194;
                    if ( v194 == 768 )
                    {
                      v191 = 1;
                    }
                    else if ( v193 == 4 )
                    {
                      v190 = 1;
                    }
                    --v189;
                  }
                  while ( v189 );
                  if ( (v191 & v190 & 1) != 0 )
                    break;
                }
              }
              ++v186;
              v187 += 3;
              if ( v186 == v185 )
                goto LABEL_248;
            }
            v202 = (unsigned int)v185 - 1;
            if ( (int)v202 > (unsigned __int8)v186 )
            {
              v203 = v187;
              do
              {
                v204 = v187[4];
                v205 = v187[5];
                ++v186;
                v206 = v203[3];
                v203 += 3;
                *v187 = v206;
                v187[1] = v204;
                v187[2] = v205;
                v187 = v203;
              }
              while ( v186 < v202 );
              v174 = (_QWORD *)v10[1036];
            }
            v195 = -1;
          }
          else
          {
LABEL_248:
            v195 = 0;
          }
          v244 = v195 + v185;
        }
      }
      else
      {
LABEL_221:
        v174 = (_QWORD *)v10[1036];
      }
      v196 = &v174[3 * v244];
      *v196 = *v107;
      v196[1] = v107[1];
      v196[2] = v107[2];
      if ( (v242 & 1) == 0 )
        *(_BYTE *)(v10[1036] + 24LL * v244 + 15) = 1;
      ++v244;
    }
LABEL_110:
    ++v96;
  }
  while ( v96 != 15 );
  v207 = v244;
  v208 = v10[1036];
  v239 = v10;
  *(_DWORD *)(v240 + 88) = v244;
  v243 = v208;
  *(_QWORD *)(v240 + 80) = v208;
  v257 = 0;
  memset(v256, 0, sizeof(v256));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: max combinations %d",
    v99,
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    "wlan_hdd_dump_iface_combinations",
    v244);
  if ( v244 )
  {
    v217 = 0;
    while ( 1 )
    {
      v245 = v217;
      v218 = (__int64 *)(v243 + 24 * v217);
      v219 = *((_BYTE *)v218 + 14);
      if ( v219 )
        break;
LABEL_264:
      qdf_trace_msg(
        0x33u,
        8u,
        "iface combination[%d]: %s",
        v209,
        v210,
        v211,
        v212,
        v213,
        v214,
        v215,
        v216,
        (unsigned int)v245,
        v256);
      v217 = v245 + 1;
      if ( v245 + 1 == v207 )
        goto LABEL_295;
    }
    v220 = *v218;
    v221 = 0;
    v222 = 0;
    while ( !*(_WORD *)(v220 + 4 * v221) )
    {
LABEL_268:
      if ( ++v221 >= (unsigned __int64)v219 )
        goto LABEL_264;
    }
    v223 = 0;
    while ( 2 )
    {
      v226 = *(unsigned __int16 *)(v220 + 4 * v221 + 2);
      if ( *(_WORD *)(v220 + 4 * v221 + 2) )
      {
        if ( v222 >= 0x65u )
          goto LABEL_307;
        if ( v223 | (unsigned int)v221 )
          v227 = "+%s";
        else
          v227 = "%s";
        if ( *(unsigned __int16 *)(v220 + 4 * v221 + 2) <= 0xFFu )
        {
          switch ( v226 )
          {
            case 4:
              v224 = "STA";
              break;
            case 8:
              v224 = "SAP";
              break;
            case 64:
              v224 = "MONITOR";
              break;
            default:
              goto LABEL_291;
          }
        }
        else if ( *(unsigned __int16 *)(v220 + 4 * v221 + 2) > 0x2FFu )
        {
          if ( v226 == 768 )
          {
            v224 = "(P2P_CLI or P2P_GO)";
          }
          else
          {
            if ( v226 != 4096 )
              goto LABEL_291;
            v224 = "NAN";
          }
        }
        else if ( v226 == 256 )
        {
          v224 = "P2P_CLIENT";
        }
        else
        {
          if ( v226 == 512 )
          {
            v224 = "P2P_GO";
            goto LABEL_272;
          }
LABEL_291:
          v224 = "invalid iface";
        }
LABEL_272:
        v209 = scnprintf((char *)v256 + v222, 100LL - v222, v227, v224);
        v220 = *v218;
        v222 += v225;
      }
      if ( ++v223 >= (unsigned int)*(unsigned __int16 *)(v220 + 4 * v221) )
      {
        v219 = *((_BYTE *)v218 + 14);
        goto LABEL_268;
      }
      continue;
    }
  }
LABEL_295:
  v10 = v239;
  v9 = v240;
LABEL_296:
  if ( (ucfg_scan_is_mac_spoofing_enabled(*v10) & 1) != 0 )
    *(_DWORD *)(v9 + 108) |= 0x60000000u;
  wlan_wifi_pos_cfg80211_set_wiphy_ext_feature(v9, *v10);
  v228 = *v10;
  LOBYTE(v256[0]) = 0;
  wlan_psoc_mlme_get_11be_capab(v228, (bool *)v256);
  if ( LOBYTE(v256[0]) )
    v229 = *(_DWORD *)(v9 + 100) | 2;
  else
    v229 = *(_DWORD *)(v9 + 100);
  *(_DWORD *)(v9 + 100) = v229 | 0x801;
  if ( (sme_is_feature_supported_by_fw(15) & 1) != 0 )
    *(_BYTE *)(v9 + 119) |= 0x80u;
  result = wlan_mlme_is_multipass_sap(*v10, v230, v231, v232, v233, v234, v235, v236, v237);
  if ( (result & 1) != 0 )
    *(_BYTE *)(v10[3] + 116) |= 0x80u;
  *(_BYTE *)(v9 + 114) |= 0x20u;
LABEL_306:
  _ReadStatusReg(SP_EL0);
  return result;
}
