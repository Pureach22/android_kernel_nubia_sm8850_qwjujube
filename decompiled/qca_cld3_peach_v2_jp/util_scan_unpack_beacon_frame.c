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
  char *v87; // x8
  int v88; // w9
  _BYTE *v89; // x8
  __int64 v90; // x10
  unsigned __int8 *v91; // x27
  __int64 v92; // x8
  __int64 i; // x9
  __int64 v94; // x9
  unsigned __int8 *v95; // x27
  unsigned __int64 v96; // x8
  unsigned int v97; // w10
  bool v98; // cc
  void *v99; // x0
  __int64 v100; // x27
  _DWORD *v101; // x8
  char v102; // w9
  int v103; // w10
  unsigned __int8 *v104; // x8
  __int64 v105; // x9
  char v106; // w9
  bool v107; // w10
  int v108; // w10
  unsigned __int64 v109; // x11
  int v110; // w12
  int v111; // w10
  int v112; // w10
  unsigned __int64 v113; // x11
  int v114; // w12
  unsigned __int8 *v115; // x9
  unsigned __int8 *v116; // x13
  int v117; // w11
  __int64 v118; // x9
  size_t v119; // x2
  unsigned __int64 v120; // x11
  char *v121; // x8
  char *v122; // x8
  __int64 v123; // x8
  __int64 v124; // x8
  unsigned __int8 *v125; // x8
  int v126; // w10
  unsigned __int8 *v127; // x9
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  __int64 v136; // x27
  __int64 v137; // x21
  __int64 v138; // x21
  __int64 v139; // x21
  __int64 v140; // x22
  __int64 v141; // x21
  __int64 v142; // x21
  __int64 v143; // x21
  unsigned int n; // [xsp+0h] [xbp-170h]
  unsigned __int8 *na; // [xsp+0h] [xbp-170h]
  unsigned __int8 *v146; // [xsp+20h] [xbp-150h]
  unsigned __int8 *v147; // [xsp+28h] [xbp-148h]
  unsigned int v148; // [xsp+34h] [xbp-13Ch]
  __int64 v149; // [xsp+48h] [xbp-128h]
  __int64 v150; // [xsp+50h] [xbp-120h]
  char *v151; // [xsp+58h] [xbp-118h]
  unsigned __int64 v152; // [xsp+60h] [xbp-110h]
  __int64 v153; // [xsp+70h] [xbp-100h]
  int v154; // [xsp+7Ch] [xbp-F4h]
  unsigned __int64 v155; // [xsp+80h] [xbp-F0h]
  const void *v156; // [xsp+88h] [xbp-E8h]
  char *v157; // [xsp+90h] [xbp-E0h]
  unsigned __int64 v158; // [xsp+98h] [xbp-D8h]
  _BYTE *v159; // [xsp+A0h] [xbp-D0h]
  int v160; // [xsp+ACh] [xbp-C4h]
  char *v161; // [xsp+B0h] [xbp-C0h]
  char *v162; // [xsp+B0h] [xbp-C0h]
  char *v163; // [xsp+B8h] [xbp-B8h]
  size_t v164; // [xsp+C0h] [xbp-B0h]
  unsigned __int8 *v165; // [xsp+C0h] [xbp-B0h]
  unsigned int v166; // [xsp+C0h] [xbp-B0h]
  _BYTE *v167; // [xsp+C8h] [xbp-A8h]
  size_t v168; // [xsp+D0h] [xbp-A0h]
  unsigned __int8 *v169; // [xsp+D0h] [xbp-A0h]
  size_t v170; // [xsp+D0h] [xbp-A0h]
  char *v171; // [xsp+D8h] [xbp-98h]
  _BYTE *v172; // [xsp+E0h] [xbp-90h]
  char *v173; // [xsp+F0h] [xbp-80h]
  __int64 v174; // [xsp+F8h] [xbp-78h]
  unsigned __int8 *v175; // [xsp+100h] [xbp-70h] BYREF
  int v176; // [xsp+108h] [xbp-68h]
  int v177; // [xsp+10Ch] [xbp-64h]
  __int64 v178; // [xsp+110h] [xbp-60h]
  __int64 v179; // [xsp+118h] [xbp-58h]
  _QWORD v180[2]; // [xsp+120h] [xbp-50h] BYREF
  __int16 v181; // [xsp+130h] [xbp-40h]
  _DWORD v182[2]; // [xsp+138h] [xbp-38h] BYREF
  _DWORD v183[2]; // [xsp+140h] [xbp-30h] BYREF
  __int64 v184; // [xsp+148h] [xbp-28h] BYREF
  __int64 v185; // [xsp+150h] [xbp-20h] BYREF
  __int16 v186; // [xsp+158h] [xbp-18h]
  __int64 v187; // [xsp+160h] [xbp-10h]

  v187 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v181 = 0;
  v180[0] = 0;
  v180[1] = 0;
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
    v51 = util_scan_gen_scan_entry(a1, a2, a3, a4, a5, v180, v10);
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
  qdf_mem_copy((char *)v180 + 2, a2 + 16, 6u);
  BYTE1(v180[0]) = 1 << v28[2];
  util_scan_gen_scan_entry(a1, a2, a3, a4, a5, v180, v19);
  v30 = *(_QWORD *)(a1 + 80);
  v186 = 0;
  v184 = 0;
  v185 = 0;
  memset(v183, 0, 6);
  memset(v182, 0, 6);
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
  v174 = comp_private_obj;
  qdf_mem_copy(v182, a2 + 16, 6u);
  v48 = (unsigned __int16)(a3 - 36);
  v49 = a2 + 36;
  while ( 1 )
  {
    v50 = (unsigned __int8)v49[1] + 2LL;
    v26 = v48 >= (unsigned int)v50;
    v48 -= v50;
    if ( !v26 )
      goto LABEL_270;
    if ( *v49 == 71 )
      break;
    v49 += v50;
    if ( v48 <= 1 )
      goto LABEL_270;
  }
  if ( !v49 )
  {
LABEL_270:
    v51 = 16;
    goto LABEL_30;
  }
  v54 = _qdf_mem_malloc((unsigned __int16)(a3 - 36), "util_scan_parse_mbssid", 3608);
  if ( !v54 )
    goto LABEL_299;
  v55 = v20 + v21;
  if ( v20 >= v20 + v21 + 2 )
    goto LABEL_284;
  v56 = 0;
  v57 = nullptr;
  v58 = v54 + 2;
  v59 = v54 + v21;
  v60 = a3 - v21;
  v61 = a2 + 36;
  v173 = nullptr;
LABEL_41:
  if ( !v61 )
    goto LABEL_282;
  v62 = v21 + v20 - (_DWORD)v61;
  if ( v62 < 2 )
    goto LABEL_282;
  v63 = v61;
  while ( 1 )
  {
    v64 = (unsigned __int8)v63[1];
    v26 = v62 >= (unsigned int)(v64 + 2);
    v62 -= v64 + 2;
    if ( !v26 )
      goto LABEL_282;
    if ( *v63 == 71 )
      break;
    v63 += v64 + 2;
    if ( v62 <= 1 )
      goto LABEL_282;
  }
  v160 = v56;
  v154 = v60;
  v155 = v59;
  v153 = v58;
  v157 = (char *)v54;
  v158 = v55;
  v163 = v57;
  v167 = v63;
  if ( !v63 )
    goto LABEL_281;
  if ( !v63[1] )
  {
    v139 = jiffies;
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
      util_scan_parse_mbssid___last_ticks = v139;
    }
LABEL_281:
    v54 = (__int64)v157;
    goto LABEL_282;
  }
  BYTE1(v184) = 1 << v63[2];
  v65 = (unsigned __int8)v63[1];
  if ( (v185 & 0x1000000000000LL) == 0 && (unsigned int)v65 < 4 )
    goto LABEL_281;
  v159 = &v63[v65];
  v172 = &v63[v65 + 2];
  if ( (unsigned __int64)&v63[v65 + 8] <= v55 )
  {
    if ( *v172 == 71 )
    {
      if ( (unsigned __int8)v159[3] >= 4u && v159[7] != 83 )
      {
LABEL_60:
        LOBYTE(v66) = 1;
        goto LABEL_55;
      }
    }
    else
    {
      LOBYTE(v66) = 0;
      if ( !v172 )
        goto LABEL_55;
      v68 = v21 + v20 - (_DWORD)v172;
      if ( v68 < 2 )
        goto LABEL_55;
      v66 = v172;
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
  BYTE6(v185) = (_BYTE)v66;
  if ( v63 + 3 >= v159 + 1 )
    goto LABEL_266;
  v61 = v172;
  v67 = v63 + 3;
  while ( 1 )
  {
    v70 = (unsigned __int8)v67[1];
    v71 = HIBYTE(v185);
    LOBYTE(v186) = HIBYTE(v185);
    if ( (unsigned int)v70 >= 0xFD )
    {
      v137 = jiffies;
      if ( util_scan_parse_mbssid___last_ticks_57 - jiffies + 125 < 0 )
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
          HIBYTE(v185),
          HIBYTE(v185));
        util_scan_parse_mbssid___last_ticks_57 = v137;
        if ( (v186 & 1) == 0 )
        {
LABEL_278:
          _qdf_mem_free((__int64)v157);
          v51 = 4;
          goto LABEL_30;
        }
      }
      else if ( !HIBYTE(v185) )
      {
        goto LABEL_278;
      }
LABEL_277:
      _qdf_mem_free((__int64)v163);
      goto LABEL_278;
    }
    if ( v61 - v67 < (__int64)(v70 + 2) )
      goto LABEL_267;
    v72 = (unsigned __int8)v67[1];
    v164 = v70 + 2;
    if ( HIBYTE(v185) )
    {
      if ( *v67 || v72 < 3 )
      {
        v138 = jiffies;
        if ( util_scan_parse_mbssid___last_ticks_59 - jiffies + 125 < 0 )
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
          util_scan_parse_mbssid___last_ticks_59 = v138;
        }
        goto LABEL_277;
      }
    }
    else if ( *v67 || v72 < 4 )
    {
      goto LABEL_75;
    }
    v73 = HIBYTE(v185);
    if ( BYTE6(v185) == 1 )
    {
      v73 = HIBYTE(v185);
      if ( v67[v70 + 4] != 83 )
      {
        v73 = 1;
        HIBYTE(v185) = 1;
      }
    }
    v161 = &v67[v70];
    if ( (v71 & 1) == 0 && (v67[2] != 83 || v67[3] != 2) )
      goto LABEL_75;
    v168 = v70;
    v171 = v67;
    v156 = v67 + 2;
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
      HIBYTE(v186) = 0;
      if ( (v71 & 1) == 0 )
        goto LABEL_260;
LABEL_107:
      if ( v173 )
      {
        qdf_mem_copy(v173, v156, v168);
        v173 += v168;
      }
      else
      {
        v173 = nullptr;
      }
      if ( BYTE6(v185) == 1 && v161[4] != 83 )
      {
        if ( (v185 & 0x100000000000000LL) != 0 )
          goto LABEL_266;
      }
      else
      {
        HIBYTE(v185) = 0;
      }
      if ( v173 )
        v160 = (_DWORD)v173 - (_DWORD)v163 - 2;
      else
        v173 = nullptr;
LABEL_117:
      v162 = v171;
      if ( (unsigned __int8)v186 == 1 )
      {
        LODWORD(v168) = v160;
        v162 = v163;
        if ( !v163 )
        {
          v61 = v172;
          v163 = nullptr;
          goto LABEL_267;
        }
      }
      v150 = *(_QWORD *)(a1 + 80);
      if ( !v150 )
      {
        qdf_trace_msg(0x15u, 2u, "%s: NULL PSOC", v40, v41, v42, v43, v44, v45, v46, v47, "util_gen_new_ie");
        goto LABEL_173;
      }
      if ( !(_DWORD)v168 )
        goto LABEL_173;
      if ( v162 == (char *)-2LL )
        goto LABEL_173;
      v152 = (unsigned int)v168;
      v165 = (unsigned __int8 *)_qdf_mem_malloc((unsigned int)v168, "util_gen_new_ie", 3246);
      if ( !v165 )
        goto LABEL_173;
      qdf_mem_copy(v165, v162 + 2, (unsigned int)v168);
      if ( (int)v168 < 2 )
      {
        v149 = 0;
        v148 = 0;
        v146 = nullptr;
        v147 = nullptr;
        v151 = v157;
        goto LABEL_135;
      }
      v84 = v165;
      v85 = v168;
      while ( 1 )
      {
        v86 = v84[1];
        v26 = v85 >= (unsigned int)(v86 + 2);
        v85 -= v86 + 2;
        if ( !v26 )
        {
LABEL_129:
          v87 = v157;
LABEL_130:
          v151 = v87;
          goto LABEL_131;
        }
        if ( !*v84 )
          break;
        v84 += v86 + 2;
        if ( v85 <= 1 )
          goto LABEL_129;
      }
      v151 = v157;
      if ( v84 )
      {
        qdf_trace_msg(0x15u, 8u, "%s:  SSID %.*s", v76, v77, v78, v79, v80, v81, v82, v83, "util_gen_new_ie");
        v124 = v84[1];
        v151 = v157;
        if ( v153 + v124 <= v155 )
        {
          qdf_mem_copy(v157, v84, (unsigned int)(v124 + 2));
          v87 = (char *)(v153 + v84[1]);
          goto LABEL_130;
        }
      }
LABEL_131:
      if ( (_DWORD)v168 != 2 )
      {
        v103 = v168;
        v104 = v165;
        while ( 1 )
        {
          v105 = v104[1];
          v26 = v103 >= (unsigned int)(v105 + 2);
          v103 -= v105 + 2;
          if ( !v26 )
            goto LABEL_132;
          if ( *v104 == 255 && v104[2] == 56 )
            break;
          v104 += v105 + 2;
          if ( v103 <= 2 )
            goto LABEL_132;
        }
        if ( !v104 )
          goto LABEL_132;
        v147 = nullptr;
        HIDWORD(v149) = 0;
        if ( (unsigned int)v105 < 4 || &v104[v105] - v165 + 2 > (unsigned __int64)(unsigned int)v168 )
        {
          v148 = 0;
          LODWORD(v149) = 0;
          v125 = nullptr;
        }
        else
        {
          LODWORD(v149) = v104[3];
          if ( (unsigned int)v149 >= (unsigned int)v105 )
            goto LABEL_132;
          v106 = v105 - 2;
          if ( v104[3] )
          {
            if ( (int)v149 > v106 )
            {
              v149 = 0;
              v147 = nullptr;
              *v104 = 0;
              goto LABEL_253;
            }
            v147 = v104 + 4;
            v106 -= v149;
          }
          else
          {
            LODWORD(v149) = 0;
            v147 = nullptr;
          }
          HIDWORD(v149) = 1;
LABEL_253:
          v126 = (char)(v106 - 1);
          if ( v126 < 1 )
          {
            v148 = 0;
            v146 = nullptr;
            goto LABEL_135;
          }
          v127 = &v104[(unsigned int)v149];
          v148 = v127[4];
          if ( v148 != (unsigned __int8)v126 )
          {
            HIDWORD(v149) = 0;
            *v104 = 0;
          }
          v125 = v127 + 5;
          if ( !v148 )
            v125 = nullptr;
        }
        v146 = v125;
        goto LABEL_135;
      }
LABEL_132:
      v149 = 0;
      v148 = 0;
      v146 = nullptr;
      v147 = nullptr;
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
          v91 = a2 + 36;
          goto LABEL_143;
        }
        if ( !*v89 )
          break;
        v89 += v90 + 2;
        if ( v88 <= 1 )
          goto LABEL_140;
      }
      v91 = a2 + 36;
      if ( v89 )
        v91 = &v89[v90 + 2];
LABEL_143:
      if ( (__int64)&v91[-v20 + 2] >= v21 )
      {
        _qdf_mem_free((__int64)v165);
LABEL_173:
        if ( (unsigned __int8)v186 == 1 )
        {
          _qdf_mem_free((__int64)v163);
          v163 = nullptr;
          v173 = nullptr;
          v160 = 0;
        }
        goto LABEL_74;
      }
      v92 = v91[1];
      for ( i = (__int64)&v91[v92 - v20 + 2]; i <= v21; i = (__int64)&v115[v92 + 2 - v20 + 2] )
      {
        if ( HIDWORD(v149) )
        {
          v107 = v149;
          if ( (_DWORD)v149 )
          {
            if ( (char)v149 < 1 )
            {
              v107 = 0;
            }
            else
            {
              v108 = *v91;
              if ( *v147 == v108 )
                goto LABEL_215;
              v109 = 0;
              while ( (unsigned int)v149 - 1LL != v109 )
              {
                v110 = v147[++v109];
                if ( v110 == v108 )
                  goto LABEL_201;
              }
              v109 = (unsigned int)v149;
LABEL_201:
              v107 = v109 < (unsigned int)v149;
            }
          }
          if ( !v148 || v107 )
          {
            if ( v107 )
              goto LABEL_215;
          }
          else
          {
            v111 = *v91;
            if ( v111 != 255 )
              goto LABEL_214;
            if ( (char)v148 < 1 )
            {
              v111 = 255;
              goto LABEL_219;
            }
            v112 = v91[2];
            if ( *v146 == v112 )
              goto LABEL_215;
            v113 = 0;
            while ( v148 - 1LL != v113 )
            {
              v114 = v146[++v113];
              if ( v114 == v112 )
              {
                if ( v113 >= v148 )
                  break;
                goto LABEL_215;
              }
            }
          }
        }
        v111 = *v91;
LABEL_214:
        if ( !v111 )
        {
LABEL_215:
          if ( i >= v22 )
            break;
          goto LABEL_216;
        }
LABEL_219:
        if ( (int)v168 > 1 )
        {
          v116 = v165;
          v117 = v168;
          do
          {
            v118 = v116[1];
            v119 = v118 + 2;
            v26 = v117 >= (unsigned int)(v118 + 2);
            v117 -= v118 + 2;
            if ( !v26 )
              break;
            if ( *v116 == v111 )
            {
              if ( !v116 )
                break;
              v120 = v165 - v116 + (unsigned int)v168;
              if ( v111 == 221 && v120 >= 7 )
              {
                v178 = 0;
                v179 = 0;
                v177 = 0;
                v175 = v91;
                n = v92 + 2;
                v176 = v92 + 2;
                if ( (wlan_action_oui_search(v150, &v175, 16) & 1) != 0
                  || (wlan_action_oui_search(v150, &v175, 18) & 1) != 0
                  || (wlan_action_oui_search(v150, &v175, 25) & 1) != 0 )
                {
                  qdf_mem_copy(v151, v91, n);
                  v121 = &v151[n];
                  goto LABEL_238;
                }
                goto LABEL_239;
              }
              if ( v111 == 255 && v120 >= 3 && v91[2] != v116[2] )
                goto LABEL_235;
              if ( (unsigned __int64)&v151[v118 + 2] > v155 )
                goto LABEL_239;
              na = v116;
              qdf_mem_copy(v151, v116, v119);
              v123 = na[1];
              *na = 0;
              v122 = &v151[v123];
              goto LABEL_237;
            }
            v116 += v119;
          }
          while ( v117 > 1 );
        }
        if ( v111 != 71 && v111 != 201 )
        {
LABEL_235:
          if ( (unsigned __int64)&v151[v92 + 2] <= v155 )
          {
            qdf_mem_copy(v151, v91, (unsigned int)(v92 + 2));
            v122 = &v151[v91[1]];
LABEL_237:
            v121 = v122 + 2;
LABEL_238:
            v151 = v121;
          }
        }
LABEL_239:
        v92 = v91[1];
        if ( (__int64)&v91[v92 - v20 + 2] >= v22 )
          break;
LABEL_216:
        v115 = &v91[v92];
        v92 = v91[v92 + 3];
        v91 = v115 + 2;
      }
      v94 = v165[1];
      v169 = v165 + 1;
      if ( v94 + 2 <= v152 )
      {
        v95 = v165;
        LODWORD(v96) = v165[1];
        while ( 1 )
        {
          v97 = *v95;
          if ( v97 > 0x54 )
          {
            if ( v97 != 85 && (v97 != 255 || !(_DWORD)v96 || v95[2] != 56) )
            {
LABEL_155:
              if ( (unsigned __int64)&v151[v94 + 2] <= v155 )
              {
                qdf_mem_copy(v151, v95, (unsigned int)(v96 + 2));
                v96 = *v169;
                v151 += v96 + 2;
              }
            }
          }
          else if ( *v95 && v97 != 83 )
          {
            goto LABEL_155;
          }
          if ( &v95[(unsigned int)v96] - v165 + 2 < v152 - 1 )
          {
            v96 = (unsigned __int64)&v95[(unsigned int)v96];
            v94 = *(unsigned __int8 *)(v96 + 3);
            v169 = (unsigned __int8 *)(v96 + 3);
            v95 = (unsigned __int8 *)(v96 + 2);
            v98 = v96 + 2 + v94 - (unsigned __int64)v165 + 2 > v152;
            LODWORD(v96) = *(unsigned __int8 *)(v96 + 3);
            if ( !v98 )
              continue;
          }
          break;
        }
      }
      _qdf_mem_free((__int64)v165);
      if ( v151 <= v157 )
        goto LABEL_173;
      v166 = (_DWORD)v151 - (_DWORD)v157;
      if ( (_DWORD)v151 == (_DWORD)v157 )
        goto LABEL_173;
      v170 = v154 + v166;
      if ( (v170 & 0x80000000) != 0LL || v170 > a3 )
      {
        if ( (unsigned __int8)v186 == 1 )
          _qdf_mem_free((__int64)v163);
        _qdf_mem_free((__int64)v157);
        v140 = jiffies;
        if ( util_scan_parse_mbssid___last_ticks_63 - jiffies + 125 < 0 )
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
            v166);
          util_scan_parse_mbssid___last_ticks_63 = v140;
        }
        v51 = 4;
        goto LABEL_30;
      }
      v99 = (void *)_qdf_mem_malloc(v170, "util_scan_parse_mbssid", 3839);
      if ( !v99 )
      {
        if ( (unsigned __int8)v186 == 1 )
          _qdf_mem_free((__int64)v163);
        _qdf_mem_free((__int64)v157);
        v142 = jiffies;
        if ( util_scan_parse_mbssid___last_ticks_65 - jiffies + 125 < 0 )
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
          util_scan_parse_mbssid___last_ticks_65 = v142;
        }
        v143 = jiffies;
        if ( util_scan_parse_mbssid___last_ticks_67 - jiffies + 125 < 0 )
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
            (unsigned __int8)v186);
          v51 = 2;
          util_scan_parse_mbssid___last_ticks_67 = v143;
          goto LABEL_30;
        }
LABEL_299:
        v51 = 2;
        goto LABEL_30;
      }
      v100 = (__int64)v99;
      qdf_mem_copy(v99, a2, 0x24u);
      qdf_mem_copy((void *)(v100 + 10), v183, 6u);
      qdf_mem_copy((void *)(v100 + 16), v183, 6u);
      qdf_mem_copy((void *)(v100 + 34), v162 + 4, 2u);
      qdf_mem_copy((void *)(v100 + 36), v157, v166);
      v101 = *(_DWORD **)(v174 + 1816);
      if ( v101 )
      {
        if ( *(v101 - 1) != -668346212 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, size_t, _QWORD, _DWORD *))v101)(v100, v170, a4, v183);
      }
      if ( !(unsigned int)util_scan_gen_scan_entry(a1, v100, v170, a4, a5, &v184, v19) )
      {
        if ( (_BYTE)v186 )
        {
          _qdf_mem_free((__int64)v163);
          v163 = nullptr;
          v173 = nullptr;
          v160 = 0;
        }
        _qdf_mem_free(v100);
        goto LABEL_74;
      }
      if ( (_BYTE)v186 )
      {
        _qdf_mem_free((__int64)v163);
        qdf_mem_set(&v184, 0x12u, 0);
        v163 = nullptr;
        v173 = nullptr;
        v160 = 0;
      }
      _qdf_mem_free(v100);
      v136 = jiffies;
      if ( util_scan_parse_mbssid___last_ticks_69 - jiffies + 125 < 0 )
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
          (unsigned __int8)v186);
        v61 = v172;
        util_scan_parse_mbssid___last_ticks_69 = v136;
      }
      else
      {
LABEL_266:
        v61 = v172;
      }
LABEL_267:
      v55 = v158;
      v54 = (__int64)v157;
      v57 = v163;
      v58 = v153;
      v59 = v155;
      v60 = v154;
      v56 = v160;
      if ( (unsigned __int64)v159 >= v158 )
      {
LABEL_282:
        _qdf_mem_free(v54);
        if ( v57 )
        {
          v54 = (__int64)v57;
LABEL_284:
          _qdf_mem_free(v54);
        }
        v51 = 0;
        goto LABEL_30;
      }
      goto LABEL_41;
    }
LABEL_74:
    v67 = v171;
    v61 = v172;
LABEL_75:
    v67 += (unsigned __int8)v67[1] + 2;
    if ( v67 >= v159 + 1 )
      goto LABEL_267;
  }
  if ( !v74[1] || !v74[2] )
    goto LABEL_74;
  if ( (v186 & 0x100) != 0 )
  {
    HIBYTE(v186) = 0;
    if ( v73 )
    {
      if ( (v71 & 1) == 0 )
        goto LABEL_260;
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
    LOBYTE(v182[0]),
    BYTE1(v182[0]),
    BYTE2(v182[0]),
    BYTE1(v182[1]));
  qdf_mem_copy((char *)&v184 + 2, v182, 6u);
  LOBYTE(v184) = v74[2];
  v102 = v167[2];
  LOBYTE(v183[0]) = v182[0];
  *(_DWORD *)((char *)v183 + 1) = *(_DWORD *)((char *)v182 + 1);
  BYTE1(v183[1]) = BYTE1(v182[1]) & -(char)(1 << v102)
                 | (((unsigned __int8)v184 + (unsigned __int8)(BYTE1(v182[1]) & ((1 << v102) - 1))) % (1 << v102));
  qdf_mem_copy(&v185, v183, 6u);
  HIBYTE(v186) = 0;
  if ( (v185 & 0x100000000000000LL) == 0 )
    goto LABEL_117;
  if ( (v186 & 1) != 0 )
    goto LABEL_107;
LABEL_260:
  v163 = (char *)_qdf_mem_malloc((unsigned __int16)(a3 - 36), "util_scan_parse_mbssid", 3729);
  if ( v163 )
  {
    qdf_mem_copy(v163, v171, v164);
    v61 = v172;
    v173 = &v163[v168 + 2];
    goto LABEL_267;
  }
  v141 = jiffies;
  if ( util_scan_parse_mbssid___last_ticks_61 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Malloc failed",
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      "util_scan_parse_mbssid");
    util_scan_parse_mbssid___last_ticks_61 = v141;
  }
  _qdf_mem_free((__int64)v157);
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
