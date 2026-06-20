__int64 __fastcall wma_populate_peer_eht_cap(__int64 result, __int64 a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int16 v4; // w8
  int v5; // w10
  _DWORD *v7; // x19
  int v8; // w9
  unsigned int v9; // w10
  unsigned int v10; // w9
  unsigned int v11; // w9
  unsigned int v12; // w9
  unsigned int v13; // w9
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w9
  unsigned int v19; // w9
  int v20; // w10
  __int16 v21; // w11
  int v22; // w9
  int v23; // w11
  unsigned int v24; // w9
  unsigned int v25; // w9
  unsigned int v26; // w9
  unsigned int v27; // w9
  unsigned int v28; // w9
  unsigned int v29; // w9
  unsigned int v30; // w9
  unsigned int v31; // w9
  int v32; // w9
  int v33; // w9
  int v34; // w9
  int v35; // w9
  int v36; // w9
  int v37; // w9
  int v38; // w9
  int v39; // w9
  int v40; // w9
  int v41; // w10
  unsigned __int64 v42; // x9
  unsigned int v43; // w10
  int v44; // w11
  int v45; // w10
  int v46; // w10
  unsigned int v47; // w10
  unsigned int v48; // w8
  int v49; // w21
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v59; // w8
  int v60; // w9
  int v61; // w8
  char v62; // w10
  unsigned int v63; // w9
  int v64; // w10
  unsigned int v65; // w8
  unsigned int v66; // w10
  int v67; // w9
  unsigned int v68; // w10
  int v69; // w8
  unsigned int v70; // w10
  int v71; // w9
  unsigned int v72; // w10
  int v73; // w8
  unsigned int v74; // w8
  unsigned int v75; // w10
  __int64 v76; // x9
  int v77; // w8
  int v78; // w9
  int v79; // w10
  unsigned int v80; // w9
  unsigned int v81; // w11
  unsigned int v82; // w10
  unsigned int v83; // w11
  int v84; // w9
  int v85; // w10
  int v86; // w9
  int v87; // w10
  unsigned int v88; // w9
  int v89; // w9
  unsigned int v90; // w8
  unsigned int v91; // w9
  unsigned __int64 v92; // x10
  int v93; // w8
  unsigned __int64 v94; // x10
  int v95; // w9
  int v96; // w8
  unsigned int v97; // w9
  unsigned int v98; // w8
  int v99; // w9
  int v100; // w8
  char v101; // w10
  unsigned int v102; // w9
  unsigned __int64 v103; // x10
  int v104; // w8
  unsigned __int64 v105; // x10
  int v106; // w9
  int v107; // w8
  int v108; // w9
  unsigned __int64 v109; // x10
  int v110; // w8
  unsigned __int64 v111; // x10
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
  unsigned int v128; // w8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  unsigned int v137; // w8
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  __int64 v146; // [xsp+0h] [xbp-40h]
  __int64 v147; // [xsp+18h] [xbp-28h]

  if ( *(_BYTE *)(a2 + 256) == 1 )
  {
    v147 = v3;
    v4 = *(_WORD *)(result + 352);
    v5 = *(_DWORD *)(result + 428);
    *(_BYTE *)(result + 362) = 1;
    v7 = (_DWORD *)result;
    *(_WORD *)(result + 352) = v4 | 4;
    v8 = *(unsigned __int8 *)(a2 + 353);
    *(_DWORD *)(result + 428) = v5 & 0xFFFFFFFE;
    *(_DWORD *)(result + 432) = v8;
    v9 = v5 & 0xFFFFFFFC | *(_DWORD *)(a2 + 261) & 1;
    *(_DWORD *)(result + 428) = v9;
    v10 = v9 & 0xFFFFFFF9 | *(_DWORD *)(a2 + 261) & 2;
    *(_DWORD *)(result + 428) = v10;
    v11 = v10 & 0xFFFFFFF3 | *(_DWORD *)(a2 + 261) & 4;
    *(_DWORD *)(result + 428) = v11;
    v12 = v11 & 0xFFFFFFE7 | *(_DWORD *)(a2 + 261) & 8;
    *(_DWORD *)(result + 428) = v12;
    v13 = v12 & 0xFFFFFFCF | *(_DWORD *)(a2 + 261) & 0x10;
    *(_DWORD *)(result + 428) = v13;
    v14 = v13 & 0xFFFFFF1F | *(_DWORD *)(a2 + 261) & 0x20;
    *(_DWORD *)(result + 428) = v14;
    v15 = v14 & 0xFFFFFE3F | *(_DWORD *)(a2 + 261) & 0xC0;
    *(_DWORD *)(result + 428) = v15;
    v16 = v15 & 0xFFFFFCFF | *(_DWORD *)(a2 + 261) & 0x100;
    *(_DWORD *)(result + 428) = v16;
    v17 = v16 & 0xFFFFF9FF | *(_DWORD *)(a2 + 261) & 0x200;
    *(_DWORD *)(result + 428) = v17;
    v18 = v17 & 0xFFFFF3FF | *(_DWORD *)(a2 + 261) & 0x400;
    *(_DWORD *)(result + 428) = v18;
    v19 = v18 & 0xFFFFC7FF | *(_DWORD *)(a2 + 261) & 0x800;
    v20 = *(_DWORD *)(result + 436);
    *(_DWORD *)(result + 428) = v19;
    v21 = *(_DWORD *)(a2 + 261);
    *(_DWORD *)(result + 436) = v20 & 0xFFFFFFFD;
    v22 = v21 & 0x3000 | v19;
    v23 = *(_DWORD *)(result + 440);
    *(_DWORD *)(result + 428) = v22;
    v24 = HIWORD(*(_DWORD *)(a2 + 261)) & 2 | v20 & 0xFFFFFFF9;
    *(_DWORD *)(result + 436) = v24;
    v25 = v24 & 0xFFFFFFF3 | HIWORD(*(_DWORD *)(a2 + 261)) & 4;
    *(_DWORD *)(result + 436) = v25;
    v26 = v25 & 0xFFFFFFE7 | HIWORD(*(_DWORD *)(a2 + 261)) & 8;
    *(_DWORD *)(result + 436) = v26;
    v27 = v26 & 0xFFFFFFCF | HIWORD(*(_DWORD *)(a2 + 261)) & 0x10;
    *(_DWORD *)(result + 436) = v27;
    v28 = v27 & 0xFFFFFF9F | HIWORD(*(_DWORD *)(a2 + 261)) & 0x20;
    *(_DWORD *)(result + 436) = v28;
    v29 = v28 & 0xFFFFFC3F | HIWORD(*(_DWORD *)(a2 + 261)) & 0x40;
    *(_DWORD *)(result + 436) = v29;
    v30 = v29 & 0xFFFFE07F | (*(_DWORD *)(a2 + 261) >> 17) & 0x380;
    *(_DWORD *)(result + 436) = v30;
    v31 = v30 & 0xFFFF03FF | (*(_DWORD *)(a2 + 261) >> 17) & 0x1C00;
    *(_DWORD *)(result + 436) = v31;
    v32 = v31 & 0xFFF81FFF | (*(_QWORD *)(a2 + 261) >> 17) & 0xE000;
    *(_DWORD *)(result + 436) = v32;
    v33 = v32 & 0xFFC0FFFF | (*(_QWORD *)(a2 + 261) >> 17) & 0x70000;
    *(_DWORD *)(result + 436) = v33;
    v34 = v33 & 0xFE07FFFF | (*(_QWORD *)(a2 + 261) >> 17) & 0x380000;
    *(_DWORD *)(result + 436) = v34;
    v35 = v34 & 0xFC3FFFFF | (*(_QWORD *)(a2 + 261) >> 17) & 0x1C00000;
    *(_DWORD *)(result + 436) = v35;
    v36 = v35 & 0xF9FFFFFF | (*(_QWORD *)(a2 + 261) >> 17) & 0x2000000;
    *(_DWORD *)(result + 436) = v36;
    v37 = v36 & 0xF3FFFFFF | (*(_QWORD *)(a2 + 261) >> 17) & 0x4000000;
    *(_DWORD *)(result + 436) = v37;
    v38 = v37 & 0xE7FFFFFF | (*(_QWORD *)(a2 + 261) >> 17) & 0x8000000;
    *(_DWORD *)(result + 436) = v38;
    v39 = v38 & 0xCFFFFFFF | (*(_QWORD *)(a2 + 261) >> 17) & 0x10000000;
    *(_DWORD *)(result + 436) = v39;
    v40 = v39 & 0x9FFFFFFF | (*(_QWORD *)(a2 + 261) >> 17) & 0x20000000;
    *(_DWORD *)(result + 436) = v40;
    v41 = (*(_QWORD *)(a2 + 261) >> 17) & 0x40000000 | v40 & 0x3FFFFFFF;
    *(_DWORD *)(result + 436) = v41;
    v42 = *(_QWORD *)(a2 + 261);
    *(_DWORD *)(result + 440) = v23 & 0xFFFFFFFE;
    LODWORD(v42) = (v42 >> 17) & 0x80000000 | v41;
    v43 = v23 & 0xFFFFFFFC;
    v44 = *(_DWORD *)(result + 444);
    *(_DWORD *)(result + 436) = v42;
    LODWORD(v42) = (*(_QWORD *)(a2 + 261) >> 49) & 1 | v43;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFFFFFF9 | (*(_QWORD *)(a2 + 261) >> 49) & 2;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFFFFFF3 | (*(_QWORD *)(a2 + 261) >> 49) & 4;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFFFFF07 | (*(_QWORD *)(a2 + 261) >> 49) & 8;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFFFFE0F | (*(_QWORD *)(a2 + 261) >> 52) & 0xF0;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFFFFCFF | (*(_QWORD *)(a2 + 261) >> 52) & 0x100;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFFFF9FF | (*(_QWORD *)(a2 + 261) >> 52) & 0x200;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFFFF3FF | (*(_QWORD *)(a2 + 261) >> 52) & 0x400;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFFFC7FF | (*(_QWORD *)(a2 + 261) >> 52) & 0x800;
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFFF80FFF | ((*(_DWORD *)(a2 + 269) & 3) << 12);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFF803FFF | (((*(_DWORD *)(a2 + 269) >> 2) & 0x1F) << 14);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFF07FFFF | (((*(_DWORD *)(a2 + 269) >> 7) & 0xF) << 19);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFE7FFFFF | (((*(_DWORD *)(a2 + 269) >> 11) & 1) << 23);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xFCFFFFFF | (((*(_DWORD *)(a2 + 269) >> 12) & 1) << 24);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xF9FFFFFF | (((*(_DWORD *)(a2 + 269) >> 13) & 1) << 25);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xF3FFFFFF | (((*(_DWORD *)(a2 + 269) >> 14) & 1) << 26);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xE7FFFFFF | (((*(_DWORD *)(a2 + 269) >> 15) & 1) << 27);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0xCFFFFFFF | ((HIWORD(*(_DWORD *)(a2 + 269)) & 1) << 28);
    *(_DWORD *)(result + 440) = v42;
    LODWORD(v42) = v42 & 0x9FFFFFFF | (((*(_DWORD *)(a2 + 269) >> 17) & 1) << 29);
    *(_DWORD *)(result + 440) = v42;
    v45 = (*(_DWORD *)(a2 + 269) << 12) & 0x40000000 | v42 & 0x3FFFFFFF;
    *(_DWORD *)(result + 440) = v45;
    v46 = v45 & 0x7FFFFFFF | ((unsigned __int8)(*(_DWORD *)(a2 + 269) >> 19) << 31);
    *(_DWORD *)(result + 444) = v44 & 0xFFFFFFFE;
    *(_DWORD *)(result + 440) = v46;
    v47 = v44 & 0xFFFFFFFC | (*(_DWORD *)(a2 + 269) >> 20) & 1;
    *(_DWORD *)(result + 444) = v47;
    LODWORD(v42) = v47 & 0xFFFFFFF9 | (*(_DWORD *)(a2 + 269) >> 20) & 2;
    *(_DWORD *)(result + 444) = v42;
    LODWORD(v42) = v42 & 0xFFFFFFF3 | (*(_DWORD *)(a2 + 269) >> 20) & 4;
    *(_DWORD *)(result + 444) = v42;
    LODWORD(v42) = v42 & 0xFFFFFFE7 | (*(_DWORD *)(a2 + 269) >> 20) & 8;
    *(_DWORD *)(result + 444) = v42;
    v48 = *(_DWORD *)(a2 + 269);
    *(_DWORD *)(result + 448) = 0;
    *(_DWORD *)(result + 444) = (v48 >> 20) & 0x10 | v42;
    v49 = *(_DWORD *)(a2 + 24);
    if ( (unsigned int)wlan_mlme_get_max_bw() > 2 && v49 == 2 )
      v59 = 3;
    else
      v59 = v49;
    if ( v59 > 2 )
    {
      if ( v59 == 7 )
      {
        v78 = v7[115];
        v77 = v7[112] + 1;
        v7[112] = v77;
        v7[115] = v78 & 0xFFFFFFF0;
        v79 = v7[119];
        v80 = v78 & 0xFFFFFFF0 | *(_WORD *)(a2 + 108) & 0xF;
        v7[119] = v79 & 0xFFFFFFF0;
        v7[115] = v80;
        v80 &= 0xFFFFFF0F;
        v81 = *(_DWORD *)(a2 + 106);
        v7[115] = v80;
        v82 = v79 & 0xFFFFFFF0 | (v81 >> 20) & 0xF;
        v7[119] = v82;
        v82 &= 0xFFFFFF0F;
        v83 = *(_DWORD *)(a2 + 106);
        v7[119] = v82;
        v84 = (v83 >> 12) & 0xF0 | v80;
        v7[115] = v84;
        v84 &= 0xFFFFF0FF;
        LOBYTE(v83) = *(_WORD *)(a2 + 108);
        v7[115] = v84;
        v85 = v83 & 0xF0 | v82;
        v7[119] = v85;
        v85 &= 0xFFFFF0FF;
        LOWORD(v83) = *(_WORD *)(a2 + 108);
        v7[119] = v85;
        v86 = v83 & 0xF00 | v84;
        v7[115] = v86;
        v87 = v85 | (*(_DWORD *)(a2 + 106) >> 28 << 8);
        v7[115] = v86 & 0xFFFF0FFF;
        v7[119] = v87;
        v88 = v86 & 0xFFFF0FFF | ((*(_BYTE *)(a2 + 110) & 0xF) << 12);
        v7[119] = v87 & 0xFFFF0FFF;
        v7[115] = v88;
        v7[119] = v87 & 0xFFFF0FFF | (((*(unsigned __int8 *)(a2 + 110) >> 4) & 0xF) << 12);
      }
      else
      {
        if ( v59 != 3 )
          goto LABEL_19;
        v77 = v7[112];
      }
      v89 = v7[114];
      v7[112] = v77 + 1;
      v7[114] = v89 & 0xFFFFFFF0;
      v90 = v7[118] & 0xFFFFFFF0;
      v91 = v89 & 0xFFFFFFF0 | *(_BYTE *)(a2 + 105) & 0xF;
      v7[118] = v90;
      v7[114] = v91;
      v91 &= 0xFFFFFF0F;
      v92 = *(_QWORD *)(a2 + 98);
      v7[114] = v91;
      v93 = v90 | (v92 >> 60);
      v7[118] = v93;
      v93 &= 0xFFFFFF0F;
      v94 = *(_QWORD *)(a2 + 98);
      v7[118] = v93;
      v95 = (v94 >> 52) & 0xF0 | v91;
      v7[114] = v95;
      LOBYTE(v94) = *(_BYTE *)(a2 + 105);
      v7[114] = v95 & 0xFFFFF0FF;
      v96 = v94 & 0xF0 | v93;
      v7[118] = v96;
      v97 = v95 & 0xFFFFF0FF | ((*(_DWORD *)(a2 + 106) & 0xF) << 8);
      v7[118] = v96 & 0xFFFFF0FF;
      v7[114] = v97;
      v98 = v96 & 0xFFFFF0FF | ((*(_DWORD *)(a2 + 106) & 0xF) << 8);
      v7[114] = v97 & 0xFFFF0FFF;
      v7[118] = v98;
      v98 &= 0xFFFF0FFF;
      LODWORD(v94) = *(_DWORD *)(a2 + 106);
      v7[118] = v98;
      v7[114] = v97 & 0xFFFF0FFF | ((((unsigned int)v94 >> 8) & 0xF) << 12);
      v7[118] = *(_DWORD *)(a2 + 106) & 0xF000 | v98;
    }
    else if ( (unsigned int)(v59 - 1) >= 2 )
    {
      if ( !v59 )
      {
        v60 = v7[113];
        ++v7[112];
        v61 = v7[117];
        v7[113] = v60 & 0xFFFFFFF0;
        v62 = *(_DWORD *)(a2 + 98);
        v7[117] = v61 & 0xFFFFFFF0;
        v63 = v60 & 0xFFFFFFF0 | v62 & 0xF;
        v7[113] = v63;
        v63 &= 0xFFFFFF0F;
        v64 = *(_DWORD *)(a2 + 98);
        v7[113] = v63;
        v65 = v61 & 0xFFFFFFF0 | ((unsigned __int8)v64 >> 4);
        v7[117] = v65;
        v65 &= 0xFFFFFF0F;
        v66 = *(_DWORD *)(a2 + 98);
        v7[117] = v65;
        v67 = (v66 >> 4) & 0xF0 | v63;
        v7[113] = v67;
        v67 &= 0xFFFFF0FF;
        v68 = *(_DWORD *)(a2 + 98);
        v7[113] = v67;
        v69 = (v68 >> 8) & 0xF0 | v65;
        v7[117] = v69;
        v69 &= 0xFFFFF0FF;
        v70 = *(_DWORD *)(a2 + 98);
        v7[117] = v69;
        v71 = (v70 >> 8) & 0xF00 | v67;
        v7[113] = v71;
        LODWORD(v76) = v71 & 0xFFFF0FFF;
        v72 = *(_DWORD *)(a2 + 98);
        v7[113] = v76;
        v73 = (v72 >> 12) & 0xF00 | v69;
        v7[117] = v73;
        v74 = v73 & 0xFFFF0FFF;
        v75 = *(_DWORD *)(a2 + 98);
        v7[117] = v74;
        v7[113] = (v75 >> 12) & 0xF000 | v76;
        LOWORD(v76) = *(_WORD *)(a2 + 100);
LABEL_18:
        v7[117] = v76 & 0xF000 | v74;
      }
LABEL_19:
      wma_print_eht_cap(a2 + 260, v50, v51, v52, v53, v54, v55, v56, v57);
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Peer EHT Capabilities:",
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        "wma_populate_peer_eht_cap");
      wma_print_eht_phy_cap(v7 + 109, v120, v121, v122, v123, v124, v125, v126, v127);
      v128 = v7[107];
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: EHT MAC Cap: EPCS Priority Access: 0x%01x OM Control: 0x%01x, Trig TXOP Sharing: mode1 0x%01x mode2 0x%01x, "
        "Restricted TWT 0x%01x SCS Traffic Desc 0x%01x",
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        "wma_print_eht_mac_cap",
        v128 & 1,
        (v128 >> 1) & 1,
        (v128 >> 2) & 1,
        (v128 >> 3) & 1,
        (v128 >> 4) & 1,
        (v128 >> 5) & 1,
        v2,
        v147);
      v137 = v7[107];
      LODWORD(v146) = (v137 >> 12) & 3;
      return qdf_trace_msg(
               0x36u,
               8u,
               " Max MPDU len 0x%01x, Max A-MPDU Len Exponent Ext 0x%01x EHT TRS 0x%01x, OP In TXOP Sharing Mode2 0x%01x,"
               " Two BQRs 0x%01x, EHT Link Adaptation 0x%01x",
               v138,
               v139,
               v140,
               v141,
               v142,
               v143,
               v144,
               v145,
               (unsigned __int8)v137 >> 6,
               (v137 >> 8) & 1,
               (v137 >> 9) & 1,
               (v137 >> 10) & 1,
               (v137 >> 11) & 1,
               v146);
    }
    v99 = v7[113];
    ++v7[112];
    v100 = v7[117];
    v7[113] = v99 & 0xFFFFFFF0;
    v101 = *(_DWORD *)(a2 + 102);
    v100 &= 0xFFFFFFF0;
    v7[117] = v100;
    v102 = v99 & 0xFFFFFFF0 | v101 & 0xF;
    v7[113] = v102;
    v102 &= 0xFFFFFF0F;
    v103 = *(_QWORD *)(a2 + 98);
    v7[113] = v102;
    v104 = (v103 >> 36) & 0xF | v100;
    v7[117] = v104;
    v104 &= 0xFFFFFF0F;
    v105 = *(_QWORD *)(a2 + 98);
    v7[117] = v104;
    v106 = (v105 >> 28) & 0xF0 | v102;
    v7[113] = v106;
    v106 &= 0xFFFFF0FF;
    LOBYTE(v105) = *(_DWORD *)(a2 + 102);
    v7[113] = v106;
    v107 = v105 & 0xF0 | v104;
    v7[117] = v107;
    v107 &= 0xFFFFF0FF;
    LOWORD(v105) = *(_DWORD *)(a2 + 102);
    v7[117] = v107;
    v108 = v105 & 0xF00 | v106;
    v7[113] = v108;
    v108 &= 0xFFFF0FFF;
    v109 = *(_QWORD *)(a2 + 98);
    v7[113] = v108;
    v110 = (v109 >> 36) & 0xF00 | v107;
    v7[117] = v110;
    v74 = v110 & 0xFFFF0FFF;
    v111 = *(_QWORD *)(a2 + 98);
    v7[117] = v74;
    v7[113] = (v111 >> 36) & 0xF000 | v108;
    v76 = *(_QWORD *)(a2 + 98) >> 36;
    goto LABEL_18;
  }
  return result;
}
