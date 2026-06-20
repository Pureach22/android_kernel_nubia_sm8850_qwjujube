_BYTE *__fastcall wma_aggregate_eht_cap(_BYTE *result, __int64 a2)
{
  unsigned __int64 v2; // x8
  __int64 v3; // x9
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x9
  unsigned int v10; // w10
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x11
  unsigned __int64 v13; // x11
  unsigned __int64 v14; // x11
  unsigned __int64 v15; // x11
  unsigned __int64 v16; // x11
  unsigned int v17; // w10
  unsigned __int64 v18; // x10
  unsigned __int64 v19; // x12
  unsigned int v20; // w10
  unsigned __int64 v21; // x12
  unsigned __int64 v22; // x12
  unsigned __int64 v23; // x12
  unsigned __int64 v24; // x12
  unsigned __int64 v25; // x12
  unsigned __int64 v26; // x11
  unsigned int v27; // w9
  unsigned __int64 v28; // x12
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x9
  __int64 v32; // x10
  unsigned __int64 v33; // x9
  __int64 v34; // x10
  unsigned __int64 v35; // x9
  __int64 v36; // x10
  unsigned __int64 v37; // x9
  __int64 v38; // x10
  unsigned __int64 v39; // x11
  unsigned __int64 v40; // x10
  unsigned __int64 v41; // x10
  unsigned __int64 v42; // x10
  unsigned __int64 v43; // x10
  unsigned __int64 v44; // x10
  unsigned __int64 v45; // x10
  unsigned __int64 v46; // x10
  unsigned __int64 v47; // x10
  unsigned __int64 v48; // x10
  unsigned __int64 v49; // x10
  unsigned __int64 v50; // x10
  unsigned int v51; // w9
  unsigned __int64 v52; // x10
  unsigned __int64 v53; // x10
  unsigned __int64 v54; // x10
  unsigned __int64 v55; // x10
  __int64 v56; // x9
  unsigned __int64 v57; // x8
  __int64 v58; // x10
  unsigned __int64 v59; // x8
  __int64 v60; // x10
  unsigned __int64 v61; // x9
  unsigned __int64 v62; // x9
  unsigned __int64 v63; // x9
  unsigned __int64 v64; // x9
  unsigned __int64 v65; // x9
  unsigned __int64 v66; // x9
  unsigned __int64 v67; // x9
  unsigned __int64 v68; // x9
  unsigned __int64 v69; // x9
  unsigned __int64 v70; // x9
  unsigned __int64 v71; // x9
  unsigned __int64 v72; // x9
  unsigned __int64 v73; // x9
  unsigned __int64 v74; // x9
  unsigned __int64 v75; // x9
  unsigned int v76; // w10
  unsigned __int64 v77; // x9
  unsigned int v78; // w10
  unsigned __int64 v79; // x9
  __int64 v80; // x10
  unsigned __int64 v81; // x9
  __int64 v82; // x10
  unsigned __int64 v83; // x9
  __int64 v84; // x10
  unsigned __int64 v85; // x9
  unsigned int v86; // w10
  unsigned __int64 v87; // x9
  __int64 v88; // x10
  __int64 v89; // x11
  unsigned __int64 v90; // x8
  unsigned __int64 v91; // x9
  unsigned int v92; // w10
  unsigned __int64 v93; // x9
  unsigned __int64 v94; // x8
  unsigned __int64 v95; // x9
  unsigned __int64 v96; // x9
  unsigned __int64 v97; // x9
  unsigned int v98; // w10
  unsigned __int64 v99; // x9
  unsigned int v100; // w10
  unsigned __int64 v101; // x11
  unsigned int v102; // w9
  unsigned __int64 v103; // x10
  unsigned __int64 v104; // x11
  unsigned int v105; // w10
  unsigned __int64 v106; // x9
  unsigned __int64 v107; // x11
  unsigned int v108; // w9
  unsigned __int64 v109; // x10
  unsigned __int64 v110; // x11
  unsigned int v111; // w10
  unsigned __int64 v112; // x9
  unsigned __int64 v113; // x11
  unsigned int v114; // w9
  unsigned __int64 v115; // x10
  unsigned __int64 v116; // x10
  unsigned __int64 v117; // x9
  unsigned int v118; // w10
  unsigned __int64 v119; // x9
  __int64 v120; // x10
  unsigned __int64 v121; // x9
  __int64 v122; // x10
  unsigned __int64 v123; // x9
  __int64 v124; // x10
  unsigned __int64 v125; // x9
  unsigned int v126; // w10
  unsigned __int64 v127; // x9
  __int64 v128; // x10
  __int64 v129; // x11
  unsigned __int64 v130; // x8
  unsigned __int64 v131; // x9
  unsigned int v132; // w10
  unsigned __int64 v133; // x9
  unsigned __int64 v134; // x9
  char v135; // w8
  unsigned int v136; // w10
  char v137; // w8
  unsigned int v138; // w9

  if ( !*result )
    return qdf_mem_copy(result, (const void *)a2, 0x5Cu);
  v2 = *(_QWORD *)(result + 1);
  v3 = *(_QWORD *)(a2 + 1) & 1LL | v2;
  *(_QWORD *)(result + 1) = v3;
  v4 = v3 & 0xFFFFFFFFFFFFFFFDLL | (2 * (((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 1) & 1));
  *(_QWORD *)(result + 1) = v4;
  v5 = v4 & 0xFFFFFFFFFFFFFFFBLL | (4 * (((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 2) & 1));
  *(_QWORD *)(result + 1) = v5;
  v6 = v5 & 0xFFFFFFFFFFFFFFF7LL | (8 * (((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 3) & 1));
  *(_QWORD *)(result + 1) = v6;
  v7 = v6 & 0xFFFFFFFFFFFFFFEFLL | (16 * (((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 4) & 1));
  *(_QWORD *)(result + 1) = v7;
  v8 = v7 & 0xFFFFFFFFFFFFFFDFLL | (32 * (((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 5) & 1));
  *(_QWORD *)(result + 1) = v8;
  v9 = v8 & 0xFFFFFFFFFFFFFF3FLL;
  v10 = (unsigned __int8)*(_DWORD *)(a2 + 1) >> 6;
  if ( (unsigned __int8)v2 >> 6 > v10 )
    v10 = (unsigned __int8)v2 >> 6;
  v11 = v9 | (v10 << 6);
  *(_QWORD *)(result + 1) = v11;
  v12 = v11 & 0xFFFFFFFFFFFFFEFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 8) & 1) << 8);
  *(_QWORD *)(result + 1) = v12;
  v13 = v12 & 0xFFFFFFFFFFFFFDFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 9) & 1) << 9);
  *(_QWORD *)(result + 1) = v13;
  v14 = v13 & 0xFFFFFFFFFFFFFBFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 10) & 1) << 10);
  *(_QWORD *)(result + 1) = v14;
  v15 = v14 & 0xFFFFFFFFFFFFF7FFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v2) >> 11) & 1) << 11);
  *(_QWORD *)(result + 1) = v15;
  v16 = v15 & 0xFFFFFFFFFFFFCFFFLL;
  v17 = (*(_DWORD *)(a2 + 1) >> 12) & 3;
  if ( (((unsigned int)v2 >> 12) & 3) > v17 )
    v17 = ((unsigned int)v2 >> 12) & 3;
  v18 = v16 | (v17 << 12);
  *(_QWORD *)(result + 1) = v18;
  v19 = v18;
  v20 = ((unsigned int)v18 >> 27) & 7;
  v21 = v19 & 0xFFFFFFFFFFFDFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v11) >> 17) & 1) << 17);
  *(_QWORD *)(result + 1) = v21;
  v22 = v21 & 0xFFFFFFFFFFFBFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v11) >> 18) & 1) << 18);
  *(_QWORD *)(result + 1) = v22;
  v23 = v22 & 0xFFFFFFFFFFF7FFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v11) >> 19) & 1) << 19);
  *(_QWORD *)(result + 1) = v23;
  v24 = v23 & 0xFFFFFFFFFFEFFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v11) >> 20) & 1) << 20);
  *(_QWORD *)(result + 1) = v24;
  v25 = v24 & 0xFFFFFFFFFFDFFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 1) | (unsigned int)v11) >> 21) & 1) << 21);
  *(_QWORD *)(result + 1) = v25;
  v26 = *(_DWORD *)(a2 + 1) | (unsigned int)v11;
  v27 = BYTE3(v11) & 7;
  v28 = v25 & 0xFFFFFFFFFFBFFFFFLL | (((v26 >> 22) & 1) << 22);
  *(_QWORD *)(result + 1) = v28;
  if ( v27 <= (*(_BYTE *)(a2 + 4) & 7u) )
    v27 = *(_BYTE *)(a2 + 4) & 7;
  v29 = v28 & 0xFFFFFFFFF8FFFFFFLL | (v27 << 24);
  *(_QWORD *)(result + 1) = v29;
  v30 = v29 & 0xFFFFFFFFC7FFFFFFLL;
  if ( v20 <= ((*(_DWORD *)(a2 + 1) >> 27) & 7u) )
    v20 = (*(_DWORD *)(a2 + 1) >> 27) & 7;
  v31 = v30 | (v20 << 27);
  *(_QWORD *)(result + 1) = v31;
  v32 = (*(_QWORD *)(a2 + 1) >> 30) & 7LL;
  if ( ((v2 >> 30) & 7) > (unsigned int)v32 )
    LOBYTE(v32) = (v2 >> 30) & 7;
  v33 = v31 & 0xFFFFFFFE3FFFFFFFLL | ((unsigned __int64)(v32 & 7) << 30);
  *(_QWORD *)(result + 1) = v33;
  v34 = (*(_QWORD *)(a2 + 1) >> 33) & 7LL;
  if ( ((v2 >> 33) & 7) > (unsigned int)v34 )
    LOBYTE(v34) = (v2 >> 33) & 7;
  v35 = v33 & 0xFFFFFFF1FFFFFFFFLL | ((unsigned __int64)(v34 & 7) << 33);
  *(_QWORD *)(result + 1) = v35;
  v36 = (*(_QWORD *)(a2 + 1) >> 36) & 7LL;
  if ( ((v2 >> 36) & 7) > (unsigned int)v36 )
    LOBYTE(v36) = (v2 >> 36) & 7;
  v37 = v35 & 0xFFFFFF8FFFFFFFFFLL | ((unsigned __int64)(v36 & 7) << 36);
  *(_QWORD *)(result + 1) = v37;
  v38 = (*(_QWORD *)(a2 + 1) >> 39) & 7LL;
  if ( ((v2 >> 39) & 7) > (unsigned int)v38 )
    LOBYTE(v38) = (v2 >> 39) & 7;
  v39 = v37 & 0xFFFFFC7FFFFFFFFFLL | ((unsigned __int64)(v38 & 7) << 39);
  *(_QWORD *)(result + 1) = v39;
  v40 = v37 & 0xFFFFF87FFFFFFFFFLL
      | ((unsigned __int64)(v38 & 7) << 39) & 0xFFFFFBFFFFFFFFFFLL
      | ((((v37 | *(_QWORD *)(a2 + 1)) >> 42) & 1) << 42);
  *(_QWORD *)(result + 1) = v40;
  v41 = v40 & 0xFFFFF7FFFFFFFFFFLL | ((((v37 | *(_QWORD *)(a2 + 1)) >> 43) & 1) << 43);
  *(_QWORD *)(result + 1) = v41;
  v42 = v41 & 0xFFFFEFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 44) & 1) << 44);
  *(_QWORD *)(result + 1) = v42;
  v43 = v42 & 0xFFFFDFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 45) & 1) << 45);
  *(_QWORD *)(result + 1) = v43;
  v44 = v43 & 0xFFFFBFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 46) & 1) << 46);
  *(_QWORD *)(result + 1) = v44;
  v45 = v44 & 0xFFFF7FFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 47) & 1) << 47);
  *(_QWORD *)(result + 1) = v45;
  v46 = v45 & 0xFFFEFFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 48) & 1) << 48);
  *(_QWORD *)(result + 1) = v46;
  v47 = v46 & 0xFFFDFFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 49) & 1) << 49);
  *(_QWORD *)(result + 1) = v47;
  v48 = v47 & 0xFFFBFFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 50) & 1) << 50);
  *(_QWORD *)(result + 1) = v48;
  v49 = v48 & 0xFFF7FFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 51) & 1) << 51);
  *(_QWORD *)(result + 1) = v49;
  v50 = v49 & 0xFFEFFFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v37) >> 52) & 1) << 52);
  *(_QWORD *)(result + 1) = v50;
  v51 = *(_BYTE *)(a2 + 8) & 0xF;
  if ( (HIBYTE(v2) & 0xFu) > v51 )
    LOBYTE(v51) = HIBYTE(v2) & 0xF;
  v52 = v50 & 0xF0FFFFFFFFFFFFFFLL | ((unsigned __int64)(v51 & 0xF) << 56);
  *(_QWORD *)(result + 1) = v52;
  v53 = v52 & 0xEFFFFFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v39) >> 60) & 1) << 60);
  *(_QWORD *)(result + 1) = v53;
  v54 = v53 & 0xDFFFFFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v39) >> 61) & 1) << 61);
  *(_QWORD *)(result + 1) = v54;
  v55 = v54 & 0xBFFFFFFFFFFFFFFFLL | ((((*(_QWORD *)(a2 + 1) | v39) >> 62) & 1) << 62);
  *(_QWORD *)(result + 1) = v55;
  v56 = *(_QWORD *)(result + 9);
  *(_QWORD *)(result + 1) = (*(_QWORD *)(a2 + 1) | v2) & 0x8000000000000000LL | v55 & 0x7FFFFFFFFFFFFFFFLL;
  LODWORD(v2) = *(_DWORD *)(a2 + 9) & 3;
  if ( ((unsigned __int8)v56 & 3u) <= (unsigned int)v2 )
    v2 = (unsigned int)v2;
  else
    v2 = v56 & 3;
  v57 = v56 & 0xFFFFFFFFFFFFFFFCLL | v2;
  *(_QWORD *)(result + 9) = v57;
  v58 = *(_QWORD *)(a2 + 9);
  if ( (v58 & 4) != 0 )
  {
    v59 = v57 & 0xFFFFFFFFFFFFFF83LL;
    *(_QWORD *)(result + 9) = v59 | v56 & 0x64;
    v60 = *(_QWORD *)(a2 + 9) & 0x18LL;
    *(_QWORD *)(result + 9) = v59 | v56 & 4 | v60;
    v57 = v59 | *(_QWORD *)(a2 + 9) & 0x60LL | v60 | 4;
    *(_QWORD *)(result + 9) = v57;
    v58 = *(_QWORD *)(a2 + 9);
  }
  *(_QWORD *)(result + 9) = v58 & 0x780 | v57;
  v61 = v58 & 0x780
      | v57 & 0xFFFFFFFFFFFFF7FFLL
      | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 11) & 1) << 11);
  *(_QWORD *)(result + 9) = v61;
  v62 = v61 & 0xFFFFFFFFFFFFEFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 12) & 1) << 12);
  *(_QWORD *)(result + 9) = v62;
  v63 = v62 & 0xFFFFFFFFFFFFDFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 13) & 1) << 13);
  *(_QWORD *)(result + 9) = v63;
  v64 = v63 & 0xFFFFFFFFFFFFBFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 14) & 1) << 14);
  *(_QWORD *)(result + 9) = v64;
  v65 = v64 & 0xFFFFFFFFFFFF7FFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 15) & 1) << 15);
  *(_QWORD *)(result + 9) = v65;
  v66 = v65 & 0xFFFFFFFFFFFEFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 16) & 1) << 16);
  *(_QWORD *)(result + 9) = v66;
  v67 = v66 & 0xFFFFFFFFFFFDFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 17) & 1) << 17);
  *(_QWORD *)(result + 9) = v67;
  v68 = v67 & 0xFFFFFFFFFFFBFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 18) & 1) << 18);
  *(_QWORD *)(result + 9) = v68;
  v69 = v68 & 0xFFFFFFFFFFF7FFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 19) & 1) << 19);
  *(_QWORD *)(result + 9) = v69;
  v70 = v69 & 0xFFFFFFFFFFEFFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 20) & 1) << 20);
  *(_QWORD *)(result + 9) = v70;
  v71 = v70 & 0xFFFFFFFFFFDFFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 21) & 1) << 21);
  *(_QWORD *)(result + 9) = v71;
  v72 = v71 & 0xFFFFFFFFFFBFFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 22) & 1) << 22);
  *(_QWORD *)(result + 9) = v72;
  v73 = v72 & 0xFFFFFFFFFF7FFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 23) & 1) << 23);
  *(_QWORD *)(result + 9) = v73;
  v74 = v73 & 0xFFFFFFFFFEFFFFFFLL | ((((unsigned __int64)(*(_DWORD *)(a2 + 9) | (unsigned int)v57) >> 24) & 1) << 24);
  *(_QWORD *)(result + 9) = v74;
  v75 = v74 & 0xFFFFFFFF0FFFFFFFLL;
  v76 = *(_DWORD *)(a2 + 9) >> 28;
  if ( (unsigned int)v57 >> 28 > v76 )
    v76 = (unsigned int)v57 >> 28;
  v77 = v75 | (v76 << 28);
  *(_QWORD *)(result + 9) = v77;
  v78 = *(_DWORD *)(a2 + 13) & 0xF;
  if ( (BYTE4(v57) & 0xFu) > v78 )
    LOBYTE(v78) = BYTE4(v57) & 0xF;
  v79 = v77 & 0xFFFFFFF0FFFFFFFFLL | ((unsigned __int64)(v78 & 0xF) << 32);
  *(_QWORD *)(result + 9) = v79;
  v80 = (*(_QWORD *)(a2 + 9) >> 36) & 0xFLL;
  if ( ((v57 >> 36) & 0xF) > (unsigned int)v80 )
    LOBYTE(v80) = (v57 >> 36) & 0xF;
  v81 = v79 & 0xFFFFFF0FFFFFFFFFLL | ((unsigned __int64)(v80 & 0xF) << 36);
  *(_QWORD *)(result + 9) = v81;
  v82 = (*(_QWORD *)(a2 + 9) >> 40) & 0xFLL;
  if ( ((v57 >> 40) & 0xF) > (unsigned int)v82 )
    LOBYTE(v82) = BYTE5(v57) & 0xF;
  v83 = v81 & 0xFFFFF0FFFFFFFFFFLL | ((unsigned __int64)(v82 & 0xF) << 40);
  *(_QWORD *)(result + 9) = v83;
  v84 = (*(_QWORD *)(a2 + 9) >> 44) & 0xFLL;
  if ( ((v57 >> 44) & 0xF) > (unsigned int)v84 )
    LOBYTE(v84) = (v57 >> 44) & 0xF;
  v85 = v83 & 0xFFFF0FFFFFFFFFFFLL | ((unsigned __int64)(v84 & 0xF) << 44);
  *(_QWORD *)(result + 9) = v85;
  v86 = *(_WORD *)(a2 + 15) & 0xF;
  if ( (HIWORD(v57) & 0xF) > v86 )
    LOBYTE(v86) = BYTE6(v57) & 0xF;
  v87 = v85 & 0xFFF0FFFFFFFFFFFFLL | ((unsigned __int64)(v86 & 0xF) << 48);
  *(_QWORD *)(result + 9) = v87;
  v88 = (*(_QWORD *)(a2 + 9) >> 52) & 0xFLL;
  if ( ((v57 >> 52) & 0xF) > (unsigned int)v88 )
    LOBYTE(v88) = (v57 >> 52) & 0xF;
  v89 = HIBYTE(v57) & 0xF;
  v90 = v57 >> 60;
  v91 = v87 & 0xFF0FFFFFFFFFFFFFLL | ((unsigned __int64)(v88 & 0xF) << 52);
  *(_QWORD *)(result + 9) = v91;
  v92 = *(_BYTE *)(a2 + 16) & 0xF;
  if ( (unsigned int)v89 > v92 )
    LOBYTE(v92) = v89;
  v93 = v91 & 0xF0FFFFFFFFFFFFFFLL | ((unsigned __int64)(v92 & 0xF) << 56);
  *(_QWORD *)(result + 9) = v93;
  if ( v90 <= *(_QWORD *)(a2 + 9) >> 60 )
    v90 = *(_QWORD *)(a2 + 9) >> 60;
  v95 = v93 & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)(unsigned __int8)v90 << 60);
  v94 = *(_QWORD *)(result + 17);
  *(_QWORD *)(result + 9) = v95;
  LODWORD(v95) = *(_DWORD *)(a2 + 17) & 0xF;
  if ( (v94 & 0xF) <= (unsigned int)v95 )
    v95 = (unsigned int)v95;
  else
    v95 = v94 & 0xF;
  v96 = v94 & 0xFFFFFFFFFFFFFFF0LL | v95;
  *(_QWORD *)(result + 17) = v96;
  v97 = v96 & 0xFFFFFFFFFFFFFF0FLL;
  v98 = (unsigned __int8)*(_DWORD *)(a2 + 17) >> 4;
  if ( (unsigned __int8)v94 >> 4 > v98 )
    v98 = (unsigned __int8)v94 >> 4;
  v99 = v97 | (16 * v98);
  *(_QWORD *)(result + 17) = v99;
  v100 = (*(_DWORD *)(a2 + 17) >> 8) & 0xF;
  if ( (((unsigned int)v94 >> 8) & 0xF) > v100 )
    v100 = ((unsigned int)v94 >> 8) & 0xF;
  v101 = v99 & 0xFFFFFFFFFFFFF0FFLL;
  v102 = (unsigned __int16)v99 >> 12;
  v103 = v101 | (v100 << 8);
  *(_QWORD *)(result + 17) = v103;
  if ( v102 <= (unsigned __int16)*(_DWORD *)(a2 + 17) >> 12 )
    v102 = (unsigned __int16)*(_DWORD *)(a2 + 17) >> 12;
  v104 = v103 & 0xFFFFFFFFFFFF0FFFLL;
  v105 = WORD1(v103) & 0xF;
  v106 = v104 | (v102 << 12);
  *(_QWORD *)(result + 17) = v106;
  if ( v105 <= (*(_WORD *)(a2 + 19) & 0xFu) )
    v105 = *(_WORD *)(a2 + 19) & 0xF;
  v107 = v106 & 0xFFFFFFFFFFF0FFFFLL;
  v108 = ((unsigned int)v106 >> 20) & 0xF;
  v109 = v107 | (v105 << 16);
  *(_QWORD *)(result + 17) = v109;
  if ( v108 <= ((*(_DWORD *)(a2 + 17) >> 20) & 0xFu) )
    v108 = (*(_DWORD *)(a2 + 17) >> 20) & 0xF;
  v110 = v109 & 0xFFFFFFFFFF0FFFFFLL;
  v111 = BYTE3(v109) & 0xF;
  v112 = v110 | (v108 << 20);
  *(_QWORD *)(result + 17) = v112;
  if ( v111 <= (*(_BYTE *)(a2 + 20) & 0xFu) )
    v111 = *(_BYTE *)(a2 + 20) & 0xF;
  v113 = v112 & 0xFFFFFFFFF0FFFFFFLL;
  v114 = (unsigned int)v112 >> 28;
  v115 = v113 | (v111 << 24);
  *(_QWORD *)(result + 17) = v115;
  v116 = v115 & 0xFFFFFFFF0FFFFFFFLL;
  if ( v114 <= *(_DWORD *)(a2 + 17) >> 28 )
    v114 = *(_DWORD *)(a2 + 17) >> 28;
  v117 = v116 | (v114 << 28);
  *(_QWORD *)(result + 17) = v117;
  v118 = *(_DWORD *)(a2 + 21) & 0xF;
  if ( (BYTE4(v94) & 0xFu) > v118 )
    LOBYTE(v118) = BYTE4(v94) & 0xF;
  v119 = v117 & 0xFFFFFFF0FFFFFFFFLL | ((unsigned __int64)(v118 & 0xF) << 32);
  *(_QWORD *)(result + 17) = v119;
  v120 = (*(_QWORD *)(a2 + 17) >> 36) & 0xFLL;
  if ( ((v94 >> 36) & 0xF) > (unsigned int)v120 )
    LOBYTE(v120) = (v94 >> 36) & 0xF;
  v121 = v119 & 0xFFFFFF0FFFFFFFFFLL | ((unsigned __int64)(v120 & 0xF) << 36);
  *(_QWORD *)(result + 17) = v121;
  v122 = (*(_QWORD *)(a2 + 17) >> 40) & 0xFLL;
  if ( ((v94 >> 40) & 0xF) > (unsigned int)v122 )
    LOBYTE(v122) = BYTE5(v94) & 0xF;
  v123 = v121 & 0xFFFFF0FFFFFFFFFFLL | ((unsigned __int64)(v122 & 0xF) << 40);
  *(_QWORD *)(result + 17) = v123;
  v124 = (*(_QWORD *)(a2 + 17) >> 44) & 0xFLL;
  if ( ((v94 >> 44) & 0xF) > (unsigned int)v124 )
    LOBYTE(v124) = (v94 >> 44) & 0xF;
  v125 = v123 & 0xFFFF0FFFFFFFFFFFLL | ((unsigned __int64)(v124 & 0xF) << 44);
  *(_QWORD *)(result + 17) = v125;
  v126 = *(_WORD *)(a2 + 23) & 0xF;
  if ( (HIWORD(v94) & 0xF) > v126 )
    LOBYTE(v126) = BYTE6(v94) & 0xF;
  v127 = v125 & 0xFFF0FFFFFFFFFFFFLL | ((unsigned __int64)(v126 & 0xF) << 48);
  *(_QWORD *)(result + 17) = v127;
  v128 = (*(_QWORD *)(a2 + 17) >> 52) & 0xFLL;
  if ( ((v94 >> 52) & 0xF) > (unsigned int)v128 )
    LOBYTE(v128) = (v94 >> 52) & 0xF;
  v129 = HIBYTE(v94) & 0xF;
  v130 = v94 >> 60;
  v131 = v127 & 0xFF0FFFFFFFFFFFFFLL | ((unsigned __int64)(v128 & 0xF) << 52);
  *(_QWORD *)(result + 17) = v131;
  v132 = *(_BYTE *)(a2 + 24) & 0xF;
  if ( (unsigned int)v129 > v132 )
    LOBYTE(v132) = v129;
  v133 = v131 & 0xF0FFFFFFFFFFFFFFLL | ((unsigned __int64)(v132 & 0xF) << 56);
  *(_QWORD *)(result + 17) = v133;
  if ( v130 <= *(_QWORD *)(a2 + 17) >> 60 )
    v130 = *(_QWORD *)(a2 + 17) >> 60;
  v134 = v133 & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)(unsigned __int8)v130 << 60);
  v135 = result[25];
  *(_QWORD *)(result + 17) = v134;
  v136 = v135 & 0xF;
  v137 = v135 & 0xF0;
  v138 = *(_BYTE *)(a2 + 25) & 0xF;
  if ( v136 > v138 )
    LOBYTE(v138) = v136;
  result[25] = v138 | v137;
  return result;
}
