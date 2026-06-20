__int64 __fastcall util_scan_unpack_beacon_frame(__int64 a1, _BYTE *a2, size_t a3, unsigned int a4, __int64 a5)
{
  _QWORD *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  unsigned __int64 v20; // x26
  __int64 v21; // x25
  __int64 v22; // x28
  int v23; // w9
  _BYTE *v24; // x8
  __int64 v25; // x10
  bool v26; // cf
  int v27; // w8
  _BYTE *v28; // x27
  __int64 v29; // x9
  __int64 v30; // x0
  __int64 comp_private_obj; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w9
  _BYTE *v49; // x8
  __int64 v50; // x10
  int v51; // w0
  __int64 v52; // x21
  __int64 v54; // x0
  unsigned __int64 v55; // x12
  int v56; // w16
  char *v57; // x27
  __int64 v58; // x13
  __int64 v59; // x14
  int v60; // w15
  _BYTE *v61; // x11
  int v62; // w8
  _BYTE *v63; // x17
  __int64 v64; // x9
  __int64 v65; // x8
  _BYTE *v66; // x8
  char *v67; // x12
  int v68; // w9
  __int64 v69; // x10
  size_t v70; // x10
  char v71; // w5
  unsigned int v72; // w8
  int v73; // w9
  _BYTE *v74; // x27
  __int64 v75; // x10
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned __int8 *v84; // x27
  int v85; // w8
  __int64 v86; // x4
  unsigned __int8 *v87; // x8
  int v88; // w9
  _BYTE *v89; // x8
  __int64 v90; // x10
  __int64 v91; // x8
  __int64 v92; // x9
  unsigned __int8 *v93; // x27
  unsigned __int64 v94; // x8
  unsigned int v95; // w10
  bool v96; // cc
  void *v97; // x0
  __int64 v98; // x27
  _DWORD *v99; // x8
  char v100; // w9
  int v101; // w10
  unsigned __int8 *v102; // x8
  __int64 v103; // x9
  char v104; // w9
  bool v105; // w9
  int v106; // w9
  unsigned __int64 v107; // x10
  int v108; // w11
  int v109; // w9
  int v110; // w9
  unsigned __int64 v111; // x10
  int v112; // w11
  size_t v113; // x8
  unsigned __int8 *v114; // x8
  unsigned __int8 *v115; // x27
  int v116; // w10
  __int64 v117; // x8
  size_t v118; // x2
  unsigned __int64 v119; // x10
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  unsigned __int8 *v128; // x8
  __int64 v129; // x8
  unsigned __int8 *v130; // x9
  unsigned __int64 v131; // x27
  unsigned int v132; // w27
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  bool v157; // zf
  int v158; // w27
  __int64 v159; // x8
  unsigned __int8 *v160; // x8
  __int64 v161; // x8
  unsigned __int8 *v162; // x8
  int v163; // w10
  unsigned __int8 *v164; // x9
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  __int64 v173; // x27
  __int64 v174; // x21
  __int64 v175; // x21
  __int64 v176; // x21
  __int64 v177; // x22
  __int64 v178; // x21
  __int64 v179; // x21
  __int64 v180; // x21
  int v181; // [xsp+Ch] [xbp-1D4h]
  unsigned int v182; // [xsp+14h] [xbp-1CCh]
  unsigned __int8 *v183; // [xsp+20h] [xbp-1C0h]
  unsigned int v184; // [xsp+28h] [xbp-1B8h]
  unsigned __int8 *v185; // [xsp+30h] [xbp-1B0h]
  size_t v186; // [xsp+38h] [xbp-1A8h]
  unsigned int v187; // [xsp+38h] [xbp-1A8h]
  unsigned __int8 *v188; // [xsp+48h] [xbp-198h]
  unsigned int v189; // [xsp+48h] [xbp-198h]
  unsigned __int8 *v190; // [xsp+50h] [xbp-190h]
  unsigned __int8 *v191; // [xsp+58h] [xbp-188h]
  unsigned int v192; // [xsp+58h] [xbp-188h]
  size_t v193; // [xsp+60h] [xbp-180h]
  unsigned __int8 *v194; // [xsp+68h] [xbp-178h]
  unsigned int v195; // [xsp+74h] [xbp-16Ch]
  unsigned __int8 *v196; // [xsp+78h] [xbp-168h]
  unsigned int v197; // [xsp+84h] [xbp-15Ch]
  unsigned int v198; // [xsp+9Ch] [xbp-144h]
  unsigned __int64 v199; // [xsp+A0h] [xbp-140h]
  int v200; // [xsp+ACh] [xbp-134h]
  __int64 v201; // [xsp+B0h] [xbp-130h]
  unsigned __int8 *v202; // [xsp+B8h] [xbp-128h]
  unsigned __int64 v203; // [xsp+C0h] [xbp-120h]
  size_t n; // [xsp+D8h] [xbp-108h]
  unsigned int na; // [xsp+D8h] [xbp-108h]
  __int64 v206; // [xsp+E0h] [xbp-100h]
  int v207; // [xsp+ECh] [xbp-F4h]
  unsigned __int64 v208; // [xsp+F0h] [xbp-F0h]
  const void *v209; // [xsp+F8h] [xbp-E8h]
  char *v210; // [xsp+F8h] [xbp-E8h]
  unsigned __int8 *v211; // [xsp+100h] [xbp-E0h]
  unsigned __int64 v212; // [xsp+108h] [xbp-D8h]
  _BYTE *v213; // [xsp+110h] [xbp-D0h]
  int v214; // [xsp+11Ch] [xbp-C4h]
  char *v215; // [xsp+120h] [xbp-C0h]
  unsigned __int8 *v216; // [xsp+120h] [xbp-C0h]
  char *v217; // [xsp+128h] [xbp-B8h]
  size_t v218; // [xsp+130h] [xbp-B0h]
  unsigned __int8 *v219; // [xsp+130h] [xbp-B0h]
  unsigned int v220; // [xsp+130h] [xbp-B0h]
  _BYTE *v221; // [xsp+138h] [xbp-A8h]
  size_t v222; // [xsp+140h] [xbp-A0h]
  unsigned __int8 *v223; // [xsp+140h] [xbp-A0h]
  size_t v224; // [xsp+140h] [xbp-A0h]
  char *v225; // [xsp+148h] [xbp-98h]
  _BYTE *v226; // [xsp+150h] [xbp-90h]
  char *v227; // [xsp+160h] [xbp-80h]
  __int64 v228; // [xsp+168h] [xbp-78h]
  unsigned __int8 *v229; // [xsp+170h] [xbp-70h] BYREF
  unsigned int v230; // [xsp+178h] [xbp-68h]
  int v231; // [xsp+17Ch] [xbp-64h]
  __int64 v232; // [xsp+180h] [xbp-60h]
  __int64 v233; // [xsp+188h] [xbp-58h]
  _QWORD v234[2]; // [xsp+190h] [xbp-50h] BYREF
  __int16 v235; // [xsp+1A0h] [xbp-40h]
  _DWORD v236[2]; // [xsp+1A8h] [xbp-38h] BYREF
  _DWORD v237[2]; // [xsp+1B0h] [xbp-30h] BYREF
  __int64 v238; // [xsp+1B8h] [xbp-28h] BYREF
  __int64 v239; // [xsp+1C0h] [xbp-20h] BYREF
  __int16 v240; // [xsp+1C8h] [xbp-18h]
  __int64 v241; // [xsp+1D0h] [xbp-10h]

  v241 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = qdf_mem_malloc_atomic_fl(0x18u, (__int64)"util_scan_unpack_beacon_frame", 0x1094u);
  v19 = (__int64)v10;
  if ( !v10 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: failed to allocate scan_list",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "util_scan_unpack_beacon_frame");
    goto LABEL_34;
  }
  v20 = (unsigned __int64)(a2 + 36);
  *v10 = v10;
  v10[1] = v10;
  v10[2] = 0x1F400000000LL;
  v235 = 0;
  v234[0] = 0;
  v234[1] = 0;
  if ( a2 == (_BYTE *)-36LL )
    goto LABEL_29;
  v21 = (unsigned __int16)(a3 - 36);
  v22 = (unsigned int)(v21 - 2);
  if ( (unsigned int)v21 < 2 )
    goto LABEL_29;
  v23 = (unsigned __int16)(a3 - 36);
  v24 = a2 + 36;
  while ( 1 )
  {
    v25 = (unsigned __int8)v24[1];
    v26 = v23 >= (unsigned int)(v25 + 2);
    v23 -= v25 + 2;
    if ( !v26 )
      goto LABEL_29;
    if ( *v24 == 127 )
      break;
    v24 += v25 + 2;
    if ( v23 <= 1 )
      goto LABEL_29;
  }
  if ( !v24 || (unsigned int)(v25 - 3) > 0xC || (v24[4] & 0x40) == 0 )
    goto LABEL_29;
  v27 = (unsigned __int16)(a3 - 36);
  v28 = a2 + 36;
  while ( 1 )
  {
    v29 = (unsigned __int8)v28[1];
    v26 = v27 >= (unsigned int)(v29 + 2);
    v27 -= v29 + 2;
    if ( !v26 )
      goto LABEL_29;
    if ( *v28 == 71 )
      break;
    v28 += v29 + 2;
    if ( v27 <= 1 )
      goto LABEL_29;
  }
  if ( !v28 )
  {
LABEL_29:
    v51 = util_scan_gen_scan_entry(a1, a2, a3, a4, a5, v234, v10);
    goto LABEL_30;
  }
  if ( !v28[1] )
  {
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: MBSSID IE length is wrong %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "util_scan_parse_beacon_frame",
      0);
LABEL_33:
    ucfg_scan_purge_results(v19, v40, v41, v42, v43, v44, v45, v46, v47);
    v19 = 0;
    goto LABEL_34;
  }
  qdf_mem_copy((char *)v234 + 2, a2 + 16, 6u);
  BYTE1(v234[0]) = 1 << v28[2];
  util_scan_gen_scan_entry(a1, a2, a3, a4, a5, v234, v19);
  v30 = *(_QWORD *)(a1 + 80);
  v240 = 0;
  v238 = 0;
  v239 = 0;
  memset(v237, 0, 6);
  memset(v236, 0, 6);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v30, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    v51 = 4;
    goto LABEL_30;
  }
  v228 = comp_private_obj;
  qdf_mem_copy(v236, a2 + 16, 6u);
  v48 = (unsigned __int16)(a3 - 36);
  v49 = a2 + 36;
  while ( 1 )
  {
    v50 = (unsigned __int8)v49[1] + 2LL;
    v26 = v48 >= (unsigned int)v50;
    v48 -= v50;
    if ( !v26 )
      goto LABEL_296;
    if ( *v49 == 71 )
      break;
    v49 += v50;
    if ( v48 <= 1 )
      goto LABEL_296;
  }
  if ( !v49 )
  {
LABEL_296:
    v51 = 16;
    goto LABEL_30;
  }
  v54 = _qdf_mem_malloc((unsigned __int16)(a3 - 36), "util_scan_parse_mbssid", 3608);
  if ( !v54 )
    goto LABEL_325;
  v55 = v20 + v21;
  if ( v20 >= v20 + v21 + 2 )
    goto LABEL_310;
  v56 = 0;
  v57 = nullptr;
  v58 = v54 + 2;
  v59 = v54 + v21;
  v60 = a3 - v21;
  v61 = a2 + 36;
  v227 = nullptr;
LABEL_41:
  if ( !v61 )
    goto LABEL_308;
  v62 = v21 + v20 - (_DWORD)v61;
  if ( v62 < 2 )
    goto LABEL_308;
  v63 = v61;
  while ( 1 )
  {
    v64 = (unsigned __int8)v63[1];
    v26 = v62 >= (unsigned int)(v64 + 2);
    v62 -= v64 + 2;
    if ( !v26 )
      goto LABEL_308;
    if ( *v63 == 71 )
      break;
    v63 += v64 + 2;
    if ( v62 <= 1 )
      goto LABEL_308;
  }
  v214 = v56;
  v207 = v60;
  v208 = v59;
  v206 = v58;
  v211 = (unsigned __int8 *)v54;
  v212 = v55;
  v217 = v57;
  v221 = v63;
  if ( !v63 )
    goto LABEL_307;
  if ( !v63[1] )
  {
    v176 = jiffies;
    if ( util_scan_parse_mbssid___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: MBSSID IE is of length zero",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "util_scan_parse_mbssid");
      util_scan_parse_mbssid___last_ticks = v176;
    }
LABEL_307:
    v54 = (__int64)v211;
    goto LABEL_308;
  }
  BYTE1(v238) = 1 << v63[2];
  v65 = (unsigned __int8)v63[1];
  if ( (v239 & 0x1000000000000LL) == 0 && (unsigned int)v65 < 4 )
    goto LABEL_307;
  v213 = &v63[v65];
  v226 = &v63[v65 + 2];
  if ( (unsigned __int64)&v63[v65 + 8] <= v55 )
  {
    if ( *v226 == 71 )
    {
      if ( (unsigned __int8)v213[3] >= 4u && v213[7] != 83 )
      {
LABEL_60:
        LOBYTE(v66) = 1;
        goto LABEL_55;
      }
    }
    else
    {
      LOBYTE(v66) = 0;
      if ( !v226 )
        goto LABEL_55;
      v68 = v21 + v20 - (_DWORD)v226;
      if ( v68 < 2 )
        goto LABEL_55;
      v66 = v226;
      do
      {
        v69 = (unsigned __int8)v66[1];
        v26 = v68 >= (unsigned int)(v69 + 2);
        v68 -= v69 + 2;
        if ( !v26 )
          break;
        if ( *v66 == 71 )
        {
          if ( !v66 )
            goto LABEL_55;
          if ( (unsigned int)v69 < 4 || v66[5] == 83 )
            break;
          goto LABEL_60;
        }
        v66 += v69 + 2;
      }
      while ( v68 > 1 );
    }
  }
  LOBYTE(v66) = 0;
LABEL_55:
  BYTE6(v239) = (_BYTE)v66;
  if ( v63 + 3 >= v213 + 1 )
    goto LABEL_292;
  v61 = v226;
  v67 = v63 + 3;
  while ( 1 )
  {
    v70 = (unsigned __int8)v67[1];
    v71 = HIBYTE(v239);
    LOBYTE(v240) = HIBYTE(v239);
    if ( (unsigned int)v70 >= 0xFD )
    {
      v174 = jiffies;
      if ( util_scan_parse_mbssid___last_ticks_77 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: Corrupt frame with subie_len: %d split_prof_continue: %d,prof_residue: %d",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "util_scan_parse_mbssid",
          v70,
          HIBYTE(v239),
          HIBYTE(v239));
        util_scan_parse_mbssid___last_ticks_77 = v174;
        if ( (v240 & 1) == 0 )
        {
LABEL_304:
          _qdf_mem_free((__int64)v211);
          v51 = 4;
          goto LABEL_30;
        }
      }
      else if ( !HIBYTE(v239) )
      {
        goto LABEL_304;
      }
LABEL_303:
      _qdf_mem_free((__int64)v217);
      goto LABEL_304;
    }
    if ( v61 - v67 < (__int64)(v70 + 2) )
      goto LABEL_293;
    v72 = (unsigned __int8)v67[1];
    v218 = v70 + 2;
    if ( HIBYTE(v239) )
    {
      if ( *v67 || v72 < 3 )
      {
        v175 = jiffies;
        if ( util_scan_parse_mbssid___last_ticks_79 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: Corrupt frame with ID_POS: %d,TAG_LEN_POS: %d",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "util_scan_parse_mbssid");
          util_scan_parse_mbssid___last_ticks_79 = v175;
        }
        goto LABEL_303;
      }
    }
    else if ( *v67 || v72 < 4 )
    {
      goto LABEL_75;
    }
    v73 = HIBYTE(v239);
    if ( BYTE6(v239) == 1 )
    {
      v73 = HIBYTE(v239);
      if ( v67[v70 + 4] != 83 )
      {
        v73 = 1;
        HIBYTE(v239) = 1;
      }
    }
    v215 = &v67[v70];
    if ( (v71 & 1) == 0 && (v67[2] != 83 || v67[3] != 2) )
      goto LABEL_75;
    v222 = v70;
    v225 = v67;
    v209 = v67 + 2;
    if ( v67 != (char *)-2LL )
    {
      v74 = v67 + 2;
      while ( 1 )
      {
        v75 = (unsigned __int8)v74[1];
        v26 = v72 >= (int)v75 + 2;
        v72 -= v75 + 2;
        if ( !v26 )
          goto LABEL_105;
        if ( *v74 == 85 )
          break;
        v74 += v75 + 2;
        if ( (int)v72 <= 1 )
          goto LABEL_105;
      }
      if ( v74 )
        break;
    }
LABEL_105:
    if ( v73 )
    {
      HIBYTE(v240) = 0;
      if ( (v71 & 1) == 0 )
        goto LABEL_286;
LABEL_107:
      if ( v227 )
      {
        qdf_mem_copy(v227, v209, v222);
        v227 += v222;
      }
      else
      {
        v227 = nullptr;
      }
      if ( BYTE6(v239) == 1 && v215[4] != 83 )
      {
        if ( (v239 & 0x100000000000000LL) != 0 )
          goto LABEL_292;
      }
      else
      {
        HIBYTE(v239) = 0;
      }
      if ( v227 )
        v214 = (_DWORD)v227 - (_DWORD)v217 - 2;
      else
        v227 = nullptr;
LABEL_117:
      v210 = v225;
      if ( (unsigned __int8)v240 == 1 )
      {
        LODWORD(v222) = v214;
        v210 = v217;
        if ( !v217 )
        {
          v61 = v226;
          v217 = nullptr;
          goto LABEL_293;
        }
      }
      v201 = *(_QWORD *)(a1 + 80);
      if ( !v201 )
      {
        qdf_trace_msg(0x15u, 2u, "%s: NULL PSOC", v40, v41, v42, v43, v44, v45, v46, v47, "util_gen_new_ie");
        goto LABEL_173;
      }
      if ( !(_DWORD)v222 )
        goto LABEL_173;
      if ( v210 == (char *)-2LL )
        goto LABEL_173;
      v195 = (unsigned __int8)v238;
      v203 = (unsigned int)v222;
      v216 = (unsigned __int8 *)_qdf_mem_malloc((unsigned int)v222, "util_gen_new_ie", 3246);
      if ( !v216 )
        goto LABEL_173;
      qdf_mem_copy(v216, v210 + 2, (unsigned int)v222);
      if ( (int)v222 < 2 )
      {
        v200 = 0;
        v197 = 0;
        v198 = 0;
        v196 = nullptr;
        v194 = nullptr;
        v202 = v211;
        goto LABEL_135;
      }
      v84 = v216;
      v85 = v222;
      while ( 1 )
      {
        v86 = v84[1];
        v26 = v85 >= (unsigned int)(v86 + 2);
        v85 -= v86 + 2;
        if ( !v26 )
        {
LABEL_129:
          v87 = v211;
LABEL_130:
          v202 = v87;
          goto LABEL_131;
        }
        if ( !*v84 )
          break;
        v84 += v86 + 2;
        if ( v85 <= 1 )
          goto LABEL_129;
      }
      v202 = v211;
      if ( v84 )
      {
        qdf_trace_msg(0x15u, 8u, "%s:  SSID %.*s", v76, v77, v78, v79, v80, v81, v82, v83, "util_gen_new_ie");
        v161 = v84[1];
        v202 = v211;
        if ( v206 + v161 <= v208 )
        {
          qdf_mem_copy(v211, v84, (unsigned int)(v161 + 2));
          v87 = (unsigned __int8 *)(v206 + v84[1]);
          goto LABEL_130;
        }
      }
LABEL_131:
      if ( (_DWORD)v222 != 2 )
      {
        v101 = v222;
        v102 = v216;
        while ( 1 )
        {
          v103 = v102[1];
          v26 = v101 >= (unsigned int)(v103 + 2);
          v101 -= v103 + 2;
          if ( !v26 )
            goto LABEL_132;
          if ( *v102 == 255 && v102[2] == 56 )
            break;
          v102 += v103 + 2;
          if ( v101 <= 2 )
            goto LABEL_132;
        }
        if ( !v102 )
          goto LABEL_132;
        v196 = nullptr;
        v200 = 0;
        if ( (unsigned int)v103 < 4 || &v102[v103] - v216 + 2 > (unsigned __int64)(unsigned int)v222 )
        {
          v197 = 0;
          v198 = 0;
          v162 = nullptr;
        }
        else
        {
          v198 = v102[3];
          if ( v198 >= (unsigned int)v103 )
            goto LABEL_132;
          v104 = v103 - 2;
          if ( v102[3] )
          {
            if ( (int)v198 > v104 )
            {
              v200 = 0;
              v198 = 0;
              v196 = nullptr;
              *v102 = 0;
              goto LABEL_279;
            }
            v196 = v102 + 4;
            v104 -= v198;
          }
          else
          {
            v198 = 0;
            v196 = nullptr;
          }
          v200 = 1;
LABEL_279:
          v163 = (char)(v104 - 1);
          if ( v163 < 1 )
          {
            v197 = 0;
            v194 = nullptr;
            goto LABEL_135;
          }
          v164 = &v102[v198];
          v197 = v164[4];
          if ( v197 != (unsigned __int8)v163 )
          {
            v200 = 0;
            *v102 = 0;
          }
          v162 = v164 + 5;
          if ( !v197 )
            v162 = nullptr;
        }
        v194 = v162;
        goto LABEL_135;
      }
LABEL_132:
      v200 = 0;
      v197 = 0;
      v198 = 0;
      v196 = nullptr;
      v194 = nullptr;
LABEL_135:
      v88 = (unsigned __int16)(a3 - 36);
      v89 = a2 + 36;
      while ( 1 )
      {
        v90 = (unsigned __int8)v89[1];
        v26 = v88 >= (unsigned int)(v90 + 2);
        v88 -= v90 + 2;
        if ( !v26 )
        {
LABEL_140:
          v219 = a2 + 36;
          goto LABEL_143;
        }
        if ( !*v89 )
          break;
        v89 += v90 + 2;
        if ( v88 <= 1 )
          goto LABEL_140;
      }
      v219 = a2 + 36;
      if ( v89 )
        v219 = &v89[v90 + 2];
LABEL_143:
      if ( (__int64)&v219[-v20 + 2] >= v21 )
      {
        _qdf_mem_free((__int64)v216);
LABEL_173:
        if ( (unsigned __int8)v240 == 1 )
        {
          _qdf_mem_free((__int64)v217);
          v217 = nullptr;
          v227 = nullptr;
          v214 = 0;
        }
        goto LABEL_74;
      }
      n = v219[1];
      v199 = (unsigned __int64)&v219[n + 2];
      v91 = v199 - v20;
      while ( (__int64)(v199 - v20) <= v21 )
      {
        if ( v200 )
        {
          v105 = v198;
          if ( v198 )
          {
            if ( (char)v198 < 1 )
            {
              v105 = 0;
            }
            else
            {
              v106 = *v219;
              if ( *v196 == v106 )
                goto LABEL_215;
              v107 = 0;
              while ( v198 - 1LL != v107 )
              {
                v108 = v196[++v107];
                if ( v108 == v106 )
                  goto LABEL_201;
              }
              v107 = v198;
LABEL_201:
              v105 = v107 < v198;
            }
          }
          if ( !v197 || v105 )
          {
            if ( v105 )
              goto LABEL_215;
          }
          else
          {
            v109 = *v219;
            if ( v109 != 255 )
              goto LABEL_214;
            if ( (char)v197 < 1 )
            {
              v109 = 255;
              goto LABEL_220;
            }
            v110 = v219[2];
            if ( *v194 == v110 )
              goto LABEL_215;
            v111 = 0;
            while ( v197 - 1LL != v111 )
            {
              v112 = v194[++v111];
              if ( v112 == v110 )
              {
                if ( v111 >= v197 )
                  break;
                goto LABEL_215;
              }
            }
          }
        }
        v109 = *v219;
LABEL_214:
        if ( !v109 )
        {
LABEL_215:
          if ( v91 >= v22 )
            break;
          v113 = n;
          goto LABEL_217;
        }
LABEL_220:
        if ( (int)v222 > 1 )
        {
          v115 = v216;
          v116 = v222;
          do
          {
            v117 = v115[1];
            v118 = v117 + 2;
            v26 = v116 >= (unsigned int)(v117 + 2);
            v116 -= v117 + 2;
            if ( !v26 )
              break;
            if ( *v115 == v109 )
            {
              if ( !v115 )
                break;
              v119 = v216 - v115 + (unsigned int)v222;
              if ( v109 == 221 && v119 >= 7 )
              {
                v232 = 0;
                v233 = 0;
                v231 = 0;
                na = (unsigned __int8)n + 2;
                v229 = v219;
                v230 = na;
                if ( (wlan_action_oui_search(v201, &v229, 16) & 1) != 0
                  || (wlan_action_oui_search(v201, &v229, 18) & 1) != 0
                  || (wlan_action_oui_search(v201, &v229, 25) & 1) != 0 )
                {
                  qdf_mem_copy(v202, v219, na);
                  v202 += na;
                }
                goto LABEL_270;
              }
              if ( v109 == 255 && v119 >= 3 && v219[2] != v115[2] )
                goto LABEL_267;
              if ( (unsigned __int64)&v202[v117 + 2] > v208 )
                goto LABEL_270;
              qdf_mem_copy(v202, v115, v118);
              v159 = v115[1];
              *v115 = 0;
              v160 = &v202[v159];
              goto LABEL_269;
            }
            v115 += v118;
          }
          while ( v116 > 1 );
        }
        if ( v109 != 71 )
        {
          if ( v109 == 201 )
          {
            qdf_mem_copy(v202, v219, 2u);
            v128 = v219 + 6;
            if ( (unsigned __int64)(v219 + 6) <= v199 )
            {
              v181 = 0;
              v188 = v202 + 2;
              v190 = v219 + 2;
              do
              {
                v130 = v190;
                v190 = v128;
                v191 = v130;
                v185 = v188;
                while ( 1 )
                {
                  v131 = *(unsigned __int16 *)v191;
                  v189 = v131 & 3;
                  v193 = v131 >> 8;
                  qdf_trace_msg(
                    0x15u,
                    8u,
                    "%s: channel number %d, op class %d, bssid_index %d",
                    v120,
                    v121,
                    v122,
                    v123,
                    v124,
                    v125,
                    v126,
                    v127,
                    "util_handle_rnr_ie_for_mbssid",
                    v191[3],
                    v191[2],
                    v195);
                  v184 = v131;
                  v132 = (unsigned __int8)v131 >> 4;
                  qdf_trace_msg(
                    0x15u,
                    8u,
                    "%s: tbtt_count %d, tbtt_length %d, tbtt_type %d",
                    v133,
                    v134,
                    v135,
                    v136,
                    v137,
                    v138,
                    v139,
                    v140,
                    "util_handle_rnr_ie_for_mbssid",
                    v132,
                    v193,
                    v189);
                  v182 = v132 + 1;
                  v186 = (v132 + 1) * (unsigned int)v193 + 4;
                  v183 = &v191[v186];
                  if ( (unsigned __int64)&v191[v186] > v199 )
                  {
                    v129 = 0;
                    goto LABEL_261;
                  }
                  if ( v184 >= 0x1000 && !v189 )
                    break;
                  qdf_trace_msg(
                    0x15u,
                    8u,
                    "%s: no MLD params, tbtt_type %d",
                    v141,
                    v142,
                    v143,
                    v144,
                    v145,
                    v146,
                    v147,
                    v148,
                    "util_handle_rnr_ie_for_mbssid",
                    v189);
                  qdf_mem_copy(v185, v191, v186);
                  v190 = v183 + 4;
                  v191 += v186;
                  v185 += v186;
                  if ( (unsigned __int64)(v183 + 4) > v199 )
                    goto LABEL_238;
                }
                qdf_mem_copy(v185, v191, 4u);
                v187 = 0;
                v188 = v185 + 4;
                v192 = v132 + 1;
                do
                {
                  v158 = v190[13];
                  if ( v190[13] )
                  {
                    qdf_mem_copy(v188, v190, v193);
                    if ( v158 == v195 )
                    {
                      qdf_trace_msg(
                        0x15u,
                        8u,
                        "%s: change MLD ID from %d to 0",
                        v149,
                        v150,
                        v151,
                        v152,
                        v153,
                        v154,
                        v155,
                        v156,
                        "util_handle_rnr_ie_for_mbssid",
                        v188[13]);
                      v188[13] = 0;
                    }
                    v188 += v193;
                  }
                  else
                  {
                    v181 += v193;
                    ++v187;
                  }
                  v157 = v192-- == 1;
                  v190 += v193;
                }
                while ( !v157 );
                qdf_trace_msg(
                  0x15u,
                  8u,
                  "%s: skip %d neighbor info",
                  v149,
                  v150,
                  v151,
                  v152,
                  v153,
                  v154,
                  v155,
                  v156,
                  "util_handle_rnr_ie_for_mbssid",
                  v187);
                if ( v187 == v182 )
                {
                  v188 -= 4;
                  v181 += 4;
                }
                else
                {
                  *(_WORD *)v185 = ((unsigned __int8)*(_WORD *)v185 - 16 * (_BYTE)v187) & 0xF0 | *(_WORD *)v185 & 0xFF0F;
                }
                v128 = v190 + 4;
              }
              while ( (unsigned __int64)(v190 + 4) <= v199 );
            }
            else
            {
              LOBYTE(v181) = 0;
            }
LABEL_238:
            v202[1] = n - v181;
            if ( (unsigned __int8)n == (unsigned __int8)v181 )
              v129 = 0;
            else
              v129 = (unsigned __int8)(n - v181) + 2LL;
LABEL_261:
            v202 += v129;
          }
          else
          {
LABEL_267:
            if ( (unsigned __int64)&v202[n + 2] <= v208 )
            {
              qdf_mem_copy(v202, v219, (unsigned int)(unsigned __int8)n + 2);
              v160 = &v202[v219[1]];
LABEL_269:
              v202 = v160 + 2;
            }
          }
        }
LABEL_270:
        v113 = v219[1];
        if ( (__int64)&v219[v113 - v20 + 2] >= v22 )
          break;
LABEL_217:
        v114 = &v219[v113];
        v219 = v114 + 2;
        n = v114[3];
        v199 = (unsigned __int64)&v114[n + 4];
        v91 = v199 - v20;
      }
      v92 = v216[1];
      v223 = v216 + 1;
      if ( v92 + 2 <= v203 )
      {
        v93 = v216;
        LODWORD(v94) = v216[1];
        while ( 1 )
        {
          v95 = *v93;
          if ( v95 > 0x54 )
          {
            if ( v95 != 85 && (v95 != 255 || !(_DWORD)v94 || v93[2] != 56) )
            {
LABEL_155:
              if ( (unsigned __int64)&v202[v92 + 2] <= v208 )
              {
                qdf_mem_copy(v202, v93, (unsigned int)(v94 + 2));
                v94 = *v223;
                v202 += v94 + 2;
              }
            }
          }
          else if ( *v93 && v95 != 83 )
          {
            goto LABEL_155;
          }
          if ( &v93[(unsigned int)v94] - v216 + 2 < v203 - 1 )
          {
            v94 = (unsigned __int64)&v93[(unsigned int)v94];
            v92 = *(unsigned __int8 *)(v94 + 3);
            v223 = (unsigned __int8 *)(v94 + 3);
            v93 = (unsigned __int8 *)(v94 + 2);
            v96 = v94 + 2 + v92 - (unsigned __int64)v216 + 2 > v203;
            LODWORD(v94) = *(unsigned __int8 *)(v94 + 3);
            if ( !v96 )
              continue;
          }
          break;
        }
      }
      _qdf_mem_free((__int64)v216);
      if ( v202 <= v211 )
        goto LABEL_173;
      v220 = (_DWORD)v202 - (_DWORD)v211;
      if ( (_DWORD)v202 == (_DWORD)v211 )
        goto LABEL_173;
      v224 = v207 + v220;
      if ( (v224 & 0x80000000) != 0LL || v224 > a3 )
      {
        if ( (unsigned __int8)v240 == 1 )
          _qdf_mem_free((__int64)v217);
        _qdf_mem_free((__int64)v211);
        v177 = jiffies;
        if ( util_scan_parse_mbssid___last_ticks_83 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: Invalid frame:Stop MBSSIE parsing, Frame_len: %zu ielen:%u,new_ie_len:%u",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "util_scan_parse_mbssid",
            a3,
            (unsigned __int16)(a3 - 36),
            v220);
          util_scan_parse_mbssid___last_ticks_83 = v177;
        }
        v51 = 4;
        goto LABEL_30;
      }
      v97 = (void *)_qdf_mem_malloc(v224, "util_scan_parse_mbssid", 3839);
      if ( !v97 )
      {
        if ( (unsigned __int8)v240 == 1 )
          _qdf_mem_free((__int64)v217);
        _qdf_mem_free((__int64)v211);
        v179 = jiffies;
        if ( util_scan_parse_mbssid___last_ticks_85 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x15u,
            2u,
            "%s: Malloc for new_frame failed",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "util_scan_parse_mbssid");
          util_scan_parse_mbssid___last_ticks_85 = v179;
        }
        v180 = jiffies;
        if ( util_scan_parse_mbssid___last_ticks_87 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x15u,
            2u,
            "%s: split_prof_continue: %d",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "util_scan_parse_mbssid",
            (unsigned __int8)v240);
          v51 = 2;
          util_scan_parse_mbssid___last_ticks_87 = v180;
          goto LABEL_30;
        }
LABEL_325:
        v51 = 2;
        goto LABEL_30;
      }
      v98 = (__int64)v97;
      qdf_mem_copy(v97, a2, 0x24u);
      qdf_mem_copy((void *)(v98 + 10), v237, 6u);
      qdf_mem_copy((void *)(v98 + 16), v237, 6u);
      qdf_mem_copy((void *)(v98 + 34), v210 + 4, 2u);
      qdf_mem_copy((void *)(v98 + 36), v211, v220);
      v99 = *(_DWORD **)(v228 + 1816);
      if ( v99 )
      {
        if ( *(v99 - 1) != -668346212 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, size_t, _QWORD, _DWORD *))v99)(v98, v224, a4, v237);
      }
      if ( !(unsigned int)util_scan_gen_scan_entry(a1, v98, v224, a4, a5, &v238, v19) )
      {
        if ( (_BYTE)v240 )
        {
          _qdf_mem_free((__int64)v217);
          v217 = nullptr;
          v227 = nullptr;
          v214 = 0;
        }
        _qdf_mem_free(v98);
        goto LABEL_74;
      }
      if ( (_BYTE)v240 )
      {
        _qdf_mem_free((__int64)v217);
        qdf_mem_set(&v238, 0x12u, 0);
        v217 = nullptr;
        v227 = nullptr;
        v214 = 0;
      }
      _qdf_mem_free(v98);
      v173 = jiffies;
      if ( util_scan_parse_mbssid___last_ticks_89 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: failed to generate a scan entry split_prof_continue: %d",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "util_scan_parse_mbssid",
          (unsigned __int8)v240);
        v61 = v226;
        util_scan_parse_mbssid___last_ticks_89 = v173;
      }
      else
      {
LABEL_292:
        v61 = v226;
      }
LABEL_293:
      v55 = v212;
      v54 = (__int64)v211;
      v57 = v217;
      v58 = v206;
      v59 = v208;
      v60 = v207;
      v56 = v214;
      if ( (unsigned __int64)v213 >= v212 )
      {
LABEL_308:
        _qdf_mem_free(v54);
        if ( v57 )
        {
          v54 = (__int64)v57;
LABEL_310:
          _qdf_mem_free(v54);
        }
        v51 = 0;
        goto LABEL_30;
      }
      goto LABEL_41;
    }
LABEL_74:
    v67 = v225;
    v61 = v226;
LABEL_75:
    v67 += (unsigned __int8)v67[1] + 2;
    if ( v67 >= v213 + 1 )
      goto LABEL_293;
  }
  if ( !v74[1] || !v74[2] )
    goto LABEL_74;
  if ( (v240 & 0x100) != 0 )
  {
    HIBYTE(v240) = 0;
    if ( v73 )
    {
      if ( (v71 & 1) == 0 )
        goto LABEL_286;
      goto LABEL_107;
    }
    goto LABEL_117;
  }
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: trans_bssid %02x:%02x:%02x:**:**:%02x",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "util_handle_nontx_prof",
    LOBYTE(v236[0]),
    BYTE1(v236[0]),
    BYTE2(v236[0]),
    BYTE1(v236[1]));
  qdf_mem_copy((char *)&v238 + 2, v236, 6u);
  LOBYTE(v238) = v74[2];
  v100 = v221[2];
  LOBYTE(v237[0]) = v236[0];
  *(_DWORD *)((char *)v237 + 1) = *(_DWORD *)((char *)v236 + 1);
  BYTE1(v237[1]) = BYTE1(v236[1]) & -(char)(1 << v100)
                 | (((unsigned __int8)v238 + (unsigned __int8)(BYTE1(v236[1]) & ((1 << v100) - 1))) % (1 << v100));
  qdf_mem_copy(&v239, v237, 6u);
  HIBYTE(v240) = 0;
  if ( (v239 & 0x100000000000000LL) == 0 )
    goto LABEL_117;
  if ( (v240 & 1) != 0 )
    goto LABEL_107;
LABEL_286:
  v217 = (char *)_qdf_mem_malloc((unsigned __int16)(a3 - 36), "util_scan_parse_mbssid", 3729);
  if ( v217 )
  {
    qdf_mem_copy(v217, v225, v218);
    v61 = v226;
    v227 = &v217[v222 + 2];
    goto LABEL_293;
  }
  v178 = jiffies;
  if ( util_scan_parse_mbssid___last_ticks_81 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Malloc failed",
      v165,
      v166,
      v167,
      v168,
      v169,
      v170,
      v171,
      v172,
      "util_scan_parse_mbssid");
    util_scan_parse_mbssid___last_ticks_81 = v178;
  }
  _qdf_mem_free((__int64)v211);
  v51 = 2;
LABEL_30:
  if ( v51 )
  {
    v52 = jiffies;
    if ( util_scan_parse_beacon_frame___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: Failed to create scan entry",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "util_scan_parse_beacon_frame");
      util_scan_parse_beacon_frame___last_ticks = v52;
    }
    goto LABEL_33;
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v19;
}
