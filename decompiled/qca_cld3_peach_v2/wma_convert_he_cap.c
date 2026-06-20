__int64 __fastcall wma_convert_he_cap(
        __int64 a1,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        _WORD *a7)
{
  unsigned int num_of_setbits_from_bitmask; // w26
  unsigned int v15; // w0
  char v16; // w22
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x8
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x8
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x9
  __int64 v57; // x8
  unsigned __int64 v58; // x8
  unsigned __int64 v59; // x8
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x8
  unsigned __int64 v63; // x8
  unsigned __int64 v64; // x8
  unsigned __int64 v65; // x8
  unsigned __int64 v66; // x8
  unsigned __int64 v67; // x8
  unsigned __int64 v68; // x8
  unsigned __int64 v69; // x8
  unsigned __int64 v70; // x8
  unsigned __int64 v71; // x8
  unsigned __int64 v72; // x8
  unsigned __int64 v73; // x8
  unsigned __int64 v74; // x8
  unsigned __int64 v75; // x8
  unsigned __int64 v76; // x8
  unsigned __int64 v77; // x8
  unsigned __int64 v78; // x8
  unsigned __int64 v79; // x8
  unsigned __int64 v80; // x8
  unsigned __int64 v81; // x8
  unsigned __int64 v82; // x8
  unsigned __int64 v83; // x8
  unsigned __int64 v84; // x8
  unsigned __int64 v85; // x8
  unsigned __int64 v86; // x8
  unsigned __int64 v87; // x8
  unsigned __int64 v88; // x8
  unsigned __int64 v89; // x8
  unsigned __int64 v90; // x8
  unsigned __int64 v91; // x8
  unsigned __int64 v92; // x8
  unsigned __int64 v93; // x8
  unsigned __int64 v94; // x8
  unsigned __int64 v95; // x8
  unsigned __int64 v96; // x8
  unsigned __int64 v97; // x8
  unsigned __int64 v98; // x8
  unsigned __int64 v99; // x8
  unsigned __int64 v100; // x8
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 result; // x0
  __int64 v110; // x8
  __int16 v111; // w9

  num_of_setbits_from_bitmask = wma_get_num_of_setbits_from_bitmask(a5);
  if ( num_of_setbits_from_bitmask <= (unsigned int)wma_get_num_of_setbits_from_bitmask(a6) )
    v15 = a6;
  else
    v15 = a5;
  v16 = wma_get_num_of_setbits_from_bitmask(v15);
  *(_BYTE *)a1 = 1;
  v17 = *(_QWORD *)(a1 + 1) & 0xFFFFFFFFFFFFFFFELL | *a2 & 1;
  *(_QWORD *)(a1 + 1) = v17;
  v18 = v17 & 0xFFFFFFFFFFFFFFFDLL | (2 * (((unsigned __int64)*a2 >> 1) & 1));
  *(_QWORD *)(a1 + 1) = v18;
  v19 = v18 & 0xFFFFFFFFFFFFFFFBLL | (4 * (((unsigned __int64)*a2 >> 2) & 1));
  *(_QWORD *)(a1 + 1) = v19;
  v20 = v19 & 0xFFFFFFFFFFFFFFE7LL | (8 * (((unsigned __int64)*a2 >> 3) & 3));
  *(_QWORD *)(a1 + 1) = v20;
  v21 = v20 & 0xFFFFFFFFFFFFFF1FLL | (32 * (((unsigned __int64)*a2 >> 5) & 7));
  *(_QWORD *)(a1 + 1) = v21;
  v22 = v21 & 0xFFFFFFFFFFFFFCFFLL | ((((unsigned __int64)*a2 >> 8) & 3) << 8);
  *(_QWORD *)(a1 + 1) = v22;
  v23 = v22 & 0xFFFFFFFFFFFFF3FFLL | ((((unsigned __int64)*a2 >> 10) & 3) << 10);
  *(_QWORD *)(a1 + 1) = v23;
  v24 = v23 & 0xFFFFFFFFFFFF8FFFLL | ((unsigned __int64)*a2 >> 11) & 0x1000;
  *(_QWORD *)(a1 + 1) = v24;
  v25 = v24 & 0xFFFFFFFFFFFE1FFFLL | *a2 & 0x18000;
  *(_QWORD *)(a1 + 1) = v25;
  v26 = v25 & 0xFFFFFFFFFFFD9FFFLL | *a2 & 0x20000;
  *(_QWORD *)(a1 + 1) = v26;
  v27 = v26 & 0xFFFFFFFFFFFB9FFFLL | *a2 & 0x40000;
  *(_QWORD *)(a1 + 1) = v27;
  v28 = v27 & 0xFFFFFFFFFFF79FFFLL | *a2 & 0x80000;
  *(_QWORD *)(a1 + 1) = v28;
  v29 = v28 & 0xFFFFFFFFFFEF9FFFLL | *a2 & 0x100000;
  *(_QWORD *)(a1 + 1) = v29;
  v30 = v29 & 0xFFFFFFFFFFDF9FFFLL | *a2 & 0x200000;
  *(_QWORD *)(a1 + 1) = v30;
  v31 = v30 & 0xFFFFFFFFFFBF9FFFLL | *a2 & 0x400000;
  *(_QWORD *)(a1 + 1) = v31;
  v32 = v31 & 0xFFFFFFFFFF7FFFFFLL | *a2 & 0x800000;
  *(_QWORD *)(a1 + 1) = v32;
  v33 = v32 & 0xFFFFFFFFFDFFFFFFLL | *a2 & 0x2000000;
  *(_QWORD *)(a1 + 1) = v33;
  v34 = v33 & 0xFFFFFFFFFBFFFFFFLL | *a2 & 0x4000000;
  *(_QWORD *)(a1 + 1) = v34;
  v35 = v34 & 0xFFFFFFFFE7FFFFFFLL | *a2 & 0x18000000;
  *(_QWORD *)(a1 + 1) = v35;
  v36 = v35 & 0xFFFFFFFFDFFFFFFFLL | *a2 & 0x20000000;
  *(_QWORD *)(a1 + 1) = v36;
  v37 = v36 & 0xFFFFFFFFBFFFFFFFLL | *a2 & 0x40000000;
  *(_QWORD *)(a1 + 1) = v37;
  v38 = v37 & 0xFFFFFFFF7FFFFFFFLL | *a2 & 0x80000000;
  *(_QWORD *)(a1 + 1) = v38;
  v39 = v38 & 0xFFFFFFFEFFFFFFFFLL | ((unsigned __int64)(a2[1] & 1) << 32);
  *(_QWORD *)(a1 + 1) = v39;
  v40 = v39 & 0xFFFFFFFDFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 1) & 1) << 33);
  *(_QWORD *)(a1 + 1) = v40;
  v41 = v40 & 0xFFFFFFFBFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 2) & 1) << 34);
  *(_QWORD *)(a1 + 1) = v41;
  v42 = v41 & 0xFFFFFFF7FFFFFFFFLL | ((unsigned __int64)((a2[1] >> 3) & 1) << 35);
  *(_QWORD *)(a1 + 1) = v42;
  v43 = v42 & 0xFFFFFFEFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 4) & 1) << 36);
  *(_QWORD *)(a1 + 1) = v43;
  v44 = v43 & 0xFFFFFFDFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 5) & 1) << 37);
  *(_QWORD *)(a1 + 1) = v44;
  v45 = v44 & 0xFFFFFFBFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 6) & 1) << 38);
  *(_QWORD *)(a1 + 1) = v45;
  v46 = v45 & 0xFFFFF8FFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 7) & 7) << 40);
  *(_QWORD *)(a1 + 1) = v46;
  v47 = v46 & 0xFFFFF7FFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 10) & 1) << 43);
  *(_QWORD *)(a1 + 1) = v47;
  v48 = v47 & 0xFFFFEFFFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 11) & 1) << 44);
  *(_QWORD *)(a1 + 1) = v48;
  v49 = v48 & 0xFFFFDFFFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 12) & 1) << 45);
  *(_QWORD *)(a1 + 1) = v49;
  v50 = v49 & 0xFFFFBFFFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 13) & 1) << 46);
  *(_QWORD *)(a1 + 1) = v50;
  v51 = v50 & 0xFFFF7FFFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 14) & 1) << 47);
  *(_QWORD *)(a1 + 1) = v51;
  *(_QWORD *)(a1 + 1) = v51 & 0xFFFEFFFFFFFFFFFFLL | ((unsigned __int64)((a2[1] >> 15) & 1) << 48);
  *a7 = *((_WORD *)a2 + 3);
  v52 = ((unsigned __int64)((*a3 >> 5) & 1) << 54)
      | ((unsigned __int64)((*a3 >> 6) & 1) << 55)
      | ((unsigned __int64)((*a3 >> 7) & 1) << 56)
      | *(_QWORD *)(a1 + 1) & 0xFE03FFFFFFFFFFFFLL
      | ((unsigned __int64)((*a3 >> 1) & 1) << 50)
      | ((unsigned __int64)((*a3 >> 2) & 1) << 51)
      | ((unsigned __int64)((*a3 >> 3) & 1) << 52)
      | ((unsigned __int64)((*a3 >> 4) & 1) << 53);
  *(_QWORD *)(a1 + 1) = v52;
  v53 = v52 & 0xE1FFFFFFFFFFFFFFLL | ((unsigned __int64)(BYTE1(*a3) & 0xF) << 57);
  *(_QWORD *)(a1 + 1) = v53;
  v54 = v53 & 0xDFFFFFFFFFFFFFFFLL | ((unsigned __int64)((*a3 & 0x1000) != 0) << 61);
  *(_QWORD *)(a1 + 1) = v54;
  v55 = v54 & 0xBFFFFFFFFFFFFFFFLL | ((unsigned __int64)((*a3 & 0x2000) != 0) << 62);
  *(_QWORD *)(a1 + 1) = v55;
  v56 = ((unsigned __int64)*a3 << 49) & 0x8000000000000000LL | v55 & 0x7FFFFFFFFFFFFFFFLL;
  v57 = *(_QWORD *)(a1 + 9);
  *(_QWORD *)(a1 + 1) = v56;
  v58 = v57 & 0xFFFFFFFFFFFFFFFCLL | ((unsigned __int64)*a3 >> 15) & 3;
  *(_QWORD *)(a1 + 9) = v58;
  v59 = v58 & 0xFFFFFFFFFFFFFFFBLL | (4 * (((unsigned __int64)*a3 >> 17) & 1));
  *(_QWORD *)(a1 + 9) = v59;
  v60 = v59 & 0xFFFFFFFFFFFFFFEFLL | (16 * (((unsigned __int64)*a3 >> 19) & 1));
  *(_QWORD *)(a1 + 9) = v60;
  v61 = v60 & 0xFFFFFFFFFFFFFFF7LL | (8 * (((unsigned __int64)*a3 >> 18) & 1));
  *(_QWORD *)(a1 + 9) = v61;
  v62 = v61 & 0xFFFBFFFFFFFFFFFFLL | ((((unsigned __int64)a3[1] >> 31) & 1) << 50);
  *(_QWORD *)(a1 + 9) = v62;
  v63 = v62 & 0xFFFDFFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x40000000) != 0) << 49);
  *(_QWORD *)(a1 + 9) = v63;
  v64 = v63 & 0xFFFFFFFFFFFFFF9FLL | (32 * (((unsigned __int64)*a3 >> 20) & 3));
  *(_QWORD *)(a1 + 9) = v64;
  v65 = v64 & 0xFFFFFFFFFFFFFE7FLL | ((((unsigned __int64)*a3 >> 22) & 3) << 7);
  *(_QWORD *)(a1 + 9) = v65;
  v66 = v65 & 0xFFFFFFFFFFFFF1FFLL | ((((unsigned __int64)*a3 >> 24) & 7) << 9);
  *(_QWORD *)(a1 + 9) = v66;
  v67 = v66 & 0xFFFFFFFFFFFF8FFFLL | ((((unsigned __int64)*a3 >> 27) & 7) << 12);
  *(_QWORD *)(a1 + 9) = v67;
  v68 = v67 & 0xFFFFFFFFFFFF7FFFLL | ((((unsigned __int64)*a3 >> 30) & 1) << 15);
  *(_QWORD *)(a1 + 9) = v68;
  v69 = v68 & 0xFFFFFFFFFFFEFFFFLL | ((((unsigned __int64)*a3 >> 31) & 1) << 16);
  *(_QWORD *)(a1 + 9) = v69;
  v70 = v69 & 0xFFFFFFFFFFFDFFFFLL | ((unsigned __int64)(a3[1] & 1) << 17);
  *(_QWORD *)(a1 + 9) = v70;
  v71 = v70 & 0xFFFFFFFFFFFBFFFFLL | ((((unsigned __int64)a3[1] >> 1) & 1) << 18);
  *(_QWORD *)(a1 + 9) = v71;
  v72 = v71 & 0xFFFFFFFFFFC7FFFFLL | ((((unsigned __int64)a3[1] >> 2) & 7) << 19);
  *(_QWORD *)(a1 + 9) = v72;
  v73 = v72 & 0xFFFFFFFFF8FFFFFFLL | ((((unsigned __int64)a3[1] >> 5) & 7) << 24);
  *(_QWORD *)(a1 + 9) = v73;
  v74 = v73 & 0xFFFFFFFFC7FFFFFFLL | ((((unsigned __int64)a3[1] >> 8) & 7) << 27);
  *(_QWORD *)(a1 + 9) = v74;
  v75 = v74 & 0xFFFFFFFE3FFFFFFFLL | ((((unsigned __int64)a3[1] >> 11) & 7) << 30);
  *(_QWORD *)(a1 + 9) = v75;
  v76 = v75 & 0xFFFFFFFDFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x4000) != 0) << 33);
  *(_QWORD *)(a1 + 9) = v76;
  v77 = v76 & 0xFFFFFFFBFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x8000) != 0) << 34);
  *(_QWORD *)(a1 + 9) = v77;
  v78 = v77 & 0xFFFFFFF7FFFFFFFFLL | ((unsigned __int64)(HIWORD(a3[1]) & 1) << 35);
  *(_QWORD *)(a1 + 9) = v78;
  v79 = v78 & 0xFFFFFFEFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x20000) != 0) << 36);
  *(_QWORD *)(a1 + 9) = v79;
  v80 = v79 & 0xFFFFFF1FFFFFFFFFLL | ((unsigned __int64)((a3[1] >> 18) & 7) << 37);
  *(_QWORD *)(a1 + 9) = v80;
  v81 = v80 & 0xFFFFFEFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x200000) != 0) << 40);
  *(_QWORD *)(a1 + 9) = v81;
  v82 = v81 & 0xFFFFFDFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x400000) != 0) << 41);
  *(_QWORD *)(a1 + 9) = v82;
  v83 = v82 & 0xFFFFFBFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x800000) != 0) << 42);
  *(_QWORD *)(a1 + 9) = v83;
  v84 = v83 & 0xFFFFF7FFFFFFFFFFLL | ((unsigned __int64)(HIBYTE(a3[1]) & 1) << 43);
  *(_QWORD *)(a1 + 9) = v84;
  v85 = v84 & 0xFFFFEFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x2000000) != 0) << 44);
  *(_QWORD *)(a1 + 9) = v85;
  v86 = v85 & 0xFFFFDFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x4000000) != 0) << 45);
  *(_QWORD *)(a1 + 9) = v86;
  v87 = v86 & 0xFFFE3FFFFFFFFFFFLL | ((unsigned __int64)((a3[1] >> 27) & 7) << 46);
  *(_QWORD *)(a1 + 9) = v87;
  v88 = v87 & 0xFFFDFFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x40000000) != 0) << 49);
  *(_QWORD *)(a1 + 9) = v88;
  v89 = v88 & 0xFFFBFFFFFFFFFFFFLL | ((((unsigned __int64)a3[1] >> 31) & 1) << 50);
  *(_QWORD *)(a1 + 9) = v89;
  v90 = v89 & 0xFFF7FFFFFFFFFFFFLL | ((unsigned __int64)(a3[2] & 1) << 51);
  *(_QWORD *)(a1 + 9) = v90;
  v91 = v90 & 0xFFEFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[2] & 2) != 0) << 52);
  *(_QWORD *)(a1 + 9) = v91;
  v92 = v91 & 0xFFDFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[2] & 4) != 0) << 53);
  *(_QWORD *)(a1 + 9) = v92;
  v93 = v92 & 0xFFBFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[2] & 8) != 0) << 54);
  *(_QWORD *)(a1 + 9) = v93;
  v94 = v93 & 0xFF7FFFFFFFFFFFFFLL | ((unsigned __int64)((a3[2] & 0x10) != 0) << 55);
  *(_QWORD *)(a1 + 9) = v94;
  v95 = v94 & 0xFEFFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[2] & 0x20) != 0) << 56);
  *(_QWORD *)(a1 + 9) = v95;
  v96 = v95 & 0xF9FFFFFFFFFFFFFFLL | ((unsigned __int64)(((unsigned __int8)a3[2] >> 6) & 3) << 57);
  *(_QWORD *)(a1 + 9) = v96;
  v97 = v96 & 0xF7FFFFFFFFFFFFFFLL | ((unsigned __int64)(BYTE1(a3[2]) & 1) << 59);
  *(_QWORD *)(a1 + 9) = v97;
  v98 = v97 & 0xEFFFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[2] & 0x200) != 0) << 60);
  *(_QWORD *)(a1 + 9) = v98;
  v99 = v98 & 0xDFFFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[2] & 0x400) != 0) << 61);
  *(_QWORD *)(a1 + 9) = v99;
  v100 = v99 & 0xBFFFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[2] & 0x800) != 0) << 62);
  *(_QWORD *)(a1 + 9) = v100;
  *(_QWORD *)(a1 + 9) = ((unsigned __int64)a3[2] << 51) & 0x8000000000000000LL | v100 & 0x7FFFFFFFFFFFFFFFLL;
  *(_BYTE *)(a1 + 17) = *(_BYTE *)(a1 + 17) & 0xFE | ((a3[2] & 0x2000) != 0);
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: supported_mcs: 0x%08x",
             v101,
             v102,
             v103,
             v104,
             v105,
             v106,
             v107,
             v108,
             "wma_convert_he_cap",
             a4);
  v110 = -1LL << (2 * v16);
  v111 = v110 | a4;
  LODWORD(v110) = v110 | HIWORD(a4);
  *(_WORD *)(a1 + 20) = v111;
  *(_WORD *)(a1 + 22) = v111;
  *(_WORD *)(a1 + 26) = v110;
  *(_WORD *)(a1 + 24) = v110;
  *(_WORD *)(a1 + 28) = v110;
  *(_WORD *)(a1 + 30) = v110;
  return result;
}
