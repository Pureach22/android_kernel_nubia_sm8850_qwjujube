__int64 __fastcall wma_populate_soc_caps(
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
  __int64 v26; // x20
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
  unsigned int v43; // w8
  _DWORD *v44; // x27
  __int64 v45; // x8
  __int64 v46; // x20
  unsigned int v47; // w19
  unsigned __int64 v48; // x28
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
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
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
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
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  double v233; // d0
  double v234; // d1
  double v235; // d2
  double v236; // d3
  double v237; // d4
  double v238; // d5
  double v239; // d6
  double v240; // d7
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  double v249; // d0
  double v250; // d1
  double v251; // d2
  double v252; // d3
  double v253; // d4
  double v254; // d5
  double v255; // d6
  double v256; // d7
  double v257; // d0
  double v258; // d1
  double v259; // d2
  double v260; // d3
  double v261; // d4
  double v262; // d5
  double v263; // d6
  double v264; // d7
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
  double v281; // d0
  double v282; // d1
  double v283; // d2
  double v284; // d3
  double v285; // d4
  double v286; // d5
  double v287; // d6
  double v288; // d7
  double v289; // d0
  double v290; // d1
  double v291; // d2
  double v292; // d3
  double v293; // d4
  double v294; // d5
  double v295; // d6
  double v296; // d7
  __int64 v297; // x9
  __int64 v298; // x9
  __int64 v299; // x8
  __int64 v300; // x8
  __int64 v301; // x10
  __int64 v302; // x11
  const char *v303; // x2
  unsigned int v304; // w1
  double v305; // d0
  double v306; // d1
  double v307; // d2
  double v308; // d3
  double v309; // d4
  double v310; // d5
  double v311; // d6
  double v312; // d7
  __int64 result; // x0
  _QWORD v314[5]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v315[5]; // [xsp+30h] [xbp-60h] BYREF
  __int64 v316; // [xsp+58h] [xbp-38h] BYREF
  int v317; // [xsp+60h] [xbp-30h]
  __int64 v318; // [xsp+68h] [xbp-28h] BYREF
  int v319; // [xsp+70h] [xbp-20h]
  __int64 v320; // [xsp+78h] [xbp-18h] BYREF
  _QWORD v321[2]; // [xsp+80h] [xbp-10h] BYREF

  v321[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", a2, a3, a4, a5, a6, a7, a8, a9, "wma_populate_soc_caps");
  if ( !_cds_get_context(61, (__int64)"wma_init_wifi_pos_dma_rings", v10, v11, v12, v13, v14, v15, v16, v17) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: invalid hif context",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wma_init_wifi_pos_dma_rings");
  v26 = *(unsigned __int8 *)(a1 + 486);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: num of hw modes [%d]",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wma_print_populate_soc_caps",
    *(unsigned int *)(a1 + 824));
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: num mac_phy_cnt [%d]",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "wma_print_populate_soc_caps",
    (unsigned int)v26);
  v43 = *(_DWORD *)(a1 + 504);
  v44 = (_DWORD *)(a1 + 1072);
  if ( v43 <= 0xA )
  {
    if ( *v44 == v43 )
    {
      v45 = 0;
    }
    else if ( *(_DWORD *)(a1 + 1328) == v43 )
    {
      v45 = 1;
    }
    else if ( *(_DWORD *)(a1 + 1584) == v43 )
    {
      v45 = 2;
    }
    else if ( *(_DWORD *)(a1 + 1840) == v43 )
    {
      v45 = 3;
    }
    else if ( *(_DWORD *)(a1 + 2096) == v43 )
    {
      v45 = 4;
    }
    else if ( *(_DWORD *)(a1 + 2352) == v43 )
    {
      v45 = 5;
    }
    else if ( *(_DWORD *)(a1 + 2608) == v43 )
    {
      v45 = 6;
    }
    else
    {
      if ( *(_DWORD *)(a1 + 2864) != v43 )
      {
LABEL_28:
        v303 = "%s: Invalid MAC PHY capabilities handle";
        v304 = 2;
        goto LABEL_29;
      }
      v45 = 7;
    }
    v44 += 64 * v45;
  }
  if ( !v44 )
    goto LABEL_28;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: <====== HW mode cap printing starts ======>",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "wma_print_populate_soc_caps");
  if ( (_DWORD)v26 )
  {
    v46 = v26 << 8;
    v47 = 0;
    v48 = 0;
    do
    {
      if ( &v44[v48 / 4] )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "====>: hw mode id[%d], phy id[%d]",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          (unsigned int)v44[v48 / 4],
          (unsigned int)v44[v48 / 4 + 2]);
        v320 = 0;
        v321[0] = 0;
        v319 = 0;
        v318 = 0;
        v317 = 0;
        v316 = 0;
        qdf_trace_msg(0x36u, 8u, "\t: index [%d]", v49, v50, v51, v52, v53, v54, v55, v56, v47);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: cap for hw_mode_id[%d]",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          (unsigned int)v44[v48 / 4]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: pdev_id[%d]",
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          (unsigned int)v44[v48 / 4 + 1]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: phy_id[%d]",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          (unsigned int)v44[v48 / 4 + 2]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: hw_mode_config_type[%d]",
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          (unsigned int)v44[v48 / 4 + 4]);
        qdf_trace_msg(0x36u, 8u, "\t: supports_11b[%d]", v89, v90, v91, v92, v93, v94, v95, v96, v44[v48 / 4 + 5] & 1);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: supports_11g[%d]",
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          (v44[v48 / 4 + 5] >> 1) & 1);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: supports_11a[%d]",
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          v111,
          v112,
          (v44[v48 / 4 + 5] >> 2) & 1);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: supports_11n[%d]",
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          (v44[v48 / 4 + 5] >> 3) & 1);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: supports_11ac[%d]",
          v121,
          v122,
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          (v44[v48 / 4 + 5] >> 4) & 1);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: supports_11ax[%d]",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          (v44[v48 / 4 + 5] >> 5) & 1);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: supported_bands[%d]",
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          (unsigned int)v44[v48 / 4 + 6]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: ampdu_density[%d]",
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          (unsigned int)v44[v48 / 4 + 7]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: max_bw_supported_2G[%d]",
          v153,
          v154,
          v155,
          v156,
          v157,
          v158,
          v159,
          v160,
          (unsigned int)v44[v48 / 4 + 8]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: ht_cap_info_2G[%d]",
          v161,
          v162,
          v163,
          v164,
          v165,
          v166,
          v167,
          v168,
          (unsigned int)v44[v48 / 4 + 9]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: vht_cap_info_2G[0x%0X]",
          v169,
          v170,
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          (unsigned int)v44[v48 / 4 + 10]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: vht_supp_mcs_2G[0x%0X]",
          v177,
          v178,
          v179,
          v180,
          v181,
          v182,
          v183,
          v184,
          (unsigned int)v44[v48 / 4 + 11]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: tx_chain_mask_2G[%d]",
          v185,
          v186,
          v187,
          v188,
          v189,
          v190,
          v191,
          v192,
          (unsigned int)v44[v48 / 4 + 15]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: rx_chain_mask_2G[%d]",
          v193,
          v194,
          v195,
          v196,
          v197,
          v198,
          v199,
          v200,
          (unsigned int)v44[v48 / 4 + 16]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: max_bw_supported_5G[%d]",
          v201,
          v202,
          v203,
          v204,
          v205,
          v206,
          v207,
          v208,
          (unsigned int)v44[v48 / 4 + 17]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: ht_cap_info_5G[%d]",
          v209,
          v210,
          v211,
          v212,
          v213,
          v214,
          v215,
          v216,
          (unsigned int)v44[v48 / 4 + 18]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: vht_cap_info_5G[0x%0X]",
          v217,
          v218,
          v219,
          v220,
          v221,
          v222,
          v223,
          v224,
          (unsigned int)v44[v48 / 4 + 19]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: vht_supp_mcs_5G[0x%0X]",
          v225,
          v226,
          v227,
          v228,
          v229,
          v230,
          v231,
          v232,
          (unsigned int)v44[v48 / 4 + 20]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: tx_chain_mask_5G[%d]",
          v233,
          v234,
          v235,
          v236,
          v237,
          v238,
          v239,
          v240,
          (unsigned int)v44[v48 / 4 + 24]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: rx_chain_mask_5G[%d]",
          v241,
          v242,
          v243,
          v244,
          v245,
          v246,
          v247,
          v248,
          (unsigned int)v44[v48 / 4 + 25]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: he_cap_info_2G[0][%08x]",
          v249,
          v250,
          v251,
          v252,
          v253,
          v254,
          v255,
          v256,
          (unsigned int)v44[v48 / 4 + 12]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: he_cap_info_2G[1][%08x]",
          v257,
          v258,
          v259,
          v260,
          v261,
          v262,
          v263,
          v264,
          (unsigned int)v44[v48 / 4 + 13]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: he_supp_mcs_2G[%08x]",
          v265,
          v266,
          v267,
          v268,
          v269,
          v270,
          v271,
          v272,
          (unsigned int)v44[v48 / 4 + 14]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: he_cap_info_5G[0][%08x]",
          v273,
          v274,
          v275,
          v276,
          v277,
          v278,
          v279,
          v280,
          (unsigned int)v44[v48 / 4 + 21]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: he_cap_info_5G[1][%08x]",
          v281,
          v282,
          v283,
          v284,
          v285,
          v286,
          v287,
          v288,
          (unsigned int)v44[v48 / 4 + 22]);
        qdf_trace_msg(
          0x36u,
          8u,
          "\t: he_supp_mcs_5G[%08x]",
          v289,
          v290,
          v291,
          v292,
          v293,
          v294,
          v295,
          v296,
          (unsigned int)v44[v48 / 4 + 23]);
        qdf_mem_copy(v321, &v44[v48 / 4 + 12], 8u);
        qdf_mem_copy(&v320, &v44[v48 / 4 + 21], 8u);
        qdf_mem_copy(&v318, &v44[v48 / 4 + 26], 0xCu);
        qdf_mem_copy(&v316, &v44[v48 / 4 + 29], 0xCu);
        v297 = *(_QWORD *)&v44[v48 / 4 + 39];
        v315[2] = *(_QWORD *)&v44[v48 / 4 + 37];
        v315[3] = v297;
        v298 = *(_QWORD *)&v44[v48 / 4 + 43];
        v315[4] = *(_QWORD *)&v44[v48 / 4 + 41];
        v299 = *(_QWORD *)&v44[v48 / 4 + 35];
        v315[0] = *(_QWORD *)&v44[v48 / 4 + 33];
        v315[1] = v299;
        v300 = *(_QWORD *)&v44[v48 / 4 + 49];
        v301 = *(_QWORD *)&v44[v48 / 4 + 51];
        v314[2] = *(_QWORD *)&v44[v48 / 4 + 47];
        v314[3] = v300;
        v302 = *(_QWORD *)&v44[v48 / 4 + 45];
        v314[4] = v301;
        v314[0] = v298;
        v314[1] = v302;
        wma_print_he_mac_cap_w1(LODWORD(v321[0]));
        wma_print_he_mac_cap_w2(HIDWORD(v321[0]));
        wma_print_he_phy_cap(&v318);
        ((void (__fastcall *)(_QWORD *))wma_print_he_ppet)(v315);
        wma_print_he_mac_cap_w1((unsigned int)v320);
        wma_print_he_mac_cap_w1(HIDWORD(v320));
        wma_print_he_phy_cap(&v316);
        ((void (__fastcall *)(_QWORD *))wma_print_he_ppet)(v314);
      }
      v48 += 256LL;
      ++v47;
    }
    while ( v46 != v48 );
  }
  v303 = "%s: <====== HW mode cap printing ends ======>\n";
  v304 = 8;
LABEL_29:
  qdf_trace_msg(0x36u, v304, v303, v35, v36, v37, v38, v39, v40, v41, v42, "wma_print_populate_soc_caps");
  result = qdf_trace_msg(0x36u, 8u, "%s: Exit", v305, v306, v307, v308, v309, v310, v311, v312, "wma_populate_soc_caps");
  _ReadStatusReg(SP_EL0);
  return result;
}
