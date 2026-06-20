unsigned int *__fastcall dp_htt_bkp_event_alert(unsigned int *result, _QWORD *a2)
{
  __int64 v2; // x25
  unsigned int v3; // w23
  unsigned int *v4; // x21
  __int64 v6; // x20
  int v7; // w22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x1
  unsigned int v17; // w22
  _BYTE *v18; // x8
  int v19; // w5
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int64 v28; // x8
  unsigned int v29; // w24
  unsigned __int8 *v30; // x25
  unsigned int v31; // w21
  unsigned __int64 v32; // x20
  unsigned int v33; // w22
  unsigned __int8 *v34; // x27
  unsigned __int64 *v35; // x8
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x11
  unsigned __int64 v38; // x10
  unsigned __int64 *v39; // x8
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x11
  unsigned __int64 v42; // x10
  __int64 v43; // x26
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _QWORD *v60; // x8
  __int64 v61; // x27
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x28
  __int64 v71; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  _QWORD *v80; // x8
  __int64 v81; // x22
  __int64 v82; // x9
  int v83; // w20
  __int64 v84; // x10
  __int64 v85; // x13
  void (*v86)(void); // x8
  _DWORD *v87; // x19
  __int64 v88; // x10
  __int64 v89; // x9
  __int64 v90; // x13
  void (*v91)(void); // x8
  _DWORD *v92; // x19
  __int64 v93; // x10
  __int64 v94; // x9
  __int64 v95; // x13
  void (*v96)(void); // x8
  _DWORD *v97; // x19
  __int64 v98; // x10
  __int64 v99; // x9
  __int64 v100; // x12
  void (*v101)(void); // x8
  unsigned int v102; // w19
  __int64 v103; // x21
  __int64 v104; // x8
  __int64 *v105; // x9
  _DWORD *v106; // x20
  __int64 v107; // x10
  int v108; // w11
  bool v109; // zf
  __int64 v110; // x11
  __int64 v111; // x11
  void (*v112)(void); // x8
  _DWORD *v113; // x19
  __int64 v114; // x9
  __int64 v115; // x10
  __int64 v116; // x13
  void (*v117)(void); // x8
  _DWORD *v118; // x21
  __int64 v119; // x9
  __int64 v120; // x10
  __int64 v121; // x13
  void (*v122)(void); // x8
  __int64 v123; // x0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x8
  unsigned __int64 v133; // x21
  __int64 v134; // x22
  unsigned int v135; // w20
  __int64 *v136; // x9
  _DWORD *v137; // x20
  __int64 v138; // x10
  int v139; // w11
  bool v140; // zf
  __int64 v141; // x11
  __int64 v142; // x11
  void (*v143)(void); // x8
  __int64 v144; // x19
  __int64 v145; // x8
  __int64 *v146; // x9
  __int64 v147; // x26
  _DWORD *v148; // x28
  __int64 v149; // x10
  int v150; // w11
  bool v151; // zf
  __int64 v152; // x11
  __int64 v153; // x11
  void (*v154)(void); // x8
  bool v155; // cf
  __int64 v156; // x0
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int64 v165; // x21
  unsigned int v166; // w19
  __int64 v167; // x8
  unsigned int v168; // w9
  __int64 *v169; // x10
  _DWORD *v170; // x19
  __int64 v171; // x11
  __int64 v172; // x9
  __int64 v173; // x14
  void (*v174)(void); // x8
  unsigned int v175; // w21
  unsigned int v176; // w24
  _DWORD *v177; // x21
  __int64 v178; // x9
  __int64 v179; // x10
  __int64 v180; // x13
  void (*v181)(void); // x8
  __int64 *v182; // x10
  unsigned int v183; // w9
  _DWORD *v184; // x19
  __int64 v185; // x11
  __int64 v186; // x9
  __int64 v187; // x14
  void (*v188)(void); // x8
  bool v189; // cc
  __int64 *v190; // x10
  _DWORD *v191; // x19
  __int64 v192; // x9
  __int64 v193; // x11
  __int64 v194; // x14
  void (*v195)(void); // x8
  __int64 v196; // x0
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  __int64 v205; // x20
  int v206; // w19
  double v207; // d0
  double v208; // d1
  double v209; // d2
  double v210; // d3
  double v211; // d4
  double v212; // d5
  double v213; // d6
  double v214; // d7
  unsigned int v215; // w19
  __int64 v216; // x8
  unsigned int v217; // w27
  unsigned int v218; // w9
  __int64 *v219; // x10
  _DWORD *v220; // x20
  __int64 v221; // x11
  int v222; // w9
  bool v223; // zf
  __int64 v224; // x9
  _DWORD *v225; // x9
  __int64 v226; // x11
  void (*v227)(void); // x8
  __int64 v228; // x9
  __int64 *v229; // x8
  _DWORD *v230; // x19
  __int64 v231; // x10
  int v232; // w11
  bool v233; // zf
  __int64 v234; // x11
  __int64 v235; // x11
  void (*v236)(void); // x8
  __int64 *v237; // x10
  _DWORD *v238; // x20
  __int64 v239; // x11
  int v240; // w9
  bool v241; // zf
  __int64 v242; // x9
  _DWORD *v243; // x9
  __int64 v244; // x11
  void (*v245)(void); // x8
  __int64 *v246; // x10
  _DWORD *v247; // x20
  __int64 v248; // x9
  int v249; // w11
  bool v250; // zf
  __int64 v251; // x11
  __int64 v252; // x11
  void (*v253)(void); // x8
  __int64 v254; // x0
  __int64 v255; // x0
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  __int64 v264; // x0
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  __int64 v273; // x0
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  __int64 v282; // x20
  unsigned int v283; // w19
  __int64 v284; // x8
  __int64 *v285; // x9
  _DWORD *v286; // x19
  __int64 v287; // x10
  __int64 v288; // x11
  __int64 v289; // x14
  void (*v290)(void); // x8
  unsigned int v291; // w19
  __int64 v292; // x21
  double v293; // d0
  double v294; // d1
  double v295; // d2
  double v296; // d3
  double v297; // d4
  double v298; // d5
  double v299; // d6
  double v300; // d7
  unsigned int v301; // w9
  __int64 v302; // x8
  __int64 *v303; // x9
  _DWORD *v304; // x21
  __int64 v305; // x10
  int v306; // w11
  bool v307; // zf
  __int64 v308; // x11
  __int64 v309; // x11
  void (*v310)(void); // x8
  __int64 v311; // x0
  double v312; // d0
  double v313; // d1
  double v314; // d2
  double v315; // d3
  double v316; // d4
  double v317; // d5
  double v318; // d6
  double v319; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int8 *v321; // x20
  unsigned int v322; // w8
  __int64 v323; // x0
  __int64 v324; // x8
  _QWORD *v325; // x9
  _QWORD *v326; // x8
  __int64 *v327; // x8
  int v328; // w9
  __int64 v329; // x8
  __int64 v330; // x0
  __int64 v331; // x0
  double v332; // d0
  double v333; // d1
  double v334; // d2
  double v335; // d3
  double v336; // d4
  double v337; // d5
  double v338; // d6
  double v339; // d7
  __int64 v340; // x4
  __int64 v341; // x0
  __int64 v342; // [xsp+8h] [xbp-18h]
  unsigned __int8 *v343; // [xsp+10h] [xbp-10h]
  __int64 v344; // [xsp+18h] [xbp-8h]

  if ( !a2 )
    return result;
  v2 = a2[1];
  v3 = *result;
  v4 = result;
  v6 = *(_QWORD *)(v2 + 40);
  v7 = (unsigned __int8)BYTE1(*result);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v6) )
  {
    if ( v7 )
      v16 = (unsigned int)(v7 - 1);
    else
      v16 = 0;
    v17 = ((__int64 (__fastcall *)(_QWORD, __int64))wlan_cfg_get_hw_mac_idx)(*(_QWORD *)(v2 + 40), v16);
    if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v2 + 40))
      || !(unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(v2 + 40), v17) )
    {
      v18 = *(_BYTE **)(v2 + 72);
      if ( v18 )
      {
        if ( !*v18 )
          goto LABEL_18;
      }
    }
    return (unsigned int *)qdf_trace_msg(
                             0x80u,
                             8u,
                             "%s: %pK: pdev id %d is invalid",
                             v8,
                             v9,
                             v10,
                             v11,
                             v12,
                             v13,
                             v14,
                             v15,
                             "dp_htt_bkp_event_alert",
                             a2);
  }
  if ( v7 )
    v19 = v7 - 1;
  else
    v19 = 0;
  if ( v19 )
    return (unsigned int *)qdf_trace_msg(
                             0x80u,
                             8u,
                             "%s: %pK: pdev id %d is invalid",
                             v8,
                             v9,
                             v10,
                             v11,
                             v12,
                             v13,
                             v14,
                             v15,
                             "dp_htt_bkp_event_alert",
                             a2);
LABEL_18:
  result = (unsigned int *)wlan_cfg_time_control_bp(v6);
  v28 = *v4;
  v29 = v4[1];
  v30 = *(unsigned __int8 **)(v2 + 72);
  v31 = v4[2];
  v32 = v28 >> 24;
  v33 = HIWORD(v29);
  v34 = v30 + 94208;
  if ( BYTE2(v3) == 1 )
  {
    v39 = (unsigned __int64 *)(a2[4] + 32LL * (unsigned int)v32);
    if ( !v39 )
      return result;
    v40 = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    if ( *v39 == -1 )
    {
      *v39 = v40;
      v39[1] = v40;
      v39[2] = 0;
      v39[3] = 1;
    }
    else
    {
      v41 = v39[3];
      v42 = v40 - *v39;
      v39[1] = v40;
      v39[2] = v42;
      v39[3] = v41 + 1;
      if ( v42 < (unsigned int)result )
        return result;
      *v39 = -1;
    }
    if ( (unsigned int)(v32 - 9) <= 4 )
      *(_BYTE *)(*((_QWORD *)v30 + 11945) + 37093LL) = 1;
    v61 = a2[4];
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: seq_num %u msg_type: %d pdev_id: %d ring_type: %s ",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_htt_alert_print",
      *((unsigned int *)v30 + 23880),
      (unsigned __int8)v3,
      *v30,
      "HTT_SW_RING_TYPE_LMAC");
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: ring_id: %d hp_idx: %d tp_idx: %d bkpressure_time_ms: %d ",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "dp_htt_alert_print",
      (unsigned int)v32,
      (unsigned __int16)v29,
      v33,
      v31);
    v60 = (_QWORD *)(v61 + 32LL * (unsigned int)v32);
    v34 = v30 + 94208;
  }
  else
  {
    if ( BYTE2(v3) )
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s: Invalid ring type: %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "dp_htt_bkp_event_alert");
      goto LABEL_36;
    }
    v35 = (unsigned __int64 *)(a2[3] + 32 * v32);
    if ( !v35 )
      return result;
    v36 = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    if ( *v35 == -1 )
    {
      *v35 = v36;
      v35[1] = v36;
      v35[2] = 0;
      v35[3] = 1;
    }
    else
    {
      v37 = v35[3];
      v38 = v36 - *v35;
      v35[1] = v36;
      v35[2] = v38;
      v35[3] = v37 + 1;
      if ( v38 < (unsigned int)result )
        return result;
      *v35 = -1;
    }
    v43 = a2[3];
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: seq_num %u msg_type: %d pdev_id: %d ring_type: %s ",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_htt_alert_print",
      *((unsigned int *)v30 + 23880),
      (unsigned __int8)v3,
      *v30,
      "HTT_SW_RING_TYPE_UMAC");
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: ring_id: %d hp_idx: %d tp_idx: %d bkpressure_time_ms: %d ",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "dp_htt_alert_print",
      (unsigned int)v32,
      (unsigned __int16)v29,
      v33,
      v31);
    v60 = (_QWORD *)(v43 + 32 * v32);
  }
  qdf_trace_msg(
    0x45u,
    1u,
    "%s: last_bp_event: %ld, total_bp_duration: %ld, bp_counter: %ld",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    "dp_htt_alert_print",
    v60[1],
    v60[2],
    v60[3]);
LABEL_36:
  v70 = *((_QWORD *)v30 + 1);
  v71 = _qdf_mem_malloc(0x518u, "dp_queue_ring_stats", 3316);
  if ( !v71 )
    return (unsigned int *)qdf_trace_msg(
                             0x80u,
                             1u,
                             "%s: Memory alloc failed for back pressure event",
                             v72,
                             v73,
                             v74,
                             v75,
                             v76,
                             v77,
                             v78,
                             v79,
                             "dp_queue_ring_stats");
  v80 = *((_QWORD **)v30 + 1);
  v81 = v71;
  v344 = v71 + 8;
  v342 = v71;
  v343 = v34;
  if ( !v80 )
  {
    v83 = 0;
    goto LABEL_84;
  }
  v82 = v80[794];
  if ( v82 )
  {
    v83 = 1;
    v84 = 16;
    if ( *(_DWORD *)(v82 + 116) )
      v85 = 16;
    else
      v85 = 12;
    if ( *(_DWORD *)(v82 + 116) )
      v84 = 12;
    *(_DWORD *)(v71 + v85) = *(_DWORD *)(v82 + 120);
    *(_DWORD *)(v71 + v84) = **(_DWORD **)(v82 + 128);
    v86 = *(void (**)(void))(*(_QWORD *)(v80[141] + 74392LL) + 24LL);
    if ( *((_DWORD *)v86 - 1) != 1884881292 )
      __break(0x8228u);
    v86();
    *(_DWORD *)(v81 + 8) = 1;
    v80 = *((_QWORD **)v30 + 1);
    if ( !v80 )
      goto LABEL_84;
    v87 = (_DWORD *)(v81 + 28);
    LODWORD(v82) = 1;
  }
  else
  {
    v87 = (_DWORD *)(v71 + 8);
    v83 = 0;
  }
  if ( v87 )
  {
    v88 = v80[804];
    if ( v88 )
    {
      v89 = 2;
      if ( *(_DWORD *)(v88 + 116) )
        v90 = 2;
      else
        v90 = 1;
      if ( *(_DWORD *)(v88 + 116) )
        v89 = 1;
      v87[v90] = *(_DWORD *)(v88 + 120);
      v87[v89] = **(_DWORD **)(v88 + 128);
      v91 = *(void (**)(void))(*(_QWORD *)(v80[141] + 74392LL) + 24LL);
      if ( *((_DWORD *)v91 - 1) != 1884881292 )
        __break(0x8228u);
      v91();
      *v87 = 2;
      ++v83;
      v80 = *((_QWORD **)v30 + 1);
      if ( !v80 )
        goto LABEL_84;
      LODWORD(v82) = v83;
    }
  }
  v92 = (_DWORD *)(v344 + 20LL * (unsigned int)v82);
  if ( v92 )
  {
    v93 = v80[814];
    if ( v93 )
    {
      v94 = 2;
      if ( *(_DWORD *)(v93 + 116) )
        v95 = 2;
      else
        v95 = 1;
      if ( *(_DWORD *)(v93 + 116) )
        v94 = 1;
      v92[v95] = *(_DWORD *)(v93 + 120);
      v92[v94] = **(_DWORD **)(v93 + 128);
      v96 = *(void (**)(void))(*(_QWORD *)(v80[141] + 74392LL) + 24LL);
      if ( *((_DWORD *)v96 - 1) != 1884881292 )
        __break(0x8228u);
      v96();
      *v92 = 3;
      ++v83;
      v80 = *((_QWORD **)v30 + 1);
      if ( !v80 )
        goto LABEL_84;
      LODWORD(v82) = v83;
    }
  }
  v97 = (_DWORD *)(v344 + 20LL * (unsigned int)v82);
  if ( !v97 )
    goto LABEL_101;
  v98 = v80[824];
  if ( !v98 )
    goto LABEL_101;
  v99 = 2;
  if ( *(_DWORD *)(v98 + 116) )
    v100 = 2;
  else
    v100 = 1;
  if ( *(_DWORD *)(v98 + 116) )
    v99 = 1;
  v97[v100] = *(_DWORD *)(v98 + 120);
  v97[v99] = **(_DWORD **)(v98 + 128);
  v101 = *(void (**)(void))(*(_QWORD *)(v80[141] + 74392LL) + 24LL);
  if ( *((_DWORD *)v101 - 1) != 1884881292 )
    __break(0x8228u);
  v101();
  *v97 = 4;
  ++v83;
  v80 = *((_QWORD **)v30 + 1);
  if ( !v80 )
  {
LABEL_84:
    v102 = v83 + 2;
    goto LABEL_85;
  }
  LODWORD(v82) = v83;
LABEL_101:
  v113 = (_DWORD *)(v344 + 20LL * (unsigned int)v82);
  if ( v113 && (v114 = v80[834]) != 0 )
  {
    v115 = 2;
    if ( *(_DWORD *)(v114 + 116) )
      v116 = 2;
    else
      v116 = 1;
    if ( *(_DWORD *)(v114 + 116) )
      v115 = 1;
    v113[v116] = *(_DWORD *)(v114 + 120);
    v113[v115] = **(_DWORD **)(v114 + 128);
    v117 = *(void (**)(void))(*(_QWORD *)(v80[141] + 74392LL) + 24LL);
    if ( *((_DWORD *)v117 - 1) != 1884881292 )
      __break(0x8228u);
    v117();
    *v113 = 13;
    v102 = v83 + 3;
    v80 = *((_QWORD **)v30 + 1);
    if ( !v80 )
      goto LABEL_85;
    ++v83;
  }
  else
  {
    v102 = v83 + 2;
  }
  v118 = (_DWORD *)(v344 + 20LL * v102);
  if ( v118 )
  {
    v119 = v80[965];
    if ( v119 )
    {
      v120 = 2;
      if ( *(_DWORD *)(v119 + 116) )
        v121 = 2;
      else
        v121 = 1;
      if ( *(_DWORD *)(v119 + 116) )
        v120 = 1;
      v118[v121] = *(_DWORD *)(v119 + 120);
      v118[v120] = **(_DWORD **)(v119 + 128);
      v122 = *(void (**)(void))(*(_QWORD *)(v80[141] + 74392LL) + 24LL);
      if ( *((_DWORD *)v122 - 1) != 1884881292 )
        __break(0x8228u);
      v122();
      *v118 = 12;
      v102 = v83 + 3;
    }
  }
LABEL_85:
  v103 = 0;
  while ( 1 )
  {
    v104 = *((_QWORD *)v30 + 1);
    if ( !v104 )
      goto LABEL_86;
    v105 = (__int64 *)(v104 + v103 + 5712);
    if ( !v105 )
      goto LABEL_86;
    v106 = (_DWORD *)(v344 + 20LL * v102);
    if ( !v106 )
      goto LABEL_86;
    v107 = *v105;
    if ( !*v105 )
      goto LABEL_86;
    v108 = *(_DWORD *)(v107 + 116);
    v109 = v108 == 0;
    if ( v108 )
      v110 = 2;
    else
      v110 = 1;
    v106[v110] = *(_DWORD *)(v107 + 120);
    if ( v109 )
      v111 = 2;
    else
      v111 = 1;
    v106[v111] = **(_DWORD **)(v107 + 128);
    v112 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v104 + 1128) + 74392LL) + 24LL);
    if ( *((_DWORD *)v112 - 1) != 1884881292 )
      __break(0x8228u);
    v112();
    *v106 = 0;
    if ( v102 >= 0x3F )
      break;
    ++v102;
LABEL_86:
    v103 += 80;
    if ( v103 == 640 )
      goto LABEL_124;
  }
  v123 = printk(
           &unk_9BB309,
           "expr",
           "__dp_assert_always_internal",
           "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
  dump_stack(v123);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Ring number %d crossed max rings %d",
    v124,
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    "dp_validate_ring_num",
    ++v102,
    64);
LABEL_124:
  v132 = *((_QWORD *)v30 + 1);
  if ( !*(_BYTE *)(v132 + 7153) )
  {
    v135 = v102;
    goto LABEL_145;
  }
  v133 = 0;
  v134 = 6752;
  while ( 2 )
  {
    if ( v133 > 5 || v102 > 0x40 )
      goto LABEL_348;
    if ( !v132
      || (v136 = (__int64 *)(v132 + v134)) == nullptr
      || (v137 = (_DWORD *)(v344 + 20LL * v102)) == nullptr
      || (v138 = *v136) == 0 )
    {
      v135 = v102;
      goto LABEL_127;
    }
    v139 = *(_DWORD *)(v138 + 116);
    v140 = v139 == 0;
    if ( v139 )
      v141 = 2;
    else
      v141 = 1;
    v137[v141] = *(_DWORD *)(v138 + 120);
    if ( v140 )
      v142 = 2;
    else
      v142 = 1;
    v137[v142] = **(_DWORD **)(v138 + 128);
    v143 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v132 + 1128) + 74392LL) + 24LL);
    if ( *((_DWORD *)v143 - 1) != 1884881292 )
      __break(0x8228u);
    v143();
    *v137 = 5;
    v135 = v102 + 1;
    if ( v102 <= 0x3E )
    {
      v132 = *((_QWORD *)v30 + 1);
LABEL_127:
      ++v133;
      v134 += 80;
      v102 = v135;
      if ( v133 >= *(unsigned __int8 *)(v132 + 7153) )
        goto LABEL_145;
      continue;
    }
    break;
  }
  v264 = printk(
           &unk_9BB309,
           "expr",
           "__dp_assert_always_internal",
           "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
  dump_stack(v264);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Ring number %d crossed max rings %d",
    v265,
    v266,
    v267,
    v268,
    v269,
    v270,
    v271,
    v272,
    "dp_validate_ring_num",
    v135,
    64);
LABEL_145:
  v144 = 0;
  LODWORD(v134) = 20;
  while ( 2 )
  {
    if ( v135 > 0x40 )
      goto LABEL_348;
    v145 = *((_QWORD *)v30 + 1);
    if ( !v145 || (v146 = (__int64 *)(v145 + v144 + 7320), v145 + v144 == -7320) )
    {
LABEL_147:
      v144 += 80;
      if ( v144 == 400 )
        goto LABEL_164;
      continue;
    }
    break;
  }
  v147 = v70;
  v148 = (_DWORD *)(v344 + 20LL * v135);
  if ( !v148 )
    goto LABEL_146;
  v149 = *v146;
  if ( !*v146 )
    goto LABEL_146;
  v150 = *(_DWORD *)(v149 + 116);
  v151 = v150 == 0;
  if ( v150 )
    v152 = 2;
  else
    v152 = 1;
  v148[v152] = *(_DWORD *)(v149 + 120);
  if ( v151 )
    v153 = 2;
  else
    v153 = 1;
  v148[v153] = **(_DWORD **)(v149 + 128);
  v154 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v145 + 1128) + 74392LL) + 24LL);
  if ( *((_DWORD *)v154 - 1) != 1884881292 )
    __break(0x8228u);
  v154();
  v155 = v135++ >= 0x3F;
  *v148 = 13;
  if ( !v155 )
  {
LABEL_146:
    v70 = v147;
    goto LABEL_147;
  }
  v156 = printk(
           &unk_9BB309,
           "expr",
           "__dp_assert_always_internal",
           "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
  dump_stack(v156);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Ring number %d crossed max rings %d",
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    v163,
    v164,
    "dp_validate_ring_num",
    v135,
    64);
  v70 = v147;
LABEL_164:
  v165 = *((_QWORD *)v30 + 1);
  v166 = *v30;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v165 + 40)) )
  {
    if ( !v166 )
    {
      v166 = *(unsigned __int8 *)(*(_QWORD *)(v165 + 72) + 1LL);
      goto LABEL_167;
    }
    goto LABEL_348;
  }
LABEL_167:
  if ( v166 > 1 || v135 > 0x40 )
    goto LABEL_348;
  v167 = *((_QWORD *)v30 + 1);
  v168 = v135;
  if ( !v167 || (v169 = (__int64 *)(v167 + 80LL * v166 + 80), v167 + 80LL * v166 == -80) )
  {
    v175 = v135;
LABEL_183:
    v135 = v175;
    v176 = v175;
    if ( !v167 )
    {
LABEL_223:
      if ( *(_BYTE *)(*(_QWORD *)(v70 + 40) + 808LL) )
      {
        LODWORD(v134) = 0;
        do
        {
          v205 = *((_QWORD *)v30 + 1);
          v206 = *v30;
          if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v205 + 40)) )
          {
            if ( v206 )
              goto LABEL_348;
            v215 = *(unsigned __int8 *)(*(_QWORD *)(v205 + 72) + 1LL);
          }
          else
          {
            if ( (_DWORD)v134 && v206 )
            {
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: Both mac_id and pdev_id cannot be non zero",
                v207,
                v208,
                v209,
                v210,
                v211,
                v212,
                v213,
                v214,
                "dp_get_lmac_id_for_pdev_id");
              v216 = *((_QWORD *)v30 + 1);
              v215 = 0;
              if ( (*(_BYTE *)(*(_QWORD *)(v216 + 40) + 633LL) & 1) == 0 )
                goto LABEL_254;
              v217 = 0;
              goto LABEL_237;
            }
            v215 = v134 + v206;
          }
          v216 = *((_QWORD *)v30 + 1);
          if ( (*(_BYTE *)(*(_QWORD *)(v216 + 40) + 633LL) & 1) == 0 )
          {
            if ( v215 > 2 )
              goto LABEL_348;
LABEL_254:
            if ( v176 > 0x40 )
              goto LABEL_348;
            goto LABEL_255;
          }
          if ( v215 >= 3 )
            goto LABEL_348;
          v217 = v215;
LABEL_237:
          if ( v176 > 0x40 )
            goto LABEL_348;
          v218 = v176;
          if ( v216
            && (v219 = (__int64 *)(v216 + 80LL * v217 + 480), v216 + 80LL * v217 != -480)
            && (v220 = (_DWORD *)(v344 + 20LL * v176)) != nullptr
            && (v221 = *v219) != 0 )
          {
            v222 = *(_DWORD *)(v221 + 116);
            v223 = v222 == 0;
            if ( v222 )
              v224 = 2;
            else
              v224 = 1;
            v220[v224] = *(_DWORD *)(v221 + 120);
            v225 = *(_DWORD **)(v221 + 128);
            if ( v223 )
              v226 = 2;
            else
              v226 = 1;
            v220[v226] = *v225;
            v227 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v216 + 1128) + 74392LL) + 24LL);
            if ( *((_DWORD *)v227 - 1) != 1884881292 )
              __break(0x8228u);
            v227();
            v189 = v176++ > 0x3E;
            *v220 = 16;
            if ( v189 )
              goto LABEL_301;
            v216 = *((_QWORD *)v30 + 1);
            v218 = v176;
            if ( !v216 )
              goto LABEL_285;
          }
          else if ( !v216 )
          {
            goto LABEL_285;
          }
          v237 = (__int64 *)(v216 + 80LL * v217 + 640);
          if ( v216 + 80LL * v217 == -640 || (v238 = (_DWORD *)(v344 + 20LL * v218)) == nullptr || (v239 = *v237) == 0 )
          {
LABEL_285:
            if ( !v216 )
              goto LABEL_255;
LABEL_286:
            v246 = (__int64 *)(v216 + 80LL * v217 + 160);
            if ( v216 + 80LL * v217 == -160 )
              goto LABEL_255;
            v247 = (_DWORD *)(v344 + 20LL * v218);
            if ( !v247 )
              goto LABEL_255;
            v248 = *v246;
            if ( !*v246 )
              goto LABEL_255;
            v249 = *(_DWORD *)(v248 + 116);
            v250 = v249 == 0;
            if ( v249 )
              v251 = 2;
            else
              v251 = 1;
            v247[v251] = *(_DWORD *)(v248 + 120);
            if ( v250 )
              v252 = 2;
            else
              v252 = 1;
            v247[v252] = **(_DWORD **)(v248 + 128);
            v253 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v216 + 1128) + 74392LL) + 24LL);
            if ( *((_DWORD *)v253 - 1) != 1884881292 )
              __break(0x8228u);
            v253();
            v155 = v176++ >= 0x3F;
            *v247 = 19;
            if ( !v155 )
              goto LABEL_255;
            v254 = printk(
                     &unk_9BB309,
                     "*num_srng < 64",
                     "dp_queue_mon_ring_stats",
                     "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c");
            dump_stack(v254);
            goto LABEL_301;
          }
          v240 = *(_DWORD *)(v239 + 116);
          v241 = v240 == 0;
          if ( v240 )
            v242 = 2;
          else
            v242 = 1;
          v238[v242] = *(_DWORD *)(v239 + 120);
          v243 = *(_DWORD **)(v239 + 128);
          if ( v241 )
            v244 = 2;
          else
            v244 = 1;
          v238[v244] = *v243;
          v245 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v216 + 1128) + 74392LL) + 24LL);
          if ( *((_DWORD *)v245 - 1) != 1884881292 )
            __break(0x8228u);
          v245();
          v189 = v176++ > 0x3E;
          *v238 = 18;
          if ( !v189 )
          {
            v216 = *((_QWORD *)v30 + 1);
            v218 = v176;
            if ( !v216 )
              goto LABEL_255;
            goto LABEL_286;
          }
LABEL_301:
          v255 = printk(
                   &unk_9BB309,
                   "expr",
                   "__dp_assert_always_internal",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
          dump_stack(v255);
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Ring number %d crossed max rings %d",
            v256,
            v257,
            v258,
            v259,
            v260,
            v261,
            v262,
            v263,
            "dp_validate_ring_num",
            v176,
            64);
          if ( v176 > 0x40 )
            goto LABEL_348;
LABEL_255:
          v228 = *((_QWORD *)v30 + 1);
          if ( v228 )
          {
            v229 = (__int64 *)(v228 + 80LL * v215 + 800);
            if ( v228 + 80LL * v215 != -800 )
            {
              v230 = (_DWORD *)(v344 + 20LL * v176);
              if ( v230 )
              {
                v231 = *v229;
                if ( *v229 )
                {
                  v232 = *(_DWORD *)(v231 + 116);
                  v233 = v232 == 0;
                  if ( v232 )
                    v234 = 2;
                  else
                    v234 = 1;
                  v230[v234] = *(_DWORD *)(v231 + 120);
                  if ( v233 )
                    v235 = 2;
                  else
                    v235 = 1;
                  v230[v235] = **(_DWORD **)(v231 + 128);
                  v236 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v228 + 1128) + 74392LL) + 24LL);
                  if ( *((_DWORD *)v236 - 1) != 1884881292 )
                    __break(0x8228u);
                  v236();
                  v155 = v176++ >= 0x3F;
                  *v230 = 17;
                  if ( v155 )
                  {
                    v273 = printk(
                             &unk_9BB309,
                             "expr",
                             "__dp_assert_always_internal",
                             "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
                    dump_stack(v273);
                    qdf_trace_msg(
                      0x45u,
                      2u,
                      "%s: Ring number %d crossed max rings %d",
                      v274,
                      v275,
                      v276,
                      v277,
                      v278,
                      v279,
                      v280,
                      v281,
                      "dp_validate_ring_num",
                      v176,
                      64);
                    break;
                  }
                }
              }
            }
          }
          LODWORD(v134) = v134 + 1;
        }
        while ( (unsigned int)v134 < *(unsigned __int8 *)(*(_QWORD *)(v70 + 40) + 808LL) );
      }
      if ( (*(_BYTE *)(v70 + 20064) & 1) != 0 || !*(_BYTE *)(*(_QWORD *)(v70 + 40) + 804LL) )
        goto LABEL_350;
      v282 = *((_QWORD *)v30 + 1);
      v283 = *v30;
      if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v282 + 40)) )
      {
        if ( v283 )
          goto LABEL_348;
        v283 = *(unsigned __int8 *)(*(_QWORD *)(v282 + 72) + 1LL);
      }
      if ( v283 > 2 || v176 > 0x40 )
      {
LABEL_348:
        __break(0x5512u);
      }
      else
      {
        v284 = *((_QWORD *)v30 + 1);
        if ( !v284 )
          goto LABEL_323;
        v285 = (__int64 *)(v284 + 80LL * v283 + 320);
        if ( v284 + 80LL * v283 == -320 )
          goto LABEL_323;
        v286 = (_DWORD *)(v344 + 20LL * v176);
        if ( !v286 )
          goto LABEL_323;
        v287 = *v285;
        if ( !*v285 )
          goto LABEL_323;
        v288 = 2;
        if ( *(_DWORD *)(v287 + 116) )
          v289 = 2;
        else
          v289 = 1;
        if ( *(_DWORD *)(v287 + 116) )
          v288 = 1;
        v286[v289] = *(_DWORD *)(v287 + 120);
        v286[v288] = **(_DWORD **)(v287 + 128);
        v290 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v284 + 1128) + 74392LL) + 24LL);
        if ( *((_DWORD *)v290 - 1) != 1884881292 )
          __break(0x8228u);
        v290();
        LODWORD(v134) = v176 + 1;
        v189 = v176 > 0x3E;
        *v286 = 15;
        ++v176;
        if ( !v189 )
        {
LABEL_323:
          if ( *(unsigned __int8 *)(*(_QWORD *)(v70 + 40) + 804LL) >= 2u )
          {
            v291 = 1;
            while ( 1 )
            {
              v292 = *((_QWORD *)v30 + 1);
              LODWORD(v134) = *v30;
              if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v292 + 40)) )
                break;
              if ( !(_DWORD)v134 )
              {
                v301 = v291;
                if ( v291 > 2 )
                  goto LABEL_348;
                goto LABEL_329;
              }
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: Both mac_id and pdev_id cannot be non zero",
                v293,
                v294,
                v295,
                v296,
                v297,
                v298,
                v299,
                v300,
                "dp_get_lmac_id_for_pdev_id");
              v301 = 0;
              v302 = *((_QWORD *)v30 + 1);
              if ( !v302 )
                goto LABEL_325;
LABEL_330:
              v303 = (__int64 *)(v302 + 80LL * v301 + 320);
              if ( v303 )
              {
                v304 = (_DWORD *)(v344 + 20LL * v176);
                if ( v304 )
                {
                  v305 = *v303;
                  if ( *v303 )
                  {
                    v306 = *(_DWORD *)(v305 + 116);
                    v307 = v306 == 0;
                    if ( v306 )
                      v308 = 2;
                    else
                      v308 = 1;
                    v304[v308] = *(_DWORD *)(v305 + 120);
                    if ( v307 )
                      v309 = 2;
                    else
                      v309 = 1;
                    v304[v309] = **(_DWORD **)(v305 + 128);
                    v310 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v302 + 1128) + 74392LL) + 24LL);
                    if ( *((_DWORD *)v310 - 1) != 1884881292 )
                      __break(0x8228u);
                    v310();
                    LODWORD(v134) = v176 + 1;
                    v155 = v176++ >= 0x3F;
                    *v304 = 15;
                    if ( v155 )
                      goto LABEL_349;
                  }
                }
              }
LABEL_325:
              if ( ++v291 >= *(unsigned __int8 *)(*(_QWORD *)(v70 + 40) + 804LL) )
                goto LABEL_350;
            }
            if ( (_DWORD)v134 )
              goto LABEL_348;
            v301 = *(unsigned __int8 *)(*(_QWORD *)(v292 + 72) + 1LL);
            if ( v301 > 2 )
              goto LABEL_348;
LABEL_329:
            v302 = *((_QWORD *)v30 + 1);
            if ( !v302 )
              goto LABEL_325;
            goto LABEL_330;
          }
LABEL_350:
          *(_DWORD *)(v342 + 4) = v176;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v30 + 95528);
            v321 = v343;
          }
          else
          {
            raw_spin_lock_bh(v30 + 95528);
            v321 = v343;
            *((_QWORD *)v343 + 166) |= 1uLL;
          }
          *(_DWORD *)v342 = *((_DWORD *)v321 + 328);
          v322 = v321[1316];
          if ( v322 >= 0x10 )
          {
            v323 = *((_QWORD *)v321 + 167);
            if ( v323 )
            {
              v324 = *(_QWORD *)(v323 + 1288);
              v325 = *(_QWORD **)(v323 + 1296);
              if ( v324 )
                v326 = (_QWORD *)(v324 + 1296);
              else
                v326 = v321 + 1344;
              *v326 = v325;
              *v325 = *(_QWORD *)(v323 + 1288);
              *(_QWORD *)(v323 + 1296) = 0;
              *(_QWORD *)(v323 + 1288) = 0;
              _qdf_mem_free(v323);
              LOBYTE(v322) = v321[1316] - 1;
            }
            else
            {
              v330 = printk(
                       &unk_9BB309,
                       "expr",
                       "__dp_assert_always_internal",
                       "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
              dump_stack(v330);
              LOBYTE(v322) = v321[1316];
            }
          }
          v321[1316] = v322 + 1;
          *(_QWORD *)(v342 + 1288) = 0;
          v327 = *((__int64 **)v321 + 168);
          *(_QWORD *)(v342 + 1296) = v327;
          *v327 = v342;
          v328 = *((_DWORD *)v321 + 328);
          v329 = *((_QWORD *)v321 + 166);
          *((_QWORD *)v321 + 168) = v342 + 1288;
          *((_DWORD *)v321 + 328) = v328 + 1;
          if ( (v329 & 1) != 0 )
          {
            *((_QWORD *)v321 + 166) = v329 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v30 + 95528);
          }
          else
          {
            raw_spin_unlock(v30 + 95528);
          }
          return (unsigned int *)queue_work_on(32, *((_QWORD *)v321 + 163), v30 + 95464);
        }
      }
LABEL_349:
      v311 = printk(
               &unk_9BB309,
               "expr",
               "__dp_assert_always_internal",
               "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
      dump_stack(v311);
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Ring number %d crossed max rings %d",
        v312,
        v313,
        v314,
        v315,
        v316,
        v317,
        v318,
        v319,
        "dp_validate_ring_num",
        (unsigned int)v134,
        64);
      v176 = v134;
      goto LABEL_350;
    }
LABEL_184:
    v177 = (_DWORD *)(v344 + 20LL * v168);
    if ( v177 )
    {
      v178 = *(_QWORD *)(v167 + 18488);
      if ( v178 )
      {
        LODWORD(v134) = 14;
        v179 = 2;
        if ( *(_DWORD *)(v178 + 116) )
          v180 = 2;
        else
          v180 = 1;
        if ( *(_DWORD *)(v178 + 116) )
          v179 = 1;
        v177[v180] = *(_DWORD *)(v178 + 120);
        v177[v179] = **(_DWORD **)(v178 + 128);
        v181 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v167 + 1128) + 74392LL) + 24LL);
        if ( *((_DWORD *)v181 - 1) != 1884881292 )
          __break(0x8228u);
        v181();
        v155 = v135++ >= 0x3F;
        *v177 = 14;
        if ( v155 )
        {
          v331 = printk(
                   &unk_9BB309,
                   "expr",
                   "__dp_assert_always_internal",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
          dump_stack(v331);
          v340 = v135;
          return (unsigned int *)qdf_trace_msg(
                                   0x45u,
                                   2u,
                                   "%s: Ring number %d crossed max rings %d",
                                   v332,
                                   v333,
                                   v334,
                                   v335,
                                   v336,
                                   v337,
                                   v338,
                                   v339,
                                   "dp_validate_ring_num",
                                   v340,
                                   64);
        }
        v167 = *((_QWORD *)v30 + 1);
      }
    }
    v182 = (__int64 *)(v30 + 112);
    v183 = v135;
    if ( v30 != (unsigned __int8 *)-112LL )
    {
      if ( v167 )
      {
        v184 = (_DWORD *)(v344 + 20LL * v135);
        if ( v184 )
        {
          v185 = *v182;
          if ( *v182 )
          {
            v186 = 2;
            if ( *(_DWORD *)(v185 + 116) )
              v187 = 2;
            else
              v187 = 1;
            if ( *(_DWORD *)(v185 + 116) )
              v186 = 1;
            v184[v187] = *(_DWORD *)(v185 + 120);
            v184[v186] = **(_DWORD **)(v185 + 128);
            v188 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v167 + 1128) + 74392LL) + 24LL);
            if ( *((_DWORD *)v188 - 1) != 1884881292 )
              __break(0x8228u);
            v188();
            v189 = v135++ > 0x3E;
            *v184 = 14;
            if ( v189 )
              goto LABEL_221;
            v167 = *((_QWORD *)v30 + 1);
            v183 = v135;
          }
        }
      }
    }
    v190 = (__int64 *)(v30 + 192);
    if ( v30 == (unsigned __int8 *)-192LL )
      goto LABEL_222;
    if ( !v167 )
      goto LABEL_222;
    v191 = (_DWORD *)(v344 + 20LL * v183);
    if ( !v191 )
      goto LABEL_222;
    v192 = *v190;
    if ( !*v190 )
      goto LABEL_222;
    v193 = 2;
    if ( *(_DWORD *)(v192 + 116) )
      v194 = 2;
    else
      v194 = 1;
    if ( *(_DWORD *)(v192 + 116) )
      v193 = 1;
    v191[v194] = *(_DWORD *)(v192 + 120);
    v191[v193] = **(_DWORD **)(v192 + 128);
    v195 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v167 + 1128) + 74392LL) + 24LL);
    if ( *((_DWORD *)v195 - 1) != 1884881292 )
      __break(0x8228u);
    v195();
    v176 = v135 + 1;
    v189 = v135 > 0x3E;
    *v191 = 14;
    ++v135;
    if ( !v189 )
      goto LABEL_223;
LABEL_221:
    v196 = printk(
             &unk_9BB309,
             "expr",
             "__dp_assert_always_internal",
             "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
    dump_stack(v196);
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Ring number %d crossed max rings %d",
      v197,
      v198,
      v199,
      v200,
      v201,
      v202,
      v203,
      v204,
      "dp_validate_ring_num",
      v135,
      64);
LABEL_222:
    v176 = v135;
    goto LABEL_223;
  }
  v170 = (_DWORD *)(v344 + 20LL * v135);
  if ( !v170 )
    goto LABEL_184;
  v171 = *v169;
  if ( !*v169 )
    goto LABEL_184;
  v172 = 2;
  if ( *(_DWORD *)(v171 + 116) )
    v173 = 2;
  else
    v173 = 1;
  if ( *(_DWORD *)(v171 + 116) )
    v172 = 1;
  v170[v173] = *(_DWORD *)(v171 + 120);
  v170[v172] = **(_DWORD **)(v171 + 128);
  v174 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v167 + 1128) + 74392LL) + 24LL);
  if ( *((_DWORD *)v174 - 1) != 1884881292 )
    __break(0x8228u);
  v174();
  *v170 = 14;
  v175 = v135 + 1;
  if ( v135 < 0x3F )
  {
    v167 = *((_QWORD *)v30 + 1);
    v168 = v135 + 1;
    goto LABEL_183;
  }
  v341 = printk(
           &unk_9BB309,
           "expr",
           "__dp_assert_always_internal",
           "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
  dump_stack(v341);
  v340 = v175;
  return (unsigned int *)qdf_trace_msg(
                           0x45u,
                           2u,
                           "%s: Ring number %d crossed max rings %d",
                           v332,
                           v333,
                           v334,
                           v335,
                           v336,
                           v337,
                           v338,
                           v339,
                           "dp_validate_ring_num",
                           v340,
                           64);
}
