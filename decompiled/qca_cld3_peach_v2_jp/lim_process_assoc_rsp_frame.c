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
  int v28; // w28
  __int64 v29; // x23
  __int64 v30; // x24
  int v31; // w22
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
  __int64 v42; // x4
  __int64 v43; // x5
  const char *v44; // x2
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x22
  _QWORD *v63; // x24
  int v64; // w4
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x9
  void *v90; // x0
  __int64 v91; // x0
  __int64 v92; // x24
  __int64 v93; // x8
  void *v94; // x0
  __int64 ext_hdl; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  size_t v104; // x2
  const void *v105; // x1
  __int64 v106; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // x8
  void *v116; // x0
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x0
  __int64 v126; // x0
  int v127; // w8
  char v128; // w24
  char v129; // w9
  int v130; // w26
  char rssi_denylist_threshold; // w0
  __int64 system_time; // x0
  __int64 v133; // x8
  __int64 v134; // x1
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  void *v159; // x0
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  __int64 v168; // x2
  __int64 v169; // x0
  __int64 v170; // x24
  __int16 v171; // w2
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  __int64 v180; // x0
  __int64 v181; // x0
  __int64 v182; // x1
  bool is_vdev_roaming; // w8
  unsigned int nss_supported_by_ap; // w24
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
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
  __int64 v209; // x0
  __int64 v210; // x26
  __int64 v211; // x0
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  __int16 *v220; // x26
  __int64 v221; // x2
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  __int64 hash_entry; // x0
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  __int64 v247; // x26
  __int64 v248; // x2
  __int64 v249; // x0
  __int64 v250; // x25
  unsigned int ielen_from_bss_description; // w0
  __int64 v252; // x27
  unsigned int v253; // w24
  double v254; // d0
  double v255; // d1
  double v256; // d2
  double v257; // d3
  double v258; // d4
  double v259; // d5
  double v260; // d6
  double v261; // d7
  int v262; // w8
  int v263; // w9
  int v264; // w9
  int v265; // w9
  int v266; // w10
  __int64 v267; // x10
  __int64 v268; // x11
  __int64 v269; // x12
  __int64 v270; // x13
  __int64 v271; // x12
  __int64 v272; // x9
  __int64 v273; // x11
  __int64 v274; // x10
  __int64 v275; // x13
  __int64 v276; // x14
  __int64 v277; // x13
  __int64 v278; // x9
  __int64 v279; // x11
  int v280; // w9
  __int64 v281; // x8
  __int64 v282; // x10
  __int64 v283; // x8
  __int64 v284; // x11
  double v285; // d0
  double v286; // d1
  double v287; // d2
  double v288; // d3
  double v289; // d4
  double v290; // d5
  double v291; // d6
  double v292; // d7
  double v293; // d0
  double v294; // d1
  double v295; // d2
  double v296; // d3
  double v297; // d4
  double v298; // d5
  double v299; // d6
  double v300; // d7
  double v301; // d0
  double v302; // d1
  double v303; // d2
  double v304; // d3
  double v305; // d4
  double v306; // d5
  double v307; // d6
  double v308; // d7
  char v309[4]; // [xsp+0h] [xbp-B0h]
  char v310[8]; // [xsp+0h] [xbp-B0h]
  __int16 v311[2]; // [xsp+8h] [xbp-A8h]
  __int64 v312; // [xsp+8h] [xbp-A8h]
  int v313; // [xsp+10h] [xbp-A0h]
  __int64 v314; // [xsp+10h] [xbp-A0h]
  char is_sha384_akm; // [xsp+24h] [xbp-8Ch]
  int v316; // [xsp+34h] [xbp-7Ch]
  _BYTE v317[4]; // [xsp+44h] [xbp-6Ch] BYREF
  __int64 v318; // [xsp+48h] [xbp-68h] BYREF
  __int16 v319; // [xsp+54h] [xbp-5Ch] BYREF
  _QWORD v320[2]; // [xsp+58h] [xbp-58h] BYREF
  __int64 v321; // [xsp+68h] [xbp-48h] BYREF
  __int64 v322; // [xsp+70h] [xbp-40h]
  __int64 v323; // [xsp+78h] [xbp-38h]
  __int64 v324; // [xsp+80h] [xbp-30h]
  __int64 v325; // [xsp+88h] [xbp-28h]
  __int64 v326; // [xsp+90h] [xbp-20h]
  _DWORD v327[2]; // [xsp+98h] [xbp-18h] BYREF
  __int64 v328; // [xsp+A0h] [xbp-10h]

  v328 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_DWORD *)(a5 + 88);
  v14 = *(_BYTE *)(a5 + 8);
  v319 = 0;
  memset(v327, 0, 6);
  v318 = 0;
  v317[0] = 0;
  BYTE6(v318) = v14;
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
    goto LABEL_76;
  }
  if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), a6, a7, a8, a9, a10, a11, a12, a13) )
  {
    v28 = 0;
    v29 = a2;
    if ( a2 )
      goto LABEL_5;
LABEL_11:
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
    goto LABEL_76;
  }
  v29 = *(_QWORD *)(a2 + 16);
  v28 = *(_DWORD *)(a2 + 8);
  if ( !v29 )
    goto LABEL_11;
LABEL_5:
  v30 = jiffies;
  if ( lim_process_assoc_rsp_frame___last_ticks - jiffies + 125 >= 0 )
  {
    if ( a4 )
      goto LABEL_7;
LABEL_13:
    if ( *(_DWORD *)(a5 + 72) != 10 )
      goto LABEL_27;
    goto LABEL_14;
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
    (unsigned int)(char)v28,
    *(unsigned __int8 *)(v29 + 10),
    *(unsigned __int8 *)(v29 + 11),
    *(unsigned __int8 *)(v29 + 12),
    *(unsigned __int8 *)(v29 + 15));
  lim_process_assoc_rsp_frame___last_ticks = v30;
  if ( !a4 )
    goto LABEL_13;
LABEL_7:
  if ( a4 != 1 )
  {
LABEL_14:
    v31 = 0;
    goto LABEL_15;
  }
  if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v20, v21, v22, v23, v24, v25, v26, v27) )
  {
    v31 = 1;
    goto LABEL_15;
  }
  v64 = *(_DWORD *)(a5 + 72);
  v31 = 1;
  if ( v64 != 11 && v64 != 28 )
  {
LABEL_27:
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
    if ( (*(_WORD *)v29 & 0x800) == 0 )
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
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          "lim_process_assoc_rsp_frame");
        lim_print_mlm_state(a1, 2, *(unsigned int *)(a5 + 72));
      }
    }
    goto LABEL_76;
  }
LABEL_15:
  v32 = *(_DWORD *)(a5 + 26);
  v33 = (const void *)(v29 + 10);
  LOWORD(v327[0]) = *(_WORD *)(a5 + 24);
  *(_DWORD *)((char *)v327 + 2) = v32;
  if ( a4 )
  {
    if ( (unsigned int)qdf_mem_cmp(v33, (const void *)(a5 + 182), 6u) )
    {
      v42 = *(unsigned __int8 *)(v29 + 10);
      v43 = *(unsigned __int8 *)(v29 + 11);
      v44 = "%s: received ReassocRsp from unexpected peer %02x:%02x:%02x:**:**:%02x";
      goto LABEL_20;
    }
  }
  else if ( (unsigned int)qdf_mem_cmp(v33, v327, 6u) )
  {
    v42 = *(unsigned __int8 *)(v29 + 10);
    v43 = *(unsigned __int8 *)(v29 + 11);
    v44 = "%s: received AssocRsp from unexpected peer %02x:%02x:%02x:**:**:%02x";
LABEL_20:
    qdf_trace_msg(
      0x35u,
      3u,
      v44,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "lim_process_assoc_rsp_frame",
      v42,
      v43,
      *(unsigned __int8 *)(v29 + 12),
      *(unsigned __int8 *)(v29 + 15));
    if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v45, v46, v47, v48, v49, v50, v51, v52) )
      *(_BYTE *)(a5 + 10073) = 1;
    goto LABEL_76;
  }
  v316 = v31;
  v53 = _qdf_mem_malloc(0x14E0u, "lim_process_assoc_rsp_frame", 1359);
  if ( !v53 )
    goto LABEL_76;
  v62 = v53;
  v63 = (_QWORD *)(a2 + 24);
  if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v54, v55, v56, v57, v58, v59, v60, v61) )
    a3 -= 24;
  else
    v63 = (_QWORD *)*v63;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD *, _QWORD, __int64))sir_convert_assoc_resp_frame2_struct)(
                       a1,
                       a5,
                       v63,
                       a3,
                       v62) == 16 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Parse error Assoc resp subtype: %dlength: %d",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "lim_process_assoc_rsp_frame",
      a3,
      a4);
LABEL_72:
    v125 = 0;
LABEL_73:
    _qdf_mem_free(v125);
    _qdf_mem_free(*(_QWORD *)(v62 + 680));
    _qdf_mem_free(*(_QWORD *)(v62 + 744));
LABEL_74:
    v126 = v62;
LABEL_75:
    _qdf_mem_free(v126);
    goto LABEL_76;
  }
  is_sha384_akm = lim_is_sha384_akm(*(unsigned int *)(a5 + 156));
  if ( (v316 & 1) != 0 )
  {
    LOBYTE(v313) = 1;
    LOBYTE(v311[0]) = *(_BYTE *)(v62 + 2704) != 0;
    v309[0] = *(_BYTE *)(v62 + 2508) != 0;
    lim_cp_stats_cstats_log_assoc_resp_evt(
      a5,
      1,
      *(unsigned __int16 *)(v62 + 4),
      *(unsigned __int16 *)(v62 + 2),
      v29 + 16,
      v29 + 4,
      *(_BYTE *)(v62 + 244) != 0,
      *(unsigned __int8 *)(v62 + 2296) != 0,
      *(_DWORD *)v309,
      *(_DWORD *)v311,
      v313);
  }
  else
  {
    if ( !a4 )
    {
      LOBYTE(v313) = 0;
      v309[0] = *(_BYTE *)(v62 + 2508) != 0;
      LOBYTE(v311[0]) = *(_BYTE *)(v62 + 2704) != 0;
      lim_cp_stats_cstats_log_assoc_resp_evt(
        a5,
        1,
        *(unsigned __int16 *)(v62 + 4),
        *(unsigned __int16 *)(v62 + 2),
        v29 + 16,
        v29 + 4,
        *(_BYTE *)(v62 + 244) != 0,
        *(unsigned __int8 *)(v62 + 2296) != 0,
        *(_DWORD *)v309,
        *(_DWORD *)v311,
        v313);
    }
    wlan_connectivity_mgmt_event(
      *(_QWORD *)(a1 + 21552),
      v29,
      *(unsigned __int8 *)(a5 + 10),
      *(unsigned __int16 *)(v62 + 4),
      0,
      v28,
      0,
      0,
      0,
      *(_WORD *)(v62 + 2) & 0x3FFF,
      5);
  }
  if ( !*(_BYTE *)(v62 + 2284) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: assoc response does not have supported rate set",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      "lim_process_assoc_rsp_frame");
    qdf_mem_copy((void *)(v62 + 6), (const void *)(a5 + 252), 0xDu);
  }
  v89 = *(_QWORD *)(a5 + 352);
  WORD2(v318) = *(_WORD *)(v62 + 4);
  if ( v89 )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: session_entry->assocRsp is not NULL freeing it and setting NULL",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      "lim_process_assoc_rsp_frame");
    _qdf_mem_free(*(_QWORD *)(a5 + 352));
    *(_QWORD *)(a5 + 352) = 0;
    *(_DWORD *)(a5 + 344) = 0;
  }
  if ( a3 )
  {
    v90 = (void *)_qdf_mem_malloc(a3, "lim_process_assoc_rsp_frame", 1459);
    *(_QWORD *)(a5 + 352) = v90;
    if ( v90 )
    {
      qdf_mem_copy(v90, v63, a3);
      *(_DWORD *)(a5 + 344) = a3;
    }
  }
  v91 = *(_QWORD *)(a5 + 400);
  if ( v91 )
  {
    _qdf_mem_free(v91);
    *(_QWORD *)(a5 + 400) = 0;
    *(_DWORD *)(a5 + 392) = 0;
  }
  v92 = a5 + 7047;
  if ( *(_BYTE *)(v62 + 2292) )
  {
    v93 = *(unsigned __int8 *)(v62 + 763);
    *(_DWORD *)(a5 + 392) = 636 * v93;
    if ( v93 )
    {
      v94 = (void *)_qdf_mem_malloc(636 * v93, "lim_update_ric_data", 387);
      *(_QWORD *)(a5 + 400) = v94;
      if ( v94 )
        qdf_mem_copy(v94, (const void *)(v62 + 764), *(unsigned int *)(a5 + 392));
      else
        *(_DWORD *)(a5 + 392) = 0;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: RIC data not present",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        "lim_update_ric_data");
    }
  }
  else
  {
    *(_DWORD *)(a5 + 392) = 0;
    *(_QWORD *)(a5 + 400) = 0;
  }
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a5 + 16), v81, v82, v83, v84, v85, v86, v87, v88);
  if ( ext_hdl )
  {
    if ( *(_BYTE *)(v62 + 689) )
    {
      v104 = *(unsigned __int8 *)(v62 + 690);
      v105 = (const void *)(v62 + 691);
    }
    else
    {
      if ( !*(_BYTE *)(v62 + 498) )
      {
        *(_DWORD *)(ext_hdl + 24008) = 0;
        qdf_mem_set((void *)(ext_hdl + 24012), 0x30u, 0);
        v106 = *(_QWORD *)(a5 + 416);
        if ( !v106 )
          goto LABEL_63;
        goto LABEL_62;
      }
      v104 = *(unsigned __int8 *)(v62 + 499);
      v105 = (const void *)(v62 + 500);
    }
    *(_DWORD *)(ext_hdl + 24008) = v104;
    qdf_mem_copy((void *)(ext_hdl + 24012), v105, v104);
  }
  v106 = *(_QWORD *)(a5 + 416);
  if ( v106 )
  {
LABEL_62:
    _qdf_mem_free(v106);
    *(_QWORD *)(a5 + 416) = 0;
    *(_DWORD *)(a5 + 408) = 0;
  }
LABEL_63:
  if ( *(_BYTE *)(v62 + 2293) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Tspec EID present in assoc rsp",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "lim_update_ese_tspec");
    v115 = *(unsigned __int8 *)(v62 + 2036);
    *(_DWORD *)(a5 + 408) = 60 * v115;
    if ( v115 )
    {
      v116 = (void *)_qdf_mem_malloc(60 * v115, "lim_update_ese_tspec", 430);
      *(_QWORD *)(a5 + 416) = v116;
      if ( v116 )
        qdf_mem_copy(v116, (const void *)(v62 + 2040), *(unsigned int *)(a5 + 408));
      else
        *(_DWORD *)(a5 + 408) = 0;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: TSPEC has Zero length",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "lim_update_ese_tspec");
    }
  }
  else
  {
    *(_DWORD *)(a5 + 408) = 0;
    *(_QWORD *)(a5 + 416) = 0;
  }
  if ( (unsigned int)lim_get_capability_info(a1, &v319, a5) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not retrieve Capabilities",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "lim_process_assoc_rsp_frame");
    goto LABEL_72;
  }
  if ( *(_WORD *)(v62 + 4) == 34 && *(_BYTE *)(v62 + 2460) )
  {
    v127 = *(unsigned __int8 *)(v62 + 2462);
    v128 = *(_BYTE *)(v62 + 2461);
    v325 = 0;
    v326 = 0;
    v323 = 0;
    v324 = 0;
    v321 = 0;
    v322 = 0;
    v320[0] = 0;
    v320[1] = 0;
    if ( v127 )
    {
      v129 = v128 + *(_BYTE *)(a2 + 8);
    }
    else
    {
      v130 = *(_DWORD *)(a2 + 8);
      rssi_denylist_threshold = dlm_get_rssi_denylist_threshold(*(_QWORD *)(a1 + 21560));
      v127 = *(unsigned __int8 *)(v62 + 2462);
      v129 = v130 + rssi_denylist_threshold + v128;
    }
    BYTE4(v322) = v129;
    LODWORD(v322) = 1000 * v127;
    qdf_mem_copy(&v321, (const void *)(v29 + 10), 6u);
    v324 = 0x100000005LL;
    LODWORD(v325) = v322;
    system_time = qdf_mc_timer_get_system_time();
    v133 = *(_QWORD *)(a1 + 21560);
    v134 = *(unsigned __int8 *)(a5 + 10);
    v326 = system_time;
    lim_add_bssid_to_reject_list(v133, v134, v320);
    v92 = a5 + 7047;
  }
  if ( !(unsigned int)lim_handle_pmfcomeback_timer(a5, v62) )
    goto LABEL_72;
  if ( a4 )
    lim_stop_reassoc_retry_timer(a1);
  else
    lim_deactivate_and_change_timer(a1, 5);
  if ( *(_WORD *)(v62 + 4) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received Re/AssocRsp frame failure code: %d",
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      "lim_process_assoc_rsp_frame");
    LODWORD(v318) = 516;
    if ( lim_search_pre_auth_list(a1, v29 + 10) )
    {
      lim_delete_pre_auth_node(a1, v29 + 10);
      if ( !a4 )
        goto LABEL_104;
      goto LABEL_102;
    }
LABEL_101:
    if ( !a4 )
      goto LABEL_104;
    goto LABEL_102;
  }
  if ( (*(_WORD *)(v62 + 2) & 0x3FF8u) >= 0x7D8 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received Re/AssocRsp frame with invalid aid: %X",
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      "lim_process_assoc_rsp_frame");
LABEL_99:
    v168 = v29 + 10;
    v169 = a1;
    LODWORD(v318) = 523;
    WORD2(v318) = 1;
LABEL_100:
    lim_send_disassoc_mgmt_frame(v169, 1, v168, a5, 0);
    goto LABEL_101;
  }
  if ( (lim_verify_fils_params_assoc_rsp(a1, a5, v62, &v318) & 1) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: FILS params does not match",
      v151,
      v152,
      v153,
      v154,
      v155,
      v156,
      v157,
      v158,
      "lim_process_assoc_rsp_frame");
    goto LABEL_99;
  }
  v159 = (void *)(a5 + 7365);
  if ( *(_BYTE *)(v62 + 2337) )
    qdf_mem_copy(v159, (const void *)(v62 + 2337), 0x3Cu);
  else
    qdf_mem_set(v159, 0x3Cu, 0);
  if ( *(_BYTE *)(v62 + 2444) )
    lim_update_obss_scanparams(a5, v62 + 2444);
  if ( *(_BYTE *)(v92 + 1629) == 1 )
  {
    if ( !wlan_cm_is_vdev_roaming(*(_QWORD *)(a5 + 16), v160, v161, v162, v163, v164, v165, v166, v167) )
      lim_set_twt_peer_capabilities(a1, (__int64)v327, v62 + 2508, v62 + 2568);
  }
  else
  {
    wlan_twt_cfg_get_req_support_for_ht_vht(*(_QWORD *)(a1 + 21552), v317);
    if ( v317[0] == 1 && *(_BYTE *)(a5 + 155) && *(_BYTE *)(v62 + 244) && *(_BYTE *)(v62 + 2318) )
      lim_set_twt_ext_capabilities(a1, (__int64)v327, v62 + 2320);
  }
  lim_diag_event_report(a1, 71, a5, 16 * (unsigned int)(*(_WORD *)(v62 + 4) != 0));
  nss_supported_by_ap = lim_get_nss_supported_by_ap(v62 + 2296, (_BYTE *)(v62 + 244), v62 + 2508);
  wlan_mlme_set_ap_nss(*(_QWORD *)(a5 + 16), nss_supported_by_ap, v185, v186, v187, v188, v189, v190, v191, v192);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: AP supported NSS = %u",
    v193,
    v194,
    v195,
    v196,
    v197,
    v198,
    v199,
    v200,
    "lim_process_assoc_rsp_frame",
    (unsigned __int8)nss_supported_by_ap);
  if ( !v316 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Successfully Associated with BSS %02x:%02x:%02x:**:**:%02x",
      v201,
      v202,
      v203,
      v204,
      v205,
      v206,
      v207,
      v208,
      "lim_process_assoc_rsp_frame",
      *(unsigned __int8 *)(v29 + 10),
      *(unsigned __int8 *)(v29 + 11),
      *(unsigned __int8 *)(v29 + 12),
      *(unsigned __int8 *)(v29 + 15));
    if ( *(_BYTE *)(a5 + 7047) )
      *(_BYTE *)(a5 + 7050) = 0;
    *(_WORD *)(a5 + 180) = *(_WORD *)(v62 + 2) & 0x3FFF;
    hash_entry = dph_get_hash_entry(a1, 1u, a5 + 360);
    if ( hash_entry )
    {
      v247 = hash_entry;
      if ( lim_search_pre_auth_list(a1, v29 + 10) )
        lim_delete_pre_auth_node(a1, v29 + 10);
      v248 = *(unsigned __int8 *)(a5 + 8635);
      if ( (unsigned int)v248 > (unsigned __int8)nss_supported_by_ap )
      {
        v248 = nss_supported_by_ap;
        *(_BYTE *)(a5 + 8635) = nss_supported_by_ap;
      }
      lim_objmgr_update_vdev_nss(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a5 + 10), v248);
      lim_update_vdev_rate_set(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a5 + 10), v62);
      v249 = _qdf_mem_malloc(0xD80u, "lim_process_assoc_rsp_frame", 1823);
      if ( v249 )
      {
        v250 = v249;
        ielen_from_bss_description = wlan_get_ielen_from_bss_description(*(_QWORD *)(a5 + 112) + 4364LL);
        v252 = *(_QWORD *)(a5 + 112);
        v253 = ielen_from_bss_description;
        ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))lim_update_iot_aggr_sz)(
          a1,
          v252 + 4468,
          (unsigned __int16)ielen_from_bss_description,
          a5);
        lim_extract_ap_capabilities(a1, v252 + 4468, v253, (void *)v250);
        if ( !*(_DWORD *)(a5 + 7036) )
          lim_enable_cts_to_self_for_exempted_iot_ap(a1, a5, v252 + 4468, v253);
        lim_update_assoc_sta_datas(a1, v247, (unsigned __int16 *)v62, a5);
        if ( *(_BYTE *)(a5 + 8676) == 1 )
        {
          v262 = *(unsigned __int8 *)(v62 + 2716);
          *(_BYTE *)(a5 + 10041) = v262;
          if ( v262 == 1 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Save MU EDCA params to session",
              v254,
              v255,
              v256,
              v257,
              v258,
              v259,
              v260,
              v261,
              "lim_process_assoc_rsp_frame");
            v263 = *(_DWORD *)(v62 + 2721);
            *(_BYTE *)(a5 + 10025) = *(_BYTE *)(v62 + 2725);
            *(_DWORD *)(a5 + 10021) = v263;
            v264 = *(_DWORD *)(v62 + 2726);
            *(_BYTE *)(a5 + 10030) = *(_BYTE *)(v62 + 2730);
            *(_DWORD *)(a5 + 10026) = v264;
            v265 = *(_DWORD *)(v62 + 2731);
            *(_BYTE *)(a5 + 10035) = *(_BYTE *)(v62 + 2735);
            *(_DWORD *)(a5 + 10031) = v265;
            v266 = *(_DWORD *)(v62 + 2736);
            *(_BYTE *)(a5 + 10040) = *(_BYTE *)(v62 + 2740);
            *(_DWORD *)(a5 + 10036) = v266;
          }
        }
        if ( *(_BYTE *)(v250 + 2484) )
        {
          v267 = *(_QWORD *)(v250 + 2492);
          *(_QWORD *)(v247 + 708) = *(_QWORD *)(v250 + 2484);
          *(_QWORD *)(v247 + 716) = v267;
        }
        if ( *(_BYTE *)(v250 + 1200) )
        {
          v268 = *(_QWORD *)(v250 + 1216);
          v269 = *(_QWORD *)(v250 + 1200);
          v270 = *(_QWORD *)(v250 + 1208);
          *(_QWORD *)(v247 + 672) = *(_QWORD *)(v250 + 1224);
          *(_QWORD *)(v247 + 664) = v268;
          *(_QWORD *)(v247 + 656) = v270;
          *(_QWORD *)(v247 + 648) = v269;
          v271 = *(_QWORD *)(v250 + 1232);
          v272 = *(_QWORD *)(v250 + 1240);
          v273 = *(_QWORD *)(v250 + 1248);
          *(_DWORD *)(v247 + 704) = *(_DWORD *)(v250 + 1256);
          *(_QWORD *)(v247 + 680) = v271;
          *(_QWORD *)(v247 + 696) = v273;
          *(_QWORD *)(v247 + 688) = v272;
        }
        if ( *(_BYTE *)(v250 + 2570) )
          *(_DWORD *)(v247 + 788) = *(_DWORD *)(v250 + 2570);
        if ( *(_BYTE *)(v250 + 1260) )
        {
          v274 = *(_QWORD *)(v250 + 1284);
          v275 = *(_QWORD *)(v250 + 1260);
          v276 = *(_QWORD *)(v250 + 1268);
          *(_QWORD *)(v247 + 740) = *(_QWORD *)(v250 + 1276);
          *(_QWORD *)(v247 + 748) = v274;
          *(_QWORD *)(v247 + 724) = v275;
          *(_QWORD *)(v247 + 732) = v276;
          v277 = *(_QWORD *)(v250 + 1292);
          v278 = *(_QWORD *)(v250 + 1300);
          v279 = *(_QWORD *)(v250 + 1308);
          *(_WORD *)(v247 + 780) = *(_WORD *)(v250 + 1316);
          *(_QWORD *)(v247 + 756) = v277;
          *(_QWORD *)(v247 + 764) = v278;
          *(_QWORD *)(v247 + 772) = v279;
        }
        if ( *(_BYTE *)(v250 + 2500) )
        {
          v280 = *(_DWORD *)(v250 + 2500);
          *(_WORD *)(v247 + 786) = *(_WORD *)(v250 + 2504);
          *(_DWORD *)(v247 + 782) = v280;
        }
        if ( *(_BYTE *)(v250 + 2700) )
        {
          v281 = *(_QWORD *)(v250 + 2700);
          v282 = *(_QWORD *)(v250 + 2708);
          *(_WORD *)(v247 + 808) = *(_WORD *)(v250 + 2716);
          *(_QWORD *)(v247 + 800) = v282;
          *(_QWORD *)(v247 + 792) = v281;
        }
        if ( *(_BYTE *)(v62 + 2586) )
        {
          v283 = *(_QWORD *)(v62 + 2586);
          v284 = *(_QWORD *)(v62 + 2594);
          *(_QWORD *)(v247 + 823) = *(_QWORD *)(v62 + 2599);
          *(_QWORD *)(v247 + 810) = v283;
          *(_QWORD *)(v247 + 818) = v284;
          lim_update_vdev_sr_elements(a5, v247, v254, v255, v256, v257, v258, v259, v260, v261);
        }
        if ( *(_BYTE *)(a1 + 8884) )
          lim_decide_sta_protection_on_assoc(a1, v250, a5);
        if ( *(_BYTE *)(v250 + 2475) )
          *(_BYTE *)(a5 + 7160) = ((*(unsigned __int8 *)(v250 + 1132) >> 2) & 1) == 0;
        lim_diag_event_report(a1, 61, a5, 0);
        lim_update_stads_ext_cap(a1, a5, v62, v247);
        if ( !(unsigned int)lim_sta_send_add_bss(a1, (_BYTE *)v62, v250, *(_QWORD *)(a5 + 112) + 4364LL, 1u, a5) )
        {
          clean_up_ft_sha384(v62, is_sha384_akm & 1);
          if ( *(_QWORD *)(a5 + 240) != v62 )
            _qdf_mem_free(v62);
          v126 = v250;
          goto LABEL_75;
        }
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: vdev:%d could not update the bss entry",
          v285,
          v286,
          v287,
          v288,
          v289,
          v290,
          v291,
          v292,
          "lim_process_assoc_rsp_frame",
          *(unsigned __int8 *)(a5 + 10));
        v125 = v250;
        WORD2(v318) = 1;
        LODWORD(v318) = 502;
        if ( a4 )
          goto LABEL_73;
        goto LABEL_105;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: could not get hash entry at DPH SA: %02x:%02x:%02x:**:**:%02x",
        v239,
        v240,
        v241,
        v242,
        v243,
        v244,
        v245,
        v246,
        "lim_process_assoc_rsp_frame",
        *(unsigned __int8 *)(v29 + 10),
        *(unsigned __int8 *)(v29 + 11),
        *(unsigned __int8 *)(v29 + 12),
        *(unsigned __int8 *)(v29 + 15));
      LODWORD(v318) = 502;
      WORD2(v318) = 0;
      lim_process_mlm_rsp_messages(a1, 1010, &v318);
    }
    clean_up_ft_sha384(v62, is_sha384_akm & 1);
    if ( *(_QWORD *)(a5 + 240) == v62 )
      goto LABEL_76;
    goto LABEL_74;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Successfully Reassociated with BSS",
    v201,
    v202,
    v203,
    v204,
    v205,
    v206,
    v207,
    v208,
    "lim_process_assoc_rsp_frame");
  if ( *(_BYTE *)(v62 + 2294) )
    lim_update_ese_tsm(a1, a5, v62);
  v209 = *(_QWORD *)(a5 + 128);
  if ( v209 )
  {
    _qdf_mem_free(v209);
    *(_QWORD *)(a5 + 128) = 0;
  }
  v210 = *(_QWORD *)(a5 + 240);
  if ( v210 )
  {
    _qdf_mem_free(*(_QWORD *)(v210 + 680));
    _qdf_mem_free(*(_QWORD *)(v210 + 744));
    _qdf_mem_free(*(_QWORD *)(a5 + 240));
  }
  *(_QWORD *)(a5 + 240) = v62;
  v211 = dph_get_hash_entry(a1, 1u, a5 + 360);
  if ( !v211 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not get hash entry at DPH for SA: %02x:%02x:%02x:**:**:%02x",
      v212,
      v213,
      v214,
      v215,
      v216,
      v217,
      v218,
      v219,
      "lim_process_assoc_rsp_frame",
      *(unsigned __int8 *)(v29 + 10),
      *(unsigned __int8 *)(v29 + 11),
      *(unsigned __int8 *)(v29 + 12),
      *(unsigned __int8 *)(v29 + 15));
    WORD2(v318) = 1;
    v169 = a1;
    LODWORD(v318) = 523;
    v168 = v29 + 10;
    goto LABEL_100;
  }
  v220 = (__int16 *)v211;
  v221 = *(unsigned __int8 *)(a5 + 8635);
  if ( (unsigned int)v221 > (unsigned __int8)nss_supported_by_ap )
  {
    v221 = nss_supported_by_ap;
    *(_BYTE *)(a5 + 8635) = nss_supported_by_ap;
  }
  lim_objmgr_update_vdev_nss(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a5 + 10), v221);
  lim_update_vdev_rate_set(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a5 + 10), v62);
  if ( *(_DWORD *)(a5 + 72) != 28
    && !wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v222, v223, v224, v225, v226, v227, v228, v229) )
  {
    if ( (unsigned __int8)sir_compare_mac_addr(a5 + 24, a5 + 182)
      || (*(_WORD *)(a5 + 7274) = 0,
          !(unsigned int)lim_cleanup_rx_path(a1, v220, a5, 1, v293, v294, v295, v296, v297, v298, v299, v300)) )
    {
      *(_BYTE *)(a5 + 10073) = 1;
      goto LABEL_76;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Could not cleanup the rx path",
      v301,
      v302,
      v303,
      v304,
      v305,
      v306,
      v307,
      v308,
      "lim_process_assoc_rsp_frame");
    if ( !a4 )
      goto LABEL_104;
LABEL_102:
    if ( !v316 )
      goto LABEL_72;
    if ( *(_DWORD *)(a5 + 72) != 28 )
    {
      is_vdev_roaming = cm_is_vdev_roaming(*(_QWORD *)(a5 + 16), v143, v144, v145, v146, v147, v148, v149, v150);
      v125 = 0;
      if ( is_vdev_roaming )
        goto LABEL_73;
LABEL_105:
      v170 = v125;
      LODWORD(v312) = *(unsigned __int8 *)(v29 + 12);
      LODWORD(v314) = *(unsigned __int8 *)(v29 + 15);
      *(_DWORD *)v310 = *(unsigned __int8 *)(v29 + 11);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Assoc Rejected by the peer mlmestate: %d sessionid: %d Reason: %d MACADDR:%02x:%02x:%02x:**:**:%02x",
        v143,
        v144,
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        "lim_process_assoc_rsp_frame",
        *(unsigned int *)(a5 + 72),
        *(unsigned __int16 *)(a5 + 8),
        (unsigned int)v318,
        *(unsigned __int8 *)(v29 + 10),
        *(_QWORD *)v310,
        v312,
        v314);
      v171 = *(_WORD *)(a5 + 8);
      *(_DWORD *)(a5 + 72) = 1;
      qdf_trace(53, 0, v171, 1);
      v180 = *(_QWORD *)(a5 + 128);
      if ( v180 )
      {
        _qdf_mem_free(v180);
        *(_QWORD *)(a5 + 128) = 0;
      }
      if ( a4 && cm_is_vdev_roaming(*(_QWORD *)(a5 + 16), v172, v173, v174, v175, v176, v177, v178, v179) )
      {
        v181 = a1;
        v182 = 1015;
        LODWORD(v318) = 537;
      }
      else
      {
        v181 = a1;
        v182 = 1010;
      }
      lim_process_mlm_rsp_messages(v181, v182, &v318);
      v125 = v170;
      goto LABEL_73;
    }
LABEL_104:
    v125 = 0;
    goto LABEL_105;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending self sta",
    v222,
    v223,
    v224,
    v225,
    v226,
    v227,
    v228,
    v229,
    "lim_process_assoc_rsp_frame");
  lim_update_assoc_sta_datas(a1, (__int64)v220, (unsigned __int16 *)v62, a5);
  lim_update_stads_ext_cap(a1, a5, v62, v220);
  *(_WORD *)(a5 + 180) = *(_WORD *)(v62 + 2) & 0x3FFF;
  lim_set_active_edca_params(a1, a5 + 7096, a5);
  if ( !wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a5 + 16), v230, v231, v232, v233, v234, v235, v236, v237) )
    lim_send_edca_params(a1, a5 + 7136, *(unsigned __int8 *)(a5 + 10), 0);
LABEL_76:
  _ReadStatusReg(SP_EL0);
}
