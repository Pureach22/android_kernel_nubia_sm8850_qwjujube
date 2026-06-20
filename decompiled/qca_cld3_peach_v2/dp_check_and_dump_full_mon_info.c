__int64 __fastcall dp_check_and_dump_full_mon_info(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x21
  __int64 *v14; // x25
  __int64 v16; // x19
  __int64 v17; // x20
  __int64 v18; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x8
  __int64 v21; // x23
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w8
  unsigned int *v32; // x23
  const char *v33; // x2
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int target_type; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
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
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
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
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  double v203; // d0
  double v204; // d1
  double v205; // d2
  double v206; // d3
  double v207; // d4
  double v208; // d5
  double v209; // d6
  double v210; // d7
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  double v219; // d0
  double v220; // d1
  double v221; // d2
  double v222; // d3
  double v223; // d4
  double v224; // d5
  double v225; // d6
  double v226; // d7
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  unsigned __int64 v251; // x22
  double v252; // d0
  double v253; // d1
  double v254; // d2
  double v255; // d3
  double v256; // d4
  double v257; // d5
  double v258; // d6
  double v259; // d7
  __int64 *v260; // x24
  void (__fastcall *v261)(unsigned int *, __int64 *); // x8
  double v262; // d0
  double v263; // d1
  double v264; // d2
  double v265; // d3
  double v266; // d4
  double v267; // d5
  double v268; // d6
  double v269; // d7
  __int64 v270; // x5
  double v271; // d0
  double v272; // d1
  double v273; // d2
  double v274; // d3
  double v275; // d4
  double v276; // d5
  double v277; // d6
  double v278; // d7
  __int64 v279; // x21
  __int64 v280; // x8
  __int64 v281; // x9
  __int64 v282; // x21
  __int64 v283; // x1
  _DWORD *v284; // x8
  unsigned int v285; // w0
  double v286; // d0
  double v287; // d1
  double v288; // d2
  double v289; // d3
  double v290; // d4
  double v291; // d5
  double v292; // d6
  double v293; // d7
  _DWORD *v294; // x8
  double v295; // d0
  double v296; // d1
  double v297; // d2
  double v298; // d3
  double v299; // d4
  double v300; // d5
  double v301; // d6
  double v302; // d7
  __int64 v303; // x8
  int v304; // [xsp+0h] [xbp-70h]
  int v305; // [xsp+14h] [xbp-5Ch]
  __int64 v306; // [xsp+18h] [xbp-58h]
  _QWORD v307[7]; // [xsp+20h] [xbp-50h] BYREF
  __int64 v308; // [xsp+58h] [xbp-18h] BYREF
  __int64 v309; // [xsp+60h] [xbp-10h]
  __int64 v310; // [xsp+68h] [xbp-8h]

  v310 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(result + 20112);
  v308 = 0;
  v309 = 0;
  memset(v307, 0, sizeof(v307));
  if ( (unsigned __int8)a3 >= 3u )
    goto LABEL_45;
  if ( !v12 )
  {
    v33 = "%s: Monitor soc is NULL\n";
LABEL_18:
    result = qdf_trace_msg(0x45u, 2u, v33, a5, a6, a7, a8, a9, a10, a11, a12, "dp_check_and_dump_full_mon_info");
    goto LABEL_19;
  }
  if ( (*(_BYTE *)(v12 + 257) & 1) == 0 )
  {
    v33 = "%s: Full monitor mode is disable\n";
    goto LABEL_18;
  }
  v13 = *(_QWORD *)(a2 + 96456);
  if ( !v13 )
  {
    v33 = "%s: mon_pdev is NULL\n";
    goto LABEL_18;
  }
  v14 = *(__int64 **)(result + 1128);
  v16 = result;
  v17 = v13 + 18528LL * (a3 & 3) + 8;
  if ( !a4 )
  {
    v18 = a2;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      result = raw_spin_lock(v13 + 18528LL * (a3 & 3) + 40);
    }
    else
    {
      result = raw_spin_lock_bh(v13 + 18528LL * (a3 & 3) + 40);
      *(_QWORD *)(v17 + 40) |= 1uLL;
    }
    a4 = 0;
    a2 = v18;
  }
  if ( a3 >= 2 )
LABEL_45:
    __break(0x5512u);
  v20 = v16 + 80LL * (int)a3;
  v21 = *(_QWORD *)(v20 + 800);
  if ( !v21 )
    goto LABEL_40;
  v306 = a2;
  v22 = v13 + 36864;
  v305 = a4;
  dp_print_ring_stat_from_hal(v16, v20 + 800, 0x11u, a5, a6, a7, a8, a9, a10, a11, a12);
  v31 = (unsigned int)(*(_DWORD *)(v21 + 44) + *(_DWORD *)(v21 + 120)) % *(_DWORD *)(v21 + 36);
  if ( v31 == *(_DWORD *)(v21 + 136) )
    v32 = nullptr;
  else
    v32 = (unsigned int *)(*(_QWORD *)(v21 + 16) + 4LL * v31);
  qdf_trace_msg(
    0x3Fu,
    8u,
    "hold_mon_dest_ring: %d\n",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    *(unsigned __int8 *)(v22 + 230),
    (int)a3);
  qdf_trace_msg(
    0x3Fu,
    8u,
    "mon_pdev last_ppdu_id: %d\n",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    *(unsigned int *)(v22 + 2256));
  target_type = hal_get_target_type(v14);
  qdf_trace_msg(0x3Fu, 8u, "soc: %d\n", v43, v44, v45, v46, v47, v48, v49, v50, target_type);
  qdf_trace_msg(0x3Fu, 8u, "reap_status:\n", v51, v52, v53, v54, v55, v56, v57, v58);
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_NO_DMA : %lld\n",
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    *(_QWORD *)(v22 + 232));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_MATCH : %lld\n",
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    *(_QWORD *)(v22 + 240));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_LAG : %lld\n",
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    *(_QWORD *)(v22 + 248));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_LEAD : %lld\n",
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    *(_QWORD *)(v22 + 256));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_REPLENISH : %lld\n",
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    *(_QWORD *)(v22 + 264));
  qdf_trace_msg(0x3Fu, 8u, "prev_status:\n", v99, v100, v101, v102, v103, v104, v105, v106);
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_NO_DMA : %lld\n",
    v107,
    v108,
    v109,
    v110,
    v111,
    v112,
    v113,
    v114,
    *(_QWORD *)(v22 + 272));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_MATCH : %lld\n",
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    *(_QWORD *)(v22 + 280));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_LAG : %lld\n",
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    *(_QWORD *)(v22 + 288));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_LEAD : %lld\n",
    v131,
    v132,
    v133,
    v134,
    v135,
    v136,
    v137,
    v138,
    *(_QWORD *)(v22 + 296));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_REPLENISH : %lld\n",
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    *(_QWORD *)(v22 + 304));
  qdf_trace_msg(0x3Fu, 8u, "match_stats:\n", v147, v148, v149, v150, v151, v152, v153, v154);
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_LAG : %lld\n",
    v155,
    v156,
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    *(_QWORD *)(v22 + 328));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "\t DP_MON_STATUS_LEAD : %lld\n",
    v163,
    v164,
    v165,
    v166,
    v167,
    v168,
    v169,
    v170,
    *(_QWORD *)(v22 + 336));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "mismatch: %d\n",
    v171,
    v172,
    v173,
    v174,
    v175,
    v176,
    v177,
    v178,
    *(unsigned int *)(v17 + 2976));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "status_ppdu_drop: %d\n",
    v179,
    v180,
    v181,
    v182,
    v183,
    v184,
    v185,
    v186,
    *(unsigned int *)(v17 + 2984));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "dest_ppdu_drop: %d\n",
    v187,
    v188,
    v189,
    v190,
    v191,
    v192,
    v193,
    v194,
    *(unsigned int *)(v17 + 2988));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "tlv_tag_status_err: %d\n",
    v195,
    v196,
    v197,
    v198,
    v199,
    v200,
    v201,
    v202,
    *(unsigned int *)(v17 + 2960));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "status_buf_done_war: %d\n",
    v203,
    v204,
    v205,
    v206,
    v207,
    v208,
    v209,
    v210,
    *(unsigned int *)(v17 + 2964));
  qdf_trace_msg(
    0x3Fu,
    8u,
    "soc[%pK] pdev[%pK] mac_id[%d]\n",
    v211,
    v212,
    v213,
    v214,
    v215,
    v216,
    v217,
    v218,
    v16,
    v306,
    a3);
  qdf_trace_msg(0x3Fu, 8u, "MON DEST TRACKER STATS:\n", v219, v220, v221, v222, v223, v224, v225, v226);
  qdf_trace_msg(0x3Fu, 8u, "MON STA TRACKER STATS:\n", v227, v228, v229, v230, v231, v232, v233, v234);
  qdf_trace_msg(0x3Fu, 8u, "rxdma_mon_status_ring:\n", v235, v236, v237, v238, v239, v240, v241, v242);
  if ( v32 )
  {
    v251 = *v32 | ((unsigned __int64)*((unsigned __int8 *)v32 + 4) << 32);
    qdf_trace_msg(0x3Fu, 8u, "Buffer address : %llx\n", v243, v244, v245, v246, v247, v248, v249, v250, v251);
    v260 = v14;
    if ( v251 )
    {
      v261 = *(void (__fastcall **)(unsigned int *, __int64 *))(*(_QWORD *)(*(_QWORD *)(v16 + 1128) + 74392LL) + 1456LL);
      if ( *((_DWORD *)v261 - 1) != -621572614 )
        __break(0x8228u);
      v261(v32, &v308);
      print_hex_dump(&unk_A05438, "\tHAL_BUF_INFO: ", 0, 32, 4, &v308, 16, 0);
      if ( (v309 & 0xE0000) != 0
        || (v270 = *(_QWORD *)(*(_QWORD *)(v16 + 120 * (((unsigned __int64)(unsigned int)v309 >> 16) & 1) + 11960)
                             + 8LL * BYTE1(v309))
                 + (unsigned __int8)v309
                 * (unsigned int)*(unsigned __int16 *)(v16
                                                     + 120 * (((unsigned __int64)(unsigned int)v309 >> 16) & 1)
                                                     + 11940)) == 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: rx_desc is NULL\n",
          v262,
          v263,
          v264,
          v265,
          v266,
          v267,
          v268,
          v269,
          "dp_check_and_dump_full_mon_info");
      }
      else
      {
        print_hex_dump(&unk_A05438, "\tRX_DESC: ", 0, 32, 4, v270, 32, 0);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: rxdma_mon_status_ring_entry NULL\n",
      v243,
      v244,
      v245,
      v246,
      v247,
      v248,
      v249,
      v250,
      "dp_check_and_dump_full_mon_info");
    v260 = v14;
  }
  qdf_trace_msg(0x3Fu, 8u, "rxdma_mon_destination_ring:\n", v252, v253, v254, v255, v256, v257, v258, v259);
  v279 = *(_QWORD *)(*(_QWORD *)(v306 + 8) + 80LL * v304 + 640);
  if ( !v279 )
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: rxdma_mon_dst_ring hal_srng is NULL\n",
               v271,
               v272,
               v273,
               v274,
               v275,
               v276,
               v277,
               v278,
               "dp_check_and_dump_full_mon_info");
LABEL_39:
    a4 = v305;
    goto LABEL_40;
  }
  result = dp_print_ring_stat_from_hal(
             v16,
             v16 + 80LL * v304 + 640,
             0x12u,
             v271,
             v272,
             v273,
             v274,
             v275,
             v276,
             v277,
             v278);
  v280 = *(unsigned int *)(v279 + 120);
  a4 = v305;
  if ( (_DWORD)v280 != *(_DWORD *)(v279 + 136) )
  {
    v281 = *(_QWORD *)(v279 + 16);
    v282 = v281 + 4 * v280;
    if ( v282 )
    {
      v283 = v281 + 4 * v280;
      v284 = *(_DWORD **)(v260[9299] + 688);
      if ( *(v284 - 1) != 1363182085 )
        __break(0x8228u);
      v285 = ((__int64 (__fastcall *)(_QWORD, __int64))v284)(0, v283);
      qdf_trace_msg(0x3Fu, 8u, "Next dest ring ppdu id: %lld\n", v286, v287, v288, v289, v290, v291, v292, v293, v285);
      v294 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(v16 + 1128) + 74392LL) + 944LL);
      if ( *(v294 - 1) != 940836275 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v294)(v282, v307);
      qdf_trace_msg(
        0x3Fu,
        8u,
        "Next desc_info ppdu_id: %d\n",
        v295,
        v296,
        v297,
        v298,
        v299,
        v300,
        v301,
        v302,
        LOWORD(v307[0]));
      result = print_hex_dump(&unk_A05438, "\tDESC_INFO: ", 0, 32, 4, v307, 56, 0);
      goto LABEL_39;
    }
  }
LABEL_40:
  if ( !a4 )
  {
    v303 = *(_QWORD *)(v17 + 40);
    if ( (v303 & 1) != 0 )
    {
      *(_QWORD *)(v17 + 40) = v303 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v17 + 32);
    }
    else
    {
      result = raw_spin_unlock(v17 + 32);
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
