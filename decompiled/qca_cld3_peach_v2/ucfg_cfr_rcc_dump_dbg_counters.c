__int64 __fastcall ucfg_cfr_rcc_dump_dbg_counters(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  __int64 v19; // x21
  _QWORD *v20; // x23
  unsigned int v21; // w22
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
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
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  __int64 v126; // x0
  unsigned int *v127; // x8
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  _QWORD *v136; // x20
  __int64 v137; // x0
  __int64 v138; // x8
  void (*v139)(void); // x8
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  double v228; // d0
  double v229; // d1
  double v230; // d2
  double v231; // d3
  double v232; // d4
  double v233; // d5
  double v234; // d6
  double v235; // d7
  double v236; // d0
  double v237; // d1
  double v238; // d2
  double v239; // d3
  double v240; // d4
  double v241; // d5
  double v242; // d6
  double v243; // d7
  double v244; // d0
  double v245; // d1
  double v246; // d2
  double v247; // d3
  double v248; // d4
  double v249; // d5
  double v250; // d6
  double v251; // d7
  __int64 v252; // [xsp+8h] [xbp-18h] BYREF
  __int64 v253[2]; // [xsp+10h] [xbp-10h] BYREF

  v253[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v252 = 0;
  v253[0] = 0;
  result = dev_sanity_check(a1, &v252, v253, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
  {
    v18 = v252;
    v19 = *(_QWORD *)(v252 + 80);
    if ( v19 )
    {
      v20 = (_QWORD *)v253[0];
      v21 = 2;
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: total_tx_evt_cnt = %llu\n",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "ucfg_cfr_rcc_dump_dbg_counters",
        *(_QWORD *)(v253[0] + 104));
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: dbr_evt_cnt = %llu\n",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[14]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: rx_tlv_evt_cnt = %llu\n",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[165]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: release_cnt = %llu\n",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[15]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: Error cnt:\n",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "ucfg_cfr_rcc_dump_dbg_counters");
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: flush_dbr_cnt = %llu\n",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[174]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: invalid_dma_length_cnt = %llu\n",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[175]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: flush_timeout_dbr_cnt = %llu\n",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[176]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: tx_peer_status_cfr_fail = %llu\n",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[16]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: tx_evt_status_cfr_fail = %llu\n",
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[17]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: tx_dbr_cookie_lookup_fail = %llu\n",
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[18]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: PPDU id mismatch for same cookie:\n",
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        "ucfg_cfr_rcc_dump_dbg_counters");
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: clear_txrx_event = %llu\n",
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[177]);
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: cfr_dma_aborts = %llu\n",
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        "ucfg_cfr_rcc_dump_dbg_counters",
        v20[179]);
      v126 = _qdf_mem_malloc(0x68u, "ucfg_cfr_rcc_dump_dbg_counters", 1100);
      if ( v126 )
      {
        v136 = (_QWORD *)v126;
        v137 = *(_QWORD *)(v19 + 2808);
        if ( v137 && *(_QWORD *)v137 )
        {
          v138 = *(_QWORD *)(*(_QWORD *)v137 + 168LL);
          if ( v138 )
          {
            v139 = *(void (**)(void))(v138 + 16);
            if ( v139 )
            {
              if ( *((_DWORD *)v139 - 1) != 931412108 )
                __break(0x8228u);
              v139();
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            1u,
            "%s invalid instance",
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            "cdp_get_cfr_dbg_stats");
        }
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: bb_captured_channel_cnt: %llu\n",
          v128,
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          "ucfg_cfr_rcc_dump_dbg_counters",
          *v136);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: bb_captured_timeout_cnt: %llu\n",
          v140,
          v141,
          v142,
          v143,
          v144,
          v145,
          v146,
          v147,
          "ucfg_cfr_rcc_dump_dbg_counters",
          v136[1]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: rx_loc_info_valid_cnt: %llu\n",
          v148,
          v149,
          v150,
          v151,
          v152,
          v153,
          v154,
          v155,
          "ucfg_cfr_rcc_dump_dbg_counters",
          v136[2]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: Channel capture status:\n",
          v156,
          v157,
          v158,
          v159,
          v160,
          v161,
          v162,
          v163,
          "ucfg_cfr_rcc_dump_dbg_counters");
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v164,
          v165,
          v166,
          v167,
          v168,
          v169,
          v170,
          v171,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "CAPTURE_IDLE",
          v136[3]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          v178,
          v179,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "CAPTURE_BUSY",
          v136[4]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v180,
          v181,
          v182,
          v183,
          v184,
          v185,
          v186,
          v187,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "CAPTURE_ACTIVE",
          v136[5]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v188,
          v189,
          v190,
          v191,
          v192,
          v193,
          v194,
          v195,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "CAPTURE_NO_BUFFER",
          v136[6]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: Freeze reason:\n",
          v196,
          v197,
          v198,
          v199,
          v200,
          v201,
          v202,
          v203,
          "ucfg_cfr_rcc_dump_dbg_counters");
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v204,
          v205,
          v206,
          v207,
          v208,
          v209,
          v210,
          v211,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "FREEZE_REASON_TM",
          v136[7]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v212,
          v213,
          v214,
          v215,
          v216,
          v217,
          v218,
          v219,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "FREEZE_REASON_FTM",
          v136[8]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v220,
          v221,
          v222,
          v223,
          v224,
          v225,
          v226,
          v227,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "FREEZE_REASON_ACK_RESP_TO_TM_FTM",
          v136[9]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v228,
          v229,
          v230,
          v231,
          v232,
          v233,
          v234,
          v235,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "FREEZE_REASON_TA_RA_TYPE_FILTER",
          v136[10]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v236,
          v237,
          v238,
          v239,
          v240,
          v241,
          v242,
          v243,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "FREEZE_REASON_NDPA_NDP",
          v136[11]);
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: %s = %llu\n",
          v244,
          v245,
          v246,
          v247,
          v248,
          v249,
          v250,
          v251,
          "ucfg_cfr_rcc_dump_dbg_counters",
          "FREEZE_REASON_ALL_PACKET",
          v136[12]);
        _qdf_mem_free((__int64)v136);
        v21 = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: psoc is null!",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "ucfg_cfr_rcc_dump_dbg_counters");
      v21 = 29;
    }
    wlan_objmgr_pdev_release_ref(v18, 0x30u, v127, v128, v129, v130, v131, v132, v133, v134, v135);
    result = v21;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
