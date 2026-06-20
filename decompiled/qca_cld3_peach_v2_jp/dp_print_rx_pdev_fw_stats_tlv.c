__int64 __fastcall dp_print_rx_pdev_fw_stats_tlv(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
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
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
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
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x20
  unsigned __int16 v91; // w24
  __int16 v92; // w0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x20
  unsigned __int16 v102; // w24
  __int16 v103; // w0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  double v200; // d0
  double v201; // d1
  double v202; // d2
  double v203; // d3
  double v204; // d4
  double v205; // d5
  double v206; // d6
  double v207; // d7
  double v208; // d0
  double v209; // d1
  double v210; // d2
  double v211; // d3
  double v212; // d4
  double v213; // d5
  double v214; // d6
  double v215; // d7
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
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
  double v248; // d0
  double v249; // d1
  double v250; // d2
  double v251; // d3
  double v252; // d4
  double v253; // d5
  double v254; // d6
  double v255; // d7
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  double v264; // d0
  double v265; // d1
  double v266; // d2
  double v267; // d3
  double v268; // d4
  double v269; // d5
  double v270; // d6
  double v271; // d7
  double v272; // d0
  double v273; // d1
  double v274; // d2
  double v275; // d3
  double v276; // d4
  double v277; // d5
  double v278; // d6
  double v279; // d7
  double v280; // d0
  double v281; // d1
  double v282; // d2
  double v283; // d3
  double v284; // d4
  double v285; // d5
  double v286; // d6
  double v287; // d7
  double v288; // d0
  double v289; // d1
  double v290; // d2
  double v291; // d3
  double v292; // d4
  double v293; // d5
  double v294; // d6
  double v295; // d7
  double v296; // d0
  double v297; // d1
  double v298; // d2
  double v299; // d3
  double v300; // d4
  double v301; // d5
  double v302; // d6
  double v303; // d7
  double v304; // d0
  double v305; // d1
  double v306; // d2
  double v307; // d3
  double v308; // d4
  double v309; // d5
  double v310; // d6
  double v311; // d7
  double v312; // d0
  double v313; // d1
  double v314; // d2
  double v315; // d3
  double v316; // d4
  double v317; // d5
  double v318; // d6
  double v319; // d7
  double v320; // d0
  double v321; // d1
  double v322; // d2
  double v323; // d3
  double v324; // d4
  double v325; // d5
  double v326; // d6
  double v327; // d7
  double v328; // d0
  double v329; // d1
  double v330; // d2
  double v331; // d3
  double v332; // d4
  double v333; // d5
  double v334; // d6
  double v335; // d7
  double v336; // d0
  double v337; // d1
  double v338; // d2
  double v339; // d3
  double v340; // d4
  double v341; // d5
  double v342; // d6
  double v343; // d7
  double v344; // d0
  double v345; // d1
  double v346; // d2
  double v347; // d3
  double v348; // d4
  double v349; // d5
  double v350; // d6
  double v351; // d7
  double v352; // d0
  double v353; // d1
  double v354; // d2
  double v355; // d3
  double v356; // d4
  double v357; // d5
  double v358; // d6
  double v359; // d7
  double v360; // d0
  double v361; // d1
  double v362; // d2
  double v363; // d3
  double v364; // d4
  double v365; // d5
  double v366; // d6
  double v367; // d7
  double v368; // d0
  double v369; // d1
  double v370; // d2
  double v371; // d3
  double v372; // d4
  double v373; // d5
  double v374; // d6
  double v375; // d7
  double v376; // d0
  double v377; // d1
  double v378; // d2
  double v379; // d3
  double v380; // d4
  double v381; // d5
  double v382; // d6
  double v383; // d7
  double v384; // d0
  double v385; // d1
  double v386; // d2
  double v387; // d3
  double v388; // d4
  double v389; // d5
  double v390; // d6
  double v391; // d7
  __int64 result; // x0
  _BYTE v393[1000]; // [xsp+0h] [xbp-3F0h] BYREF
  __int64 v394; // [xsp+3E8h] [xbp-8h]

  v394 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v393, 0, sizeof(v393));
  DP_PRINT_STATS("HTT_RX_PDEV_FW_STATS_TLV:", v2, v3, v4, v5, v6, v7, v8, v9);
  DP_PRINT_STATS("mac_id__word = %u", v10, v11, v12, v13, v14, v15, v16, v17, *(unsigned int *)(a1 + 4));
  DP_PRINT_STATS("ppdu_recvd = %u", v18, v19, v20, v21, v22, v23, v24, v25, *(unsigned int *)(a1 + 8));
  DP_PRINT_STATS("mpdu_cnt_fcs_ok = %u", v26, v27, v28, v29, v30, v31, v32, v33, *(unsigned int *)(a1 + 12));
  DP_PRINT_STATS("mpdu_cnt_fcs_err = %u", v34, v35, v36, v37, v38, v39, v40, v41, *(unsigned int *)(a1 + 16));
  DP_PRINT_STATS("bytes_received = %llu", v42, v43, v44, v45, v46, v47, v48, v49, *(_QWORD *)(a1 + 316));
  DP_PRINT_STATS("tcp_msdu_cnt = %u", v50, v51, v52, v53, v54, v55, v56, v57, *(unsigned int *)(a1 + 20));
  DP_PRINT_STATS("tcp_ack_msdu_cnt = %u", v58, v59, v60, v61, v62, v63, v64, v65, *(unsigned int *)(a1 + 24));
  DP_PRINT_STATS("udp_msdu_cnt = %u", v66, v67, v68, v69, v70, v71, v72, v73, *(unsigned int *)(a1 + 28));
  DP_PRINT_STATS("other_msdu_cnt = %u", v74, v75, v76, v77, v78, v79, v80, v81, *(unsigned int *)(a1 + 32));
  DP_PRINT_STATS("fw_ring_mpdu_ind = %u", v82, v83, v84, v85, v86, v87, v88, v89, *(unsigned int *)(a1 + 36));
  qdf_mem_set(v393, 0x3E8u, 0);
  v90 = 0;
  v91 = 0;
  do
  {
    if ( v91 >= 0x3E9u )
LABEL_8:
      __break(0x5512u);
    v92 = snprintf(&v393[v91], 1000LL - v91, " %u:%u,", v90, *(_DWORD *)(a1 + 40 + 4 * v90));
    ++v90;
    v91 += v92;
  }
  while ( v90 != 16 );
  DP_PRINT_STATS("fw_ring_mgmt_subtype = %s ", v93, v94, v95, v96, v97, v98, v99, v100, v393);
  qdf_mem_set(v393, 0x3E8u, 0);
  v101 = 0;
  v102 = 0;
  do
  {
    if ( v102 > 0x3E8u )
      goto LABEL_8;
    v103 = snprintf(&v393[v102], 1000LL - v102, " %u:%u,", v101, *(_DWORD *)(a1 + 104 + 4 * v101));
    ++v101;
    v102 += v103;
  }
  while ( v101 != 16 );
  DP_PRINT_STATS("fw_ring_ctrl_subtype = %s ", v104, v105, v106, v107, v108, v109, v110, v111, v393);
  DP_PRINT_STATS(
    "fw_ring_mcast_data_msdu = %u",
    v112,
    v113,
    v114,
    v115,
    v116,
    v117,
    v118,
    v119,
    *(unsigned int *)(a1 + 168));
  DP_PRINT_STATS(
    "fw_ring_bcast_data_msdu = %u",
    v120,
    v121,
    v122,
    v123,
    v124,
    v125,
    v126,
    v127,
    *(unsigned int *)(a1 + 172));
  DP_PRINT_STATS(
    "fw_ring_ucast_data_msdu = %u",
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    v134,
    v135,
    *(unsigned int *)(a1 + 176));
  DP_PRINT_STATS(
    "fw_ring_null_data_msdu = %u",
    v136,
    v137,
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    *(unsigned int *)(a1 + 180));
  DP_PRINT_STATS("fw_ring_mpdu_drop = %u", v144, v145, v146, v147, v148, v149, v150, v151, *(unsigned int *)(a1 + 184));
  DP_PRINT_STATS(
    "ofld_local_data_ind_cnt = %u",
    v152,
    v153,
    v154,
    v155,
    v156,
    v157,
    v158,
    v159,
    *(unsigned int *)(a1 + 188));
  DP_PRINT_STATS(
    "ofld_local_data_buf_recycle_cnt = %u",
    v160,
    v161,
    v162,
    v163,
    v164,
    v165,
    v166,
    v167,
    *(unsigned int *)(a1 + 192));
  DP_PRINT_STATS(
    "drx_local_data_ind_cnt = %u",
    v168,
    v169,
    v170,
    v171,
    v172,
    v173,
    v174,
    v175,
    *(unsigned int *)(a1 + 196));
  DP_PRINT_STATS(
    "drx_local_data_buf_recycle_cnt = %u",
    v176,
    v177,
    v178,
    v179,
    v180,
    v181,
    v182,
    v183,
    *(unsigned int *)(a1 + 200));
  DP_PRINT_STATS(
    "local_nondata_ind_cnt = %u",
    v184,
    v185,
    v186,
    v187,
    v188,
    v189,
    v190,
    v191,
    *(unsigned int *)(a1 + 204));
  DP_PRINT_STATS(
    "local_nondata_buf_recycle_cnt = %u",
    v192,
    v193,
    v194,
    v195,
    v196,
    v197,
    v198,
    v199,
    *(unsigned int *)(a1 + 208));
  DP_PRINT_STATS(
    "fw_status_buf_ring_refill_cnt = %u",
    v200,
    v201,
    v202,
    v203,
    v204,
    v205,
    v206,
    v207,
    *(unsigned int *)(a1 + 212));
  DP_PRINT_STATS(
    "fw_status_buf_ring_empty_cnt = %u",
    v208,
    v209,
    v210,
    v211,
    v212,
    v213,
    v214,
    v215,
    *(unsigned int *)(a1 + 216));
  DP_PRINT_STATS(
    "fw_pkt_buf_ring_refill_cnt = %u",
    v216,
    v217,
    v218,
    v219,
    v220,
    v221,
    v222,
    v223,
    *(unsigned int *)(a1 + 220));
  DP_PRINT_STATS(
    "fw_pkt_buf_ring_empty_cnt = %u",
    v224,
    v225,
    v226,
    v227,
    v228,
    v229,
    v230,
    v231,
    *(unsigned int *)(a1 + 224));
  DP_PRINT_STATS(
    "fw_link_buf_ring_refill_cnt = %u",
    v232,
    v233,
    v234,
    v235,
    v236,
    v237,
    v238,
    v239,
    *(unsigned int *)(a1 + 228));
  DP_PRINT_STATS(
    "fw_link_buf_ring_empty_cnt = %u",
    v240,
    v241,
    v242,
    v243,
    v244,
    v245,
    v246,
    v247,
    *(unsigned int *)(a1 + 232));
  DP_PRINT_STATS(
    "host_pkt_buf_ring_refill_cnt = %u",
    v248,
    v249,
    v250,
    v251,
    v252,
    v253,
    v254,
    v255,
    *(unsigned int *)(a1 + 236));
  DP_PRINT_STATS(
    "host_pkt_buf_ring_empty_cnt = %u",
    v256,
    v257,
    v258,
    v259,
    v260,
    v261,
    v262,
    v263,
    *(unsigned int *)(a1 + 240));
  DP_PRINT_STATS(
    "mon_pkt_buf_ring_refill_cnt = %u",
    v264,
    v265,
    v266,
    v267,
    v268,
    v269,
    v270,
    v271,
    *(unsigned int *)(a1 + 244));
  DP_PRINT_STATS(
    "mon_pkt_buf_ring_empty_cnt = %u",
    v272,
    v273,
    v274,
    v275,
    v276,
    v277,
    v278,
    v279,
    *(unsigned int *)(a1 + 248));
  DP_PRINT_STATS(
    "mon_status_buf_ring_refill_cnt = %u",
    v280,
    v281,
    v282,
    v283,
    v284,
    v285,
    v286,
    v287,
    *(unsigned int *)(a1 + 252));
  DP_PRINT_STATS(
    "mon_status_buf_ring_empty_cnt = %u",
    v288,
    v289,
    v290,
    v291,
    v292,
    v293,
    v294,
    v295,
    *(unsigned int *)(a1 + 256));
  DP_PRINT_STATS(
    "mon_desc_buf_ring_refill_cnt = %u",
    v296,
    v297,
    v298,
    v299,
    v300,
    v301,
    v302,
    v303,
    *(unsigned int *)(a1 + 260));
  DP_PRINT_STATS(
    "mon_desc_buf_ring_empty_cnt = %u",
    v304,
    v305,
    v306,
    v307,
    v308,
    v309,
    v310,
    v311,
    *(unsigned int *)(a1 + 264));
  DP_PRINT_STATS(
    "mon_dest_ring_update_cnt = %u",
    v312,
    v313,
    v314,
    v315,
    v316,
    v317,
    v318,
    v319,
    *(unsigned int *)(a1 + 268));
  DP_PRINT_STATS(
    "mon_dest_ring_full_cnt = %u",
    v320,
    v321,
    v322,
    v323,
    v324,
    v325,
    v326,
    v327,
    *(unsigned int *)(a1 + 272));
  DP_PRINT_STATS("rx_suspend_cnt = %u", v328, v329, v330, v331, v332, v333, v334, v335, *(unsigned int *)(a1 + 276));
  DP_PRINT_STATS(
    "rx_suspend_fail_cnt = %u",
    v336,
    v337,
    v338,
    v339,
    v340,
    v341,
    v342,
    v343,
    *(unsigned int *)(a1 + 280));
  DP_PRINT_STATS("rx_resume_cnt = %u", v344, v345, v346, v347, v348, v349, v350, v351, *(unsigned int *)(a1 + 284));
  DP_PRINT_STATS("rx_resume_fail_cnt = %u", v352, v353, v354, v355, v356, v357, v358, v359, *(unsigned int *)(a1 + 288));
  DP_PRINT_STATS("rx_ring_switch_cnt = %u", v360, v361, v362, v363, v364, v365, v366, v367, *(unsigned int *)(a1 + 292));
  DP_PRINT_STATS(
    "rx_ring_restore_cnt = %u",
    v368,
    v369,
    v370,
    v371,
    v372,
    v373,
    v374,
    v375,
    *(unsigned int *)(a1 + 296));
  DP_PRINT_STATS("rx_flush_cnt = %u", v376, v377, v378, v379, v380, v381, v382, v383, *(unsigned int *)(a1 + 300));
  result = DP_PRINT_STATS("rx_packets_other_cnt = 0\n", v384, v385, v386, v387, v388, v389, v390, v391);
  _ReadStatusReg(SP_EL0);
  return result;
}
