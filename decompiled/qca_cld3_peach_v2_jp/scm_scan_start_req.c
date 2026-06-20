__int64 __fastcall scm_scan_start_req(
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
  _QWORD *v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 comp_private_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w9
  __int64 v28; // x22
  const char *v29; // x26
  int v30; // w8
  __int64 v31; // x21
  int v32; // w9
  __int64 v33; // x8
  const char *v34; // x2
  __int64 result; // x0
  const char *v36; // x2
  unsigned int v37; // w1
  int v38; // w8
  int v39; // w9
  __int64 v40; // x23
  int v41; // w9
  int v42; // w9
  unsigned int v43; // w8
  unsigned int v44; // w9
  unsigned int v45; // w9
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w8
  __int64 v55; // x23
  __int64 v56; // x22
  __int64 v57; // x21
  int v58; // w8
  char v59; // w9
  __int64 v60; // x24
  __int64 v61; // x25
  const char *v62; // x20
  int v63; // w27
  int v64; // w28
  int v65; // w23
  __int16 peer_count_for_mode; // w26
  __int16 v67; // w24
  __int64 v68; // x8
  __int64 v69; // x23
  unsigned int v70; // w23
  int v71; // w8
  int v72; // w9
  bool v73; // zf
  int v74; // w8
  bool v75; // zf
  unsigned int v76; // w8
  int v77; // w28
  unsigned int v78; // w8
  int v79; // w8
  int v80; // w9
  int v81; // w9
  unsigned int v82; // w9
  unsigned int v83; // w9
  __int64 v84; // x24
  unsigned __int16 channel; // w0
  unsigned __int16 v86; // w26
  unsigned int v87; // w8
  int v88; // w8
  int v89; // w4
  char v90; // w9
  int v91; // w8
  int v93; // w9
  __int64 v94; // x4
  __int64 v95; // x8
  __int64 v96; // x0
  unsigned int v97; // w8
  unsigned int v98; // w9
  unsigned int v99; // w12
  int v100; // w8
  int v101; // w20
  int wide_band_scan; // w0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  int v111; // w8
  unsigned int v112; // w9
  unsigned int v113; // w10
  int v114; // w8
  __int64 v115; // x23
  __int64 v116; // x0
  int v117; // w20
  int v118; // w21
  unsigned int *v119; // x25
  int v120; // w8
  int v122; // w28
  unsigned __int64 v123; // x22
  const char *v124; // x2
  unsigned int v125; // w27
  __int64 v126; // x10
  char *v127; // x8
  __int64 v128; // x22
  __int64 v129; // x23
  __int64 v130; // x0
  __int64 v131; // x0
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x24
  __int64 v141; // x27
  unsigned int v142; // w28
  unsigned __int64 v143; // x20
  unsigned int v144; // w25
  __int64 v145; // x10
  char *v146; // x8
  unsigned __int64 v147; // x4
  char v148; // w25
  __int64 v149; // x27
  __int64 v150; // x28
  unsigned __int64 v151; // x20
  __int64 v152; // x10
  char *v153; // x8
  unsigned __int64 v154; // x4
  unsigned __int64 v155; // x20
  unsigned int v156; // w25
  __int64 v157; // x10
  char *v158; // x8
  unsigned __int64 v159; // x4
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  __int64 v176; // x0
  __int64 v177; // x20
  int v178; // w0
  __int64 v179; // x20
  int v180; // w0
  unsigned int v181; // w27
  __int64 v182; // x20
  __int64 v183; // x1
  __int64 v184; // x0
  __int64 v185; // x8
  int v186; // w3
  int v187; // w4
  int v188; // w5
  int v189; // w6
  int v190; // w0
  unsigned int v191; // w8
  int v192; // w9
  unsigned int v193; // w22
  __int64 v194; // x0
  unsigned __int64 v195; // x20
  unsigned int v196; // w24
  char *v197; // x27
  int v198; // w0
  int v199; // w4
  int v200; // w8
  __int64 v201; // x8
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  unsigned int v210; // w0
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  __int64 v219; // x4
  bool v220; // cf
  unsigned int v221; // w20
  unsigned int v222; // w8
  int v223; // w9
  double v224; // d0
  unsigned int *v225; // x8
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  __int64 v233; // x0
  __int64 v234; // x0
  __int64 v235; // x0
  __int64 v236; // [xsp+0h] [xbp-F0h]
  __int64 v237; // [xsp+8h] [xbp-E8h]
  __int64 v238; // [xsp+10h] [xbp-E0h]
  __int64 v239; // [xsp+18h] [xbp-D8h]
  __int64 v240; // [xsp+20h] [xbp-D0h]
  __int64 v241; // [xsp+28h] [xbp-C8h]
  __int64 v242; // [xsp+30h] [xbp-C0h]
  int v243; // [xsp+58h] [xbp-98h]
  __int64 v244; // [xsp+58h] [xbp-98h]
  int v245; // [xsp+60h] [xbp-90h]
  const char *v246; // [xsp+60h] [xbp-90h]
  __int64 v247; // [xsp+68h] [xbp-88h]
  int v248; // [xsp+70h] [xbp-80h]
  char *v249; // [xsp+70h] [xbp-80h]
  __int64 v250; // [xsp+78h] [xbp-78h] BYREF
  void *v251; // [xsp+80h] [xbp-70h]
  __int64 v252; // [xsp+88h] [xbp-68h]
  __int64 v253; // [xsp+90h] [xbp-60h]
  __int64 v254; // [xsp+98h] [xbp-58h]
  _QWORD *v255; // [xsp+A0h] [xbp-50h]
  unsigned int v256; // [xsp+A8h] [xbp-48h] BYREF
  __int64 v257; // [xsp+ACh] [xbp-44h]
  int v258; // [xsp+B4h] [xbp-3Ch]
  int v259; // [xsp+B8h] [xbp-38h]
  int v260; // [xsp+BCh] [xbp-34h]
  __int64 v261; // [xsp+C0h] [xbp-30h]
  _QWORD *v262; // [xsp+C8h] [xbp-28h]
  __int64 v263; // [xsp+D0h] [xbp-20h]
  __int64 v264; // [xsp+E0h] [xbp-10h]

  v264 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v254 = 0;
  v255 = nullptr;
  v252 = 0;
  v253 = 0;
  v250 = 0;
  v251 = nullptr;
  if ( !a1 )
  {
    v34 = "%s: msg received is NULL";
LABEL_19:
    qdf_trace_msg(0x15u, 2u, v34, a2, a3, a4, a5, a6, a7, a8, a9, "scm_scan_start_req");
    result = 29;
    goto LABEL_359;
  }
  v9 = *(_QWORD **)(a1 + 8);
  if ( !v9 )
  {
    v34 = "%s: bodyptr is NULL";
    goto LABEL_19;
  }
  if ( (scm_is_scan_allowed(*v9, a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
  {
    v36 = "%s: scan disabled, rejecting the scan req";
    v37 = 2;
LABEL_351:
    qdf_trace_msg(0x15u, v37, v36, v10, v11, v12, v13, v14, v15, v16, v17, "scm_scan_start_req");
    v221 = 29;
    goto LABEL_352;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(*v9 + 152LL) + 80LL), 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    v36 = "%s: Couldn't find scan object";
    v37 = 8;
    goto LABEL_351;
  }
  v27 = *((_DWORD *)v9 + 17);
  v28 = *v9;
  v29 = (const char *)comp_private_obj;
  if ( !v27 )
  {
    v27 = *((_DWORD *)v9 + 9) >> 1;
    *((_DWORD *)v9 + 17) = v27;
  }
  v30 = *((_DWORD *)v9 + 23);
  if ( (v30 & 1) != 0 )
    *((_DWORD *)v9 + 518) |= 4u;
  v31 = comp_private_obj + 16256;
  if ( !*((_DWORD *)v9 + 29) )
  {
    if ( v27 )
      v27 = *((_DWORD *)v9 + 9) / v27;
    *((_DWORD *)v9 + 29) = v27;
  }
  v32 = *((_DWORD *)v9 + 7);
  if ( (unsigned int)(v32 - 1) > 1 )
  {
    v38 = v30 | 0x30020;
    if ( *((_DWORD *)v9 + 28) )
      v39 = 4;
    else
      v39 = 6;
    *((_DWORD *)v9 + 23) = v38 | v39;
    v33 = *(_QWORD *)(v28 + 152);
    if ( !v33 )
      goto LABEL_36;
    goto LABEL_26;
  }
  *((_DWORD *)v9 + 10) = 0;
  *((_DWORD *)v9 + 25) = 4;
  if ( v32 == 2 )
  {
    *((_DWORD *)v9 + 17) = 0;
    v33 = *(_QWORD *)(v28 + 152);
    if ( !v33 )
      goto LABEL_36;
    goto LABEL_26;
  }
  v41 = *((_DWORD *)v9 + 28);
  *((_DWORD *)v9 + 23) = v30 | 0x20;
  if ( !v41 )
    *((_DWORD *)v9 + 23) = v30 | 0x22;
  v42 = *((unsigned __int8 *)v9 + 120);
  v43 = *((_DWORD *)v9 + 9) + 20;
  *((_DWORD *)v9 + 9) = v43;
  if ( v42 == 3 && *(_BYTE *)(comp_private_obj + 18737) != 1 )
    v44 = 5;
  else
    v44 = 3;
  *((_DWORD *)v9 + 17) = v43 / v44;
  v45 = *(unsigned __int8 *)(comp_private_obj + 1737);
  if ( *(_BYTE *)(comp_private_obj + 1737) )
    goto LABEL_34;
  *((_DWORD *)v9 + 26) = 3 * v43;
  if ( 3 * v43 >= 0xB5 )
  {
    v45 = 180;
    if ( v43 <= 0xB4 )
      v45 = 0xB4u / (unsigned __int8)v43 * (unsigned __int8)v43;
LABEL_34:
    *((_DWORD *)v9 + 26) = v45;
  }
  *((_WORD *)v9 + 16) &= ~4u;
  v33 = *(_QWORD *)(v28 + 152);
  if ( !v33 )
  {
LABEL_36:
    v40 = 0;
    goto LABEL_37;
  }
LABEL_26:
  v40 = *(_QWORD *)(v33 + 80);
LABEL_37:
  if ( (policy_mgr_is_dbs_scan_allowed(v40) & 1) != 0 )
  {
    if ( (wlan_scan_cfg_honour_nl_scan_policy_flags(v40) & 1) != 0 )
    {
      if ( (unsigned int)policy_mgr_mode_specific_connection_count(v40, 4, 0)
        || (policy_mgr_is_hw_dbs_2x2_capable(v40) & 1) != 0 )
      {
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: NDP present or HW 2x2 capable, go for DBS scan",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "scm_update_dbs_scan_ctrl_ext_flag");
        v54 = 0;
      }
      else if ( (v9[12] & 1) != 0 )
      {
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: high accuracy scan received, going for non-dbs scan",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "scm_update_dbs_scan_ctrl_ext_flag");
        v54 = 1;
      }
      else if ( (v9[12] & 6) != 0 )
      {
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: low power/span scan received, going for dbs scan",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "scm_update_dbs_scan_ctrl_ext_flag");
        v54 = 2;
      }
      else
      {
        v54 = 0;
      }
    }
    else
    {
      v55 = v28;
      v56 = v31;
      v57 = jiffies;
      if ( scm_update_dbs_scan_ctrl_ext_flag___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: nl scan policy flags not honoured, goto end",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "scm_update_dbs_scan_ctrl_ext_flag");
        v54 = 0;
        scm_update_dbs_scan_ctrl_ext_flag___last_ticks = v57;
      }
      else
      {
        v54 = 0;
      }
      v31 = v56;
      v28 = v55;
    }
  }
  else
  {
    v54 = 1;
  }
  v58 = *((_DWORD *)v9 + 518) | v54;
  v59 = *((_BYTE *)v9 + 92);
  *((_DWORD *)v9 + 518) = v58;
  v60 = *(_QWORD *)(v28 + 152);
  if ( (v59 & 1) == 0 || *((_BYTE *)v9 + 120) != 1 )
  {
    if ( *((_DWORD *)v9 + 7) == 3 )
      goto LABEL_164;
    if ( !v60 )
      goto LABEL_165;
    v61 = *(_QWORD *)(v60 + 80);
    if ( v61 )
    {
      v62 = v29;
      v63 = policy_mgr_mode_specific_connection_count(*(_QWORD *)(v60 + 80), 1, 0);
      v64 = policy_mgr_mode_specific_connection_count(v61, 3, 0);
      v65 = policy_mgr_mode_specific_connection_count(v61, 2, 0);
      v248 = policy_mgr_mode_specific_connection_count(v61, 0, 0);
      v245 = policy_mgr_mode_specific_connection_count(v61, 4, 0);
      if ( v63 )
        peer_count_for_mode = wlan_util_get_peer_count_for_mode(v60, 1u);
      else
        peer_count_for_mode = 0;
      v243 = v65;
      if ( v64 )
        v67 = wlan_util_get_peer_count_for_mode(v60, 3u);
      else
        v67 = 0;
      if ( (*((_BYTE *)v9 + 92) & 1) == 0 )
      {
        v68 = *(_QWORD *)(v28 + 152);
        if ( v68 )
        {
          v69 = *(_QWORD *)(v68 + 80);
          if ( v69 )
          {
            if ( (policy_mgr_is_sta_connected_2g(*(_QWORD *)(v68 + 80)) & 1) != 0
              && (policy_mgr_is_hw_dbs_capable(v69) & 1) == 0
              && (ucfg_scan_get_bt_activity(v69) & 1) != 0 )
            {
              *((_DWORD *)v9 + 11) = 28;
            }
          }
        }
      }
      v70 = *((_DWORD *)v9 + 10);
      if ( (unsigned int)policy_mgr_get_connection_count(v61) )
      {
        v71 = *((_DWORD *)v9 + 23);
        if ( (v71 & 1) == 0 )
        {
          v72 = *((_DWORD *)v62 + 413);
          *((_DWORD *)v9 + 9) = v72;
          *((_DWORD *)v9 + 10) = v72;
        }
        if ( (v71 & 0x2000000) == 0 )
          *((_DWORD *)v9 + 11) = *((_DWORD *)v62 + 414);
        *((_DWORD *)v9 + 16) = *((_DWORD *)v62 + 415);
        *((_DWORD *)v9 + 15) = *((_DWORD *)v62 + 416);
        *((_DWORD *)v9 + 19) = *((_DWORD *)v62 + 417);
      }
      if ( (unsigned int)wlan_vdev_is_up() )
        *((_DWORD *)v9 + 25) = *((_DWORD *)v62 + 439);
      if ( v67 )
        v73 = v64 == 0;
      else
        v73 = 1;
      v74 = !v73;
      if ( peer_count_for_mode )
        v75 = v63 == 0;
      else
        v75 = 1;
      if ( !v75 || v74 )
      {
        if ( (policy_mgr_is_hw_dbs_capable(v61) & 1) != 0 && (policy_mgr_is_sap_go_on_2g(v61) & 1) != 0
          || (policy_mgr_is_hw_dbs_capable(v61) & 1) == 0 )
        {
          if ( v63 )
          {
            v76 = *((_DWORD *)v9 + 9);
            if ( v76 >= 0x1C )
              v76 = 28;
          }
          else
          {
            v76 = 0;
          }
          *((_DWORD *)v9 + 10) = v76;
        }
        *((_DWORD *)v9 + 15) = *((_DWORD *)v9 + 16);
      }
      if ( (policy_mgr_current_concurrency_is_mcc(v61) & 1) != 0 )
        *((_DWORD *)v9 + 15) = *((_DWORD *)v62 + 415);
      if ( *(_DWORD *)(v28 + 16) == 1 )
        *((_DWORD *)v9 + 10) = 40;
      if ( *((_DWORD *)v9 + 7) )
      {
        v77 = v245;
        if ( !v63 )
          goto LABEL_154;
        goto LABEL_139;
      }
      if ( v63 && v64 && v248 )
      {
        v78 = *((_DWORD *)v9 + 9);
        v77 = v245;
        if ( v78 > 0x19 )
          *((_DWORD *)v9 + 26) = 25;
        else
          *((_DWORD *)v9 + 26) = v78;
LABEL_136:
        v82 = (unsigned __int8)(*((_DWORD *)v9 + 27) * *((_DWORD *)v9 + 28));
        if ( v82 >= 0xA )
          v82 = 10;
        v83 = scan_probe_time_dwell_time_map[2 * v82 + 1];
        *((_DWORD *)v9 + 17) = v83;
        *((_DWORD *)v9 + 29) = v78 / v83;
LABEL_139:
        v84 = *(_QWORD *)(v28 + 152);
        channel = policy_mgr_get_channel(v61, 1, 0);
        v73 = peer_count_for_mode == 0;
        v86 = channel;
        if ( !v73 )
        {
          if ( (policy_mgr_is_hw_dbs_capable(v61) & 1) != 0
            && (wlan_reg_is_5ghz_ch_freq(v86) || wlan_reg_is_6ghz_chan_freq(v86)) )
          {
            v87 = *((_DWORD *)v9 + 9);
            if ( v87 >= 0x1C )
              v87 = 28;
            *((_DWORD *)v9 + 9) = v87;
          }
          if ( (policy_mgr_is_hw_dbs_capable(v61) & 1) == 0
            || (policy_mgr_is_hw_dbs_capable(v61) & 1) != 0 && wlan_reg_is_5ghz_ch_freq(v86) )
          {
            *((_DWORD *)v9 + 11) = *((_DWORD *)v9 + 9);
          }
        }
        v88 = *((unsigned __int8 *)v62 + 1739);
        if ( v62[1739] )
          goto LABEL_153;
        *((_DWORD *)v9 + 26) = 0;
        if ( (wlan_reg_is_dfs_for_freq(v84, v86, v46, v47, v48, v49, v50, v51, v52, v53) & 1) != 0 )
        {
          v88 = 3 * *((_DWORD *)v9 + 9);
LABEL_153:
          *((_DWORD *)v9 + 26) = v88;
        }
LABEL_154:
        if ( v77 )
        {
          if ( v70 >= 0x3C )
            v89 = 60;
          else
            v89 = v70;
          *((_DWORD *)v9 + 9) = 60;
          *((_DWORD *)v9 + 10) = v89;
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: NDP active modify dwell time 2ghz %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "scm_req_update_concurrency_params");
        }
        v29 = v62;
        if ( v248 )
        {
          v90 = *((_BYTE *)v9 + 95);
          *((_DWORD *)v9 + 13) = *((_DWORD *)v62 + 406);
          if ( (v90 & 2) == 0 )
            *((_DWORD *)v9 + 14) = *((_DWORD *)v62 + 407);
        }
        goto LABEL_162;
      }
      if ( *(_BYTE *)(v31 + 2481) == 1 && (policy_mgr_is_mcc_in_24G(v61) & 1) != 0 )
        *((_DWORD *)v9 + 16) = *((_DWORD *)v62 + 410);
      if ( v64 )
      {
        v79 = *((unsigned __int8 *)v62 + 1738);
        v77 = v245;
        if ( !v62[1738] )
        {
          v80 = *((_DWORD *)v9 + 9);
          if ( *(_BYTE *)(v31 + 2481) == 1 )
          {
            if ( v80 >= 40 )
              v79 = 40;
            else
              v79 = *((_DWORD *)v9 + 9);
          }
          else
          {
            v79 = 6 * v80;
            if ( 6 * v80 >= 241 )
            {
              v73 = (unsigned __int8)(240 / v80) == 0;
              v81 = (unsigned __int8)(240 / v80) * v80;
              if ( v73 )
                v79 = 240;
              else
                v79 = v81;
            }
          }
        }
      }
      else if ( v248 | v243 )
      {
        v79 = *((unsigned __int8 *)v62 + 1736);
        v77 = v245;
        if ( !v62[1736] )
          goto LABEL_134;
      }
      else
      {
        v77 = v245;
        if ( !v245 )
        {
LABEL_134:
          if ( !v63 )
            goto LABEL_154;
          v78 = *((_DWORD *)v9 + 9);
          goto LABEL_136;
        }
        v79 = 0;
      }
      *((_DWORD *)v9 + 26) = v79;
      goto LABEL_134;
    }
  }
LABEL_162:
  if ( *((_DWORD *)v9 + 7) != 3 )
    goto LABEL_165;
  v58 = *((_DWORD *)v9 + 518);
LABEL_164:
  *((_DWORD *)v9 + 518) = v58 | 0x400;
LABEL_165:
  v91 = *(_DWORD *)(v28 + 16);
  if ( v91 == 7 || v91 == 2 )
  {
    if ( *((_DWORD *)v9 + 469) | *((unsigned __int16 *)v9 + 940) )
    {
      if ( *((_DWORD *)v9 + 469) != -1 || *((__int16 *)v9 + 940) != -1 )
      {
        v93 = *((unsigned __int8 *)v9 + 120);
        *((_DWORD *)v9 + 518) |= 0x80000u;
        if ( v93 == 1 )
        {
          v94 = *((unsigned int *)v9 + 25);
          *(_QWORD *)((char *)v9 + 36) = 0x6400000064LL;
          *((_DWORD *)v9 + 13) = 100;
          *((_DWORD *)v9 + 26) = 100;
          *((_DWORD *)v9 + 17) = 10;
          *((_DWORD *)v9 + 29) = 10;
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: p2p scan with bssid dwell and busrt time %d, probe time %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "scm_scan_req_update_params",
            v94,
            10);
        }
      }
    }
  }
  v95 = *(_QWORD *)(v28 + 152);
  if ( v95 )
  {
    v96 = *(_QWORD *)(v95 + 80);
    if ( (v9[12] & 2) == 0 )
      goto LABEL_187;
  }
  else
  {
    v96 = 0;
    if ( (v9[12] & 2) == 0 )
      goto LABEL_187;
  }
  if ( (wlan_scan_cfg_honour_nl_scan_policy_flags(v96) & 1) != 0 )
  {
    v97 = *((_DWORD *)v9 + 9);
    v98 = *((_DWORD *)v9 + 10);
    v99 = *((_DWORD *)v9 + 11);
    *((_DWORD *)v9 + 25) = 4;
    if ( v97 >= 0x28 )
      v97 = 40;
    if ( v98 >= 0x28 )
      v98 = 40;
    *((_DWORD *)v9 + 9) = v97;
    *((_DWORD *)v9 + 10) = v98;
    if ( v99 >= 0x6E )
      v100 = 110;
    else
      v100 = v99;
    *((_DWORD *)v9 + 11) = v100;
  }
LABEL_187:
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: scan_ctrl_flags_ext %0x",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "scm_scan_req_update_params",
    *((unsigned int *)v9 + 518));
  v101 = *(unsigned __int8 *)(*(_QWORD *)(v28 + 152) + 40LL);
  wide_band_scan = ucfg_scan_get_wide_band_scan();
  v111 = *((_DWORD *)v9 + 23);
  v112 = v111 & 0x4000000;
  v113 = v111 & 0xFAFFFFFF;
  v114 = v111 | 0x1000000;
  if ( ((wide_band_scan | (v112 >> 26)) & 1) == 0 )
    v114 = v113;
  *((_DWORD *)v9 + 23) = v114;
  if ( v101 )
  {
LABEL_299:
    __break(0x5512u);
LABEL_300:
    if ( (_DWORD)v29 )
      qdf_trace_msg(0x15u, 8u, "SSID :%s", v103, v104, v105, v106, v107, v108, v109, v110, v31);
    goto LABEL_302;
  }
  if ( *(_BYTE *)v31 )
  {
    qdf_mem_copy(v9 + 15, (const void *)v31, 0x4CCu);
  }
  else if ( !*((_BYTE *)v9 + 120) )
  {
    ucfg_scan_init_chanlist_params(v9, 0, 0, 0);
  }
  v115 = *(_QWORD *)(*v9 + 152LL);
  v116 = wlan_objmgr_vdev_get_comp_private_obj(*v9, 3u);
  v247 = v31;
  if ( v116 )
  {
    v117 = *(unsigned __int8 *)(v116 + 8);
    if ( (v117 & 1) == 0 )
      *(_BYTE *)(v116 + 8) = 1;
    v118 = *((_DWORD *)v9 + 7);
    v119 = (unsigned int *)v9 + 31;
    if ( *((_BYTE *)v9 + 120) != 1 || (utils_dfs_is_freq_in_nol(v115, *v119) & 1) != 0 )
    {
      v120 = *(_DWORD *)(*v9 + 16LL);
      if ( v120 )
        v122 = v120 == 2 || v118 == 1;
      else
        v122 = 1;
      if ( v29[1605] == 1 && ((*((unsigned __int8 *)v29 + 1604) | v117) & 1) != 0 && (v29[1606] != 1 || v118 != 1) )
        v122 = (unsigned __int8)(*(_BYTE *)(v247 + 2481) & v122);
      v244 = v28;
      v246 = v29;
      v249 = (char *)v9 + 124;
      if ( *((_BYTE *)v9 + 120) )
      {
        v123 = 0;
        v31 = 0;
        v29 = "Skip NOL freq %d";
        while ( 1 )
        {
          if ( v123 == 102 )
            goto LABEL_299;
          v125 = *v119;
          if ( wlan_reg_is_6ghz_chan_freq(*v119)
            && (wlan_reg_is_6ghz_band_set(v115, v103, v104, v105, v106, v107, v108, v109, v110) & 1) == 0 )
          {
            v124 = "Skip 6 GHz freq = %d";
            goto LABEL_216;
          }
          if ( v122
            && (wlan_reg_chan_has_dfs_attribute_for_freq(v115, v125, v103, v104, v105, v106, v107, v108, v109, v110) & 1) != 0 )
          {
            break;
          }
          if ( (utils_dfs_is_freq_in_nol(v115, v125) & 1) != 0 )
          {
            v124 = "Skip NOL freq %d";
LABEL_216:
            qdf_trace_msg(0x15u, 8u, v124, v103, v104, v105, v106, v107, v108, v109, v110, v125);
            goto LABEL_217;
          }
          if ( (unsigned int)v31 > 0x66 )
            goto LABEL_299;
          v126 = *(_QWORD *)v119;
          v127 = &v249[12 * (unsigned int)v31];
          v31 = (unsigned int)(v31 + 1);
          *((_DWORD *)v127 + 2) = v119[2];
          *(_QWORD *)v127 = v126;
LABEL_217:
          ++v123;
          v119 += 3;
          if ( v123 >= *((unsigned __int8 *)v9 + 120) )
            goto LABEL_229;
        }
        v124 = "Skip DFS freq %d";
        goto LABEL_216;
      }
      LOBYTE(v31) = 0;
LABEL_229:
      *((_BYTE *)v9 + 120) = v31;
      scm_update_6ghz_channel_list(v9, v246);
      v128 = *(_QWORD *)(*v9 + 152LL);
      if ( v128 )
      {
        v129 = *(_QWORD *)(v128 + 80);
        if ( v129 )
        {
          v130 = *(_QWORD *)(v128 + 80);
          v256 = 0;
          v131 = wlan_objmgr_psoc_get_comp_private_obj(v130, 3u);
          if ( v131 )
          {
            if ( (*(_DWORD *)(*v9 + 16LL) | 2) == 2 )
            {
              v140 = v131;
              if ( (policy_mgr_scan_trim_5g_chnls_for_dfs_ap(v129, &v256) & 1) != 0 )
              {
                v29 = *(const char **)(*v9 + 152LL);
                if ( v29 )
                {
                  v141 = *((_QWORD *)v29 + 10);
                  if ( v141 )
                  {
                    if ( *((_BYTE *)v9 + 120) )
                    {
                      v142 = v256;
                      v31 = (__int64)v9 + 124;
                      v143 = 0;
                      v144 = 0;
                      while ( v143 != 102 )
                      {
                        if ( (wlan_reg_is_24ghz_ch_freq(*(_DWORD *)v31)
                           || v142
                           && ((policy_mgr_2_freq_always_on_same_mac(v141, v142, *(unsigned int *)v31) & 1) == 0
                            || *(_DWORD *)v31 == v142))
                          && ((wlan_reg_is_dfs_for_freq(
                                 (__int64)v29,
                                 v142,
                                 v103,
                                 v104,
                                 v105,
                                 v106,
                                 v107,
                                 v108,
                                 v109,
                                 v110)
                             & 1) == 0
                           || (policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(v141) & 1) != 0) )
                        {
                          if ( v144 > 0x66 )
                            goto LABEL_299;
                          v145 = *(_QWORD *)v31;
                          v146 = &v249[12 * v144++];
                          *((_DWORD *)v146 + 2) = *(_DWORD *)(v31 + 8);
                          *(_QWORD *)v146 = v145;
                        }
                        v147 = *((unsigned __int8 *)v9 + 120);
                        ++v143;
                        v31 += 12;
                        if ( v143 >= v147 )
                        {
                          if ( v144 < (unsigned int)v147 )
                            qdf_trace_msg(
                              0x15u,
                              8u,
                              "%s: 5g chan skipped (%d, %d)",
                              v103,
                              v104,
                              v105,
                              v106,
                              v107,
                              v108,
                              v109,
                              v110,
                              "scm_update_5ghz_6ghz_chlist");
                          goto LABEL_253;
                        }
                      }
                      goto LABEL_299;
                    }
                    LOBYTE(v144) = 0;
LABEL_253:
                    *((_BYTE *)v9 + 120) = v144;
                  }
                }
              }
              if ( *(_BYTE *)(v140 + 1672) == 1 )
              {
                v148 = policy_mgr_scan_trim_chnls_for_connected_ap(v128);
                if ( (v148 & 1) != 0 )
                {
                  v149 = *(_QWORD *)(*v9 + 152LL);
                  if ( v149 )
                  {
                    v150 = *(_QWORD *)(v149 + 80);
                    if ( v150 )
                    {
                      if ( *((_BYTE *)v9 + 120) )
                      {
                        v31 = (__int64)v9 + 124;
                        v151 = 0;
                        LODWORD(v29) = 0;
                        while ( v151 != 102 )
                        {
                          if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)v31)
                            && ((wlan_reg_is_dfs_for_freq(v149, 0, v103, v104, v105, v106, v107, v108, v109, v110) & 1) == 0
                             || (policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(v150) & 1) != 0) )
                          {
                            if ( (unsigned int)v29 > 0x66 )
                              goto LABEL_299;
                            v152 = *(_QWORD *)v31;
                            v153 = &v249[12 * (unsigned int)v29];
                            LODWORD(v29) = (_DWORD)v29 + 1;
                            *((_DWORD *)v153 + 2) = *(_DWORD *)(v31 + 8);
                            *(_QWORD *)v153 = v152;
                          }
                          v154 = *((unsigned __int8 *)v9 + 120);
                          ++v151;
                          v31 += 12;
                          if ( v151 >= v154 )
                          {
                            if ( (unsigned int)v29 < (unsigned int)v154 )
                              qdf_trace_msg(
                                0x15u,
                                8u,
                                "%s: 5g chan skipped (%d, %d)",
                                v103,
                                v104,
                                v105,
                                v106,
                                v107,
                                v108,
                                v109,
                                v110,
                                "scm_update_5ghz_6ghz_chlist");
                            goto LABEL_271;
                          }
                        }
                        goto LABEL_299;
                      }
                      LOBYTE(v29) = 0;
LABEL_271:
                      *((_BYTE *)v9 + 120) = (_BYTE)v29;
                    }
                  }
                }
                if ( (v148 & 2) != 0 )
                {
                  if ( *((_BYTE *)v9 + 120) )
                  {
                    v29 = (char *)v9 + 124;
                    v155 = 0;
                    v156 = 0;
                    v31 = 12;
                    while ( v155 != 102 )
                    {
                      if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)v29) )
                      {
                        if ( v156 > 0x66 )
                          goto LABEL_299;
                        v157 = *(_QWORD *)v29;
                        v158 = &v249[12 * v156++];
                        *((_DWORD *)v158 + 2) = *((_DWORD *)v29 + 2);
                        *(_QWORD *)v158 = v157;
                      }
                      v159 = *((unsigned __int8 *)v9 + 120);
                      ++v155;
                      v29 += 12;
                      if ( v155 >= v159 )
                      {
                        if ( v156 < (unsigned int)v159 )
                          qdf_trace_msg(
                            0x15u,
                            8u,
                            "%s: 2g chan skipped (%d, %d)",
                            v103,
                            v104,
                            v105,
                            v106,
                            v107,
                            v108,
                            v109,
                            v110,
                            "scm_update_24g_chlist");
                        goto LABEL_284;
                      }
                    }
                    goto LABEL_299;
                  }
                  LOBYTE(v156) = 0;
LABEL_284:
                  *((_BYTE *)v9 + 120) = v156;
                }
              }
              if ( *(_BYTE *)(v140 + 1768) == 1
                && (policy_mgr_is_hw_dbs_capable(v129) & 1) == 0
                && !*(_DWORD *)(*v9 + 16LL)
                && (unsigned int)policy_mgr_mode_specific_connection_count(v129, 1, 0) )
              {
                scm_filter_6g_and_indoor_freq(v128, v9);
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x15u,
              2u,
              "%s: %s:%u, Failed to get scan object",
              v132,
              v133,
              v134,
              v135,
              v136,
              v137,
              v138,
              v139,
              "wlan_psoc_get_scan_obj_fl",
              "wlan_pdev_get_scan_obj",
              764);
          }
        }
      }
      v28 = v244;
    }
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: null scan_vdev_obj",
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      "scm_update_channel_list");
  }
  wlan_scan_update_low_latency_profile_chnlist(v28, v9);
  qdf_trace_msg(
    0x15u,
    8u,
    "Scan start: scan id %d vdev %d Dwell time: act %d pass %d act_2G %d act_6G %d pass_6G %d, probe time %d n_probes %d "
    "flags %x ext_flag %x events %x policy %d is_wb: %d pri %d",
    v160,
    v161,
    v162,
    v163,
    v164,
    v165,
    v166,
    v167,
    *((unsigned int *)v9 + 2),
    *((unsigned int *)v9 + 4),
    *((unsigned int *)v9 + 9),
    *((unsigned int *)v9 + 11),
    *((unsigned int *)v9 + 10),
    *((_DWORD *)v9 + 13),
    *((_DWORD *)v9 + 14),
    *((_DWORD *)v9 + 17),
    *((_DWORD *)v9 + 29),
    *((_DWORD *)v9 + 23),
    *((_DWORD *)v9 + 518),
    *((_DWORD *)v9 + 8),
    *((_DWORD *)v9 + 24),
    HIBYTE(*((_DWORD *)v9 + 23)) & 1,
    *((_DWORD *)v9 + 6));
  LODWORD(v240) = *((_DWORD *)v9 + 28);
  LODWORD(v242) = *((_DWORD *)v9 + 520);
  LODWORD(v241) = *((_DWORD *)v9 + 519);
  LODWORD(v239) = *((_DWORD *)v9 + 25);
  LODWORD(v238) = *((_DWORD *)v9 + 26);
  LODWORD(v237) = *((_DWORD *)v9 + 22);
  LODWORD(v236) = *((_DWORD *)v9 + 21);
  qdf_trace_msg(
    0x15u,
    8u,
    "Scan Type %d rest time: min %d max %d probe spacing %d idle %d probe delay %d scan offset %d burst duration %d adapt"
    "ive dwell mode %d SSID %d S_SSID %d H_BSSID %d",
    v168,
    v169,
    v170,
    v171,
    v172,
    v173,
    v174,
    v175,
    *((unsigned int *)v9 + 7),
    *((unsigned int *)v9 + 15),
    *((unsigned int *)v9 + 16),
    *((unsigned int *)v9 + 18),
    *((unsigned int *)v9 + 19),
    v236,
    v237,
    v238,
    v239,
    v240,
    v241,
    v242);
  v176 = _qdf_mem_malloc(0x97u, "scm_dump_ssid_bssid_info", 1306);
  if ( !v176 )
    goto LABEL_324;
  v31 = v176;
  if ( *((_DWORD *)v9 + 28) )
  {
    LODWORD(v29) = 0;
    v177 = 0;
    do
    {
      while ( 1 )
      {
        v103 = scnprintf(
                 v31 + (unsigned int)v29,
                 (unsigned int)(151 - (_DWORD)v29),
                 " %.*s",
                 *((unsigned __int8 *)v9 + 33 * v177 + 1348),
                 (const char *)v9 + 33 * v177 + 1349);
        LODWORD(v29) = v178 + (_DWORD)v29;
        if ( (unsigned int)((_DWORD)v29 - 108) < 0xFFFFFF6A )
          break;
        if ( *((_DWORD *)v9 + 28) <= (unsigned int)++v177 )
          goto LABEL_300;
        if ( v177 == 16 )
          goto LABEL_299;
      }
      qdf_trace_msg(0x15u, 8u, "SSID :%s", v103, v104, v105, v106, v107, v108, v109, v110, v31);
      if ( *((_DWORD *)v9 + 28) <= (unsigned int)++v177 )
        goto LABEL_302;
      LODWORD(v29) = 0;
    }
    while ( v177 != 16 );
    goto LABEL_299;
  }
LABEL_302:
  if ( !*((_DWORD *)v9 + 519) )
    goto LABEL_311;
  LODWORD(v29) = 0;
  v179 = 0;
  while ( 1 )
  {
    v103 = scnprintf(
             v31 + (unsigned int)v29,
             (unsigned int)(151 - (_DWORD)v29),
             " 0x%x[%d,0x%x]",
             LODWORD(v9[v179 + 261]),
             HIWORD(HIDWORD(v9[v179 + 260])),
             (unsigned __int16)HIDWORD(v9[v179 + 260]));
    LODWORD(v29) = v180 + (_DWORD)v29;
    if ( (unsigned int)((_DWORD)v29 - 120) >= 0xFFFFFF6A )
      break;
    qdf_trace_msg(0x15u, 8u, "S_SSID (s_ssid[freq,flag]):%s", v103, v104, v105, v106, v107, v108, v109, v110, v31);
    if ( *((_DWORD *)v9 + 519) <= (unsigned int)++v179 )
      goto LABEL_311;
    LODWORD(v29) = 0;
LABEL_305:
    if ( v179 == 10 )
      goto LABEL_299;
  }
  if ( *((_DWORD *)v9 + 519) > (unsigned int)++v179 )
    goto LABEL_305;
  if ( (_DWORD)v29 )
    qdf_trace_msg(0x15u, 8u, "S_SSID (s_ssid[freq, flag]):%s", v103, v104, v105, v106, v107, v108, v109, v110, v31);
LABEL_311:
  if ( !*((_DWORD *)v9 + 520) )
    goto LABEL_323;
  v181 = 0;
  v182 = 0;
  LODWORD(v29) = 12;
  v183 = 151;
  v184 = v31;
  while ( 2 )
  {
    v185 = (__int64)v9 + 12 * v182 + 2164;
    if ( v185 == -4 )
    {
      v188 = 0;
      v186 = 0;
      v187 = 0;
      v189 = 0;
    }
    else
    {
      v186 = *(unsigned __int8 *)(v185 + 4);
      v187 = *(unsigned __int8 *)(v185 + 5);
      v188 = *(unsigned __int8 *)(v185 + 6);
      v189 = *(unsigned __int8 *)(v185 + 9);
    }
    v103 = scnprintf(
             v184,
             v183,
             " %02x:%02x:%02x:**:**:%02x[%d,0x%x]",
             v186,
             v187,
             v188,
             v189,
             HIWORD(*(_DWORD *)v185),
             (unsigned __int16)*(_DWORD *)v185);
    v181 += v190;
    if ( v181 - 110 < 0xFFFFFF6A )
    {
      qdf_trace_msg(0x15u, 8u, "H_BSSID (bssid[freq,flag]):%s", v103, v104, v105, v106, v107, v108, v109, v110, v31);
      if ( *((_DWORD *)v9 + 520) <= (unsigned int)++v182 )
        goto LABEL_323;
      v181 = 0;
      goto LABEL_314;
    }
    if ( *((_DWORD *)v9 + 520) > (unsigned int)++v182 )
    {
LABEL_314:
      v184 = v31 + v181;
      v183 = 151 - v181;
      if ( v182 == 10 )
        goto LABEL_299;
      continue;
    }
    break;
  }
  if ( v181 )
    qdf_trace_msg(0x15u, 8u, "H_BSSID (bssid[freq,flag]):%s", v103, v104, v105, v106, v107, v108, v109, v110, v31);
LABEL_323:
  _qdf_mem_free(v31);
LABEL_324:
  v191 = *((unsigned __int8 *)v9 + 120);
  if ( !*((_BYTE *)v9 + 120) )
    goto LABEL_350;
  if ( (*((_DWORD *)v9 + 23) & 0x1000000) != 0 )
    v192 = 15;
  else
    v192 = 11;
  if ( v191 >= 0x19 )
    v191 = 25;
  v193 = v192 * v191 + 1;
  v194 = _qdf_mem_malloc(v193, "scm_print_scan_req_info", 1412);
  if ( !v194 )
    goto LABEL_344;
  v31 = v194;
  qdf_trace_msg(0x15u, 8u, "Total freq %d", v10, v11, v12, v13, v14, v15, v16, v17, *((unsigned __int8 *)v9 + 120));
  if ( !*((_BYTE *)v9 + 120) )
    goto LABEL_343;
  v195 = 0;
  LODWORD(v29) = 0;
  v196 = 0;
  v197 = (char *)v9 + 124;
  while ( 2 )
  {
    while ( 2 )
    {
      if ( (*((_BYTE *)v9 + 95) & 1) == 0 )
      {
        if ( v195 > 0x65 )
          goto LABEL_299;
        v103 = scnprintf(
                 v31 + v196,
                 v193 - v196,
                 "%d(0x%02x) ",
                 *(_DWORD *)&v197[12 * v195],
                 *(_DWORD *)&v197[12 * v195 + 8]);
        if ( (unsigned int)v29 <= 0x17 )
          break;
        goto LABEL_333;
      }
      if ( v195 >= 0x66 )
        goto LABEL_299;
      v103 = scnprintf(
               v31 + v196,
               v193 - v196,
               "%d(0x%02x)[%d] ",
               *(_DWORD *)&v197[12 * v195],
               *(_DWORD *)&v197[12 * v195 + 8],
               *(_DWORD *)&v197[12 * v195 + 4]);
      if ( (unsigned int)v29 > 0x17 )
      {
LABEL_333:
        qdf_trace_msg(0x15u, 8u, "Freq list: %s", v103, v104, v105, v106, v107, v108, v109, v110, v31);
        ++v195;
        LODWORD(v29) = 0;
        v196 = 0;
        if ( v195 >= *((unsigned __int8 *)v9 + 120) )
          goto LABEL_343;
        continue;
      }
      break;
    }
    ++v195;
    LODWORD(v29) = (_DWORD)v29 + 1;
    v196 += v198;
    if ( v195 < *((unsigned __int8 *)v9 + 120) )
      continue;
    break;
  }
  if ( v196 )
    qdf_trace_msg(0x15u, 8u, "Freq list: %s", v103, v104, v105, v106, v107, v108, v109, v110, v31);
LABEL_343:
  _qdf_mem_free(v31);
LABEL_344:
  if ( !*((_BYTE *)v9 + 120) )
  {
LABEL_350:
    v36 = "%s: Reject 0 channel Scan";
    v37 = 4;
    goto LABEL_351;
  }
  v199 = *((_DWORD *)v9 + 2);
  v251 = &scm_scan_serialize_callback;
  LODWORD(v252) = 3;
  BYTE4(v252) &= ~1u;
  v200 = *((_DWORD *)v9 + 20);
  LODWORD(v250) = 0;
  HIDWORD(v250) = v199;
  v255 = v9;
  LODWORD(v253) = v200 + 10;
  v201 = *v9;
  v254 = *v9;
  if ( *(_BYTE *)(v247 + 2482) == 1 )
    LODWORD(v253) = 0;
  qdf_mtrace(21, 76, 0, *(_BYTE *)(v201 + 104), v199);
  v210 = wlan_serialization_request((unsigned int *)&v250, v202, v203, v204, v205, v206, v207, v208, v209);
  v219 = v210;
  v220 = v210 >= 2;
  result = 0;
  if ( v220 )
  {
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: ser cmd status %d",
      v211,
      v212,
      v213,
      v214,
      v215,
      v216,
      v217,
      v218,
      "scm_scan_start_req",
      v219);
    v221 = 0;
LABEL_352:
    v262 = nullptr;
    v263 = 0;
    v261 = 0;
    v258 = 0;
    v257 = 0x500000001LL;
    v222 = *((_DWORD *)v9 + 4);
    v259 = *((_DWORD *)v9 + 3);
    v223 = *((_DWORD *)v9 + 2);
    v256 = v222;
    v262 = v9;
    v260 = v223;
    v224 = ((double (__fastcall *)(_QWORD, unsigned int *))scm_scan_post_event)(*v9, &v256);
    wlan_objmgr_vdev_release_ref(*v9, 0xCu, v225, v224, v226, v227, v228, v229, v230, v231, v232);
    v233 = v9[254];
    if ( v233 )
    {
      v9[254] = 0;
      *((_DWORD *)v9 + 506) = 0;
      _qdf_mem_free(v233);
    }
    v234 = v9[256];
    if ( v234 )
    {
      *((_DWORD *)v9 + 510) = 0;
      v9[256] = 0;
      _qdf_mem_free(v234);
    }
    v235 = v9[258];
    if ( v235 )
    {
      *((_DWORD *)v9 + 514) = 0;
      v9[258] = 0;
      _qdf_mem_free(v235);
    }
    _qdf_mem_free((__int64)v9);
    result = v221;
  }
LABEL_359:
  _ReadStatusReg(SP_EL0);
  return result;
}
