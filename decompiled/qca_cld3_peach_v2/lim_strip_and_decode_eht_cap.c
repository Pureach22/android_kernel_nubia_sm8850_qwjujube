unsigned __int8 *__fastcall lim_strip_and_decode_eht_cap(
        unsigned __int8 *a1,
        unsigned __int16 a2,
        _BYTE *a3,
        __int64 a4,
        unsigned __int16 a5,
        char a6)
{
  unsigned __int8 *result; // x0
  unsigned __int8 *v11; // x20
  bool is_24ghz_ch_freq; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x22
  bool v31; // w23
  __int64 v32; // x9
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x9
  unsigned __int64 v35; // x9
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x9
  unsigned __int64 v38; // x9
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x9
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x9
  unsigned __int64 v44; // x9
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x9
  unsigned __int64 v47; // x9
  unsigned __int64 v48; // x9
  unsigned __int64 v49; // x9
  unsigned __int64 v50; // x9
  unsigned __int64 v51; // x9
  unsigned __int64 v52; // x10
  unsigned __int64 v53; // x9
  unsigned __int64 v54; // x9
  unsigned __int64 v55; // x9
  unsigned __int64 v56; // x9
  unsigned __int64 v57; // x9
  unsigned __int64 v58; // x9
  unsigned __int64 v59; // x9
  unsigned __int64 v60; // x9
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
  __int64 v74; // x10
  unsigned __int64 v75; // x10
  unsigned __int64 v76; // x9
  unsigned __int64 v77; // x9
  unsigned __int64 v78; // x9
  unsigned __int64 v79; // x9
  unsigned __int64 v80; // x9
  unsigned __int64 v81; // x9
  unsigned __int64 v82; // x9
  unsigned __int64 v83; // x9
  unsigned __int64 v84; // x9
  unsigned __int64 v85; // x9
  unsigned __int64 v86; // x9
  unsigned __int64 v87; // x9
  unsigned __int64 v88; // x9
  unsigned __int64 v89; // x9
  unsigned __int64 v90; // x9
  unsigned __int64 v91; // x9
  unsigned int v92; // w4
  unsigned __int64 v93; // x9
  unsigned __int64 v94; // x9
  unsigned int v95; // w10
  unsigned int v96; // w11
  __int64 v97; // x12
  unsigned __int64 v98; // x9
  unsigned __int64 v99; // x10
  unsigned __int64 v100; // x9
  unsigned __int64 v101; // x11
  unsigned __int64 v102; // x9
  unsigned __int64 v103; // x10
  unsigned __int64 v104; // x11
  unsigned __int64 v105; // x9
  unsigned __int64 v106; // x11
  unsigned __int64 v107; // x9
  unsigned __int64 v108; // x10
  unsigned int v109; // w10
  unsigned int v110; // w9
  __int64 v111; // x8
  unsigned int v112; // w12
  unsigned __int8 *v113; // x8
  unsigned __int64 v114; // x9
  unsigned __int64 v115; // x9
  unsigned __int64 v116; // x9
  unsigned __int64 v117; // x9
  unsigned __int64 v118; // x9
  unsigned __int8 *v119; // x12
  unsigned __int64 v120; // x14
  unsigned __int64 v121; // x14
  unsigned __int64 v122; // x13
  unsigned __int64 v123; // x13
  unsigned __int64 v124; // x13
  unsigned __int64 v125; // x13
  unsigned __int8 *v126; // x8
  unsigned __int64 v127; // x10
  unsigned __int64 v128; // x10
  unsigned __int64 v129; // x10
  unsigned __int64 v130; // x10
  char v131; // w9

  result = wlan_get_ext_ie_ptr_from_ext_id("l", 1u, a1, a2);
  if ( !result )
    return result;
  v11 = result;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a5);
  if ( v11[1] <= 0xBu )
  {
    v21 = "%s: Invalid EHT cap IE len %d";
    goto LABEL_4;
  }
  if ( *v11 != 255 || v11[2] != 108 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid EHT cap IE",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_ieee80211_unpack_ehtcap");
    goto LABEL_12;
  }
  v30 = *(_QWORD *)(a4 + 1);
  v31 = is_24ghz_ch_freq;
  qdf_mem_set(a3, 0x5Cu, 0);
  v32 = *(_QWORD *)(a3 + 1);
  *a3 = 1;
  v33 = v32 & 0xFFFFFFFFFFFFFFFELL | v11[3] & 1;
  *(_QWORD *)(a3 + 1) = v33;
  v34 = v33 & 0xFFFFFFFFFFFFFFFDLL | (2 * (((unsigned __int64)v11[3] >> 1) & 1));
  *(_QWORD *)(a3 + 1) = v34;
  v35 = v34 & 0xFFFFFFFFFFFFFFFBLL | (4 * (((unsigned __int64)v11[3] >> 2) & 1));
  *(_QWORD *)(a3 + 1) = v35;
  v36 = v35 & 0xFFFFFFFFFFFFFFF7LL | (8 * (((unsigned __int64)v11[3] >> 3) & 1));
  *(_QWORD *)(a3 + 1) = v36;
  v37 = v36 & 0xFFFFFFFFFFFFFFEFLL | (16 * (((unsigned __int64)v11[3] >> 4) & 1));
  *(_QWORD *)(a3 + 1) = v37;
  v38 = v37 & 0xFFFFFFFFFFFFFFDFLL | (32 * (((unsigned __int64)v11[3] >> 5) & 1));
  *(_QWORD *)(a3 + 1) = v38;
  v39 = v38 & 0xFFFFFFFFFFFFFF3FLL | ((((unsigned __int64)v11[3] >> 6) & 3) << 6);
  *(_QWORD *)(a3 + 1) = v39;
  v40 = v39 & 0xFFFFFFFFFFFFFEFFLL | ((unsigned __int64)(v11[4] & 1) << 8);
  *(_QWORD *)(a3 + 1) = v40;
  v41 = v40 & 0xFFFFFFFFFFFFFDFFLL | ((((unsigned __int64)v11[4] >> 1) & 1) << 9);
  *(_QWORD *)(a3 + 1) = v41;
  v42 = v41 & 0xFFFFFFFFFFFFFBFFLL | ((((unsigned __int64)v11[4] >> 2) & 1) << 10);
  *(_QWORD *)(a3 + 1) = v42;
  v43 = v42 & 0xFFFFFFFFFFFFF7FFLL | ((((unsigned __int64)v11[4] >> 3) & 1) << 11);
  *(_QWORD *)(a3 + 1) = v43;
  v44 = v43 & 0xFFFFFFFFFFFFCFFFLL | ((((unsigned __int64)v11[4] >> 4) & 3) << 12);
  *(_QWORD *)(a3 + 1) = v44;
  v45 = v11[5];
  v46 = v44 & 0xFFFFFFFFFFFDFFFFLL | (((v45 >> 1) & 1) << 17);
  *(_QWORD *)(a3 + 1) = v46;
  v47 = v46 & 0xFFFFFFFFFFFBFFFFLL | ((((unsigned __int64)v11[5] >> 2) & 1) << 18);
  *(_QWORD *)(a3 + 1) = v47;
  v48 = v47 & 0xFFFFFFFFFFF7FFFFLL | ((((unsigned __int64)v11[5] >> 3) & 1) << 19);
  *(_QWORD *)(a3 + 1) = v48;
  v49 = v48 & 0xFFFFFFFFFFEFFFFFLL | ((((unsigned __int64)v11[5] >> 4) & 1) << 20);
  *(_QWORD *)(a3 + 1) = v49;
  v50 = v49 & 0xFFFFFFFFFFDFFFFFLL | ((((unsigned __int64)v11[5] >> 5) & 1) << 21);
  *(_QWORD *)(a3 + 1) = v50;
  v51 = v50 & 0xFFFFFFFFFFBFFFFFLL | ((((unsigned __int64)v11[5] >> 6) & 1) << 22);
  *(_QWORD *)(a3 + 1) = v51;
  v51 &= 0xFFFFFFFFF8FFFFFFLL;
  v52 = v11[5];
  *(_QWORD *)(a3 + 1) = v51 & 0xFFFFFFFFFEFFFFFFLL | (((v52 >> 7) & 1) << 24);
  v53 = ((_DWORD)v52 << 17) & 0x1000000 | ((unsigned __int64)(v11[6] & 3) << 25) | v51;
  *(_QWORD *)(a3 + 1) = v53;
  v54 = v53 & 0xFFFFFFFFC7FFFFFFLL | ((((unsigned __int64)v11[6] >> 2) & 7) << 27);
  *(_QWORD *)(a3 + 1) = v54;
  v55 = v54 & 0xFFFFFFFE3FFFFFFFLL | ((((unsigned __int64)v11[6] >> 5) & 7) << 30);
  *(_QWORD *)(a3 + 1) = v55;
  v56 = v55 & 0xFFFFFFF1FFFFFFFFLL | ((unsigned __int64)(v11[7] & 7) << 33);
  *(_QWORD *)(a3 + 1) = v56;
  v57 = v56 & 0xFFFFFF8FFFFFFFFFLL | ((unsigned __int64)((v11[7] >> 3) & 7) << 36);
  *(_QWORD *)(a3 + 1) = v57;
  v58 = v57 & 0xFFFFFC7FFFFFFFFFLL | ((((unsigned __int64)v11[7] >> 6) & 3) << 39);
  *(_QWORD *)(a3 + 1) = v58;
  v59 = v58 & 0xFFFFF9FFFFFFFFFFLL | ((unsigned __int64)((v11[8] >> 1) & 1) << 42);
  *(_QWORD *)(a3 + 1) = v59;
  v60 = v59 & 0xFFFFF7FFFFFFFFFFLL | ((unsigned __int64)((v11[8] >> 2) & 1) << 43);
  *(_QWORD *)(a3 + 1) = v60;
  v61 = v60 & 0xFFFFEFFFFFFFFFFFLL | ((unsigned __int64)((v11[8] >> 3) & 1) << 44);
  *(_QWORD *)(a3 + 1) = v61;
  v62 = v61 & 0xFFFFDFFFFFFFFFFFLL | ((unsigned __int64)((v11[8] >> 4) & 1) << 45);
  *(_QWORD *)(a3 + 1) = v62;
  v63 = v62 & 0xFFFFBFFFFFFFFFFFLL | ((unsigned __int64)((v11[8] >> 5) & 1) << 46);
  *(_QWORD *)(a3 + 1) = v63;
  v64 = v63 & 0xFFFF7FFFFFFFFFFFLL | ((unsigned __int64)((v11[8] >> 6) & 1) << 47);
  *(_QWORD *)(a3 + 1) = v64;
  v65 = v64 & 0xFFFEFFFFFFFFFFFFLL | ((unsigned __int64)v11[8] << 41) & 0x1000000000000LL;
  *(_QWORD *)(a3 + 1) = v65;
  v66 = v65 & 0xFFFDFFFFFFFFFFFFLL | ((unsigned __int64)(v11[9] & 1) << 49);
  *(_QWORD *)(a3 + 1) = v66;
  v67 = v66 & 0xFFFBFFFFFFFFFFFFLL | ((unsigned __int64)((v11[9] >> 1) & 1) << 50);
  *(_QWORD *)(a3 + 1) = v67;
  v68 = v67 & 0xFFF7FFFFFFFFFFFFLL | ((unsigned __int64)((v11[9] >> 2) & 1) << 51);
  *(_QWORD *)(a3 + 1) = v68;
  v69 = v68 & 0xFFEFFFFFFFFFFFFFLL | ((unsigned __int64)((v11[9] >> 3) & 1) << 52);
  *(_QWORD *)(a3 + 1) = v69;
  v70 = v69 & 0xF0FFFFFFFFFFFFFFLL | ((unsigned __int64)v11[9] << 52) & 0xF00000000000000LL;
  *(_QWORD *)(a3 + 1) = v70;
  v71 = v70 & 0xEFFFFFFFFFFFFFFFLL | ((unsigned __int64)(v11[10] & 1) << 60);
  *(_QWORD *)(a3 + 1) = v71;
  v72 = v71 & 0xDFFFFFFFFFFFFFFFLL | ((unsigned __int64)((v11[10] >> 1) & 1) << 61);
  *(_QWORD *)(a3 + 1) = v72;
  v73 = v72 & 0xBFFFFFFFFFFFFFFFLL | ((unsigned __int64)((v11[10] >> 2) & 1) << 62);
  *(_QWORD *)(a3 + 1) = v73;
  v74 = *(_QWORD *)(a3 + 9);
  *(_QWORD *)(a3 + 1) = v73 & 0x7FFFFFFFFFFFFFFFLL | ((unsigned __int64)v11[10] >> 3 << 63);
  v75 = v74 & 0xFFFFFFFFFFFFFFFCLL | ((unsigned __int64)v11[10] >> 4) & 3;
  *(_QWORD *)(a3 + 9) = v75;
  v76 = v75 & 0xFFFFFFFFFFFFFF83LL | ((unsigned __int64)v11[10] >> 4) & 0xC;
  *(_QWORD *)(a3 + 9) = v76;
  v77 = v76 & 0xFFFFFFFFFFFFF80FLL | ((((unsigned __int64)v11[11] >> 3) & 0xF) << 7);
  *(_QWORD *)(a3 + 9) = v77;
  v78 = v77 & 0xFFFFFFFFFFFFF7FFLL | (16 * v11[11]) & 0x800;
  *(_QWORD *)(a3 + 9) = v78;
  v79 = v78 & 0xFFFFFFFFFFFFEFFFLL | ((unsigned __int64)(v11[12] & 1) << 12);
  *(_QWORD *)(a3 + 9) = v79;
  v80 = v79 & 0xFFFFFFFFFFFFDFFFLL | (v11[12] << 12) & 0x2000LL;
  *(_QWORD *)(a3 + 9) = v80;
  v81 = v80 & 0xFFFFFFFFFFFFBFFFLL | (v11[12] << 12) & 0x4000LL;
  *(_QWORD *)(a3 + 9) = v81;
  v82 = v81 & 0xFFFFFFFFFFFF7FFFLL | (v11[12] << 12) & 0x8000LL;
  *(_QWORD *)(a3 + 9) = v82;
  v83 = v82 & 0xFFFFFFFFFFFEFF8FLL | ((((unsigned __int64)v11[12] >> 4) & 1) << 16);
  *(_QWORD *)(a3 + 9) = v83;
  v84 = v83 & 0xFFFFFFFFFFFDFF8FLL | ((((unsigned __int64)v11[12] >> 5) & 1) << 17);
  *(_QWORD *)(a3 + 9) = v84;
  v85 = v84 & 0xFFFFFFFFFFFBFF8FLL | ((((unsigned __int64)v11[12] >> 6) & 1) << 18);
  *(_QWORD *)(a3 + 9) = v85;
  v86 = v85 & 0xFFFFFFFFFFF7FF8FLL | ((((unsigned __int64)v11[12] >> 7) & 1) << 19);
  *(_QWORD *)(a3 + 9) = v86;
  v87 = v86 & 0xFFFFFFFFFFEFFF8FLL | ((unsigned __int64)(v11[13] & 1) << 20);
  *(_QWORD *)(a3 + 9) = v87;
  v88 = v87 & 0xFFFFFFFFFFDFFF8FLL | ((((unsigned __int64)v11[13] >> 1) & 1) << 21);
  *(_QWORD *)(a3 + 9) = v88;
  v89 = v88 & 0xFFFFFFFFFFBFFF8FLL | ((((unsigned __int64)v11[13] >> 2) & 1) << 22);
  *(_QWORD *)(a3 + 9) = v89;
  v90 = v89 & 0xFFFFFFFFFF7FFF8FLL | ((((unsigned __int64)v11[13] >> 3) & 1) << 23);
  *(_QWORD *)(a3 + 9) = v90;
  v91 = v90 & 0xFFFFFFFFFEFFFFFFLL | ((((unsigned __int64)v11[13] >> 4) & 1) << 24);
  *(_QWORD *)(a3 + 9) = v91;
  v92 = v11[1];
  if ( v31 )
  {
    if ( (v30 & 0x4000000000000LL) != 0 )
    {
      if ( v92 >= 0xF )
        goto LABEL_24;
LABEL_16:
      v21 = "%s: Invalid EHT cap IE len %d for MCS NSS";
      goto LABEL_4;
    }
LABEL_17:
    if ( v92 > 0xE )
    {
      v93 = (v11[14] << 28) | v91 & 0xFFFFFFFF0FFFFF8FLL;
      *(_QWORD *)(a3 + 9) = v93;
      v94 = v93 & 0xFFFFFFF0FFFFFFFFLL | ((unsigned __int64)v11[14] << 28) & 0xF00000000LL;
      *(_QWORD *)(a3 + 9) = v94;
      if ( (a6 & 1) != 0 )
      {
        if ( v11[1] != 16 )
        {
          v21 = "%s: Invalid EHT cap IE len %d for MCS NSS STA";
          goto LABEL_4;
        }
        v95 = 1;
      }
      else
      {
        v95 = 0;
      }
      v113 = &v11[v95 + 14];
      v114 = v94 & 0xFFFFFF0FFFFFFF8FLL | ((unsigned __int64)(*v113 & 0xF) << 36);
      *(_QWORD *)(a3 + 9) = v114;
      v115 = v114 & 0xFFFFF0FFFFFFFFFFLL | ((unsigned __int64)*v113 << 36) & 0xF0000000000LL;
      *(_QWORD *)(a3 + 9) = v115;
      v116 = v115 & 0xFFFF0FFFFFFFFFFFLL | ((unsigned __int64)(v113[1] & 0xF) << 44);
      *(_QWORD *)(a3 + 9) = v116;
      v117 = v116 & 0xFFF0FFFFFFFFFFFFLL | ((unsigned __int64)v113[1] << 44) & 0xF000000000000LL;
      *(_QWORD *)(a3 + 9) = v117;
      v118 = v117 & 0xFF0FFFFFFFFFFFFFLL | ((unsigned __int64)(v113[2] & 0xF) << 52);
      *(_QWORD *)(a3 + 9) = v118;
      *(_QWORD *)(a3 + 9) = v118 & 0xF0FFFFFFFFFFFFFFLL | ((unsigned __int64)v113[2] << 52) & 0xF00000000000000LL;
      return nullptr;
    }
    v21 = "%s: Invalid EHT cap IE len %d for MCS NSS 20 MHz BW";
LABEL_4:
    qdf_trace_msg(0x35u, 2u, v21, v13, v14, v15, v16, v17, v18, v19, v20, "lim_ieee80211_unpack_ehtcap");
LABEL_12:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to extract eht cap",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "lim_strip_and_decode_eht_cap");
    return (unsigned __int8 *)&off_10;
  }
  if ( (v30 & 0x38000000000000LL) == 0 )
    goto LABEL_17;
  if ( v92 <= 0xE )
    goto LABEL_16;
  if ( (v30 & 0x8000000000000LL) == 0 )
  {
    v96 = 0;
    goto LABEL_25;
  }
LABEL_24:
  v97 = *(_QWORD *)(a3 + 17);
  v98 = v91 & 0xFFFFF0F0FFFFF8FLL
      | ((unsigned __int64)v11[14] << 60)
      | (v11[14] << 28)
      | ((unsigned __int64)(v11[14] & 0xF) << 36);
  *(_QWORD *)(a3 + 9) = v98;
  v99 = (unsigned __int64)v11[14] >> 4;
  *(_QWORD *)(a3 + 17) = v97 & 0xFFFFFFFFFFFFFFF0LL | v99;
  v100 = v98 & 0xFFFFF0F0FFFFFF8FLL | (v99 << 32) | (v99 << 40);
  *(_QWORD *)(a3 + 9) = v100;
  v101 = v97 & 0xFFFFFFFFFFFFFF00LL | v99 & 0xFFFFFFFFFFFFFF0FLL | (16LL * (v11[15] & 0xF));
  v102 = v100 & 0xFFFF0FFFFFFFFFFFLL | ((unsigned __int64)(v11[15] & 0xF) << 44);
  *(_QWORD *)(a3 + 17) = v101;
  *(_QWORD *)(a3 + 9) = v102;
  v103 = (unsigned __int64)v11[15] >> 4;
  v104 = v101 & 0xFFFFFFFFFFFFF0FFLL | ((v103 & 0xF) << 8);
  v105 = v102 & 0xFFF0FFFFFFFFFFFFLL | (v103 << 48);
  *(_QWORD *)(a3 + 17) = v104;
  *(_QWORD *)(a3 + 9) = v105;
  v106 = v104 & 0xFFFFFFFFFFFF0FFFLL | ((unsigned __int64)(v11[16] & 0xF) << 12);
  v107 = v105 & 0xFF0FFFFFFFFFFFFFLL | ((unsigned __int64)(v11[16] & 0xF) << 52);
  *(_QWORD *)(a3 + 17) = v106;
  *(_QWORD *)(a3 + 9) = v107;
  v108 = (unsigned __int64)v11[16] >> 4;
  *(_QWORD *)(a3 + 17) = v106 & 0xFFFFFFFFFFF0FFFFLL | ((v108 & 0xF) << 16);
  v96 = 3;
  *(_QWORD *)(a3 + 9) = v107 & 0xF0FFFFFFFFFFFFFFLL | (v108 << 56);
LABEL_25:
  v109 = v92 - 12;
  v110 = v96 + 3;
  if ( (v30 & 0x10000000000000LL) != 0 && v110 > v109 )
  {
    v21 = "%s: Invalid EHT cap IE len %d for ch_width2";
    goto LABEL_4;
  }
  v111 = ((_DWORD)v45 << 16) & 0x20000;
  if ( (v30 & 0x10000000000000LL) != 0 )
  {
    v119 = &v11[v96];
    v120 = *(_QWORD *)(a3 + 17) & 0xFFFFFFFFFF0FFFFFLL | ((unsigned __int64)(v119[14] & 0xF) << 20);
    *(_QWORD *)(a3 + 17) = v120;
    v121 = v120 & 0xFFFFFFFFF0FFFFFFLL | ((((unsigned __int64)v119[14] >> 4) & 0xF) << 24);
    *(_QWORD *)(a3 + 17) = v121;
    v122 = v121 & 0xFFFFFFFF0FFFFFFFLL | (v119[15] << 28);
    *(_QWORD *)(a3 + 17) = v122;
    v123 = v122 & 0xFFFFFFF0FFFFFFFFLL | ((((unsigned __int64)v119[15] >> 4) & 0xF) << 32);
    *(_QWORD *)(a3 + 17) = v123;
    v124 = v123 & 0xFFFFFF0FFFFFFFFFLL | ((unsigned __int64)(v119[16] & 0xF) << 36);
    *(_QWORD *)(a3 + 17) = v124;
    v125 = v124 & 0xFFFFF0FFFFFFFFFFLL | ((((unsigned __int64)v119[16] >> 4) & 0xF) << 40);
    v112 = v96 + 6;
    *(_QWORD *)(a3 + 17) = v125;
  }
  else
  {
    v112 = v96 + 3;
    v110 = v96;
  }
  if ( v111 && v112 > v109 )
  {
    v21 = "%s: Invalid EHT cap IE len %d for 320 MHz BW";
    goto LABEL_4;
  }
  result = nullptr;
  if ( v111 )
  {
    v126 = &v11[v110];
    v127 = *(_QWORD *)(a3 + 17) & 0xFFFF0FFFFFFFFFFFLL | ((unsigned __int64)(v126[14] & 0xF) << 44);
    *(_QWORD *)(a3 + 17) = v127;
    v128 = v127 & 0xFFF0FFFFFFFFFFFFLL | ((((unsigned __int64)v126[14] >> 4) & 0xF) << 48);
    *(_QWORD *)(a3 + 17) = v128;
    v129 = v128 & 0xFF0FFFFFFFFFFFFFLL | ((unsigned __int64)(v126[15] & 0xF) << 52);
    *(_QWORD *)(a3 + 17) = v129;
    v130 = v129 & 0xF0FFFFFFFFFFFFFFLL | ((((unsigned __int64)v126[15] >> 4) & 0xF) << 56);
    *(_QWORD *)(a3 + 17) = v130;
    v131 = a3[25];
    *(_QWORD *)(a3 + 17) = v130 & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)v126[16] << 60);
    a3[25] = v131 & 0xF0 | (v126[16] >> 4);
  }
  return result;
}
