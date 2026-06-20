__int64 __fastcall extract_mac_phy_cap_service_ready_ext2_tlv(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        unsigned int *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned int v14; // w8
  __int64 v15; // x20
  __int64 (*v17)(void); // x8
  unsigned int v18; // w19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
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
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  double v267; // d0
  double v268; // d1
  double v269; // d2
  double v270; // d3
  double v271; // d4
  double v272; // d5
  double v273; // d6
  double v274; // d7
  double v275; // d0
  double v276; // d1
  double v277; // d2
  double v278; // d3
  double v279; // d4
  double v280; // d5
  double v281; // d6
  double v282; // d7
  double v283; // d0
  double v284; // d1
  double v285; // d2
  double v286; // d3
  double v287; // d4
  double v288; // d5
  double v289; // d6
  double v290; // d7
  double v291; // d0
  double v292; // d1
  double v293; // d2
  double v294; // d3
  double v295; // d4
  double v296; // d5
  double v297; // d6
  double v298; // d7
  double v299; // d0
  double v300; // d1
  double v301; // d2
  double v302; // d3
  double v303; // d4
  double v304; // d5
  double v305; // d6
  double v306; // d7
  double v307; // d0
  double v308; // d1
  double v309; // d2
  double v310; // d3
  double v311; // d4
  double v312; // d5
  double v313; // d6
  double v314; // d7
  __int64 result; // x0
  int v316; // w9
  unsigned int v317; // w9
  unsigned int v318; // w9
  unsigned int v319; // w9
  __int16 v320; // w8
  int v321; // w9
  unsigned int v322; // w9
  unsigned int v323; // w9
  unsigned int v324; // w9
  unsigned int v325; // w9
  __int16 v326; // w8
  __int16 v327; // w8
  __int16 v328; // w10
  unsigned int v329; // w9

  if ( !a2 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: null evt_buf",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "extract_mac_phy_cap_service_ready_ext2_tlv");
    return 4;
  }
  v14 = *(_DWORD *)(a2 + 56);
  if ( !v14 )
    return 0;
  if ( v14 <= a5 )
    return 4;
  v15 = *(_QWORD *)(a2 + 48) + 192LL * a5;
  if ( *(_DWORD *)(v15 + 4) != a3 || *(_DWORD *)(v15 + 12) != a4 )
    return 4;
  *a6 = a3;
  a6[2] = *(_DWORD *)(v15 + 12);
  v17 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3688LL);
  if ( *((_DWORD *)v17 - 1) != -2112860426 )
    __break(0x8228u);
  a6[1] = v17();
  v18 = *(_DWORD *)(v15 + 16);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Target wireless mode: 0x%x",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "convert_wireless_modes_ext_tlv",
    v18);
  *((_QWORD *)a6 + 2) = (v18 << 23) | ((((*(_QWORD *)&v18 & 0x3FE00uLL) >> 9) & 0x1FF) << 32);
  a6[7] = *(_DWORD *)(v15 + 36);
  a6[9] = *(_DWORD *)(v15 + 40);
  a6[16] = *(_DWORD *)(v15 + 148);
  qdf_mem_copy(a6 + 6, (const void *)(v15 + 20), 4u);
  qdf_mem_copy(a6 + 8, (const void *)(v15 + 28), 4u);
  qdf_mem_copy(a6 + 10, (const void *)(v15 + 44), 0xCu);
  qdf_mem_copy(a6 + 13, (const void *)(v15 + 56), 0xCu);
  qdf_mem_copy(a6 + 17, (const void *)(v15 + 152), 8u);
  qdf_mem_copy(a6 + 19, (const void *)(v15 + 160), 0x10u);
  qdf_mem_copy(a6 + 23, (const void *)(v15 + 68), 0x28u);
  qdf_mem_copy(a6 + 33, (const void *)(v15 + 108), 0x28u);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: EHT mac caps: mac cap_info_2G %x, mac cap_info_5G %x, supp_mcs_2G %x, supp_mcs_5G %x, info_internal %x",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "extract_mac_phy_cap_ehtcaps",
    *(unsigned int *)(v15 + 20),
    *(unsigned int *)(v15 + 28),
    *(unsigned int *)(v15 + 36),
    *(unsigned int *)(v15 + 40),
    *(_DWORD *)(v15 + 148));
  qdf_trace_msg(0x31u, 8u, "EHT phy caps: ", v35, v36, v37, v38, v39, v40, v41, v42);
  qdf_trace_msg(0x31u, 8u, "2G:", v43, v44, v45, v46, v47, v48, v49, v50);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v51, v52, v53, v54, v55, v56, v57, v58, 0, a6[10]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v59, v60, v61, v62, v63, v64, v65, v66, 1, a6[11]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v67, v68, v69, v70, v71, v72, v73, v74, 2, a6[12]);
  qdf_trace_msg(0x31u, 8u, "5G:", v75, v76, v77, v78, v79, v80, v81, v82);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v83, v84, v85, v86, v87, v88, v89, v90, 0, a6[13]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v91, v92, v93, v94, v95, v96, v97, v98, 1, a6[14]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v99, v100, v101, v102, v103, v104, v105, v106, 2, a6[15]);
  qdf_trace_msg(0x31u, 8u, "2G MCS ext Map:", v107, v108, v109, v110, v111, v112, v113, v114);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v115, v116, v117, v118, v119, v120, v121, v122, 0, a6[17]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v123, v124, v125, v126, v127, v128, v129, v130, 1, a6[18]);
  qdf_trace_msg(0x31u, 8u, "5G MCS ext Map:", v131, v132, v133, v134, v135, v136, v137, v138);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v139, v140, v141, v142, v143, v144, v145, v146, 0, a6[19]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v147, v148, v149, v150, v151, v152, v153, v154, 1, a6[20]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v155, v156, v157, v158, v159, v160, v161, v162, 2, a6[21]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v163, v164, v165, v166, v167, v168, v169, v170, 3, a6[22]);
  qdf_trace_msg(
    0x31u,
    8u,
    "2G PPET: numss_m1 %x ru_bit_mask %x",
    v171,
    v172,
    v173,
    v174,
    v175,
    v176,
    v177,
    v178,
    a6[23],
    a6[24]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v179, v180, v181, v182, v183, v184, v185, v186, 0, a6[25]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v187, v188, v189, v190, v191, v192, v193, v194, 1, a6[26]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v195, v196, v197, v198, v199, v200, v201, v202, 2, a6[27]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v203, v204, v205, v206, v207, v208, v209, v210, 3, a6[28]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v211, v212, v213, v214, v215, v216, v217, v218, 4, a6[29]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v219, v220, v221, v222, v223, v224, v225, v226, 5, a6[30]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v227, v228, v229, v230, v231, v232, v233, v234, 6, a6[31]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v235, v236, v237, v238, v239, v240, v241, v242, 7, a6[32]);
  qdf_trace_msg(
    0x31u,
    8u,
    "5G PPET: numss_m1 %x ru_bit_mask %x",
    v243,
    v244,
    v245,
    v246,
    v247,
    v248,
    v249,
    v250,
    a6[33],
    a6[34]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v251, v252, v253, v254, v255, v256, v257, v258, 0, a6[35]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v259, v260, v261, v262, v263, v264, v265, v266, 1, a6[36]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v267, v268, v269, v270, v271, v272, v273, v274, 2, a6[37]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v275, v276, v277, v278, v279, v280, v281, v282, 3, a6[38]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v283, v284, v285, v286, v287, v288, v289, v290, 4, a6[39]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v291, v292, v293, v294, v295, v296, v297, v298, 5, a6[40]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v299, v300, v301, v302, v303, v304, v305, v306, 6, a6[41]);
  qdf_trace_msg(0x31u, 8u, "index %d value %x", v307, v308, v309, v310, v311, v312, v313, v314, 7, a6[42]);
  result = 0;
  if ( a6 )
  {
    if ( v15 )
    {
      v316 = a6[43] & 0xFFFE | *(_WORD *)(v15 + 176) & 1;
      *((_WORD *)a6 + 86) = a6[43] & 0xFFFE | *(_WORD *)(v15 + 176) & 1;
      v317 = v316 & 0xFFFFFFF1 | (2 * ((*(unsigned __int16 *)(v15 + 176) >> 1) & 7));
      *((_WORD *)a6 + 86) = v317;
      v318 = v317 & 0xFFFFFF8F | (16 * ((*(unsigned __int16 *)(v15 + 176) >> 4) & 7));
      *((_WORD *)a6 + 86) = v318;
      v319 = v318 & 0xFFFFFF7F | (((*(unsigned __int16 *)(v15 + 176) >> 7) & 1) << 7);
      *((_WORD *)a6 + 86) = v319;
      LOWORD(v319) = v319 & 0xF8FF | ((HIBYTE(*(_WORD *)(v15 + 176)) & 7) << 8);
      *((_WORD *)a6 + 86) = v319;
      v320 = v319 & 0x87FF | *(_WORD *)(v15 + 176) & 0x7800;
      v321 = *((unsigned __int16 *)a6 + 87);
      *((_WORD *)a6 + 86) = v320;
      v322 = v321 & 0xFFFFFFF0 | *(_WORD *)(v15 + 180) & 0xF;
      *((_WORD *)a6 + 87) = v322;
      v323 = v322 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)(v15 + 180) >> 4) & 1));
      *((_WORD *)a6 + 87) = v323;
      v324 = v323 & 0xFFFFFF9F | (32 * ((*(unsigned __int16 *)(v15 + 180) >> 5) & 3));
      *((_WORD *)a6 + 87) = v324;
      v325 = v324 & 0xFFFFF07F | (((*(unsigned __int16 *)(v15 + 180) >> 7) & 0x1F) << 7);
      *((_WORD *)a6 + 87) = v325;
      LOWORD(v325) = v325 & 0xEFFF | (((*(_WORD *)(v15 + 180) >> 12) & 1) << 12);
      *((_WORD *)a6 + 87) = v325;
      v326 = v325 & 0xDFFF | *(_WORD *)(v15 + 180) & 0x2000;
      LOWORD(v325) = *((unsigned __int8 *)a6 + 177);
      *((_WORD *)a6 + 87) = v326;
      v327 = *(unsigned __int8 *)(v15 + 188);
      LOWORD(v325) = v327 | ((_WORD)v325 << 8);
      *((_WORD *)a6 + 88) = v325;
      v328 = *(_WORD *)(v15 + 188) & 0xF00;
      *((_WORD *)a6 + 88) = v328 | v325 & 0xF0FF;
      v329 = a6[45];
      *((_WORD *)a6 + 88) = v327 | *(_WORD *)(v15 + 188) & 0xF000 | v328;
      a6[45] = v329 & 0xFFFFFF7F | (((*(_DWORD *)(v15 + 184) >> 7) & 1) << 7);
      return 0;
    }
  }
  return result;
}
