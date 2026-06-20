__int64 __fastcall cm_copy_join_params(__int64 a1, __int64 a2)
{
  size_t v2; // x8
  void *v5; // x0
  size_t v6; // x0
  void *v7; // x0
  size_t v8; // x2
  __int64 v9; // x22
  void *v10; // x0
  __int64 v11; // x21
  void *v12; // x0
  size_t v13; // x0
  void *v14; // x0
  __int64 v15; // x23
  __int64 v16; // x24
  __int64 v17; // x8
  __int64 v18; // x9
  bool v19; // zf
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x10
  __int64 v26; // x8
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
  __int64 v140; // x9
  __int64 v141; // x10
  __int64 v142; // x8
  __int64 v143; // x9
  __int64 v144; // x8
  __int64 v145; // x8
  __int64 v146; // x11
  __int64 v147; // x8
  __int64 v148; // x10
  int v149; // w9
  unsigned int v151; // w9
  unsigned int v152; // w9
  unsigned int v153; // w9
  __int64 v154; // x0
  __int64 v155; // x0

  v2 = *(unsigned int *)(a2 + 24);
  if ( (_DWORD)v2 )
  {
    v5 = (void *)_qdf_mem_malloc(v2, "cm_copy_join_params", 1265);
    *(_QWORD *)(a1 + 24) = v5;
    if ( !v5 )
      return 2;
    qdf_mem_copy(v5, *(const void **)(a2 + 32), *(unsigned int *)(a2 + 24));
    *(_DWORD *)(a1 + 16) = *(_DWORD *)(a2 + 24);
  }
  v6 = *(unsigned int *)(a2 + 40);
  if ( (_DWORD)v6 )
  {
    v7 = (void *)_qdf_mem_malloc(v6, "cm_copy_join_params", 1273);
    *(_QWORD *)(a1 + 40) = v7;
    if ( v7 )
    {
      v8 = *(unsigned int *)(a2 + 40);
      *(_DWORD *)(a1 + 32) = v8;
      qdf_mem_copy(v7, *(const void **)(a2 + 48), v8);
      goto LABEL_7;
    }
    return 2;
  }
LABEL_7:
  v9 = *(_QWORD *)(*(_QWORD *)(a2 + 56) + 24LL);
  if ( !v9 )
    goto LABEL_153;
  v10 = qdf_mem_malloc_atomic_fl(0x6C8u, (__int64)"util_scan_copy_cache_entry", 0x364u);
  if ( !v10 )
    goto LABEL_153;
  v11 = (__int64)v10;
  qdf_mem_copy(v10, (const void *)v9, 0x6C8u);
  if ( *(_QWORD *)(v9 + 1192) )
  {
    v12 = qdf_mem_malloc_atomic_fl(*(unsigned int *)(v9 + 1184), (__int64)"util_scan_copy_cache_entry", 0x36Du);
    *(_QWORD *)(v11 + 1192) = v12;
    if ( !v12 )
    {
LABEL_152:
      _qdf_mem_free(v11);
LABEL_153:
      *(_QWORD *)(a1 + 48) = 0;
      return 2;
    }
    qdf_mem_copy(v12, *(const void **)(v9 + 1192), *(unsigned int *)(v9 + 1184));
    *(_DWORD *)(v11 + 1184) = *(_DWORD *)(v9 + 1184);
  }
  if ( !*(_QWORD *)(v9 + 1712)
    || (v13 = *(unsigned int *)(v9 + 1704), !(_DWORD)v13)
    || (v14 = qdf_mem_malloc_atomic_fl(v13, (__int64)"util_scan_copy_beacon_data", 0x2D2u),
        (*(_QWORD *)(v11 + 1712) = v14) == 0) )
  {
    v154 = *(_QWORD *)(v11 + 1192);
    if ( v154 )
      _qdf_mem_free(v154);
    v155 = *(_QWORD *)(v11 + 1712);
    if ( v155 )
      _qdf_mem_free(v155);
    goto LABEL_152;
  }
  qdf_mem_copy(v14, *(const void **)(v9 + 1712), *(unsigned int *)(v9 + 1704));
  v15 = *(_QWORD *)(v11 + 1712);
  *(_DWORD *)(v11 + 1704) = *(_DWORD *)(v9 + 1704);
  v16 = *(_QWORD *)(v9 + 1712);
  memcpy((void *)(v11 + 1200), (const void *)(v9 + 1200), 0x1F8u);
  v17 = *(_QWORD *)(v11 + 1200);
  v18 = *(_QWORD *)(v11 + 1208);
  v19 = v17 == 0;
  v20 = v15 + v17 - v16;
  v21 = *(_QWORD *)(v11 + 1216);
  v22 = v15 + v18 - v16;
  if ( v19 )
    v20 = 0;
  v19 = v18 == 0;
  v23 = *(_QWORD *)(v11 + 1224);
  *(_QWORD *)(v11 + 1200) = v20;
  v24 = v21 - v16;
  if ( v19 )
    v22 = 0;
  v19 = v21 == 0;
  v25 = *(_QWORD *)(v11 + 1232);
  v26 = v15 + v24;
  *(_QWORD *)(v11 + 1208) = v22;
  if ( v19 )
    v26 = 0;
  *(_QWORD *)(v11 + 1216) = v26;
  if ( v23 )
    v27 = v15 + v23 - v16;
  else
    v27 = 0;
  v28 = *(_QWORD *)(v11 + 1240);
  *(_QWORD *)(v11 + 1224) = v27;
  v29 = v15 + v25 - v16;
  if ( !v25 )
    v29 = 0;
  v30 = *(_QWORD *)(v11 + 1248);
  *(_QWORD *)(v11 + 1232) = v29;
  v31 = v15 + v28 - v16;
  if ( !v28 )
    v31 = 0;
  v32 = *(_QWORD *)(v11 + 1256);
  *(_QWORD *)(v11 + 1240) = v31;
  v33 = v15 + v30 - v16;
  if ( !v30 )
    v33 = 0;
  v34 = *(_QWORD *)(v11 + 1264);
  *(_QWORD *)(v11 + 1248) = v33;
  v35 = v15 + v32 - v16;
  if ( !v32 )
    v35 = 0;
  v36 = *(_QWORD *)(v11 + 1552);
  *(_QWORD *)(v11 + 1256) = v35;
  v37 = v15 + v34 - v16;
  if ( !v34 )
    v37 = 0;
  v38 = *(_QWORD *)(v11 + 1272);
  *(_QWORD *)(v11 + 1264) = v37;
  v39 = v15 + v36 - v16;
  if ( !v36 )
    v39 = 0;
  v40 = *(_QWORD *)(v11 + 1280);
  *(_QWORD *)(v11 + 1552) = v39;
  v41 = v15 + v38 - v16;
  if ( !v38 )
    v41 = 0;
  v42 = *(_QWORD *)(v11 + 1288);
  *(_QWORD *)(v11 + 1272) = v41;
  v43 = v15 + v40 - v16;
  if ( !v40 )
    v43 = 0;
  v44 = *(_QWORD *)(v11 + 1296);
  *(_QWORD *)(v11 + 1280) = v43;
  v45 = v15 + v42 - v16;
  if ( !v42 )
    v45 = 0;
  v46 = *(_QWORD *)(v11 + 1304);
  *(_QWORD *)(v11 + 1288) = v45;
  v47 = v15 + v44 - v16;
  if ( !v44 )
    v47 = 0;
  v48 = *(_QWORD *)(v11 + 1312);
  *(_QWORD *)(v11 + 1296) = v47;
  v49 = v15 + v46 - v16;
  if ( !v46 )
    v49 = 0;
  v50 = *(_QWORD *)(v11 + 1320);
  *(_QWORD *)(v11 + 1304) = v49;
  v51 = v15 + v48 - v16;
  if ( !v48 )
    v51 = 0;
  v52 = *(_QWORD *)(v11 + 1328);
  *(_QWORD *)(v11 + 1312) = v51;
  v53 = v15 + v50 - v16;
  if ( !v50 )
    v53 = 0;
  v54 = *(_QWORD *)(v11 + 1336);
  *(_QWORD *)(v11 + 1320) = v53;
  v55 = v15 + v52 - v16;
  if ( !v52 )
    v55 = 0;
  v56 = *(_QWORD *)(v11 + 1344);
  *(_QWORD *)(v11 + 1328) = v55;
  v57 = v15 + v54 - v16;
  if ( !v54 )
    v57 = 0;
  v58 = *(_QWORD *)(v11 + 1352);
  *(_QWORD *)(v11 + 1336) = v57;
  v59 = v15 + v56 - v16;
  if ( !v56 )
    v59 = 0;
  v60 = *(_QWORD *)(v11 + 1360);
  *(_QWORD *)(v11 + 1344) = v59;
  v61 = v15 + v58 - v16;
  if ( !v58 )
    v61 = 0;
  v62 = *(_QWORD *)(v11 + 1368);
  *(_QWORD *)(v11 + 1352) = v61;
  v63 = v15 + v60 - v16;
  if ( !v60 )
    v63 = 0;
  v64 = *(_QWORD *)(v11 + 1376);
  *(_QWORD *)(v11 + 1360) = v63;
  v65 = v15 + v62 - v16;
  if ( !v62 )
    v65 = 0;
  v66 = *(_QWORD *)(v11 + 1384);
  *(_QWORD *)(v11 + 1368) = v65;
  v67 = v15 + v64 - v16;
  if ( !v64 )
    v67 = 0;
  v68 = *(_QWORD *)(v11 + 1392);
  *(_QWORD *)(v11 + 1376) = v67;
  v69 = v15 + v66 - v16;
  if ( !v66 )
    v69 = 0;
  v70 = *(_QWORD *)(v11 + 1400);
  *(_QWORD *)(v11 + 1384) = v69;
  v71 = v15 + v68 - v16;
  if ( !v68 )
    v71 = 0;
  v72 = *(_QWORD *)(v11 + 1408);
  *(_QWORD *)(v11 + 1392) = v71;
  v73 = v15 + v70 - v16;
  if ( !v70 )
    v73 = 0;
  v74 = *(_QWORD *)(v11 + 1416);
  *(_QWORD *)(v11 + 1400) = v73;
  v75 = v15 + v72 - v16;
  if ( !v72 )
    v75 = 0;
  v76 = *(_QWORD *)(v11 + 1424);
  *(_QWORD *)(v11 + 1408) = v75;
  v77 = v15 + v74 - v16;
  if ( !v74 )
    v77 = 0;
  v78 = *(_QWORD *)(v11 + 1432);
  *(_QWORD *)(v11 + 1416) = v77;
  v79 = v15 + v76 - v16;
  if ( !v76 )
    v79 = 0;
  v80 = *(_QWORD *)(v11 + 1440);
  *(_QWORD *)(v11 + 1424) = v79;
  v81 = v15 + v78 - v16;
  if ( !v78 )
    v81 = 0;
  v82 = *(_QWORD *)(v11 + 1448);
  *(_QWORD *)(v11 + 1432) = v81;
  v83 = v15 + v80 - v16;
  if ( !v80 )
    v83 = 0;
  v84 = *(_QWORD *)(v11 + 1520);
  *(_QWORD *)(v11 + 1440) = v83;
  v85 = v15 + v82 - v16;
  if ( !v82 )
    v85 = 0;
  v86 = *(_QWORD *)(v11 + 1456);
  *(_QWORD *)(v11 + 1448) = v85;
  v87 = v15 + v84 - v16;
  if ( !v84 )
    v87 = 0;
  v88 = *(_QWORD *)(v11 + 1464);
  *(_QWORD *)(v11 + 1520) = v87;
  v89 = v15 + v86 - v16;
  if ( !v86 )
    v89 = 0;
  v90 = *(_QWORD *)(v11 + 1472);
  *(_QWORD *)(v11 + 1456) = v89;
  v91 = v15 + v88 - v16;
  if ( !v88 )
    v91 = 0;
  v92 = *(_QWORD *)(v11 + 1480);
  *(_QWORD *)(v11 + 1464) = v91;
  v93 = v15 + v90 - v16;
  if ( !v90 )
    v93 = 0;
  v94 = *(_QWORD *)(v11 + 1488);
  *(_QWORD *)(v11 + 1472) = v93;
  v95 = v15 + v92 - v16;
  if ( !v92 )
    v95 = 0;
  v96 = *(_QWORD *)(v11 + 1496);
  *(_QWORD *)(v11 + 1480) = v95;
  v97 = v15 + v94 - v16;
  if ( !v94 )
    v97 = 0;
  v98 = *(_QWORD *)(v11 + 1504);
  *(_QWORD *)(v11 + 1488) = v97;
  v99 = v15 + v96 - v16;
  if ( !v96 )
    v99 = 0;
  v100 = *(_QWORD *)(v11 + 1512);
  *(_QWORD *)(v11 + 1496) = v99;
  v101 = v15 + v98 - v16;
  if ( !v98 )
    v101 = 0;
  v102 = *(_QWORD *)(v11 + 1528);
  *(_QWORD *)(v11 + 1504) = v101;
  v103 = v15 + v100 - v16;
  if ( !v100 )
    v103 = 0;
  v104 = *(_QWORD *)(v11 + 1536);
  *(_QWORD *)(v11 + 1512) = v103;
  v105 = v15 + v102 - v16;
  if ( !v102 )
    v105 = 0;
  v106 = *(_QWORD *)(v11 + 1544);
  *(_QWORD *)(v11 + 1528) = v105;
  v107 = v15 + v104 - v16;
  if ( !v104 )
    v107 = 0;
  v108 = *(_QWORD *)(v11 + 1560);
  *(_QWORD *)(v11 + 1536) = v107;
  v109 = v15 + v106 - v16;
  if ( !v106 )
    v109 = 0;
  v110 = *(_QWORD *)(v11 + 1568);
  *(_QWORD *)(v11 + 1544) = v109;
  v111 = v15 + v108 - v16;
  if ( !v108 )
    v111 = 0;
  v112 = *(_QWORD *)(v11 + 1576);
  *(_QWORD *)(v11 + 1560) = v111;
  v113 = v15 + v110 - v16;
  if ( !v110 )
    v113 = 0;
  v114 = *(_QWORD *)(v11 + 1584);
  *(_QWORD *)(v11 + 1568) = v113;
  v115 = v15 + v112 - v16;
  if ( !v112 )
    v115 = 0;
  v116 = *(_QWORD *)(v11 + 1592);
  *(_QWORD *)(v11 + 1576) = v115;
  v117 = v15 + v114 - v16;
  if ( !v114 )
    v117 = 0;
  v118 = *(_QWORD *)(v11 + 1600);
  *(_QWORD *)(v11 + 1584) = v117;
  v119 = v15 + v116 - v16;
  if ( !v116 )
    v119 = 0;
  v120 = *(_QWORD *)(v11 + 1608);
  *(_QWORD *)(v11 + 1592) = v119;
  v121 = v15 + v118 - v16;
  if ( !v118 )
    v121 = 0;
  v122 = *(_QWORD *)(v11 + 1616);
  *(_QWORD *)(v11 + 1600) = v121;
  v123 = v15 + v120 - v16;
  if ( !v120 )
    v123 = 0;
  v124 = *(_QWORD *)(v11 + 1624);
  *(_QWORD *)(v11 + 1608) = v123;
  v125 = v15 + v122 - v16;
  if ( !v122 )
    v125 = 0;
  v126 = *(_QWORD *)(v11 + 1632);
  *(_QWORD *)(v11 + 1616) = v125;
  v127 = v15 + v124 - v16;
  if ( !v124 )
    v127 = 0;
  v128 = *(_QWORD *)(v11 + 1640);
  *(_QWORD *)(v11 + 1624) = v127;
  v129 = v15 + v126 - v16;
  if ( !v126 )
    v129 = 0;
  v130 = *(_QWORD *)(v11 + 1648);
  *(_QWORD *)(v11 + 1632) = v129;
  v131 = v15 + v128 - v16;
  if ( !v128 )
    v131 = 0;
  v132 = *(_QWORD *)(v11 + 1656);
  *(_QWORD *)(v11 + 1640) = v131;
  v133 = v15 + v130 - v16;
  if ( !v130 )
    v133 = 0;
  v134 = *(_QWORD *)(v11 + 1664);
  *(_QWORD *)(v11 + 1648) = v133;
  v135 = v15 + v132 - v16;
  v19 = v132 == 0;
  v136 = *(_QWORD *)(v11 + 1672);
  if ( v19 )
    v135 = 0;
  *(_QWORD *)(v11 + 1656) = v135;
  v137 = v15 + v134 - v16;
  v19 = v134 == 0;
  v138 = *(_QWORD *)(v11 + 1680);
  if ( v19 )
    v137 = 0;
  *(_QWORD *)(v11 + 1664) = v137;
  if ( v136 )
    v139 = v15 + v136 - v16;
  else
    v139 = 0;
  v19 = v138 == 0;
  v140 = v15 + v138 - v16;
  v141 = *(_QWORD *)(v11 + 1688);
  *(_QWORD *)(v11 + 1672) = v139;
  if ( v19 )
    v142 = 0;
  else
    v142 = v140;
  v143 = *(_QWORD *)(v11 + 1696);
  *(_QWORD *)(v11 + 1680) = v142;
  v144 = v15 + v141 - v16;
  if ( !v141 )
    v144 = 0;
  *(_QWORD *)(v11 + 1688) = v144;
  if ( v143 )
    v145 = v15 + v143 - v16;
  else
    v145 = 0;
  *(_QWORD *)(v11 + 1696) = v145;
  *(_QWORD *)(a1 + 48) = v11;
  if ( *(_BYTE *)(a2 + 73) )
  {
    *(_QWORD *)(a1 + 56) = *(_QWORD *)(a2 + 73);
    v146 = *(_QWORD *)(a2 + 81);
    v147 = *(_QWORD *)(a2 + 89);
    v148 = *(_QWORD *)(a2 + 97);
    *(_BYTE *)(a1 + 88) = *(_BYTE *)(a2 + 105);
    *(_QWORD *)(a1 + 64) = v146;
    *(_QWORD *)(a1 + 72) = v147;
    *(_QWORD *)(a1 + 80) = v148;
  }
  v149 = *(unsigned __int8 *)(a1 + 8);
  *(_BYTE *)a1 = *(_BYTE *)a2;
  *(_DWORD *)(a1 + 4) = *(_DWORD *)(a2 + 4);
  v151 = v149 & 0xFFFFFFFE | *(_BYTE *)(a2 + 8) & 1;
  *(_BYTE *)(a1 + 8) = v151;
  v152 = v151 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a2 + 8) >> 1) & 1));
  *(_BYTE *)(a1 + 8) = v152;
  v153 = v152 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a2 + 8) >> 2) & 1));
  *(_BYTE *)(a1 + 8) = v153;
  *(_BYTE *)(a1 + 8) = v153 & 0xF7 | (8 * *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 24LL) + 46LL));
  *(_BYTE *)(a1 + 96) = *(_BYTE *)(a2 + 106);
  return 0;
}
