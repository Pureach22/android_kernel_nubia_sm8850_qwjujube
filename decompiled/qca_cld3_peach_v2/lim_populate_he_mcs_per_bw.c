__int64 __fastcall lim_populate_he_mcs_per_bw(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _WORD *a10,
        _WORD *a11,
        unsigned int a12,
        unsigned int a13,
        char a14,
        unsigned int a15,
        unsigned int a16)
{
  unsigned int v16; // w25
  unsigned int v17; // w21
  unsigned int v18; // w27
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int16 v30; // w5
  int v31; // w14
  int v32; // w15
  int v33; // w13
  int v34; // w16
  int v35; // w12
  int v36; // w17
  __int16 v37; // w10
  int v38; // w12
  int v39; // w13
  int v40; // w14
  int v41; // w15
  int v42; // w11
  __int16 v43; // w10
  int v44; // w14
  int v45; // w14
  int v46; // w16
  int v47; // w17
  int v48; // w0
  __int16 v49; // w8
  __int16 v50; // w10
  int v51; // w12
  int v52; // w17
  int v53; // w17
  unsigned __int16 v54; // w3
  int v55; // w4
  int v56; // w6
  int v57; // w1
  unsigned __int16 v58; // w20
  int v59; // w17
  int v60; // w0
  int v61; // w4
  int v62; // w1
  int v63; // w7
  int v64; // w5
  int v65; // w3
  int v66; // w4
  int v67; // w6
  int v68; // w3
  int v69; // w2
  int v70; // w5
  int v71; // w6
  int v72; // w4
  int v73; // w7
  int v74; // w19
  int v75; // w3
  int v76; // w4
  int v77; // w5
  int v78; // w7
  int v79; // w28
  int v80; // w4
  int v81; // w6
  int v82; // w7
  int v83; // w5
  int v84; // w19
  int v85; // w2
  int v86; // w26
  int v87; // w10
  __int64 v89; // x8
  __int16 v90; // [xsp+4h] [xbp-1Ch]

  v16 = (unsigned __int16)a12;
  v17 = (unsigned __int16)a13;
  v18 = a13;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: peer rates: rx_mcs - 0x%04x tx_mcs - 0x%04x",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "lim_populate_he_mcs_per_bw",
    (unsigned __int16)a12,
    (unsigned __int16)a13);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: self rates: rx_mcs - 0x%04x tx_mcs - 0x%04x",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "lim_populate_he_mcs_per_bw",
    (unsigned __int16)a15,
    (unsigned __int16)a16);
  v30 = (unsigned __int16)v18 >> 14;
  v31 = (unsigned __int16)v18 >> 2;
  v32 = (unsigned __int16)v18 >> 3;
  v33 = (unsigned __int16)a15 >> 3;
  v34 = ((unsigned __int16)a15 >> 2) & 1;
  v35 = ((unsigned __int16)a15 >> 3) & 1;
  v36 = v34 & v33 | (unsigned __int8)v31 & (unsigned __int8)v32 & 1;
  v37 = (v32 ^ v31) & ~(_WORD)v33 & v34 | (v35 ^ v34) & ~(_WORD)v32 & v31;
  v38 = v32 & ~(v31 | ((unsigned __int16)a15 >> 2)) & v35 | v36;
  v39 = ((unsigned __int16)a15 >> 4) & 1;
  v40 = (unsigned __int16)v18 >> 4;
  v41 = (unsigned __int16)v18 >> 5;
  v42 = ((unsigned __int16)a15 >> 5) & 1;
  v90 = ((unsigned __int16)a15 >> 1) & a15 & 1
      | (unsigned __int8)v18 & (unsigned __int8)((unsigned __int16)v18 >> 1) & 1;
  v43 = v37 | (2 * v38) | v36;
  LOWORD(v34) = v39 & ((unsigned __int16)a15 >> 5);
  LOWORD(v36) = (unsigned __int8)v40 & (unsigned __int8)v41 & 1;
  LOWORD(v38) = (v41 ^ v40) & ~((unsigned __int16)a15 >> 5) & v39;
  LOWORD(v39) = (v42 ^ v39) & ~(_WORD)v41 & v40;
  v44 = v41 & ~(v40 | ((unsigned __int16)a15 >> 4));
  LOWORD(v41) = v34 | v36;
  LOWORD(v42) = v44 & v42;
  v45 = ((unsigned __int16)a15 >> 6) & 1;
  v46 = ((unsigned __int16)a15 >> 7) & 1;
  v47 = (unsigned __int16)v18 >> 6;
  v48 = (unsigned __int16)v18 >> 7;
  v49 = (((unsigned __int16)v18 >> 1) ^ v18) & (unsigned __int8)~(unsigned __int8)((unsigned __int16)a15 >> 1) & a15 & 1
      | (((unsigned __int16)a15 >> 1) & 1 ^ a15 & 1) & ~((unsigned __int16)v18 >> 1) & v17
      | (2 * (((unsigned __int16)v18 >> 1) & ~(a15 | v18) & ((unsigned __int16)a15 >> 1) & 1 | v90))
      | (4 * v43);
  v50 = v38 | v39 | (2 * (v42 | v41)) | v41;
  LOWORD(v42) = v45 & ((unsigned __int16)a15 >> 7) | (unsigned __int8)v47 & (unsigned __int8)v48 & 1;
  LOWORD(v39) = (v48 ^ v47) & ~((unsigned __int16)a15 >> 7) & v45 | (v46 ^ v45) & ~(_WORD)v48 & v47;
  v51 = v48 & ~(v47 | ((unsigned __int16)a15 >> 6)) & v46;
  v52 = BYTE1(a15) & 1;
  LOWORD(v48) = v51 | v42;
  LOWORD(v51) = v52 & ((unsigned __int16)a15 >> 9) | BYTE1(v18) & ((unsigned __int16)v18 >> 9) & 1;
  LOWORD(v45) = (((unsigned __int16)v18 >> 9) ^ BYTE1(v18)) & ~((unsigned __int16)a15 >> 9) & v52
              | (unsigned __int8)((((a15 & 0x200) != 0) ^ v52) & ~((unsigned __int16)v18 >> 9) & BYTE1(v18));
  v53 = ((unsigned __int16)a15 >> 10) & 1;
  LOWORD(v41) = v53 & ((unsigned __int16)a15 >> 11) | ((unsigned __int16)v18 >> 10) & ((unsigned __int16)v18 >> 11) & 1;
  v54 = (unsigned __int16)a15 >> 14;
  v55 = (a15 >> 15) & 1;
  v56 = (v18 >> 15) & 1;
  LOWORD(v51) = v45
              | (2 * (((unsigned __int16)v18 >> 9) & ~(BYTE1(v18) | BYTE1(a15)) & ((unsigned __int16)a15 >> 9) & 1 | v51))
              | v51;
  LOWORD(v45) = (((unsigned __int16)v18 >> 11) ^ ((unsigned __int16)v18 >> 10)) & ~((unsigned __int16)a15 >> 11) & v53
              | (((unsigned __int16)a15 >> 11)
               & 1
               ^ v53)
              & ~((unsigned __int16)v18 >> 11)
              & ((unsigned __int16)v18 >> 10)
              | (2
               * (((unsigned __int16)v18 >> 11)
                & ~(((unsigned __int16)v18 >> 10) | ((unsigned __int16)a15 >> 10))
                & ((unsigned __int16)a15 >> 11)
                & 1
                | v41))
              | v41;
  v57 = ((unsigned __int16)a15 >> 12) & 1;
  v58 = v57 & ((unsigned __int16)a15 >> 13) | ((unsigned __int16)v18 >> 12) & ((unsigned __int16)v18 >> 13) & 1;
  v59 = ((unsigned __int16)a16 >> 1) & 1;
  LOWORD(v42) = ((((v17 >> 14) & 1 ^ (unsigned __int16)v56) & (unsigned __int16)~(_WORD)v55 & v54
                | (unsigned __int16)((((a15 & 0x4000) != 0) ^ (unsigned __int16)v55) & ~(_WORD)v56 & v30)
                | (unsigned __int16)(2 * (v54 & v55 | v30 & v56 | v56 & ~(v54 | v30) & v55))
                | (unsigned __int16)(v54 & v55 | v30 & v56)) << 14)
              | (16 * v50)
              | (((unsigned __int16)(v39 | (2 * v48)) | (unsigned __int16)v42) << 6)
              | ((_WORD)v51 << 8);
  LOWORD(v51) = (((unsigned __int16)v18 >> 13) ^ ((unsigned __int16)v18 >> 12)) & ~((unsigned __int16)a15 >> 13) & v57
              | (((unsigned __int16)a15 >> 13)
               & 1
               ^ v57)
              & ~((unsigned __int16)v18 >> 13)
              & ((unsigned __int16)v18 >> 12)
              | (2
               * (((unsigned __int16)v18 >> 13)
                & ~(((unsigned __int16)v18 >> 12) | ((unsigned __int16)a15 >> 12))
                & ((unsigned __int16)a15 >> 13)
                & 1
                | v58));
  LOWORD(v42) = v42 | ((_WORD)v45 << 10);
  v60 = (unsigned __int16)a12 >> 2;
  LOWORD(v45) = (((unsigned __int16)a12 >> 1) ^ a12) & ~((unsigned __int16)a16 >> 1) & a16 & 1
              | (v59 ^ a16 & 1) & ~((unsigned __int16)a12 >> 1) & v16;
  v61 = ((unsigned __int16)a16 >> 2) & 1;
  v62 = ((unsigned __int16)a16 >> 3) & 1;
  LOWORD(v41) = ((unsigned __int16)a12 >> 1) & ~(a16 | a12) & v59;
  v63 = v60 | ((unsigned __int16)a16 >> 2);
  LOWORD(v46) = v61 & ((unsigned __int16)a16 >> 3)
              | (unsigned __int8)v60 & (unsigned __int8)((unsigned __int16)a12 >> 3) & 1;
  v64 = (unsigned __int16)a12 >> 4;
  LOWORD(v59) = (((unsigned __int16)a12 >> 3) ^ v60) & ~((unsigned __int16)a16 >> 3) & v61;
  LOWORD(v60) = (v62 ^ v61) & ~((unsigned __int16)a12 >> 3) & v60;
  v65 = ((unsigned __int16)a16 >> 4) & 1;
  v66 = ((unsigned __int16)a16 >> 5) & 1;
  v67 = (unsigned __int16)a12 >> 5;
  LOWORD(v59) = v59 | v60 | (2 * (((unsigned __int16)a12 >> 3) & ~(_WORD)v63 & v62 | v46));
  LOWORD(v60) = v65 & ((unsigned __int16)a16 >> 5) | (unsigned __int8)v64 & (unsigned __int8)v67 & 1;
  LOWORD(v62) = (v67 ^ v64) & ~((unsigned __int16)a16 >> 5) & v65 | (v66 ^ v65) & ~(_WORD)v67 & v64;
  v68 = (unsigned __int16)a12 >> 6;
  v69 = v67 & ~(v64 | ((unsigned __int16)a16 >> 4));
  v70 = (unsigned __int16)a12 >> 7;
  v71 = ((unsigned __int16)a16 >> 6) & 1;
  LOWORD(v69) = v69 & v66;
  v72 = (unsigned __int16)a16 >> 7;
  v73 = ((unsigned __int16)a16 >> 7) & 1;
  v74 = v71 & v72 | (unsigned __int8)v68 & (unsigned __int8)v70 & 1;
  LOWORD(v62) = v62 | (2 * (v69 | v60));
  LOWORD(v69) = (v70 ^ v68) & ~(_WORD)v72 & v71 | (v73 ^ v71) & ~(_WORD)v70 & v68;
  v75 = v70 & ~(v68 | ((unsigned __int16)a16 >> 6)) & v73 | v74;
  v76 = BYTE1(a16) & 1;
  v77 = ((unsigned __int16)a16 >> 9) & 1;
  v78 = (unsigned __int16)a12 >> 9;
  LOWORD(v62) = v62 | v60;
  v79 = (a12 >> 15) & 1;
  LOWORD(v60) = v69 | (2 * v75) | v74;
  LOWORD(v75) = (v78 ^ BYTE1(a12)) & ~((unsigned __int16)a16 >> 9) & v76 | (v77 ^ v76) & ~(_WORD)v78 & BYTE1(a12);
  LOWORD(v69) = v76 & ((unsigned __int16)a16 >> 9) | BYTE1(a12) & (unsigned __int8)v78 & 1;
  v80 = v78 & ~(BYTE1(a12) | BYTE1(a16)) & v77;
  v81 = (unsigned __int16)a12 >> 10;
  v82 = (unsigned __int16)a12 >> 11;
  v83 = (unsigned __int16)a16 >> 11;
  v84 = ((unsigned __int16)a16 >> 10) & 1;
  LOWORD(v75) = v75 | (2 * (v80 | v69)) | v69;
  v85 = v84 & v83 | (unsigned __int8)v81 & (unsigned __int8)v82 & 1;
  LOWORD(v17) = (unsigned __int16)a16 >> 14;
  v86 = (a16 >> 15) & 1;
  LOWORD(v18) = (unsigned __int16)a12 >> 14;
  v87 = (v82 ^ v81) & ~v83 & v84
      | (((unsigned __int16)a16 >> 11) & 1 ^ v84) & ~v82 & v81
      | (2 * (v82 & ~(v81 | ((unsigned __int16)a16 >> 10)) & ((unsigned __int16)a16 >> 11) & 1 | v85));
  LOWORD(v80) = (unsigned __int16)a12 >> 12;
  LOWORD(v83) = (unsigned __int16)a12 >> 13;
  LOWORD(v81) = (unsigned __int16)a16 >> 13;
  *a11 = v42 | (((unsigned __int16)v51 | v58) << 12) | v49 | v90;
  *a10 = ((((v16 >> 14) & 1 ^ (unsigned __int16)v79) & (unsigned __int16)~(_WORD)v86 & (unsigned __int16)v17
         | (((a16 & 0x4000) != 0) ^ (unsigned __int16)v86) & ~(_WORD)v79 & v18
         | (unsigned __int16)(2 * (v17 & v86 | v18 & v79 | v79 & ~(v17 | v18) & v86))
         | v17 & (unsigned __int16)v86
         | v18 & (unsigned __int16)v79) << 14)
       | (16 * v62)
       | ((_WORD)v60 << 6)
       | ((_WORD)v75 << 8)
       | (((unsigned __int16)v87 | (unsigned __int16)v85) << 10)
       | (((v83 ^ v80) & ~(_WORD)v81 & ((unsigned __int16)a16 >> 12) & 1
         | (((unsigned __int16)a16 >> 13)
          & 1
          ^ ((unsigned __int16)a16 >> 12)
          & 1)
         & (unsigned __int16)~(_WORD)v83
         & (unsigned __int16)v80
         | (unsigned __int16)(2
                            * (v83 & ~(v80 | ((unsigned __int16)a16 >> 12)) & ((unsigned __int16)a16 >> 13) & 1
                             | ((a16 & 0x1000) != 0) & (unsigned __int8)v81
                             | (unsigned __int8)v80 & (unsigned __int8)v83 & 1))
         | ((a16 & 0x1000) != 0) & (unsigned __int8)v81
         | (unsigned __int8)v80 & (unsigned __int8)v83 & 1) << 12)
       | v45
       | (2
        * (v41
         | ((unsigned __int16)a16 >> 1) & a16 & 1
         | (unsigned __int8)a12 & (unsigned __int8)((unsigned __int16)a12 >> 1) & 1))
       | (4 * (v59 | v46))
       | ((unsigned __int16)a16 >> 1) & a16 & 1
       | (unsigned __int8)a12 & (unsigned __int8)((unsigned __int16)a12 >> 1) & 1;
  v89 = -1LL << (2 * a14);
  *a11 |= v89;
  *a10 |= v89;
  return 0;
}
