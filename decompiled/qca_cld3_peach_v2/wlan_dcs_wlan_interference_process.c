bool __fastcall wlan_dcs_wlan_interference_process(
        __int64 a1,
        unsigned int a2,
        _DWORD *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int *v13; // x26
  int v14; // w21
  int v15; // w20
  unsigned int v16; // w28
  unsigned int v17; // w22
  unsigned int v18; // w23
  __int64 v19; // x5
  __int64 v20; // x7
  __int64 v21; // x4
  __int64 v22; // x6
  unsigned int v23; // w25
  __int64 v24; // x9
  unsigned int v25; // w9
  unsigned int v26; // w27
  unsigned int v27; // w8
  unsigned int v28; // w9
  unsigned int v29; // w24
  const char *v30; // x2
  _BOOL4 v31; // w21
  unsigned int v33; // w10
  unsigned int v34; // w16
  unsigned int v35; // w9
  unsigned int v36; // w15
  unsigned int v37; // w12
  unsigned int v38; // w14
  unsigned int v39; // w8
  unsigned int v40; // w11
  unsigned int v41; // w2
  int v42; // w10
  int v43; // w13
  int v44; // w12
  unsigned int v45; // w14
  int v46; // w16
  unsigned int v47; // w16
  int v48; // w15
  const char *v49; // x2
  __int64 v50; // x4
  __int64 v51; // x5
  unsigned __int64 StatusReg; // x8
  __int64 v53; // x24
  int v54; // w9
  unsigned int v55; // w14
  unsigned int v56; // w11
  int v57; // w12
  int v58; // w13
  unsigned int v59; // w10
  int v60; // w9
  __int64 v61; // x9
  unsigned int v62; // w16
  unsigned __int8 v63; // w8
  __int64 v64; // x0
  unsigned int v65; // w13
  unsigned int v66; // w27
  unsigned int v67; // w14
  unsigned int v68; // w6
  unsigned int v69; // w12
  unsigned int v70; // w10
  int v71; // w11
  unsigned int v72; // w4
  __int64 v73; // x9
  unsigned int v74; // w24
  unsigned int v75; // w11
  unsigned int v76; // w10
  unsigned int v77; // w15
  unsigned int v78; // w13
  unsigned int v79; // w11
  unsigned int v80; // w12
  unsigned int v81; // w27
  unsigned int v82; // w14
  unsigned int v83; // w17
  unsigned int v84; // w21
  unsigned int v85; // w20
  __int64 v86; // x20
  char v87; // w21
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  char v96; // w21
  char v97; // w8
  char is_supported; // w0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w4
  unsigned int dcs_mode; // w0
  char v109; // w8
  unsigned int v110; // w10
  __int64 v111; // x8
  unsigned int v112; // w9
  unsigned int v113; // w9
  unsigned int v114; // w24
  unsigned int v115; // w27
  __int64 v116; // x4
  int v117; // w24
  unsigned int v118; // w24
  __int64 v119; // x22
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  unsigned int v128; // w21
  __int64 v129; // x28
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  __int64 v138; // [xsp+0h] [xbp-E0h]
  __int64 v139; // [xsp+0h] [xbp-E0h]
  __int64 v140; // [xsp+8h] [xbp-D8h]
  __int64 v141; // [xsp+8h] [xbp-D8h]
  __int64 v142; // [xsp+10h] [xbp-D0h]
  __int64 v143; // [xsp+10h] [xbp-D0h]
  __int64 v144; // [xsp+18h] [xbp-C8h]
  __int64 v145; // [xsp+20h] [xbp-C0h]
  __int64 v146; // [xsp+28h] [xbp-B8h]
  unsigned int v147; // [xsp+30h] [xbp-B0h]
  unsigned int v148; // [xsp+34h] [xbp-ACh]
  unsigned int v149; // [xsp+38h] [xbp-A8h]
  __int64 v150; // [xsp+38h] [xbp-A8h]
  __int64 v151; // [xsp+38h] [xbp-A8h]
  __int64 v152; // [xsp+38h] [xbp-A8h]
  __int64 v153; // [xsp+38h] [xbp-A8h]
  unsigned int v154; // [xsp+44h] [xbp-9Ch]
  unsigned int v155; // [xsp+48h] [xbp-98h]
  unsigned int v156; // [xsp+48h] [xbp-98h]
  unsigned int v157; // [xsp+4Ch] [xbp-94h]
  unsigned int v158; // [xsp+50h] [xbp-90h]
  unsigned int v159; // [xsp+50h] [xbp-90h]
  unsigned int v160; // [xsp+54h] [xbp-8Ch]
  unsigned int v161; // [xsp+54h] [xbp-8Ch]
  unsigned int v162; // [xsp+58h] [xbp-88h]
  unsigned int v163; // [xsp+5Ch] [xbp-84h]
  unsigned int v164; // [xsp+60h] [xbp-80h]
  unsigned int v165; // [xsp+60h] [xbp-80h]
  unsigned int v166; // [xsp+60h] [xbp-80h]
  unsigned int v167; // [xsp+64h] [xbp-7Ch]
  unsigned int v168; // [xsp+68h] [xbp-78h]
  unsigned int v169; // [xsp+68h] [xbp-78h]
  unsigned int v170; // [xsp+68h] [xbp-78h]
  unsigned int v171; // [xsp+6Ch] [xbp-74h]
  unsigned int v172; // [xsp+6Ch] [xbp-74h]
  int v173; // [xsp+6Ch] [xbp-74h]
  unsigned int v174; // [xsp+70h] [xbp-70h]
  unsigned int v175; // [xsp+70h] [xbp-70h]
  unsigned int v176; // [xsp+74h] [xbp-6Ch]
  __int64 v177; // [xsp+78h] [xbp-68h]
  __int64 v178; // [xsp+78h] [xbp-68h]
  unsigned int v179; // [xsp+80h] [xbp-60h]
  __int64 v180; // [xsp+B0h] [xbp-30h]
  __int64 v181; // [xsp+B8h] [xbp-28h]
  __int64 v182; // [xsp+C0h] [xbp-20h]
  __int64 v183; // [xsp+C8h] [xbp-18h]
  __int64 v184; // [xsp+D0h] [xbp-10h]

  v184 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = (int *)(a4 + 44);
  v14 = *(unsigned __int8 *)(a4 + 2);
  v16 = *(_DWORD *)(a4 + 4);
  v15 = *(_DWORD *)(a4 + 8);
  v17 = *(_DWORD *)(a4 + 12);
  v18 = *(_DWORD *)(a4 + 16);
  v20 = *(unsigned int *)(a4 + 28);
  v19 = *(unsigned int *)(a4 + 32);
  v21 = *(unsigned int *)(a4 + 36);
  v22 = *(unsigned int *)(a4 + 40);
  v23 = *(_DWORD *)(a4 + 20);
  v24 = *(_QWORD *)(a4 + 52);
  v182 = *(_QWORD *)(a4 + 44);
  v183 = v24;
  if ( v16 >= 2 )
  {
    v175 = a2;
    v114 = v21;
    v178 = a1;
    v150 = a4;
    v115 = v20;
    v165 = v19;
    v161 = v22;
    wlan_dcs_im_print_stats(a4 + 60, a3, a2);
    v22 = v161;
    v19 = v165;
    v20 = v115;
    a1 = v178;
    a2 = v175;
    v21 = v114;
    a4 = v150;
  }
  if ( (int)a3[5] < 1 || (v25 = v13[4], v26 = *a3 - v25, *a3 <= v25) )
  {
    if ( v16 )
    {
      v30 = "%s: ignoring due to negative TSF value";
      goto LABEL_109;
    }
LABEL_9:
    v31 = 0;
    goto LABEL_10;
  }
  v27 = *(_DWORD *)(a4 + 92);
  v28 = a3[8];
  v29 = v28 - v27;
  if ( v28 < v27 )
  {
    if ( v16 )
    {
      v30 = "%s: ignoring due to negative rxclr count";
LABEL_109:
      qdf_trace_msg(
        0x74u,
        8u,
        v30,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wlan_dcs_wlan_interference_get_stats_delta",
        v21,
        v19,
        v22,
        v20);
      goto LABEL_9;
    }
    goto LABEL_9;
  }
  v34 = *(_DWORD *)(a4 + 96);
  v33 = *(_DWORD *)(a4 + 100);
  v36 = a3[9];
  v35 = a3[10];
  v37 = *(_DWORD *)(a4 + 84);
  v38 = *(_DWORD *)(a4 + 88);
  v39 = a3[6];
  v40 = a3[7];
  v41 = *(_DWORD *)(a4 + 116);
  if ( v35 < v33 )
    v42 = ~v33;
  else
    v42 = -v33;
  v43 = -v38;
  if ( v39 < v37 )
    v44 = ~v37;
  else
    v44 = -v37;
  if ( v40 < v38 )
    v43 = ~v38;
  v45 = a3[14];
  if ( v36 < v34 )
    v46 = ~v34;
  else
    v46 = -v34;
  v47 = v46 + v36;
  v48 = -v41;
  if ( v45 < v41 )
    v48 = ~v41;
  if ( v47 < v29 )
  {
    if ( !v16 )
      goto LABEL_9;
    v49 = "%s: cycle count %d is less than rxclr_delta %d, need to investigate!!";
    v50 = v47;
    v51 = v29;
LABEL_66:
    qdf_trace_msg(0x74u, 8u, v49, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_dcs_wlan_interference_process", v50, v51);
    goto LABEL_9;
  }
  v176 = v29;
  v167 = v44 + v39;
  v171 = v43 + v40;
  v168 = v48 + v45;
  v179 = v47;
  v174 = a2;
  v177 = a1;
  v163 = v21;
  v164 = v19;
  v160 = v22;
  if ( v16 >= 2 )
  {
    v116 = v29;
    v117 = v20;
    v151 = a4;
    qdf_trace_msg(
      0x74u,
      8u,
      "%s: Deltas: rxclr %u rxclr_ext %u tx_frame %u rx_frame %u cycle_cnt %u my_bss_rx %u reg_tsf %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_dcs_wlan_interference_process",
      v116,
      v42 + v35,
      v167,
      v171,
      v47,
      v48 + v45,
      v26);
    a4 = v151;
    LODWORD(v20) = v117;
  }
  v162 = v20;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v53 = a4;
    raw_spin_lock(a4 + 352);
  }
  else
  {
    v53 = a4;
    raw_spin_lock_bh(a4 + 352);
    *(_QWORD *)(v53 + 360) |= 1uLL;
  }
  v54 = *v13;
  if ( *v13 )
  {
    v55 = *(_DWORD *)(v53 + 140) + v176;
    v56 = *(_DWORD *)(v53 + 128);
    v57 = *(_DWORD *)(v53 + 144);
    v58 = *(_DWORD *)(v53 + 148);
    *(_DWORD *)(v53 + 136) += v179;
    *(_DWORD *)(v53 + 140) = v55;
    *(_DWORD *)(v53 + 144) = v57 + v171;
    *(_DWORD *)(v53 + 148) = v58 + v168;
    if ( v56 || *(_DWORD *)(v53 + 132) )
    {
      v59 = a3[1];
      if ( v59 > v56 )
      {
        *(_DWORD *)(v53 + 128) = v59;
        v59 = a3[1];
      }
      if ( v59 >= *(_DWORD *)(v53 + 132) )
        goto LABEL_42;
    }
    else
    {
      v59 = a3[1];
      *(_DWORD *)(v53 + 128) = v59;
    }
    *(_DWORD *)(v53 + 132) = v59;
LABEL_42:
    v60 = v54 - 1;
    *v13 = v60;
    if ( !v60 )
      *(_BYTE *)(v53 + 48) = 1;
  }
  v61 = *(_QWORD *)(v53 + 360);
  if ( (v61 & 1) != 0 )
  {
    *(_QWORD *)(v53 + 360) = v61 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v53 + 352);
  }
  else
  {
    raw_spin_unlock(v53 + 352);
  }
  v62 = v26 >> 8;
  v63 = v174;
  v64 = v177;
  v65 = v179 >> 8;
  if ( v26 < 0x100 || v179 <= 0xFF )
  {
    if ( !v16 )
      goto LABEL_9;
    v49 = "%s: cycle count %d or TSF %d is NULL --Investigate--";
    v50 = v65;
    v51 = v62;
    goto LABEL_66;
  }
  v66 = 100 * (v167 >> 8);
  v67 = v66 / v65;
  v68 = 100 * (v171 >> 8) / v65;
  v69 = 100 * (a3[3] >> 8) / v62;
  v70 = 100 * ((v171 - v168) >> 8) / v65;
  if ( v69 >= v68 )
    v69 = 100 * (v171 >> 8) / v65;
  v71 = a3[13];
  *(_DWORD *)(v53 + 152) = v68;
  *(_DWORD *)(v53 + 156) = v67;
  *(_DWORD *)(v53 + 168) = v71;
  v72 = 100 * (v176 >> 8) / v65;
  v73 = v53;
  *(_DWORD *)(v53 + 160) = v70;
  *(_DWORD *)(v53 + 164) = v72;
  if ( v16 < 2 )
  {
    if ( (v14 & 1) != 0 )
      goto LABEL_52;
LABEL_112:
    if ( v16 )
    {
      v119 = jiffies;
      if ( wlan_dcs_wlan_interference_process___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x74u,
          8u,
          "%s: skip as dcs_algorithm_process disabled",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "wlan_dcs_wlan_interference_process");
        v31 = 0;
        wlan_dcs_wlan_interference_process___last_ticks = v119;
        goto LABEL_10;
      }
    }
    goto LABEL_9;
  }
  LODWORD(v140) = v14;
  v152 = v53;
  v118 = v69;
  v170 = 100 * (v171 >> 8) / v65;
  v173 = v66 / v65;
  LODWORD(v138) = v70;
  v156 = 100 * (v176 >> 8) / v65;
  v159 = v62;
  qdf_trace_msg(
    0x74u,
    8u,
    "%s: total_cu: %u, tx_cu: %u, rx_cu: %u, rx_time_cu: %u, obss_rx_cu: %u dcs_algorithm: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "wlan_dcs_wlan_interference_process",
    v138,
    v140);
  v65 = v179 >> 8;
  v62 = v159;
  v68 = v170;
  v67 = v173;
  v72 = v156;
  v64 = v177;
  v69 = v118;
  v63 = v174;
  v73 = v152;
  if ( (v14 & 1) == 0 )
    goto LABEL_112;
LABEL_52:
  v74 = v68;
  v157 = v65;
  v75 = 0;
  v76 = 100 * (a3[2] >> 8) / v62;
  if ( v67 < v76 )
    v76 = v67;
  if ( v65 <= v66 && v76 )
    v75 = 100 * v76 / v67;
  v158 = v75;
  v172 = v67;
  v154 = v69;
  v155 = v72;
  if ( v72 >= v69 + v67 )
    v77 = v72 - (v69 + v67);
  else
    v77 = 0;
  v78 = *(_DWORD *)(v73 + 104);
  v80 = a3[11];
  v79 = a3[12];
  v81 = v77;
  if ( v80 < v78 )
    v78 = 0;
  if ( (v80 - v78) * v15 )
    v82 = 100 * (((v80 - v78) * v15) >> 8) / v62;
  else
    v82 = 0;
  v83 = a3[5];
  if ( 1000 * v80 / v83 <= 1000 * v79 / v83 )
    v84 = 1000 * v79 / v83;
  else
    v84 = 1000 * v80 / v83;
  if ( v80 <= v79 )
    v85 = a3[12];
  else
    v85 = a3[11];
  v169 = v76 + v77 + v82;
  if ( v16 >= 2 )
  {
    v147 = 1000 * v80 / v83;
    v148 = 1000 * v79 / v83;
    v153 = v73;
    qdf_trace_msg(
      0x74u,
      8u,
      "%s: unused_cu %u, ofdm_phyerr_delta %u, cck_phyerr_delta %u, ofdm_phyerr_cu %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_dcs_wlan_interference_process",
      v77);
    LODWORD(v140) = v85;
    LODWORD(v138) = v84;
    qdf_trace_msg(
      0x74u,
      8u,
      "%s: wasted_cu %u, ofdm_err %u, cck_err %u, ofdm_error_cu %u, max err: rate %u cnt %d",
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      v127,
      "wlan_dcs_wlan_interference_process",
      v169,
      v147,
      v148,
      (unsigned int)(100 * a3[11]) / a3[5],
      v138,
      v140);
    v64 = v177;
    v63 = v174;
    v73 = v153;
    if ( v84 < v17 )
      goto LABEL_77;
  }
  else if ( v84 < v17 )
  {
    goto LABEL_77;
  }
  if ( v85 > v17 )
  {
LABEL_78:
    v86 = v73;
    v87 = 0;
    v149 = 1;
    goto LABEL_80;
  }
LABEL_77:
  if ( a3[4] > v18 )
    goto LABEL_78;
  v86 = v73;
  v149 = 0;
  v87 = 1;
LABEL_80:
  if ( policy_mgr_is_vdev_ll_lt_sap(v64, v63) )
    wlan_ll_sap_set_cur_freq_unused_cu(v177, v174, v81);
  if ( v81 >= v23 )
  {
    v96 = 2;
LABEL_86:
    v97 = *(_BYTE *)(v86 + 172) + v96;
    v96 = 0;
    *(_BYTE *)(v86 + 172) = v97;
    goto LABEL_87;
  }
  if ( (v87 & 1) == 0 )
  {
    if ( v169 <= v23 + 10 || v74 + v172 <= v162 )
    {
      v96 = 1;
      if ( v172 < 0x1F || v158 < v160 )
        goto LABEL_87;
    }
    else
    {
      v96 = 1;
    }
    goto LABEL_86;
  }
  v96 = 1;
LABEL_87:
  v180 = v182;
  v181 = v183;
  is_supported = target_if_vdev_level_dcs_is_supported(v177, v88, v89, v90, v91, v92, v93, v94, v95);
  v107 = v164;
  if ( (is_supported & 1) != 0 )
  {
    dcs_mode = wlan_get_dcs_mode(v177, (unsigned __int8)v174);
    if ( dcs_mode < 4 )
      v107 = *((unsigned __int8 *)&v181 + dcs_mode + 1);
    else
      v107 = BYTE1(v181);
  }
  if ( v16 )
    v109 = v96;
  else
    v109 = 1;
  if ( (v109 & 1) != 0 )
  {
    v110 = v163;
    v111 = v86;
    if ( v16 >= 2 )
    {
      v128 = v107;
      qdf_trace_msg(
        0x74u,
        8u,
        "%s: intfr_detection_th %u detection_win %u, intfr cnt %d sample cnt %d",
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        "wlan_dcs_wlan_interference_process");
      v110 = v163;
      v107 = v128;
      v111 = v86;
    }
  }
  else
  {
    v166 = v107;
    v129 = jiffies;
    if ( wlan_dcs_wlan_interference_process___last_ticks_34 - jiffies + 125 < 0 )
    {
      LODWORD(v140) = v107;
      LODWORD(v142) = v163;
      LODWORD(v138) = v160;
      qdf_trace_msg(
        0x74u,
        8u,
        "%s: intfr_th %u phy_err_th %u radar_err_th %u usr_max_cu %u tx_err_th %u intfr_detection_th %u detection_win %u",
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        "wlan_dcs_wlan_interference_process",
        v23,
        v17,
        v18,
        v162,
        v138,
        v140,
        v142);
      wlan_dcs_wlan_interference_process___last_ticks_34 = v129;
    }
    LODWORD(v142) = v176;
    LODWORD(v140) = v157;
    LODWORD(v138) = v154;
    qdf_trace_msg(
      0x74u,
      8u,
      "%s: vdev %d, unused cu: %u: Scaled: rx_clr %u tx_cu %u rx_t_cu %u cc %u, orig: cu %u tx_cu %u rx_t_cu %u cc %u",
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      "wlan_dcs_wlan_interference_process",
      (unsigned __int8)v174,
      v81,
      v155,
      v172,
      v138,
      v140,
      v142,
      v167,
      a3[3],
      v179);
    LODWORD(v145) = *(unsigned __int8 *)(v86 + 172);
    LODWORD(v146) = *(unsigned __int8 *)(v86 + 173);
    LODWORD(v144) = v158;
    LODWORD(v141) = v74;
    LODWORD(v143) = v169;
    LODWORD(v139) = a3[4];
    qdf_trace_msg(
      0x74u,
      8u,
      "%s: phyerr %u: ofdm %u cck %u listen time %u, phyerr cnt %u, rx_cu %u wasted_cu %u tx_err %u intfr_cnt %d samp_cnt %d",
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      v136,
      v137,
      "wlan_dcs_wlan_interference_process",
      v149,
      (unsigned int)a3[11],
      (unsigned int)a3[12],
      (unsigned int)a3[5],
      v139,
      v141,
      v143,
      v144,
      v145,
      v146);
    v110 = v163;
    v107 = v166;
    v111 = v86;
  }
  v112 = *(unsigned __int8 *)(v111 + 172);
  v31 = v107 <= v112;
  if ( v107 <= v112 || !*(_BYTE *)(v111 + 172) || (v113 = *(unsigned __int8 *)(v111 + 173), v110 <= v113) )
  {
    LOBYTE(v113) = 0;
    *(_BYTE *)(v111 + 172) = 0;
  }
  *(_BYTE *)(v111 + 173) = v113 + 1;
LABEL_10:
  qdf_mem_copy(v13 + 4, a3, 0x44u);
  _ReadStatusReg(SP_EL0);
  return v31;
}
