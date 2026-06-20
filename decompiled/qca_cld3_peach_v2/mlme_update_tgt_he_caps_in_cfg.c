__int64 __fastcall mlme_update_tgt_he_caps_in_cfg(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 psoc_ext_obj_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int64 *v14; // x22
  unsigned int v15; // w12
  int v16; // w23
  __int64 v17; // x20
  __int64 v18; // x10
  unsigned int v19; // w11
  unsigned int v20; // w9
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // x10
  unsigned int v23; // w8
  unsigned __int64 v24; // x10
  unsigned __int64 v25; // x10
  unsigned __int64 v26; // x10
  unsigned __int64 v27; // x10
  unsigned int v28; // w11
  unsigned __int64 v29; // x11
  unsigned __int64 v30; // x10
  unsigned __int64 v31; // x10
  unsigned __int64 v32; // x12
  unsigned int v33; // w13
  unsigned int v34; // w11
  unsigned __int64 v35; // x10
  unsigned __int64 v36; // x11
  unsigned __int64 v37; // x12
  unsigned int v38; // w10
  unsigned int v39; // w8
  unsigned __int64 v40; // x12
  unsigned __int64 v41; // x12
  unsigned __int64 v42; // x12
  unsigned __int64 v43; // x12
  unsigned __int64 v44; // x12
  unsigned __int64 v45; // x12
  __int64 v46; // x10
  unsigned __int64 v47; // x10
  unsigned int v48; // w9
  __int64 v49; // x8
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x8
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
  unsigned __int64 v72; // x9
  unsigned __int64 v73; // x8
  unsigned __int64 v74; // x8
  unsigned __int64 v75; // x8
  unsigned __int64 v76; // x8
  unsigned __int64 v77; // x8
  unsigned __int64 v78; // x8
  int v79; // w10
  unsigned __int64 v80; // x8
  unsigned __int64 v81; // x8
  unsigned __int64 v82; // x8
  unsigned __int64 v83; // x9
  __int64 v84; // x8
  unsigned __int64 v85; // x8
  unsigned __int64 v86; // x8
  unsigned __int64 v87; // x8
  unsigned __int64 v88; // x8
  __int64 result; // x0
  int v90; // w9
  unsigned __int64 v91; // x8
  unsigned __int64 v92; // x8
  int v93; // w10
  unsigned __int64 v94; // x8
  unsigned __int64 v95; // x8
  unsigned __int64 v96; // x8
  unsigned __int64 v97; // x8
  unsigned __int64 v98; // x8
  unsigned __int64 v99; // x8
  unsigned __int64 v100; // x8
  unsigned __int64 v101; // x8
  int v102; // w9
  unsigned __int64 v103; // x8
  unsigned __int64 v104; // x9
  unsigned __int64 v105; // x8
  unsigned __int64 v106; // x8
  unsigned __int64 v107; // x9
  _QWORD *v108; // x24
  unsigned __int64 v109; // x8
  unsigned __int16 v110; // w0
  unsigned __int64 v111; // x8
  unsigned __int64 v112; // x8
  unsigned __int64 v113; // x8
  unsigned __int64 v114; // x8
  unsigned __int64 v115; // x8
  unsigned __int64 v116; // x8
  unsigned __int64 v117; // x8
  unsigned __int64 v118; // x8
  unsigned __int64 v119; // x8
  unsigned __int64 v120; // x8
  unsigned __int64 v121; // x8
  unsigned __int64 v122; // x8
  unsigned __int64 v123; // x8
  unsigned __int64 v124; // x8
  unsigned __int64 v125; // x8
  unsigned __int64 v126; // x8
  unsigned __int64 v127; // x8
  unsigned __int64 v128; // x8
  unsigned __int64 v129; // x8
  unsigned __int64 v130; // x8
  unsigned __int64 v131; // x8
  unsigned __int64 v132; // x8
  unsigned __int64 v133; // x8
  __int16 min_he_mcs_map; // w22
  __int16 v135; // w0
  unsigned __int8 v136; // w8
  __int64 v137; // x23
  __int16 v138; // w8
  unsigned __int16 v139; // w0
  __int16 v140; // w21
  __int16 v141; // w0
  __int64 v142; // x9
  __int64 v143; // x8
  __int64 v144; // x9
  __int64 v145; // x9
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  __int64 v154; // [xsp+0h] [xbp-10h] BYREF
  __int64 v155; // [xsp+8h] [xbp-8h]

  v155 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  WORD2(v154) = 0;
  LOWORD(v154) = 0;
  if ( !psoc_ext_obj_fl )
  {
    result = 16;
    goto LABEL_49;
  }
  v14 = (unsigned __int64 *)(psoc_ext_obj_fl + 1309);
  v15 = *(unsigned __int8 *)(psoc_ext_obj_fl + 1484);
  *(_BYTE *)(psoc_ext_obj_fl + 1308) = 1;
  v16 = *(unsigned __int8 *)(psoc_ext_obj_fl + 2871);
  v17 = psoc_ext_obj_fl;
  v18 = *(_QWORD *)(psoc_ext_obj_fl + 1309);
  v19 = ((unsigned int)v18 >> 1) & 1;
  v20 = ((unsigned int)v18 >> 2) & 1;
  v21 = v18 & 0xFFFFFFFFFFFFFFFELL | *(_QWORD *)(a2 + 177) & 1LL;
  *(_QWORD *)(psoc_ext_obj_fl + 1309) = v21;
  v22 = v21 & 0xFFFFFFFFFFFFFFFDLL;
  if ( ((*(_DWORD *)(a2 + 177) >> 1) & 1u) >= v19 )
    v23 = v19;
  else
    v23 = 0;
  v24 = v22 | (2 * v23);
  *v14 = v24;
  v25 = v24 & 0xFFFFFFFFFFFFFFFBLL;
  if ( ((*(_DWORD *)(a2 + 177) >> 2) & 1u) < v20 )
    v20 = 0;
  v26 = v25 | (4 * v20);
  *v14 = v26;
  v27 = v26 & 0xFFFFFFFFFFFFFFE7LL;
  v28 = (*(_DWORD *)(a2 + 177) >> 3) & 3;
  if ( v28 >= v15 )
    v28 = v15;
  v29 = v27 | (8 * v28);
  *v14 = v29;
  v30 = v29 & 0xFFFFFFFFFFFFFF1FLL | (32 * ((*(_QWORD *)(a2 + 177) >> 5) & 7LL));
  *v14 = v30;
  v31 = v30 & 0xFFFFFFFFFFFFFCFFLL | (((*(_QWORD *)(a2 + 177) >> 8) & 3LL) << 8);
  *v14 = v31;
  v32 = *(_QWORD *)(a2 + 177);
  v33 = ((unsigned int)v32 >> 10) & 3;
  if ( v33 != 3 )
  {
    v34 = ((unsigned int)v29 >> 10) & 3;
    v35 = v31 & 0xFFFFFFFFFFFFF3FFLL;
    if ( v33 < v34 )
      v34 = ((unsigned int)v32 >> 10) & 3;
    v31 = v35 | (v34 << 10);
    *v14 = v31;
    v32 = *(_QWORD *)(a2 + 177);
  }
  v36 = v32 >> 12;
  v37 = v31;
  v38 = ((unsigned int)v31 >> 20) & 1;
  v39 = v20 | v23;
  v40 = v37 & 0xFFFFFFFFFFFF8FFFLL | ((v36 & 7) << 12);
  *v14 = v40;
  v41 = v40 & 0xFFFFF8FFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 40) & 7LL) << 40);
  *v14 = v41;
  v42 = v41 & 0xFFFFFFFFFFFE7FFFLL | (((*(_QWORD *)(a2 + 177) >> 15) & 3LL) << 15);
  *v14 = v42;
  v43 = v42 & 0xFFFFFFFFFFFDFFFFLL | (((*(_QWORD *)(a2 + 177) >> 17) & 1LL) << 17);
  *v14 = v43;
  v44 = v43 & 0xFFFFFFFFFFFBFFFFLL | (((*(_QWORD *)(a2 + 177) >> 18) & 1LL) << 18);
  *v14 = v44;
  v45 = v44 & 0xFFFFFFFFFFF7FFFFLL | (((*(_QWORD *)(a2 + 177) >> 19) & 1LL) << 19);
  *v14 = v45;
  if ( ((*(_DWORD *)(a2 + 177) >> 20) & 1u) >= v38 )
    v46 = v38 << 20;
  else
    v46 = 0;
  v47 = v45 & 0xFFFFFFFFFFEFFFFFLL | v46;
  *v14 = v47;
  v48 = ((unsigned int)v47 >> 30) & 1;
  if ( ((*(_DWORD *)(a2 + 177) >> 30) & 1u) < v39 )
    v39 = 0;
  if ( v39 >= v48 )
    v49 = v48 << 30;
  else
    v49 = 0;
  v50 = v47 & 0xFFFFFFFFBFFFFFFFLL | v49;
  *v14 = v50;
  v51 = v50 & 0xFFFFFFFFFFDFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 21) & 1LL) << 21);
  *v14 = v51;
  v52 = v51 & 0xFFFFFFFFFFBFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 22) & 1LL) << 22);
  *v14 = v52;
  v53 = v52 & 0xFFFFFFFFFF7FFFFFLL | (((*(_QWORD *)(a2 + 177) >> 23) & 1LL) << 23);
  *v14 = v53;
  v54 = v53 & 0xFFFFFFFFFDFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 25) & 1LL) << 25);
  *v14 = v54;
  v55 = v54 & 0xFFFFFFFFFBFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 26) & 1LL) << 26);
  *v14 = v55;
  v56 = v55 & 0xFFFFFFFFE7FFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 27) & 3LL) << 27);
  *v14 = v56;
  v57 = v56 & 0xFFFFFFFFDFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 29) & 1LL) << 29);
  *v14 = v57;
  v58 = v57 & 0xFFFFFFFF7FFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 31) & 1LL) << 31);
  *v14 = v58;
  v59 = v58 & 0xFFFFFFFEFFFFFFFFLL | ((HIDWORD(*(_QWORD *)(a2 + 177)) & 1LL) << 32);
  *v14 = v59;
  v60 = v59 & 0xFFFFFFFDFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 33) & 1LL) << 33);
  *v14 = v60;
  v61 = v60 & 0xFFFFFFFBFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 34) & 1LL) << 34);
  *v14 = v61;
  v62 = v61 & 0xFFFFFFF7FFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 35) & 1LL) << 35);
  *v14 = v62;
  v63 = v62 & 0xFFFFFFEFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 36) & 1LL) << 36);
  *v14 = v63;
  v64 = v63 & 0xFFFFFFDFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 37) & 1LL) << 37);
  *v14 = v64;
  v65 = v64 & 0xFFFFFFBFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 38) & 1LL) << 38);
  *v14 = v65;
  v66 = v65 & 0xFFFFF7FFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 43) & 1LL) << 43);
  *v14 = v66;
  v67 = v66 & 0xFFFFEFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 44) & 1LL) << 44);
  *v14 = v67;
  v68 = v67 & 0xFFFFDFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 45) & 1LL) << 45);
  *v14 = v68;
  v69 = v68 & 0xFFFFBFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 46) & 1LL) << 46);
  *v14 = v69;
  v70 = v69 & 0xFFFF7FFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 47) & 1LL) << 47);
  *v14 = v70;
  v71 = v70 & 0xFFFEFFFFFFFFFFFFLL | ((HIWORD(*(_QWORD *)(a2 + 177)) & 1LL) << 48);
  *v14 = v71;
  v72 = *(_QWORD *)(a2 + 177);
  if ( (v72 & 0x100000000000000LL) == 0 )
  {
    v73 = v71 & 0xFFFBFFFFFFFFFFFFLL | (((v72 >> 50) & 1) << 50);
    *v14 = v73;
    v74 = v73 & 0xFFF7FFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 51) & 1LL) << 51);
    *v14 = v74;
    v75 = v74 & 0xFFEFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 52) & 1LL) << 52);
    *v14 = v75;
    v76 = v75 & 0xFFDFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 53) & 1LL) << 53);
    *v14 = v76;
    v77 = v76 & 0xFFBFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 54) & 1LL) << 54);
    *v14 = v77;
    v78 = v77 & 0xFF7FFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 55) & 1LL) << 55);
    *v14 = v78;
    v71 = v78 & 0xFEFFFFFFFFFFFFFFLL | ((HIBYTE(*(_QWORD *)(a2 + 177)) & 1LL) << 56);
    *v14 = v71;
    v72 = *(_QWORD *)(a2 + 177);
  }
  v79 = *(unsigned __int8 *)(psoc_ext_obj_fl + 2825);
  v80 = v71 & 0xE1FFFFFFFFFFFFFFLL | (((v72 >> 57) & 0xF) << 57);
  *v14 = v80;
  v81 = v80 & 0xDFFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 61) & 1LL) << 61);
  *v14 = v81;
  v82 = v81 & 0xBFFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 177) >> 62) & 1LL) << 62);
  *v14 = v82;
  v83 = *(_QWORD *)(a2 + 177) & 0x8000000000000000LL | v82 & 0x7FFFFFFFFFFFFFFFLL;
  v84 = *(_QWORD *)(psoc_ext_obj_fl + 1317);
  *v14 = v83;
  v85 = v84 & 0xFFFFFFFFFFFFFFFCLL | *(_QWORD *)(a2 + 185) & 3LL;
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v85;
  v86 = v85 & 0xFFFFFFFFFFFFFFFBLL | (4 * ((*(_QWORD *)(a2 + 185) >> 2) & 1LL));
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v86;
  if ( v79 == 1 )
  {
    v87 = v86 & 0xFFFFFFFFFFFFFFEFLL | (16 * ((*(_QWORD *)(a2 + 185) >> 4) & 1LL));
    *(_QWORD *)(psoc_ext_obj_fl + 1317) = v87;
    v88 = v87 & 0xFFFBFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 50) & 1LL) << 50);
  }
  else
  {
    v88 = v86 & 0xFFFBFFFFFFFFFFEFLL;
  }
  v90 = *(unsigned __int8 *)(psoc_ext_obj_fl + 2824);
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v88;
  if ( v90 == 1 )
  {
    v91 = v88 & 0xFFFFFFFFFFFFFFF7LL | (8 * ((*(_QWORD *)(a2 + 185) >> 3) & 1LL));
    *(_QWORD *)(psoc_ext_obj_fl + 1317) = v91;
    v92 = v91 & 0xFFFDFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 49) & 1LL) << 49);
  }
  else
  {
    v92 = v88 & 0xFFFDFFFFFFFFFFF7LL;
  }
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v92;
  v93 = *(unsigned __int8 *)(psoc_ext_obj_fl + 2826);
  v94 = v92 & 0xFFFFFFFFFFFFFF9FLL | (32 * ((*(_QWORD *)(a2 + 185) >> 5) & 3LL));
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v94;
  v95 = v94 & 0xFFFFFFFFFFFFF1FFLL | (((*(_QWORD *)(a2 + 185) >> 9) & 7LL) << 9);
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v95;
  v96 = v95 & 0xFFFFFFFFFFFF8FFFLL | (((*(_QWORD *)(a2 + 185) >> 12) & 7LL) << 12);
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v96;
  v97 = v96 & 0xFFFFFFFFFFFF7FFFLL | (((*(_QWORD *)(a2 + 185) >> 15) & 1LL) << 15);
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v97;
  if ( v93 == 1 )
  {
    v98 = v97 & 0xFFFFFFFFFFFEFFFFLL | (((*(_QWORD *)(a2 + 185) >> 16) & 1LL) << 16);
    *(_QWORD *)(psoc_ext_obj_fl + 1317) = v98;
    v99 = v98 & 0xFFFFFFFFC7FFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 27) & 7LL) << 27);
    *(_QWORD *)(psoc_ext_obj_fl + 1317) = v99;
    v100 = v99 & 0xFFFFFFFE3FFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 30) & 7LL) << 30);
    *(_QWORD *)(psoc_ext_obj_fl + 1317) = v100;
    v101 = v100 & 0xFFFFFFFFFFFBFFFFLL | (((*(_QWORD *)(a2 + 185) >> 18) & 1LL) << 18);
  }
  else
  {
    v101 = v97 & 0xFFFFFFFE07FAFFFFLL;
  }
  v102 = *(unsigned __int8 *)(psoc_ext_obj_fl + 2827);
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v101;
  if ( v102 == 1 )
  {
    v103 = v101 & 0xFFFFFFFFFFFDFFFFLL | (((*(_QWORD *)(a2 + 185) >> 17) & 1LL) << 17);
    *(_QWORD *)(psoc_ext_obj_fl + 1317) = v103;
    v104 = *(_QWORD *)(a2 + 185);
    v105 = v103 & 0xFFFFFFFFFFC7FFFFLL | (((v104 >> 19) & 7) << 19);
    *(_QWORD *)(psoc_ext_obj_fl + 1317) = v105;
    v106 = v105 & 0xFFFFFFFFF8FFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 24) & 7LL) << 24);
    *(_QWORD *)(psoc_ext_obj_fl + 1317) = v106;
    if ( (v104 & 0x200000) != 0 && (*(_BYTE *)(a2 + 413) & 1) == 0 )
    {
      v106 = v106 & 0xFFFFFFFFFFC7FFFFLL | 0x180000;
      *(_QWORD *)(psoc_ext_obj_fl + 1317) = v106;
    }
    if ( (v106 & 0x4000000) == 0 || (*(_BYTE *)(a2 + 413) & 1) != 0 )
      goto LABEL_42;
    v106 = v106 & 0xFFFFFFFFF8FFFFFFLL | 0x3000000;
  }
  else
  {
    v106 = v101 & 0xFFFFFFFFF8C5FFFFLL;
  }
  *(_QWORD *)(psoc_ext_obj_fl + 1317) = v106;
LABEL_42:
  v107 = *(_QWORD *)(a2 + 185);
  v108 = (_QWORD *)(psoc_ext_obj_fl + 1308);
  if ( *(_BYTE *)(psoc_ext_obj_fl + 1485) )
  {
    v109 = v106 & 0xFFFFFFFFFFFFFE7FLL | (((v107 >> 7) & 3) << 7);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: UL MIMO feature is disabled via ini, fw caps :%d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "mlme_update_tgt_he_caps_in_cfg",
      ((unsigned int)v107 >> 7) & 3,
      v154,
      v155);
    v109 = v14[1] & 0xFFFFFFFFFFFFFE7FLL;
  }
  v14[1] = v109;
  v110 = *(_WORD *)(v17 + 1330);
  v111 = v109 & 0xFFFFFFFDFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 33) & 1LL) << 33);
  v14[1] = v111;
  v112 = v111 & 0xFFFFFFFBFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 34) & 1LL) << 34);
  v14[1] = v112;
  v113 = v112 & 0xFFFFFFF7FFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 35) & 1LL) << 35);
  v14[1] = v113;
  v114 = v113 & 0xFFFFFFEFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 36) & 1LL) << 36);
  v14[1] = v114;
  v115 = v114 & 0xFFFFFF1FFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 37) & 7LL) << 37);
  v14[1] = v115;
  v116 = v115 & 0xFFFFFEFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 40) & 1LL) << 40);
  v14[1] = v116;
  v117 = v116 & 0xFFFFFDFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 41) & 1LL) << 41);
  v14[1] = v117;
  v118 = v117 & 0xFFFFFBFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 42) & 1LL) << 42);
  v14[1] = v118;
  v119 = v118 & 0xFFFFF7FFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 43) & 1LL) << 43);
  v14[1] = v119;
  v120 = v119 & 0xFFFFEFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 44) & 1LL) << 44);
  v14[1] = v120;
  v121 = v120 & 0xFFFFDFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 45) & 1LL) << 45);
  v14[1] = v121;
  v122 = v121 & 0xFFFE3FFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 46) & 7LL) << 46);
  v14[1] = v122;
  v123 = v122 & 0xFFF7FFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 51) & 1LL) << 51);
  v14[1] = v123;
  v124 = v123 & 0xFFEFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 52) & 1LL) << 52);
  v14[1] = v124;
  v125 = v124 & 0xFFDFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 53) & 1LL) << 53);
  v14[1] = v125;
  v126 = v125 & 0xFFBFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 54) & 1LL) << 54);
  v14[1] = v126;
  v127 = v126 & 0xFF7FFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 55) & 1LL) << 55);
  v14[1] = v127;
  v128 = v127 & 0xFEFFFFFFFFFFFFFFLL | ((HIBYTE(*(_QWORD *)(a2 + 185)) & 1LL) << 56);
  v14[1] = v128;
  v129 = v128 & 0xF9FFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 57) & 3LL) << 57);
  v14[1] = v129;
  v130 = v129 & 0xF7FFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 59) & 1LL) << 59);
  v14[1] = v130;
  v131 = v130 & 0xDFFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 61) & 1LL) << 61);
  v14[1] = v131;
  v132 = v131 & 0xBFFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 62) & 1LL) << 62);
  v14[1] = v132;
  v133 = v132 & 0xEFFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a2 + 185) >> 60) & 1LL) << 60);
  v14[1] = v133;
  v14[1] = *(_QWORD *)(a2 + 185) & 0x8000000000000000LL | v133 & 0x7FFFFFFFFFFFFFFFLL;
  *(_BYTE *)(v17 + 1325) = *(_BYTE *)(v17 + 1325) & 0xFE | *(_BYTE *)(a2 + 193) & 1;
  min_he_mcs_map = wlan_mlme_get_min_he_mcs_map(v110, *(_WORD *)(a2 + 198));
  v135 = wlan_mlme_get_min_he_mcs_map(*(_WORD *)(v17 + 1328), *(_WORD *)(a2 + 196));
  if ( v16 + 1 < (unsigned int)a3 )
    v136 = v16 + 1;
  else
    v136 = a3;
  v137 = -1LL << (2 * v136);
  v138 = v135 | v137;
  v139 = *(_WORD *)(v17 + 1334);
  *(_WORD *)(v17 + 1328) = v138;
  *(_WORD *)(v17 + 1330) = min_he_mcs_map | v137;
  v140 = wlan_mlme_get_min_he_mcs_map(v139, *(_WORD *)(a2 + 202));
  v141 = wlan_mlme_get_min_he_mcs_map(*(_WORD *)(v17 + 1332), *(_WORD *)(a2 + 200));
  WORD2(v154) = v140 | v137;
  LOWORD(v154) = v141 | v137;
  qdf_mem_copy((void *)(v17 + 1332), &v154, 2u);
  qdf_mem_copy((void *)(v17 + 1334), (char *)&v154 + 4, 2u);
  qdf_mem_copy((void *)(v17 + 1336), (const void *)(a2 + 204), 2u);
  qdf_mem_copy((void *)(v17 + 1338), (const void *)(a2 + 206), 2u);
  qdf_mem_copy((void *)(v17 + 1428), (const void *)(a2 + 236), 0x19u);
  qdf_mem_copy((void *)(v17 + 1453), (const void *)(a2 + 261), 0x19u);
  v142 = *(_QWORD *)(v17 + 1348);
  *(_QWORD *)(v17 + 1400) = *(_QWORD *)(v17 + 1340);
  v143 = *(_QWORD *)(v17 + 1356);
  *(_QWORD *)(v17 + 1408) = v142;
  LODWORD(v142) = *(_DWORD *)(v17 + 1364);
  *(_QWORD *)(v17 + 1416) = v143;
  *(_DWORD *)(v17 + 1424) = v142;
  v144 = *(_QWORD *)(v17 + 1316);
  *(_QWORD *)(v17 + 1368) = *v108;
  *(_QWORD *)(v17 + 1376) = v144;
  v145 = *(_QWORD *)(v17 + 1332);
  *(_QWORD *)(v17 + 1384) = *(_QWORD *)(v17 + 1324);
  *(_QWORD *)(v17 + 1392) = v145;
  LOWORD(v145) = *(_WORD *)(v17 + 1494);
  *(_WORD *)(v17 + 1492) &= *(_WORD *)(a2 + 408);
  *(_WORD *)(v17 + 1494) = v145 & *(_WORD *)(a2 + 410);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: mcs_12_13 2G: %x 5G: %x FW_cap: 2G: %x 5G: %x",
    v146,
    v147,
    v148,
    v149,
    v150,
    v151,
    v152,
    v153,
    "mlme_update_tgt_he_caps_in_cfg");
  result = 0;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
