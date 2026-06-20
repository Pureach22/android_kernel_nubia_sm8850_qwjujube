__int64 __fastcall lim_gen_link_specific_probe_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        int a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x20
  unsigned int mlie; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w19
  const char *v28; // x2
  __int64 result; // x0
  const char *v30; // x2
  unsigned int v31; // w1
  unsigned int bvmlie_persta_partner_info; // w0
  __int64 v33; // x8
  unsigned __int64 v34; // x9
  int v35; // w12
  int v36; // w11
  unsigned __int64 v37; // x10
  unsigned __int8 *ie_ptr_from_eid; // x0
  unsigned __int8 *v42; // x24
  int v43; // w0
  unsigned __int64 v44; // x21
  __int64 v45; // x26
  unsigned __int8 *v46; // x8
  unsigned __int8 *v47; // x19
  unsigned int v48; // w22
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned __int8 *v58; // x26
  unsigned __int64 v59; // x22
  unsigned __int8 *v60; // x12
  int v61; // w8
  __int64 v62; // x9
  bool v63; // cf
  void *v64; // x0
  __int64 v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned __int16 *v82; // x23
  unsigned __int64 v83; // x19
  unsigned __int64 v84; // x27
  int v85; // w8
  unsigned __int64 v86; // x24
  const void *v87; // x0
  int v88; // w28
  int v89; // w22
  __int64 v90; // x2
  __int64 v91; // x3
  int v92; // w9
  unsigned int v93; // w20
  double v94; // d0
  char v95; // w0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  unsigned __int16 *v103; // x23
  bool v104; // w8
  bool v105; // w27
  char v106; // w20
  __int64 v107; // x8
  char v108; // w9
  char v109; // w9
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  unsigned __int8 v126; // w2
  int v127; // w0
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  __int16 v136; // w22
  unsigned int v137; // w0
  __int64 v138; // x9
  _BYTE *v139; // x22
  __int64 v140; // x5
  __int64 v141; // x6
  __int64 v142; // x7
  int v143; // w8
  __int64 v144; // x9
  bool v145; // zf
  bool v146; // zf
  __int64 v151; // x20
  __int64 v152; // [xsp+0h] [xbp-210h]
  unsigned __int64 v153; // [xsp+8h] [xbp-208h]
  unsigned __int8 *v154; // [xsp+10h] [xbp-200h]
  __int64 v155; // [xsp+18h] [xbp-1F8h]
  const void *v156; // [xsp+20h] [xbp-1F0h]
  unsigned __int8 *v157; // [xsp+28h] [xbp-1E8h]
  __int64 v158; // [xsp+30h] [xbp-1E0h]
  unsigned __int8 *v159; // [xsp+38h] [xbp-1D8h]
  __int64 v160; // [xsp+40h] [xbp-1D0h]
  unsigned __int64 v161; // [xsp+50h] [xbp-1C0h]
  unsigned __int8 v166[4]; // [xsp+70h] [xbp-1A0h] BYREF
  _BYTE v167[4]; // [xsp+74h] [xbp-19Ch] BYREF
  __int64 v168; // [xsp+78h] [xbp-198h] BYREF
  int v169[2]; // [xsp+80h] [xbp-190h]
  __int64 v170; // [xsp+88h] [xbp-188h] BYREF
  __int64 v171; // [xsp+90h] [xbp-180h] BYREF
  unsigned int v172; // [xsp+98h] [xbp-178h] BYREF
  unsigned __int16 v173; // [xsp+9Ch] [xbp-174h]
  _DWORD dest[44]; // [xsp+A0h] [xbp-170h] BYREF
  __int64 v175; // [xsp+150h] [xbp-C0h] BYREF
  __int64 v176; // [xsp+158h] [xbp-B8h]
  __int64 v177; // [xsp+160h] [xbp-B0h]
  __int64 v178; // [xsp+168h] [xbp-A8h]
  __int64 v179; // [xsp+170h] [xbp-A0h]
  __int64 v180; // [xsp+178h] [xbp-98h]
  __int64 v181; // [xsp+180h] [xbp-90h]
  __int64 v182; // [xsp+188h] [xbp-88h]
  __int64 v183; // [xsp+190h] [xbp-80h]
  __int64 v184; // [xsp+198h] [xbp-78h]
  __int64 v185; // [xsp+1A0h] [xbp-70h]
  __int64 v186; // [xsp+1A8h] [xbp-68h]
  __int64 v187; // [xsp+1B0h] [xbp-60h]
  __int64 v188; // [xsp+1B8h] [xbp-58h]
  __int64 v189; // [xsp+1C0h] [xbp-50h]
  __int64 v190; // [xsp+1C8h] [xbp-48h]
  __int64 v191; // [xsp+1D0h] [xbp-40h]
  __int64 v192; // [xsp+1D8h] [xbp-38h]
  __int64 v193; // [xsp+1E0h] [xbp-30h]
  __int64 v194; // [xsp+1E8h] [xbp-28h]
  __int64 v195; // [xsp+1F0h] [xbp-20h]
  __int64 v196; // [xsp+1F8h] [xbp-18h]
  __int64 v197; // [xsp+200h] [xbp-10h]

  v197 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v168 = 0;
  *(_QWORD *)v169 = 0;
  if ( !a2 )
  {
    result = 29;
    goto LABEL_13;
  }
  v14 = *(_QWORD *)(a2 + 112);
  if ( !v14 )
    goto LABEL_12;
  v173 = 0;
  v15 = v14 + 4096;
  v172 = 0;
  v167[0] = 0;
  v166[0] = 0;
  if ( !*(_BYTE *)(v15 + 272) )
  {
    v30 = "%s: No partner link info since supports 1 link only";
    v31 = 8;
LABEL_11:
    qdf_trace_msg(0x35u, v31, v30, a7, a8, a9, a10, a11, a12, a13, a14, "lim_gen_link_specific_probe_rsp");
    goto LABEL_12;
  }
  if ( *(_BYTE *)(v15 + 449) != 1 )
  {
LABEL_12:
    result = 16;
    goto LABEL_13;
  }
  if ( *(_BYTE *)(a3 + 3437) != 1 )
  {
    ((void (__fastcall *)(__int64, __int64))lim_check_scan_db_for_join_req_partner_info)(a2, a1);
    result = 16;
    goto LABEL_13;
  }
  *(_BYTE *)(v15 + 449) = 0;
  v16 = *(_QWORD *)(a2 + 112);
  if ( !*(_BYTE *)(v16 + 4368) )
  {
    v30 = "%s: STA doesn't have any partner link information";
    v31 = 2;
    goto LABEL_11;
  }
  v170 = 0;
  v171 = 0;
  v195 = 0;
  v196 = 0;
  v193 = 0;
  v194 = 0;
  v191 = 0;
  v192 = 0;
  v189 = 0;
  v190 = 0;
  v187 = 0;
  v188 = 0;
  v185 = 0;
  v186 = 0;
  v183 = 0;
  v184 = 0;
  v181 = 0;
  v182 = 0;
  v179 = 0;
  v180 = 0;
  v177 = 0;
  v178 = 0;
  v175 = 0;
  v176 = 0;
  mlie = util_find_mlie(a4 + 12, a5 - 12, &v171, &v170);
  if ( mlie )
  {
    v27 = mlie;
    v28 = "%s: Mlo ie not found in Probe response";
LABEL_171:
    qdf_trace_msg(0x35u, 2u, v28, v19, v20, v21, v22, v23, v24, v25, v26, "lim_validate_probe_rsp_link_info");
    goto LABEL_172;
  }
  bvmlie_persta_partner_info = util_get_bvmlie_persta_partner_info(v171, v170, &v175, 255);
  if ( bvmlie_persta_partner_info )
  {
    v27 = bvmlie_persta_partner_info;
    v28 = "%s: Per STA profile parsing failed";
    goto LABEL_171;
  }
  memcpy(dest, (const void *)(*(_QWORD *)(a2 + 112) + 4368LL), sizeof(dest));
  LODWORD(v33) = LOBYTE(dest[0]);
  if ( LOBYTE(dest[0]) )
  {
    LODWORD(v34) = (unsigned __int8)v175;
    if ( !(_BYTE)v175 )
      goto LABEL_170;
    v35 = BYTE6(v176);
    v36 = BYTE6(v182);
    LODWORD(v37) = BYTE6(v188);
    if ( BYTE6(v176) == BYTE2(dest[3]) && dest[2] == (_DWORD)v176 && LOWORD(dest[3]) == WORD2(v176) )
      goto LABEL_39;
    if ( (unsigned __int8)v175 == 1 )
      goto LABEL_170;
    if ( BYTE6(v182) == BYTE2(dest[3]) && dest[2] == (_DWORD)v182 && LOWORD(dest[3]) == WORD2(v182) )
      goto LABEL_39;
    if ( (unsigned __int8)v175 < 3u )
      goto LABEL_170;
    if ( BYTE6(v188) == BYTE2(dest[3]) && dest[2] == (_DWORD)v188 && LOWORD(dest[3]) == WORD2(v188) )
      goto LABEL_39;
LABEL_37:
    if ( (unsigned int)v34 <= 3 )
    {
LABEL_170:
      v27 = 27;
      v28 = "%s: Atleast one Per-STA profile is missing in the ML-probe response";
      goto LABEL_171;
    }
LABEL_38:
    do
    {
      __break(0x5512u);
LABEL_39:
      if ( (_DWORD)v33 == 1 )
        break;
      if ( v35 != BYTE2(dest[15])
        || (dest[14] == (_DWORD)v176 ? (v145 = LOWORD(dest[15]) == WORD2(v176)) : (v145 = 0), !v145) )
      {
        if ( (_DWORD)v34 == 1 )
          goto LABEL_170;
        if ( v36 != BYTE2(dest[15])
          || (dest[14] == (_DWORD)v182 ? (v146 = LOWORD(dest[15]) == WORD2(v182)) : (v146 = 0), !v146) )
        {
          if ( (unsigned int)v34 < 3 )
            goto LABEL_170;
          if ( (_DWORD)v37 != BYTE2(dest[15]) )
            goto LABEL_37;
          if ( dest[14] != (_DWORD)v188 || LOWORD(dest[15]) != WORD2(v188) )
            goto LABEL_37;
        }
      }
      if ( (_DWORD)v33 == 2 )
        break;
      if ( v35 == BYTE2(dest[27]) )
      {
        v35 = dest[26];
        if ( dest[26] == (_DWORD)v176 && LOWORD(dest[27]) == WORD2(v176) )
          continue;
      }
      if ( (_DWORD)v34 == 1 )
        goto LABEL_170;
      if ( v36 == BYTE2(dest[27]) )
      {
        v36 = dest[26];
        v35 = v182;
        if ( dest[26] == (_DWORD)v182 && LOWORD(dest[27]) == WORD2(v182) )
          continue;
      }
      if ( (unsigned int)v34 < 3 )
        goto LABEL_170;
      if ( (_DWORD)v37 != BYTE2(dest[27]) )
        goto LABEL_37;
      LODWORD(v37) = dest[26];
      v36 = v188;
      v35 = LOWORD(dest[27]);
      if ( dest[26] != (_DWORD)v188 || LOWORD(dest[27]) != WORD2(v188) )
        goto LABEL_37;
    }
    while ( (_DWORD)v33 != 3 );
  }
  *(_QWORD *)v169 = _qdf_mem_malloc(0x900u, "lim_gen_link_specific_probe_rsp", 4894);
  if ( *(_QWORD *)v169 )
  {
    LODWORD(v168) = 2304;
    qdf_mem_copy(&v172, (const void *)(a2 + 30), 6u);
    ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(7u, (unsigned __int8 *)(a4 + 12), (unsigned __int16)a5 - 12);
    if ( ie_ptr_from_eid )
    {
      if ( ie_ptr_from_eid[1] )
        v42 = ie_ptr_from_eid + 2;
      else
        v42 = nullptr;
    }
    else
    {
      v42 = nullptr;
    }
    v37 = *(unsigned __int8 *)(v16 + 4368);
    LODWORD(v34) = a5;
    v43 = a4;
    if ( !*(_BYTE *)(v16 + 4368) )
    {
      v33 = a2;
      v27 = 0;
LABEL_130:
      lim_check_partner_link_for_cmn_akm(v33);
      goto LABEL_172;
    }
    v44 = 0;
    v45 = v16 + 4376;
    LODWORD(v33) = a5;
    v160 = v16 + 4376;
    while ( 1 )
    {
      if ( v44 == 3 )
        goto LABEL_38;
      v47 = (unsigned __int8 *)(v45 + 48 * v44);
      v48 = v47[6];
      v161 = v37 & 0xFFFF000000000000LL | v172 | ((unsigned __int64)v173 << 32);
      v49 = util_gen_link_probe_rsp(v43, a5, v48, v172, v169[0], 2304, (__int64)&v168);
      if ( v49 )
        break;
      v58 = (unsigned __int8 *)(*(_QWORD *)v169 + 36LL);
      v59 = *(_QWORD *)v169 + 36LL + (unsigned int)(v168 - 36);
      if ( *(_QWORD *)v169 + 36LL < v59 )
      {
        v60 = &v58[v168 + 4294967260LL];
LABEL_57:
        if ( v58 )
        {
          v61 = (_DWORD)v60 - (_DWORD)v58;
          if ( (int)v60 - (int)v58 >= 2 )
          {
            do
            {
              v62 = v58[1];
              v63 = v61 >= (unsigned int)(v62 + 2);
              v61 -= v62 + 2;
              if ( !v63 )
                break;
              if ( *v58 == 201 )
              {
                if ( !v58 )
                  break;
                if ( v58[1] )
                {
                  v157 = v60;
                  v64 = (void *)_qdf_mem_malloc(v62 + 2, "lim_gen_link_specific_rnr_ie", 4602);
                  v65 = v58[1];
                  if ( v64 )
                  {
                    v153 = v59;
                    v154 = v42;
                    v159 = v47;
                    v155 = v16;
                    v156 = v64;
                    qdf_mem_copy(v64, v58, (unsigned int)(v65 + 2));
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: Generated RNR IE received:",
                      v66,
                      v67,
                      v68,
                      v69,
                      v70,
                      v71,
                      v72,
                      v73,
                      "lim_gen_link_specific_rnr_ie");
                    ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(
                      53,
                      8,
                      v58,
                      (unsigned int)v58[1] + 2);
                    WORD2(v175) = 0;
                    LODWORD(v175) = 0;
                    qdf_mem_copy(&v175, (const void *)(a2 + 24), 6u);
                    v82 = (unsigned __int16 *)(v58 + 2);
                    v83 = (unsigned __int64)&v58[v58[1] + 2];
                    while ( (unsigned __int64)v82 < v83 )
                    {
                      v84 = *v82;
                      v85 = (unsigned __int8)v84 >> 4;
                      v86 = v84 >> 8;
                      if ( (unsigned int)v84 <= 0x6FF )
                        v87 = v82 + 2;
                      else
                        v87 = (char *)v82 + 5;
                      v88 = v85 + 1;
                      if ( (unsigned __int64)v82 + (unsigned int)((v85 + 1) * v86 + 4) > v83 )
                      {
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: error about rnr length",
                          v74,
                          v75,
                          v76,
                          v77,
                          v78,
                          v79,
                          v80,
                          v81,
                          "lim_derive_link_specific_rnr_ie");
                        break;
                      }
                      if ( !v87 )
                      {
                        while ( 1 )
                          ;
                      }
                      v89 = qdf_mem_cmp(v87, v159, 6u);
                      if ( !v89 )
                      {
                        v90 = *(unsigned int *)(a2 + 7176);
                        if ( (_DWORD)v90 == 2 )
                        {
                          v91 = 4;
                        }
                        else
                        {
                          v92 = *(_DWORD *)(a2 + 164);
                          if ( v92 == 3 )
                            v91 = 3;
                          else
                            v91 = v92 == 1;
                        }
                        v93 = *(_DWORD *)(a2 + 284);
                        v158 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 216LL);
                        v94 = lim_op_class_from_bandwidth(a1, v93, v90, v91);
                        *((_BYTE *)v82 + 2) = v95;
                        *((_BYTE *)v82 + 3) = wlan_reg_freq_to_chan(
                                                v158,
                                                v93,
                                                v94,
                                                v96,
                                                v97,
                                                v98,
                                                v99,
                                                v100,
                                                v101,
                                                v102);
                      }
                      v103 = v82 + 10;
                      v104 = (unsigned int)v84 < 0x1000;
                      if ( v89 )
                        v105 = 1;
                      else
                        v105 = (unsigned int)v84 < 0x700;
                      if ( v89 )
                        v106 = 1;
                      else
                        v106 = v104;
                      v107 = a2;
                      do
                      {
                        v108 = (unsigned __int64)v103 - 9 > v83 || v105;
                        if ( (v108 & 1) == 0 )
                        {
                          qdf_mem_copy((char *)v103 - 15, &v175, 6u);
                          v107 = a2;
                        }
                        if ( (unsigned __int64)v103 > v83 )
                          v109 = 1;
                        else
                          v109 = v106;
                        if ( (v109 & 1) == 0 )
                          *(v103 - 1) = *(v103 - 1) & 0xFFF0 | *(_BYTE *)(*(_QWORD *)(v107 + 16) + 93LL) & 0xF;
                        --v88;
                        v103 = (unsigned __int16 *)((char *)v103 + v86);
                      }
                      while ( v88 );
                      v82 = v103 - 8;
                      if ( !v89 )
                        break;
                    }
                    v16 = v155;
                    v47 = v159;
                    if ( (unsigned int)qdf_mem_cmp(v156, v58, v58[1] + 2LL) )
                    {
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Updated RNR IE: ",
                        v110,
                        v111,
                        v112,
                        v113,
                        v114,
                        v115,
                        v116,
                        v117,
                        "lim_gen_link_specific_rnr_ie");
                      ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(
                        53,
                        8,
                        v58,
                        (unsigned int)v58[1] + 2);
                    }
                    _qdf_mem_free((__int64)v156);
                    v65 = v58[1];
                    v59 = v153;
                    v42 = v154;
                    v60 = v157;
                  }
                  else
                  {
                    v60 = v157;
                  }
                  v58 += v65;
                }
                v58 += 2;
                if ( (unsigned __int64)v58 < v59 )
                  goto LABEL_57;
                goto LABEL_109;
              }
              v58 += v62 + 2;
            }
            while ( v61 > 1 );
          }
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: RNR IE not present in gen link frame",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "lim_gen_link_specific_rnr_ie");
      }
LABEL_109:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: MLO:link probe rsp size:%u orig probe rsp:%u",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "lim_gen_link_specific_probe_rsp",
        (unsigned int)v168,
        a5);
      wlan_get_chan_by_bssid_from_rnr(*(_QWORD *)(a2 + 16), *(_DWORD *)(a2 + 4), (__int64)v47, v167, v166);
      v126 = v167[0];
      if ( v167[0]
        || (wlan_get_chan_by_link_id_from_rnr(*(_QWORD *)(a2 + 16), *(_DWORD *)(a2 + 4), v47[6], v167, v166),
            (v126 = v167[0]) != 0) )
      {
        v127 = wlan_reg_chan_opclass_to_freq_prefer_global(
                 *(_QWORD *)(a1 + 21632),
                 v42,
                 v126,
                 v166[0],
                 v118,
                 v119,
                 v120,
                 v121,
                 v122,
                 v123,
                 v124,
                 v125);
        v45 = v160;
        if ( !v127 )
        {
          v151 = jiffies;
          if ( lim_gen_link_specific_probe_rsp___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Invalid op_class %d",
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              "lim_gen_link_specific_probe_rsp",
              v166[0]);
            lim_gen_link_specific_probe_rsp___last_ticks = v151;
          }
          v27 = 16;
          goto LABEL_172;
        }
        v136 = v127;
        v137 = lim_add_bcn_probe(*(_QWORD *)(a1 + 21632), *(_BYTE **)v169, v168, 1, v127, a6, 0, 0);
        if ( !v137 )
        {
          v46 = v47;
          v27 = 0;
          *((_WORD *)v46 + 5) = v136;
          v33 = a2;
          goto LABEL_50;
        }
        v27 = v137;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: failed to add bcn probe %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "lim_gen_link_specific_probe_rsp");
        goto LABEL_114;
      }
      v45 = v160;
      if ( v47 )
      {
        v140 = *v47;
        v141 = v47[1];
        v142 = v47[2];
        v143 = v47[5];
      }
      else
      {
        v142 = 0;
        v140 = 0;
        v141 = 0;
        v143 = 0;
      }
      LODWORD(v152) = v143;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid link id %d link mac: %02x:%02x:%02x:**:**:%02x",
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        "lim_gen_link_specific_probe_rsp",
        v47[6],
        v140,
        v141,
        v142,
        v152);
      v144 = *(_QWORD *)(a2 + 112);
      v33 = a2;
      if ( v144 )
      {
        v43 = a4;
        if ( v44 >= *(unsigned __int8 *)(v144 + 4368)
          || (v139 = (_BYTE *)(v144 + 48 * v44 + 4376), *(unsigned __int8 *)(v144 + 48 * v44 + 4382) == 255) )
        {
          v27 = 0;
          goto LABEL_51;
        }
        mlo_mgr_clear_ap_link_info(*(_QWORD *)(a2 + 16), v139);
        qdf_mem_set(v139, 0x30u, 0);
        v43 = a4;
        v33 = a2;
        v27 = 0;
        goto LABEL_118;
      }
      v27 = 0;
LABEL_50:
      v43 = a4;
LABEL_51:
      v34 = *(unsigned __int8 *)(v16 + 4368);
      ++v44;
      v37 = v161;
      if ( v44 >= v34 )
        goto LABEL_130;
    }
    v27 = v49;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: MLO: Link %d probe resp gen failed %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "lim_gen_link_specific_probe_rsp",
      v48);
LABEL_114:
    v138 = *(_QWORD *)(a2 + 112);
    v33 = a2;
    if ( v138 )
    {
      v43 = a4;
      if ( v44 >= *(unsigned __int8 *)(v138 + 4368) )
        goto LABEL_51;
      v139 = (_BYTE *)(v138 + 48 * v44 + 4376);
      if ( *(unsigned __int8 *)(v138 + 48 * v44 + 4382) == 255 )
        goto LABEL_51;
      mlo_mgr_clear_ap_link_info(*(_QWORD *)(a2 + 16), v139);
      qdf_mem_set(v139, 0x30u, 0);
      v43 = a4;
      v33 = a2;
LABEL_118:
      v139[6] = -1;
      goto LABEL_51;
    }
    goto LABEL_50;
  }
  v27 = 2;
LABEL_172:
  ((void (__fastcall *)(__int64, __int64))lim_check_scan_db_for_join_req_partner_info)(a2, a1);
  if ( *(_QWORD *)v169 )
    _qdf_mem_free(*(__int64 *)v169);
  result = v27;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
