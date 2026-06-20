__int64 __fastcall pe_roam_synch_callback(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        unsigned __int16 a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v16; // w23
  __int64 session_by_vdev_id; // x0
  __int64 v19; // x20
  int *v20; // x28
  unsigned __int16 v21; // w9
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  const char *v31; // x2
  __int64 v32; // x0
  int v33; // w8
  unsigned __int16 v34; // w9
  __int64 v35; // x22
  unsigned int v36; // w25
  __int64 v37; // x24
  unsigned int v38; // w27
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x28
  char v48; // w25
  unsigned int v49; // w24
  unsigned __int8 *v50; // x24
  int v51; // w9
  int v52; // w10
  int v53; // w11
  int v54; // w12
  __int64 v55; // x3
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int v72; // w25
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x0
  int v82; // w9
  size_t v83; // x2
  char v84; // w8
  int v85; // w8
  __int64 v86; // x8
  __int64 v87; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v96; // w24
  int v97; // w25
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // w9
  _QWORD *v107; // x8
  unsigned int v108; // w27
  __int64 v109; // x24
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  const char *v119; // x2
  unsigned int v120; // w27
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  size_t v129; // x27
  void *v130; // x0
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  __int64 v139; // x4
  __int64 v140; // x5
  __int64 v141; // x6
  __int64 v142; // x7
  __int64 v143; // x4
  __int64 v144; // x25
  unsigned int v145; // w27
  unsigned int v146; // w24
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  __int64 v155; // x4
  const char *v156; // x2
  _DWORD *v157; // x0
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  unsigned int v166; // w27
  __int64 v167; // x28
  __int64 v168; // x25
  __int64 v169; // x0
  __int64 v170; // x0
  const char *v171; // x2
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  __int64 v180; // x0
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  __int64 v189; // x24
  _BYTE *v190; // x27
  char v191; // w9
  unsigned int v192; // w25
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  size_t v209; // x2
  unsigned __int8 *v210; // x28
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  __int64 v219; // x0
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  char v228; // w9
  __int64 v229; // x23
  __int64 v230; // x0
  __int64 v231; // x3
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  __int64 v240; // x26
  __int64 v241; // x25
  double v242; // d0
  double v243; // d1
  double v244; // d2
  double v245; // d3
  double v246; // d4
  double v247; // d5
  double v248; // d6
  double v249; // d7
  __int64 v250; // x4
  __int64 v251; // x5
  __int64 v252; // x6
  __int64 v253; // x7
  unsigned int ielen_from_bss_description; // w0
  double v255; // d0
  double v256; // d1
  double v257; // d2
  double v258; // d3
  double v259; // d4
  double v260; // d5
  double v261; // d6
  double v262; // d7
  char v263; // w8
  unsigned int v264; // w22
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  double v273; // d0
  double v274; // d1
  double v275; // d2
  double v276; // d3
  double v277; // d4
  double v278; // d5
  double v279; // d6
  double v280; // d7
  unsigned __int16 v281; // w22
  double v282; // d0
  double v283; // d1
  double v284; // d2
  double v285; // d3
  double v286; // d4
  double v287; // d5
  double v288; // d6
  double v289; // d7
  void *v290; // x0
  size_t v291; // x2
  size_t v292; // x2
  __int64 v293; // x8
  __int64 v294; // x9
  int v295; // w8
  __int64 v296; // x1
  unsigned int v297; // w0
  double v298; // d0
  double v299; // d1
  double v300; // d2
  double v301; // d3
  double v302; // d4
  double v303; // d5
  double v304; // d6
  double v305; // d7
  double v306; // d0
  double v307; // d1
  double v308; // d2
  double v309; // d3
  double v310; // d4
  double v311; // d5
  double v312; // d6
  double v313; // d7
  int v314; // w9
  __int64 v315; // x0
  double v316; // d0
  double v317; // d1
  double v318; // d2
  double v319; // d3
  double v320; // d4
  double v321; // d5
  double v322; // d6
  double v323; // d7
  __int64 v324; // [xsp+0h] [xbp-130h]
  __int64 v325; // [xsp+0h] [xbp-130h]
  __int64 v326; // [xsp+0h] [xbp-130h]
  __int64 v327; // [xsp+8h] [xbp-128h]
  __int64 v328; // [xsp+8h] [xbp-128h]
  __int64 v329; // [xsp+10h] [xbp-120h]
  char v330; // [xsp+2Ch] [xbp-104h]
  void *v331; // [xsp+30h] [xbp-100h]
  unsigned int v332; // [xsp+38h] [xbp-F8h]
  int v333; // [xsp+40h] [xbp-F0h]
  unsigned int v334; // [xsp+44h] [xbp-ECh]
  unsigned __int8 *v335; // [xsp+48h] [xbp-E8h]
  unsigned int v336; // [xsp+54h] [xbp-DCh]
  _QWORD *v337; // [xsp+58h] [xbp-D8h]
  __int64 v338; // [xsp+60h] [xbp-D0h]
  char v339[4]; // [xsp+6Ch] [xbp-C4h] BYREF
  unsigned __int16 v340[2]; // [xsp+70h] [xbp-C0h] BYREF
  char v341[4]; // [xsp+74h] [xbp-BCh] BYREF
  __int64 v342; // [xsp+78h] [xbp-B8h] BYREF
  __int64 v343; // [xsp+80h] [xbp-B0h]
  __int64 v344; // [xsp+88h] [xbp-A8h]
  __int64 v345; // [xsp+90h] [xbp-A0h]
  _QWORD *v346; // [xsp+98h] [xbp-98h] BYREF
  _QWORD *v347; // [xsp+A0h] [xbp-90h] BYREF
  int v348; // [xsp+A8h] [xbp-88h] BYREF
  unsigned __int16 v349; // [xsp+ACh] [xbp-84h]
  int v350; // [xsp+B0h] [xbp-80h] BYREF
  unsigned __int16 v351; // [xsp+B4h] [xbp-7Ch]
  __int64 v352; // [xsp+C0h] [xbp-70h] BYREF
  __int64 v353; // [xsp+C8h] [xbp-68h]
  __int64 v354; // [xsp+D0h] [xbp-60h]
  __int64 v355; // [xsp+D8h] [xbp-58h]
  __int64 v356; // [xsp+E0h] [xbp-50h]
  __int64 v357; // [xsp+E8h] [xbp-48h]
  __int64 v358; // [xsp+F0h] [xbp-40h]
  __int64 v359; // [xsp+F8h] [xbp-38h]
  __int64 v360; // [xsp+100h] [xbp-30h]
  __int64 v361; // [xsp+108h] [xbp-28h]
  __int64 v362; // [xsp+110h] [xbp-20h]
  __int64 v363; // [xsp+118h] [xbp-18h]
  __int64 v364; // [xsp+120h] [xbp-10h]

  v364 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v341[0] = 0;
  v340[0] = 0;
  v339[0] = 0;
  if ( !a3 )
  {
    v31 = "%s: LFR3:roam_sync_ind_ptr is NULL";
LABEL_14:
    qdf_trace_msg(0x35u, 2u, v31, a6, a7, a8, a9, a10, a11, a12, a13, "pe_roam_synch_callback");
    goto LABEL_15;
  }
  v16 = a2;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( !session_by_vdev_id )
  {
    v31 = "%s: LFR3:Unable to find session";
    goto LABEL_14;
  }
  v19 = session_by_vdev_id;
  if ( *(_DWORD *)(session_by_vdev_id + 88) != 2 )
  {
    v31 = "%s: LFR3:session is not in STA mode";
    goto LABEL_14;
  }
  v20 = (int *)(a3 + 7);
  v21 = a3[9];
  v348 = *(_DWORD *)(a3 + 7);
  v349 = v21;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: LFR3: PE callback reason: %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "pe_roam_synch_callback",
    a5);
  if ( a5 != 1 )
  {
    if ( a5 == 4 )
    {
      if ( *(_BYTE *)(v19 + 10009) == 1 )
        lim_perform_deauth(a1, v19, *(unsigned __int16 *)(v19 + 10012), v19 + 24, 0);
      if ( *(_BYTE *)(v19 + 10010) == 1 )
      {
        lim_disassoc_tdls_peers(a1, v19, v19 + 24);
        lim_perform_disassoc(a1, 0, *(unsigned __int16 *)(v19 + 10012), v19, v19 + 24);
      }
      goto LABEL_10;
    }
LABEL_15:
    result = 16;
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: LFR3:Received ROAM SYNCH IND bssid %02x:%02x:%02x:**:**:%02x auth: %d vdevId: %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "pe_roam_synch_callback",
    *((unsigned __int8 *)a3 + 14),
    *((unsigned __int8 *)a3 + 15),
    *((unsigned __int8 *)a3 + 16),
    *((unsigned __int8 *)a3 + 19),
    *((_DWORD *)a3 + 14),
    (unsigned __int8)v16);
  if ( *(_DWORD *)(v19 + 80) != 10 )
  {
    v31 = "%s: LFR3: Not in Link est state";
    goto LABEL_14;
  }
  v32 = _qdf_mem_malloc(a4 + 108LL, "pe_roam_synch_callback", 3148);
  if ( !v32 )
  {
    result = 4294967294LL;
    goto LABEL_16;
  }
  v33 = *v20;
  v34 = a3[9];
  v35 = v32;
  v36 = *(unsigned __int8 *)(v19 + 10);
  v37 = *a3;
  v38 = a3[1];
  v344 = 0;
  v345 = 0;
  v342 = 0;
  v343 = 0;
  v350 = v33;
  v351 = v34;
  v338 = _qdf_mem_malloc(0xD80u, "lim_roam_fill_bss_descr", 2407);
  if ( !v338 )
  {
    v47 = 0;
    v48 = 0;
    v49 = 2;
    goto LABEL_89;
  }
  if ( v38 <= 0x18 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: very few bytes in synchInd %s beacon / probe resp frame! length: %d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "lim_roam_fill_bss_descr",
      &unk_8B9E43,
      v38);
    v47 = v338;
LABEL_88:
    v48 = 0;
    v49 = 16;
    goto LABEL_89;
  }
  v50 = (unsigned __int8 *)a3 + v37;
  v334 = v36;
  if ( v50 == (unsigned __int8 *)-16LL )
  {
    v53 = 0;
    v51 = 0;
    v52 = 0;
    v54 = 0;
  }
  else
  {
    v51 = v50[16];
    v52 = v50[17];
    v53 = v50[18];
    v54 = v50[21];
  }
  LODWORD(v327) = v51;
  LODWORD(v324) = HIBYTE(v351);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: LFR3:Beacon/Prb Rsp: %d bssid %02x:%02x:%02x:**:**:%02x beacon %02x:%02x:%02x:**:**:%02x",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "lim_roam_fill_bss_descr",
    *((unsigned __int8 *)a3 + 12),
    (unsigned __int8)v350,
    BYTE1(v350),
    BYTE2(v350),
    v324,
    v327,
    v52,
    v53,
    v54);
  mgmt_txrx_frame_hex_dump((__int64)v50, v38, 0, v55, v56, v57, v58, v59, v60, v61, v62, v63);
  if ( !(*((_DWORD *)v50 + 4) | *((unsigned __int16 *)v50 + 10)) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: bssid is 0 in beacon/probe update it with bssId%02x:%02x:%02x:**:**:%02xin sync ind",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "lim_roam_gen_beacon_descr",
      (unsigned __int8)v350,
      BYTE1(v350),
      BYTE2(v350),
      HIBYTE(v351));
    qdf_mem_copy(v50 + 16, &v350, 6u);
  }
  v72 = *((unsigned __int8 *)a3 + 12);
  if ( !(unsigned int)qdf_mem_cmp(&v350, v50 + 16, 6u) )
  {
    if ( v72 )
    {
      v47 = v338;
      if ( (unsigned int)sir_parse_beacon_ie(a1, v338) || !*(_BYTE *)(v338 + 2460) )
      {
        v119 = "%s: Parse error Beacon, length: %d";
LABEL_53:
        qdf_trace_msg(0x35u, 2u, v119, v111, v112, v113, v114, v115, v116, v117, v118, "lim_roam_gen_beacon_descr", v38);
        goto LABEL_86;
      }
    }
    else
    {
      v47 = v338;
      if ( (unsigned int)sir_convert_probe_frame2_struct(a1, (int)v50 + 24, v38 - 24, v338) || !*(_BYTE *)(v338 + 2460) )
      {
        v119 = "%s: Parse error ProbeResponse, length: %d";
        goto LABEL_53;
      }
    }
    v333 = v72;
    if ( v38 < 0x25 )
    {
      v331 = nullptr;
      LODWORD(v129) = 0;
      goto LABEL_120;
    }
    v129 = v38 - 36;
    v130 = (void *)_qdf_mem_malloc(v129, "lim_roam_gen_beacon_descr", 2345);
    if ( v130 )
    {
      v331 = v130;
      qdf_mem_copy(v130, v50 + 36, (unsigned int)v129);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: beacon/probe Ie length: %d",
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        "lim_roam_gen_beacon_descr",
        (unsigned int)v129);
      goto LABEL_120;
    }
LABEL_86:
    v171 = "%s: Failed to parse beacon";
LABEL_87:
    qdf_trace_msg(0x35u, 2u, v171, v121, v122, v123, v124, v125, v126, v127, v128, "lim_roam_fill_bss_descr");
    goto LABEL_88;
  }
  v333 = v72;
  v335 = v50;
  LODWORD(v325) = v50[21];
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: LFR3:MBSSID Beacon/Prb Rsp: %d bssid %02x:%02x:%02x:**:**:%02x",
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    "lim_roam_gen_beacon_descr",
    *((unsigned __int8 *)a3 + 12),
    v50[16],
    v50[17],
    v50[18],
    v325);
  v81 = *(_QWORD *)(a1 + 21560);
  v362 = 0;
  v363 = 0;
  v360 = 0;
  v361 = 0;
  v82 = *((char *)a3 + 60);
  v83 = a3[1];
  v358 = 0;
  v359 = 0;
  v356 = 0;
  v357 = 0;
  v84 = *(_BYTE *)(v81 + 40);
  v352 = 0;
  v353 = 0;
  HIDWORD(v356) = v82;
  LOBYTE(v358) = v84;
  v85 = *((_DWORD *)a3 + 16);
  v354 = 0;
  v355 = 0;
  LODWORD(v352) = v85;
  v86 = *a3;
  v347 = nullptr;
  HIDWORD(v353) = -1;
  v346 = nullptr;
  v87 = util_scan_unpack_beacon_frame(v81, (_BYTE *)a3 + v86, v83, 0x80u, (__int64)&v352);
  if ( !v87 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: failed to parse",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "lim_roam_gen_mbssid_beacon");
    goto LABEL_48;
  }
  v96 = *(_DWORD *)(v87 + 16);
  v337 = (_QWORD *)v87;
  v97 = qdf_list_peek_front((_QWORD *)v87, &v346);
  v106 = (unsigned __int8)v96;
  v330 = v96;
  v336 = (unsigned __int8)v96;
  if ( v97 || (v107 = v346) == nullptr )
  {
    v120 = (unsigned __int8)v96;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: list peek front failure. list size %d",
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      "lim_roam_gen_mbssid_beacon",
      (unsigned __int8)v96);
LABEL_50:
    v331 = nullptr;
    v332 = 0;
  }
  else
  {
    if ( (unsigned __int8)v96 >= 2u )
    {
      v108 = 1;
      while ( 1 )
      {
        v109 = v107[3];
        if ( *v20 == *(_DWORD *)(v109 + 1) && a3[9] == *(unsigned __int16 *)(v109 + 5) )
          break;
        v97 = qdf_list_peek_next(v337, v346, &v347);
        if ( v97 || (v107 = v347) == nullptr )
        {
          v143 = v108;
          v120 = v336;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: list remove failure i:%d, lsize:%d",
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            "lim_roam_gen_mbssid_beacon",
            v143,
            v336);
          goto LABEL_50;
        }
        v106 = v336;
        ++v108;
        v346 = v347;
        if ( v336 == v108 )
          goto LABEL_69;
      }
      if ( v109 == -1 )
      {
        v141 = 0;
        v139 = 0;
        v140 = 0;
        v142 = 0;
      }
      else
      {
        v139 = *(unsigned __int8 *)(v109 + 1);
        v140 = *(unsigned __int8 *)(v109 + 2);
        v141 = *(unsigned __int8 *)(v109 + 3);
        v142 = *(unsigned __int8 *)(v109 + 6);
      }
      LODWORD(v328) = v336;
      LODWORD(v325) = *(_DWORD *)(v109 + 1704);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: matched BSSID %02x:%02x:%02x:**:**:%02x bcn len %d profiles %d",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "lim_roam_gen_mbssid_beacon",
        v139,
        v140,
        v141,
        v142,
        v325,
        v328);
      v144 = *(_QWORD *)(v109 + 1712);
      v145 = *(_DWORD *)(v109 + 1704);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, v144, v145);
      v106 = v336;
      if ( v145 )
      {
        if ( *((_BYTE *)a3 + 12) )
        {
          v47 = v338;
          v146 = v145 - 36;
          if ( (unsigned int)sir_parse_beacon_ie(a1, v338) || !*(_BYTE *)(v338 + 2460) )
          {
            v155 = a3[1];
            v156 = "%s: Parse error Beacon, length: %d";
LABEL_140:
            qdf_trace_msg(
              0x35u,
              2u,
              v156,
              v147,
              v148,
              v149,
              v150,
              v151,
              v152,
              v153,
              v154,
              "lim_roam_gen_mbssid_beacon",
              v155);
            v331 = nullptr;
            v332 = 0;
            v97 = 16;
            goto LABEL_141;
          }
        }
        else
        {
          v47 = v338;
          if ( (unsigned int)sir_convert_probe_frame2_struct(a1, (int)v144 + 24, v145 - 24, v338)
            || !*(_BYTE *)(v338 + 2460) )
          {
            v155 = a3[1];
            v156 = "%s: Parse error ProbeResponse, length: %d";
            goto LABEL_140;
          }
          v146 = v145 - 36;
        }
        if ( !v146 )
        {
          v331 = nullptr;
          v332 = 0;
          goto LABEL_151;
        }
        v331 = (void *)_qdf_mem_malloc(v146, "lim_roam_gen_mbssid_beacon", 2247);
        if ( v331 )
        {
          qdf_mem_copy(v331, (const void *)(v144 + 36), v146);
          v332 = v146;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: beacon/probe Ie length: %d",
            v316,
            v317,
            v318,
            v319,
            v320,
            v321,
            v322,
            v323,
            "lim_roam_gen_mbssid_beacon",
            v146);
LABEL_151:
          v47 = v338;
          v97 = 0;
LABEL_141:
          v50 = v335;
          v157 = v337;
          if ( !v336 )
            goto LABEL_84;
          goto LABEL_71;
        }
LABEL_48:
        v47 = v338;
LABEL_85:
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: failed to gen mbssid beacon",
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          "lim_roam_gen_beacon_descr");
        goto LABEL_86;
      }
    }
LABEL_69:
    v120 = v106;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: failed to generate/find MBSSID beacon",
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      "lim_roam_gen_mbssid_beacon");
    v331 = nullptr;
    v332 = 0;
    v97 = 0;
  }
  v47 = v338;
  v50 = v335;
  v157 = v337;
  if ( !v120 )
    goto LABEL_84;
LABEL_71:
  v97 = qdf_list_remove_front(v157, &v347);
  v166 = 0;
  if ( !v97 )
  {
    v167 = (__int64)v347;
    if ( v347 )
    {
      v166 = 0;
      while ( 1 )
      {
        v168 = *(_QWORD *)(v167 + 24);
        if ( v168 )
        {
          v169 = *(_QWORD *)(v168 + 1192);
          if ( v169 )
            _qdf_mem_free(v169);
          v170 = *(_QWORD *)(v168 + 1712);
          if ( v170 )
            _qdf_mem_free(v170);
          _qdf_mem_free(v168);
        }
        _qdf_mem_free(v167);
        if ( (unsigned __int8)(v330 - 1) == v166 )
          break;
        ++v166;
        v97 = qdf_list_remove_front(v337, &v347);
        if ( !v97 )
        {
          v167 = (__int64)v347;
          if ( v347 )
            continue;
        }
        goto LABEL_83;
      }
      _qdf_mem_free((__int64)v337);
      v47 = v338;
      v50 = v335;
      LODWORD(v129) = v332;
      goto LABEL_120;
    }
  }
LABEL_83:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: list remove failure i:%d, lsize:%d",
    v158,
    v159,
    v160,
    v161,
    v162,
    v163,
    v164,
    v165,
    "lim_roam_gen_mbssid_beacon",
    v166,
    v336);
  v157 = v337;
  v47 = v338;
  v50 = v335;
LABEL_84:
  _qdf_mem_free((__int64)v157);
  LODWORD(v129) = v332;
  if ( v97 )
    goto LABEL_85;
LABEL_120:
  if ( v333 )
  {
    v295 = *((_DWORD *)v50 + 6);
    LOWORD(v352) = 0;
    *(_DWORD *)v47 = v295;
    *(_DWORD *)(v47 + 4) = *((_DWORD *)v50 + 7);
    *(_WORD *)(v47 + 8) = *((_WORD *)v50 + 16);
    dot11f_unpack_ff_capabilities(a1, v50 + 34, &v352);
    sir_copy_caps_info(a1, (unsigned __int16)v352, v47);
  }
  *(_WORD *)v35 = v129 + 102;
  *(_BYTE *)(v35 + 48) = *((_BYTE *)a3 + 12) == 0;
  *(_BYTE *)(v35 + 24) = *((_BYTE *)a3 + 60);
  if ( (*(_BYTE *)(v47 + 2703) & 0x20) != 0 )
  {
    v297 = wlan_reg_chan_band_to_freq(
             *(_QWORD *)(a1 + 21560),
             *(unsigned __int8 *)(v47 + 2712),
             4u,
             v111,
             v112,
             v113,
             v114,
             v115,
             v116,
             v117,
             v118);
LABEL_126:
    v296 = v297;
    goto LABEL_127;
  }
  if ( *(_BYTE *)(v47 + 2465) )
  {
    v296 = *(unsigned int *)(v47 + 72);
    goto LABEL_127;
  }
  if ( *(_BYTE *)(v47 + 1260) )
  {
    v297 = wlan_reg_legacy_chan_to_freq(
             *(_QWORD *)(a1 + 21560),
             *(unsigned __int8 *)(v47 + 1261),
             v111,
             v112,
             v113,
             v114,
             v115,
             v116,
             v117,
             v118);
    goto LABEL_126;
  }
  v296 = *((unsigned int *)a3 + 16);
LABEL_127:
  *(_DWORD *)(v35 + 28) = v296;
  *(_DWORD *)(v35 + 20) = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))lim_get_nw_type)(a1, v296, 0, v47);
  *(_WORD *)(v35 + 16) = *(_WORD *)(v47 + 8);
  *(_DWORD *)(v35 + 8) = *(_DWORD *)v47;
  *(_DWORD *)(v35 + 12) = *(_DWORD *)(v47 + 4);
  *(_WORD *)(v35 + 18) = *(_WORD *)(v47 + 10);
  qdf_mem_copy((void *)(v35 + 2), &v350, 6u);
  LODWORD(v325) = *(unsigned __int8 *)(v35 + 7);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Non-tx bss desc: privacy bit: %d, bssid %02x:%02x:%02x:**:**:%02x",
    v298,
    v299,
    v300,
    v301,
    v302,
    v303,
    v304,
    v305,
    "lim_roam_fill_bss_descr",
    (*(unsigned __int16 *)(v35 + 18) >> 4) & 1,
    *(unsigned __int8 *)(v35 + 2),
    *(unsigned __int8 *)(v35 + 3),
    *(unsigned __int8 *)(v35 + 4),
    v325);
  if ( *(_BYTE *)(v47 + 2482) )
  {
    *(_BYTE *)(v35 + 44) = *(_BYTE *)(v47 + 2482);
    qdf_mem_copy((void *)(v35 + 45), (const void *)(v47 + 2446), 3u);
    v314 = *(unsigned __int16 *)(v35 + 45);
    v315 = *(_QWORD *)(a1 + 21552);
    LOBYTE(v343) = 1;
    LODWORD(v342) = v314;
    wlan_cm_roam_cfg_set_value(v315, v334, 0x14u, (unsigned int *)&v342);
  }
  LODWORD(v329) = *(unsigned __int8 *)(v35 + 47);
  LODWORD(v328) = *(unsigned __int8 *)(v35 + 46);
  LODWORD(v326) = *(unsigned __int8 *)(v35 + 45);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: chan: %d rssi: %d ie_len %d mdie_present:%d mdie = %02x %02x %02x",
    v306,
    v307,
    v308,
    v309,
    v310,
    v311,
    v312,
    v313,
    "lim_roam_fill_bss_descr",
    *(unsigned int *)(v35 + 28),
    (unsigned int)*(char *)(v35 + 24),
    (unsigned int)v129,
    *(unsigned __int8 *)(v35 + 44),
    v326,
    v328,
    v329);
  if ( !(_DWORD)v129 )
  {
    v171 = "%s: Beacon/Probe rsp doesn't have any IEs";
    goto LABEL_87;
  }
  qdf_mem_copy((void *)(v35 + 104), v331, (unsigned int)v129);
  _qdf_mem_free((__int64)v331);
  v49 = 0;
  v48 = 1;
LABEL_89:
  _qdf_mem_free(0);
  _qdf_mem_free(v47);
  if ( (v48 & 1) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: LFR3:Failed to fill Bss Descr",
      v172,
      v173,
      v174,
      v175,
      v176,
      v177,
      v178,
      v179,
      "pe_roam_synch_callback");
    _qdf_mem_free(v35);
    result = v49;
    goto LABEL_16;
  }
  v180 = ((__int64 (__fastcall *)(__int64, __int64, char *, _QWORD, _QWORD, _QWORD))pe_create_session)(
           a1,
           v35 + 2,
           v341,
           *(unsigned __int8 *)(a1 + 12272),
           *(unsigned int *)(v19 + 92),
           *(unsigned __int8 *)(v19 + 10));
  if ( !v180 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: LFR3:Cannot create PE Session bssid: %02x:%02x:%02x:**:**:%02x",
      v181,
      v182,
      v183,
      v184,
      v185,
      v186,
      v187,
      v188,
      "pe_roam_synch_callback",
      *(unsigned __int8 *)(v35 + 2),
      *(unsigned __int8 *)(v35 + 3),
      *(unsigned __int8 *)(v35 + 4),
      *(unsigned __int8 *)(v35 + 7));
    _qdf_mem_free(v35);
    goto LABEL_15;
  }
  v189 = v180;
  v190 = (_BYTE *)(v180 + 7276);
  lim_set_bcn_probe_filter(a1, v180, 0);
  *(_BYTE *)(v189 + 182) = *(_BYTE *)(v35 + 2);
  *(_BYTE *)(v189 + 183) = *(_BYTE *)(v35 + 3);
  *(_BYTE *)(v189 + 184) = *(_BYTE *)(v35 + 4);
  *(_BYTE *)(v189 + 185) = *(_BYTE *)(v35 + 5);
  *(_BYTE *)(v189 + 186) = *(_BYTE *)(v35 + 6);
  *(_BYTE *)(v189 + 187) = *(_BYTE *)(v35 + 7);
  *(_BYTE *)(v19 + 7425) = 1;
  v190[149] = 1;
  *(_DWORD *)(v189 + 88) = 2;
  v191 = *(_BYTE *)(v19 + 7276);
  *(_BYTE *)(v19 + 182) = *(_BYTE *)(v35 + 2);
  *(_BYTE *)(v19 + 183) = *(_BYTE *)(v35 + 3);
  *(_BYTE *)(v19 + 184) = *(_BYTE *)(v35 + 4);
  *(_BYTE *)(v19 + 185) = *(_BYTE *)(v35 + 5);
  *(_BYTE *)(v19 + 186) = *(_BYTE *)(v35 + 6);
  *(_BYTE *)(v19 + 187) = *(_BYTE *)(v35 + 7);
  *v190 = v191;
  v192 = lim_fill_ft_session(a1, v35, v189, v19, *((unsigned int *)a3 + 615));
  if ( v192 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to fill ft session for vdev id %d",
      v193,
      v194,
      v195,
      v196,
      v197,
      v198,
      v199,
      v200,
      "pe_roam_synch_callback",
      *(unsigned __int8 *)(v189 + 10));
LABEL_93:
    _qdf_mem_free(v35);
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Roam sync failure status %d session vdev %d",
      v201,
      v202,
      v203,
      v204,
      v205,
      v206,
      v207,
      v208,
      "pe_roam_synch_callback",
      v192,
      *(unsigned __int8 *)(v19 + 10));
LABEL_94:
    pe_delete_session(a1);
    result = v192;
    goto LABEL_16;
  }
  if ( *(unsigned __int8 *)(v189 + 36) >= 0x20u )
    v209 = 32;
  else
    v209 = *(unsigned __int8 *)(v189 + 36);
  *((_BYTE *)a3 + 20) = v209;
  qdf_mem_copy((char *)a3 + 21, (const void *)(v189 + 37), v209);
  pe_update_crypto_params(a1, v189, a3);
  wlan_mlme_set_sae_single_pmk_bss_cap(*(_QWORD *)(a1 + 21552), v16, 0);
  lim_ft_prepare_add_bss_req(a1, v189, v35);
  lim_process_tpe_ie_from_beacon(a1, v189, v35, v339);
  if ( *(_BYTE *)(v19 + 7041) == 1 )
    lim_fill_fils_ft(v19, v189);
  v210 = *(unsigned __int8 **)(v189 + 7832);
  *((_QWORD *)a3 + 34) = v210;
  lim_delete_tdls_peers(a1, v19, 1);
  wlan_tdls_notify_sta_disconnect(v16, 1, 0, *(_QWORD *)(v19 + 16));
  v219 = dph_lookup_hash_entry(
           v211,
           v212,
           v213,
           v214,
           v215,
           v216,
           v217,
           v218,
           a1,
           (unsigned __int8 *)(v19 + 24),
           v340,
           v19 + 360);
  if ( !v219 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: LFR3:failed to lookup hash entry",
      v220,
      v221,
      v222,
      v223,
      v224,
      v225,
      v226,
      v227,
      "pe_roam_synch_callback");
    v190[149] = 0;
    goto LABEL_93;
  }
  v228 = v190[1469];
  v229 = v219;
  *(_DWORD *)(v189 + 10016) = *(_DWORD *)(v19 + 10016);
  v190[1469] = v228 & 0xC0 | *(_BYTE *)(v19 + 8745) & 0x3F;
  v230 = dph_add_hash_entry(
           v220,
           v221,
           v222,
           v223,
           v224,
           v225,
           v226,
           v227,
           a1,
           (unsigned __int8 *)&v348,
           1u,
           v189 + 360);
  if ( !v230 )
  {
    if ( v210 == (unsigned __int8 *)-29LL )
    {
      v252 = 0;
      v250 = 0;
      v251 = 0;
      v253 = 0;
    }
    else
    {
      v250 = v210[29];
      v251 = v210[30];
      v252 = v210[31];
      v253 = v210[34];
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: LFR3:failed to add hash entry for %02x:%02x:%02x:**:**:%02x",
      v232,
      v233,
      v234,
      v235,
      v236,
      v237,
      v238,
      v239,
      "pe_roam_synch_callback",
      v250,
      v251,
      v252,
      v253);
    v190[149] = 0;
    goto LABEL_93;
  }
  v240 = v230;
  if ( *((_DWORD *)a3 + 14) == 2 )
    *(_BYTE *)(v230 + 641) = 1;
  v241 = a3[2];
  mgmt_txrx_frame_hex_dump((__int64)a3 + v241, a3[3], 0, v231, v232, v233, v234, v235, v236, v237, v238, v239);
  lim_process_assoc_rsp_frame(a1, (char *)a3 + v241, a3[3], 1, v189);
  if ( v190[2797] == 1 )
  {
    _qdf_mem_free(v35);
    v192 = 16;
LABEL_108:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Roam sync failure status %d session vdev %d",
      v242,
      v243,
      v244,
      v245,
      v246,
      v247,
      v248,
      v249,
      "pe_roam_synch_callback",
      v192,
      *(unsigned __int8 *)(v19 + 10));
    lim_cleanup_rx_path(a1, v240, v189, 0);
    lim_delete_dph_hash_entry(a1, v240 + 338, *(unsigned __int16 *)(v240 + 336), v189);
    goto LABEL_94;
  }
  ielen_from_bss_description = wlan_get_ielen_from_bss_description(v35);
  lim_enable_cts_to_self_for_exempted_iot_ap(a1, v189, v35 + 104, ielen_from_bss_description);
  _qdf_mem_free(v35);
  lim_check_ft_initial_im_association((__int64)a3, v189, v255, v256, v257, v258, v259, v260, v261, v262);
  lim_copy_and_free_hlp_data_from_session(v189, a3);
  a3[152] = *(_WORD *)(v189 + 180);
  *(_DWORD *)(v240 + 8) = 14;
  v263 = v190[1359];
  *(_BYTE *)(v240 + 643) = v263;
  *((_BYTE *)a3 + 392) = v263;
  *(_QWORD *)(v189 + 72) = 0xE0000000ELL;
  lim_init_tdls_data(a1, v189);
  v264 = *(_DWORD *)(v189 + 392);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: LFR3: Session RicLength: %d",
    v265,
    v266,
    v267,
    v268,
    v269,
    v270,
    v271,
    v272,
    "pe_roam_synch_callback",
    v264);
  lim_handle_sr_cap(*(_QWORD *)(v189 + 16), 0, v273, v274, v275, v276, v277, v278, v279, v280);
  v281 = *(_DWORD *)(v189 + 408) + v264;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: LFR3: tspecLen: %d",
    v282,
    v283,
    v284,
    v285,
    v286,
    v287,
    v288,
    v289,
    "pe_roam_synch_callback");
  if ( v281 )
  {
    v290 = (void *)_qdf_mem_malloc(v281, "pe_roam_synch_callback", 3309);
    *((_QWORD *)a3 + 37) = v290;
    if ( !v290 )
    {
      v192 = 2;
      v190[149] = 0;
      goto LABEL_108;
    }
    if ( *(_QWORD *)(v189 + 400) )
    {
      v291 = *(unsigned int *)(v189 + 392);
      *((_DWORD *)a3 + 72) = v291;
      qdf_mem_copy(v290, *(const void **)(v189 + 400), v291);
      _qdf_mem_free(*(_QWORD *)(v189 + 400));
      *(_QWORD *)(v189 + 400) = 0;
      *(_DWORD *)(v189 + 392) = 0;
    }
    if ( *(_QWORD *)(v189 + 416) )
    {
      v292 = *(unsigned int *)(v189 + 408);
      v293 = *((_QWORD *)a3 + 37);
      v294 = *((unsigned int *)a3 + 72);
      *((_DWORD *)a3 + 73) = v292;
      qdf_mem_copy((void *)(v293 + v294), *(const void **)(v189 + 416), v292);
      _qdf_mem_free(*(_QWORD *)(v189 + 416));
      *(_QWORD *)(v189 + 416) = 0;
      *(_DWORD *)(v189 + 408) = 0;
    }
  }
  *((_DWORD *)a3 + 70) = *(_DWORD *)(v189 + 7176);
  *((_DWORD *)a3 + 71) = lim_get_max_rate_flags(a1, v240);
  *(_QWORD *)(v189 + 80) = 0xA0000000ALL;
  v190[149] = 0;
  *(_DWORD *)(v19 + 80) = 1;
  lim_cleanup_rx_path(a1, v229, v19, 0);
  lim_delete_dph_hash_entry(a1, v229 + 338, v340[0], v19);
  pe_delete_session(a1);
LABEL_10:
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
