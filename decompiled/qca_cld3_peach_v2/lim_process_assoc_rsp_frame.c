void __fastcall lim_process_assoc_rsp_frame(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  int v13; // w8
  char v14; // w9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int8 *v28; // x23
  int v29; // w24
  __int64 v30; // x25
  int v31; // w28
  int v32; // w9
  const void *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int16 v50; // w2
  __int64 v51; // x0
  __int64 v52; // x1
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x21
  char *v79; // x28
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int16 v88; // w2
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  int v97; // w4
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  const char *v106; // x2
  __int64 v107; // x9
  __int16 v108; // w10
  __int64 v109; // x11
  __int64 v110; // x8
  __int64 v111; // x9
  __int64 v112; // x10
  __int64 v113; // x10
  __int64 v114; // x8
  __int64 v115; // x8
  __int64 v116; // x4
  __int64 v117; // x9
  __int64 v118; // x10
  __int64 v119; // x9
  __int64 v120; // x8
  __int64 v121; // x11
  __int64 v122; // x9
  void *v123; // x0
  __int64 v124; // x0
  int v125; // w28
  __int64 v126; // x8
  void *v127; // x0
  __int64 ext_hdl; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  size_t v137; // x2
  const void *v138; // x1
  __int64 v139; // x0
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  __int64 v148; // x8
  void *v149; // x0
  __int64 v150; // x0
  __int64 v151; // x0
  int v152; // w8
  char v153; // w24
  char v154; // w9
  int dlm_reject_reason; // w0
  __int64 v156; // x8
  __int64 v157; // x1
  int v158; // w26
  char rssi_denylist_threshold; // w0
  __int64 system_time; // x0
  __int64 v161; // x8
  __int64 v162; // x1
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  double v187; // d0
  double v188; // d1
  double v189; // d2
  double v190; // d3
  double v191; // d4
  double v192; // d5
  double v193; // d6
  double v194; // d7
  void *v195; // x0
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  int v204; // w8
  __int16 v205; // w9
  unsigned __int8 *v206; // x2
  __int64 v207; // x0
  __int64 v208; // x24
  bool is_vdev_roaming; // w8
  __int64 v210; // x24
  __int16 v211; // w2
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  __int64 v220; // x0
  __int64 v221; // x0
  __int64 v222; // x1
  unsigned int nss_supported_by_ap; // w24
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
  __int64 v248; // x0
  __int64 v249; // x26
  __int64 hash_entry; // x0
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  __int16 *v259; // x26
  __int64 v260; // x2
  double v261; // d0
  double v262; // d1
  double v263; // d2
  double v264; // d3
  double v265; // d4
  double v266; // d5
  double v267; // d6
  double v268; // d7
  double v269; // d0
  double v270; // d1
  double v271; // d2
  double v272; // d3
  double v273; // d4
  double v274; // d5
  double v275; // d6
  double v276; // d7
  __int64 v277; // x0
  double v278; // d0
  double v279; // d1
  double v280; // d2
  double v281; // d3
  double v282; // d4
  double v283; // d5
  double v284; // d6
  double v285; // d7
  __int64 v286; // x25
  __int64 v287; // x2
  __int64 v288; // x0
  __int64 v289; // x26
  unsigned int ielen_from_bss_description; // w0
  __int64 v291; // x27
  unsigned int v292; // w24
  double v293; // d0
  double v294; // d1
  double v295; // d2
  double v296; // d3
  double v297; // d4
  double v298; // d5
  double v299; // d6
  double v300; // d7
  int v301; // w8
  int v302; // w9
  int v303; // w9
  int v304; // w9
  int v305; // w10
  __int64 v306; // x9
  __int64 v307; // x10
  __int64 v308; // x11
  __int64 v309; // x12
  __int64 v310; // x11
  __int64 v311; // x8
  __int64 v312; // x10
  __int64 v313; // x9
  __int64 v314; // x12
  __int64 v315; // x13
  __int64 v316; // x12
  __int64 v317; // x8
  __int64 v318; // x10
  int v319; // w8
  __int64 v320; // x8
  __int64 v321; // x10
  __int64 v322; // x8
  __int64 v323; // x11
  __int64 v324; // x8
  double v325; // d0
  double v326; // d1
  double v327; // d2
  double v328; // d3
  double v329; // d4
  double v330; // d5
  double v331; // d6
  double v332; // d7
  double v333; // d0
  double v334; // d1
  double v335; // d2
  double v336; // d3
  double v337; // d4
  double v338; // d5
  double v339; // d6
  double v340; // d7
  double v341; // d0
  double v342; // d1
  double v343; // d2
  double v344; // d3
  double v345; // d4
  double v346; // d5
  double v347; // d6
  double v348; // d7
  char v349[4]; // [xsp+0h] [xbp-100h]
  __int64 v350; // [xsp+0h] [xbp-100h]
  __int16 v351[2]; // [xsp+8h] [xbp-F8h]
  __int64 v352; // [xsp+8h] [xbp-F8h]
  int v353; // [xsp+10h] [xbp-F0h]
  __int64 v354; // [xsp+10h] [xbp-F0h]
  char is_sha384_akm; // [xsp+24h] [xbp-DCh]
  int v356; // [xsp+34h] [xbp-CCh]
  char v357[4]; // [xsp+44h] [xbp-BCh] BYREF
  __int64 v358; // [xsp+48h] [xbp-B8h] BYREF
  __int16 v359; // [xsp+54h] [xbp-ACh] BYREF
  _QWORD v360[2]; // [xsp+58h] [xbp-A8h] BYREF
  __int16 v361; // [xsp+68h] [xbp-98h]
  _DWORD v362[2]; // [xsp+70h] [xbp-90h] BYREF
  __int64 v363; // [xsp+78h] [xbp-88h] BYREF
  __int64 v364; // [xsp+80h] [xbp-80h]
  __int64 v365; // [xsp+88h] [xbp-78h] BYREF
  __int64 v366; // [xsp+90h] [xbp-70h]
  __int64 v367; // [xsp+98h] [xbp-68h]
  __int64 v368; // [xsp+A0h] [xbp-60h]
  __int64 v369; // [xsp+A8h] [xbp-58h]
  __int64 v370; // [xsp+B0h] [xbp-50h]
  __int64 v371; // [xsp+B8h] [xbp-48h]
  __int64 v372; // [xsp+C0h] [xbp-40h]
  __int64 v373; // [xsp+C8h] [xbp-38h]
  __int64 v374; // [xsp+D0h] [xbp-30h]
  __int64 v375; // [xsp+D8h] [xbp-28h]
  __int64 v376; // [xsp+E0h] [xbp-20h]
  __int64 v377; // [xsp+E8h] [xbp-18h]
  __int64 v378; // [xsp+F0h] [xbp-10h]

  v378 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_DWORD *)(a5 + 88);
  v14 = *(_BYTE *)(a5 + 8);
  v359 = 0;
  memset(v362, 0, 6);
  v358 = 0;
  v357[0] = 0;
  BYTE6(v358) = v14;
  if ( v13 == 1 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Should not received Re/Assoc Response in role: %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_process_assoc_rsp_frame",
      1);
    goto LABEL_92;
  }
  if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), a6, a7, a8, a9, a10, a11, a12, a13)
    || (*(_BYTE *)(*(_QWORD *)(a5 + 16) + 60LL) & 2) != 0 )
  {
    v29 = 0;
    v28 = (unsigned __int8 *)a2;
    if ( !a2 )
      goto LABEL_6;
  }
  else
  {
    v28 = *(unsigned __int8 **)(a2 + 16);
    v29 = *(_DWORD *)(a2 + 8);
    if ( !v28 )
    {
LABEL_6:
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: LFR3: Reassoc response packet header is NULL",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "lim_process_assoc_rsp_frame");
      goto LABEL_92;
    }
  }
  v30 = jiffies;
  if ( lim_process_assoc_rsp_frame___last_ticks - jiffies + 125 >= 0 )
  {
    if ( a4 )
      goto LABEL_10;
LABEL_15:
    if ( *(_DWORD *)(a5 + 72) != 10 )
      goto LABEL_39;
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x35u,
    4u,
    "Assoc rsp RX: subtype %d vdev %d sys role %d lim state %d rssi %d from %02x:%02x:%02x:**:**:%02x",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    a4,
    *(unsigned __int8 *)(a5 + 10),
    *(unsigned int *)(a5 + 88),
    *(unsigned int *)(a5 + 72),
    (unsigned int)(char)v29,
    v28[10],
    v28[11],
    v28[12],
    v28[15]);
  lim_process_assoc_rsp_frame___last_ticks = v30;
  if ( !a4 )
    goto LABEL_15;
LABEL_10:
  if ( a4 != 1 )
  {
LABEL_16:
    v31 = 0;
    goto LABEL_17;
  }
  if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v20, v21, v22, v23, v24, v25, v26, v27)
    || (unsigned int)mlme_get_roam_state(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a5 + 10)) == 6 )
  {
    v31 = 1;
    goto LABEL_17;
  }
  v97 = *(_DWORD *)(a5 + 72);
  v31 = 1;
  if ( v97 == 11 || v97 == 28 )
  {
LABEL_17:
    v32 = *(_DWORD *)(a5 + 26);
    v33 = v28 + 10;
    LOWORD(v362[0]) = *(_WORD *)(a5 + 24);
    *(_DWORD *)((char *)v362 + 2) = v32;
    if ( a4 )
    {
      if ( (unsigned int)qdf_mem_cmp(v33, (const void *)(a5 + 182), 6u) )
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: received ReassocRsp from unexpected peer %02x:%02x:%02x:**:**:%02x",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "lim_process_assoc_rsp_frame",
          v28[10],
          v28[11],
          v28[12],
          v28[15]);
        if ( !wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v42, v43, v44, v45, v46, v47, v48, v49) )
        {
          if ( (*(_BYTE *)(*(_QWORD *)(a5 + 16) + 60LL) & 2) == 0 )
            goto LABEL_92;
          v50 = *(_WORD *)(a5 + 8);
          *(_DWORD *)(a5 + 80) = 7;
          qdf_trace(53, 1u, v50, 7);
          v51 = a1;
          v52 = 517;
LABEL_34:
          lim_handle_sme_join_result(v51, v52, 1, a5);
          goto LABEL_92;
        }
        goto LABEL_24;
      }
    }
    else if ( (unsigned int)qdf_mem_cmp(v33, v362, 6u) )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: received AssocRsp from unexpected peer %02x:%02x:%02x:**:**:%02x",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "lim_process_assoc_rsp_frame",
        v28[10],
        v28[11],
        v28[12],
        v28[15]);
      if ( !wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v61, v62, v63, v64, v65, v66, v67, v68) )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(a5 + 16) + 60LL) & 2) == 0 )
          goto LABEL_92;
        v88 = *(_WORD *)(a5 + 8);
        *(_DWORD *)(a5 + 80) = 7;
        qdf_trace(53, 1u, v88, 7);
        v51 = a1;
        v52 = 516;
        goto LABEL_34;
      }
LABEL_24:
      *(_BYTE *)(a5 + 13282) = 1;
      goto LABEL_92;
    }
    v69 = _qdf_mem_malloc(0x2160u, "lim_process_assoc_rsp_frame", 1359);
    if ( !v69 )
      goto LABEL_92;
    v78 = v69;
    v356 = v31;
    if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v70, v71, v72, v73, v74, v75, v76, v77)
      || (*(_BYTE *)(*(_QWORD *)(a5 + 16) + 60LL) & 2) != 0 )
    {
      v79 = (char *)(a2 + 24);
      a3 -= 24;
    }
    else
    {
      v79 = *(char **)(a2 + 24);
    }
    if ( (unsigned int)sir_convert_assoc_resp_frame2_struct(a1, a5, v79, a3, v78) == 16 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Parse error Assoc resp subtype: %dlength: %d",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "lim_process_assoc_rsp_frame",
        a3,
        a4);
LABEL_88:
      v150 = 0;
LABEL_89:
      _qdf_mem_free(v150);
      _qdf_mem_free(*(_QWORD *)(v78 + 680));
      _qdf_mem_free(*(_QWORD *)(v78 + 744));
LABEL_90:
      v151 = v78;
LABEL_91:
      _qdf_mem_free(v151);
      goto LABEL_92;
    }
    is_sha384_akm = lim_is_sha384_akm(*(unsigned int *)(a5 + 156));
    if ( (v356 & 1) != 0 )
    {
      LOBYTE(v353) = 1;
      LOBYTE(v351[0]) = *(_BYTE *)(v78 + 2704) != 0;
      v349[0] = *(_BYTE *)(v78 + 2508) != 0;
      lim_cp_stats_cstats_log_assoc_resp_evt(
        a5,
        1,
        *(unsigned __int16 *)(v78 + 4),
        *(unsigned __int16 *)(v78 + 2),
        v28 + 16,
        v28 + 4,
        *(_BYTE *)(v78 + 244) != 0,
        *(unsigned __int8 *)(v78 + 2296) != 0,
        *(_DWORD *)v349,
        *(_DWORD *)v351,
        v353);
    }
    else
    {
      if ( !a4 )
      {
        LOBYTE(v353) = 0;
        v349[0] = *(_BYTE *)(v78 + 2508) != 0;
        LOBYTE(v351[0]) = *(_BYTE *)(v78 + 2704) != 0;
        lim_cp_stats_cstats_log_assoc_resp_evt(
          a5,
          1,
          *(unsigned __int16 *)(v78 + 4),
          *(unsigned __int16 *)(v78 + 2),
          v28 + 16,
          v28 + 4,
          *(_BYTE *)(v78 + 244) != 0,
          *(unsigned __int8 *)(v78 + 2296) != 0,
          *(_DWORD *)v349,
          *(_DWORD *)v351,
          v353);
      }
      wlan_connectivity_mgmt_event(
        *(_QWORD *)(a1 + 21624),
        (int)v28,
        *(unsigned __int8 *)(a5 + 10),
        *(unsigned __int16 *)(v78 + 4),
        0,
        v29,
        0,
        0,
        0,
        *(_WORD *)(v78 + 2) & 0x3FFF,
        5);
    }
    if ( a5 && *(_BYTE *)(a5 + 10071) == 1 )
    {
      if ( a3 <= 5 )
      {
        v106 = "%s: frame body length is < ies_offset";
LABEL_87:
        qdf_trace_msg(0x35u, 2u, v106, v89, v90, v91, v92, v93, v94, v95, v96, "lim_process_assoc_rsp_frame");
        goto LABEL_88;
      }
      v107 = *(_QWORD *)(v78 + 2576);
      v108 = *(_WORD *)(v78 + 2584);
      v109 = *(unsigned int *)(v78 + 2312);
      v360[0] = *(_QWORD *)(v78 + 2568);
      v360[1] = v107;
      v110 = *(_QWORD *)(v78 + 336);
      v111 = *(_QWORD *)(v78 + 344);
      v361 = v108;
      v112 = *(_QWORD *)(v78 + 352);
      v367 = v110;
      v368 = v111;
      LOWORD(v110) = *(_WORD *)(v78 + 360);
      v369 = v112;
      v113 = *(unsigned __int16 *)(v78 + 2316);
      LOWORD(v370) = v110;
      v114 = *(_QWORD *)(v78 + 312);
      v363 = *(_QWORD *)(v78 + 304);
      v364 = v114;
      v115 = *(_QWORD *)(v78 + 328);
      v365 = *(_QWORD *)(v78 + 320);
      v366 = v115;
      if ( (unsigned int)lim_strip_and_decode_eht_op(v79 + 6, a3 - 6, v78 + 2704, v109 | (v113 << 32), v360, &v363) )
      {
        v106 = "%s: Failed to extract eht op";
        goto LABEL_87;
      }
      v116 = *(unsigned int *)(a5 + 284);
      v117 = *(_QWORD *)(v78 + 2540);
      v118 = *(_QWORD *)(v78 + 2548);
      v369 = *(_QWORD *)(v78 + 2556);
      v367 = v117;
      v368 = v118;
      LODWORD(v370) = *(_DWORD *)(v78 + 2564);
      v119 = *(_QWORD *)(v78 + 2516);
      v121 = *(_QWORD *)(v78 + 2524);
      v120 = *(_QWORD *)(v78 + 2532);
      v363 = *(_QWORD *)(v78 + 2508);
      v364 = v119;
      v365 = v121;
      v366 = v120;
      if ( (unsigned int)lim_strip_and_decode_eht_cap(v79 + 6, a3 - 6, v78 + 2612, &v363, v116, 0) )
      {
        v106 = "%s: Failed to extract eht cap";
        goto LABEL_87;
      }
    }
    if ( !*(_BYTE *)(v78 + 2284) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: assoc response does not have supported rate set",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "lim_process_assoc_rsp_frame");
      qdf_mem_copy((void *)(v78 + 6), (const void *)(a5 + 252), 0xDu);
    }
    v122 = *(_QWORD *)(a5 + 352);
    WORD2(v358) = *(_WORD *)(v78 + 4);
    if ( v122 )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: session_entry->assocRsp is not NULL freeing it and setting NULL",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "lim_process_assoc_rsp_frame");
      _qdf_mem_free(*(_QWORD *)(a5 + 352));
      *(_QWORD *)(a5 + 352) = 0;
      *(_DWORD *)(a5 + 344) = 0;
    }
    if ( a3 )
    {
      v123 = (void *)_qdf_mem_malloc(a3, "lim_process_assoc_rsp_frame", 1459);
      *(_QWORD *)(a5 + 352) = v123;
      if ( v123 )
      {
        qdf_mem_copy(v123, v79, a3);
        *(_DWORD *)(a5 + 344) = a3;
      }
    }
    v124 = *(_QWORD *)(a5 + 400);
    if ( v124 )
    {
      _qdf_mem_free(v124);
      *(_QWORD *)(a5 + 400) = 0;
      *(_DWORD *)(a5 + 392) = 0;
    }
    v125 = v356;
    if ( *(_BYTE *)(v78 + 2292) )
    {
      v126 = *(unsigned __int8 *)(v78 + 763);
      *(_DWORD *)(a5 + 392) = 636 * v126;
      if ( v126 )
      {
        v127 = (void *)_qdf_mem_malloc(636 * v126, "lim_update_ric_data", 387);
        *(_QWORD *)(a5 + 400) = v127;
        if ( v127 )
          qdf_mem_copy(v127, (const void *)(v78 + 764), *(unsigned int *)(a5 + 392));
        else
          *(_DWORD *)(a5 + 392) = 0;
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: RIC data not present",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "lim_update_ric_data");
      }
    }
    else
    {
      *(_DWORD *)(a5 + 392) = 0;
      *(_QWORD *)(a5 + 400) = 0;
    }
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a5 + 16), v89, v90, v91, v92, v93, v94, v95, v96);
    if ( ext_hdl )
    {
      if ( *(_BYTE *)(v78 + 689) )
      {
        v137 = *(unsigned __int8 *)(v78 + 690);
        v138 = (const void *)(v78 + 691);
      }
      else
      {
        if ( !*(_BYTE *)(v78 + 498) )
        {
          *(_DWORD *)(ext_hdl + 24008) = 0;
          qdf_mem_set((void *)(ext_hdl + 24012), 0x30u, 0);
          v139 = *(_QWORD *)(a5 + 416);
          if ( !v139 )
          {
LABEL_78:
            if ( *(_BYTE *)(v78 + 2293) )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Tspec EID present in assoc rsp",
                v129,
                v130,
                v131,
                v132,
                v133,
                v134,
                v135,
                v136,
                "lim_update_ese_tspec");
              v148 = *(unsigned __int8 *)(v78 + 2036);
              *(_DWORD *)(a5 + 408) = 60 * v148;
              if ( v148 )
              {
                v149 = (void *)_qdf_mem_malloc(60 * v148, "lim_update_ese_tspec", 430);
                *(_QWORD *)(a5 + 416) = v149;
                if ( v149 )
                  qdf_mem_copy(v149, (const void *)(v78 + 2040), *(unsigned int *)(a5 + 408));
                else
                  *(_DWORD *)(a5 + 408) = 0;
              }
              else
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: TSPEC has Zero length",
                  v140,
                  v141,
                  v142,
                  v143,
                  v144,
                  v145,
                  v146,
                  v147,
                  "lim_update_ese_tspec");
              }
            }
            else
            {
              *(_DWORD *)(a5 + 408) = 0;
              *(_QWORD *)(a5 + 416) = 0;
            }
            if ( (unsigned int)lim_get_capability_info(a1, &v359, a5) )
            {
              v106 = "%s: could not retrieve Capabilities";
              goto LABEL_87;
            }
            if ( *(_WORD *)(v78 + 4) )
            {
              if ( *(_WORD *)(v78 + 4) == 34 && *(_BYTE *)(v78 + 2460) )
              {
                v376 = 0;
                v377 = 0;
                v152 = *(unsigned __int8 *)(v78 + 2462);
                v374 = 0;
                v375 = 0;
                v373 = 0;
                v153 = *(_BYTE *)(v78 + 2461);
                v371 = 0;
                v372 = 0;
                v369 = 0;
                v370 = 0;
                v367 = 0;
                v368 = 0;
                v365 = 0;
                v366 = 0;
                v363 = 0;
                v364 = 0;
                if ( v152 )
                {
                  v154 = v153 + *(_BYTE *)(a2 + 8);
                }
                else
                {
                  v158 = *(_DWORD *)(a2 + 8);
                  rssi_denylist_threshold = dlm_get_rssi_denylist_threshold(*(_QWORD *)(a1 + 21632));
                  v152 = *(unsigned __int8 *)(v78 + 2462);
                  v154 = v158 + rssi_denylist_threshold + v153;
                }
                BYTE4(v366) = v154;
                LODWORD(v366) = 1000 * v152;
                qdf_mem_copy(&v365, v28 + 10, 6u);
                v368 = 0x100000005LL;
                LODWORD(v369) = v366;
                system_time = qdf_mc_timer_get_system_time();
                v161 = *(_QWORD *)(a1 + 21632);
                v162 = *(unsigned __int8 *)(a5 + 10);
                v370 = system_time;
                lim_add_bssid_to_reject_list(v161, v162, &v363);
              }
              else if ( (lim_handle_assoc_failure_in_dlm() & 1) != 0 )
              {
                v374 = 0;
                v375 = 0;
                v373 = 0;
                v371 = 0;
                v372 = 0;
                v369 = 0;
                v370 = 0;
                v367 = 0;
                v368 = 0;
                v365 = 0;
                v366 = 0;
                v363 = 0;
                v364 = 0;
                qdf_mem_set(&v363, 0x68u, 0);
                qdf_mem_copy(&v363, v28 + 10, 6u);
                LODWORD(v374) = 2;
                dlm_reject_reason = lim_get_dlm_reject_reason(*(unsigned __int16 *)(v78 + 4));
                v156 = *(_QWORD *)(a1 + 21632);
                v157 = *(unsigned __int8 *)(a5 + 10);
                HIDWORD(v374) = dlm_reject_reason;
                LODWORD(v375) = 1;
                ((void (__fastcall *)(__int64, __int64, __int64 *))dlm_update_mlo_reject_ap_info)(v156, v157, &v363);
                dlm_add_bssid_to_reject_list(*(_QWORD *)(a1 + 21632), &v363);
              }
            }
            if ( !(unsigned int)lim_handle_pmfcomeback_timer(a5, v78) )
              goto LABEL_88;
            if ( a4 )
              lim_stop_reassoc_retry_timer(a1);
            else
              lim_deactivate_and_change_timer(a1, 5);
            if ( *(_WORD *)(v78 + 4) )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: received Re/AssocRsp frame failure code: %d",
                v163,
                v164,
                v165,
                v166,
                v167,
                v168,
                v169,
                v170,
                "lim_process_assoc_rsp_frame");
              LODWORD(v358) = 516;
              v150 = lim_search_pre_auth_list(a1, v28 + 10);
              if ( v150 )
              {
                lim_delete_pre_auth_node(a1, v28 + 10);
                v150 = 0;
                if ( !a4 )
                  goto LABEL_127;
                goto LABEL_124;
              }
LABEL_123:
              if ( !a4 )
                goto LABEL_127;
              goto LABEL_124;
            }
            if ( (*(_WORD *)(v78 + 2) & 0x3FF8u) >= 0x7D8 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: received Re/AssocRsp frame with invalid aid: %X",
                v163,
                v164,
                v165,
                v166,
                v167,
                v168,
                v169,
                v170,
                "lim_process_assoc_rsp_frame");
LABEL_120:
              v204 = 523;
              v205 = 1;
LABEL_121:
              v206 = v28 + 10;
              v207 = a1;
              LODWORD(v358) = v204;
              WORD2(v358) = v205;
LABEL_122:
              lim_send_disassoc_mgmt_frame(v207, 1, v206, a5, 0);
              v150 = 0;
              goto LABEL_123;
            }
            if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a5 + 16), v163, v164, v165, v166, v167, v168, v169, v170) & 1) != 0
              && !*(_BYTE *)(v78 + 2612) )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: EHT caps is missing for ML association, trigger disconnection",
                v179,
                v180,
                v181,
                v182,
                v183,
                v184,
                v185,
                v186,
                "lim_process_assoc_rsp_frame");
              v204 = 500;
              v205 = 135;
              goto LABEL_121;
            }
            if ( (lim_verify_fils_params_assoc_rsp(a1, a5, v78, &v358) & 1) == 0 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: FILS params does not match",
                v187,
                v188,
                v189,
                v190,
                v191,
                v192,
                v193,
                v194,
                "lim_process_assoc_rsp_frame");
              goto LABEL_120;
            }
            v195 = (void *)(a5 + 7365);
            if ( *(_BYTE *)(v78 + 2337) )
              qdf_mem_copy(v195, (const void *)(v78 + 2337), 0x3Cu);
            else
              qdf_mem_set(v195, 0x3Cu, 0);
            if ( *(_BYTE *)(v78 + 2444) )
              lim_update_obss_scanparams(a5, v78 + 2444);
            if ( *(_BYTE *)(a5 + 8676) == 1 )
            {
              if ( !wlan_cm_is_vdev_roaming(*(_QWORD *)(a5 + 16), v196, v197, v198, v199, v200, v201, v202, v203) )
                lim_set_twt_peer_capabilities(a1, (__int64)v362, v78 + 2508, v78 + 2568);
            }
            else
            {
              wlan_twt_cfg_get_req_support_for_ht_vht(*(_QWORD *)(a1 + 21624), v357);
              if ( v357[0] == 1 && *(_BYTE *)(a5 + 155) && *(_BYTE *)(v78 + 244) && *(_BYTE *)(v78 + 2318) )
                lim_set_twt_ext_capabilities(a1, (__int64)v362, v78 + 2320);
            }
            lim_diag_event_report(a1, 71, a5, 16 * (unsigned int)(*(_WORD *)(v78 + 4) != 0));
            nss_supported_by_ap = lim_get_nss_supported_by_ap(v78 + 2296, (_BYTE *)(v78 + 244), v78 + 2508);
            wlan_mlme_set_ap_nss(
              *(_QWORD *)(a5 + 16),
              nss_supported_by_ap,
              v224,
              v225,
              v226,
              v227,
              v228,
              v229,
              v230,
              v231);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: AP supported NSS = %u",
              v232,
              v233,
              v234,
              v235,
              v236,
              v237,
              v238,
              v239,
              "lim_process_assoc_rsp_frame",
              (unsigned __int8)nss_supported_by_ap);
            if ( v356 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Successfully Reassociated with BSS",
                v240,
                v241,
                v242,
                v243,
                v244,
                v245,
                v246,
                v247,
                "lim_process_assoc_rsp_frame");
              if ( *(_BYTE *)(v78 + 2294) )
                lim_update_ese_tsm(a1, a5, v78);
              v248 = *(_QWORD *)(a5 + 128);
              if ( v248 )
              {
                _qdf_mem_free(v248);
                *(_QWORD *)(a5 + 128) = 0;
              }
              v249 = *(_QWORD *)(a5 + 240);
              if ( v249 )
              {
                _qdf_mem_free(*(_QWORD *)(v249 + 680));
                _qdf_mem_free(*(_QWORD *)(v249 + 744));
                _qdf_mem_free(*(_QWORD *)(a5 + 240));
              }
              *(_QWORD *)(a5 + 240) = v78;
              hash_entry = dph_get_hash_entry(a1, 1u, a5 + 360);
              if ( !hash_entry )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: could not get hash entry at DPH for SA: %02x:%02x:%02x:**:**:%02x",
                  v251,
                  v252,
                  v253,
                  v254,
                  v255,
                  v256,
                  v257,
                  v258,
                  "lim_process_assoc_rsp_frame",
                  v28[10],
                  v28[11],
                  v28[12],
                  v28[15]);
                WORD2(v358) = 1;
                v207 = a1;
                LODWORD(v358) = 523;
                v206 = v28 + 10;
                goto LABEL_122;
              }
              v259 = (__int16 *)hash_entry;
              v260 = *(unsigned __int8 *)(a5 + 8635);
              if ( (unsigned int)v260 > (unsigned __int8)nss_supported_by_ap )
              {
                v260 = nss_supported_by_ap;
                *(_BYTE *)(a5 + 8635) = nss_supported_by_ap;
              }
              lim_objmgr_update_vdev_nss(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a5 + 10), v260);
              lim_update_vdev_rate_set(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a5 + 10), v78);
              if ( *(_DWORD *)(a5 + 72) == 28
                || wlan_cm_is_vdev_roam_sync_inprogress(
                     *(_QWORD *)(a5 + 16),
                     v261,
                     v262,
                     v263,
                     v264,
                     v265,
                     v266,
                     v267,
                     v268) )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Sending self sta",
                  v261,
                  v262,
                  v263,
                  v264,
                  v265,
                  v266,
                  v267,
                  v268,
                  "lim_process_assoc_rsp_frame");
                lim_update_assoc_sta_datas(a1, (__int64)v259, (unsigned __int16 *)v78, a5);
                lim_update_stads_ext_cap(a1, a5, v78, v259);
                *(_WORD *)(a5 + 180) = *(_WORD *)(v78 + 2) & 0x3FFF;
                lim_set_active_edca_params(a1, a5 + 7096, a5);
                if ( wlan_cm_is_vdev_roam_sync_inprogress(
                       *(_QWORD *)(a5 + 16),
                       v269,
                       v270,
                       v271,
                       v272,
                       v273,
                       v274,
                       v275,
                       v276) )
                {
                  lim_set_emlsr_caps(a1, a5);
                  lim_objmgr_update_emlsr_caps(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a5 + 10), v78);
                  lim_cache_emlsr_params(a5, v78);
                }
                else
                {
                  lim_send_edca_params(a1, a5 + 7136, *(unsigned __int8 *)(a5 + 10), 0);
                }
                goto LABEL_92;
              }
              if ( !(unsigned __int8)sir_compare_mac_addr(a5 + 24, a5 + 182) )
              {
                *(_WORD *)(a5 + 7274) = 0;
                lim_mlo_notify_peer_disconn(a5, v259);
                if ( (unsigned int)lim_cleanup_rx_path(a1, v259, a5, 1, v333, v334, v335, v336, v337, v338, v339, v340) )
                {
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Could not cleanup the rx path",
                    v341,
                    v342,
                    v343,
                    v344,
                    v345,
                    v346,
                    v347,
                    v348,
                    "lim_process_assoc_rsp_frame");
                  goto LABEL_173;
                }
              }
              if ( (mlo_roam_is_auth_status_connected(
                      *(_QWORD *)(a1 + 21624),
                      *(unsigned __int8 *)(*(_QWORD *)(a5 + 16) + 168LL))
                  & 1) == 0 )
              {
                *(_BYTE *)(a5 + 13282) = 1;
                goto LABEL_92;
              }
            }
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Successfully Associated with BSS %02x:%02x:%02x:**:**:%02x",
              v240,
              v241,
              v242,
              v243,
              v244,
              v245,
              v246,
              v247,
              "lim_process_assoc_rsp_frame",
              v28[10],
              v28[11],
              v28[12],
              v28[15]);
            if ( *(_BYTE *)(a5 + 7047) )
              *(_BYTE *)(a5 + 7050) = 0;
            *(_WORD *)(a5 + 180) = *(_WORD *)(v78 + 2) & 0x3FFF;
            v277 = dph_get_hash_entry(a1, 1u, a5 + 360);
            if ( v277 )
            {
              v286 = v277;
              if ( lim_search_pre_auth_list(a1, v28 + 10) )
                lim_delete_pre_auth_node(a1, v28 + 10);
              v287 = *(unsigned __int8 *)(a5 + 8635);
              if ( (unsigned int)v287 > (unsigned __int8)nss_supported_by_ap )
              {
                v287 = nss_supported_by_ap;
                *(_BYTE *)(a5 + 8635) = nss_supported_by_ap;
              }
              lim_objmgr_update_vdev_nss(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a5 + 10), v287);
              lim_update_vdev_rate_set(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a5 + 10), v78);
              if ( (unsigned int)lim_update_sta_vdev_punc(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a5 + 10), v78) )
              {
                LODWORD(v358) = 523;
                WORD2(v358) = 1;
                lim_send_disassoc_mgmt_frame(a1, 1, v28 + 10, a5, 0);
LABEL_173:
                v150 = 0;
                goto LABEL_174;
              }
              lim_objmgr_update_emlsr_caps(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a5 + 10), v78);
              lim_process_assoc_rsp_t2lm(a5, v78);
              v288 = _qdf_mem_malloc(0x1A08u, "lim_process_assoc_rsp_frame", 1823);
              if ( v288 )
              {
                v289 = v288;
                ielen_from_bss_description = wlan_get_ielen_from_bss_description(*(_QWORD *)(a5 + 112) + 4548LL);
                v291 = *(_QWORD *)(a5 + 112);
                v292 = ielen_from_bss_description;
                ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))lim_update_iot_aggr_sz)(
                  a1,
                  v291 + 4652,
                  (unsigned __int16)ielen_from_bss_description,
                  a5);
                lim_extract_ap_capabilities(a1, v291 + 4652, v292, (void *)v289);
                if ( !*(_DWORD *)(a5 + 7036) )
                  lim_enable_cts_to_self_for_exempted_iot_ap(a1, a5, v291 + 4652, v292);
                lim_update_assoc_sta_datas(a1, v286, (unsigned __int16 *)v78, a5);
                if ( *(_BYTE *)(a5 + 8676) == 1 )
                {
                  v301 = *(unsigned __int8 *)(v78 + 2716);
                  *(_BYTE *)(a5 + 10041) = v301;
                  if ( v301 == 1 )
                  {
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: Save MU EDCA params to session",
                      v293,
                      v294,
                      v295,
                      v296,
                      v297,
                      v298,
                      v299,
                      v300,
                      "lim_process_assoc_rsp_frame");
                    v302 = *(_DWORD *)(v78 + 2721);
                    *(_BYTE *)(a5 + 10025) = *(_BYTE *)(v78 + 2725);
                    *(_DWORD *)(a5 + 10021) = v302;
                    v303 = *(_DWORD *)(v78 + 2726);
                    *(_BYTE *)(a5 + 10030) = *(_BYTE *)(v78 + 2730);
                    *(_DWORD *)(a5 + 10026) = v303;
                    v304 = *(_DWORD *)(v78 + 2731);
                    *(_BYTE *)(a5 + 10035) = *(_BYTE *)(v78 + 2735);
                    *(_DWORD *)(a5 + 10031) = v304;
                    v305 = *(_DWORD *)(v78 + 2736);
                    *(_BYTE *)(a5 + 10040) = *(_BYTE *)(v78 + 2740);
                    *(_DWORD *)(a5 + 10036) = v305;
                  }
                }
                if ( *(_BYTE *)(v289 + 2484) )
                {
                  v306 = *(_QWORD *)(v289 + 2492);
                  *(_QWORD *)(v286 + 724) = *(_QWORD *)(v289 + 2484);
                  *(_QWORD *)(v286 + 732) = v306;
                }
                if ( *(_BYTE *)(v289 + 1200) )
                {
                  v307 = *(_QWORD *)(v289 + 1216);
                  v308 = *(_QWORD *)(v289 + 1200);
                  v309 = *(_QWORD *)(v289 + 1208);
                  *(_QWORD *)(v286 + 688) = *(_QWORD *)(v289 + 1224);
                  *(_QWORD *)(v286 + 680) = v307;
                  *(_QWORD *)(v286 + 672) = v309;
                  *(_QWORD *)(v286 + 664) = v308;
                  v310 = *(_QWORD *)(v289 + 1232);
                  v311 = *(_QWORD *)(v289 + 1240);
                  v312 = *(_QWORD *)(v289 + 1248);
                  *(_DWORD *)(v286 + 720) = *(_DWORD *)(v289 + 1256);
                  *(_QWORD *)(v286 + 696) = v310;
                  *(_QWORD *)(v286 + 712) = v312;
                  *(_QWORD *)(v286 + 704) = v311;
                }
                if ( *(_BYTE *)(v289 + 2570) )
                  *(_DWORD *)(v286 + 804) = *(_DWORD *)(v289 + 2570);
                if ( *(_BYTE *)(v289 + 1260) )
                {
                  v313 = *(_QWORD *)(v289 + 1284);
                  v314 = *(_QWORD *)(v289 + 1260);
                  v315 = *(_QWORD *)(v289 + 1268);
                  *(_QWORD *)(v286 + 756) = *(_QWORD *)(v289 + 1276);
                  *(_QWORD *)(v286 + 764) = v313;
                  *(_QWORD *)(v286 + 740) = v314;
                  *(_QWORD *)(v286 + 748) = v315;
                  v316 = *(_QWORD *)(v289 + 1292);
                  v317 = *(_QWORD *)(v289 + 1300);
                  v318 = *(_QWORD *)(v289 + 1308);
                  *(_WORD *)(v286 + 796) = *(_WORD *)(v289 + 1316);
                  *(_QWORD *)(v286 + 772) = v316;
                  *(_QWORD *)(v286 + 780) = v317;
                  *(_QWORD *)(v286 + 788) = v318;
                }
                if ( *(_BYTE *)(v289 + 2500) )
                {
                  v319 = *(_DWORD *)(v289 + 2500);
                  *(_WORD *)(v286 + 802) = *(_WORD *)(v289 + 2504);
                  *(_DWORD *)(v286 + 798) = v319;
                }
                if ( *(_BYTE *)(v289 + 2700) )
                {
                  v320 = *(_QWORD *)(v289 + 2700);
                  v321 = *(_QWORD *)(v289 + 2708);
                  *(_WORD *)(v286 + 824) = *(_WORD *)(v289 + 2716);
                  *(_QWORD *)(v286 + 816) = v321;
                  *(_QWORD *)(v286 + 808) = v320;
                }
                if ( *(_BYTE *)(v78 + 2586) )
                {
                  v322 = *(_QWORD *)(v78 + 2586);
                  v323 = *(_QWORD *)(v78 + 2594);
                  *(_QWORD *)(v286 + 839) = *(_QWORD *)(v78 + 2599);
                  *(_QWORD *)(v286 + 826) = v322;
                  *(_QWORD *)(v286 + 834) = v323;
                  lim_update_vdev_sr_elements(a5, v286, v293, v294, v295, v296, v297, v298, v299, v300);
                }
                if ( a5 && *(_BYTE *)(a5 + 10071) == 1 && *(_BYTE *)(v289 + 2832) )
                {
                  v324 = *(_QWORD *)(v289 + 2832);
                  *(_DWORD *)(v286 + 856) = *(_DWORD *)(v289 + 2840);
                  *(_QWORD *)(v286 + 848) = v324;
                }
                if ( *(_BYTE *)(a1 + 8884) )
                  lim_decide_sta_protection_on_assoc(a1, v289, a5);
                if ( *(_BYTE *)(v289 + 2475) )
                  *(_BYTE *)(a5 + 7160) = ((*(unsigned __int8 *)(v289 + 1132) >> 2) & 1) == 0;
                lim_diag_event_report(a1, 61, a5, 0);
                lim_update_stads_ext_cap(a1, a5, v78, v286);
                if ( !(unsigned int)lim_sta_send_add_bss(a1, (_BYTE *)v78, v289, *(_QWORD *)(a5 + 112) + 4548LL, 1u, a5) )
                {
                  clean_up_ft_sha384(v78, is_sha384_akm & 1);
                  if ( *(_QWORD *)(a5 + 240) != v78 )
                    _qdf_mem_free(v78);
                  v151 = v289;
                  goto LABEL_91;
                }
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: vdev:%d could not update the bss entry",
                  v325,
                  v326,
                  v327,
                  v328,
                  v329,
                  v330,
                  v331,
                  v332,
                  "lim_process_assoc_rsp_frame",
                  *(unsigned __int8 *)(a5 + 10));
                v150 = v289;
                WORD2(v358) = 1;
                LODWORD(v358) = 502;
LABEL_174:
                v125 = v356;
                if ( !a4 )
                  goto LABEL_127;
LABEL_124:
                if ( !v125 )
                  goto LABEL_89;
                if ( *(_DWORD *)(a5 + 72) != 28 )
                {
                  v208 = v150;
                  is_vdev_roaming = cm_is_vdev_roaming(
                                      *(_QWORD *)(a5 + 16),
                                      v171,
                                      v172,
                                      v173,
                                      v174,
                                      v175,
                                      v176,
                                      v177,
                                      v178);
                  v150 = v208;
                  if ( is_vdev_roaming )
                    goto LABEL_89;
                }
LABEL_127:
                v210 = v150;
                LODWORD(v352) = v28[12];
                LODWORD(v354) = v28[15];
                LODWORD(v350) = v28[11];
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Assoc Rejected by the peer mlmestate: %d sessionid: %d Reason: %d MACADDR:%02x:%02x:%02x:**:**:%02x",
                  v171,
                  v172,
                  v173,
                  v174,
                  v175,
                  v176,
                  v177,
                  v178,
                  "lim_process_assoc_rsp_frame",
                  *(unsigned int *)(a5 + 72),
                  *(unsigned __int16 *)(a5 + 8),
                  (unsigned int)v358,
                  v28[10],
                  v350,
                  v352,
                  v354);
                v211 = *(_WORD *)(a5 + 8);
                *(_DWORD *)(a5 + 72) = 1;
                qdf_trace(53, 0, v211, 1);
                v220 = *(_QWORD *)(a5 + 128);
                if ( v220 )
                {
                  _qdf_mem_free(v220);
                  *(_QWORD *)(a5 + 128) = 0;
                }
                if ( a4 && cm_is_vdev_roaming(*(_QWORD *)(a5 + 16), v212, v213, v214, v215, v216, v217, v218, v219) )
                {
                  v221 = a1;
                  v222 = 1015;
                  LODWORD(v358) = 537;
                }
                else
                {
                  v221 = a1;
                  v222 = 1010;
                }
                lim_process_mlm_rsp_messages(v221, v222, &v358);
                v150 = v210;
                goto LABEL_89;
              }
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: could not get hash entry at DPH SA: %02x:%02x:%02x:**:**:%02x",
                v278,
                v279,
                v280,
                v281,
                v282,
                v283,
                v284,
                v285,
                "lim_process_assoc_rsp_frame",
                v28[10],
                v28[11],
                v28[12],
                v28[15]);
              LODWORD(v358) = 502;
              WORD2(v358) = 0;
              lim_process_mlm_rsp_messages(a1, 1010, &v358);
            }
            clean_up_ft_sha384(v78, is_sha384_akm & 1);
            if ( *(_QWORD *)(a5 + 240) == v78 )
              goto LABEL_92;
            goto LABEL_90;
          }
LABEL_77:
          _qdf_mem_free(v139);
          *(_QWORD *)(a5 + 416) = 0;
          *(_DWORD *)(a5 + 408) = 0;
          goto LABEL_78;
        }
        v137 = *(unsigned __int8 *)(v78 + 499);
        v138 = (const void *)(v78 + 500);
      }
      *(_DWORD *)(ext_hdl + 24008) = v137;
      qdf_mem_copy((void *)(ext_hdl + 24012), v138, v137);
    }
    v139 = *(_QWORD *)(a5 + 416);
    if ( !v139 )
      goto LABEL_78;
    goto LABEL_77;
  }
LABEL_39:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Received Re/Assoc rsp in unexpected state: %d on session: %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "lim_process_assoc_rsp_frame");
  if ( (*(_WORD *)v28 & 0x800) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 12432) & 0xF) != 0 )
    {
      ++*(_BYTE *)(a1 + 12432);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: recvd Re/Assoc rsp:not a retry frame",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "lim_process_assoc_rsp_frame");
      lim_print_mlm_state(a1, 2, *(unsigned int *)(a5 + 72));
    }
  }
LABEL_92:
  _ReadStatusReg(SP_EL0);
}
