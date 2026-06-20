__int64 __fastcall util_scan_gen_scan_entry(
        unsigned __int64 a1,
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
  char *v46; // x22
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
  __int64 v60; // x4
  __int64 v61; // x24
  unsigned int v62; // w13
  unsigned int v63; // w25
  unsigned int v64; // w14
  __int64 *v65; // x16
  _QWORD *v66; // x17
  __int64 v67; // x12
  _QWORD *v68; // x1
  _QWORD *v69; // x2
  _QWORD *v70; // x3
  __int64 v71; // x20
  unsigned int v72; // w9
  _BYTE *v73; // x26
  unsigned int v74; // w8
  int v75; // w9
  int *v76; // x10
  __int64 v77; // x21
  unsigned int v78; // w9
  __int64 v79; // x8
  unsigned __int64 v80; // x8
  unsigned __int8 *v81; // x9
  unsigned int v82; // w27
  __int64 v83; // x21
  unsigned int v84; // w22
  _BYTE *v85; // x25
  unsigned __int64 v86; // x27
  unsigned __int16 *v87; // x23
  _BYTE *v88; // x21
  unsigned __int64 v89; // x8
  unsigned int v90; // w28
  unsigned __int64 v91; // x21
  unsigned __int64 v92; // x11
  unsigned int v93; // w24
  bool v94; // cc
  __int64 v95; // x10
  unsigned __int64 v96; // x28
  int v97; // w8
  __int64 v98; // x27
  void *v99; // x0
  const void *v100; // x1
  size_t v101; // x2
  __int64 v102; // x22
  unsigned int v103; // w25
  __int64 v104; // x21
  unsigned int v105; // w1
  unsigned int v106; // w22
  bool v107; // cf
  _QWORD *v108; // x10
  unsigned __int64 v109; // x10
  unsigned int v110; // w11
  __int64 v111; // x8
  __int64 v112; // x27
  unsigned int v113; // w24
  char *v114; // x23
  __int64 v115; // x22
  __int64 v116; // x8
  __int64 v117; // x8
  __int64 v118; // x8
  unsigned int v119; // w8
  unsigned int v120; // w20
  const char *v121; // x3
  const char *v122; // x20
  const char *v123; // x4
  __int64 v124; // x5
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  unsigned __int64 v134; // x8
  __int64 v135; // x9
  unsigned __int8 *v136; // x9
  unsigned int v137; // w12
  char v138; // w10
  unsigned __int64 v139; // x11
  __int64 v140; // x12
  __int64 v141; // x0
  __int64 v142; // x0
  unsigned __int8 *v143; // x9
  unsigned int v144; // w11
  char v145; // w10
  __int64 v146; // x11
  unsigned __int8 *v147; // x9
  size_t v148; // x2
  __int64 v149; // x8
  const void *v150; // x1
  __int64 v151; // x9
  int phymode; // w0
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  __int64 v161; // x8
  char v162; // w8
  __int64 v163; // x8
  unsigned __int16 *v164; // x8
  int v165; // w8
  _BYTE *v166; // x8
  __int64 v167; // x4
  __int64 v168; // x5
  __int64 v169; // x6
  __int64 v170; // x7
  int v171; // w9
  const char *v172; // x2
  __int64 v173; // x9
  char v174; // w8
  __int64 v175; // x20
  unsigned __int64 v176; // x27
  unsigned __int64 v177; // x8
  char v178; // w8
  _BYTE *v179; // x22
  int v180; // w26
  unsigned __int64 v181; // x21
  char *v182; // x0
  int v183; // w8
  __int64 v184; // x8
  _QWORD *v185; // x0
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  _QWORD *v194; // x22
  __int64 v195; // x8
  __int64 v196; // x23
  __int16 v197; // w21
  unsigned __int64 v198; // x20
  __int64 v199; // x8
  double v200; // d0
  double v201; // d1
  double v202; // d2
  double v203; // d3
  double v204; // d4
  double v205; // d5
  double v206; // d6
  double v207; // d7
  _BYTE *v208; // x8
  __int64 v209; // x20
  unsigned __int8 link_info_offset; // w0
  __int64 v211; // x9
  __int64 v212; // x8
  int v213; // w10
  unsigned __int8 *v214; // x9
  __int64 v215; // x26
  unsigned __int64 v216; // x27
  int v217; // w8
  __int64 v218; // x6
  __int64 v219; // x7
  int v220; // w9
  __int64 v221; // x21
  __int64 v222; // x24
  int v223; // w9
  __int16 v224; // w0
  __int64 v225; // x25
  _BYTE *v226; // x8
  __int64 v227; // x5
  unsigned __int64 v228; // x9
  __int64 v229; // x20
  __int64 v230; // x21
  __int64 v231; // x22
  __int64 v232; // x23
  unsigned __int64 v233; // x8
  __int16 v234; // w24
  unsigned __int8 v235; // w23
  unsigned __int8 *v236; // x22
  unsigned int v237; // w27
  __int64 v238; // x23
  __int64 v239; // x21
  unsigned int v240; // w0
  int v241; // w8
  unsigned int v242; // w21
  __int64 v243; // x25
  __int64 v244; // x21
  unsigned __int8 *v245; // x23
  __int64 v246; // x26
  unsigned int v247; // w9
  __int64 v248; // x21
  __int64 v249; // x21
  int v250; // w8
  _QWORD *v251; // x24
  int v252; // w28
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  __int64 v261; // x7
  __int64 v262; // x5
  int v263; // w8
  signed int v264; // w8
  __int64 v265; // x6
  const char *v266; // x3
  __int64 v267; // x4
  int v268; // w21
  unsigned int v269; // w26
  double v270; // d0
  double v271; // d1
  double v272; // d2
  double v273; // d3
  double v274; // d4
  double v275; // d5
  double v276; // d6
  double v277; // d7
  unsigned int v278; // w0
  unsigned int v279; // w8
  int v280; // w8
  unsigned int v281; // w8
  unsigned int v282; // w9
  unsigned int v283; // w8
  unsigned int v284; // w8
  __int64 v285; // [xsp+0h] [xbp-E0h]
  __int64 v286; // [xsp+8h] [xbp-D8h]
  __int64 v287; // [xsp+10h] [xbp-D0h]
  __int64 v288; // [xsp+20h] [xbp-C0h]
  unsigned int v289; // [xsp+2Ch] [xbp-B4h]
  __int64 v290; // [xsp+30h] [xbp-B0h]
  _QWORD *v291; // [xsp+38h] [xbp-A8h]
  _QWORD *v292; // [xsp+38h] [xbp-A8h]
  unsigned int v293; // [xsp+44h] [xbp-9Ch]
  unsigned int v294; // [xsp+44h] [xbp-9Ch]
  __int64 v295; // [xsp+48h] [xbp-98h]
  __int64 v296; // [xsp+48h] [xbp-98h]
  __int64 v297; // [xsp+48h] [xbp-98h]
  __int64 v298; // [xsp+50h] [xbp-90h]
  __int64 v299; // [xsp+50h] [xbp-90h]
  __int64 v300; // [xsp+50h] [xbp-90h]
  _QWORD *v301; // [xsp+58h] [xbp-88h]
  _QWORD *v302; // [xsp+58h] [xbp-88h]
  _QWORD *v303; // [xsp+58h] [xbp-88h]
  _QWORD *v304; // [xsp+60h] [xbp-80h]
  _QWORD *v305; // [xsp+60h] [xbp-80h]
  _QWORD *v306; // [xsp+60h] [xbp-80h]
  _QWORD *v307; // [xsp+68h] [xbp-78h]
  _QWORD *v308; // [xsp+68h] [xbp-78h]
  _QWORD *v309; // [xsp+68h] [xbp-78h]
  _QWORD *v310; // [xsp+70h] [xbp-70h]
  _QWORD *v311; // [xsp+70h] [xbp-70h]
  _QWORD *v312; // [xsp+70h] [xbp-70h]
  __int64 *v313; // [xsp+78h] [xbp-68h]
  __int64 *v314; // [xsp+78h] [xbp-68h]
  __int64 *v315; // [xsp+78h] [xbp-68h]
  unsigned int v316; // [xsp+84h] [xbp-5Ch]
  unsigned int v317; // [xsp+84h] [xbp-5Ch]
  unsigned int v318; // [xsp+84h] [xbp-5Ch]
  unsigned int v319; // [xsp+88h] [xbp-58h]
  unsigned int v320; // [xsp+88h] [xbp-58h]
  unsigned int v321; // [xsp+88h] [xbp-58h]
  __int64 v322; // [xsp+88h] [xbp-58h]
  __int64 v323; // [xsp+90h] [xbp-50h]
  __int64 v324; // [xsp+90h] [xbp-50h]
  unsigned __int64 v325; // [xsp+98h] [xbp-48h]
  unsigned __int64 v326; // [xsp+98h] [xbp-48h]
  unsigned int v327; // [xsp+A0h] [xbp-40h]
  unsigned int v328; // [xsp+A0h] [xbp-40h]
  unsigned __int8 v329; // [xsp+A0h] [xbp-40h]
  unsigned __int8 *v330; // [xsp+A8h] [xbp-38h]
  unsigned int v331; // [xsp+A8h] [xbp-38h]
  const void *v332; // [xsp+B0h] [xbp-30h]
  _QWORD v333[2]; // [xsp+B8h] [xbp-28h] BYREF
  char v334[4]; // [xsp+C8h] [xbp-18h] BYREF
  char v335[4]; // [xsp+CCh] [xbp-14h] BYREF
  __int64 v336; // [xsp+D0h] [xbp-10h]

  v336 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = qdf_mem_malloc_atomic_fl(0x828u, (__int64)"util_scan_gen_scan_entry", 0xA32u);
  if ( !v14 )
  {
    v120 = 2;
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
    goto LABEL_290;
  }
  v23 = (__int64)v14;
  v24 = qdf_mem_malloc_atomic_fl(a3, (__int64)"util_scan_gen_scan_entry", 0xA39u);
  *(_QWORD *)(v23 + 1896) = v24;
  if ( !v24 )
  {
    v120 = 2;
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
    goto LABEL_290;
  }
  v332 = a6;
  *(_QWORD *)(v23 + 1296) = ktime_get_with_offset(1);
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
  *(_DWORD *)(v23 + 1256) = a5[10];
  *(_BYTE *)(v23 + 1904) = *(_BYTE *)(a1 + 40);
  v35 = *a5;
  *(_DWORD *)(v23 + 2080) = *a5;
  qdf_mem_copy((void *)(v23 + 1288), a5 + 3, 4u);
  v36 = wlan_reg_freq_to_band(v35);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 80) + 21LL) & 0x80) == 0 )
  {
    v37 = *(unsigned __int8 *)(v23 + 1288);
    v38 = *(unsigned __int8 *)(v23 + 1289);
    v39 = *(unsigned __int8 *)(v23 + 1290);
    v40 = v37 == 128;
    v41 = v37 - 96;
    if ( v40 )
      v41 = -1;
    v40 = v38 == 128;
    v42 = v38 - 96;
    *(_BYTE *)(v23 + 1288) = v41;
    v43 = *(unsigned __int8 *)(v23 + 1291);
    if ( v40 )
      v42 = -1;
    *(_BYTE *)(v23 + 1289) = v42;
    v44 = v39 - 96;
    if ( v39 == 128 )
      v44 = -1;
    v40 = v43 == 128;
    v45 = v43 - 96;
    if ( v40 )
      v45 = -1;
    *(_BYTE *)(v23 + 1290) = v44;
    *(_BYTE *)(v23 + 1291) = v45;
  }
  v46 = "_disconn_pipes_per_inst";
  *(_DWORD *)(v23 + 1304) = jiffies;
  v47 = a2[16];
  if ( !v47 )
    v47 = 100;
  *(_WORD *)(v23 + 68) = v47;
  *(_WORD *)(v23 + 70) = a2[17];
  qdf_mem_copy((void *)(v23 + 72), a2 + 12, 8u);
  *(_BYTE *)(v23 + 80) = 1;
  system_time = qdf_mc_timer_get_system_time();
  v49 = *(void **)(v23 + 1896);
  *(_QWORD *)(v23 + 88) = system_time;
  *(_DWORD *)(v23 + 1888) = a3;
  qdf_mem_copy(v49, a2, (unsigned int)a3);
  v58 = *(_QWORD *)(a1 + 80);
  if ( !v58 )
  {
    v121 = "util_scan_populate_bcn_ie_list";
    goto LABEL_278;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v58, 3u);
  if ( !comp_private_obj )
  {
    v122 = "util_scan_populate_bcn_ie_list";
    v123 = "util_scan_populate_bcn_ie_list";
    v124 = 1504;
    goto LABEL_280;
  }
  v61 = 1LL << v36;
  v62 = (unsigned __int16)(*(_WORD *)(v23 + 1888) - 36);
  if ( v62 < 2 )
  {
    v63 = 0;
LABEL_282:
    if ( !*(_QWORD *)(v23 + 1872) )
      goto LABEL_286;
    goto LABEL_283;
  }
  v63 = 0;
  v64 = 0;
  v65 = (__int64 *)(v23 + 1840);
  v66 = (_QWORD *)(v23 + 1816);
  v67 = *(_QWORD *)(v23 + 1896) + 36LL;
  v68 = (_QWORD *)(v23 + 1664);
  v69 = (_QWORD *)(v23 + 1656);
  v70 = (_QWORD *)(v23 + 1336);
  v60 = v23 + 1584;
  while ( 2 )
  {
    v71 = 0;
    v72 = v62;
    while ( 1 )
    {
      v73 = (_BYTE *)(v67 + v71);
      v74 = *(unsigned __int8 *)(v67 + v71 + 1);
      if ( *(_BYTE *)(v67 + v71 + 1) )
        break;
      v72 -= 2;
      v71 += 2;
      if ( v72 <= 1 )
        goto LABEL_282;
    }
    if ( v62 - (unsigned int)v71 - 2 < v74 )
    {
      v167 = *(unsigned __int8 *)(v23 + 1);
      v168 = *(unsigned __int8 *)(v23 + 2);
      v169 = *(unsigned __int8 *)(v23 + 3);
      v170 = *(unsigned __int8 *)(v23 + 6);
      v171 = *(unsigned __int8 *)(v67 + v71);
      if ( *(_BYTE *)(comp_private_obj + 23986) != 1 )
      {
        v172 = "%s: %02x:%02x:%02x:**:**:%02x: Scan not allowed with incomplete corrupted IE:%x, ie_len: %d, ie->ie_len: "
               "%d, stop processing further";
        LODWORD(v287) = *(unsigned __int8 *)(v67 + v71 + 1);
        LODWORD(v286) = v62 - 2 - v71;
        goto LABEL_457;
      }
      LODWORD(v285) = *(unsigned __int8 *)(v67 + v71);
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x: Scan allowed with incomplete corrupted IE:%x, ie_len: %d, ie->ie_len: %d, stop pr"
        "ocessing further",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "util_scan_populate_bcn_ie_list",
        v167,
        v168,
        v169,
        v170,
        v285,
        v62 - 2 - v71,
        *(unsigned __int8 *)(v67 + v71 + 1));
      if ( !*(_QWORD *)(v23 + 1872) )
        goto LABEL_286;
LABEL_283:
      if ( !*(_QWORD *)(v23 + 1864) && !*(_QWORD *)(v23 + 1880) )
        *(_QWORD *)(v23 + 1872) = 0;
LABEL_286:
      v71 = *(_QWORD *)(v23 + 1344);
      if ( v71 && *(unsigned __int8 *)(v71 + 1) >= 0x21u )
        goto LABEL_288;
      if ( *(_QWORD *)(v23 + 1520) )
        *(_BYTE *)(v23 + 85) = 1;
      if ( v63 )
        goto LABEL_294;
      v134 = *(_QWORD *)(v23 + 1696);
      if ( !v134 )
      {
        v63 = 0;
        goto LABEL_295;
      }
      v141 = *(_QWORD *)(a1 + 80);
      if ( v141 )
      {
        v142 = wlan_objmgr_psoc_get_comp_private_obj(v141, 3u);
        if ( v142 )
        {
          v63 = 0;
          if ( !*(_QWORD *)(v23 + 1696) )
            goto LABEL_471;
          v143 = *(unsigned __int8 **)(v23 + 1712);
          LOBYTE(v134) = 0;
          if ( !v143 )
            goto LABEL_295;
          v144 = v143[1];
          v145 = v144 - 7;
          if ( v144 >= 7 && (v143[5] & 2) != 0 && (_BYTE)v144 != 7 )
          {
            v134 = v143[4];
            if ( (v134 & 0x40) == 0 )
            {
              v146 = 9;
              goto LABEL_464;
            }
            if ( (unsigned __int8)(v144 - 7) >= 4u )
            {
              v145 = v144 - 10;
              v146 = 12;
LABEL_464:
              v63 = 0;
              if ( (unsigned __int8)(v145 + ((unsigned int)(char)v134 >> 7)) >= 5u )
              {
                v236 = &v143[v146 + (v134 >> 7)];
                LOBYTE(v134) = 0;
                if ( !v236 )
                  goto LABEL_295;
                v237 = v35;
                v238 = a1;
                v239 = v142;
                v240 = wlan_reg_chan_band_to_freq(v238, *v236, v61, v50, v51, v52, v53, v54, v55, v56, v57);
                v241 = *(unsigned __int8 *)(v239 + 18740);
                v242 = v240;
                if ( v241 == 1
                  && (wlan_reg_is_freq_enabled(v238, v240, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
                {
                  v247 = v242;
                  v248 = jiffies;
                  if ( util_scan_get_chan_from_he_6g_params___last_ticks - jiffies + 125 < 0 )
                  {
                    LODWORD(v286) = v247;
                    LODWORD(v285) = *v236;
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
                      v285,
                      v286);
                    util_scan_get_chan_from_he_6g_params___last_ticks = v248;
                  }
                  goto LABEL_288;
                }
                v243 = v238;
                v294 = v242;
                if ( (v236[1] & 4) == 0 )
                {
                  LOBYTE(v134) = 0;
LABEL_470:
                  a1 = v243;
                  v63 = v294;
                  v35 = v237;
                  goto LABEL_295;
                }
                v292 = a7;
                if ( !*(_QWORD *)(v23 + 1800) )
                  goto LABEL_517;
                v245 = *(unsigned __int8 **)(v23 + 1808);
                if ( !v245 || (v245[3] & 1) == 0 )
                  goto LABEL_517;
                if ( v245[1] <= 8u )
                {
                  qdf_trace_msg(
                    0x15u,
                    2u,
                    "%s: Invalid EHT OP IE length %d with EHT OP info present",
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    v57,
                    "util_scan_is_out_of_band_leak_eht");
                  goto LABEL_517;
                }
                v252 = v245[8] & 7;
                v331 = wlan_reg_chan_band_to_freq(v243, v245[9], v61, v50, v51, v52, v53, v54, v55, v56, v57);
                v261 = (unsigned int)wlan_reg_chan_band_to_freq(
                                       v243,
                                       v245[10],
                                       v61,
                                       v253,
                                       v254,
                                       v255,
                                       v256,
                                       v257,
                                       v258,
                                       v259,
                                       v260);
                if ( v252 <= 1 )
                {
                  if ( v252 )
                  {
                    v263 = v331;
                    v262 = 40;
                    goto LABEL_513;
                  }
                }
                else
                {
                  switch ( v252 )
                  {
                    case 2:
                      v263 = v331;
                      v262 = 80;
                      goto LABEL_513;
                    case 4:
                      v262 = 320;
                      goto LABEL_512;
                    case 3:
                      v262 = 160;
LABEL_512:
                      v263 = v261;
LABEL_513:
                      v264 = v263 - v237;
                      if ( v264 < 0 )
                        v264 = -v264;
                      if ( v264 > (unsigned int)v262 >> 1 )
                      {
                        v265 = v331;
                        v266 = "util_scan_is_out_of_band_leak_eht";
                        v35 = v237;
                        v267 = v237;
                        goto LABEL_539;
                      }
LABEL_517:
                      v268 = v236[1] & 3;
                      v269 = wlan_reg_chan_band_to_freq(v243, v236[2], v61, v50, v51, v52, v53, v54, v55, v56, v57);
                      v278 = wlan_reg_chan_band_to_freq(
                               v243,
                               v236[3],
                               v61,
                               v270,
                               v271,
                               v272,
                               v273,
                               v274,
                               v275,
                               v276,
                               v277);
                      if ( v268 == 1 )
                        v279 = 40;
                      else
                        v279 = 20;
                      if ( v268 == 2 )
                        v279 = 80;
                      v261 = v278;
                      if ( v268 == 3 )
                        v262 = 160;
                      else
                        v262 = v279;
                      if ( v268 == 3 )
                      {
                        v35 = v237;
                        if ( (~v236[1] & 3) == 0 && v236[3] )
                        {
                          v280 = v236[3] - v236[2];
                          if ( v280 < 0 )
                            v280 = v236[2] - v236[3];
                          if ( v280 == 8 )
                          {
                            v281 = v278 - v237;
                            v35 = v237;
                            if ( (int)(v278 - v237) < 0 )
                              v281 = v237 - v278;
                            if ( v281 <= 0x50 )
                            {
LABEL_548:
                              LOBYTE(v134) = 1;
                              goto LABEL_549;
                            }
                          }
                          else
                          {
                            v35 = v237;
                            if ( (unsigned int)v280 >= 9 )
                            {
                              v283 = v269 - v237;
                              if ( (int)(v269 - v237) < 0 )
                                v283 = v237 - v269;
                              if ( v283 < 0x29 )
                              {
                                a7 = v292;
                                LOBYTE(v134) = 1;
                                goto LABEL_470;
                              }
                              v284 = v278 - v237;
                              v35 = v237;
                              if ( (int)(v278 - v237) < 0 )
                                v284 = v237 - v278;
                              if ( v284 < 0x29 )
                                goto LABEL_548;
                            }
                          }
                        }
                      }
                      else
                      {
                        v282 = v269 - v237;
                        v35 = v237;
                        if ( (int)(v269 - v237) < 0 )
                          v282 = v237 - v269;
                        if ( v282 <= v279 >> 1 )
                          goto LABEL_548;
                      }
                      v266 = "util_scan_is_out_of_band_leak_he";
                      v267 = v35;
                      v265 = v269;
LABEL_539:
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
                        v266,
                        v267,
                        v262,
                        v265,
                        v261);
                      LOBYTE(v134) = 0;
LABEL_549:
                      a7 = v292;
                      a1 = v243;
                      v63 = v294;
                      goto LABEL_295;
                  }
                }
                v263 = v331;
                v262 = 20;
                goto LABEL_513;
              }
LABEL_471:
              LOBYTE(v134) = 0;
              goto LABEL_295;
            }
          }
          v63 = 0;
LABEL_294:
          LOBYTE(v134) = 0;
LABEL_295:
          v135 = *(_QWORD *)(v23 + 1696);
          *(_BYTE *)(v23 + 2084) = 9;
          if ( v135 )
          {
            v136 = *(unsigned __int8 **)(v23 + 1712);
            if ( v136 )
            {
              v137 = v136[1];
              v138 = v137 - 7;
              if ( v137 >= 7 && (v136[5] & 2) != 0 && (_BYTE)v137 != 7 )
              {
                v139 = v136[4];
                if ( (v139 & 0x40) != 0 )
                {
                  if ( (unsigned __int8)(v137 - 7) < 4u )
                    goto LABEL_320;
                  v138 = v137 - 10;
                  v140 = 12;
                }
                else
                {
                  v140 = 9;
                }
                if ( (unsigned __int8)(v138 + ((unsigned int)(char)v139 >> 7)) >= 5u )
                {
                  v147 = &v136[v140 + (v139 >> 7)];
                  if ( v147 )
                    *(_BYTE *)(v23 + 2084) = (v147[1] >> 3) & 0xF;
                }
              }
            }
          }
LABEL_320:
          if ( v63 )
          {
            *(_DWORD *)(v23 + 1192) = v63;
          }
          else
          {
            v63 = *(_DWORD *)(v23 + 1192);
            if ( !v63 )
            {
              *(_DWORD *)(v23 + 1192) = v35;
              if ( !v71 )
                goto LABEL_336;
              goto LABEL_328;
            }
          }
          if ( v35 == v63 )
            LOBYTE(v134) = 1;
          if ( (v134 & 1) == 0 )
            *(_BYTE *)(v23 + 1216) = 1;
          if ( !v71 )
            goto LABEL_336;
LABEL_328:
          v148 = *(unsigned __int8 *)(v71 + 1);
          if ( *(_BYTE *)(v71 + 1) )
          {
            v149 = 0;
            v150 = (const void *)(v71 + 2);
            while ( v149 != 32 )
            {
              if ( *((_BYTE *)v150 + v149) )
              {
                qdf_mem_copy((void *)(v23 + 14), v150, v148);
                v151 = *(_QWORD *)(v23 + 88);
                *(_BYTE *)(v23 + 13) = *(_BYTE *)(v71 + 1);
                *(_QWORD *)(v23 + 104) = v151;
                goto LABEL_337;
              }
              if ( v148 == ++v149 )
                goto LABEL_336;
            }
            goto LABEL_550;
          }
LABEL_336:
          *(_QWORD *)(v23 + 1344) = 0;
          *(_BYTE *)(v23 + 46) = 1;
LABEL_337:
          qdf_mem_copy((void *)(v23 + 112), v332, 0x12u);
          phymode = util_scan_get_phymode(a1, v23);
          v161 = *(_QWORD *)(v23 + 1696);
          *(_DWORD *)(v23 + 52) = phymode;
          *(_DWORD *)(v23 + 2076) = phymode;
          if ( v161 )
          {
            if ( v161 + 22 > v161 + (unsigned __int64)*(unsigned __int8 *)(v161 + 1) + 2 )
            {
              qdf_trace_msg(
                0x15u,
                8u,
                "%s: mcs_map_offset exceeds he cap len",
                v153,
                v154,
                v155,
                v156,
                v157,
                v158,
                v159,
                v160,
                "util_scan_scm_calc_nss_supported_by_ap");
LABEL_340:
              v162 = 1;
              goto LABEL_367;
            }
            v164 = (unsigned __int16 *)(v161 + 20);
          }
          else
          {
            v163 = *(_QWORD *)(v23 + 1560);
            if ( !v163 )
            {
              v166 = *(_BYTE **)(v23 + 1456);
              if ( !v166 )
                goto LABEL_340;
              if ( !v166[6] )
              {
                if ( !v166[5] )
                {
                  if ( !v166[4] )
                    goto LABEL_340;
LABEL_366:
                  v162 = 2;
LABEL_367:
                  v173 = *(_QWORD *)(v23 + 1776);
                  *(_BYTE *)(v23 + 84) = v162;
                  if ( v173 )
                    *(_BYTE *)(v23 + 86) = *(_BYTE *)(v173 + 4) & 1;
                  if ( *(_QWORD *)(v23 + 1400) )
                    *(_BYTE *)(v23 + 47) |= 2u;
                  if ( *(_QWORD *)(v23 + 1416) )
                    *(_BYTE *)(v23 + 47) |= 8u;
                  if ( *(_QWORD *)(v23 + 1512) )
                    *(_BYTE *)(v23 + 47) |= 4u;
                  if ( *(_QWORD *)(v23 + 1864) || *(_QWORD *)(v23 + 1880) )
                  {
                    v174 = *(_BYTE *)(v23 + 47) | 0x10;
                  }
                  else
                  {
                    if ( *(_BYTE *)(v23 + 47) || (*(_WORD *)(v23 + 70) & 0x10) == 0 )
                    {
LABEL_379:
                      v175 = *(_QWORD *)(v23 + 1736);
                      memset(v333, 0, 15);
                      if ( v175 )
                      {
                        v176 = a1;
                        v177 = *(unsigned __int8 *)(v175 + 1) - 1LL;
                        if ( v177 <= 0xE )
                        {
                          if ( v177 >= 3 )
                          {
                            v179 = (_BYTE *)(v175 + 3);
                            v180 = 1;
                            v181 = ((unsigned __int64)*(unsigned __int8 *)(v175 + 1) - 1) / 3;
                            while ( (unsigned __int64)v179 < v175 + (unsigned __int64)*(unsigned __int8 *)(v175 + 1) )
                            {
                              v182 = (char *)v333 + 3;
                              v183 = *v179 & 3;
                              if ( (*v179 & 3) != 0 )
                              {
                                v182 = (char *)&v333[1] + 1;
                                if ( v183 != 2 )
                                {
                                  v182 = (char *)v333 + 6;
                                  if ( v183 != 1 )
                                  {
                                    qdf_mem_copy((char *)&v333[1] + 4, v179, 3u);
                                    break;
                                  }
                                }
                              }
                              qdf_mem_copy(v182, v179, 3u);
                              v94 = v181 > v180++;
                              v179 += 3;
                              if ( !v94 )
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
                            v153,
                            v154,
                            v155,
                            v156,
                            v157,
                            v158,
                            v159,
                            v160,
                            "util_scan_update_esp_data");
                        }
                        if ( (BYTE6(v333[0]) & 3) == 1 )
                        {
                          v178 = HIBYTE(v333[0]);
                          a1 = v176;
                        }
                        else
                        {
                          a1 = v176;
                          if ( (BYTE1(v333[1]) & 3) == 2 )
                          {
                            v178 = BYTE2(v333[1]);
                          }
                          else if ( (~BYTE4(v333[1]) & 3) != 0 )
                          {
                            if ( (v333[0] & 0x3000000LL) != 0 )
                              v178 = 0;
                            else
                              v178 = BYTE4(v333[0]);
                          }
                          else
                          {
                            v178 = BYTE5(v333[1]);
                          }
                        }
                        *(_BYTE *)(v23 + 82) = v178;
                      }
                      v184 = *(_QWORD *)(v23 + 1504);
                      if ( v184 )
                        *(_BYTE *)(v23 + 83) = *(_BYTE *)(v184 + 4);
                      v185 = qdf_mem_malloc_atomic_fl(0x20u, (__int64)"util_scan_gen_scan_entry", 0xACBu);
                      if ( !v185 )
                      {
                        _qdf_mem_free(*(_QWORD *)(v23 + 1896));
                        _qdf_mem_free(v23);
                        qdf_trace_msg(
                          0x15u,
                          2u,
                          "%s: failed to allocate memory for scan_node",
                          v200,
                          v201,
                          v202,
                          v203,
                          v204,
                          v205,
                          v206,
                          v207,
                          "util_scan_gen_scan_entry");
                        goto LABEL_289;
                      }
                      v194 = v185;
                      if ( (unsigned int)(*(_DWORD *)(v23 + 52) - 31) >= 0xA )
                      {
                        if ( *(_QWORD *)(v23 + 1800) || *(_QWORD *)(v23 + 1824) )
                        {
                          qdf_trace_msg(
                            0x15u,
                            8u,
                            "%s: EHT cap present but phymode %d not EHT, reset eht info",
                            v186,
                            v187,
                            v188,
                            v189,
                            v190,
                            v191,
                            v192,
                            v193,
                            "util_scan_gen_scan_entry");
                          *(_QWORD *)(v23 + 1824) = 0;
                          *(_QWORD *)(v23 + 1800) = 0;
                          *(_QWORD *)(v23 + 1808) = 0;
                        }
                        *(_BYTE *)(v23 + 1919) = -1;
                        goto LABEL_420;
                      }
                      v195 = *(_QWORD *)(v23 + 1800);
                      v196 = *(_QWORD *)(v23 + 1824);
                      v334[0] = 1;
                      *(_BYTE *)(v23 + 1919) = -1;
                      if ( v195 )
                      {
                        if ( !v196 )
                          goto LABEL_420;
                        util_get_link_info_offset(v196, v334);
                        if ( (v334[0] & 1) != 0 )
                        {
                          v324 = a1;
                          v197 = *(_WORD *)(v196 + 3);
                          v198 = v196 + *(unsigned __int8 *)(v196 + 1) + 2;
                          if ( v196 + 12 <= v198 )
                          {
                            qdf_mem_copy((void *)(v23 + 1912), (const void *)(v196 + 6), 6u);
                            v199 = 12;
                          }
                          else
                          {
                            v199 = 6;
                          }
                          *(_BYTE *)(v23 + 1918) = 0;
                          if ( (v197 & 0x10) != 0 )
                          {
                            v208 = (_BYTE *)(v196 + v199);
                            if ( (unsigned __int64)v208 < v198 )
                              *(_BYTE *)(v23 + 1919) = *v208 & 0xF;
                          }
                          v209 = *(_QWORD *)(v23 + 1824);
                          LOBYTE(v333[0]) = 0;
                          link_info_offset = util_get_link_info_offset(v209, v333);
                          v335[0] = 0;
                          v211 = *(_QWORD *)(v23 + 1336);
                          v212 = *(unsigned __int8 *)(v209 + 1);
                          v322 = v209;
                          v329 = link_info_offset;
                          if ( v211 )
                          {
                            v213 = *(unsigned __int8 *)(v211 + 1);
                            v214 = (unsigned __int8 *)(v211 + 2);
                            if ( !v213 )
                              v214 = nullptr;
                            v330 = v214;
                          }
                          else
                          {
                            v330 = nullptr;
                          }
                          v215 = 0;
                          v216 = 0;
                          v71 = 0;
                          v326 = v212 + 2;
                          do
                          {
                            if ( v216 >= *(unsigned __int8 *)(v23 + 132) || (unsigned int)v71 > 2 )
                              break;
                            if ( *(_BYTE *)(v23 + v215 + 162) == 1 && !*(_BYTE *)(v23 + v215 + 163) )
                            {
                              v221 = v23 + v215;
                              v222 = v23 + 1920 + 48LL * (unsigned int)v71;
                              v223 = *(_DWORD *)(v23 + v215 + 148);
                              *(_WORD *)(v222 + 4) = *(_WORD *)(v23 + v215 + 152);
                              *(_DWORD *)v222 = v223;
                              *(_BYTE *)(v222 + 10) = *(_BYTE *)(v23 + v215 + 164) & 0xF;
                              v224 = wlan_reg_chan_opclass_to_freq_prefer_global(
                                       v324,
                                       v330,
                                       *(_DWORD *)(v23 + v215 + 140),
                                       *(_DWORD *)(v23 + v215 + 144),
                                       v50,
                                       v51,
                                       v52,
                                       v53,
                                       v54,
                                       v55,
                                       v56,
                                       v57);
                              *(_WORD *)(v222 + 6) = v224;
                              if ( !v224 )
                              {
                                v225 = jiffies;
                                if ( util_update_partner_info_from_rnr___last_ticks - jiffies + 125 < 0 )
                                {
                                  if ( v23 + v215 == -148 )
                                  {
                                    v217 = 0;
                                    v218 = 0;
                                    v219 = 0;
                                    v220 = 0;
                                  }
                                  else
                                  {
                                    v218 = *(unsigned __int8 *)(v23 + v215 + 148);
                                    v219 = *(unsigned __int8 *)(v23 + v215 + 149);
                                    v217 = *(unsigned __int8 *)(v23 + v215 + 150);
                                    v220 = *(unsigned __int8 *)(v23 + v215 + 153);
                                  }
                                  LODWORD(v286) = v220;
                                  LODWORD(v285) = v217;
                                  qdf_trace_msg(
                                    0x15u,
                                    8u,
                                    "%s: freq 0 rnr channel %u op_class %u %02x:%02x:%02x:**:**:%02x",
                                    v50,
                                    v51,
                                    v52,
                                    v53,
                                    v54,
                                    v55,
                                    v56,
                                    v57,
                                    "util_update_partner_info_from_rnr",
                                    *(unsigned int *)(v221 + 140),
                                    *(unsigned int *)(v221 + 144),
                                    v218,
                                    v219,
                                    v285,
                                    v286);
                                  util_update_partner_info_from_rnr___last_ticks = v225;
                                }
                              }
                              v71 = (unsigned int)(v71 + 1);
                              *(_BYTE *)(v222 + 41) = *(_DWORD *)(v221 + 144);
                            }
                            v215 += 32;
                            ++v216;
                          }
                          while ( v215 != 1056 );
                          *(_BYTE *)(v23 + 1918) = v71;
                          if ( !v329 || (unsigned __int64)v329 + 4 >= v326 )
                          {
                            v230 = jiffies;
                            if ( util_get_ml_bv_partner_link_info___last_ticks - jiffies + 125 < 0 )
                            {
                              qdf_trace_msg(
                                0x15u,
                                8u,
                                "%s: incorrect offset value %d",
                                v50,
                                v51,
                                v52,
                                v53,
                                v54,
                                v55,
                                v56,
                                v57,
                                "util_get_ml_bv_partner_link_info",
                                v329);
                              util_get_ml_bv_partner_link_info___last_ticks = v230;
                            }
                            goto LABEL_420;
                          }
                          v226 = (_BYTE *)(v322 + v329);
                          if ( *v226 )
                          {
LABEL_420:
                            v194[3] = v23;
                            qdf_list_insert_front(a7, v194);
                            v120 = 0;
                            goto LABEL_290;
                          }
                          v227 = (unsigned __int8)v226[1];
                          v228 = (unsigned __int64)&v226[v227 + 2];
                          if ( v228 > v322 + v326 )
                          {
                            v229 = jiffies;
                            if ( *(unsigned __int8 *)(v322 + 1) == 255 )
                            {
                              if ( util_get_ml_bv_partner_link_info___last_ticks_68 - jiffies + 125 < 0 )
                              {
                                qdf_trace_msg(
                                  0x15u,
                                  8u,
                                  "%s: Possible fragmentation in ml_ie for tag_len %d. Ignore the processing",
                                  v50,
                                  v51,
                                  v52,
                                  v53,
                                  v54,
                                  v55,
                                  v56,
                                  v57,
                                  "util_get_ml_bv_partner_link_info",
                                  255);
                                util_get_ml_bv_partner_link_info___last_ticks_68 = v229;
                              }
                            }
                            else if ( util_get_ml_bv_partner_link_info___last_ticks_70 - jiffies + 125 < 0 )
                            {
                              qdf_trace_msg(
                                0x15u,
                                8u,
                                "%s: perstaprof exceeds ML IE boundary for tag_len %d. Ignore the processing",
                                v50,
                                v51,
                                v52,
                                v53,
                                v54,
                                v55,
                                v56,
                                v57,
                                "util_get_ml_bv_partner_link_info");
                              util_get_ml_bv_partner_link_info___last_ticks_70 = v229;
                            }
                            goto LABEL_420;
                          }
                          v60 = *(unsigned __int8 *)(v322 + (unsigned __int8)(v329 + 4));
                          v233 = (unsigned __int8)(v60 + v329 + 4);
                          if ( v326 <= v233 )
                          {
                            v244 = jiffies;
                            if ( util_get_ml_bv_partner_link_info___last_ticks_72 - jiffies + 125 < 0 )
                            {
                              qdf_trace_msg(
                                0x15u,
                                2u,
                                "%s: incorrect offset value %d",
                                v50,
                                v51,
                                v52,
                                v53,
                                v54,
                                v55,
                                v56,
                                v57,
                                "util_get_ml_bv_partner_link_info",
                                (unsigned __int8)(v60 + v329 + 4));
                              util_get_ml_bv_partner_link_info___last_ticks_72 = v244;
                            }
                            goto LABEL_420;
                          }
                          a1 = v322 + v233;
                          v234 = *(_WORD *)(v322 + (unsigned __int8)(v329 + 2));
                          if ( (int)v60 + 2 >= (unsigned int)v227 )
                          {
                            v246 = jiffies;
                            if ( util_get_ml_bv_partner_link_info___last_ticks_73 - jiffies + 125 < 0 )
                            {
                              qdf_trace_msg(
                                0x15u,
                                8u,
                                "%s: No STA profile IE list found for perstaprof_stainfo_len %d perstaprof_len %d",
                                v50,
                                v51,
                                v52,
                                v53,
                                v54,
                                v55,
                                v56,
                                v57,
                                "util_get_ml_bv_partner_link_info");
                              v71 = *(unsigned __int8 *)(v23 + 1918);
                              v235 = 0;
                              util_get_ml_bv_partner_link_info___last_ticks_73 = v246;
LABEL_489:
                              if ( (_DWORD)v71 )
                              {
                                if ( (unsigned int)(v71 - 4) < 0xFFFFFFFD )
                                {
LABEL_550:
                                  __break(0x5512u);
LABEL_551:
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
                                    "util_scan_parse_vendor_ie",
                                    v60);
                                  v67 = a1;
                                  goto LABEL_456;
                                }
                                v250 = v234 & 0xF;
                                if ( v250 == *(unsigned __int8 *)(v23 + 1930) )
                                  v251 = (_QWORD *)(v23 + 1920);
                                else
                                  v251 = nullptr;
                                if ( (_DWORD)v71 != 1 )
                                {
                                  if ( v250 == *(unsigned __int8 *)(v23 + 1978) )
                                    v251 = (_QWORD *)(v23 + 1968);
                                  if ( (_DWORD)v71 != 2 && v250 == *(unsigned __int8 *)(v23 + 2026) )
                                    v251 = (_QWORD *)(v23 + 2016);
                                }
                                if ( v251 )
                                {
                                  v251[2] = wlan_get_ie_ptr_from_eid(0x25u, (unsigned __int8 *)a1, v235);
                                  v251[3] = wlan_get_ie_ptr_from_eid(0x3Cu, (unsigned __int8 *)a1, v235);
                                  v335[0] = 52;
                                  v251[4] = wlan_get_ext_ie_ptr_from_ext_id(v335, 1u, (unsigned __int8 *)a1, v235);
                                }
                              }
                              goto LABEL_420;
                            }
                          }
                          else if ( a1 <= v228 )
                          {
                            v235 = v227 - (v60 + 2);
                            goto LABEL_489;
                          }
                          v235 = 0;
                          goto LABEL_489;
                        }
                      }
                      else if ( !v196 )
                      {
                        goto LABEL_420;
                      }
                      *(_QWORD *)(v23 + 1824) = 0;
                      goto LABEL_420;
                    }
                    v174 = 1;
                  }
                  *(_BYTE *)(v23 + 47) = v174;
                  goto LABEL_379;
                }
LABEL_360:
                v162 = 3;
                goto LABEL_367;
              }
LABEL_355:
              v162 = 4;
              goto LABEL_367;
            }
            v164 = (unsigned __int16 *)(v163 + 6);
          }
          v165 = *v164;
          if ( (~v165 & 0xC000) != 0 )
          {
            v162 = 8;
            goto LABEL_367;
          }
          if ( (~v165 & 0x3000) != 0 )
          {
            v162 = 7;
            goto LABEL_367;
          }
          if ( (~v165 & 0xC00) != 0 )
          {
            v162 = 6;
            goto LABEL_367;
          }
          if ( (~v165 & 0x300) != 0 )
          {
            v162 = 5;
            goto LABEL_367;
          }
          if ( (~v165 & 0xC0) == 0 )
          {
            if ( (~v165 & 0x30) == 0 )
            {
              if ( (~v165 & 0xC) == 0 )
                goto LABEL_340;
              goto LABEL_366;
            }
            goto LABEL_360;
          }
          goto LABEL_355;
        }
        v122 = "util_scan_get_chan_from_he_6g_params";
        v123 = "util_scan_get_chan_from_he_6g_params";
        v124 = 608;
LABEL_280:
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
          v123,
          v124);
        qdf_trace_msg(0x15u, 2u, "%s: scan_obj is NULL", v125, v126, v127, v128, v129, v130, v131, v132, v122);
        goto LABEL_288;
      }
      v121 = "util_scan_get_chan_from_he_6g_params";
LABEL_278:
      qdf_trace_msg(0x15u, 2u, "%s: psoc is NULL", v50, v51, v52, v53, v54, v55, v56, v57, v121);
      goto LABEL_288;
    }
    v323 = a1;
    switch ( *v73 )
    {
      case 0:
        if ( v74 > 0x20 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1344) = v73;
        goto LABEL_200;
      case 1:
        if ( v74 > 0xC )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1352) = v73;
        goto LABEL_200;
      case 3:
        v298 = v60;
        v301 = v70;
        v304 = v69;
        v307 = v68;
        v310 = v66;
        v313 = v65;
        v316 = v64;
        v319 = v62;
        if ( v74 != 1 )
          goto LABEL_288;
        v82 = v35;
        *(_QWORD *)(v23 + 1368) = v73;
        v83 = comp_private_obj;
        v295 = v67;
        v327 = *(unsigned __int8 *)(v67 + v71 + 2);
        v63 = wlan_reg_chan_band_to_freq(v323, v327, v61, v50, v51, v52, v53, v54, v55, v56, v57);
        if ( *(_BYTE *)(v83 + 18740) == 1
          && (wlan_reg_is_freq_enabled(v323, v63, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
        {
          v167 = *(unsigned __int8 *)(v23 + 1);
          v168 = *(unsigned __int8 *)(v23 + 2);
          v169 = *(unsigned __int8 *)(v23 + 3);
          v170 = *(unsigned __int8 *)(v23 + 6);
          v172 = "%s: %02x:%02x:%02x:**:**:%02x: Drop as invalid chan %d in DS IE, freq %d, band_mask %d";
          LODWORD(v287) = (unsigned __int8)v61;
          LODWORD(v286) = v63;
          LODWORD(v285) = v327;
          goto LABEL_458;
        }
        comp_private_obj = v83;
        goto LABEL_118;
      case 5:
        if ( v74 < 4 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1328) = v73;
        *(_BYTE *)(v23 + 81) = *(_BYTE *)(v67 + v71 + 3);
        goto LABEL_200;
      case 7:
        if ( v74 < 3 )
          goto LABEL_456;
        *v70 = v73;
        goto LABEL_200;
      case 0xB:
        if ( v74 == 5 )
          *(_QWORD *)(v23 + 1504) = v73;
        goto LABEL_200;
      case 0x25:
        if ( v74 != 3 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1376) = v73;
        goto LABEL_200;
      case 0x28:
        if ( v74 != 6 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1448) = v73;
        goto LABEL_200;
      case 0x29:
        if ( v74 < 7 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1544) = v73;
        goto LABEL_200;
      case 0x2A:
        if ( v74 != 1 )
          goto LABEL_456;
        *(_BYTE *)(v23 + 80) = *(_BYTE *)(v67 + v71 + 2);
        goto LABEL_200;
      case 0x2D:
        if ( v74 == 26 )
          *(_QWORD *)(v23 + 1456) = v67 + v71 + 2;
        goto LABEL_200;
      case 0x30:
        if ( v74 != 1 )
          *(_QWORD *)(v23 + 1416) = v73;
        goto LABEL_200;
      case 0x32:
        if ( v74 > 0xC )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1360) = v73;
        goto LABEL_200;
      case 0x36:
        if ( v74 != 3 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1688) = v73;
        goto LABEL_200;
      case 0x3C:
        if ( v74 != 4 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1384) = v73;
        goto LABEL_200;
      case 0x3D:
        if ( v74 != 22 )
          goto LABEL_456;
        v82 = v35;
        v304 = v69;
        v307 = v68;
        *(_QWORD *)(v23 + 1464) = v67 + v71 + 2;
        v102 = comp_private_obj;
        v103 = *(unsigned __int8 *)(v67 + v71 + 2);
        v298 = v60;
        v301 = v70;
        v310 = v66;
        v313 = v65;
        v316 = v64;
        v319 = v62;
        v295 = v67;
        v104 = comp_private_obj;
        v105 = wlan_reg_chan_band_to_freq(v323, v103, v61, v50, v51, v52, v53, v54, v55, v56, v57);
        if ( *(_BYTE *)(v104 + 18740) == 1 )
        {
          v106 = v103;
          v63 = v105;
          if ( (wlan_reg_is_freq_enabled(v323, v105, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
          {
            v249 = jiffies;
            if ( util_scan_populate_bcn_ie_list___last_ticks - jiffies + 125 < 0 )
            {
              LODWORD(v285) = v106;
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
                v285,
                v63);
              util_scan_populate_bcn_ie_list___last_ticks = v249;
            }
            goto LABEL_288;
          }
          comp_private_obj = v104;
          v46 = "_disconn_pipes_per_inst";
LABEL_118:
          v35 = v82;
        }
        else
        {
          comp_private_obj = v102;
          v46 = "_disconn_pipes_per_inst";
          v63 = v105;
        }
        v67 = v295;
        v60 = v298;
        v64 = v316;
        v62 = v319;
        v68 = v307;
        v66 = v310;
        v70 = v301;
        v69 = v304;
        v65 = v313;
        goto LABEL_200;
      case 0x3E:
        if ( v74 != 1 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1680) = v73;
        goto LABEL_200;
      case 0x44:
        if ( v74 < 0x14 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1512) = v73;
        goto LABEL_200;
      case 0x7F:
        if ( v74 > 0xF )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1536) = v73;
        goto LABEL_200;
      case 0xBF:
        if ( v74 != 12 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1560) = v73;
        goto LABEL_200;
      case 0xC0:
        if ( v74 != 5 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1568) = v73;
        goto LABEL_200;
      case 0xC3:
        if ( v74 == 1 || v64 > 7 )
          goto LABEL_456;
        *(_QWORD *)(v60 + 8LL * v64++) = v73;
        goto LABEL_200;
      case 0xC4:
        *(_QWORD *)(v23 + 1648) = v73;
        v80 = (unsigned __int8)v73[1];
        if ( v80 < 2 )
          goto LABEL_200;
        v81 = (unsigned __int8 *)(v67 + v71 + 2);
        while ( 2 )
        {
          v109 = v81[1];
          v80 -= 2LL;
          if ( !v81[1] )
            goto LABEL_140;
          if ( v80 < v109 )
          {
            v231 = *((_QWORD *)v46 + 288);
            if ( util_scan_parse_chan_switch_wrapper_ie___last_ticks - v231 + 125 < 0 )
            {
              LODWORD(v285) = 196;
              v232 = v67;
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
                v285);
              v67 = v232;
              util_scan_parse_chan_switch_wrapper_ie___last_ticks = v231;
            }
            goto LABEL_456;
          }
          v110 = *v81;
          if ( v110 > 0xC1 )
          {
            if ( v110 == 194 )
            {
              v107 = (unsigned int)v109 >= 3;
              v108 = v69;
              if ( !v107 )
                goto LABEL_456;
            }
            else
            {
              if ( v110 != 195 )
                goto LABEL_139;
              v40 = (_DWORD)v109 == 1;
              v108 = v68;
              if ( v40 )
                goto LABEL_456;
            }
          }
          else if ( v110 == 7 )
          {
            v107 = (unsigned int)v109 >= 3;
            v108 = v70;
            if ( !v107 )
              goto LABEL_456;
          }
          else
          {
            if ( v110 != 135 )
              goto LABEL_139;
            v94 = (unsigned int)v109 > 9;
            v108 = v66;
            if ( v94 )
              goto LABEL_456;
          }
          *v108 = v81;
          v109 = v81[1];
LABEL_139:
          v81 += v109;
          v80 -= v109;
LABEL_140:
          v81 += 2;
          if ( v80 <= 1 )
            goto LABEL_200;
          continue;
        }
      case 0xC7:
        if ( v74 != 1 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1576) = v73;
        goto LABEL_200;
      case 0xC9:
        if ( v74 < 5 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1760) = v73;
        v84 = *(unsigned __int8 *)(v23 + 132);
        v293 = v63;
        v85 = (_BYTE *)(v67 + v71 + 6);
        v86 = v67 + v71 + (unsigned __int8)v73[1] + 2;
        if ( (unsigned __int64)v85 > v86 )
          goto LABEL_157;
        v289 = v35;
        v87 = (unsigned __int16 *)(v67 + v71 + 2);
        v299 = v60;
        v302 = v70;
        v305 = v69;
        v308 = v68;
        v311 = v66;
        v314 = v65;
        v317 = v64;
        v320 = v62;
        v296 = v67;
        v288 = v61;
        v290 = comp_private_obj;
        v291 = a7;
        while ( 1 )
        {
          v89 = *v87;
          v90 = (unsigned __int8)v89 >> 4;
          v91 = v89 >> 8;
          LODWORD(v285) = v89 & 3;
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
            *((unsigned __int8 *)v87 + 3),
            *((unsigned __int8 *)v87 + 2),
            (unsigned __int8)v89 >> 4,
            (unsigned int)(v89 >> 8),
            v285);
          v92 = v91;
          v93 = 0;
          v325 = v91;
          v328 = v90;
          while ( 1 )
          {
            v88 = &v85[v92];
            if ( (unsigned __int64)&v85[v92] > v86 )
              break;
            if ( v84 <= 0x20 )
            {
              v95 = v84;
              v96 = v86;
              ++v84;
              v97 = HIBYTE(*v87);
              if ( (unsigned int)v97 > 0x10 )
                v97 = 16;
              v98 = v23 + 136 + 32 * v95;
              if ( v97 > 8 )
              {
                if ( v97 > 11 )
                {
                  switch ( v97 )
                  {
                    case 12:
                      goto LABEL_92;
                    case 13:
                      goto LABEL_91;
                    case 16:
                      qdf_mem_copy((void *)(v98 + 27), v85 + 13, 3u);
                      *(_BYTE *)(v98 + 26) = 1;
LABEL_91:
                      *(_BYTE *)(v98 + 25) = v85[12];
LABEL_92:
                      *(_BYTE *)(v98 + 24) = v85[11];
LABEL_95:
                      *(_DWORD *)(v98 + 4) = *((unsigned __int8 *)v87 + 3);
                      *(_DWORD *)(v98 + 8) = *((unsigned __int8 *)v87 + 2);
                      qdf_mem_copy((void *)(v98 + 12), v85 + 1, 6u);
                      v99 = (void *)(v98 + 20);
                      v100 = v85 + 7;
LABEL_103:
                      v101 = 4;
LABEL_104:
                      qdf_mem_copy(v99, v100, v101);
LABEL_105:
                      v86 = v96;
                      v90 = v328;
                      v92 = v325;
                      goto LABEL_75;
                  }
LABEL_97:
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
                  goto LABEL_105;
                }
                if ( v97 != 9 )
                {
                  if ( v97 == 11 )
                    goto LABEL_95;
                  goto LABEL_97;
                }
                *(_BYTE *)(v98 + 25) = v85[8];
LABEL_99:
                *(_BYTE *)(v98 + 24) = v85[7];
LABEL_100:
                v99 = (void *)(v98 + 12);
                v100 = v85 + 1;
                v101 = 6;
                *(_DWORD *)(v98 + 4) = *((unsigned __int8 *)v87 + 3);
                *(_DWORD *)(v98 + 8) = *((unsigned __int8 *)v87 + 2);
                goto LABEL_104;
              }
              if ( v97 > 5 )
              {
                if ( v97 != 6 )
                {
                  if ( v97 != 7 )
                    goto LABEL_99;
                  goto LABEL_100;
                }
                *(_BYTE *)(v98 + 24) = v85[5];
LABEL_102:
                v99 = (void *)(v98 + 20);
                v100 = v85 + 1;
                *(_DWORD *)(v98 + 4) = *((unsigned __int8 *)v87 + 3);
                *(_DWORD *)(v98 + 8) = *((unsigned __int8 *)v87 + 2);
                goto LABEL_103;
              }
              if ( (unsigned int)(v97 - 1) >= 2 )
              {
                if ( v97 != 5 )
                  goto LABEL_97;
                goto LABEL_102;
              }
              v86 = v96;
              v90 = v328;
            }
LABEL_75:
            v94 = v90 > v93++;
            v85 = v88;
            if ( !v94 )
              goto LABEL_71;
          }
          v88 = v85;
LABEL_71:
          v85 = v88 + 4;
          v87 = (unsigned __int16 *)v88;
          if ( (unsigned __int64)(v88 + 4) > v86 )
          {
            comp_private_obj = v290;
            a7 = v291;
            v67 = v296;
            v60 = v299;
            v64 = v317;
            v62 = v320;
            v68 = v308;
            v66 = v311;
            v70 = v302;
            v69 = v305;
            v35 = v289;
            v61 = v288;
            v65 = v314;
LABEL_157:
            v63 = v293;
            *(_BYTE *)(v23 + 132) = v84;
            v46 = "_disconn_pipes_per_inst";
            goto LABEL_200;
          }
        }
      case 0xDD:
        if ( !*(_QWORD *)(v23 + 1496) )
        {
          *(_QWORD *)(v23 + 1496) = v73;
          v74 = (unsigned __int8)v73[1];
        }
        if ( v74 < 4 )
          goto LABEL_200;
        v76 = (int *)(v67 + v71 + 2);
        v75 = *v76;
        if ( *v76 == 82989056 )
        {
          *(_QWORD *)(v23 + 1424) = v73;
          if ( (unsigned __int8)v73[1] >= 5u && *v76 == 82989056 )
            *(_QWORD *)(v23 + 1408) = v73;
          goto LABEL_200;
        }
        if ( v75 == 32657408 )
        {
          *(_QWORD *)(v23 + 1400) = v73;
          goto LABEL_200;
        }
        if ( v74 >= 6 && v75 == 49434624 )
        {
          if ( !*(_BYTE *)(v67 + v71 + 6) )
          {
            *(_QWORD *)(v23 + 1432) = v73;
            goto LABEL_200;
          }
          if ( *(_BYTE *)(v67 + v71 + 6) != 1 )
            goto LABEL_200;
          if ( v74 <= 0x18 )
          {
            *(_QWORD *)(v23 + 1440) = v73;
            goto LABEL_200;
          }
          goto LABEL_456;
        }
        if ( v75 == 75432704 )
        {
          if ( v74 <= 0xA )
          {
            *(_QWORD *)(v23 + 1480) = v73;
            goto LABEL_200;
          }
          goto LABEL_456;
        }
        if ( v75 == 25101056 )
        {
          if ( v74 <= 9 )
          {
            *(_QWORD *)(v23 + 1472) = v73;
            goto LABEL_200;
          }
          goto LABEL_456;
        }
        a1 = v67;
        if ( v74 == 4 )
        {
          if ( v75 <= 860655615 )
          {
            if ( v75 == 161115984 )
            {
LABEL_229:
              *(_QWORD *)(v23 + 1520) = v73;
              goto LABEL_200;
            }
            if ( v75 != 379219792 )
              goto LABEL_200;
LABEL_217:
            *(_QWORD *)(v23 + 1744) = v73;
            goto LABEL_200;
          }
          if ( v75 == 860655616 )
          {
            v118 = *(_QWORD *)(v23 + 1456);
          }
          else
          {
            if ( v75 != 877432832 )
              goto LABEL_200;
            v118 = *(_QWORD *)(v23 + 1464);
          }
          if ( v118 )
            goto LABEL_200;
          goto LABEL_456;
        }
        if ( v75 <= 345391103 )
        {
          if ( v75 == 15793548 )
          {
            if ( !*(_BYTE *)(v67 + v71 + 6) )
              *(_QWORD *)(v23 + 1552) = v73;
            goto LABEL_200;
          }
          if ( v75 == 161115984 )
            goto LABEL_229;
        }
        else
        {
          switch ( v75 )
          {
            case 877432832:
              if ( *(_QWORD *)(v23 + 1464) )
                goto LABEL_200;
              if ( v74 == 26 )
              {
                *(_QWORD *)(v23 + 1464) = v67 + v71 + 6;
                goto LABEL_200;
              }
              goto LABEL_456;
            case 860655616:
              if ( *(_QWORD *)(v23 + 1456) )
                goto LABEL_200;
              if ( v74 == 30 )
              {
                *(_QWORD *)(v23 + 1456) = v67 + v71 + 6;
                goto LABEL_200;
              }
              goto LABEL_456;
            case 345391104:
              if ( v74 <= 5 )
              {
                *(_QWORD *)(v23 + 1488) = v73;
                goto LABEL_200;
              }
              goto LABEL_456;
          }
        }
        if ( v74 >= 0xD && v75 == 72126464 )
        {
          if ( (*(_BYTE *)(v67 + v71 + 6) & 0xEF) != 8 || *(_QWORD *)(v23 + 1560) )
            goto LABEL_200;
          if ( v74 >= 0x13 && *(_BYTE *)(v67 + v71 + 8) == 12 )
          {
            *(_QWORD *)(v23 + 1560) = v67 + v71 + 7;
            v119 = (unsigned __int8)v73[1];
            if ( v119 < 0x14 )
              goto LABEL_200;
            if ( v119 >= 0x1A && *(_BYTE *)(v67 + v71 + 22) == 5 )
            {
              *(_QWORD *)(v23 + 1568) = v67 + v71 + 21;
              goto LABEL_200;
            }
          }
          goto LABEL_456;
        }
        if ( v75 <= 379219791 )
        {
          if ( v75 > 66125195 )
          {
            if ( v75 == 66125196 )
            {
              *(_QWORD *)(v23 + 1768) = v73;
            }
            else if ( v75 == 92209920 && v74 >= 8 )
            {
              *(_QWORD *)(v23 + 1672) = v67 + v71 + 8;
            }
            goto LABEL_200;
          }
          if ( v75 == 32570764 )
          {
            *(_QWORD *)(v23 + 1856) = v73;
            goto LABEL_200;
          }
          if ( v75 == 60178432 )
          {
            if ( v74 - 9 > 0xFFFFFFFA )
            {
              *(_QWORD *)(v23 + 1784) = v76;
              goto LABEL_200;
            }
            goto LABEL_551;
          }
LABEL_200:
          v117 = (unsigned __int8)v73[1];
          a1 = v323;
          v62 = v62 - v117 - v71 - 2;
          v67 += v71 + v117 + 2;
          if ( v62 <= 1 )
            goto LABEL_282;
          continue;
        }
        if ( v75 <= 714764111 )
        {
          if ( v75 != 379219792 )
          {
            if ( v75 == 697986896 )
              *(_QWORD *)(v23 + 1864) = v73;
            goto LABEL_200;
          }
          goto LABEL_217;
        }
        if ( v75 == 714764112 )
        {
          *(_QWORD *)(v23 + 1880) = v73;
          goto LABEL_200;
        }
        if ( v75 == 731541328 )
        {
          *(_QWORD *)(v23 + 1872) = v73;
          goto LABEL_200;
        }
        if ( v75 != 748044288 )
          goto LABEL_200;
        if ( v74 - 9 >= 0xFFFFFFFB )
        {
          *(_QWORD *)(v23 + 1776) = v76;
          goto LABEL_200;
        }
LABEL_456:
        v167 = *(unsigned __int8 *)(v23 + 1);
        v168 = *(unsigned __int8 *)(v23 + 2);
        v169 = *(unsigned __int8 *)(v23 + 3);
        v170 = *(unsigned __int8 *)(v23 + 6);
        v172 = "%s: %02x:%02x:%02x:**:**:%02x: failed to parse IE - id: %d, len: %d";
        v171 = *(unsigned __int8 *)(v67 + v71);
        LODWORD(v286) = *(unsigned __int8 *)(v67 + v71 + 1);
LABEL_457:
        LODWORD(v285) = v171;
LABEL_458:
        qdf_trace_msg(
          0x15u,
          8u,
          v172,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "util_scan_populate_bcn_ie_list",
          v167,
          v168,
          v169,
          v170,
          v285,
          v286,
          v287);
LABEL_288:
        _qdf_mem_free(*(_QWORD *)(v23 + 1896));
        _qdf_mem_free(v23);
LABEL_289:
        v120 = 16;
LABEL_290:
        _ReadStatusReg(SP_EL0);
        return v120;
      case 0xF0:
        if ( v74 == 1 )
          goto LABEL_456;
        *(_QWORD *)(v23 + 1728) = v73;
        goto LABEL_200;
      case 0xF4:
        *(_QWORD *)(v23 + 1792) = v73;
        goto LABEL_200;
      case 0xFF:
        v77 = v67 + v71;
        v78 = *(unsigned __int8 *)(v67 + v71 + 2);
        if ( v78 <= 0x25 )
        {
          switch ( v78 )
          {
            case 0xBu:
              v79 = 1736;
              break;
            case 0x23u:
              if ( v74 - 56 < 0xFFFFFFDE )
                goto LABEL_456;
              v79 = 1696;
              break;
            case 0x24u:
              if ( v74 > 0x10 )
                goto LABEL_456;
              v79 = 1712;
              break;
            default:
              goto LABEL_186;
          }
        }
        else if ( *(unsigned __int8 *)(v67 + v71 + 2) > 0x33u )
        {
          if ( v78 == 59 )
          {
            if ( v74 > 3 )
              goto LABEL_456;
            v79 = 1704;
          }
          else
          {
            if ( v78 != 52 )
              goto LABEL_186;
            if ( v74 != 4 )
              goto LABEL_456;
            v79 = 1392;
          }
        }
        else if ( v78 == 38 )
        {
          if ( v74 > 0xE )
            goto LABEL_456;
          v79 = 1752;
        }
        else
        {
          if ( v78 != 39 )
            goto LABEL_186;
          if ( v74 > 0x15 )
            goto LABEL_456;
          v79 = 1720;
        }
        *(_QWORD *)(v23 + v79) = v73;
        v78 = *(unsigned __int8 *)(v77 + 2);
LABEL_186:
        if ( v78 == 108 )
        {
          v111 = 1800;
        }
        else
        {
          if ( v78 != 106 )
            goto LABEL_191;
          v111 = 1808;
        }
        *(_QWORD *)(v23 + v111) = v73;
        v78 = *(unsigned __int8 *)(v77 + 2);
LABEL_191:
        if ( v78 != 107 )
          goto LABEL_195;
        LODWORD(v333[0]) = 0;
        v112 = v61;
        v113 = v35;
        v306 = v69;
        v309 = v68;
        v114 = v46;
        v115 = comp_private_obj;
        v300 = v60;
        v303 = v70;
        v312 = v66;
        v315 = v65;
        v318 = v64;
        v321 = v62;
        v297 = v67;
        if ( (unsigned int)util_get_mlie_variant(v67 + v71, (unsigned __int8)v73[1] + 2LL, v333) )
        {
          qdf_trace_msg(
            0x15u,
            2u,
            "%s: Unable to get ml variant",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "util_scan_parse_ml_ie");
LABEL_194:
          v67 = v297;
          v60 = v300;
          comp_private_obj = v115;
          v64 = v318;
          v62 = v321;
          v68 = v309;
          v66 = v312;
          v46 = v114;
          v70 = v303;
          v69 = v306;
          v35 = v113;
          v65 = v315;
          v61 = v112;
          goto LABEL_195;
        }
        if ( LODWORD(v333[0]) == 2 )
        {
          *(_QWORD *)(v23 + 1832) = v73;
          goto LABEL_194;
        }
        v67 = v297;
        v60 = v300;
        comp_private_obj = v115;
        v64 = v318;
        v62 = v321;
        v68 = v309;
        v66 = v312;
        v46 = v114;
        v70 = v303;
        v69 = v306;
        v35 = v113;
        v65 = v315;
        v61 = v112;
        if ( !LODWORD(v333[0]) )
          *(_QWORD *)(v23 + 1824) = v73;
LABEL_195:
        if ( *(_BYTE *)(v77 + 2) != 109 )
          goto LABEL_200;
        v116 = *v65;
        if ( *v65 )
        {
          if ( *(_QWORD *)(v23 + 1848) )
            goto LABEL_200;
          v116 = 1;
        }
        v65[v116] = (__int64)v73;
        goto LABEL_200;
      default:
        goto LABEL_200;
    }
  }
}
