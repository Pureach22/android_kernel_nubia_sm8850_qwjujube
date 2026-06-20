__int64 __fastcall util_gen_link_reqrsp_cmn(
        char *a1,
        unsigned __int64 a2,
        unsigned __int8 a3,
        unsigned int a4,
        __int64 a5,
        unsigned int *a6,
        char *a7,
        unsigned __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        __int64 *a17)
{
  unsigned int v17; // w22
  unsigned __int64 v18; // x19
  __int64 result; // x0
  const char *v20; // x2
  const char *v21; // x2
  char *v22; // x26
  unsigned __int64 v23; // x8
  char *v24; // x20
  unsigned __int64 v25; // x23
  unsigned int v26; // w21
  unsigned int *v27; // x27
  unsigned __int64 v28; // x19
  unsigned int v29; // w23
  unsigned __int64 v30; // x20
  char *v31; // x27
  unsigned __int8 *v32; // x21
  __int64 v33; // x20
  __int64 v34; // x20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  size_t v43; // x0
  __int64 v44; // x20
  __int64 v45; // x20
  void *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x22
  unsigned int noninheritlists; // w28
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x20
  __int64 v66; // x20
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int bvmlie_persta_prof_for_linkid; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x20
  __int64 v85; // x20
  __int64 v86; // x20
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  const char *v95; // x2
  __int64 v96; // x4
  unsigned __int64 v97; // x5
  __int64 v98; // x20
  __int64 v99; // x20
  __int64 v100; // x20
  __int64 v101; // x20
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  const char *v118; // x2
  __int64 v119; // x4
  __int64 v120; // x20
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  unsigned __int8 *v129; // x8
  unsigned __int64 v130; // x9
  unsigned __int64 v131; // x10
  bool v132; // cf
  unsigned __int8 *v133; // x0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 v142; // x23
  char *v143; // x19
  __int64 v144; // x21
  char *v145; // x23
  unsigned int v146; // w0
  __int64 v147; // x20
  __int64 v148; // x20
  __int64 v149; // x20
  __int64 v150; // x20
  bool v151; // zf
  char v152; // w8
  int v153; // w8
  __int64 v154; // x1
  unsigned int v155; // w0
  unsigned __int64 v156; // x9
  unsigned __int8 *extn_eid; // x26
  unsigned __int64 v158; // x10
  __int64 v159; // x8
  __int64 v160; // x23
  char *v161; // x9
  unsigned __int64 v162; // x10
  unsigned __int64 v163; // x11
  void *v164; // x0
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  char v173; // w8
  __int64 v174; // x5
  __int64 v175; // x6
  __int64 v176; // x7
  int v177; // w8
  int v178; // w9
  int v179; // w10
  int v180; // w11
  int v181; // w12
  int v182; // w13
  unsigned int v183; // w14
  int v184; // w15
  int v185; // w16
  __int64 v186; // x20
  __int64 v187; // [xsp+0h] [xbp-170h]
  __int64 v188; // [xsp+8h] [xbp-168h]
  __int64 v189; // [xsp+10h] [xbp-160h]
  __int64 v190; // [xsp+18h] [xbp-158h]
  __int64 v191; // [xsp+20h] [xbp-150h]
  __int64 v192; // [xsp+28h] [xbp-148h]
  char *v193; // [xsp+58h] [xbp-118h]
  char v194; // [xsp+64h] [xbp-10Ch]
  unsigned __int8 *v195; // [xsp+68h] [xbp-108h]
  unsigned __int8 *v196; // [xsp+70h] [xbp-100h]
  unsigned __int8 *v197; // [xsp+78h] [xbp-F8h]
  unsigned __int64 v198; // [xsp+80h] [xbp-F0h]
  char *v199; // [xsp+88h] [xbp-E8h]
  unsigned int v200; // [xsp+90h] [xbp-E0h]
  unsigned __int8 v201; // [xsp+94h] [xbp-DCh] BYREF
  __int64 v202; // [xsp+98h] [xbp-D8h] BYREF
  char v203; // [xsp+A0h] [xbp-D0h] BYREF
  char v204; // [xsp+A4h] [xbp-CCh] BYREF
  __int64 v205; // [xsp+A8h] [xbp-C8h] BYREF
  __int64 v206; // [xsp+B0h] [xbp-C0h] BYREF
  char v207; // [xsp+B8h] [xbp-B8h] BYREF
  _WORD v208[2]; // [xsp+BCh] [xbp-B4h] BYREF
  __int64 v209; // [xsp+C0h] [xbp-B0h] BYREF
  char v210[4]; // [xsp+CCh] [xbp-A4h] BYREF
  __int64 v211; // [xsp+D0h] [xbp-A0h] BYREF
  __int64 v212; // [xsp+D8h] [xbp-98h] BYREF
  char v213[4]; // [xsp+E0h] [xbp-90h] BYREF
  char v214[4]; // [xsp+E4h] [xbp-8Ch] BYREF
  __int64 v215; // [xsp+E8h] [xbp-88h] BYREF
  __int64 v216; // [xsp+F0h] [xbp-80h] BYREF
  __int64 v217; // [xsp+F8h] [xbp-78h] BYREF
  __int64 v218; // [xsp+100h] [xbp-70h] BYREF
  unsigned __int64 v219; // [xsp+108h] [xbp-68h] BYREF
  char *v220; // [xsp+110h] [xbp-60h] BYREF
  __int64 v221; // [xsp+118h] [xbp-58h] BYREF
  char *v222; // [xsp+120h] [xbp-50h] BYREF
  __int64 v223; // [xsp+128h] [xbp-48h]
  __int64 v224; // [xsp+130h] [xbp-40h]
  unsigned __int64 v225; // [xsp+138h] [xbp-38h] BYREF
  unsigned __int64 v226; // [xsp+140h] [xbp-30h] BYREF
  unsigned __int8 *v227; // [xsp+148h] [xbp-28h] BYREF
  int v228; // [xsp+150h] [xbp-20h] BYREF
  __int16 v229; // [xsp+154h] [xbp-1Ch]
  int v230; // [xsp+158h] [xbp-18h] BYREF
  __int16 v231; // [xsp+15Ch] [xbp-14h]
  __int64 v232; // [xsp+160h] [xbp-10h]

  v232 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v230 = a5;
  v231 = WORD2(a5);
  v226 = 0;
  v227 = nullptr;
  v224 = 0;
  v225 = 0;
  v222 = nullptr;
  v223 = 0;
  v221 = 0;
  v219 = 0;
  v220 = nullptr;
  v217 = 0;
  v218 = 0;
  v215 = 0;
  v216 = 0;
  v214[0] = 0;
  v213[0] = 0;
  v229 = 0;
  v228 = 0;
  v211 = 0;
  v212 = 0;
  v210[0] = 0;
  v209 = 0;
  v208[0] = 0;
  v207 = 0;
  v205 = 0;
  v206 = 0;
  v204 = 0;
  v203 = 0;
  v202 = 0;
  v201 = -1;
  if ( !a1 )
  {
    v20 = "%s: Pointer to original frame is NULL";
LABEL_20:
    qdf_trace_msg(0x8Fu, 2u, v20, a9, a10, a11, a12, a13, a14, a15, a16, "util_gen_link_reqrsp_cmn");
    result = 29;
    goto LABEL_21;
  }
  if ( !a2 )
  {
    v21 = "%s: Length of original frame is zero";
LABEL_17:
    qdf_trace_msg(0x8Fu, 2u, v21, a9, a10, a11, a12, a13, a14, a15, a16, "util_gen_link_reqrsp_cmn");
    result = 4;
    goto LABEL_21;
  }
  v17 = a3;
  if ( a3 >= 4u && a3 != 5 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: 802.11 frame subtype %u is invalid",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "util_gen_link_reqrsp_cmn",
      a3);
    result = 4;
    goto LABEL_21;
  }
  if ( !a7 )
  {
    v20 = "%s: Pointer to secondary link specific frame is NULL";
    goto LABEL_20;
  }
  if ( !a8 )
  {
    v21 = "%s: Maximum size of secondary link specific frame is zero";
    goto LABEL_17;
  }
  if ( !a17 )
  {
    v20 = "%s: Pointer to populated length of secondary link specific frame is NULL";
    goto LABEL_20;
  }
  if ( a3 )
  {
    if ( a3 == 2 )
    {
      v22 = a1;
      v23 = 10;
    }
    else if ( a3 == 5 )
    {
      v18 = a2;
      if ( a2 <= 7 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Frame length %zu is smaller than required timestamp length",
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          a16,
          "util_gen_link_reqrsp_cmn",
          a2);
        result = 4;
        goto LABEL_21;
      }
      v22 = a1;
      v24 = a7;
      v25 = a8;
      v26 = a4;
      v27 = a6;
      qdf_mem_copy(&v206, a1, 8u);
      a6 = v27;
      a4 = v26;
      a8 = v25;
      a7 = v24;
      v23 = 12;
      a2 = v18;
    }
    else
    {
      v22 = a1;
      v23 = 6;
    }
  }
  else
  {
    v22 = a1;
    v23 = 4;
  }
  v28 = a2 - v23;
  if ( a2 < v23 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Frame length %zu is smaller than the IE section offset %zu for subtype %u",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "util_gen_link_reqrsp_cmn",
      a2,
      v23,
      v17,
      a8);
    result = 4;
    goto LABEL_21;
  }
  if ( a2 == v23 )
  {
    v21 = "%s: No space left in frame for IE section";
    goto LABEL_17;
  }
  v29 = a4;
  v30 = a8;
  v31 = a7;
  v32 = (unsigned __int8 *)&v22[v23];
  v226 = 0;
  v227 = nullptr;
  if ( v17 == 5 && a6 )
    result = util_find_mlie_for_ml_probe_resp_by_mldaddr(
               v32,
               v28,
               &v227,
               &v226,
               *a6 | ((unsigned __int64)*((unsigned __int16 *)a6 + 2) << 32));
  else
    result = util_find_mlie(&v22[v23], a2 - v23, &v227, &v226);
  if ( (_DWORD)result )
    goto LABEL_21;
  if ( !v227 )
  {
    v21 = "%s: Invalid original frame since no Multi-Link element found";
    goto LABEL_17;
  }
  if ( !v226 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Length of Multi-Link element sequence is zero. Investigate.",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "util_gen_link_reqrsp_cmn");
    result = 16;
    goto LABEL_21;
  }
  if ( v226 <= 4 )
  {
    v33 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Multi-Link element sequence length %zu octets is smaller than required for the fixed portion of Multi-Link e"
        "lement (%zu octets)",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks = v33;
      result = 27;
      goto LABEL_21;
    }
LABEL_39:
    result = 27;
    goto LABEL_21;
  }
  if ( *v227 != 255 || v227[2] != 107 )
  {
    result = 4;
    goto LABEL_21;
  }
  if ( (*(_WORD *)(v227 + 3) & 7u) > 4 )
    goto LABEL_39;
  if ( (*(_WORD *)(v227 + 3) & 7) != 0 )
  {
    v34 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_60 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Unexpected variant %u of Multi-Link element.",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        "util_gen_link_reqrsp_cmn",
        *(_WORD *)(v227 + 3) & 7);
      util_gen_link_reqrsp_cmn___last_ticks_60 = v34;
      result = 27;
      goto LABEL_21;
    }
    goto LABEL_39;
  }
  v225 = 0;
  v202 = 0;
  v210[0] = 0;
  result = wlan_get_elem_fragseq_info((__int64)v227, v226, (__int64)v210, (__int64)&v202, (__int64)&v225);
  if ( (_DWORD)result )
    goto LABEL_21;
  v200 = v17;
  if ( v210[0] == 1 )
  {
    if ( v202 == v226 )
    {
      if ( v225 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: ML IE fragment sequence found with payload len %zu",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "util_gen_link_reqrsp_cmn");
        v43 = v225;
        goto LABEL_61;
      }
      v85 = jiffies;
      if ( util_gen_link_reqrsp_cmn___last_ticks_64 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Multi-Link element fragment sequence payload is reported as 0, investigate",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "util_gen_link_reqrsp_cmn");
        util_gen_link_reqrsp_cmn___last_ticks_64 = v85;
        result = 16;
        goto LABEL_21;
      }
    }
    else
    {
      v45 = jiffies;
      if ( util_gen_link_reqrsp_cmn___last_ticks_62 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Mismatch in values of element fragment sequence total length. Val per frag info determination: %zu octets,"
          " val per Multi-Link element search: %zu octets",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "util_gen_link_reqrsp_cmn");
        util_gen_link_reqrsp_cmn___last_ticks_62 = v45;
        result = 16;
        goto LABEL_21;
      }
    }
LABEL_77:
    result = 16;
    goto LABEL_21;
  }
  if ( v226 >= 0x102 )
  {
    v44 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_66 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Expected presence of valid fragment sequence since Multi-Link element sequence length %zu octets is larger t"
        "han frag threshold of %zu octets, however no valid fragment sequence found",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_66 = v44;
      result = 16;
      goto LABEL_21;
    }
    goto LABEL_77;
  }
  v43 = v226 - 3;
  v225 = v226 - 3;
LABEL_61:
  v46 = (void *)_qdf_mem_malloc(v43, "util_gen_link_reqrsp_cmn", 2322);
  v55 = (__int64)v46;
  if ( !v46 )
  {
    v66 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_67 - jiffies + 125 < 0 )
    {
      noninheritlists = 2;
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Could not allocate memory for Multi-Link element payload copy",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_67 = v66;
      goto LABEL_90;
    }
LABEL_69:
    noninheritlists = 2;
    goto LABEL_90;
  }
  if ( v210[0] == 1 )
  {
    noninheritlists = wlan_defrag_elem_fragseq(0, (__int64)v227, v226, (__int64)v46, v225, (__int64)&v209);
    if ( noninheritlists )
      goto LABEL_90;
    if ( v209 != v225 )
    {
      v65 = jiffies;
      if ( util_gen_link_reqrsp_cmn___last_ticks_68 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Length of de-fragmented payload %zu octets is not equal to length of Multi-Link element fragment sequence "
          "payload %zu octets",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "util_gen_link_reqrsp_cmn");
        util_gen_link_reqrsp_cmn___last_ticks_68 = v65;
      }
      noninheritlists = 16;
      goto LABEL_90;
    }
  }
  else
  {
    qdf_mem_copy(v46, v227 + 3, (unsigned int)v225);
  }
  v223 = 0;
  v224 = 0;
  noninheritlists = util_parse_multi_link_ctrl(v55);
  if ( noninheritlists )
    goto LABEL_90;
  if ( !v224 )
  {
    v86 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_69 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Unable to successfully obtain Link Info",
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_69 = v86;
      noninheritlists = 27;
      goto LABEL_90;
    }
    goto LABEL_81;
  }
  v211 = 0;
  v212 = 0;
  bvmlie_persta_prof_for_linkid = util_find_bvmlie_persta_prof_for_linkid(v29, v224, v223, &v212, &v211);
  if ( bvmlie_persta_prof_for_linkid )
  {
    noninheritlists = bvmlie_persta_prof_for_linkid;
    v84 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_71 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Per STA profile not found for link id %d",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "util_gen_link_reqrsp_cmn",
        (unsigned __int8)v29);
      util_gen_link_reqrsp_cmn___last_ticks_71 = v84;
    }
    goto LABEL_90;
  }
  v219 = 0;
  v220 = nullptr;
  v213[0] = 0;
  v207 = 0;
  v203 = 0;
  v204 = 0;
  noninheritlists = util_parse_bvmlie_perstaprofile_stactrl(
                      (int)v212 + 2,
                      v211,
                      (int)&v201,
                      (int)v208,
                      (int)&v207,
                      (int)&v205,
                      (int)&v204,
                      (int)&v203,
                      (__int64)v213,
                      (int)&v228,
                      1,
                      (__int64)&v220,
                      (int)&v219,
                      0);
  if ( noninheritlists )
    goto LABEL_90;
  if ( v200 == 5 && (v203 & 1) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Complete profile information is not present in per-STA profile of probe response frame",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "util_gen_link_reqrsp_cmn");
    noninheritlists = 11;
    goto LABEL_90;
  }
  if ( !v220 )
  {
    v98 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_75 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: STA profile is NULL",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_75 = v98;
      noninheritlists = 27;
      goto LABEL_90;
    }
    goto LABEL_81;
  }
  if ( (v213[0] & 1) == 0 )
  {
    v99 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_77 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Unable to get MAC address from per-STA profile",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_77 = v99;
      noninheritlists = 27;
      goto LABEL_90;
    }
    goto LABEL_81;
  }
  *a17 = 0;
  if ( v30 <= 0x17 )
  {
    v95 = "%s: Insufficient space in link specific frame for 802.11 header. Required: %u octets, available: %zu octets";
    v96 = 24;
    v97 = v30;
LABEL_124:
    noninheritlists = 2;
    qdf_trace_msg(0x8Fu, 2u, v95, v87, v88, v89, v90, v91, v92, v93, v94, "util_gen_link_reqrsp_cmn", v96, v97);
    goto LABEL_90;
  }
  v221 = 24;
  v222 = v31 + 24;
  if ( (v200 | 2) == 2 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Populating fixed fields for (re)assoc req in link specific frame",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "util_gen_link_reqrsp_cmn");
    if ( v219 <= 1 )
    {
      v100 = jiffies;
      if ( util_gen_link_reqrsp_cmn___last_ticks_81 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Remaining length of STA profile %zu octets is less than length of Capability Info %u",
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          "util_gen_link_reqrsp_cmn");
        util_gen_link_reqrsp_cmn___last_ticks_81 = v100;
        noninheritlists = 27;
        goto LABEL_90;
      }
      goto LABEL_81;
    }
    v97 = v30 - 24;
    if ( v30 - 24 <= 1 )
      goto LABEL_105;
    qdf_mem_copy(v31 + 24, v220, 2u);
    v97 = v30 - 26;
    v219 -= 2LL;
    v220 += 2;
    if ( v30 - 26 <= 1 )
    {
      v95 = "%s: Insufficient space in link specific frame for Listen Interval field. Required: %u octets, available: %zu octets";
      goto LABEL_123;
    }
    qdf_mem_copy(v31 + 26, v22 + 2, 2u);
    v221 = 28;
    v222 = v31 + 28;
    if ( v200 != 2 )
      goto LABEL_130;
    v97 = v30 - 28;
    if ( v30 - 28 <= 5 )
    {
      v95 = "%s: Insufficient space in link specific frame for current AP address. Required: %u octets, available: %zu octets";
      v96 = 6;
      goto LABEL_124;
    }
    qdf_mem_copy(v31 + 28, v22 + 4, 6u);
    v118 = "%s: Reassoc req: Added Current AP address field (%u octets) to link specific frame";
    v119 = 6;
    v221 = 34;
    v222 = v31 + 34;
    goto LABEL_129;
  }
  if ( (v200 & 5) == 1 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Populating fixed fields for (re)assoc resp in link specific frame",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "util_gen_link_reqrsp_cmn");
    if ( v219 <= 3 )
    {
      v101 = jiffies;
      if ( util_gen_link_reqrsp_cmn___last_ticks_88 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Remaining length of STA profile %zu octets is less than length of Capability Info + length of Status Code %u",
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          "util_gen_link_reqrsp_cmn");
        util_gen_link_reqrsp_cmn___last_ticks_88 = v101;
        noninheritlists = 27;
        goto LABEL_90;
      }
      goto LABEL_81;
    }
    v97 = v30 - 24;
    if ( v30 - 24 <= 3 )
    {
      v95 = "%s: Insufficient space in link specific frame for Capability Info and Status Code fields. Required: %u octet"
            "s, available: %zu octets";
      v96 = 4;
      goto LABEL_124;
    }
    qdf_mem_copy(v31 + 24, v220, 4u);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Added Capability Info and Status Code fields (%u octets) to link specific frame",
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      "util_gen_link_reqrsp_cmn",
      4);
    v97 = v30 - 28;
    v219 -= 4LL;
    v220 += 4;
    if ( v30 - 28 <= 1 )
    {
      v95 = "%s: Insufficient space in link specific frame for AID field. Required: %u octets, available: %zu octets";
      goto LABEL_123;
    }
    qdf_mem_copy(v31 + 28, v22 + 4, 2u);
    v118 = "%s: Added AID field (%u octets) to link specific frame";
    v221 = 30;
    v222 = v31 + 30;
    v119 = 2;
LABEL_129:
    qdf_trace_msg(0x8Fu, 8u, v118, v110, v111, v112, v113, v114, v115, v116, v117, "util_gen_link_reqrsp_cmn", v119);
    goto LABEL_130;
  }
  if ( v200 != 5 )
  {
LABEL_130:
    v198 = v219;
    v199 = v220;
    goto LABEL_131;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Populating fixed fields for probe response in link specific frame",
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    "util_gen_link_reqrsp_cmn");
  v97 = v30 - 24;
  if ( v30 - 24 <= 7 )
  {
    v95 = "%s: Insufficient space in link specific frame for Timestamp Info field. Required: %u octets, available: %zu octets";
    v96 = 8;
    goto LABEL_124;
  }
  if ( v204 == 1 )
    v206 += 2 * v205;
  qdf_mem_copy(v31 + 24, &v206, 8u);
  if ( (v207 & 1) == 0 )
  {
    v120 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_96 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Beacon interval information not present in STA info field of per-STA profile",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_96 = v120;
      noninheritlists = 27;
      goto LABEL_90;
    }
    goto LABEL_81;
  }
  v97 = v30 - 32;
  if ( v30 - 32 <= 1 )
  {
    v95 = "%s: Insufficient space in link specific frame for Beacon Interval Info field. Required: %u octets, available: %zu octets";
    goto LABEL_123;
  }
  qdf_mem_copy(v31 + 32, v208, 2u);
  if ( v219 <= 1 )
  {
    v150 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_99 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Remaining length of STA profile %zu octets is less than length of Capability Info %u",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_99 = v150;
      noninheritlists = 27;
      goto LABEL_90;
    }
    goto LABEL_81;
  }
  v97 = v30 - 34;
  if ( v30 - 34 <= 1 )
  {
LABEL_105:
    v95 = "%s: Insufficient space in link specific frame for Capability Info field. Required: %u octets, available: %zu octets";
LABEL_123:
    v96 = 2;
    goto LABEL_124;
  }
  qdf_mem_copy(v31 + 34, v220, 2u);
  v221 = 36;
  v222 = v31 + 36;
  v198 = v219 - 2;
  v199 = v220 + 2;
  v219 -= 2LL;
  v220 += 2;
LABEL_131:
  v217 = 0;
  v218 = 0;
  v215 = 0;
  v216 = 0;
  noninheritlists = util_get_noninheritlists(v199, v198, &v218, &v217, &v216, &v215);
  if ( noninheritlists )
    goto LABEL_90;
  v129 = nullptr;
  if ( v32 && v28 >= 2 )
  {
    v130 = v28;
    v129 = v32;
    do
    {
      v131 = v129[1] + 2LL;
      v132 = v130 >= v131;
      v130 -= v131;
      if ( !v132 )
        break;
      if ( !*v129 )
        goto LABEL_140;
      v129 += v131;
    }
    while ( v130 > 1 );
    v129 = nullptr;
  }
LABEL_140:
  if ( v200 <= 5 && ((1 << v200) & 0x25) != 0 )
  {
    if ( v129 )
      goto LABEL_143;
    v148 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_100 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: SSID element not found in reporting STA of the frame.",
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_100 = v148;
      noninheritlists = 27;
      goto LABEL_90;
    }
LABEL_81:
    noninheritlists = 27;
    goto LABEL_90;
  }
  if ( v129 )
  {
    v149 = jiffies;
    if ( util_gen_link_reqrsp_cmn___last_ticks_102 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: SSID element found for reporting STA for (re)association response. It should not be present.",
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        "util_gen_link_reqrsp_cmn");
      util_gen_link_reqrsp_cmn___last_ticks_102 = v149;
      noninheritlists = 27;
      goto LABEL_90;
    }
    goto LABEL_81;
  }
  if ( v198 >= 2 && v199 )
  {
    v162 = v198;
    v161 = v199;
    while ( 1 )
    {
      v163 = (unsigned __int8)v161[1] + 2LL;
      v132 = v162 >= v163;
      v162 -= v163;
      if ( !v132 )
        goto LABEL_143;
      if ( !*v161 )
        break;
      v161 += v163;
      if ( v162 <= 1 )
        goto LABEL_143;
    }
    if ( v161 )
    {
      v186 = jiffies;
      if ( util_gen_link_reqrsp_cmn___last_ticks_104 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: SSID element found in STA profile for (re)association response. It should not be present.",
          v121,
          v122,
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          "util_gen_link_reqrsp_cmn");
        util_gen_link_reqrsp_cmn___last_ticks_104 = v186;
        noninheritlists = 27;
        goto LABEL_90;
      }
      goto LABEL_81;
    }
  }
LABEL_143:
  if ( v129 )
    v133 = v129;
  else
    v133 = v32;
  v196 = v133;
  noninheritlists = ((__int64 (*)(void))util_validate_reportingsta_ie)();
  if ( noninheritlists )
    goto LABEL_90;
  v142 = v196[1] + 2LL;
  v197 = &v196[v142];
  v195 = (unsigned __int8 *)(&v196[v142] - v32);
  if ( (unsigned __int64)v195 <= v28 )
  {
    v151 = v198 < 2 || v199 == nullptr;
    v193 = &v31[v30];
    v152 = v151;
    v194 = v152;
    while ( 1 )
    {
      v153 = *v196;
      if ( v153 != 255 )
        break;
      v154 = v196[2];
      if ( (_DWORD)v154 != 107 )
      {
        if ( v198 )
        {
          extn_eid = (unsigned __int8 *)util_find_extn_eid(255, v154, v199, v198);
LABEL_189:
          if ( extn_eid )
          {
            v155 = util_validate_sta_prof_ie(extn_eid, v199, v198);
            if ( v155 )
              goto LABEL_218;
            v159 = extn_eid[1];
            if ( (unsigned __int64)(&v199[v198] - (char *)extn_eid) < 7 || *v196 != 221 )
            {
              v160 = v159 + 2;
              if ( &v222[v159 + 2] > v193 )
                goto LABEL_69;
              qdf_mem_copy(v222, extn_eid, (unsigned int)v160);
              v221 += v160;
              v222 += v160;
              *extn_eid = 0;
            }
LABEL_199:
            if ( v195 == (unsigned __int8 *)v28 )
              goto LABEL_148;
            v155 = util_validate_reportingsta_ie(v197, v32, v28);
            if ( v155 )
            {
LABEL_218:
              noninheritlists = v155;
              goto LABEL_90;
            }
            v142 = v197[1] + 2LL;
            goto LABEL_202;
          }
        }
LABEL_195:
        v214[0] = 0;
        v155 = util_eval_ie_in_noninheritlist(v196, v142, v218, v217, v216, v215, v214);
        if ( v155 )
          goto LABEL_218;
        if ( (v214[0] & 1) == 0 )
        {
          if ( &v222[v142] > v193 )
            goto LABEL_69;
          qdf_mem_copy(v222, v196, (unsigned int)v142);
          v221 += v142;
          v222 += v142;
        }
        goto LABEL_199;
      }
      if ( v200 == 5 && v196 == v227 )
      {
        v155 = util_add_mlie_for_prb_rsp_gen(v196, v196[1], &v222, &v221, v30, v201);
        if ( v155 )
          goto LABEL_218;
      }
      if ( v195 == (unsigned __int8 *)v28 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: break while bml ie is the last one",
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          v140,
          v141,
          "util_gen_link_reqrsp_cmn");
        goto LABEL_148;
      }
      v155 = util_validate_reportingsta_ie(v197, v32, v28);
      if ( v155 )
        goto LABEL_218;
      while ( 1 )
      {
        v142 = v197[1] + 2LL;
        if ( *v197 != 242 || &v197[v142] - v32 >= v28 )
          break;
        noninheritlists = util_validate_reportingsta_ie(&v197[v142], v32, v28);
        v197 += v142;
        if ( noninheritlists )
          goto LABEL_90;
      }
LABEL_202:
      v196 = v197;
      v197 += v142;
      v195 = (unsigned __int8 *)(v197 - v32);
      if ( v197 - v32 > v28 )
        goto LABEL_148;
    }
    v156 = v198;
    extn_eid = (unsigned __int8 *)v199;
    if ( (v194 & 1) == 0 )
    {
      do
      {
        v158 = extn_eid[1] + 2LL;
        v132 = v156 >= v158;
        v156 -= v158;
        if ( !v132 )
          break;
        if ( *extn_eid == v153 )
          goto LABEL_189;
        extn_eid += v158;
      }
      while ( v156 > 1 );
    }
    goto LABEL_195;
  }
LABEL_148:
  if ( !v198 )
  {
LABEL_216:
    v164 = v31 + 16;
    if ( (v200 | 2) == 2 )
    {
      qdf_mem_copy(v164, &v230, 6u);
      qdf_mem_copy(v31 + 10, &v228, 6u);
      qdf_mem_copy(v31 + 4, &v230, 6u);
      v173 = 0;
    }
    else
    {
      qdf_mem_copy(v164, &v228, 6u);
      qdf_mem_copy(v31 + 10, &v228, 6u);
      qdf_mem_copy(v31 + 4, &v230, 6u);
      if ( v200 == 5 )
        v173 = 80;
      else
        v173 = 16;
    }
    *v31 = v173;
    v174 = (unsigned __int8)v31[16];
    v175 = (unsigned __int8)v31[17];
    v176 = (unsigned __int8)v31[18];
    v177 = (unsigned __int8)v31[21];
    v178 = (unsigned __int8)v31[10];
    v179 = (unsigned __int8)v31[11];
    v180 = (unsigned __int8)v31[12];
    v181 = (unsigned __int8)v31[15];
    v182 = (unsigned __int8)v31[4];
    v183 = (unsigned __int8)v31[5];
    v184 = (unsigned __int8)v31[6];
    v185 = (unsigned __int8)v31[9];
    v31[1] = 0;
    LODWORD(v192) = v182;
    LODWORD(v191) = v181;
    LODWORD(v190) = v180;
    LODWORD(v189) = v179;
    LODWORD(v188) = v178;
    LODWORD(v187) = v177;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: subtype:%u addr3:%02x:%02x:%02x:**:**:%02x addr2:%02x:%02x:%02x:**:**:%02x addr1:%02x:%02x:%02x:**:**:%02x",
      v165,
      v166,
      v167,
      v168,
      v169,
      v170,
      v171,
      v172,
      "util_gen_link_reqrsp_cmn",
      v200,
      v174,
      v175,
      v176,
      v187,
      v188,
      v189,
      v190,
      v191,
      v192,
      v183,
      v184,
      v185);
    noninheritlists = 0;
    *a17 = v221;
    goto LABEL_90;
  }
  v144 = v221;
  v143 = v222;
  v145 = &v31[v30];
  while ( 1 )
  {
    v146 = util_validate_sta_prof_ie(v199, v199, v198);
    if ( v146 )
    {
      noninheritlists = v146;
      goto LABEL_224;
    }
    v147 = (unsigned __int8)v199[1] + 2LL;
    if ( *v199 )
      break;
LABEL_150:
    v151 = v198 == v147;
    v198 -= v147;
    v199 += v147;
    if ( v151 )
    {
      v221 = v144;
      v222 = v143;
      goto LABEL_216;
    }
  }
  if ( &v143[v147] <= v145 )
  {
    qdf_mem_copy(v143, v199, (unsigned int)v147);
    v144 += v147;
    *v199 = 0;
    v143 += v147;
    goto LABEL_150;
  }
  noninheritlists = 2;
LABEL_224:
  v221 = v144;
  v222 = v143;
LABEL_90:
  _qdf_mem_free(v55);
  result = noninheritlists;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
