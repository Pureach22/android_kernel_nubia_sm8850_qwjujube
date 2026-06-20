int *__fastcall dp_rx_mon_config_packet_type_subtype(int *result, __int64 *a2, int a3)
{
  __int64 v3; // x8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8
  int v9; // w8
  int v10; // w8
  int v11; // w8
  int v12; // w8
  __int64 v13; // x9
  int v14; // w8
  int v15; // w8
  int v16; // w8
  int v17; // w8
  int v18; // w8
  int v19; // w8
  int v20; // w8
  int v21; // w8
  int v22; // w8
  int v23; // w8
  int v24; // w8
  int v25; // w8
  int v26; // w8
  int v27; // w8
  int v28; // w8
  int v29; // w8
  int v30; // w8
  int v31; // w8
  int v32; // w8
  unsigned int v33; // w8
  int v34; // w9
  int v35; // w8
  int v36; // w8
  int v37; // w8
  int v38; // w8
  int v39; // w8
  int v40; // w8
  int v41; // w8
  int v42; // w8
  int v43; // w8
  int v44; // w8
  int v45; // w8
  int v46; // w8
  __int64 v47; // x9
  int v48; // w8
  int v49; // w8
  unsigned int v50; // w8
  unsigned int v51; // w8
  unsigned int v52; // w8
  unsigned int v53; // w8
  unsigned int v54; // w8
  unsigned int v55; // w8
  int v56; // w8
  int v57; // w8
  int v58; // w8
  int v59; // w8
  int v60; // w8
  int v61; // w8
  int v62; // w8
  int v63; // w8
  int v64; // w8
  int v65; // w8
  int v66; // w8
  int v67; // w8
  int v68; // w8
  int v69; // w8
  int v70; // w8
  int v71; // w8
  int v72; // w8
  int v73; // w8
  int v74; // w8
  int v75; // w8
  __int64 v76; // x9
  int v77; // w8
  unsigned int v78; // w8
  int v79; // w9
  int v80; // w8
  int v81; // w8
  int v82; // w8
  int v83; // w8
  unsigned int v84; // w8
  int v85; // w8
  int v86; // w8
  int v87; // w8
  int v88; // w8
  int v89; // w8
  int v90; // w8
  int v91; // w8
  int v92; // w8
  int v93; // w8
  int v94; // w8
  int v95; // w8
  int v96; // w8
  int v97; // w8
  int v98; // w8
  int v99; // w8
  int v100; // w8
  int v101; // w8
  char v102; // w8
  int v103; // w9
  int v104; // w8
  int v105; // w8
  int v106; // w8
  int v107; // w8
  int v108; // w8
  int v109; // w8
  int v110; // w8
  int v111; // w8
  int v112; // w8
  int v113; // w8
  int v114; // w8
  int v115; // w8
  int v116; // w8
  int v117; // w8
  unsigned int v118; // w8
  unsigned int v119; // w8
  unsigned int v120; // w8
  int v121; // w8
  int v122; // w8
  int v123; // w8
  int v124; // w8
  int v125; // w8
  int v126; // w8
  int v127; // w8
  int v128; // w8
  int v129; // w8
  int v130; // w8
  int v131; // w8
  int v132; // w8
  unsigned int v133; // w8
  int v134; // w9

  if ( !result || !a2 || a3 != 12 )
    return result;
  v3 = *a2;
  if ( (*a2 & 0x20000) != 0 )
  {
    v15 = *result | *((_WORD *)a2 + 11) & 1;
    *result = v15;
    v16 = v15 | (4 * *((unsigned __int16 *)a2 + 11)) & 8;
    *result = v16;
    v17 = v16 | (16 * *((unsigned __int16 *)a2 + 11)) & 0x40;
    *result = v17;
    v18 = v17 | (*((unsigned __int16 *)a2 + 11) << 6) & 0x200;
    *result = v18;
    v19 = v18 | (*((unsigned __int16 *)a2 + 11) << 8) & 0x1000;
    *result = v19;
    v20 = v19 | (*((unsigned __int16 *)a2 + 11) << 10) & 0x8000;
    *result = v20;
    v21 = v20 | (((*((unsigned __int16 *)a2 + 11) >> 6) & 1) << 18);
    *result = v21;
    v22 = v21 | (((*((unsigned __int16 *)a2 + 11) >> 7) & 1) << 21);
    *result = v22;
    v23 = v22 | ((HIBYTE(*((unsigned __int16 *)a2 + 11)) & 1) << 24);
    *result = v23;
    *result = v23 | (((*((unsigned __int16 *)a2 + 11) >> 9) & 1) << 27);
    v3 = *a2;
    if ( (*a2 & 0x40000) == 0 )
    {
LABEL_6:
      if ( (v3 & 0x80000) == 0 )
        goto LABEL_8;
      goto LABEL_7;
    }
  }
  else if ( (v3 & 0x40000) == 0 )
  {
    goto LABEL_6;
  }
  v24 = *result | (2 * (*((_WORD *)a2 + 18) & 1));
  *result = v24;
  v25 = v24 | (8 * *((unsigned __int16 *)a2 + 18)) & 0x10;
  *result = v25;
  v26 = v25 | (32 * *((unsigned __int16 *)a2 + 18)) & 0x80;
  *result = v26;
  v27 = v26 | (*((unsigned __int16 *)a2 + 18) << 7) & 0x400;
  *result = v27;
  v28 = v27 | (*((unsigned __int16 *)a2 + 18) << 9) & 0x2000;
  *result = v28;
  v29 = v28 | (((*((unsigned __int16 *)a2 + 18) >> 5) & 1) << 16);
  *result = v29;
  v30 = v29 | (((*((unsigned __int16 *)a2 + 18) >> 6) & 1) << 19);
  *result = v30;
  v31 = v30 | (((*((unsigned __int16 *)a2 + 18) >> 7) & 1) << 22);
  *result = v31;
  v32 = v31 | ((HIBYTE(*((unsigned __int16 *)a2 + 18)) & 1) << 25);
  *result = v32;
  *result = v32 | (((*((unsigned __int16 *)a2 + 18) >> 9) & 1) << 28);
  if ( (*a2 & 0x80000) != 0 )
  {
LABEL_7:
    v4 = *result | (4 * (a2[3] & 1));
    *result = v4;
    v5 = v4 | (16 * *((unsigned __int16 *)a2 + 12)) & 0x20;
    *result = v5;
    v6 = v5 | (*((unsigned __int16 *)a2 + 12) << 6) & 0x100;
    *result = v6;
    v7 = v6 | (*((unsigned __int16 *)a2 + 12) << 8) & 0x800;
    *result = v7;
    v8 = v7 | (*((unsigned __int16 *)a2 + 12) << 10) & 0x4000;
    *result = v8;
    v9 = v8 | (((*((unsigned __int16 *)a2 + 12) >> 5) & 1) << 17);
    *result = v9;
    v10 = v9 | (((*((unsigned __int16 *)a2 + 12) >> 6) & 1) << 20);
    *result = v10;
    v11 = v10 | (((*((unsigned __int16 *)a2 + 12) >> 7) & 1) << 23);
    *result = v11;
    v12 = v11 | ((HIBYTE(*((unsigned __int16 *)a2 + 12)) & 1) << 26);
    *result = v12;
    *result = v12 | (((*((unsigned __int16 *)a2 + 12) >> 9) & 1) << 29);
  }
LABEL_8:
  result[1] = 0;
  v13 = *a2;
  if ( (*a2 & 0x20000) != 0 )
  {
    v33 = *((unsigned __int16 *)a2 + 11);
    result[1] = (v33 >> 10) & 1;
    v34 = HIBYTE(*((unsigned __int16 *)a2 + 11)) & 8 | (v33 >> 10) & 1;
    result[1] = v34;
    v35 = (*((unsigned __int16 *)a2 + 11) >> 6) & 0x40 | v34;
    result[1] = v35;
    v36 = (*((unsigned __int16 *)a2 + 11) >> 4) & 0x200 | v35;
    result[1] = v36;
    v37 = (*((unsigned __int16 *)a2 + 11) >> 2) & 0x1000 | v36;
    result[1] = v37;
    v14 = v37 | *((_WORD *)a2 + 11) & 0x8000;
    result[1] = v14;
    v13 = *a2;
    if ( (*a2 & 0x40000) == 0 )
      goto LABEL_16;
    goto LABEL_15;
  }
  v14 = 0;
  if ( (v13 & 0x40000) != 0 )
  {
LABEL_15:
    v38 = v14 | (*((unsigned __int16 *)a2 + 18) >> 9) & 2;
    result[1] = v38;
    v39 = v38 | (*((unsigned __int16 *)a2 + 18) >> 7) & 0x10;
    result[1] = v39;
    v40 = v39 | (*((unsigned __int16 *)a2 + 18) >> 5) & 0x80;
    result[1] = v40;
    v41 = v40 | (*((unsigned __int16 *)a2 + 18) >> 3) & 0x400;
    result[1] = v41;
    v14 = v41 | (*((unsigned __int16 *)a2 + 18) >> 1) & 0x2000;
    result[1] = v14;
    v13 = *a2;
  }
LABEL_16:
  if ( (v13 & 0x80000) != 0 )
  {
    v42 = v14 | HIBYTE(*((unsigned __int16 *)a2 + 12)) & 4;
    result[1] = v42;
    v43 = v42 | (*((unsigned __int16 *)a2 + 12) >> 6) & 0x20;
    result[1] = v43;
    v44 = v43 | (*((unsigned __int16 *)a2 + 12) >> 4) & 0x100;
    result[1] = v44;
    v45 = v44 | (*((unsigned __int16 *)a2 + 12) >> 2) & 0x800;
    result[1] = v45;
    v46 = v45 | a2[3] & 0x4000;
    result[1] = v46;
    result[1] = v46 & 0xFFFDFFFF | (((*((unsigned __int16 *)a2 + 12) >> 15) & 1) << 17);
  }
  result[2] = 0;
  v47 = *a2;
  if ( (*a2 & 0x20000) != 0 )
  {
    v49 = *((_WORD *)a2 + 13) & 1;
    result[2] = v49;
    v50 = v49 & 0xFFFFFFF7 | (8 * ((*((unsigned __int16 *)a2 + 13) >> 1) & 1));
    result[2] = v50;
    v51 = v50 & 0xFFFFFFBF | (((*((unsigned __int16 *)a2 + 13) >> 2) & 1) << 6);
    result[2] = v51;
    v52 = v51 & 0xFFFFFDFF | (((*((unsigned __int16 *)a2 + 13) >> 3) & 1) << 9);
    result[2] = v52;
    v53 = v52 & 0xFFFFEFFF | (((*((unsigned __int16 *)a2 + 13) >> 4) & 1) << 12);
    result[2] = v53;
    v54 = v53 & 0xFFFF7FFF | (((*((unsigned __int16 *)a2 + 13) >> 5) & 1) << 15);
    result[2] = v54;
    v55 = v54 & 0xFFFBFFFF | (((*((unsigned __int16 *)a2 + 13) >> 6) & 1) << 18);
    result[2] = v55;
    v56 = v55 | (((*((unsigned __int16 *)a2 + 13) >> 7) & 1) << 21);
    result[2] = v56;
    v57 = v56 | ((HIBYTE(*((unsigned __int16 *)a2 + 13)) & 1) << 24);
    result[2] = v57;
    v48 = v57 | (((*((unsigned __int16 *)a2 + 13) >> 9) & 1) << 27);
    result[2] = v48;
    v47 = *a2;
    if ( (*a2 & 0x40000) == 0 )
      goto LABEL_23;
    goto LABEL_22;
  }
  v48 = 0;
  if ( (v47 & 0x40000) != 0 )
  {
LABEL_22:
    v58 = v48 | (2 * (*((_WORD *)a2 + 19) & 1));
    result[2] = v58;
    v59 = v58 | (8 * *((unsigned __int16 *)a2 + 19)) & 0x10;
    result[2] = v59;
    v60 = v59 | (32 * *((unsigned __int16 *)a2 + 19)) & 0x80;
    result[2] = v60;
    v61 = v60 | (*((unsigned __int16 *)a2 + 19) << 7) & 0x400;
    result[2] = v61;
    v62 = v61 | (*((unsigned __int16 *)a2 + 19) << 9) & 0x2000;
    result[2] = v62;
    v63 = v62 | (((*((unsigned __int16 *)a2 + 19) >> 5) & 1) << 16);
    result[2] = v63;
    v64 = v63 | (((*((unsigned __int16 *)a2 + 19) >> 6) & 1) << 19);
    result[2] = v64;
    v65 = v64 | (((*((unsigned __int16 *)a2 + 19) >> 7) & 1) << 22);
    result[2] = v65;
    v66 = v65 | ((HIBYTE(*((unsigned __int16 *)a2 + 19)) & 1) << 25);
    result[2] = v66;
    v48 = v66 | (((*((unsigned __int16 *)a2 + 19) >> 9) & 1) << 28);
    result[2] = v48;
    v47 = *a2;
  }
LABEL_23:
  if ( (v47 & 0x80000) != 0 )
  {
    v67 = v48 | (4 * (*((_WORD *)a2 + 14) & 1));
    result[2] = v67;
    v68 = v67 | (16 * *((unsigned __int16 *)a2 + 14)) & 0x20;
    result[2] = v68;
    v69 = v68 | (*((unsigned __int16 *)a2 + 14) << 6) & 0x100;
    result[2] = v69;
    v70 = v69 | (*((unsigned __int16 *)a2 + 14) << 8) & 0x800;
    result[2] = v70;
    v71 = v70 | (*((unsigned __int16 *)a2 + 14) << 10) & 0x4000;
    result[2] = v71;
    v72 = v71 | (((*((unsigned __int16 *)a2 + 14) >> 5) & 1) << 17);
    result[2] = v72;
    v73 = v72 | (((*((unsigned __int16 *)a2 + 14) >> 6) & 1) << 20);
    result[2] = v73;
    v74 = v73 | (((*((unsigned __int16 *)a2 + 14) >> 7) & 1) << 23);
    result[2] = v74;
    v75 = v74 | ((HIBYTE(*((unsigned __int16 *)a2 + 14)) & 1) << 26);
    result[2] = v75;
    result[2] = v75 | (((*((unsigned __int16 *)a2 + 14) >> 9) & 1) << 29);
  }
  result[3] = 0;
  v76 = *a2;
  if ( (*a2 & 0x20000) == 0 )
  {
    v77 = 0;
    if ( (v76 & 0x40000) == 0 )
      goto LABEL_30;
    goto LABEL_29;
  }
  v78 = *((unsigned __int16 *)a2 + 13);
  result[3] = (v78 >> 10) & 1;
  v79 = HIBYTE(*((unsigned __int16 *)a2 + 13)) & 8 | (v78 >> 10) & 1;
  result[3] = v79;
  v80 = (*((unsigned __int16 *)a2 + 13) >> 6) & 0x40 | v79;
  result[3] = v80;
  v81 = (*((unsigned __int16 *)a2 + 13) >> 4) & 0x200 | v80;
  result[3] = v81;
  v82 = (*((unsigned __int16 *)a2 + 13) >> 2) & 0x1000 | v81;
  result[3] = v82;
  v83 = v82 | *((_WORD *)a2 + 13) & 0x8000;
  result[3] = v83;
  v84 = v83 & 0xFFFBFFFF | (((*((unsigned __int16 *)a2 + 15) >> 14) & 1) << 18);
  result[3] = v84;
  v85 = v84 | (*((unsigned __int16 *)a2 + 15) << 6) & 0x200000;
  result[3] = v85;
  v77 = v85 | (((*((unsigned __int16 *)a2 + 15) >> 3) & 1) << 24);
  result[3] = v77;
  v76 = *a2;
  if ( (*a2 & 0x40000) != 0 )
  {
LABEL_29:
    v86 = v77 | (*((unsigned __int16 *)a2 + 19) >> 9) & 2;
    result[3] = v86;
    v87 = v86 | (*((unsigned __int16 *)a2 + 19) >> 7) & 0x10;
    result[3] = v87;
    v88 = v87 | (*((unsigned __int16 *)a2 + 19) >> 5) & 0x80;
    result[3] = v88;
    v89 = v88 | (*((unsigned __int16 *)a2 + 19) >> 3) & 0x400;
    result[3] = v89;
    v90 = v89 | (*((unsigned __int16 *)a2 + 19) >> 1) & 0x2000;
    result[3] = v90;
    v91 = (2 * *((unsigned __int16 *)a2 + 19)) & 0x10000 | v90;
    result[3] = v91;
    v92 = v91 | (((*((unsigned __int16 *)a2 + 17) >> 14) & 1) << 19);
    result[3] = v92;
    v93 = v92 | (*((unsigned __int16 *)a2 + 17) << 7) & 0x400000;
    result[3] = v93;
    v77 = v93 | (((*((unsigned __int16 *)a2 + 17) >> 3) & 1) << 25);
    result[3] = v77;
    v76 = *a2;
  }
LABEL_30:
  if ( (v76 & 0x80000) != 0 )
  {
    v94 = v77 | HIBYTE(*((unsigned __int16 *)a2 + 14)) & 4;
    result[3] = v94;
    v95 = v94 | (*((unsigned __int16 *)a2 + 14) >> 6) & 0x20;
    result[3] = v95;
    v96 = v95 | (*((unsigned __int16 *)a2 + 14) >> 4) & 0x100;
    result[3] = v96;
    v97 = v96 | (*((unsigned __int16 *)a2 + 14) >> 2) & 0x800;
    result[3] = v97;
    v98 = v97 | *((_WORD *)a2 + 14) & 0x4000;
    result[3] = v98;
    v99 = (4 * *((unsigned __int16 *)a2 + 14)) & 0x20000 | v98;
    result[3] = v99;
    v100 = v99 | (((*((unsigned __int16 *)a2 + 16) >> 14) & 1) << 20);
    result[3] = v100;
    v101 = v100 | (*((unsigned __int16 *)a2 + 16) << 8) & 0x800000;
    result[3] = v101;
    result[3] = v101 | (((*((unsigned __int16 *)a2 + 16) >> 3) & 1) << 26);
  }
  result[4] = 0;
  if ( (*((_BYTE *)a2 + 2) & 0x10) != 0 )
  {
    v102 = *((_WORD *)a2 + 21);
    result[4] = v102 & 1;
    v103 = *((_WORD *)a2 + 21) & 2 | v102 & 1;
    result[4] = v103;
    v104 = *((_WORD *)a2 + 21) & 4 | v103;
    result[4] = v104;
    v105 = *((_WORD *)a2 + 21) & 8 | v104;
    result[4] = v105;
    v106 = *((_WORD *)a2 + 21) & 0x10 | v105;
    result[4] = v106;
    v107 = *((_WORD *)a2 + 21) & 0x20 | v106;
    result[4] = v107;
    v108 = *((_WORD *)a2 + 21) & 0x40 | v107;
    result[4] = v108;
    v109 = *((_WORD *)a2 + 21) & 0x80 | (unsigned __int16)v108;
    result[4] = v109;
    v110 = *((_WORD *)a2 + 21) & 0x100 | v109;
    result[4] = v110;
    v111 = *((_WORD *)a2 + 21) & 0x200 | v110;
    result[4] = v111;
    v112 = *((_WORD *)a2 + 21) & 0x400 | v111;
    result[4] = v112;
    v113 = *((_WORD *)a2 + 21) & 0x800 | v112;
    result[4] = v113;
    v114 = *((_WORD *)a2 + 21) & 0x1000 | v113;
    result[4] = v114;
    v115 = *((_WORD *)a2 + 21) & 0x2000 | (unsigned __int16)v114;
    result[4] = v115;
    v116 = *((_WORD *)a2 + 21) & 0x4000 | v115;
    result[4] = v116;
    v117 = *((_WORD *)a2 + 21) & 0x8000 | v116;
    result[4] = v117;
    v118 = v117 & 0xFFFEFFFF | ((*((_WORD *)a2 + 22) & 1) << 16);
    result[4] = v118;
    v119 = v118 & 0xFFFDFFFF | (((*((unsigned __int16 *)a2 + 22) >> 1) & 1) << 17);
    result[4] = v119;
    v120 = v119 & 0xFFFBFFFF | (((*((unsigned __int16 *)a2 + 22) >> 2) & 1) << 18);
    result[4] = v120;
    v121 = v120 | (((*((unsigned __int16 *)a2 + 22) >> 3) & 1) << 19);
    result[4] = v121;
    v122 = v121 | (((*((unsigned __int16 *)a2 + 22) >> 4) & 1) << 20);
    result[4] = v122;
    v123 = v122 | (((*((unsigned __int16 *)a2 + 22) >> 5) & 1) << 21);
    result[4] = v123;
    v124 = v123 | (((*((unsigned __int16 *)a2 + 22) >> 6) & 1) << 22);
    result[4] = v124;
    v125 = v124 | (((*((unsigned __int16 *)a2 + 22) >> 7) & 1) << 23);
    result[4] = v125;
    v126 = v125 | ((HIBYTE(*((unsigned __int16 *)a2 + 22)) & 1) << 24);
    result[4] = v126;
    v127 = v126 | (((*((unsigned __int16 *)a2 + 22) >> 9) & 1) << 25);
    result[4] = v127;
    v128 = v127 | (((*((unsigned __int16 *)a2 + 22) >> 10) & 1) << 26);
    result[4] = v128;
    v129 = v128 | (((*((unsigned __int16 *)a2 + 22) >> 11) & 1) << 27);
    result[4] = v129;
    v130 = v129 | (((*((unsigned __int16 *)a2 + 22) >> 12) & 1) << 28);
    result[4] = v130;
    v131 = v130 | (((*((unsigned __int16 *)a2 + 22) >> 13) & 1) << 29);
    result[4] = v131;
    v132 = v131 | (((*((unsigned __int16 *)a2 + 22) >> 14) & 1) << 30);
    result[4] = v132;
    result[4] = v132 | (*((unsigned __int16 *)a2 + 22) >> 15 << 31);
    result[5] = 0;
    v133 = *((unsigned __int16 *)a2 + 20);
    result[5] = (v133 >> 14) & 1;
    v134 = (*((unsigned __int16 *)a2 + 20) >> 14) & 2 | (v133 >> 14) & 1;
    result[5] = v134;
    result[5] = (*((unsigned __int16 *)a2 + 20) >> 1) & 4 | v134;
  }
  else
  {
    result[5] = 0;
  }
  return result;
}
