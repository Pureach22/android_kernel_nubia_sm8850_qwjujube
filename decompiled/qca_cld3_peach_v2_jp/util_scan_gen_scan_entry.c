__int64 __fastcall util_scan_gen_scan_entry(
        __int64 a1,
        _WORD *a2,
        size_t a3,
        char a4,
        unsigned int *a5,
        const void *a6,
        _QWORD *a7)
{
  void *v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  void *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w9
  unsigned int v34; // w8
  unsigned int v35; // w23
  char v36; // w26
  int v37; // w8
  int v38; // w9
  int v39; // w10
  bool v40; // zf
  char v41; // w8
  char v42; // w9
  int v43; // w8
  char v44; // w9
  char v45; // w8
  char *v46; // x28
  __int16 v47; // w8
  __int64 system_time; // x0
  void *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  __int64 comp_private_obj; // x0
  __int64 v60; // x24
  unsigned int v61; // w13
  unsigned int v62; // w14
  unsigned int v63; // w16
  _QWORD *v64; // x17
  _QWORD *v65; // x1
  __int64 v66; // x12
  char **v67; // x2
  __int64 v68; // x3
  unsigned int v69; // w9
  char *v70; // x20
  unsigned int v71; // w8
  int v72; // w9
  int *v73; // x10
  unsigned int v74; // w9
  unsigned __int64 v75; // x8
  char *v76; // x9
  bool v77; // cf
  char **v78; // x10
  unsigned __int64 v79; // x10
  int v80; // w11
  unsigned int v81; // w26
  const void *v82; // x23
  __int64 v83; // x21
  unsigned int v84; // w25
  char *v85; // x25
  unsigned int v86; // w23
  char *v87; // x24
  char *v88; // x21
  unsigned __int64 v89; // x8
  int v90; // w21
  unsigned __int64 v91; // x27
  unsigned __int64 v92; // x5
  unsigned int v93; // w13
  unsigned int v94; // w22
  unsigned int v95; // w9
  bool v96; // cc
  __int64 v97; // x26
  int v98; // w8
  void *v99; // x0
  const void *v100; // x1
  size_t v101; // x2
  unsigned int v102; // w26
  const void *v103; // x25
  __int64 v104; // x21
  unsigned int v105; // w26
  __int64 v106; // x8
  char *v107; // x9
  const void *v108; // x25
  __int64 v109; // x8
  unsigned int v110; // w8
  unsigned int v111; // w20
  const char *v112; // x3
  const char *v113; // x20
  const char *v114; // x4
  __int64 v115; // x5
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x20
  unsigned __int64 v126; // x8
  __int64 v127; // x9
  unsigned __int8 *v128; // x9
  unsigned int v129; // w12
  char v130; // w10
  unsigned __int64 v131; // x11
  __int64 v132; // x12
  __int64 v133; // x0
  __int64 v134; // x0
  unsigned __int8 *v135; // x9
  unsigned int v136; // w11
  char v137; // w10
  __int64 v138; // x11
  unsigned __int8 *v139; // x9
  size_t v140; // x2
  __int64 v141; // x8
  const void *v142; // x1
  __int64 v143; // x9
  int phymode; // w0
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  __int64 v153; // x8
  char v154; // w8
  __int64 v155; // x8
  unsigned __int16 *v156; // x8
  int v157; // w8
  _BYTE *v158; // x8
  __int64 v159; // x4
  __int64 v160; // x5
  __int64 v161; // x6
  __int64 v162; // x7
  int v163; // w9
  unsigned int v164; // w20
  const char *v165; // x2
  __int64 v166; // x9
  char v167; // w8
  __int64 v168; // x20
  unsigned __int64 v169; // x8
  char v170; // w8
  _BYTE *v171; // x21
  int v172; // w26
  unsigned __int64 v173; // x22
  char *v174; // x0
  int v175; // w8
  __int64 v176; // x8
  _QWORD *v177; // x0
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  __int64 v186; // x21
  __int64 v187; // x22
  unsigned __int8 *v188; // x21
  __int64 v189; // x23
  __int64 v190; // x22
  unsigned __int8 v191; // w26
  unsigned int v192; // w24
  char is_freq_enabled; // w0
  __int64 v194; // x24
  int v195; // w22
  unsigned int v196; // w27
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  unsigned int v205; // w0
  unsigned int v206; // w8
  __int64 v207; // x5
  int v208; // w8
  unsigned int v209; // w8
  __int64 v210; // x22
  unsigned int v211; // w9
  __int64 v212; // x21
  unsigned int v213; // w8
  unsigned int v214; // w8
  __int64 v215; // [xsp+0h] [xbp-B0h]
  __int64 v216; // [xsp+8h] [xbp-A8h]
  __int64 v217; // [xsp+10h] [xbp-A0h]
  __int64 v218; // [xsp+18h] [xbp-98h]
  const void *v219; // [xsp+20h] [xbp-90h]
  __int64 v220; // [xsp+28h] [xbp-88h]
  __int64 v221; // [xsp+30h] [xbp-80h]
  _QWORD *v222; // [xsp+38h] [xbp-78h]
  _QWORD *v223; // [xsp+38h] [xbp-78h]
  unsigned int v224; // [xsp+44h] [xbp-6Ch]
  unsigned int v225; // [xsp+44h] [xbp-6Ch]
  unsigned int v226; // [xsp+44h] [xbp-6Ch]
  unsigned int v227; // [xsp+48h] [xbp-68h]
  unsigned int v228; // [xsp+48h] [xbp-68h]
  unsigned int v229; // [xsp+4Ch] [xbp-64h]
  unsigned int v230; // [xsp+4Ch] [xbp-64h]
  __int64 v231; // [xsp+50h] [xbp-60h]
  __int64 v232; // [xsp+50h] [xbp-60h]
  __int64 v233; // [xsp+50h] [xbp-60h]
  __int64 v234; // [xsp+58h] [xbp-58h]
  __int64 v235; // [xsp+58h] [xbp-58h]
  char **v236; // [xsp+60h] [xbp-50h]
  char **v237; // [xsp+60h] [xbp-50h]
  _QWORD *v238; // [xsp+68h] [xbp-48h]
  _QWORD *v239; // [xsp+68h] [xbp-48h]
  _QWORD *v240; // [xsp+70h] [xbp-40h]
  _QWORD *v241; // [xsp+70h] [xbp-40h]
  unsigned int v242; // [xsp+78h] [xbp-38h]
  unsigned int v243; // [xsp+78h] [xbp-38h]
  int v244; // [xsp+7Ch] [xbp-34h]
  unsigned int v245; // [xsp+80h] [xbp-30h]
  __int64 v246; // [xsp+80h] [xbp-30h]
  unsigned int v247; // [xsp+80h] [xbp-30h]
  _QWORD v248[4]; // [xsp+90h] [xbp-20h] BYREF

  v248[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = qdf_mem_malloc_atomic_fl(0x6C8u, (__int64)"util_scan_gen_scan_entry", 0xA32u);
  if ( !v14 )
  {
    v111 = 2;
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: failed to allocate memory for scan_entry",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "util_scan_gen_scan_entry");
    goto LABEL_268;
  }
  v23 = (__int64)v14;
  v24 = qdf_mem_malloc_atomic_fl(a3, (__int64)"util_scan_gen_scan_entry", 0xA39u);
  *(_QWORD *)(v23 + 1712) = v24;
  if ( !v24 )
  {
    v111 = 2;
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: failed to allocate memory for frame",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "util_scan_gen_scan_entry");
    _qdf_mem_free(v23);
    goto LABEL_268;
  }
  *(_QWORD *)(v23 + 1168) = ktime_get_with_offset(1);
  *(_BYTE *)v23 = a4;
  qdf_mem_copy((void *)(v23 + 1), a2 + 8, 6u);
  qdf_mem_copy((void *)(v23 + 7), a2 + 5, 6u);
  *(_WORD *)(v23 + 48) = a2[11] >> 4;
  v33 = (unsigned __int8)a5[2] << 7;
  *(_BYTE *)(v23 + 61) = a5[2];
  *(_DWORD *)(v23 + 64) = v33;
  v34 = a5[9];
  *(_BYTE *)(v23 + 60) = v34;
  *(_DWORD *)(v23 + 56) = (char)v34 << 7;
  *(_DWORD *)(v23 + 1128) = a5[10];
  *(_BYTE *)(v23 + 1720) = *(_BYTE *)(a1 + 40);
  v35 = *a5;
  *(_DWORD *)(v23 + 1728) = *a5;
  qdf_mem_copy((void *)(v23 + 1160), a5 + 3, 4u);
  v36 = wlan_reg_freq_to_band(v35);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 80) + 21LL) & 0x80) == 0 )
  {
    v37 = *(unsigned __int8 *)(v23 + 1160);
    v38 = *(unsigned __int8 *)(v23 + 1161);
    v39 = *(unsigned __int8 *)(v23 + 1162);
    v40 = v37 == 128;
    v41 = v37 - 96;
    if ( v40 )
      v41 = -1;
    v40 = v38 == 128;
    v42 = v38 - 96;
    *(_BYTE *)(v23 + 1160) = v41;
    v43 = *(unsigned __int8 *)(v23 + 1163);
    if ( v40 )
      v42 = -1;
    *(_BYTE *)(v23 + 1161) = v42;
    v44 = v39 - 96;
    if ( v39 == 128 )
      v44 = -1;
    v40 = v43 == 128;
    v45 = v43 - 96;
    if ( v40 )
      v45 = -1;
    *(_BYTE *)(v23 + 1162) = v44;
    *(_BYTE *)(v23 + 1163) = v45;
  }
  v46 = "s_thermal_cdev_register";
  *(_DWORD *)(v23 + 1176) = jiffies;
  v47 = a2[16];
  if ( !v47 )
    v47 = 100;
  *(_WORD *)(v23 + 68) = v47;
  *(_WORD *)(v23 + 70) = a2[17];
  qdf_mem_copy((void *)(v23 + 72), a2 + 12, 8u);
  *(_BYTE *)(v23 + 80) = 1;
  system_time = qdf_mc_timer_get_system_time();
  v49 = *(void **)(v23 + 1712);
  *(_QWORD *)(v23 + 88) = system_time;
  *(_DWORD *)(v23 + 1704) = a3;
  qdf_mem_copy(v49, a2, (unsigned int)a3);
  v58 = *(_QWORD *)(a1 + 80);
  if ( !v58 )
  {
    v112 = "util_scan_populate_bcn_ie_list";
LABEL_255:
    qdf_trace_msg(0x15u, 2u, "%s: psoc is NULL", v50, v51, v52, v53, v54, v55, v56, v57, v112);
    goto LABEL_266;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v58, 3u);
  if ( !comp_private_obj )
  {
    v113 = "util_scan_populate_bcn_ie_list";
    v114 = "util_scan_populate_bcn_ie_list";
    v115 = 1504;
LABEL_257:
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wlan_psoc_get_scan_obj_fl",
      v114,
      v115);
    qdf_trace_msg(0x15u, 2u, "%s: scan_obj is NULL", v116, v117, v118, v119, v120, v121, v122, v123, v113);
    goto LABEL_266;
  }
  v60 = 1LL << v36;
  v61 = (unsigned __int16)(*(_WORD *)(v23 + 1704) - 36);
  if ( v61 < 2 )
  {
    v62 = 0;
    if ( !*(_QWORD *)(v23 + 1688) )
      goto LABEL_264;
    goto LABEL_261;
  }
  v62 = 0;
  v63 = 0;
  v64 = (_QWORD *)(v23 + 1536);
  v65 = (_QWORD *)(v23 + 1528);
  v66 = *(_QWORD *)(v23 + 1712) + 36LL;
  v67 = (char **)(v23 + 1208);
  v68 = v23 + 1456;
  while ( 2 )
  {
    v46 = nullptr;
    v69 = v61;
    while ( 1 )
    {
      v70 = &v46[v66];
      v71 = (unsigned __int8)v46[v66 + 1];
      if ( v46[v66 + 1] )
        break;
      v69 -= 2;
      v46 += 2;
      if ( v69 <= 1 )
      {
        v46 = "s_thermal_cdev_register";
        goto LABEL_260;
      }
    }
    if ( v61 - (unsigned int)v46 - 2 >= v71 )
    {
      switch ( *v70 )
      {
        case 0:
          if ( v71 > 0x20 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1216) = v70;
          goto LABEL_156;
        case 1:
          if ( v71 > 0xC )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1224) = v70;
          goto LABEL_156;
        case 3:
          v234 = v68;
          v236 = v67;
          v238 = v65;
          v240 = v64;
          v242 = v63;
          if ( v71 != 1 )
            goto LABEL_266;
          *(_QWORD *)(v23 + 1240) = v70;
          v81 = v35;
          v82 = a6;
          v83 = comp_private_obj;
          v84 = v61;
          v231 = v66;
          v245 = (unsigned __int8)v46[v66 + 2];
          v62 = wlan_reg_chan_band_to_freq(a1, v245, v60, v50, v51, v52, v53, v54, v55, v56, v57);
          if ( *(_BYTE *)(v83 + 18740) != 1 )
            goto LABEL_78;
          v224 = v62;
          if ( (wlan_reg_is_freq_enabled(a1, v62, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
          {
            v159 = *(unsigned __int8 *)(v23 + 1);
            v160 = *(unsigned __int8 *)(v23 + 2);
            v161 = *(unsigned __int8 *)(v23 + 3);
            v162 = *(unsigned __int8 *)(v23 + 6);
            v165 = "%s: %02x:%02x:%02x:**:**:%02x: Drop as invalid chan %d in DS IE, freq %d, band_mask %d";
            LODWORD(v217) = (unsigned __int8)v60;
            LODWORD(v216) = v224;
            LODWORD(v215) = v245;
            goto LABEL_393;
          }
          v62 = v224;
LABEL_78:
          comp_private_obj = v83;
          a6 = v82;
          v35 = v81;
          v66 = v231;
          v61 = v84;
          goto LABEL_155;
        case 5:
          if ( v71 < 4 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1200) = v70;
          *(_BYTE *)(v23 + 81) = v46[v66 + 3];
          goto LABEL_156;
        case 7:
          if ( v71 < 3 )
            goto LABEL_391;
          *v67 = v70;
          goto LABEL_156;
        case 11:
          if ( v71 == 5 )
            *(_QWORD *)(v23 + 1376) = v70;
          goto LABEL_156;
        case 37:
          if ( v71 != 3 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1248) = v70;
          goto LABEL_156;
        case 40:
          if ( v71 != 6 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1320) = v70;
          goto LABEL_156;
        case 41:
          if ( v71 < 7 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1416) = v70;
          goto LABEL_156;
        case 42:
          if ( v71 != 1 )
            goto LABEL_391;
          *(_BYTE *)(v23 + 80) = v46[v66 + 2];
          goto LABEL_156;
        case 45:
          if ( v71 == 26 )
            *(_QWORD *)(v23 + 1328) = &v46[v66 + 2];
          goto LABEL_156;
        case 48:
          if ( v71 != 1 )
            *(_QWORD *)(v23 + 1288) = v70;
          goto LABEL_156;
        case 50:
          if ( v71 > 0xC )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1232) = v70;
          goto LABEL_156;
        case 54:
          if ( v71 != 3 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1560) = v70;
          goto LABEL_156;
        case 60:
          if ( v71 != 4 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1256) = v70;
          goto LABEL_156;
        case 61:
          if ( v71 != 22 )
            goto LABEL_391;
          v228 = v61;
          v236 = v67;
          v238 = v65;
          *(_QWORD *)(v23 + 1336) = &v46[v66 + 2];
          v102 = (unsigned __int8)v46[v66 + 2];
          v234 = v68;
          v103 = a6;
          v240 = v64;
          v242 = v63;
          v233 = v66;
          v104 = comp_private_obj;
          v62 = wlan_reg_chan_band_to_freq(a1, v102, v60, v50, v51, v52, v53, v54, v55, v56, v57);
          if ( *(_BYTE *)(v104 + 18740) == 1 )
          {
            v247 = v102;
            v105 = v62;
            if ( (wlan_reg_is_freq_enabled(a1, v62, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
            {
              v212 = jiffies;
              if ( util_scan_populate_bcn_ie_list___last_ticks - jiffies + 125 < 0 )
              {
                LODWORD(v215) = v247;
                qdf_trace_msg(
                  0x15u,
                  8u,
                  "%s: %02x:%02x:%02x:**:**:%02x: Drop as invalid channel %d freq %d in HT_INFO IE",
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  "util_scan_populate_bcn_ie_list",
                  *(unsigned __int8 *)(v23 + 1),
                  *(unsigned __int8 *)(v23 + 2),
                  *(unsigned __int8 *)(v23 + 3),
                  *(unsigned __int8 *)(v23 + 6),
                  v215,
                  v105);
                util_scan_populate_bcn_ie_list___last_ticks = v212;
              }
              goto LABEL_266;
            }
            comp_private_obj = v104;
            a6 = v103;
            v62 = v105;
          }
          else
          {
            comp_private_obj = v104;
            a6 = v103;
          }
          v66 = v233;
          v61 = v228;
LABEL_155:
          v65 = v238;
          v64 = v240;
          v63 = v242;
          v67 = v236;
          v68 = v234;
          goto LABEL_156;
        case 62:
          if ( v71 != 1 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1552) = v70;
          goto LABEL_156;
        case 68:
          if ( v71 < 0x14 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1384) = v70;
          goto LABEL_156;
        case 127:
          if ( v71 > 0xF )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1408) = v70;
          goto LABEL_156;
        case -65:
          if ( v71 != 12 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1432) = v70;
          goto LABEL_156;
        case -64:
          if ( v71 != 5 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1440) = v70;
          goto LABEL_156;
        case -61:
          if ( v71 == 1 || v63 > 7 )
            goto LABEL_391;
          *(_QWORD *)(v68 + 8LL * v63++) = v70;
          goto LABEL_156;
        case -60:
          *(_QWORD *)(v23 + 1520) = v70;
          v75 = (unsigned __int8)v70[1];
          if ( v75 < 2 )
            goto LABEL_156;
          v76 = &v46[v66 + 2];
          while ( 2 )
          {
            v79 = (unsigned __int8)v76[1];
            v75 -= 2LL;
            if ( !v76[1] )
              goto LABEL_59;
            if ( v75 < v79 )
            {
              v186 = jiffies;
              if ( util_scan_parse_chan_switch_wrapper_ie___last_ticks - jiffies + 125 < 0 )
              {
                LODWORD(v215) = 196;
                v187 = v66;
                qdf_trace_msg(
                  0x15u,
                  8u,
                  "%s: %02x:%02x:%02x:**:**:%02x: Incomplete corrupted IE:%x",
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  "util_scan_parse_chan_switch_wrapper_ie",
                  *(unsigned __int8 *)(v23 + 1),
                  *(unsigned __int8 *)(v23 + 2),
                  *(unsigned __int8 *)(v23 + 3),
                  *(unsigned __int8 *)(v23 + 6),
                  v215);
                v66 = v187;
                util_scan_parse_chan_switch_wrapper_ie___last_ticks = v186;
              }
              goto LABEL_391;
            }
            v80 = (unsigned __int8)*v76;
            switch ( v80 )
            {
              case 195:
                v40 = (_DWORD)v79 == 1;
                v78 = (char **)v64;
                if ( v40 )
                  goto LABEL_391;
                break;
              case 194:
                v77 = (unsigned int)v79 >= 3;
                v78 = (char **)v65;
                if ( !v77 )
                  goto LABEL_391;
                break;
              case 7:
                v77 = (unsigned int)v79 >= 3;
                v78 = v67;
                if ( !v77 )
                  goto LABEL_391;
                break;
              default:
                goto LABEL_58;
            }
            *v78 = v76;
            v79 = (unsigned __int8)v76[1];
LABEL_58:
            v76 += v79;
            v75 -= v79;
LABEL_59:
            v76 += 2;
            if ( v75 <= 1 )
              goto LABEL_156;
            continue;
          }
        case -57:
          if ( v71 != 1 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1448) = v70;
          goto LABEL_156;
        case -55:
          if ( v71 < 5 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1632) = v70;
          v229 = v35;
          v85 = &v46[v66 + 6];
          v86 = *(unsigned __int8 *)(v23 + 132);
          if ( v85 > &v46[v66 + 2 + (unsigned __int8)v70[1]] )
            goto LABEL_152;
          v218 = v60;
          v219 = a6;
          v87 = &v46[v66 + 2];
          v235 = v68;
          v237 = v67;
          v239 = v65;
          v241 = v64;
          v243 = v63;
          v225 = v62;
          v227 = v61;
          v232 = v66;
          v220 = a1;
          v221 = comp_private_obj;
          v222 = a7;
          v246 = (__int64)&v46[v66 + 2 + (unsigned __int8)v70[1]];
          break;
        case -35:
          if ( !*(_QWORD *)(v23 + 1368) )
          {
            *(_QWORD *)(v23 + 1368) = v70;
            v71 = (unsigned __int8)v70[1];
          }
          if ( v71 < 4 )
            goto LABEL_156;
          v73 = (int *)&v46[v66 + 2];
          v72 = *v73;
          if ( *v73 == 82989056 )
          {
            *(_QWORD *)(v23 + 1296) = v70;
            if ( (unsigned __int8)v70[1] >= 5u && *v73 == 82989056 )
              *(_QWORD *)(v23 + 1280) = v70;
            goto LABEL_156;
          }
          if ( v72 == 32657408 )
          {
            *(_QWORD *)(v23 + 1272) = v70;
            goto LABEL_156;
          }
          if ( v71 >= 6 && v72 == 49434624 )
          {
            if ( !v46[v66 + 6] )
            {
              *(_QWORD *)(v23 + 1304) = v70;
              goto LABEL_156;
            }
            if ( v46[v66 + 6] != 1 )
              goto LABEL_156;
            if ( v71 <= 0x18 )
            {
              *(_QWORD *)(v23 + 1312) = v70;
              goto LABEL_156;
            }
            goto LABEL_391;
          }
          if ( v72 == 75432704 )
          {
            if ( v71 <= 0xA )
            {
              *(_QWORD *)(v23 + 1352) = v70;
              goto LABEL_156;
            }
            goto LABEL_391;
          }
          if ( v72 == 25101056 )
          {
            if ( v71 <= 9 )
            {
              *(_QWORD *)(v23 + 1344) = v70;
              goto LABEL_156;
            }
            goto LABEL_391;
          }
          v108 = (const void *)v66;
          if ( v71 == 4 )
          {
            if ( v72 <= 860655615 )
            {
              if ( v72 == 161115984 )
              {
LABEL_206:
                *(_QWORD *)(v23 + 1392) = v70;
                goto LABEL_156;
              }
              if ( v72 != 379219792 )
                goto LABEL_156;
LABEL_194:
              *(_QWORD *)(v23 + 1616) = v70;
              goto LABEL_156;
            }
            if ( v72 == 860655616 )
            {
              v109 = *(_QWORD *)(v23 + 1328);
            }
            else
            {
              if ( v72 != 877432832 )
                goto LABEL_156;
              v109 = *(_QWORD *)(v23 + 1336);
            }
            if ( v109 )
              goto LABEL_156;
            goto LABEL_391;
          }
          if ( v72 <= 345391103 )
          {
            if ( v72 == 15793548 )
            {
              if ( !v46[v66 + 6] )
                *(_QWORD *)(v23 + 1424) = v70;
              goto LABEL_156;
            }
            if ( v72 == 161115984 )
              goto LABEL_206;
          }
          else
          {
            switch ( v72 )
            {
              case 877432832:
                if ( *(_QWORD *)(v23 + 1336) )
                  goto LABEL_156;
                if ( v71 == 26 )
                {
                  *(_QWORD *)(v23 + 1336) = &v46[v66 + 6];
                  goto LABEL_156;
                }
                goto LABEL_391;
              case 860655616:
                if ( *(_QWORD *)(v23 + 1328) )
                  goto LABEL_156;
                if ( v71 == 30 )
                {
                  *(_QWORD *)(v23 + 1328) = &v46[v66 + 6];
                  goto LABEL_156;
                }
                goto LABEL_391;
              case 345391104:
                if ( v71 <= 5 )
                {
                  *(_QWORD *)(v23 + 1360) = v70;
                  goto LABEL_156;
                }
                goto LABEL_391;
            }
          }
          if ( v71 >= 0xD && v72 == 72126464 )
          {
            if ( (v46[v66 + 6] & 0xEF) != 8 || *(_QWORD *)(v23 + 1432) )
              goto LABEL_156;
            if ( v71 >= 0x13 && v46[v66 + 8] == 12 )
            {
              *(_QWORD *)(v23 + 1432) = &v46[v66 + 7];
              v110 = (unsigned __int8)v70[1];
              if ( v110 < 0x14 )
                goto LABEL_156;
              if ( v110 >= 0x1A && v46[v66 + 22] == 5 )
              {
                *(_QWORD *)(v23 + 1440) = &v46[v66 + 21];
                goto LABEL_156;
              }
            }
            goto LABEL_391;
          }
          if ( v72 > 379219791 )
          {
            if ( v72 <= 714764111 )
            {
              if ( v72 != 379219792 )
              {
                if ( v72 == 697986896 )
                  *(_QWORD *)(v23 + 1680) = v70;
                goto LABEL_156;
              }
              goto LABEL_194;
            }
            if ( v72 == 714764112 )
            {
              *(_QWORD *)(v23 + 1696) = v70;
              goto LABEL_156;
            }
            if ( v72 == 731541328 )
            {
              *(_QWORD *)(v23 + 1688) = v70;
              goto LABEL_156;
            }
            if ( v72 != 748044288 )
              goto LABEL_156;
            if ( v71 - 9 >= 0xFFFFFFFB )
            {
              *(_QWORD *)(v23 + 1648) = v73;
              goto LABEL_156;
            }
LABEL_391:
            v159 = *(unsigned __int8 *)(v23 + 1);
            v160 = *(unsigned __int8 *)(v23 + 2);
            v161 = *(unsigned __int8 *)(v23 + 3);
            v162 = *(unsigned __int8 *)(v23 + 6);
            v165 = "%s: %02x:%02x:%02x:**:**:%02x: failed to parse IE - id: %d, len: %d";
            v163 = (unsigned __int8)v46[v66];
            LODWORD(v216) = (unsigned __int8)v46[v66 + 1];
LABEL_392:
            LODWORD(v215) = v163;
LABEL_393:
            qdf_trace_msg(
              0x15u,
              8u,
              v165,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              "util_scan_populate_bcn_ie_list",
              v159,
              v160,
              v161,
              v162,
              v215,
              v216,
              v217);
LABEL_266:
            _qdf_mem_free(*(_QWORD *)(v23 + 1712));
            _qdf_mem_free(v23);
LABEL_267:
            v111 = 16;
            goto LABEL_268;
          }
          if ( v72 > 66125195 )
          {
            if ( v72 == 66125196 )
            {
              *(_QWORD *)(v23 + 1640) = v70;
            }
            else if ( v72 == 92209920 && v71 >= 8 )
            {
              *(_QWORD *)(v23 + 1544) = &v46[v66 + 8];
            }
            goto LABEL_156;
          }
          if ( v72 == 32570764 )
          {
            *(_QWORD *)(v23 + 1672) = v70;
            goto LABEL_156;
          }
          if ( v72 == 60178432 )
          {
            if ( v71 - 9 > 0xFFFFFFFA )
            {
              *(_QWORD *)(v23 + 1656) = v73;
              goto LABEL_156;
            }
            goto LABEL_441;
          }
LABEL_156:
          v106 = (unsigned __int8)v70[1];
          v61 = v61 - v106 - (_DWORD)v46 - 2;
          v107 = &v46[v66];
          v46 = "s_thermal_cdev_register";
          v66 = (__int64)&v107[v106 + 2];
          if ( v61 > 1 )
            continue;
LABEL_260:
          if ( *(_QWORD *)(v23 + 1688) )
            goto LABEL_261;
          goto LABEL_264;
        case -16:
          if ( v71 == 1 )
            goto LABEL_391;
          *(_QWORD *)(v23 + 1600) = v70;
          goto LABEL_156;
        case -12:
          *(_QWORD *)(v23 + 1664) = v70;
          goto LABEL_156;
        case -1:
          v74 = (unsigned __int8)v46[v66 + 2];
          if ( v74 <= 0x25 )
          {
            switch ( v74 )
            {
              case 0xBu:
                *(_QWORD *)(v23 + 1608) = v70;
                goto LABEL_156;
              case 0x23u:
                if ( v71 - 56 >= 0xFFFFFFDE )
                {
                  *(_QWORD *)(v23 + 1568) = v70;
                  goto LABEL_156;
                }
                break;
              case 0x24u:
                if ( v71 <= 0x10 )
                {
                  *(_QWORD *)(v23 + 1584) = v70;
                  goto LABEL_156;
                }
                break;
              default:
                goto LABEL_156;
            }
          }
          else if ( (unsigned __int8)v46[v66 + 2] > 0x33u )
          {
            if ( v74 == 59 )
            {
              if ( v71 <= 3 )
              {
                *(_QWORD *)(v23 + 1576) = v70;
                goto LABEL_156;
              }
            }
            else
            {
              if ( v74 != 52 )
                goto LABEL_156;
              if ( v71 == 4 )
              {
                *(_QWORD *)(v23 + 1264) = v70;
                goto LABEL_156;
              }
            }
          }
          else if ( v74 == 38 )
          {
            if ( v71 <= 0xE )
            {
              *(_QWORD *)(v23 + 1624) = v70;
              goto LABEL_156;
            }
          }
          else
          {
            if ( v74 != 39 )
              goto LABEL_156;
            if ( v71 <= 0x15 )
            {
              *(_QWORD *)(v23 + 1592) = v70;
              goto LABEL_156;
            }
          }
          goto LABEL_391;
        default:
          goto LABEL_156;
      }
LABEL_88:
      v89 = *(unsigned __int16 *)v87;
      v90 = (unsigned __int8)v89 >> 4;
      v91 = v89 >> 8;
      LODWORD(v215) = v89 & 3;
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: chan %d, opclass %d tbtt_cnt %d, tbtt_len %d, fieldtype %d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "util_scan_parse_rnr_ie",
        (unsigned __int8)v87[3],
        (unsigned __int8)v87[2],
        (unsigned __int8)v89 >> 4,
        (unsigned int)(v89 >> 8),
        v215);
      v92 = v246;
      v93 = v90;
      v94 = 0;
      v95 = v86;
      v244 = v90;
      while ( 1 )
      {
        v88 = &v85[v91];
        if ( (unsigned __int64)&v85[v91] > v92 )
        {
          v86 = v95;
          v88 = v85;
LABEL_87:
          v85 = v88 + 4;
          v87 = v88;
          if ( (unsigned __int64)(v88 + 4) > v92 )
          {
            comp_private_obj = v221;
            a7 = v222;
            a6 = v219;
            a1 = v220;
            v62 = v225;
            v61 = v227;
            v66 = v232;
            v68 = v235;
            v65 = v239;
            v64 = v241;
            v60 = v218;
            v63 = v243;
            v67 = v237;
LABEL_152:
            *(_BYTE *)(v23 + 132) = v86;
            v35 = v229;
            goto LABEL_156;
          }
          goto LABEL_88;
        }
        if ( v95 > 0x20 )
        {
          v86 = v95;
        }
        else
        {
          v97 = v23 + 136 + 28LL * v95;
          v86 = v95 + 1;
          v98 = HIBYTE(*(unsigned __int16 *)v87);
          if ( (unsigned int)v98 > 0x10 )
            v98 = 16;
          if ( v98 > 8 )
          {
            if ( v98 > 11 )
            {
              if ( v98 == 12 )
                goto LABEL_106;
              if ( v98 == 13 || v98 == 16 )
              {
                *(_BYTE *)(v97 + 25) = v85[12];
LABEL_106:
                *(_BYTE *)(v97 + 24) = v85[11];
LABEL_112:
                *(_DWORD *)(v97 + 4) = (unsigned __int8)v87[3];
                *(_DWORD *)(v97 + 8) = (unsigned __int8)v87[2];
                qdf_mem_copy((void *)(v97 + 12), v85 + 1, 6u);
                v99 = (void *)(v97 + 20);
                v100 = v85 + 7;
LABEL_118:
                v101 = 4;
LABEL_119:
                qdf_mem_copy(v99, v100, v101);
LABEL_120:
                v93 = v244;
                v92 = v246;
                goto LABEL_90;
              }
LABEL_121:
              qdf_trace_msg(
                0x15u,
                8u,
                "%s: Wrong fieldtype",
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                "util_scan_update_rnr");
              goto LABEL_120;
            }
            if ( v98 != 9 )
            {
              if ( v98 == 11 )
                goto LABEL_112;
              goto LABEL_121;
            }
            *(_BYTE *)(v97 + 25) = v85[8];
LABEL_114:
            *(_BYTE *)(v97 + 24) = v85[7];
LABEL_115:
            v99 = (void *)(v97 + 12);
            v100 = v85 + 1;
            v101 = 6;
            *(_DWORD *)(v97 + 4) = (unsigned __int8)v87[3];
            *(_DWORD *)(v97 + 8) = (unsigned __int8)v87[2];
            goto LABEL_119;
          }
          if ( v98 > 5 )
          {
            if ( v98 != 6 )
            {
              if ( v98 != 7 )
                goto LABEL_114;
              goto LABEL_115;
            }
            *(_BYTE *)(v97 + 24) = v85[5];
LABEL_117:
            v99 = (void *)(v97 + 20);
            v100 = v85 + 1;
            *(_DWORD *)(v97 + 4) = (unsigned __int8)v87[3];
            *(_DWORD *)(v97 + 8) = (unsigned __int8)v87[2];
            goto LABEL_118;
          }
          if ( (unsigned int)(v98 - 1) >= 2 )
          {
            if ( v98 != 5 )
              goto LABEL_121;
            goto LABEL_117;
          }
        }
LABEL_90:
        v96 = v93 > v94++;
        v85 += v91;
        v95 = v86;
        if ( !v96 )
          goto LABEL_87;
      }
    }
    break;
  }
  v159 = *(unsigned __int8 *)(v23 + 1);
  v160 = *(unsigned __int8 *)(v23 + 2);
  v161 = *(unsigned __int8 *)(v23 + 3);
  v162 = *(unsigned __int8 *)(v23 + 6);
  v163 = (unsigned __int8)v46[v66];
  if ( *(_BYTE *)(comp_private_obj + 23986) != 1 )
  {
    v165 = "%s: %02x:%02x:%02x:**:**:%02x: Scan not allowed with incomplete corrupted IE:%x, ie_len: %d, ie->ie_len: %d, "
           "stop processing further";
    LODWORD(v217) = (unsigned __int8)v46[v66 + 1];
    LODWORD(v216) = v61 - 2 - (_DWORD)v46;
    goto LABEL_392;
  }
  v164 = v62;
  LODWORD(v215) = (unsigned __int8)v46[v66];
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: %02x:%02x:%02x:**:**:%02x: Scan allowed with incomplete corrupted IE:%x, ie_len: %d, ie->ie_len: %d, stop processing further",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "util_scan_populate_bcn_ie_list",
    v159,
    v160,
    v161,
    v162,
    v215,
    v61 - 2 - (_DWORD)v46,
    (unsigned __int8)v46[v66 + 1]);
  v62 = v164;
  v46 = "s_thermal_cdev_register";
  if ( *(_QWORD *)(v23 + 1688) )
  {
LABEL_261:
    if ( !*(_QWORD *)(v23 + 1680) && !*(_QWORD *)(v23 + 1696) )
      *(_QWORD *)(v23 + 1688) = 0;
  }
LABEL_264:
  v124 = *(_QWORD *)(v23 + 1216);
  if ( v124 && *(unsigned __int8 *)(v124 + 1) >= 0x21u )
    goto LABEL_266;
  if ( *(_QWORD *)(v23 + 1392) )
    *(_BYTE *)(v23 + 85) = 1;
  v108 = a6;
  if ( v62 )
    goto LABEL_272;
  v126 = *(_QWORD *)(v23 + 1568);
  if ( !v126 )
  {
    v62 = 0;
    goto LABEL_273;
  }
  v133 = *(_QWORD *)(a1 + 80);
  if ( !v133 )
  {
    v112 = "util_scan_get_chan_from_he_6g_params";
    goto LABEL_255;
  }
  v134 = wlan_objmgr_psoc_get_comp_private_obj(v133, 3u);
  if ( !v134 )
  {
    v113 = "util_scan_get_chan_from_he_6g_params";
    v114 = "util_scan_get_chan_from_he_6g_params";
    v115 = 608;
    goto LABEL_257;
  }
  v62 = 0;
  if ( !*(_QWORD *)(v23 + 1568) )
    goto LABEL_401;
  v135 = *(unsigned __int8 **)(v23 + 1584);
  LOBYTE(v126) = 0;
  if ( !v135 )
    goto LABEL_273;
  v136 = v135[1];
  v137 = v136 - 7;
  if ( v136 >= 7 && (v135[5] & 2) != 0 && (_BYTE)v136 != 7 )
  {
    v126 = v135[4];
    if ( (v126 & 0x40) == 0 )
    {
      v138 = 9;
      goto LABEL_395;
    }
    if ( (unsigned __int8)(v136 - 7) >= 4u )
    {
      v137 = v136 - 10;
      v138 = 12;
LABEL_395:
      v62 = 0;
      if ( (unsigned __int8)(v137 + ((unsigned int)(char)v126 >> 7)) >= 5u )
      {
        v188 = &v135[v138 + (v126 >> 7)];
        LOBYTE(v126) = 0;
        if ( !v188 )
          goto LABEL_273;
        v230 = v35;
        v189 = a1;
        v190 = v134;
        v191 = v60;
        v62 = wlan_reg_chan_band_to_freq(v189, *v188, v60, v50, v51, v52, v53, v54, v55, v56, v57);
        if ( *(_BYTE *)(v190 + 18740) == 1 )
        {
          v192 = v62;
          is_freq_enabled = wlan_reg_is_freq_enabled(v189, v62, v50, v51, v52, v53, v54, v55, v56, v57);
          v62 = v192;
          if ( (is_freq_enabled & 1) == 0 )
          {
            v210 = jiffies;
            if ( util_scan_get_chan_from_he_6g_params___last_ticks - jiffies + 125 < 0 )
            {
              LODWORD(v216) = v192;
              LODWORD(v215) = *v188;
              qdf_trace_msg(
                0x15u,
                8u,
                "%s: %02x:%02x:%02x:**:**:%02x: Drop as invalid channel %d freq %d in HE 6Ghz params",
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                "util_scan_get_chan_from_he_6g_params",
                *(unsigned __int8 *)(v23 + 1),
                *(unsigned __int8 *)(v23 + 2),
                *(unsigned __int8 *)(v23 + 3),
                *(unsigned __int8 *)(v23 + 6),
                v215,
                v216);
              util_scan_get_chan_from_he_6g_params___last_ticks = v210;
            }
            goto LABEL_266;
          }
        }
        v194 = v189;
        if ( (v188[1] & 4) == 0 )
        {
          v35 = v230;
          LOBYTE(v126) = 0;
          a1 = v194;
          goto LABEL_273;
        }
        v226 = v62;
        v195 = v188[1] & 3;
        v223 = a7;
        v196 = wlan_reg_chan_band_to_freq(v189, v188[2], v191, v50, v51, v52, v53, v54, v55, v56, v57);
        v205 = wlan_reg_chan_band_to_freq(v189, v188[3], v191, v197, v198, v199, v200, v201, v202, v203, v204);
        if ( v195 == 1 )
          v206 = 40;
        else
          v206 = 20;
        if ( v195 == 2 )
          v206 = 80;
        if ( v195 == 3 )
          v207 = 160;
        else
          v207 = v206;
        if ( v195 == 3 )
        {
          v35 = v230;
          if ( (~v188[1] & 3) == 0 && v188[3] )
          {
            v208 = v188[3] - v188[2];
            if ( v208 < 0 )
              v208 = v188[2] - v188[3];
            if ( v208 == 8 )
            {
              v35 = v230;
              v209 = v205 - v230;
              if ( (int)(v205 - v230) < 0 )
                v209 = v230 - v205;
              if ( v209 <= 0x50 )
              {
LABEL_437:
                LOBYTE(v126) = 1;
                goto LABEL_438;
              }
            }
            else
            {
              v35 = v230;
              if ( (unsigned int)v208 >= 9 )
              {
                v213 = v196 - v230;
                if ( (int)(v196 - v230) < 0 )
                  v213 = v230 - v196;
                if ( v213 < 0x29 )
                {
                  a7 = v223;
                  v35 = v230;
                  LOBYTE(v126) = 1;
LABEL_439:
                  v62 = v226;
                  a1 = v194;
                  goto LABEL_273;
                }
                v35 = v230;
                v214 = v205 - v230;
                if ( (int)(v205 - v230) < 0 )
                  v214 = v230 - v205;
                if ( v214 < 0x29 )
                  goto LABEL_437;
              }
            }
          }
        }
        else
        {
          v35 = v230;
          v211 = v196 - v230;
          if ( (int)(v196 - v230) < 0 )
            v211 = v230 - v196;
          if ( v211 <= v206 >> 1 )
            goto LABEL_437;
        }
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: Leaked freq:%u ch width:%u freq0:%u freq1:%u",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "util_scan_is_out_of_band_leak_he",
          v35,
          v207,
          v196,
          v205);
        LOBYTE(v126) = 0;
LABEL_438:
        a7 = v223;
        goto LABEL_439;
      }
LABEL_401:
      LOBYTE(v126) = 0;
      goto LABEL_273;
    }
  }
  v62 = 0;
LABEL_272:
  LOBYTE(v126) = 0;
LABEL_273:
  v127 = *(_QWORD *)(v23 + 1568);
  *(_BYTE *)(v23 + 1732) = 9;
  if ( v127 )
  {
    v128 = *(unsigned __int8 **)(v23 + 1584);
    if ( v128 )
    {
      v129 = v128[1];
      v130 = v129 - 7;
      if ( v129 >= 7 && (v128[5] & 2) != 0 && (_BYTE)v129 != 7 )
      {
        v131 = v128[4];
        if ( (v131 & 0x40) != 0 )
        {
          if ( (unsigned __int8)(v129 - 7) < 4u )
            goto LABEL_298;
          v130 = v129 - 10;
          v132 = 12;
        }
        else
        {
          v132 = 9;
        }
        if ( (unsigned __int8)(v130 + ((unsigned int)(char)v131 >> 7)) >= 5u )
        {
          v139 = &v128[v132 + (v131 >> 7)];
          if ( v139 )
            *(_BYTE *)(v23 + 1732) = (v139[1] >> 3) & 0xF;
        }
      }
    }
  }
LABEL_298:
  if ( v62 )
  {
    *(_DWORD *)(v23 + 1064) = v62;
  }
  else
  {
    v62 = *(_DWORD *)(v23 + 1064);
    if ( !v62 )
    {
      *(_DWORD *)(v23 + 1064) = v35;
      if ( !v124 )
        goto LABEL_314;
      goto LABEL_306;
    }
  }
  if ( v35 == v62 )
    LOBYTE(v126) = 1;
  if ( (v126 & 1) == 0 )
    *(_BYTE *)(v23 + 1088) = 1;
  if ( !v124 )
    goto LABEL_314;
LABEL_306:
  v140 = *(unsigned __int8 *)(v124 + 1);
  if ( *(_BYTE *)(v124 + 1) )
  {
    v141 = 0;
    v142 = (const void *)(v124 + 2);
    while ( v141 != 32 )
    {
      if ( *((_BYTE *)v142 + v141) )
      {
        qdf_mem_copy((void *)(v23 + 14), v142, v140);
        v143 = *(_QWORD *)(v23 + 88);
        *(_BYTE *)(v23 + 13) = *(_BYTE *)(v124 + 1);
        *(_QWORD *)(v23 + 104) = v143;
        goto LABEL_315;
      }
      if ( v140 == ++v141 )
        goto LABEL_314;
    }
    __break(0x5512u);
LABEL_441:
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: Invalid sae single pmk OUI",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "util_scan_parse_vendor_ie");
    v66 = (__int64)v108;
    goto LABEL_391;
  }
LABEL_314:
  *(_QWORD *)(v23 + 1216) = 0;
  *(_BYTE *)(v23 + 46) = 1;
LABEL_315:
  qdf_mem_copy((void *)(v23 + 112), v108, 0x12u);
  phymode = util_scan_get_phymode(a1, v23);
  v153 = *(_QWORD *)(v23 + 1568);
  *(_DWORD *)(v23 + 52) = phymode;
  *(_DWORD *)(v23 + 1724) = phymode;
  if ( v153 )
  {
    if ( v153 + 22 > v153 + (unsigned __int64)*(unsigned __int8 *)(v153 + 1) + 2 )
    {
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: mcs_map_offset exceeds he cap len",
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        "util_scan_scm_calc_nss_supported_by_ap");
LABEL_318:
      v154 = 1;
      goto LABEL_345;
    }
    v156 = (unsigned __int16 *)(v153 + 20);
LABEL_322:
    v157 = *v156;
    if ( (~v157 & 0xC000) != 0 )
    {
      v154 = 8;
      goto LABEL_345;
    }
    if ( (~v157 & 0x3000) != 0 )
    {
      v154 = 7;
      goto LABEL_345;
    }
    if ( (~v157 & 0xC00) != 0 )
    {
      v154 = 6;
      goto LABEL_345;
    }
    if ( (~v157 & 0x300) != 0 )
    {
      v154 = 5;
      goto LABEL_345;
    }
    if ( (~v157 & 0xC0) == 0 )
    {
      if ( (~v157 & 0x30) == 0 )
      {
        if ( (~v157 & 0xC) == 0 )
          goto LABEL_318;
        goto LABEL_344;
      }
LABEL_338:
      v154 = 3;
      goto LABEL_345;
    }
LABEL_333:
    v154 = 4;
    goto LABEL_345;
  }
  v155 = *(_QWORD *)(v23 + 1432);
  if ( v155 )
  {
    v156 = (unsigned __int16 *)(v155 + 6);
    goto LABEL_322;
  }
  v158 = *(_BYTE **)(v23 + 1328);
  if ( !v158 )
    goto LABEL_318;
  if ( v158[6] )
    goto LABEL_333;
  if ( v158[5] )
    goto LABEL_338;
  if ( !v158[4] )
    goto LABEL_318;
LABEL_344:
  v154 = 2;
LABEL_345:
  v166 = *(_QWORD *)(v23 + 1648);
  *(_BYTE *)(v23 + 84) = v154;
  if ( v166 )
    *(_BYTE *)(v23 + 86) = *(_BYTE *)(v166 + 4) & 1;
  if ( *(_QWORD *)(v23 + 1272) )
    *(_BYTE *)(v23 + 47) |= 2u;
  if ( *(_QWORD *)(v23 + 1288) )
    *(_BYTE *)(v23 + 47) |= 8u;
  if ( *(_QWORD *)(v23 + 1384) )
    *(_BYTE *)(v23 + 47) |= 4u;
  if ( *(_QWORD *)(v23 + 1680) || *(_QWORD *)(v23 + 1696) )
  {
    v167 = *(_BYTE *)(v23 + 47) | 0x10;
  }
  else
  {
    if ( *(_BYTE *)(v23 + 47) || (*(_WORD *)(v23 + 70) & 0x10) == 0 )
      goto LABEL_357;
    v167 = 1;
  }
  *(_BYTE *)(v23 + 47) = v167;
LABEL_357:
  v168 = *(_QWORD *)(v23 + 1608);
  memset(v248, 0, 15);
  if ( v168 )
  {
    v169 = *(unsigned __int8 *)(v168 + 1) - 1LL;
    if ( v169 <= 0xE )
    {
      if ( v169 >= 3 )
      {
        v171 = (_BYTE *)(v168 + 3);
        v172 = 1;
        v173 = ((unsigned __int64)*(unsigned __int8 *)(v168 + 1) - 1) / 3;
        while ( (unsigned __int64)v171 < v168 + (unsigned __int64)*(unsigned __int8 *)(v168 + 1) )
        {
          v174 = (char *)v248 + 3;
          v175 = *v171 & 3;
          if ( (*v171 & 3) != 0 )
          {
            v174 = (char *)&v248[1] + 1;
            if ( v175 != 2 )
            {
              v174 = (char *)v248 + 6;
              if ( v175 != 1 )
              {
                qdf_mem_copy((char *)&v248[1] + 4, v171, 3u);
                break;
              }
            }
          }
          qdf_mem_copy(v174, v171, 3u);
          v96 = v173 > v172++;
          v171 += 3;
          if ( !v96 )
            break;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: No of Air time fractions are greater than supported",
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        "util_scan_update_esp_data");
    }
    if ( (BYTE6(v248[0]) & 3) == 1 )
    {
      v170 = HIBYTE(v248[0]);
    }
    else if ( (BYTE1(v248[1]) & 3) == 2 )
    {
      v170 = BYTE2(v248[1]);
    }
    else if ( (~BYTE4(v248[1]) & 3) != 0 )
    {
      if ( (v248[0] & 0x3000000LL) != 0 )
        v170 = 0;
      else
        v170 = BYTE4(v248[0]);
    }
    else
    {
      v170 = BYTE5(v248[1]);
    }
    *(_BYTE *)(v23 + 82) = v170;
  }
  v176 = *(_QWORD *)(v23 + 1376);
  if ( v176 )
    *(_BYTE *)(v23 + 83) = *(_BYTE *)(v176 + 4);
  v177 = qdf_mem_malloc_atomic_fl(0x20u, (__int64)"util_scan_gen_scan_entry", 0xACBu);
  if ( !v177 )
  {
    _qdf_mem_free(*(_QWORD *)(v23 + 1712));
    _qdf_mem_free(v23);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: failed to allocate memory for scan_node",
      v178,
      v179,
      v180,
      v181,
      v182,
      v183,
      v184,
      v185,
      "util_scan_gen_scan_entry");
    goto LABEL_267;
  }
  v177[3] = v23;
  qdf_list_insert_front(a7, v177);
  v111 = 0;
LABEL_268:
  _ReadStatusReg(SP_EL0);
  return v111;
}
