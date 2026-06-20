__int64 __fastcall feature_set_cmd_send_tlv(__int64 a1, int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 v14; // x8
  int v15; // w9
  _DWORD *v16; // x2
  int v17; // w10
  int v18; // w11
  int v19; // w10
  int v20; // w13
  int v21; // w10
  int v22; // w11
  unsigned int v23; // w15
  int v24; // w12
  int v25; // w10
  unsigned int v26; // w12
  unsigned int v27; // w14
  unsigned int v28; // w14
  unsigned int v29; // w14
  unsigned int v30; // w14
  unsigned int v31; // w14
  unsigned int v32; // w14
  unsigned int v33; // w14
  unsigned int v34; // w14
  unsigned int v35; // w15
  unsigned int v36; // w15
  unsigned int v37; // w16
  unsigned int v38; // w16
  unsigned int v39; // w16
  unsigned int v40; // w16
  unsigned int v41; // w16
  unsigned int v42; // w16
  bool v43; // cf
  unsigned int v44; // w16
  unsigned int v45; // w16
  int v46; // w16
  unsigned int v47; // w16
  unsigned int v48; // w16
  unsigned int v49; // w16
  unsigned int v50; // w16
  unsigned int v51; // w16
  int v52; // w17
  int v53; // w1
  int v54; // w16
  unsigned int v55; // w0
  int v56; // w1
  int v57; // w13
  unsigned int v58; // w13
  unsigned int v59; // w13
  unsigned int v60; // w13
  unsigned int v61; // w13
  unsigned int v62; // w13
  unsigned int v63; // w13
  unsigned int v64; // w13
  unsigned int v65; // w13
  unsigned int v66; // w13
  unsigned int v67; // w13
  unsigned int v68; // w13
  int v69; // w14
  unsigned int v70; // w12
  int v71; // w13
  int v72; // w12
  unsigned int v73; // w12
  unsigned int v74; // w12
  int v75; // w12
  unsigned int v76; // w12
  unsigned int v77; // w12
  unsigned int v78; // w12
  unsigned int v79; // w12
  unsigned int v80; // w12
  unsigned int v81; // w12
  unsigned int v82; // w12
  unsigned int v83; // w12
  unsigned int v84; // w12
  unsigned int v85; // w12
  unsigned int v86; // w12
  unsigned int v87; // w12
  unsigned int v88; // w12
  unsigned int v89; // w12
  unsigned int v90; // w12
  unsigned int v91; // w12
  unsigned int v92; // w12
  unsigned int v93; // w12
  unsigned int v94; // w12
  int v95; // w13
  int v96; // w14
  unsigned int v97; // w13
  unsigned int v98; // w13
  unsigned int v99; // w13
  unsigned int v100; // w13
  unsigned int v101; // w13
  unsigned int v102; // w13
  unsigned int v103; // w13
  unsigned int v104; // w13
  unsigned int v105; // w13
  unsigned int v106; // w13
  unsigned int v107; // w13
  unsigned int v108; // w13
  unsigned int v109; // w13
  unsigned int v110; // w12
  unsigned int v111; // w12
  char v112; // w13
  unsigned int v113; // w14
  int v114; // w15
  int v115; // w16
  int v116; // w9
  unsigned int v117; // w9
  int v118; // w10
  unsigned int v119; // w9
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int64 result; // x0
  unsigned int v129; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x20u, "feature_set_cmd_send_tlv", 0x2AE0u);
  if ( !v4 )
    return 2;
  v13 = v4;
  qdf_trace_msg(0x31u, 8u, "%s: Send feature set param", v5, v6, v7, v8, v9, v10, v11, v12, "feature_set_cmd_send_tlv");
  v14 = *(_QWORD *)(v13 + 224);
  v15 = 0;
  *(_QWORD *)v14 = 0x10001804560000LL;
  v16 = (_DWORD *)(v14 + 8);
  v18 = *a2;
  v17 = a2[1];
  if ( v17 == 1 )
    v19 = 16;
  else
    v19 = 32 * (v17 == 2);
  if ( (unsigned int)(*a2 - 1) >= 4 )
    v18 = 0;
  v20 = a2[8];
  v21 = v18 | v19;
  v22 = a2[19];
  v23 = v21 | *(_DWORD *)(v14 + 8) & 0xFFFFFF80;
  v24 = a2[12];
  v25 = a2[5];
  *v16 = v23 & 0xFFFFFF37;
  v26 = v24 - 1;
  v27 = v23 & 0xFFFFFE37 | (*((unsigned __int8 *)a2 + 8) << 7);
  *v16 = v27;
  v28 = v27 & 0xFFFFFDFF | (*((unsigned __int8 *)a2 + 9) << 8);
  *v16 = v28;
  v29 = v28 & 0xFFFFFBFF | (*((unsigned __int8 *)a2 + 10) << 9);
  *v16 = v29;
  v30 = v29 & 0xFFFFF7FF | (*((unsigned __int8 *)a2 + 11) << 10);
  *v16 = v30;
  v31 = v30 & 0xFFFFEFFF | (*((unsigned __int8 *)a2 + 12) << 11);
  *v16 = v31;
  v32 = v31 & 0xFFFFDFFF | (*((unsigned __int8 *)a2 + 13) << 12);
  *v16 = v32;
  v33 = v32 & 0xFFFFBFFF | (*((unsigned __int8 *)a2 + 14) << 13);
  *v16 = v33;
  v34 = v33 & 0xFFFF7FFF | (*((unsigned __int8 *)a2 + 15) << 14);
  *v16 = v34;
  v35 = v34 & 0xFFFEFFFF | (*((unsigned __int8 *)a2 + 16) << 15);
  *v16 = v35;
  v36 = v35 & 0xFFFCFFB7 | (*((unsigned __int8 *)a2 + 17) << 16);
  *v16 = v36;
  v37 = v36 & 0xFFFBFFFF | ((a2[6] & 1) << 17);
  *v16 = v37;
  v38 = v37 & 0xFFF3FFB7 | (((*((unsigned __int8 *)a2 + 24) >> 1) & 1) << 18);
  *v16 = v38;
  v39 = v38 & 0xFFE7FFB7 | (((*((unsigned __int8 *)a2 + 24) >> 2) & 1) << 19);
  *v16 = v39;
  v40 = v39 & 0xFFCFFFB7 | (((*((unsigned __int8 *)a2 + 24) >> 3) & 1) << 20);
  *v16 = v40;
  v41 = v40 & 0xFF9FFFB7 | (((*((unsigned __int8 *)a2 + 24) >> 4) & 1) << 21);
  *v16 = v41;
  v42 = v41 & 0xFF3FFFB7;
  if ( (unsigned int)(v20 - 1) >= 9 )
    v20 = 0;
  v43 = v26 >= 4;
  v44 = v42 & 0xFFBFFFFF | (((*((unsigned __int8 *)a2 + 24) >> 5) & 1) << 22);
  *v16 = v44;
  v45 = v44 & 0xFE7FFFFF | (((*((unsigned __int8 *)a2 + 24) >> 6) & 1) << 23) & 0xFEFFFFFF;
  *v16 = v45;
  v46 = (*((unsigned __int8 *)a2 + 24) << 17) & 0x1000000 | v45;
  *v16 = v46 & 0xFDFFFFFF;
  v47 = v46 & 0xF9FFFFFF | (*((unsigned __int8 *)a2 + 25) << 25);
  *v16 = v47;
  v48 = v47 & 0xF7FFFFFF | (*((unsigned __int8 *)a2 + 26) << 26);
  *v16 = v48;
  v49 = v48 & 0xEFFFFFFF | ((*((_BYTE *)a2 + 27) & 1) << 27);
  *v16 = v49;
  v50 = v49 & 0xDFFFFFFF | (((*((unsigned __int8 *)a2 + 27) >> 1) & 1) << 28);
  *v16 = v50;
  v51 = v50 & 0xBFFFFFFF | (((*((unsigned __int8 *)a2 + 27) >> 2) & 1) << 29);
  *v16 = v51;
  v52 = v51 & 0x7FFFFFFF | (((*((unsigned __int8 *)a2 + 27) >> 3) & 1) << 30);
  v53 = *(_DWORD *)(v14 + 12);
  v54 = *(_DWORD *)(v14 + 16);
  *v16 = v52;
  v55 = v53 & 0xFFFFFF00;
  v56 = *((unsigned __int8 *)a2 + 28);
  v57 = v55 | v20;
  *(_DWORD *)(v14 + 12) = v57 & 0xFFFFFE0F;
  *v16 = v52 | (v56 << 31);
  v58 = v57 & 0xFFFFFC0F | (*((unsigned __int8 *)a2 + 36) << 8);
  *(_DWORD *)(v14 + 12) = v58;
  v59 = v58 & 0xFFFFFBFF | (*((unsigned __int8 *)a2 + 37) << 9);
  *(_DWORD *)(v14 + 12) = v59;
  v60 = v59 & 0xFFFFF7FF | (*((unsigned __int8 *)a2 + 38) << 10);
  *(_DWORD *)(v14 + 12) = v60;
  v61 = v60 & 0xFFFFEFFF | (*((unsigned __int8 *)a2 + 39) << 11);
  *(_DWORD *)(v14 + 12) = v61;
  v62 = v61 & 0xFFFFDFFF | (*((unsigned __int8 *)a2 + 40) << 12);
  *(_DWORD *)(v14 + 12) = v62;
  v63 = v62 & 0xFFFFBFFF | (*((unsigned __int8 *)a2 + 41) << 13);
  *(_DWORD *)(v14 + 12) = v63;
  v64 = v63 & 0xFFFF7FFF | (*((unsigned __int8 *)a2 + 42) << 14);
  *(_DWORD *)(v14 + 12) = v64;
  v65 = v64 & 0xFFFE7F0F | (*((unsigned __int8 *)a2 + 43) << 15);
  *(_DWORD *)(v14 + 12) = v65;
  v66 = v65 & 0xFFFDFFFF | (*((unsigned __int8 *)a2 + 44) << 16);
  *(_DWORD *)(v14 + 12) = v66;
  v67 = v66 & 0xFFF9FF0F | (*((unsigned __int8 *)a2 + 45) << 17);
  *(_DWORD *)(v14 + 12) = v67;
  v68 = v67 & 0xFFF7FFFF | (*((unsigned __int8 *)a2 + 46) << 18);
  *(_DWORD *)(v14 + 12) = v68;
  v69 = (v26 << 20) + 0x100000;
  v70 = v68 & 0xF00FFFFF | (*((unsigned __int8 *)a2 + 47) << 19);
  if ( v43 )
    v71 = 0;
  else
    v71 = v69;
  v72 = v70 | v71;
  *(_DWORD *)(v14 + 12) = v72 & 0xE07FFFFF;
  v73 = v72 & 0xC07FFFFF | (*((unsigned __int8 *)a2 + 52) << 28);
  *(_DWORD *)(v14 + 12) = v73;
  v74 = v73 & 0xBFFFFFFF | (*((unsigned __int8 *)a2 + 53) << 29);
  *(_DWORD *)(v14 + 12) = v74;
  v75 = v74 & 0x7FFFFFFF | (*((unsigned __int8 *)a2 + 54) << 30);
  *(_DWORD *)(v14 + 12) = v75;
  *(_DWORD *)(v14 + 12) = v75 | (*((unsigned __int8 *)a2 + 55) << 31);
  *(_DWORD *)(v14 + 16) = v54 & 0xFFFFFFFE;
  v76 = v54 & 0xFFFFFFFC | *((unsigned __int8 *)a2 + 56);
  *(_DWORD *)(v14 + 16) = v76;
  v77 = v76 & 0xFFFFFFF9 | (2 * *((unsigned __int8 *)a2 + 57));
  *(_DWORD *)(v14 + 16) = v77;
  v78 = v77 & 0xFFFFFFF3 | (4 * *((unsigned __int8 *)a2 + 58));
  *(_DWORD *)(v14 + 16) = v78;
  v79 = v78 & 0xFFFFFFE7 | (8 * *((unsigned __int8 *)a2 + 59));
  *(_DWORD *)(v14 + 16) = v79;
  v80 = v79 & 0xFFFFFFCF | (16 * *((unsigned __int8 *)a2 + 60));
  *(_DWORD *)(v14 + 16) = v80;
  v81 = v80 & 0xFFFFFF9F | (32 * *((unsigned __int8 *)a2 + 61));
  *(_DWORD *)(v14 + 16) = v81;
  v82 = v81 & 0xFFFFFF3F | (*((unsigned __int8 *)a2 + 62) << 6);
  *(_DWORD *)(v14 + 16) = v82;
  v83 = v82 & 0xFFFFFE7F | (*((unsigned __int8 *)a2 + 63) << 7);
  *(_DWORD *)(v14 + 16) = v83;
  v84 = v83 & 0xFFFFFCFF | (*((unsigned __int8 *)a2 + 64) << 8);
  *(_DWORD *)(v14 + 16) = v84;
  v85 = v84 & 0xFFFFF9FF | (*((unsigned __int8 *)a2 + 65) << 9);
  *(_DWORD *)(v14 + 16) = v85;
  v86 = v85 & 0xFFFFF3FF | (*((unsigned __int8 *)a2 + 66) << 10);
  *(_DWORD *)(v14 + 16) = v86;
  v87 = v86 & 0xFFFFE7FF | (*((unsigned __int8 *)a2 + 67) << 11);
  *(_DWORD *)(v14 + 16) = v87;
  v88 = v87 & 0xFFFFCFFF | (*((unsigned __int8 *)a2 + 68) << 12);
  *(_DWORD *)(v14 + 16) = v88;
  v89 = v88 & 0xFFFF9FFF | (*((unsigned __int8 *)a2 + 69) << 13);
  *(_DWORD *)(v14 + 16) = v89;
  v90 = v89 & 0xFFFF3FFF | ((*((_BYTE *)a2 + 70) & 1) << 14);
  *(_DWORD *)(v14 + 16) = v90;
  v91 = v90 & 0xFFFE7FFF | (((*((unsigned __int8 *)a2 + 70) >> 1) & 1) << 15);
  *(_DWORD *)(v14 + 16) = v91;
  v92 = v91 & 0xFFFCFFFF | (((*((unsigned __int8 *)a2 + 70) >> 2) & 1) << 16);
  *(_DWORD *)(v14 + 16) = v92;
  v93 = v92 & 0xFFF9FFFF | (((*((unsigned __int8 *)a2 + 70) >> 3) & 1) << 17);
  *(_DWORD *)(v14 + 16) = v93;
  v94 = v93 & 0xFFFBFFFF | ((((unsigned int)a2[21] >> 4) & 1) << 18);
  v95 = *(_DWORD *)(v14 + 20);
  v96 = *(_DWORD *)(v14 + 24);
  *(_DWORD *)(v14 + 16) = v94;
  *(_DWORD *)(v14 + 20) = v95 & 0xFFFDFFFF;
  v97 = v95 & 0xFFF9FFFF | ((a2[21] & 1) << 17);
  *(_DWORD *)(v14 + 20) = v97;
  v98 = v97 & 0xFFF3FFFF | ((((unsigned int)a2[21] >> 1) & 1) << 18);
  *(_DWORD *)(v14 + 20) = v98;
  v99 = v98 & 0xFFE7FFFF | ((((unsigned int)a2[21] >> 2) & 1) << 19);
  *(_DWORD *)(v14 + 20) = v99;
  *(_DWORD *)(v14 + 20) = v99 & 0xFFEFFFFF | ((((unsigned int)a2[21] >> 3) & 1) << 20);
  *(_DWORD *)(v14 + 24) = v96 & 0xFFFFFFDF;
  v100 = a2[21] & 0x20 | v96 & 0xFFFFFF9F;
  *(_DWORD *)(v14 + 24) = v100;
  v101 = v100 & 0xFFFFFF3F | a2[21] & 0x40;
  *(_DWORD *)(v14 + 24) = v101;
  v102 = v101 & 0xFFFFFE7F | a2[21] & 0x80;
  *(_DWORD *)(v14 + 24) = v102;
  v103 = v102 & 0xFFFFFCFF | a2[21] & 0x100;
  *(_DWORD *)(v14 + 24) = v103;
  v104 = v103 & 0xFFFFF9FF | a2[21] & 0x200;
  *(_DWORD *)(v14 + 24) = v104;
  v105 = v104 & 0xF7FFFFFF | a2[21] & 0x400;
  *(_DWORD *)(v14 + 24) = v105;
  v106 = v105 & 0xE7FFFFFF | ((((unsigned int)a2[21] >> 11) & 1) << 27);
  *(_DWORD *)(v14 + 24) = v106;
  v107 = v106 & 0xCFFFFFFF | ((((unsigned int)a2[21] >> 12) & 1) << 28);
  *(_DWORD *)(v14 + 24) = v107;
  v108 = v107 & 0x9FFFFFFF | ((((unsigned int)a2[21] >> 13) & 1) << 29);
  *(_DWORD *)(v14 + 24) = v108;
  v109 = v108 & 0xBFFFFFFF | ((((unsigned int)a2[21] >> 14) & 1) << 30);
  *(_DWORD *)(v14 + 16) = v94 & 0xFFF7FFFF;
  *(_DWORD *)(v14 + 24) = v109;
  v110 = v94 & 0xFFE7FFFF | (*((unsigned __int8 *)a2 + 71) << 19);
  *(_DWORD *)(v14 + 16) = v110;
  v111 = v110 & 0xFFCFFFFF | (*((unsigned __int8 *)a2 + 72) << 20);
  *(_DWORD *)(v14 + 16) = v111;
  *(_DWORD *)(v14 + 16) = v111 | (*((unsigned __int8 *)a2 + 73) << 21);
  do
  {
    v112 = v15 + 86;
    v113 = (unsigned int)(v15 + 86) >> 5;
    v114 = v16[v113] & ~(1 << (v15 + 86));
    v16[v113] = v114;
    v115 = *((unsigned __int16 *)a2 + 37) >> v15++;
    v16[v113] = ((v115 & 1) << v112) | v114;
  }
  while ( v15 != 16 );
  if ( v22 == 2 )
    v116 = 128;
  else
    v116 = 64;
  v117 = v116 & 0xFFFFE3FF | ((v25 & 7) << 10);
  v118 = *(_DWORD *)(v14 + 24);
  v119 = v117 | *(_DWORD *)(v14 + 20) & 0xFFFE003F;
  *(_DWORD *)(v14 + 20) = v119;
  *(_DWORD *)(v14 + 20) = v119 | (*((unsigned __int8 *)a2 + 80) << 16);
  *(_DWORD *)(v14 + 24) = v118 & 0x7FFFFFFF;
  *(_DWORD *)(v14 + 24) = v118 & 0x7FFFFFFF | (*((unsigned __int8 *)a2 + 88) << 31);
  ((void (__fastcall *)(__int64, __int64))qdf_trace_hex_dump)(49, 8);
  qdf_mtrace(49, 100, 0x24Du, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v13,
             0x20u,
             0x404Du,
             "feature_set_cmd_send_tlv",
             0x2AFEu,
             v120,
             v121,
             v122,
             v123,
             v124,
             v125,
             v126,
             v127);
  if ( (_DWORD)result )
  {
    v129 = result;
    wmi_buf_free();
    return v129;
  }
  return result;
}
