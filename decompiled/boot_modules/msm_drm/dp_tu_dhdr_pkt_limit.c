__int64 __fastcall dp_tu_dhdr_pkt_limit(unsigned int *a1)
{
  unsigned __int64 v2; // x17
  unsigned __int64 v3; // x10
  int v4; // w8
  unsigned __int64 v5; // x10
  __int64 v6; // x13
  bool v7; // cf
  unsigned int v8; // w11
  int v9; // w9
  _BOOL8 v10; // x0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x11
  unsigned __int64 v13; // x11
  __int64 v14; // x13
  unsigned int v15; // w10
  int v16; // w11
  signed __int64 v17; // x9
  unsigned __int64 v18; // x13
  __int64 v19; // x10
  unsigned __int64 v20; // x13
  __int64 v21; // x15
  unsigned __int64 v22; // x12
  __int64 v23; // x10
  signed int v24; // w13
  __int64 v25; // x16
  unsigned __int64 v26; // x8
  char v27; // w15
  __int64 v28; // x14
  char v29; // w16
  bool v30; // cc
  __int64 v31; // x12
  __int64 v32; // x12
  char v33; // w14
  unsigned __int64 v34; // x14
  signed __int64 v35; // x11
  unsigned __int64 v36; // x12
  __int64 v37; // x1
  __int64 v38; // x17
  char v39; // w2
  __int64 v40; // x0
  __int64 v41; // x2
  char v42; // w4
  __int64 v43; // x1
  bool v44; // cc
  __int64 v45; // x0
  __int64 v46; // x0
  char v47; // w2
  __int64 v48; // x0
  unsigned __int64 v49; // x2
  bool v50; // zf
  unsigned __int64 v51; // x0
  int v52; // w21
  char v53; // w2
  __int64 v54; // x0
  __int64 v55; // x1
  char v56; // w4
  __int64 v57; // x2
  bool v58; // cc
  __int64 v59; // x0
  __int64 v60; // x0
  char v61; // w1
  __int64 v62; // x0
  unsigned __int64 v63; // x1
  bool v64; // zf
  unsigned __int64 v65; // x0
  char v66; // w3
  __int64 v67; // x1
  __int64 v68; // x3
  char v69; // w5
  __int64 v70; // x2
  __int64 v71; // x1
  __int64 v72; // x17
  char v73; // w1
  __int64 v74; // x17
  unsigned __int64 v75; // x1
  bool v76; // zf
  unsigned __int64 v77; // x17
  int v78; // w1
  int v79; // w22
  char v80; // w0
  __int64 v81; // x17
  signed __int64 v82; // x16
  unsigned __int64 v83; // x1
  unsigned __int64 v84; // x1
  __int64 v85; // x17
  __int64 v86; // x1
  unsigned __int64 v87; // x0
  __int64 v88; // x2
  unsigned int v89; // w2
  unsigned int v90; // w1
  __int64 v91; // x0
  __int64 v92; // x13
  int v93; // w23
  __int64 v94; // x0
  __int64 v95; // x15
  unsigned __int64 v96; // x14
  __int64 v97; // x13
  char v98; // w2
  __int64 v99; // x15
  signed __int64 v100; // x14
  __int64 v101; // x14
  char v102; // w16
  __int64 v103; // x15
  unsigned __int64 v104; // x14
  __int64 v105; // x16
  __int64 v106; // x0
  unsigned int v107; // w17
  unsigned int v108; // w16
  __int64 v109; // x13
  __int64 v110; // x15
  int v111; // w13
  char v112; // w17
  unsigned __int64 v113; // x1
  bool v114; // cc
  signed __int64 v115; // x14
  __int64 v116; // x14
  char v117; // w15
  int v118; // w14
  int v119; // w25
  __int64 v120; // x13
  __int64 v121; // x12
  char v122; // w15
  __int64 v123; // x10
  __int64 v124; // x9
  char v125; // w10
  __int64 v126; // x9
  __int64 v127; // x10
  unsigned int v128; // w12
  unsigned int v129; // w10
  __int64 v130; // x9
  __int64 v131; // x10
  __int64 v132; // x11
  unsigned int v133; // w11
  unsigned int v134; // w10
  __int64 v135; // x8
  unsigned __int64 v136; // x27
  unsigned int v137; // w24
  unsigned int v138; // w26
  __int64 ipc_log_context; // x0
  unsigned int v140; // w3
  unsigned int v141; // w4
  unsigned int v142; // w5
  unsigned int v143; // w6
  unsigned __int64 StatusReg; // x28
  __int64 v145; // x0
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x0
  const char *v149; // x19
  __int64 v150; // x0
  unsigned int v151; // w19
  __int64 v152; // x0
  int v154; // [xsp+28h] [xbp-8h]

  v2 = *a1 / 0xF4240uLL;
  v3 = *a1 % 0xF4240;
  v4 = -32;
  do
  {
    v5 = 2 * v3;
    if ( v5 <= 0xF423F )
      v6 = 0;
    else
      v6 = -1000000;
    v7 = __CFADD__(v4++, 1);
    v2 = (v5 > 0xF423F) | (2 * v2);
    v3 = v6 + v5;
  }
  while ( !v7 );
  v8 = a1[1];
  v9 = -32;
  v10 = 2 * v3 > 0xF423F;
  v11 = v8 / 0x3E8uLL;
  v12 = v8 % 0x3E8;
  do
  {
    v13 = 2 * v12;
    if ( v13 <= 0x3E7 )
      v14 = 0;
    else
      v14 = -1000;
    v7 = __CFADD__(v9++, 1);
    v11 = (v13 > 0x3E7) | (2 * v11);
    v12 = v14 + v13;
  }
  while ( !v7 );
  v15 = a1[2];
  v30 = 2 * v12 > 0x3E7;
  v16 = -32;
  v17 = v15 / 0x3E8uLL;
  v18 = v15 % 0x3E8;
  v19 = v30;
  do
  {
    v20 = 2 * v18;
    if ( v20 <= 0x3E7 )
      v21 = 0;
    else
      v21 = -1000;
    v7 = __CFADD__(v16++, 1);
    v17 = (v20 > 0x3E7) | (unsigned __int64)(2 * v17);
    v18 = v21 + v20;
  }
  while ( !v7 );
  v22 = *((_QWORD *)a1 + 3);
  v23 = v11 + v19;
  v30 = 2 * v18 > 0x3E7;
  v24 = a1[4];
  if ( v30 )
    ++v17;
  if ( (*((_BYTE *)a1 + 33) & 1) == 0 )
  {
    v26 = 0x100000000LL;
    if ( (a1[8] & 1) == 0 )
    {
      v27 = 0;
      v25 = 0x100000000LL;
      goto LABEL_36;
    }
LABEL_27:
    v28 = 62;
    do
    {
      if ( ((v22 >> v28) & 1) != v22 >> 63 )
        break;
      --v28;
    }
    while ( v28 );
    v29 = v28 - 30;
    v30 = (unsigned int)(62 - v28) > 0x20;
    v31 = v22 << (62 - (unsigned __int8)v28);
    if ( (unsigned int)(62 - v28) >= 0x20 )
      v29 = 0;
    v32 = v31 / (__int64)(0x4000000000uLL >> v29);
    v33 = 30 - v28;
    v27 = 1;
    if ( !v30 )
      v33 = 0;
    v25 = v32 >> v33;
    goto LABEL_36;
  }
  v25 = 0x100000000LL;
  v26 = 4194240001LL;
  if ( (a1[8] & 1) != 0 )
    goto LABEL_27;
  v26 = 0x100000000LL;
  v27 = 0;
LABEL_36:
  v34 = (__int64)v24 << 32;
  v35 = (unsigned __int64)a1[3] << 32;
  v36 = (unsigned __int64)v23 >> 63;
  v37 = 0;
  v38 = v2 + v10;
  while ( (((unsigned __int64)v23 >> ((unsigned __int8)v37 + 62)) & 1) == v36 )
  {
    if ( --v37 == -62 )
      goto LABEL_43;
  }
  if ( (unsigned int)(v37 + 35) >= 0xFFFFFFC2 )
  {
LABEL_43:
    v39 = 0;
    v40 = (unsigned __int64)(unsigned int)(5 * v23) << 33;
LABEL_44:
    v40 >>= 32 - v39;
    goto LABEL_45;
  }
  v39 = v37 + 36;
  v40 = (0xA00000000uLL >> (((unsigned int)(v37 + 36) >> 1) + ((v37 + 62) & 1)))
      * (v23 >> ((unsigned int)(v37 + 36) >> 1));
  if ( (unsigned int)(v37 + 36) >= 0x21 )
  {
    v40 <<= (unsigned __int8)v37 + 4;
    goto LABEL_45;
  }
  if ( (_DWORD)v37 != -4 )
    goto LABEL_44;
LABEL_45:
  v41 = 62;
  do
  {
    if ( (((unsigned __int64)v40 >> v41) & 1) != (unsigned __int64)v40 >> 63 )
      break;
    --v41;
  }
  while ( v41 );
  v42 = v41 - 30;
  v43 = 0;
  v44 = (unsigned int)(62 - v41) > 0x20;
  v45 = v40 << (62 - (unsigned __int8)v41);
  if ( (unsigned int)(62 - v41) >= 0x20 )
    v42 = 0;
  v46 = v45 / (v38 >> v42);
  v47 = 30 - v41;
  if ( !v44 )
    v47 = 0;
  v48 = v46 >> v47;
  v49 = 0xFFFFFFFF00000001LL;
  v50 = v48 == 0;
  if ( v48 >= 0 )
    v49 = 0xFFFFFFFFLL;
  v51 = (v49 + v48) >> 32;
  if ( v50 )
    v52 = 0;
  else
    v52 = v51;
  while ( (((unsigned __int64)v23 >> ((unsigned __int8)v43 + 62)) & 1) == v36 )
  {
    if ( --v43 == -62 )
      goto LABEL_63;
  }
  if ( (unsigned int)(v43 + 33) >= 0xFFFFFFC2 )
  {
LABEL_63:
    v54 = v23 << 33;
    v53 = 0;
LABEL_64:
    v54 >>= 32 - v53;
    goto LABEL_65;
  }
  v53 = v43 + 34;
  v54 = (0x200000000uLL >> (((unsigned int)(v43 + 34) >> 1) + ((v43 + 62) & 1)))
      * (v23 >> ((unsigned int)(v43 + 34) >> 1));
  if ( (unsigned int)(v43 + 34) >= 0x21 )
  {
    v54 <<= (unsigned __int8)v43 + 2;
    goto LABEL_65;
  }
  if ( (_DWORD)v43 != -2 )
    goto LABEL_64;
LABEL_65:
  v55 = 62;
  do
  {
    if ( (((unsigned __int64)v54 >> v55) & 1) != (unsigned __int64)v54 >> 63 )
      break;
    --v55;
  }
  while ( v55 );
  v56 = v55 - 30;
  v57 = 0;
  v58 = (unsigned int)(62 - v55) > 0x20;
  v59 = v54 << (62 - (unsigned __int8)v55);
  if ( (unsigned int)(62 - v55) >= 0x20 )
    v56 = 0;
  v60 = v59 / (v38 >> v56);
  v61 = 30 - v55;
  if ( !v58 )
    v61 = 0;
  v62 = v60 >> v61;
  v63 = 0xFFFFFFFF00000001LL;
  v64 = v62 == 0;
  if ( v62 >= 0 )
    v63 = 0xFFFFFFFFLL;
  v65 = (v63 + v62) >> 32;
  if ( v64 )
    LODWORD(v65) = 0;
  while ( (((unsigned __int64)v23 >> ((unsigned __int8)v57 + 62)) & 1) == v36 )
  {
    if ( --v57 == -62 )
      goto LABEL_82;
  }
  if ( (unsigned int)(v57 + 32) >= 0xFFFFFFC2 )
  {
LABEL_82:
    v67 = v23 << 32;
    v66 = 0;
LABEL_83:
    v67 >>= 32 - v66;
    goto LABEL_84;
  }
  v66 = v57 + 33;
  v67 = (0x100000000uLL >> (((unsigned int)(v57 + 33) >> 1) + ((v57 + 33) & 1)))
      * (v23 >> ((unsigned int)(v57 + 33) >> 1));
  if ( (unsigned int)v57 < 0xFFFFFFDF )
  {
    v67 <<= (unsigned __int8)v57 + 1;
    goto LABEL_84;
  }
  if ( (_DWORD)v57 != -1 )
    goto LABEL_83;
LABEL_84:
  v68 = 62;
  do
  {
    if ( (((unsigned __int64)v67 >> v68) & 1) != (unsigned __int64)v67 >> 63 )
      break;
    --v68;
  }
  while ( v68 );
  v69 = v68 - 30;
  v70 = 0;
  v71 = v67 << (62 - (unsigned __int8)v68);
  if ( (unsigned int)(62 - v68) >= 0x20 )
    v69 = 0;
  v72 = v71 / (v38 >> v69);
  v73 = 30 - v68;
  if ( (unsigned int)(62 - v68) <= 0x20 )
    v73 = 0;
  v74 = v72 >> v73;
  v75 = 0xFFFFFFFF00000001LL;
  v76 = v74 == 0;
  if ( v74 >= 0 )
    v75 = 0xFFFFFFFFLL;
  v77 = (v75 + v74) >> 32;
  if ( v76 )
    v78 = 0;
  else
    v78 = v77;
  v79 = v78 + v65;
  while ( (((unsigned __int64)v25 >> ((unsigned __int8)v70 + 62)) & 1) == (unsigned __int64)v25 >> 63 )
  {
    if ( --v70 == -62 )
      goto LABEL_103;
  }
  if ( (unsigned int)(v70 + 38) >= 0xFFFFFFC2 )
  {
LABEL_103:
    v81 = v25 << 38;
    v80 = 0;
LABEL_104:
    v81 >>= 32 - v80;
    goto LABEL_105;
  }
  v80 = v70 + 39;
  v81 = (v25 >> (((unsigned int)(v70 + 39) >> 1) + ((v70 + 39) & 1)))
      * (0x4000000000uLL >> ((unsigned int)(v70 + 39) >> 1));
  if ( (unsigned int)(v70 + 39) >= 0x21 )
  {
    v81 <<= (unsigned __int8)v70 + 7;
    goto LABEL_105;
  }
  if ( (_DWORD)v70 != -7 )
    goto LABEL_104;
LABEL_105:
  if ( HIDWORD(v81) )
    v82 = v81 & 0xFFFFFFFF00000000LL;
  else
    v82 = 0x4000000000000000LL
        / (((0x4000000000000000LL / ((unsigned __int64)v81 >> 2) + 0xFFFFFFFF) >> 2) & 0x1FFFFFFFC0000000LL);
  v83 = 0xFFFFFFFF00000001LL;
  if ( v81 >= 0 )
    v83 = 0xFFFFFFFFLL;
  v84 = 0x4000000000LL - ((v83 + v81) & 0xFFFFFFFF00000000LL);
  if ( v81 )
    v85 = v84;
  else
    v85 = 0x4000000000LL;
  v86 = 62;
  v87 = ((0x4000000000000000LL / (v82 >> 3)) & 0xFFFFFFFF00000000LL) + 0x100000000LL;
  do
  {
    if ( ((v87 >> v86) & 1) != v87 >> 63 )
      break;
    --v86;
  }
  while ( v86 );
  v88 = 62;
  do
  {
    if ( (((unsigned __int64)v85 >> v88) & 1) != (unsigned __int64)v85 >> 63 )
      break;
    --v88;
  }
  while ( v88 );
  v89 = v88 + v86;
  v90 = v89 - 61;
  if ( v89 <= 0x3D )
  {
    v91 = v87 * v85;
    LOBYTE(v90) = 0;
LABEL_123:
    v91 >>= 32 - (unsigned __int8)v90;
    goto LABEL_124;
  }
  v91 = ((__int64)v87 >> ((v90 >> 1) + (v90 & 1))) * (v85 >> (v90 >> 1));
  if ( v90 >= 0x21 )
  {
    v91 <<= (unsigned __int8)v89 - 93;
    goto LABEL_124;
  }
  if ( v89 != 93 )
    goto LABEL_123;
LABEL_124:
  v92 = (__int64)v24 << 25;
  v93 = HIDWORD(v91) + 2;
  if ( (v27 & 1) != 0 )
  {
    v94 = 62;
    v95 = 0x7000000000000000LL / v92;
    v96 = 0x7000000000000000LL / v92 + 0x100000000LL;
    do
    {
      if ( ((v96 >> v94) & 1) != v96 >> 63 )
        break;
      --v94;
    }
    while ( v94 );
    v97 = 62;
    v98 = v94 - 30;
    v99 = v85 + v95;
    v100 = v96 << (62 - (unsigned __int8)v94);
    if ( (unsigned int)(62 - v94) >= 0x20 )
      v98 = 0;
    v101 = v100 / (v82 >> v98);
    v102 = 30 - v94;
    if ( (unsigned int)(62 - v94) <= 0x20 )
      v102 = 0;
    v103 = v99 + 0x100000000LL;
    v104 = ((v101 >> v102) & 0xFFFFFFFF00000000LL) + 0x100000000LL;
    do
    {
      if ( ((v104 >> v97) & 1) != v104 >> 63 )
        break;
      --v97;
    }
    while ( v97 );
    v105 = 62;
    do
    {
      v106 = ((unsigned __int64)v103 >> v105) & 1;
      if ( v106 != (unsigned __int64)v103 >> 63 )
        break;
      --v105;
    }
    while ( v105 );
    v107 = v105 + v97;
    v108 = v105 + v97 - 61;
    if ( v107 <= 0x3D )
    {
      v109 = v104 * v103;
      LOBYTE(v108) = 0;
    }
    else
    {
      v106 = (v108 >> 1) + (v108 & 1);
      v109 = ((__int64)v104 >> ((v108 >> 1) + (v108 & 1))) * (v103 >> (v108 >> 1));
      if ( v108 >= 0x21 )
      {
        v109 <<= (unsigned __int8)v107 - 93;
LABEL_153:
        v113 = HIDWORD(v109);
        v118 = 0;
        goto LABEL_154;
      }
      if ( v108 == 32 )
        goto LABEL_153;
    }
    v109 >>= 32 - (unsigned __int8)v108;
    goto LABEL_153;
  }
  v110 = 62;
  v111 = ((unsigned __int64)(0x6400000000000000LL / v92) >> 32) + 1;
  do
  {
    if ( ((v34 >> v110) & 1) != v34 >> 63 )
      break;
    --v110;
  }
  while ( v110 );
  v112 = v110 - 30;
  v106 = 0x200000000LL;
  LODWORD(v113) = 0;
  v114 = (unsigned int)(62 - v110) > 0x20;
  v115 = v34 << (62 - (unsigned __int8)v110);
  if ( (unsigned int)(62 - v110) >= 0x20 )
    v112 = 0;
  v116 = v115 / (__int64)(0x200000000uLL >> v112);
  v117 = 30 - v110;
  if ( !v114 )
    v117 = 0;
  v118 = v111 + ((unsigned __int64)(v116 >> v117) >> 32);
LABEL_154:
  v119 = v118;
  v120 = 62;
  do
  {
    if ( (((unsigned __int64)v23 >> v120) & 1) != v36 )
      break;
    --v120;
  }
  while ( v120 );
  v121 = 62;
  v122 = v120 - 30;
  v123 = v23 << (62 - (unsigned __int8)v120);
  if ( (unsigned int)(62 - v120) >= 0x20 )
    v122 = 0;
  v124 = v123 / (v17 >> v122);
  v125 = 30 - v120;
  if ( (unsigned int)(62 - v120) <= 0x20 )
    v125 = 0;
  v126 = v124 >> v125;
  do
  {
    if ( (((unsigned __int64)v35 >> v121) & 1) != (unsigned __int64)a1[3] >> 31 )
      break;
    --v121;
  }
  while ( v121 );
  v127 = 62;
  do
  {
    if ( (((unsigned __int64)v126 >> v127) & 1) != (unsigned __int64)v126 >> 63 )
      break;
    --v127;
  }
  while ( v127 );
  v128 = v127 + v121;
  v129 = v128 - 61;
  if ( v128 <= 0x3D )
  {
    v130 = v126 * v35;
    LOBYTE(v129) = 0;
LABEL_171:
    v130 >>= 32 - (unsigned __int8)v129;
    goto LABEL_172;
  }
  v130 = (v35 >> ((v129 >> 1) + (v129 & 1))) * (v126 >> (v129 >> 1));
  if ( v129 < 0x21 )
  {
    if ( v128 == 93 )
      goto LABEL_172;
    goto LABEL_171;
  }
  v130 <<= (unsigned __int8)v128 - 93;
LABEL_172:
  v131 = 62;
  do
  {
    if ( ((v26 >> v131) & 1) != 0 )
      break;
    --v131;
  }
  while ( v131 );
  v132 = 62;
  v154 = v113;
  do
  {
    if ( (((unsigned __int64)v130 >> v132) & 1) != (unsigned __int64)v130 >> 63 )
      break;
    --v132;
  }
  while ( v132 );
  v133 = v132 + v131;
  v134 = v133 - 61;
  if ( v133 <= 0x3D )
  {
    v135 = v130 * v26;
    LOBYTE(v134) = 0;
LABEL_182:
    v135 >>= 32 - (unsigned __int8)v134;
    goto LABEL_183;
  }
  v135 = (v26 >> ((v134 >> 1) + (v134 & 1))) * (v130 >> (v134 >> 1));
  if ( v134 >= 0x21 )
  {
    v135 <<= (unsigned __int8)v133 - 93;
    goto LABEL_183;
  }
  if ( v133 != 93 )
    goto LABEL_182;
LABEL_183:
  v136 = HIDWORD(v135);
  v137 = v52 + v79 + v93 + v113 + v118 + 19;
  v138 = HIDWORD(v135) / v137;
  ipc_log_context = get_ipc_log_context(v106);
  v140 = *a1;
  v141 = a1[1];
  v142 = a1[2];
  v143 = a1[3];
  StatusReg = _ReadStatusReg(SP_EL0);
  v145 = ipc_log_string(
           ipc_log_context,
           "[d][%-4d]input: %d, %d, %d, %d, %d, 0x%llx, %d, %d\n",
           *(_DWORD *)(StatusReg + 1800),
           v140,
           v141,
           v142,
           v143,
           a1[4],
           *((_QWORD *)a1 + 3),
           *((unsigned __int8 *)a1 + 32),
           *((unsigned __int8 *)a1 + 33));
  if ( (_drm_debug & 4) != 0 )
    v145 = _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dp-debug][%-4d]input: %d, %d, %d, %d, %d, 0x%llx, %d, %d\n",
             *(_DWORD *)(StatusReg + 1800),
             *a1,
             a1[1],
             a1[2],
             a1[3],
             a1[4],
             *((_QWORD *)a1 + 3),
             *((unsigned __int8 *)a1 + 32),
             *((unsigned __int8 *)a1 + 33));
  v146 = get_ipc_log_context(v145);
  v147 = ipc_log_string(
           v146,
           "[d][%-4d]factors: %d, %d, %d, %d, %d\n",
           *(_DWORD *)(StatusReg + 1800),
           v52,
           v79,
           v93,
           v119,
           v154);
  if ( (_drm_debug & 4) != 0 )
    v147 = _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dp-debug][%-4d]factors: %d, %d, %d, %d, %d\n",
             *(_DWORD *)(StatusReg + 1800),
             v52,
             v79,
             v93,
             v119,
             v154);
  v148 = get_ipc_log_context(v147);
  if ( v138 <= 0x40 )
    v149 = (const char *)&unk_229BD3;
  else
    v149 = " CAPPED";
  v150 = ipc_log_string(
           v148,
           "[d][%-4d]d_p: %d, t_p: %d, maxPkts: %d%s\n",
           *(_DWORD *)(StatusReg + 1800),
           v137,
           v136,
           v138,
           v149);
  if ( (_drm_debug & 4) != 0 )
    v150 = _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dp-debug][%-4d]d_p: %d, t_p: %d, maxPkts: %d%s\n",
             *(_DWORD *)(StatusReg + 1800),
             v137,
             v136,
             v138,
             v149);
  if ( v138 >= 0x40 )
    v151 = 64;
  else
    v151 = v138;
  v152 = get_ipc_log_context(v150);
  ipc_log_string(v152, "[d][%-4d]packet limit per line = %d\n", *(_DWORD *)(StatusReg + 1800), v151);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]packet limit per line = %d\n", *(_DWORD *)(StatusReg + 1800), v151);
  return v151;
}
