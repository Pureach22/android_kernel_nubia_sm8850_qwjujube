__int64 __fastcall cm_copy_join_params(__int64 a1, __int64 a2, __int64 a3)
{
  void *v6; // x0
  size_t v7; // x0
  void *v8; // x0
  size_t v9; // x2
  __int64 v10; // x23
  void *v11; // x0
  __int64 v12; // x22
  void *v13; // x0
  size_t v14; // x0
  void *v15; // x0
  __int64 v16; // x24
  __int64 v17; // x25
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  __int64 v27; // x9
  bool v28; // zf
  __int64 v29; // x8
  __int64 v30; // x10
  __int64 v31; // x11
  __int64 v32; // x9
  __int64 v33; // x8
  __int64 v34; // x10
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x11
  __int64 v38; // x8
  __int64 v39; // x10
  __int64 v40; // x8
  __int64 v41; // x11
  __int64 v42; // x8
  __int64 v43; // x10
  __int64 v44; // x8
  __int64 v45; // x11
  __int64 v46; // x8
  __int64 v47; // x10
  __int64 v48; // x8
  __int64 v49; // x11
  __int64 v50; // x8
  __int64 v51; // x10
  __int64 v52; // x8
  __int64 v53; // x11
  __int64 v54; // x8
  __int64 v55; // x10
  __int64 v56; // x8
  __int64 v57; // x11
  __int64 v58; // x8
  __int64 v59; // x10
  __int64 v60; // x8
  __int64 v61; // x11
  __int64 v62; // x8
  __int64 v63; // x10
  __int64 v64; // x8
  __int64 v65; // x11
  __int64 v66; // x8
  __int64 v67; // x10
  __int64 v68; // x8
  __int64 v69; // x11
  __int64 v70; // x8
  __int64 v71; // x10
  __int64 v72; // x8
  __int64 v73; // x11
  __int64 v74; // x8
  __int64 v75; // x10
  __int64 v76; // x8
  __int64 v77; // x11
  __int64 v78; // x8
  __int64 v79; // x10
  __int64 v80; // x8
  __int64 v81; // x11
  __int64 v82; // x8
  __int64 v83; // x10
  __int64 v84; // x8
  __int64 v85; // x11
  __int64 v86; // x8
  __int64 v87; // x10
  __int64 v88; // x8
  __int64 v89; // x11
  __int64 v90; // x8
  __int64 v91; // x10
  __int64 v92; // x8
  __int64 v93; // x11
  __int64 v94; // x8
  __int64 v95; // x10
  __int64 v96; // x8
  __int64 v97; // x11
  __int64 v98; // x8
  __int64 v99; // x10
  __int64 v100; // x8
  __int64 v101; // x11
  __int64 v102; // x8
  __int64 v103; // x10
  __int64 v104; // x8
  __int64 v105; // x11
  __int64 v106; // x8
  __int64 v107; // x10
  __int64 v108; // x8
  __int64 v109; // x11
  __int64 v110; // x8
  __int64 v111; // x10
  __int64 v112; // x8
  __int64 v113; // x11
  __int64 v114; // x8
  __int64 v115; // x10
  __int64 v116; // x8
  __int64 v117; // x11
  __int64 v118; // x8
  __int64 v119; // x10
  __int64 v120; // x8
  __int64 v121; // x11
  __int64 v122; // x8
  __int64 v123; // x10
  __int64 v124; // x8
  __int64 v125; // x11
  __int64 v126; // x8
  __int64 v127; // x10
  __int64 v128; // x8
  __int64 v129; // x11
  __int64 v130; // x8
  __int64 v131; // x10
  __int64 v132; // x8
  __int64 v133; // x11
  __int64 v134; // x8
  __int64 v135; // x10
  __int64 v136; // x8
  __int64 v137; // x11
  __int64 v138; // x8
  __int64 v139; // x10
  __int64 v140; // x8
  __int64 v141; // x11
  __int64 v142; // x8
  __int64 v143; // x10
  __int64 v144; // x8
  __int64 v145; // x11
  __int64 v146; // x8
  __int64 v147; // x10
  __int64 v148; // x8
  __int64 v149; // x11
  __int64 v150; // x8
  __int64 v151; // x10
  __int64 v152; // x8
  __int64 v153; // x11
  __int64 v154; // x8
  __int64 v155; // x10
  __int64 v156; // x8
  __int64 v157; // x11
  __int64 v158; // x8
  __int64 v159; // x10
  __int64 v160; // x8
  __int64 v161; // x11
  __int64 v162; // x8
  __int64 v163; // x10
  __int64 v164; // x8
  __int64 v165; // x9
  __int64 v166; // x8
  __int64 v167; // x8
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  __int64 v176; // x10
  __int64 v177; // x12
  __int64 v178; // x11
  int v179; // w9
  unsigned int v181; // w9
  unsigned int v182; // w9
  unsigned int v183; // w9
  __int64 v184; // x0
  __int64 v185; // x0

  if ( *(_DWORD *)(a3 + 24) )
  {
    v6 = (void *)_qdf_mem_malloc(*(unsigned int *)(a3 + 24), "cm_copy_join_params", 1265);
    *(_QWORD *)(a2 + 24) = v6;
    if ( !v6 )
      return 2;
    qdf_mem_copy(v6, *(const void **)(a3 + 32), *(unsigned int *)(a3 + 24));
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(a3 + 24);
  }
  v7 = *(unsigned int *)(a3 + 40);
  if ( (_DWORD)v7 )
  {
    v8 = (void *)_qdf_mem_malloc(v7, "cm_copy_join_params", 1273);
    *(_QWORD *)(a2 + 40) = v8;
    if ( v8 )
    {
      v9 = *(unsigned int *)(a3 + 40);
      *(_DWORD *)(a2 + 32) = v9;
      qdf_mem_copy(v8, *(const void **)(a3 + 48), v9);
      goto LABEL_7;
    }
    return 2;
  }
LABEL_7:
  v10 = *(_QWORD *)(*(_QWORD *)(a3 + 56) + 24LL);
  if ( !v10 )
    goto LABEL_171;
  v11 = qdf_mem_malloc_atomic_fl(0x828u, (__int64)"util_scan_copy_cache_entry", 0x364u);
  if ( !v11 )
    goto LABEL_171;
  v12 = (__int64)v11;
  qdf_mem_copy(v11, (const void *)v10, 0x828u);
  if ( *(_QWORD *)(v10 + 1320) )
  {
    v13 = qdf_mem_malloc_atomic_fl(*(unsigned int *)(v10 + 1312), (__int64)"util_scan_copy_cache_entry", 0x36Du);
    *(_QWORD *)(v12 + 1320) = v13;
    if ( !v13 )
    {
LABEL_170:
      _qdf_mem_free(v12);
LABEL_171:
      *(_QWORD *)(a2 + 48) = 0;
      return 2;
    }
    qdf_mem_copy(v13, *(const void **)(v10 + 1320), *(unsigned int *)(v10 + 1312));
    *(_DWORD *)(v12 + 1312) = *(_DWORD *)(v10 + 1312);
  }
  if ( !*(_QWORD *)(v10 + 1896)
    || (v14 = *(unsigned int *)(v10 + 1888), !(_DWORD)v14)
    || (v15 = qdf_mem_malloc_atomic_fl(v14, (__int64)"util_scan_copy_beacon_data", 0x2D2u),
        (*(_QWORD *)(v12 + 1896) = v15) == 0) )
  {
    v184 = *(_QWORD *)(v12 + 1320);
    if ( v184 )
      _qdf_mem_free(v184);
    v185 = *(_QWORD *)(v12 + 1896);
    if ( v185 )
      _qdf_mem_free(v185);
    goto LABEL_170;
  }
  qdf_mem_copy(v15, *(const void **)(v10 + 1896), *(unsigned int *)(v10 + 1888));
  v16 = *(_QWORD *)(v12 + 1896);
  *(_DWORD *)(v12 + 1888) = *(_DWORD *)(v10 + 1888);
  v17 = *(_QWORD *)(v10 + 1896);
  memcpy((void *)(v12 + 1328), (const void *)(v10 + 1328), 0x230u);
  v26 = *(_QWORD *)(v12 + 1328);
  v27 = *(_QWORD *)(v12 + 1336);
  v28 = v26 == 0;
  v29 = v16 + v26 - v17;
  v30 = *(_QWORD *)(v12 + 1344);
  v31 = v16 + v27 - v17;
  if ( v28 )
    v29 = 0;
  v28 = v27 == 0;
  v32 = *(_QWORD *)(v12 + 1352);
  *(_QWORD *)(v12 + 1328) = v29;
  v33 = v30 - v17;
  if ( v28 )
    v31 = 0;
  v28 = v30 == 0;
  v34 = *(_QWORD *)(v12 + 1360);
  v35 = v16 + v33;
  *(_QWORD *)(v12 + 1336) = v31;
  if ( v28 )
    v35 = 0;
  *(_QWORD *)(v12 + 1344) = v35;
  if ( v32 )
    v36 = v16 + v32 - v17;
  else
    v36 = 0;
  v37 = *(_QWORD *)(v12 + 1368);
  *(_QWORD *)(v12 + 1352) = v36;
  v38 = v16 + v34 - v17;
  if ( !v34 )
    v38 = 0;
  v39 = *(_QWORD *)(v12 + 1376);
  *(_QWORD *)(v12 + 1360) = v38;
  v40 = v16 + v37 - v17;
  if ( !v37 )
    v40 = 0;
  v41 = *(_QWORD *)(v12 + 1384);
  *(_QWORD *)(v12 + 1368) = v40;
  v42 = v16 + v39 - v17;
  if ( !v39 )
    v42 = 0;
  v43 = *(_QWORD *)(v12 + 1392);
  *(_QWORD *)(v12 + 1376) = v42;
  v44 = v16 + v41 - v17;
  if ( !v41 )
    v44 = 0;
  v45 = *(_QWORD *)(v12 + 1680);
  *(_QWORD *)(v12 + 1384) = v44;
  v46 = v16 + v43 - v17;
  if ( !v43 )
    v46 = 0;
  v47 = *(_QWORD *)(v12 + 1400);
  *(_QWORD *)(v12 + 1392) = v46;
  v48 = v16 + v45 - v17;
  if ( !v45 )
    v48 = 0;
  v49 = *(_QWORD *)(v12 + 1408);
  *(_QWORD *)(v12 + 1680) = v48;
  v50 = v16 + v47 - v17;
  if ( !v47 )
    v50 = 0;
  v51 = *(_QWORD *)(v12 + 1416);
  *(_QWORD *)(v12 + 1400) = v50;
  v52 = v16 + v49 - v17;
  if ( !v49 )
    v52 = 0;
  v53 = *(_QWORD *)(v12 + 1424);
  *(_QWORD *)(v12 + 1408) = v52;
  v54 = v16 + v51 - v17;
  if ( !v51 )
    v54 = 0;
  v55 = *(_QWORD *)(v12 + 1432);
  *(_QWORD *)(v12 + 1416) = v54;
  v56 = v16 + v53 - v17;
  if ( !v53 )
    v56 = 0;
  v57 = *(_QWORD *)(v12 + 1440);
  *(_QWORD *)(v12 + 1424) = v56;
  v58 = v16 + v55 - v17;
  if ( !v55 )
    v58 = 0;
  v59 = *(_QWORD *)(v12 + 1448);
  *(_QWORD *)(v12 + 1432) = v58;
  v60 = v16 + v57 - v17;
  if ( !v57 )
    v60 = 0;
  v61 = *(_QWORD *)(v12 + 1456);
  *(_QWORD *)(v12 + 1440) = v60;
  v62 = v16 + v59 - v17;
  if ( !v59 )
    v62 = 0;
  v63 = *(_QWORD *)(v12 + 1464);
  *(_QWORD *)(v12 + 1448) = v62;
  v64 = v16 + v61 - v17;
  if ( !v61 )
    v64 = 0;
  v65 = *(_QWORD *)(v12 + 1472);
  *(_QWORD *)(v12 + 1456) = v64;
  v66 = v16 + v63 - v17;
  if ( !v63 )
    v66 = 0;
  v67 = *(_QWORD *)(v12 + 1480);
  *(_QWORD *)(v12 + 1464) = v66;
  v68 = v16 + v65 - v17;
  if ( !v65 )
    v68 = 0;
  v69 = *(_QWORD *)(v12 + 1488);
  *(_QWORD *)(v12 + 1472) = v68;
  v70 = v16 + v67 - v17;
  if ( !v67 )
    v70 = 0;
  v71 = *(_QWORD *)(v12 + 1496);
  *(_QWORD *)(v12 + 1480) = v70;
  v72 = v16 + v69 - v17;
  if ( !v69 )
    v72 = 0;
  v73 = *(_QWORD *)(v12 + 1504);
  *(_QWORD *)(v12 + 1488) = v72;
  v74 = v16 + v71 - v17;
  if ( !v71 )
    v74 = 0;
  v75 = *(_QWORD *)(v12 + 1512);
  *(_QWORD *)(v12 + 1496) = v74;
  v76 = v16 + v73 - v17;
  if ( !v73 )
    v76 = 0;
  v77 = *(_QWORD *)(v12 + 1520);
  *(_QWORD *)(v12 + 1504) = v76;
  v78 = v16 + v75 - v17;
  if ( !v75 )
    v78 = 0;
  v79 = *(_QWORD *)(v12 + 1528);
  *(_QWORD *)(v12 + 1512) = v78;
  v80 = v16 + v77 - v17;
  if ( !v77 )
    v80 = 0;
  v81 = *(_QWORD *)(v12 + 1536);
  *(_QWORD *)(v12 + 1520) = v80;
  v82 = v16 + v79 - v17;
  if ( !v79 )
    v82 = 0;
  v83 = *(_QWORD *)(v12 + 1544);
  *(_QWORD *)(v12 + 1528) = v82;
  v84 = v16 + v81 - v17;
  if ( !v81 )
    v84 = 0;
  v85 = *(_QWORD *)(v12 + 1552);
  *(_QWORD *)(v12 + 1536) = v84;
  v86 = v16 + v83 - v17;
  if ( !v83 )
    v86 = 0;
  v87 = *(_QWORD *)(v12 + 1560);
  *(_QWORD *)(v12 + 1544) = v86;
  v88 = v16 + v85 - v17;
  if ( !v85 )
    v88 = 0;
  v89 = *(_QWORD *)(v12 + 1568);
  *(_QWORD *)(v12 + 1552) = v88;
  v90 = v16 + v87 - v17;
  if ( !v87 )
    v90 = 0;
  v91 = *(_QWORD *)(v12 + 1576);
  *(_QWORD *)(v12 + 1560) = v90;
  v92 = v16 + v89 - v17;
  if ( !v89 )
    v92 = 0;
  v93 = *(_QWORD *)(v12 + 1648);
  *(_QWORD *)(v12 + 1568) = v92;
  v94 = v16 + v91 - v17;
  if ( !v91 )
    v94 = 0;
  v95 = *(_QWORD *)(v12 + 1584);
  *(_QWORD *)(v12 + 1576) = v94;
  v96 = v16 + v93 - v17;
  if ( !v93 )
    v96 = 0;
  v97 = *(_QWORD *)(v12 + 1592);
  *(_QWORD *)(v12 + 1648) = v96;
  v98 = v16 + v95 - v17;
  if ( !v95 )
    v98 = 0;
  v99 = *(_QWORD *)(v12 + 1600);
  *(_QWORD *)(v12 + 1584) = v98;
  v100 = v16 + v97 - v17;
  if ( !v97 )
    v100 = 0;
  v101 = *(_QWORD *)(v12 + 1608);
  *(_QWORD *)(v12 + 1592) = v100;
  v102 = v16 + v99 - v17;
  if ( !v99 )
    v102 = 0;
  v103 = *(_QWORD *)(v12 + 1616);
  *(_QWORD *)(v12 + 1600) = v102;
  v104 = v16 + v101 - v17;
  if ( !v101 )
    v104 = 0;
  v105 = *(_QWORD *)(v12 + 1624);
  *(_QWORD *)(v12 + 1608) = v104;
  v106 = v16 + v103 - v17;
  if ( !v103 )
    v106 = 0;
  v107 = *(_QWORD *)(v12 + 1632);
  *(_QWORD *)(v12 + 1616) = v106;
  v108 = v16 + v105 - v17;
  if ( !v105 )
    v108 = 0;
  v109 = *(_QWORD *)(v12 + 1640);
  *(_QWORD *)(v12 + 1624) = v108;
  v110 = v16 + v107 - v17;
  if ( !v107 )
    v110 = 0;
  v111 = *(_QWORD *)(v12 + 1656);
  *(_QWORD *)(v12 + 1632) = v110;
  v112 = v16 + v109 - v17;
  if ( !v109 )
    v112 = 0;
  v113 = *(_QWORD *)(v12 + 1664);
  *(_QWORD *)(v12 + 1640) = v112;
  v114 = v16 + v111 - v17;
  if ( !v111 )
    v114 = 0;
  v115 = *(_QWORD *)(v12 + 1672);
  *(_QWORD *)(v12 + 1656) = v114;
  v116 = v16 + v113 - v17;
  if ( !v113 )
    v116 = 0;
  v117 = *(_QWORD *)(v12 + 1688);
  *(_QWORD *)(v12 + 1664) = v116;
  v118 = v16 + v115 - v17;
  if ( !v115 )
    v118 = 0;
  v119 = *(_QWORD *)(v12 + 1696);
  *(_QWORD *)(v12 + 1672) = v118;
  v120 = v16 + v117 - v17;
  if ( !v117 )
    v120 = 0;
  v121 = *(_QWORD *)(v12 + 1704);
  *(_QWORD *)(v12 + 1688) = v120;
  v122 = v16 + v119 - v17;
  if ( !v119 )
    v122 = 0;
  v123 = *(_QWORD *)(v12 + 1712);
  *(_QWORD *)(v12 + 1696) = v122;
  v124 = v16 + v121 - v17;
  if ( !v121 )
    v124 = 0;
  v125 = *(_QWORD *)(v12 + 1720);
  *(_QWORD *)(v12 + 1704) = v124;
  v126 = v16 + v123 - v17;
  if ( !v123 )
    v126 = 0;
  v127 = *(_QWORD *)(v12 + 1728);
  *(_QWORD *)(v12 + 1712) = v126;
  v128 = v16 + v125 - v17;
  if ( !v125 )
    v128 = 0;
  v129 = *(_QWORD *)(v12 + 1736);
  *(_QWORD *)(v12 + 1720) = v128;
  v130 = v16 + v127 - v17;
  if ( !v127 )
    v130 = 0;
  v131 = *(_QWORD *)(v12 + 1744);
  *(_QWORD *)(v12 + 1728) = v130;
  v132 = v16 + v129 - v17;
  if ( !v129 )
    v132 = 0;
  v133 = *(_QWORD *)(v12 + 1752);
  *(_QWORD *)(v12 + 1736) = v132;
  v134 = v16 + v131 - v17;
  if ( !v131 )
    v134 = 0;
  v135 = *(_QWORD *)(v12 + 1760);
  *(_QWORD *)(v12 + 1744) = v134;
  v136 = v16 + v133 - v17;
  if ( !v133 )
    v136 = 0;
  v137 = *(_QWORD *)(v12 + 1768);
  *(_QWORD *)(v12 + 1752) = v136;
  v138 = v16 + v135 - v17;
  if ( !v135 )
    v138 = 0;
  v139 = *(_QWORD *)(v12 + 1776);
  *(_QWORD *)(v12 + 1760) = v138;
  v140 = v16 + v137 - v17;
  if ( !v137 )
    v140 = 0;
  v141 = *(_QWORD *)(v12 + 1784);
  *(_QWORD *)(v12 + 1768) = v140;
  v142 = v16 + v139 - v17;
  if ( !v139 )
    v142 = 0;
  v143 = *(_QWORD *)(v12 + 1792);
  *(_QWORD *)(v12 + 1776) = v142;
  v144 = v16 + v141 - v17;
  if ( !v141 )
    v144 = 0;
  v145 = *(_QWORD *)(v12 + 1800);
  *(_QWORD *)(v12 + 1784) = v144;
  v146 = v16 + v143 - v17;
  if ( !v143 )
    v146 = 0;
  v147 = *(_QWORD *)(v12 + 1808);
  *(_QWORD *)(v12 + 1792) = v146;
  v148 = v16 + v145 - v17;
  if ( !v145 )
    v148 = 0;
  v149 = *(_QWORD *)(v12 + 1816);
  *(_QWORD *)(v12 + 1800) = v148;
  v150 = v16 + v147 - v17;
  if ( !v147 )
    v150 = 0;
  v151 = *(_QWORD *)(v12 + 1824);
  *(_QWORD *)(v12 + 1808) = v150;
  v152 = v16 + v149 - v17;
  if ( !v149 )
    v152 = 0;
  v153 = *(_QWORD *)(v12 + 1832);
  *(_QWORD *)(v12 + 1816) = v152;
  v154 = v16 + v151 - v17;
  if ( !v151 )
    v154 = 0;
  v155 = *(_QWORD *)(v12 + 1840);
  *(_QWORD *)(v12 + 1824) = v154;
  v156 = v16 + v153 - v17;
  if ( !v153 )
    v156 = 0;
  v157 = *(_QWORD *)(v12 + 1848);
  *(_QWORD *)(v12 + 1832) = v156;
  v158 = v16 + v155 - v17;
  v28 = v155 == 0;
  v159 = *(_QWORD *)(v12 + 1856);
  if ( v28 )
    v158 = 0;
  *(_QWORD *)(v12 + 1840) = v158;
  v160 = v16 + v157 - v17;
  v28 = v157 == 0;
  v161 = *(_QWORD *)(v12 + 1864);
  if ( v28 )
    v160 = 0;
  *(_QWORD *)(v12 + 1848) = v160;
  if ( v159 )
    v162 = v16 + v159 - v17;
  else
    v162 = 0;
  v163 = *(_QWORD *)(v12 + 1872);
  *(_QWORD *)(v12 + 1856) = v162;
  if ( v161 )
    v164 = v16 + v161 - v17;
  else
    v164 = 0;
  v165 = *(_QWORD *)(v12 + 1880);
  *(_QWORD *)(v12 + 1864) = v164;
  v166 = v16 + v163 - v17;
  if ( !v163 )
    v166 = 0;
  *(_QWORD *)(v12 + 1872) = v166;
  if ( v165 )
    v167 = v16 + v165 - v17;
  else
    v167 = 0;
  *(_QWORD *)(v12 + 1880) = v167;
  *(_QWORD *)(a2 + 48) = v12;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v18, v19, v20, v21, v22, v23, v24, v25) & 1) != 0 )
  {
    qdf_mem_copy((void *)(a2 + 56), (const void *)(a3 + 80), 0xB0u);
    if ( (*(_BYTE *)(a1 + 60) & 2) == 0 )
    {
      *(_BYTE *)(a2 + 232) = *(_BYTE *)(*(_QWORD *)(a2 + 48) + 1919LL);
      mlo_mgr_reset_ap_link_info(a1);
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Num of partner links %d assoc_link_id:%d",
      v168,
      v169,
      v170,
      v171,
      v172,
      v173,
      v174,
      v175,
      "cm_copy_join_req_info_from_cm_connect_req",
      *(unsigned __int8 *)(a2 + 56),
      *(unsigned __int8 *)(a2 + 232));
  }
  if ( *(_BYTE *)(a3 + 256) )
  {
    *(_QWORD *)(a2 + 233) = *(_QWORD *)(a3 + 256);
    v177 = *(_QWORD *)(a3 + 272);
    v176 = *(_QWORD *)(a3 + 280);
    v178 = *(_QWORD *)(a3 + 264);
    *(_BYTE *)(a2 + 265) = *(_BYTE *)(a3 + 288);
    *(_QWORD *)(a2 + 249) = v177;
    *(_QWORD *)(a2 + 257) = v176;
    *(_QWORD *)(a2 + 241) = v178;
  }
  v179 = *(unsigned __int8 *)(a2 + 8);
  *(_BYTE *)a2 = *(_BYTE *)a3;
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(a3 + 4);
  v181 = v179 & 0xFFFFFFFE | *(_BYTE *)(a3 + 8) & 1;
  *(_BYTE *)(a2 + 8) = v181;
  v182 = v181 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a3 + 8) >> 1) & 1));
  *(_BYTE *)(a2 + 8) = v182;
  v183 = v182 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a3 + 8) >> 2) & 1));
  *(_BYTE *)(a2 + 8) = v183;
  *(_BYTE *)(a2 + 8) = v183 & 0xF7 | (8 * *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a3 + 56) + 24LL) + 46LL));
  *(_BYTE *)(a2 + 272) = *(_BYTE *)(a3 + 289);
  return 0;
}
