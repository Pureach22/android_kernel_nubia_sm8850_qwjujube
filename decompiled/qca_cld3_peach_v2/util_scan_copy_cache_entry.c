__int64 __fastcall util_scan_copy_cache_entry(__int64 a1)
{
  void *v2; // x0
  __int64 v3; // x19
  void *v4; // x0
  size_t v5; // x0
  void *v6; // x0
  __int64 v7; // x21
  __int64 v8; // x22
  __int64 v9; // x8
  __int64 v10; // x9
  bool v11; // zf
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x11
  __int64 v21; // x8
  __int64 v22; // x10
  __int64 v23; // x8
  __int64 v24; // x11
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x11
  __int64 v29; // x8
  __int64 v30; // x10
  __int64 v31; // x8
  __int64 v32; // x11
  __int64 v33; // x8
  __int64 v34; // x10
  __int64 v35; // x8
  __int64 v36; // x11
  __int64 v37; // x8
  __int64 v38; // x10
  __int64 v39; // x8
  __int64 v40; // x11
  __int64 v41; // x8
  __int64 v42; // x10
  __int64 v43; // x8
  __int64 v44; // x11
  __int64 v45; // x8
  __int64 v46; // x10
  __int64 v47; // x8
  __int64 v48; // x11
  __int64 v49; // x8
  __int64 v50; // x10
  __int64 v51; // x8
  __int64 v52; // x11
  __int64 v53; // x8
  __int64 v54; // x10
  __int64 v55; // x8
  __int64 v56; // x11
  __int64 v57; // x8
  __int64 v58; // x10
  __int64 v59; // x8
  __int64 v60; // x11
  __int64 v61; // x8
  __int64 v62; // x10
  __int64 v63; // x8
  __int64 v64; // x11
  __int64 v65; // x8
  __int64 v66; // x10
  __int64 v67; // x8
  __int64 v68; // x11
  __int64 v69; // x8
  __int64 v70; // x10
  __int64 v71; // x8
  __int64 v72; // x11
  __int64 v73; // x8
  __int64 v74; // x10
  __int64 v75; // x8
  __int64 v76; // x11
  __int64 v77; // x8
  __int64 v78; // x10
  __int64 v79; // x8
  __int64 v80; // x11
  __int64 v81; // x8
  __int64 v82; // x10
  __int64 v83; // x8
  __int64 v84; // x11
  __int64 v85; // x8
  __int64 v86; // x10
  __int64 v87; // x8
  __int64 v88; // x11
  __int64 v89; // x8
  __int64 v90; // x10
  __int64 v91; // x8
  __int64 v92; // x11
  __int64 v93; // x8
  __int64 v94; // x10
  __int64 v95; // x8
  __int64 v96; // x11
  __int64 v97; // x8
  __int64 v98; // x10
  __int64 v99; // x8
  __int64 v100; // x11
  __int64 v101; // x8
  __int64 v102; // x10
  __int64 v103; // x8
  __int64 v104; // x11
  __int64 v105; // x8
  __int64 v106; // x10
  __int64 v107; // x8
  __int64 v108; // x11
  __int64 v109; // x8
  __int64 v110; // x10
  __int64 v111; // x8
  __int64 v112; // x11
  __int64 v113; // x8
  __int64 v114; // x10
  __int64 v115; // x8
  __int64 v116; // x11
  __int64 v117; // x8
  __int64 v118; // x10
  __int64 v119; // x8
  __int64 v120; // x11
  __int64 v121; // x8
  __int64 v122; // x10
  __int64 v123; // x8
  __int64 v124; // x11
  __int64 v125; // x8
  __int64 v126; // x10
  __int64 v127; // x8
  __int64 v128; // x11
  __int64 v129; // x8
  __int64 v130; // x10
  __int64 v131; // x8
  __int64 v132; // x11
  __int64 v133; // x8
  __int64 v134; // x10
  __int64 v135; // x8
  __int64 v136; // x11
  __int64 v137; // x8
  __int64 v138; // x10
  __int64 v139; // x8
  __int64 v140; // x11
  __int64 v141; // x8
  __int64 v142; // x10
  __int64 v143; // x8
  __int64 v144; // x11
  __int64 v145; // x8
  __int64 v146; // x10
  __int64 v147; // x8
  __int64 v148; // x9
  __int64 v149; // x8
  __int64 v150; // x8
  __int64 v151; // x0
  __int64 v152; // x0

  if ( !a1 )
    return 0;
  v2 = qdf_mem_malloc_atomic_fl(0x828u, (__int64)"util_scan_copy_cache_entry", 0x364u);
  v3 = (__int64)v2;
  if ( !v2 )
    return v3;
  qdf_mem_copy(v2, (const void *)a1, 0x828u);
  if ( *(_QWORD *)(a1 + 1320) )
  {
    v4 = qdf_mem_malloc_atomic_fl(*(unsigned int *)(a1 + 1312), (__int64)"util_scan_copy_cache_entry", 0x36Du);
    *(_QWORD *)(v3 + 1320) = v4;
    if ( !v4 )
    {
LABEL_158:
      _qdf_mem_free(v3);
      return 0;
    }
    qdf_mem_copy(v4, *(const void **)(a1 + 1320), *(unsigned int *)(a1 + 1312));
    *(_DWORD *)(v3 + 1312) = *(_DWORD *)(a1 + 1312);
  }
  if ( !*(_QWORD *)(a1 + 1896)
    || (v5 = *(unsigned int *)(a1 + 1888), !(_DWORD)v5)
    || (v6 = qdf_mem_malloc_atomic_fl(v5, (__int64)"util_scan_copy_beacon_data", 0x2D2u),
        (*(_QWORD *)(v3 + 1896) = v6) == 0) )
  {
    v151 = *(_QWORD *)(v3 + 1320);
    if ( v151 )
      _qdf_mem_free(v151);
    v152 = *(_QWORD *)(v3 + 1896);
    if ( v152 )
      _qdf_mem_free(v152);
    goto LABEL_158;
  }
  qdf_mem_copy(v6, *(const void **)(a1 + 1896), *(unsigned int *)(a1 + 1888));
  v7 = *(_QWORD *)(v3 + 1896);
  *(_DWORD *)(v3 + 1888) = *(_DWORD *)(a1 + 1888);
  v8 = *(_QWORD *)(a1 + 1896);
  memcpy((void *)(v3 + 1328), (const void *)(a1 + 1328), 0x230u);
  v9 = *(_QWORD *)(v3 + 1328);
  v10 = *(_QWORD *)(v3 + 1336);
  v11 = v9 == 0;
  v12 = v7 + v9 - v8;
  v13 = *(_QWORD *)(v3 + 1344);
  v14 = v7 + v10 - v8;
  if ( v11 )
    v12 = 0;
  v11 = v10 == 0;
  v15 = *(_QWORD *)(v3 + 1352);
  *(_QWORD *)(v3 + 1328) = v12;
  v16 = v13 - v8;
  if ( v11 )
    v14 = 0;
  v11 = v13 == 0;
  v17 = *(_QWORD *)(v3 + 1360);
  v18 = v7 + v16;
  *(_QWORD *)(v3 + 1336) = v14;
  if ( v11 )
    v18 = 0;
  *(_QWORD *)(v3 + 1344) = v18;
  if ( v15 )
    v19 = v7 + v15 - v8;
  else
    v19 = 0;
  v20 = *(_QWORD *)(v3 + 1368);
  *(_QWORD *)(v3 + 1352) = v19;
  v21 = v7 + v17 - v8;
  if ( !v17 )
    v21 = 0;
  v22 = *(_QWORD *)(v3 + 1376);
  *(_QWORD *)(v3 + 1360) = v21;
  v23 = v7 + v20 - v8;
  if ( !v20 )
    v23 = 0;
  v24 = *(_QWORD *)(v3 + 1384);
  *(_QWORD *)(v3 + 1368) = v23;
  v25 = v7 + v22 - v8;
  if ( !v22 )
    v25 = 0;
  v26 = *(_QWORD *)(v3 + 1392);
  *(_QWORD *)(v3 + 1376) = v25;
  v27 = v7 + v24 - v8;
  if ( !v24 )
    v27 = 0;
  v28 = *(_QWORD *)(v3 + 1680);
  *(_QWORD *)(v3 + 1384) = v27;
  v29 = v7 + v26 - v8;
  if ( !v26 )
    v29 = 0;
  v30 = *(_QWORD *)(v3 + 1400);
  *(_QWORD *)(v3 + 1392) = v29;
  v31 = v7 + v28 - v8;
  if ( !v28 )
    v31 = 0;
  v32 = *(_QWORD *)(v3 + 1408);
  *(_QWORD *)(v3 + 1680) = v31;
  v33 = v7 + v30 - v8;
  if ( !v30 )
    v33 = 0;
  v34 = *(_QWORD *)(v3 + 1416);
  *(_QWORD *)(v3 + 1400) = v33;
  v35 = v7 + v32 - v8;
  if ( !v32 )
    v35 = 0;
  v36 = *(_QWORD *)(v3 + 1424);
  *(_QWORD *)(v3 + 1408) = v35;
  v37 = v7 + v34 - v8;
  if ( !v34 )
    v37 = 0;
  v38 = *(_QWORD *)(v3 + 1432);
  *(_QWORD *)(v3 + 1416) = v37;
  v39 = v7 + v36 - v8;
  if ( !v36 )
    v39 = 0;
  v40 = *(_QWORD *)(v3 + 1440);
  *(_QWORD *)(v3 + 1424) = v39;
  v41 = v7 + v38 - v8;
  if ( !v38 )
    v41 = 0;
  v42 = *(_QWORD *)(v3 + 1448);
  *(_QWORD *)(v3 + 1432) = v41;
  v43 = v7 + v40 - v8;
  if ( !v40 )
    v43 = 0;
  v44 = *(_QWORD *)(v3 + 1456);
  *(_QWORD *)(v3 + 1440) = v43;
  v45 = v7 + v42 - v8;
  if ( !v42 )
    v45 = 0;
  v46 = *(_QWORD *)(v3 + 1464);
  *(_QWORD *)(v3 + 1448) = v45;
  v47 = v7 + v44 - v8;
  if ( !v44 )
    v47 = 0;
  v48 = *(_QWORD *)(v3 + 1472);
  *(_QWORD *)(v3 + 1456) = v47;
  v49 = v7 + v46 - v8;
  if ( !v46 )
    v49 = 0;
  v50 = *(_QWORD *)(v3 + 1480);
  *(_QWORD *)(v3 + 1464) = v49;
  v51 = v7 + v48 - v8;
  if ( !v48 )
    v51 = 0;
  v52 = *(_QWORD *)(v3 + 1488);
  *(_QWORD *)(v3 + 1472) = v51;
  v53 = v7 + v50 - v8;
  if ( !v50 )
    v53 = 0;
  v54 = *(_QWORD *)(v3 + 1496);
  *(_QWORD *)(v3 + 1480) = v53;
  v55 = v7 + v52 - v8;
  if ( !v52 )
    v55 = 0;
  v56 = *(_QWORD *)(v3 + 1504);
  *(_QWORD *)(v3 + 1488) = v55;
  v57 = v7 + v54 - v8;
  if ( !v54 )
    v57 = 0;
  v58 = *(_QWORD *)(v3 + 1512);
  *(_QWORD *)(v3 + 1496) = v57;
  v59 = v7 + v56 - v8;
  if ( !v56 )
    v59 = 0;
  v60 = *(_QWORD *)(v3 + 1520);
  *(_QWORD *)(v3 + 1504) = v59;
  v61 = v7 + v58 - v8;
  if ( !v58 )
    v61 = 0;
  v62 = *(_QWORD *)(v3 + 1528);
  *(_QWORD *)(v3 + 1512) = v61;
  v63 = v7 + v60 - v8;
  if ( !v60 )
    v63 = 0;
  v64 = *(_QWORD *)(v3 + 1536);
  *(_QWORD *)(v3 + 1520) = v63;
  v65 = v7 + v62 - v8;
  if ( !v62 )
    v65 = 0;
  v66 = *(_QWORD *)(v3 + 1544);
  *(_QWORD *)(v3 + 1528) = v65;
  v67 = v7 + v64 - v8;
  if ( !v64 )
    v67 = 0;
  v68 = *(_QWORD *)(v3 + 1552);
  *(_QWORD *)(v3 + 1536) = v67;
  v69 = v7 + v66 - v8;
  if ( !v66 )
    v69 = 0;
  v70 = *(_QWORD *)(v3 + 1560);
  *(_QWORD *)(v3 + 1544) = v69;
  v71 = v7 + v68 - v8;
  if ( !v68 )
    v71 = 0;
  v72 = *(_QWORD *)(v3 + 1568);
  *(_QWORD *)(v3 + 1552) = v71;
  v73 = v7 + v70 - v8;
  if ( !v70 )
    v73 = 0;
  v74 = *(_QWORD *)(v3 + 1576);
  *(_QWORD *)(v3 + 1560) = v73;
  v75 = v7 + v72 - v8;
  if ( !v72 )
    v75 = 0;
  v76 = *(_QWORD *)(v3 + 1648);
  *(_QWORD *)(v3 + 1568) = v75;
  v77 = v7 + v74 - v8;
  if ( !v74 )
    v77 = 0;
  v78 = *(_QWORD *)(v3 + 1584);
  *(_QWORD *)(v3 + 1576) = v77;
  v79 = v7 + v76 - v8;
  if ( !v76 )
    v79 = 0;
  v80 = *(_QWORD *)(v3 + 1592);
  *(_QWORD *)(v3 + 1648) = v79;
  v81 = v7 + v78 - v8;
  if ( !v78 )
    v81 = 0;
  v82 = *(_QWORD *)(v3 + 1600);
  *(_QWORD *)(v3 + 1584) = v81;
  v83 = v7 + v80 - v8;
  if ( !v80 )
    v83 = 0;
  v84 = *(_QWORD *)(v3 + 1608);
  *(_QWORD *)(v3 + 1592) = v83;
  v85 = v7 + v82 - v8;
  if ( !v82 )
    v85 = 0;
  v86 = *(_QWORD *)(v3 + 1616);
  *(_QWORD *)(v3 + 1600) = v85;
  v87 = v7 + v84 - v8;
  if ( !v84 )
    v87 = 0;
  v88 = *(_QWORD *)(v3 + 1624);
  *(_QWORD *)(v3 + 1608) = v87;
  v89 = v7 + v86 - v8;
  if ( !v86 )
    v89 = 0;
  v90 = *(_QWORD *)(v3 + 1632);
  *(_QWORD *)(v3 + 1616) = v89;
  v91 = v7 + v88 - v8;
  if ( !v88 )
    v91 = 0;
  v92 = *(_QWORD *)(v3 + 1640);
  *(_QWORD *)(v3 + 1624) = v91;
  v93 = v7 + v90 - v8;
  if ( !v90 )
    v93 = 0;
  v94 = *(_QWORD *)(v3 + 1656);
  *(_QWORD *)(v3 + 1632) = v93;
  v95 = v7 + v92 - v8;
  if ( !v92 )
    v95 = 0;
  v96 = *(_QWORD *)(v3 + 1664);
  *(_QWORD *)(v3 + 1640) = v95;
  v97 = v7 + v94 - v8;
  if ( !v94 )
    v97 = 0;
  v98 = *(_QWORD *)(v3 + 1672);
  *(_QWORD *)(v3 + 1656) = v97;
  v99 = v7 + v96 - v8;
  if ( !v96 )
    v99 = 0;
  v100 = *(_QWORD *)(v3 + 1688);
  *(_QWORD *)(v3 + 1664) = v99;
  v101 = v7 + v98 - v8;
  if ( !v98 )
    v101 = 0;
  v102 = *(_QWORD *)(v3 + 1696);
  *(_QWORD *)(v3 + 1672) = v101;
  v103 = v7 + v100 - v8;
  if ( !v100 )
    v103 = 0;
  v104 = *(_QWORD *)(v3 + 1704);
  *(_QWORD *)(v3 + 1688) = v103;
  v105 = v7 + v102 - v8;
  if ( !v102 )
    v105 = 0;
  v106 = *(_QWORD *)(v3 + 1712);
  *(_QWORD *)(v3 + 1696) = v105;
  v107 = v7 + v104 - v8;
  if ( !v104 )
    v107 = 0;
  v108 = *(_QWORD *)(v3 + 1720);
  *(_QWORD *)(v3 + 1704) = v107;
  v109 = v7 + v106 - v8;
  if ( !v106 )
    v109 = 0;
  v110 = *(_QWORD *)(v3 + 1728);
  *(_QWORD *)(v3 + 1712) = v109;
  v111 = v7 + v108 - v8;
  if ( !v108 )
    v111 = 0;
  v112 = *(_QWORD *)(v3 + 1736);
  *(_QWORD *)(v3 + 1720) = v111;
  v113 = v7 + v110 - v8;
  if ( !v110 )
    v113 = 0;
  v114 = *(_QWORD *)(v3 + 1744);
  *(_QWORD *)(v3 + 1728) = v113;
  v115 = v7 + v112 - v8;
  if ( !v112 )
    v115 = 0;
  v116 = *(_QWORD *)(v3 + 1752);
  *(_QWORD *)(v3 + 1736) = v115;
  v117 = v7 + v114 - v8;
  if ( !v114 )
    v117 = 0;
  v118 = *(_QWORD *)(v3 + 1760);
  *(_QWORD *)(v3 + 1744) = v117;
  v119 = v7 + v116 - v8;
  if ( !v116 )
    v119 = 0;
  v120 = *(_QWORD *)(v3 + 1768);
  *(_QWORD *)(v3 + 1752) = v119;
  v121 = v7 + v118 - v8;
  if ( !v118 )
    v121 = 0;
  v122 = *(_QWORD *)(v3 + 1776);
  *(_QWORD *)(v3 + 1760) = v121;
  v123 = v7 + v120 - v8;
  if ( !v120 )
    v123 = 0;
  v124 = *(_QWORD *)(v3 + 1784);
  *(_QWORD *)(v3 + 1768) = v123;
  v125 = v7 + v122 - v8;
  if ( !v122 )
    v125 = 0;
  v126 = *(_QWORD *)(v3 + 1792);
  *(_QWORD *)(v3 + 1776) = v125;
  v127 = v7 + v124 - v8;
  if ( !v124 )
    v127 = 0;
  v128 = *(_QWORD *)(v3 + 1800);
  *(_QWORD *)(v3 + 1784) = v127;
  v129 = v7 + v126 - v8;
  if ( !v126 )
    v129 = 0;
  v130 = *(_QWORD *)(v3 + 1808);
  *(_QWORD *)(v3 + 1792) = v129;
  v131 = v7 + v128 - v8;
  if ( !v128 )
    v131 = 0;
  v132 = *(_QWORD *)(v3 + 1816);
  *(_QWORD *)(v3 + 1800) = v131;
  v133 = v7 + v130 - v8;
  if ( !v130 )
    v133 = 0;
  v134 = *(_QWORD *)(v3 + 1824);
  *(_QWORD *)(v3 + 1808) = v133;
  v135 = v7 + v132 - v8;
  if ( !v132 )
    v135 = 0;
  v136 = *(_QWORD *)(v3 + 1832);
  *(_QWORD *)(v3 + 1816) = v135;
  v137 = v7 + v134 - v8;
  if ( !v134 )
    v137 = 0;
  v138 = *(_QWORD *)(v3 + 1840);
  *(_QWORD *)(v3 + 1824) = v137;
  v139 = v7 + v136 - v8;
  if ( !v136 )
    v139 = 0;
  v140 = *(_QWORD *)(v3 + 1848);
  *(_QWORD *)(v3 + 1832) = v139;
  v141 = v7 + v138 - v8;
  v11 = v138 == 0;
  v142 = *(_QWORD *)(v3 + 1856);
  if ( v11 )
    v141 = 0;
  *(_QWORD *)(v3 + 1840) = v141;
  v143 = v7 + v140 - v8;
  v11 = v140 == 0;
  v144 = *(_QWORD *)(v3 + 1864);
  if ( v11 )
    v143 = 0;
  *(_QWORD *)(v3 + 1848) = v143;
  if ( v142 )
    v145 = v7 + v142 - v8;
  else
    v145 = 0;
  v146 = *(_QWORD *)(v3 + 1872);
  *(_QWORD *)(v3 + 1856) = v145;
  if ( v144 )
    v147 = v7 + v144 - v8;
  else
    v147 = 0;
  v148 = *(_QWORD *)(v3 + 1880);
  *(_QWORD *)(v3 + 1864) = v147;
  v149 = v7 + v146 - v8;
  if ( !v146 )
    v149 = 0;
  *(_QWORD *)(v3 + 1872) = v149;
  if ( v148 )
    v150 = v7 + v148 - v8;
  else
    v150 = 0;
  *(_QWORD *)(v3 + 1880) = v150;
  return v3;
}
