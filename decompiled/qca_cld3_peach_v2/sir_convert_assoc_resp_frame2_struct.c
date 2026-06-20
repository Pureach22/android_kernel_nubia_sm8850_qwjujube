__int64 __fastcall sir_convert_assoc_resp_frame2_struct(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5)
{
  __int64 v9; // x0
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _BYTE *v21; // x19
  unsigned int v22; // w21
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  unsigned int v33; // w8
  unsigned int v34; // w8
  unsigned int v35; // w8
  unsigned int v36; // w8
  unsigned int v37; // w8
  unsigned int v38; // w8
  unsigned int v39; // w8
  unsigned int v40; // w8
  unsigned int v41; // w8
  unsigned int v42; // w8
  unsigned int v43; // w8
  unsigned int v44; // w8
  unsigned int v45; // w8
  __int64 result; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x25
  __int64 v56; // x4
  __int64 v57; // x5
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
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
  unsigned int v82; // w8
  char v83; // w9
  __int16 v84; // w8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  int v101; // w8
  size_t v102; // x2
  size_t v103; // x2
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned __int64 v112; // x8
  __int16 v113; // w8
  __int16 v114; // w9
  __int16 v115; // w10
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int16 v124; // w8
  __int16 v125; // w9
  __int16 v126; // w5
  __int16 v127; // w9
  int v128; // w10
  __int16 v129; // w8
  int v130; // w9
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  char *v155; // x25
  __int64 v156; // x21
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  size_t v166; // x2
  void *v167; // x0
  const char *v168; // x28
  const char *v169; // x2
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  unsigned int v178; // w11
  unsigned int v179; // w9
  unsigned int v180; // w10
  unsigned int v181; // w0
  __int64 v182; // [xsp+0h] [xbp-240h]
  __int64 v183; // [xsp+0h] [xbp-240h]
  __int64 v184; // [xsp+8h] [xbp-238h]
  __int64 v185; // [xsp+8h] [xbp-238h]
  __int64 v186; // [xsp+10h] [xbp-230h]
  __int64 v187; // [xsp+10h] [xbp-230h]
  __int64 v188; // [xsp+18h] [xbp-228h]
  __int64 v189; // [xsp+20h] [xbp-220h]
  __int64 v190; // [xsp+28h] [xbp-218h]
  __int64 v191; // [xsp+30h] [xbp-210h]
  __int64 v192; // [xsp+38h] [xbp-208h]
  __int64 v193; // [xsp+40h] [xbp-200h]
  __int64 v194; // [xsp+48h] [xbp-1F8h]
  unsigned __int8 *v195; // [xsp+B0h] [xbp-190h]
  unsigned int v196; // [xsp+BCh] [xbp-184h] BYREF
  _WORD v197[2]; // [xsp+C0h] [xbp-180h] BYREF
  __int16 v198; // [xsp+C4h] [xbp-17Ch] BYREF
  _WORD v199[2]; // [xsp+C8h] [xbp-178h] BYREF
  _BYTE v200[4]; // [xsp+CCh] [xbp-174h] BYREF
  _BYTE v201[4]; // [xsp+D0h] [xbp-170h] BYREF
  _BYTE v202[4]; // [xsp+D4h] [xbp-16Ch] BYREF
  _BYTE v203[4]; // [xsp+D8h] [xbp-168h] BYREF
  _BYTE v204[4]; // [xsp+DCh] [xbp-164h] BYREF
  int v205[2]; // [xsp+E0h] [xbp-160h] BYREF
  int v206; // [xsp+E8h] [xbp-158h] BYREF
  __int16 v207; // [xsp+ECh] [xbp-154h]
  int v208[2]; // [xsp+F0h] [xbp-150h] BYREF
  __int64 v209; // [xsp+F8h] [xbp-148h]
  __int64 v210; // [xsp+100h] [xbp-140h]
  __int64 v211; // [xsp+108h] [xbp-138h]
  __int64 v212; // [xsp+110h] [xbp-130h]
  __int64 v213; // [xsp+118h] [xbp-128h]
  int v214; // [xsp+120h] [xbp-120h]
  _QWORD s[35]; // [xsp+128h] [xbp-118h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v196 = a4;
  v9 = _qdf_mem_malloc(0x1310u, "sir_convert_assoc_resp_frame2_struct", 4565);
  if ( !v9 )
  {
    result = 16;
    goto LABEL_140;
  }
  v21 = (_BYTE *)v9;
  if ( **(_BYTE **)(a2 + 9976) == 1 && *(_WORD *)(a3 + 2) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: FILS: assoc reject Status code:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sir_convert_assoc_resp_frame2_struct");
  }
  else if ( **(_BYTE **)(a2 + 9976)
         && !*(_WORD *)(a3 + 2)
         && (unsigned int)aead_decrypt_assoc_rsp(a1, a2, v9, a3, &v196) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: FILS assoc rsp AEAD decrypt fails",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "sir_convert_assoc_resp_frame2_struct");
LABEL_16:
    _qdf_mem_free((__int64)v21);
    result = 16;
    goto LABEL_140;
  }
  v22 = v196;
  v23 = dot11f_unpack_assoc_response(a1, a3, v196, (__int64)v21, 0, v10, v11, v12);
  if ( (v23 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to parse an Association Response (0x%08x, %d bytes):",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "dot11f_parse_assoc_response",
      v23,
      v22);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a3, v22);
    goto LABEL_16;
  }
  v32 = *(_WORD *)a5 & 0xFFFE | *(_WORD *)v21 & 1;
  *(_WORD *)a5 = *(_WORD *)a5 & 0xFFFE | *(_WORD *)v21 & 1;
  v33 = v32 & 0xFFFFFFFD | (2 * ((*(unsigned __int16 *)v21 >> 1) & 1));
  *(_WORD *)a5 = v33;
  v34 = v33 & 0xFFFFFFFB | (4 * ((*(unsigned __int16 *)v21 >> 2) & 1));
  *(_WORD *)a5 = v34;
  v35 = v34 & 0xFFFFFFF7 | (8 * ((*(unsigned __int16 *)v21 >> 3) & 1));
  *(_WORD *)a5 = v35;
  v36 = v35 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)v21 >> 4) & 1));
  *(_WORD *)a5 = v36;
  v37 = v36 & 0xFFFFFFDF | (32 * ((*(unsigned __int16 *)v21 >> 5) & 1));
  *(_WORD *)a5 = v37;
  v38 = v37 & 0xFFFFFFBF | (((*(unsigned __int16 *)v21 >> 6) & 1) << 6);
  *(_WORD *)a5 = v38;
  v39 = v38 & 0xFFFFFF7F | (((*(unsigned __int16 *)v21 >> 7) & 1) << 7);
  *(_WORD *)a5 = v39;
  v40 = v39 & 0xFFFFFEFF | ((HIBYTE(*(unsigned __int16 *)v21) & 1) << 8);
  *(_WORD *)a5 = v40;
  v41 = v40 & 0xFFFFFDFF | (((*(unsigned __int16 *)v21 >> 9) & 1) << 9);
  *(_WORD *)a5 = v41;
  v42 = v41 & 0xFFFFFBFF | (((*(unsigned __int16 *)v21 >> 10) & 1) << 10);
  *(_WORD *)a5 = v42;
  v43 = v42 & 0xFFFFF7FF | (((*(unsigned __int16 *)v21 >> 11) & 1) << 11);
  *(_WORD *)a5 = v43;
  v44 = v43 & 0xFFFFEFFF | (((*(unsigned __int16 *)v21 >> 12) & 1) << 12);
  *(_WORD *)a5 = v44;
  v45 = v44 & 0xFFFFDFFF | (((*(unsigned __int16 *)v21 >> 13) & 1) << 13);
  *(_WORD *)a5 = v45;
  LOWORD(v45) = v45 & 0xBFFF | (((*(_WORD *)v21 >> 14) & 1) << 14);
  *(_WORD *)a5 = v45;
  *(_WORD *)a5 = *(_WORD *)v21 & 0x8000 | v45 & 0x7FFF;
  *(_WORD *)(a5 + 4) = *((_WORD *)v21 + 1);
  *(_WORD *)(a5 + 2) = *((_WORD *)v21 + 2);
  if ( v21[292] )
  {
    *(_BYTE *)(a5 + 2400) = 1;
    *(_BYTE *)(a5 + 2401) = v21[293];
    *(_DWORD *)(a5 + 2404) = *((_DWORD *)v21 + 74);
  }
  if ( v21[6] )
  {
    *(_BYTE *)(a5 + 2284) = 1;
    convert_supp_rates(a1, a5 + 6, v21 + 6);
  }
  else
  {
    *(_BYTE *)(a5 + 2284) = 0;
    v55 = jiffies;
    if ( sir_convert_assoc_resp_frame2_struct___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Mandatory IE Supported Rates not present!",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "sir_convert_assoc_resp_frame2_struct");
      sir_convert_assoc_resp_frame2_struct___last_ticks = v55;
    }
  }
  if ( v21[20] )
  {
    *(_BYTE *)(a5 + 2285) = 1;
    convert_ext_supp_rates(a1, a5 + 19, v21 + 20);
  }
  if ( v21[34] )
  {
    *(_BYTE *)(a5 + 2286) = 1;
    convert_edca_param(a1, a5 + 32, v21 + 34);
  }
  if ( v21[4190] )
  {
    *(_BYTE *)(a5 + 2287) = 1;
    convert_wmm_params(a1, a5 + 32, v21 + 4190);
  }
  if ( v21[300] )
    qdf_mem_copy((void *)(a5 + 244), v21 + 300, 0x3Cu);
  if ( v21[360] )
    qdf_mem_copy((void *)(a5 + 304), v21 + 360, 0x3Au);
  if ( v21[58] )
    qdf_mem_copy((void *)(a5 + 2408), v21 + 58, 6u);
  if ( v21[64] )
  {
    *(_BYTE *)(a5 + 2291) = 1;
    qdf_mem_copy((void *)(a5 + 760), v21 + 66, 2u);
    v56 = *(unsigned __int8 *)(a5 + 760);
    v57 = *(unsigned __int8 *)(a5 + 761);
    *(_BYTE *)(a5 + 762) = v21[68] & 3;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: new mdie=%02x%02x%02x",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "sir_convert_assoc_resp_frame2_struct",
      v56,
      v57);
  }
  if ( (lim_is_sha384_akm(*(_DWORD *)(a2 + 156)) & 1) != 0 )
  {
    if ( (unsigned int)wlan_parse_ftie_sha384((unsigned __int8 *)(a3 + 6), (unsigned __int16)v196 - 6, a5) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: FT IE parsing failed status:%d",
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        "sir_convert_assoc_resp_frame2_struct",
        0);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: FT: R0KH present:%d len:%d R1KH present%d",
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        "sir_convert_assoc_resp_frame2_struct",
        *(unsigned __int8 *)(a5 + 689),
        *(unsigned __int8 *)(a5 + 690),
        *(unsigned __int8 *)(a5 + 672));
      v21[70] = 0;
    }
  }
  else if ( v21[70] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: FT: R0KH present:%d, len:%d R1KH present:%d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "sir_convert_assoc_resp_frame2_struct",
      (unsigned __int8)v21[206],
      (unsigned __int8)v21[207],
      (unsigned __int8)v21[153]);
    *(_BYTE *)(a5 + 2290) = 1;
    qdf_mem_copy((void *)(a5 + 362), v21 + 70, 0xDCu);
  }
  v82 = *((unsigned __int16 *)v21 + 730);
  if ( v82 - 1 <= 1 )
  {
    if ( v21[1464] )
    {
      qdf_mem_copy((void *)(a5 + 764), v21 + 1464, 0x27Cu);
      v82 = *((unsigned __int16 *)v21 + 730);
    }
    v83 = v82;
    if ( v82 >= 2 )
    {
      if ( v21[2100] )
      {
        qdf_mem_copy((void *)(a5 + 1400), v21 + 2100, 0x27Cu);
        v82 = *((unsigned __int16 *)v21 + 730);
        v83 = *((_WORD *)v21 + 730);
      }
      if ( v82 > 2 )
        goto LABEL_141;
    }
    *(_BYTE *)(a5 + 763) = v83;
    *(_BYTE *)(a5 + 2292) = 1;
  }
  v84 = *((_WORD *)v21 + 2111);
  if ( v84 )
  {
    *(_BYTE *)(a5 + 2036) = v84;
    if ( *((_WORD *)v21 + 2111) )
    {
      qdf_mem_copy((void *)(a5 + 2040), v21 + 4224, 0x3Cu);
      if ( *((unsigned __int16 *)v21 + 2111) >= 2u )
      {
        qdf_mem_copy((void *)(a5 + 2100), v21 + 4284, 0x3Cu);
        if ( *((unsigned __int16 *)v21 + 2111) >= 3u )
        {
          qdf_mem_copy((void *)(a5 + 2160), v21 + 4344, 0x3Cu);
          if ( *((unsigned __int16 *)v21 + 2111) >= 4u )
          {
            qdf_mem_copy((void *)(a5 + 2220), v21 + 4404, 0x3Cu);
            if ( *((unsigned __int16 *)v21 + 2111) >= 5u )
            {
              qdf_mem_copy((void *)(a5 + 2280), v21 + 4464, 0x3Cu);
              if ( *((unsigned __int16 *)v21 + 2111) > 5u )
                goto LABEL_141;
            }
          }
        }
      }
    }
    *(_BYTE *)(a5 + 2293) = 1;
  }
  if ( v21[4216] )
  {
    *(_BYTE *)(a5 + 2294) = 1;
    qdf_mem_copy((void *)(a5 + 2280), v21 + 4217, 4u);
  }
  if ( v21[452] )
    qdf_mem_copy((void *)(a5 + 2742), v21 + 452, 6u);
  if ( v21[520] )
    qdf_mem_copy((void *)(a5 + 2296), v21 + 520, 0x10u);
  if ( v21[536] )
    qdf_mem_copy((void *)(a5 + 2312), v21 + 536, 6u);
  if ( v21[434] )
  {
    qdf_mem_copy((void *)(a5 + 2318), v21 + 434, 0x11u);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: timingMeas: %d, finetimingMeas Init: %d, Resp: %d",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "sir_convert_assoc_resp_frame2_struct",
      (*(_DWORD *)(a5 + 2320) >> 23) & 1,
      (*(unsigned __int16 *)(a5 + 2328) >> 7) & 1,
      (*(unsigned __int16 *)(a5 + 2328) >> 6) & 1);
  }
  if ( v21[542] )
    qdf_mem_copy((void *)(a5 + 2335), v21 + 542, 2u);
  if ( v21[458] )
  {
    *(_BYTE *)(a5 + 2337) = 1;
    ((void (__fastcall *)(__int64, __int64, _BYTE *))convert_qos_mapset_frame)(a1, a5 + 2337, v21 + 458);
    if ( *(unsigned __int8 *)(a5 + 2338) >= 0x16u )
      *(_BYTE *)(a5 + 2338) = 21;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: num of dscp exceptions: %d",
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      "lim_log_qos_map_set");
    ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, a5 + 2339, 42);
    ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, a5 + 2381, 16);
  }
  v101 = (unsigned __int8)v21[4496];
  *(_BYTE *)(a5 + 2416) = v101;
  if ( v101 )
    *(_BYTE *)(a5 + 2417) = v21[4497];
  if ( v21[418] )
    qdf_mem_copy((void *)(a5 + 2444), v21 + 418, 0x10u);
  if ( v21[4500] )
    qdf_mem_copy((void *)(a5 + 2420), v21 + 4500, 0x10u);
  if ( v21[4516] )
    qdf_mem_copy((void *)(a5 + 2436), v21 + 4516, 6u);
  if ( v21[4524] )
    qdf_mem_copy((void *)(a5 + 2464), v21 + 4524, 0x2Cu);
  if ( v21[1340] )
    qdf_mem_copy((void *)(a5 + 2508), v21 + 1340, 0x3Cu);
  if ( v21[1400] )
    qdf_mem_copy((void *)(a5 + 2568), v21 + 1400, 0x12u);
  if ( v21[1418] )
    qdf_mem_copy((void *)(a5 + 2586), v21 + 1418, 0x15u);
  if ( v21[1456] )
    qdf_mem_copy((void *)(a5 + 2608), v21 + 1456, 4u);
  if ( v21[1442] )
  {
    *(_BYTE *)(a5 + 2716) = 1;
    convert_mu_edca_param(a1, a5 + 2717, v21 + 1442);
  }
  if ( v21[4568] && v21[4844] )
    qdf_mem_copy((void *)(a5 + 2460), v21 + 4844, 3u);
  if ( v21[3264] )
    qdf_mem_copy((void *)(a5 + 2612), v21 + 3264, 0x5Cu);
  if ( v21[3356] )
    qdf_mem_copy((void *)(a5 + 2704), v21 + 3356, 0xCu);
  if ( v21[544] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: fils session IE present",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "fils_convert_assoc_rsp_frame2_struct");
    *(_BYTE *)(a5 + 2748) = 1;
    qdf_mem_copy((void *)(a5 + 2749), v21 + 545, 8u);
  }
  if ( v21[811] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: fils key conf IE present",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "fils_convert_assoc_rsp_frame2_struct");
    v102 = (unsigned __int8)v21[812];
    *(_BYTE *)(a5 + 2758) = v102;
    qdf_mem_copy((void *)(a5 + 2759), v21 + 813, v102);
  }
  if ( v21[2996] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: fils kde IE present %d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "fils_convert_assoc_rsp_frame2_struct",
      (unsigned __int8)v21[3005]);
    *(_BYTE *)(a5 + 3023) = v21[3005];
    qdf_mem_copy((void *)(a5 + 3015), v21 + 2997, 8u);
    qdf_mem_copy((void *)(a5 + 3024), v21 + 3006, *(unsigned __int8 *)(a5 + 3023));
  }
  if ( v21[1068] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: FILS HLP container IE present",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "fils_convert_assoc_rsp_frame2_struct");
    *(_BYTE *)(a5 + 3279) = v21[1069];
    *(_BYTE *)(a5 + 3280) = v21[1070];
    *(_BYTE *)(a5 + 3281) = v21[1071];
    *(_BYTE *)(a5 + 3282) = v21[1072];
    *(_BYTE *)(a5 + 3283) = v21[1073];
    *(_BYTE *)(a5 + 3284) = v21[1074];
    *(_BYTE *)(a5 + 3285) = v21[1075];
    *(_BYTE *)(a5 + 3286) = v21[1076];
    *(_BYTE *)(a5 + 3287) = v21[1077];
    *(_BYTE *)(a5 + 3288) = v21[1078];
    *(_BYTE *)(a5 + 3289) = v21[1079];
    *(_BYTE *)(a5 + 3290) = v21[1080];
    v103 = (unsigned __int8)v21[1081];
    *(_WORD *)(a5 + 3292) = v103;
    qdf_mem_copy((void *)(a5 + 3294), v21 + 1082, v103);
    if ( v21[2739] )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: FILS fragment ie present",
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        "fils_convert_assoc_rsp_frame2_struct");
      v112 = *(unsigned __int16 *)(a5 + 3292);
      if ( v112 < 0x801 )
      {
        qdf_mem_copy((void *)(a5 + 3294 + v112), v21 + 2741, (unsigned __int8)v21[2740]);
        *(_WORD *)(a5 + 3292) += (unsigned __int8)v21[2740];
        goto LABEL_108;
      }
LABEL_141:
      __break(0x5512u);
    }
  }
LABEL_108:
  v195 = v21 + 4190;
  if ( v21[3368] )
  {
    *(_QWORD *)v208 = 0;
    *(_QWORD *)v205 = 0;
    v204[0] = 0;
    v203[0] = 0;
    v202[0] = 0;
    v201[0] = 0;
    v200[0] = 0;
    v199[0] = 0;
    v198 = 0;
    v197[0] = 0;
    v206 = 0;
    v207 = 0;
    memset(s, 0, 176);
    if ( !(unsigned int)util_find_mlie(a3 + 6, v196 - 6, v208, v205) )
    {
      util_get_bvmlie_persta_partner_info(*(_QWORD *)v208, *(_QWORD *)v205, s, 1);
      if ( !*(_WORD *)(a5 + 4)
        && (*(_BYTE *)(*(_QWORD *)(a2 + 16) + 60LL) & 2) == 0
        && *(_BYTE *)(a2 + 10696)
        && !wlan_cm_is_roam_sync_in_progress(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a2 + 10)) )
      {
        mlo_mgr_validate_connection_partner_links(*(_QWORD *)(a2 + 16), s);
        sir_copy_assoc_rsp_partner_info_to_session(a2, s);
      }
      util_get_bvmlie_mldmacaddr(v208[0], v205[0], (int)&v206);
      qdf_mem_copy((void *)(a5 + 5347), &v206, 6u);
      util_get_mlie_common_info_len(*(_QWORD *)v208, *(_QWORD *)v205, a5 + 5346);
      util_get_bvmlie_primary_linkid(*(_QWORD *)v208, *(_QWORD *)v205, v204, v203);
      util_get_bvmlie_msd_cap(*(_QWORD *)v208, *(_QWORD *)v205, v201, &v198);
      if ( v201[0] == 1 )
      {
        v113 = *(_WORD *)(a5 + 5344) | 0x40;
        *(_WORD *)(a5 + 5356) = v198;
        *(_WORD *)(a5 + 5344) = v113;
      }
      util_get_bvmlie_eml_cap(*(_QWORD *)v208, *(_QWORD *)v205, v202, v199);
      if ( v202[0] == 1 )
      {
        v114 = v199[0] & 0x7801;
        v115 = *(_WORD *)(a5 + 5358) & 0x87FE;
        *(_WORD *)(a5 + 5344) |= 0x80u;
        *(_WORD *)(a5 + 5358) = v115 | v114;
      }
      util_get_bvmlie_ext_mld_cap_op_info(*(_QWORD *)v208, *(_QWORD *)v205, v200, v197);
      if ( (v200[0] & 1) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Ext mld caps found in assoc rsp",
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          "sir_convert_assoc_resp_frame2_mlo_struct");
        v124 = *(_WORD *)(a5 + 5344) & 0xFBFF | (v200[0] << 10);
        v125 = *(_WORD *)(a5 + 5364) & 0xFFBF | v197[0] & 0x40;
        *(_WORD *)(a5 + 5344) = v124;
        *(_WORD *)(a5 + 5364) = v125;
      }
      else
      {
        v124 = *(_WORD *)(a5 + 5344);
      }
      v126 = *(unsigned __int8 *)(a2 + 10696);
      v127 = 16 * (v204[0] & 1);
      *(_BYTE *)(a5 + 5353) = v203[0];
      v128 = *(unsigned __int8 *)(a5 + 5352);
      *(_WORD *)(a5 + 5366) = v126;
      v129 = v124 & 0xFFEF | v127;
      v130 = *(unsigned __int8 *)(a5 + 5349);
      *(_WORD *)(a5 + 5344) = v129;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev:%d Partner link count: %d, Link id: %d, MLD mac addr: %02x:%02x:%02x:**:**:%02x",
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        "sir_convert_assoc_resp_frame2_mlo_struct",
        *(unsigned __int8 *)(a2 + 10),
        *(unsigned __int8 *)(a5 + 5348),
        v130,
        v128);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Single link EMLSR: %d",
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        "sir_convert_assoc_resp_frame2_mlo_struct",
        (*(unsigned __int16 *)(a5 + 5364) >> 6) & 1);
    }
  }
  memset(s, 0, 0x102u);
  v214 = 0;
  v212 = 0;
  v213 = 0;
  v210 = 0;
  v211 = 0;
  *(_QWORD *)v208 = 0;
  v209 = 0;
  qdf_mem_set((void *)(a5 + 7700), 0x34u, 0);
  *(_DWORD *)(a5 + 7700) = 4;
  qdf_mem_set((void *)(a5 + 7756), 0x34u, 0);
  *(_DWORD *)(a5 + 7756) = 4;
  if ( !*((_WORD *)v21 + 1813) )
  {
    v169 = "%s: T2LM IEs not present";
LABEL_136:
    qdf_trace_msg(
      0x35u,
      8u,
      v169,
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      "sir_convert_assoc_resp_frame2_t2lm_struct");
    goto LABEL_137;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Number of T2LM IEs in assoc resp %d",
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    "sir_convert_assoc_resp_frame2_t2lm_struct");
  if ( *((_WORD *)v21 + 1813) )
  {
    v155 = v21 + 3630;
    v156 = 1;
    while ( 1 )
    {
      qdf_mem_set(s, 0x102u, 0);
      qdf_mem_set(v208, 0x34u, 0);
      LOBYTE(s[0]) = -1;
      if ( v156 == 3 )
        goto LABEL_141;
      v166 = (unsigned __int8)*(v155 - 1);
      BYTE2(s[0]) = 109;
      BYTE1(s[0]) = v166 + 1;
      qdf_mem_copy((char *)s + 3, v155, v166);
      ((void (__fastcall *)(__int64, __int64, _QWORD *, _QWORD))qdf_trace_hex_dump)(
        53,
        8,
        s,
        (unsigned int)(unsigned __int8)*(v155 - 1) + 3);
      if ( (unsigned int)wlan_mlo_parse_t2lm_info(s, v208) )
        break;
      v167 = (void *)(a5 + 7756);
      v168 = "%s: Parse upcoming T2LM IE success";
      if ( (v208[1] & 0x100) != 0
        || (v167 = (void *)(a5 + 7700), v168 = "%s: Parse established T2LM IE success", BYTE2(v208[1]) == 1) )
      {
        qdf_mem_copy(v167, v208, 0x34u);
        qdf_trace_msg(
          0x35u,
          8u,
          v168,
          v157,
          v158,
          v159,
          v160,
          v161,
          v162,
          v163,
          v164,
          "sir_convert_assoc_resp_frame2_t2lm_struct");
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Parse T2LM IE success",
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        "sir_convert_assoc_resp_frame2_t2lm_struct");
      v155 += 257;
      if ( *((unsigned __int16 *)v21 + 1813) <= (unsigned int)(unsigned __int16)v156++ )
        goto LABEL_137;
    }
    v169 = "%s: Parse T2LM IE fail";
    goto LABEL_136;
  }
LABEL_137:
  LODWORD(v186) = (unsigned __int8)v21[3264];
  LODWORD(v184) = (unsigned __int8)v21[1456];
  LODWORD(v182) = (unsigned __int8)v21[1340];
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: ht %d vht %d vendor vht: cap %d op %d, he %d he 6ghband %d eht %d eht320 %d, max idle: present %d val %d, he mu "
    "edca %d wmm %d qos %d mlo %d",
    v147,
    v148,
    v149,
    v150,
    v151,
    v152,
    v153,
    v154,
    "sir_convert_assoc_resp_frame2_struct",
    (unsigned __int8)v21[300],
    (unsigned __int8)v21[520],
    (unsigned __int8)v21[4500],
    (unsigned __int8)v21[4516],
    v182,
    v184,
    v186,
    (*(_DWORD *)(a5 + 2613) >> 17) & 1,
    (unsigned __int8)v21[452],
    *(unsigned __int16 *)(a5 + 2744),
    (unsigned __int8)v21[1442],
    *v195,
    (unsigned __int8)v21[458],
    (unsigned __int8)v21[3368]);
  if ( *v195 )
  {
    v178 = *((unsigned __int16 *)v21 + 2101);
    v179 = *((unsigned __int16 *)v21 + 2097);
    v180 = *((unsigned __int16 *)v21 + 2099);
    v181 = *((unsigned __int16 *)v21 + 2103);
    LODWORD(v194) = (v178 >> 5) & 3;
    LODWORD(v193) = (v178 >> 4) & 1;
    LODWORD(v192) = v178 & 0xF;
    LODWORD(v191) = *((unsigned __int16 *)v21 + 2100);
    LODWORD(v190) = v180 >> 12;
    LODWORD(v189) = (v180 >> 8) & 0xF;
    LODWORD(v188) = (v180 >> 5) & 3;
    LODWORD(v187) = (v180 >> 4) & 1;
    LODWORD(v185) = v180 & 0xF;
    LODWORD(v183) = *((unsigned __int16 *)v21 + 2098);
    qdf_trace_msg(
      0x35u,
      8u,
      "WMM: BE: aifsn %d, acm %d, aci %d, cwmin %d, cwmax %d, txop %d, BK: aifsn %d, acm %d, aci %d, cwmin %d, cwmax %d, "
      "txop %d, VI: aifsn %d, acm %d, aci %d, cwmin %d, cwmax %d, txop %d, VO: aifsn %d, acm %d, aci %d, cwmin %d, cwmax %d, txop %d",
      v170,
      v171,
      v172,
      v173,
      v174,
      v175,
      v176,
      v177,
      v179 & 0xF,
      (v179 >> 4) & 1,
      (v179 >> 5) & 3,
      (v179 >> 8) & 0xF,
      v179 >> 12,
      v183,
      v185,
      v187,
      v188,
      v189,
      v190,
      v191,
      v192,
      v193,
      v194,
      (v178 >> 8) & 0xF,
      v178 >> 12,
      *((unsigned __int16 *)v21 + 2102),
      v181 & 0xF,
      (v181 >> 4) & 1,
      (v181 >> 5) & 3,
      (v181 >> 8) & 0xF,
      v181 >> 12,
      *((unsigned __int16 *)v21 + 2104));
  }
  _qdf_mem_free((__int64)v21);
  result = 0;
LABEL_140:
  _ReadStatusReg(SP_EL0);
  return result;
}
