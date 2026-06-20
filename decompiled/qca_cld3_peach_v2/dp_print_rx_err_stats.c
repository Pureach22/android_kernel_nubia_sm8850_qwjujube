__int64 __fastcall dp_print_rx_err_stats(
        unsigned int *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
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
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
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
  __int64 result; // x0
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  _DWORD *v245; // x8

  DP_PRINT_STATS("intra-bss EAPOL drops: %u", a3, a4, a5, a6, a7, a8, a9, a10, a1[3546]);
  DP_PRINT_STATS("mic errors %u", v12, v13, v14, v15, v16, v17, v18, v19, *(unsigned int *)(a2 + 6096));
  DP_PRINT_STATS(
    "Invalid peer on rx path: %llu",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    *(_QWORD *)(*(_QWORD *)(a2 + 8) + 13776LL));
  DP_PRINT_STATS(
    "sw_peer_id invalid %llu",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    *(_QWORD *)(*(_QWORD *)(a2 + 8) + 13792LL));
  DP_PRINT_STATS(
    "packet_len invalid %llu",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    *(_QWORD *)(*(_QWORD *)(a2 + 8) + 13808LL));
  DP_PRINT_STATS(
    "sa or da idx invalid %u",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 13764LL));
  DP_PRINT_STATS(
    "defrag peer uninit %u",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 13760LL));
  DP_PRINT_STATS(
    "pkts delivered no peer %u",
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 13756LL));
  DP_PRINT_STATS("RX invalid cookie: %d", v68, v69, v70, v71, v72, v73, v74, v75, a1[3527]);
  DP_PRINT_STATS("RX stale cookie: %d", v76, v77, v78, v79, v80, v81, v82, v83, a1[3528]);
  DP_PRINT_STATS(
    "2k jump delba sent: %u",
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14116LL));
  DP_PRINT_STATS(
    "2k jump msdu to stack: %u",
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14120LL));
  DP_PRINT_STATS(
    "2k jump msdu drop: %u",
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14124LL));
  DP_PRINT_STATS(
    "REO err oor msdu to stack %u",
    v108,
    v109,
    v110,
    v111,
    v112,
    v113,
    v114,
    v115,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14140LL));
  DP_PRINT_STATS(
    "REO err oor msdu drop: %u",
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    v123,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14136LL));
  DP_PRINT_STATS("Rx err msdu rejected: %d", v124, v125, v126, v127, v128, v129, v130, v131, a1[3537]);
  DP_PRINT_STATS("Rx raw frame dropped: %d", v132, v133, v134, v135, v136, v137, v138, v139, a1[3539]);
  DP_PRINT_STATS(
    "Rx stale link desc cookie: %d",
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14160LL));
  DP_PRINT_STATS(
    "Rx nbuf sanity fails: %d",
    v148,
    v149,
    v150,
    v151,
    v152,
    v153,
    v154,
    v155,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14164LL));
  DP_PRINT_STATS(
    "Rx refill duplicate link desc: %d",
    v156,
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    v163,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14168LL));
  DP_PRINT_STATS(
    "Rx ipa smmu map duplicate: %d",
    v164,
    v165,
    v166,
    v167,
    v168,
    v169,
    v170,
    v171,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14068LL));
  DP_PRINT_STATS(
    "Rx ipa smmu unmap duplicate: %d",
    v172,
    v173,
    v174,
    v175,
    v176,
    v177,
    v178,
    v179,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14072LL));
  DP_PRINT_STATS(
    "Rx ipa smmu unmap no pipes: %d",
    v180,
    v181,
    v182,
    v183,
    v184,
    v185,
    v186,
    v187,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 14076LL));
  DP_PRINT_STATS("PN-in-Dest error frame pn-check fail: %d", v188, v189, v190, v191, v192, v193, v194, v195, a1[3547]);
  DP_PRINT_STATS("Reo Statistics", v196, v197, v198, v199, v200, v201, v202, v203);
  DP_PRINT_STATS("near_full: %u ", v204, v205, v206, v207, v208, v209, v210, v211, a1[3424]);
  DP_PRINT_STATS(
    "rbm error: %u msdus",
    v212,
    v213,
    v214,
    v215,
    v216,
    v217,
    v218,
    v219,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 13744LL));
  DP_PRINT_STATS(
    "hal ring access fail: %u msdus",
    v220,
    v221,
    v222,
    v223,
    v224,
    v225,
    v226,
    v227,
    *(unsigned int *)(*(_QWORD *)(a2 + 8) + 13824LL));
  result = DP_PRINT_STATS(
             "hal ring access full fail: %u msdus",
             v228,
             v229,
             v230,
             v231,
             v232,
             v233,
             v234,
             v235,
             *(unsigned int *)(*(_QWORD *)(a2 + 8) + 13828LL));
  v245 = *(_DWORD **)(a2 + 8);
  if ( v245[3491] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 0);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3492] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 1);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3493] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 2);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3494] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 3);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3495] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 4);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3496] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 5);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3497] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 6);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3498] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 7);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3499] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 8);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3500] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 9);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3501] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 10);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3502] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 11);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3503] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 12);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3504] )
  {
    result = DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 13);
    v245 = *(_DWORD **)(a2 + 8);
  }
  if ( v245[3505] )
    return DP_PRINT_STATS("Reo error number (%u): %u msdus", v237, v238, v239, v240, v241, v242, v243, v244, 14);
  return result;
}
