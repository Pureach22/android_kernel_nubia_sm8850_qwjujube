void *__fastcall lim_ieee80211_pack_ehtcap(
        _BYTE *a1,
        _BYTE *a2,
        __int64 a3,
        char a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  void *result; // x0
  int v19; // w12
  int v20; // w9
  unsigned int v21; // w9
  unsigned int v22; // w9
  unsigned int v23; // w9
  unsigned int v24; // w9
  int v25; // w8
  unsigned int v26; // w8
  unsigned int v27; // w8
  int v28; // w9
  __int64 v29; // x8
  unsigned int v30; // w9
  unsigned int v31; // w9
  unsigned int v32; // w9
  unsigned int v33; // w9
  unsigned int v34; // w9
  unsigned int v35; // w10
  unsigned int v36; // w12
  char v37; // w11
  __int64 v38; // x9
  __int64 v39; // x11
  int v40; // w10
  unsigned int v41; // w10
  unsigned int v42; // w10
  unsigned int v43; // w10
  unsigned int v44; // w10
  unsigned int v45; // w10
  int v46; // w10
  int v47; // w10
  unsigned int v48; // w10
  unsigned int v49; // w10
  int v50; // w10
  unsigned int v51; // w10
  unsigned int v52; // w10
  unsigned int v53; // w10
  unsigned int v54; // w10
  int v55; // w10
  unsigned int v56; // w10
  unsigned int v57; // w10
  unsigned int v58; // w10
  unsigned int v59; // w10
  unsigned int v60; // w10
  unsigned int v61; // w10
  int v62; // w10
  unsigned int v63; // w10
  unsigned int v64; // w10
  unsigned int v65; // w10
  unsigned int v66; // w10
  __int64 v67; // x10
  unsigned int v68; // w9
  unsigned int v69; // w9
  _BYTE *v70; // x8
  char v71; // w10
  _BYTE *v72; // x9
  __int64 v73; // x10
  __int64 v74; // x10
  __int64 v75; // x11
  __int64 v76; // x8
  __int64 v77; // x9
  char v78; // w10
  char v79; // w10
  char v80; // w10
  _BYTE *v81; // x10
  unsigned int v82; // w11
  unsigned int v83; // w11
  __int64 v84; // x11
  _BYTE *v85; // x8
  __int64 v86; // x10
  char v87; // w11
  __int64 v88; // x10
  char v89; // w11
  __int64 v90; // x10

  if ( !a1 )
    return (void *)qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: ie is null",
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     a12,
                     a13,
                     "lim_ieee80211_pack_ehtcap");
  qdf_mem_set(a1, 0x17u, 0);
  *a1 = -1;
  result = qdf_mem_copy(a1 + 2, "l", 1u);
  v19 = (unsigned __int8)a1[6];
  v20 = a1[3] & 0xFE | a2[1] & 1;
  a1[3] = v20;
  v21 = v20 & 0xFFFFFFFD | (2 * (((unsigned __int8)a2[1] >> 1) & 1));
  a1[3] = v21;
  v22 = v21 & 0xFFFFFFFB | (4 * (((unsigned __int8)a2[1] >> 2) & 1));
  a1[3] = v22;
  v23 = v22 & 0xFFFFFFF7 | (8 * (((unsigned __int8)a2[1] >> 3) & 1));
  a1[3] = v23;
  v24 = v23 & 0xFFFFFFEF | (16 * (((unsigned __int8)a2[1] >> 4) & 1));
  a1[3] = v24;
  LOBYTE(v24) = v24 & 0xDF | (32 * ((a2[1] & 0x20) != 0));
  a1[3] = v24;
  a1[3] = a2[1] & 0xC0 | v24 & 0x3F;
  v25 = a1[4] & 0xFE | a2[2] & 1;
  a1[4] = v25;
  v26 = v25 & 0xFFFFFFFD | (2 * (((unsigned __int8)a2[2] >> 1) & 1));
  a1[4] = v26;
  v27 = v26 & 0xFFFFFFFB | (4 * (((unsigned __int8)a2[2] >> 2) & 1));
  a1[4] = v27;
  LOBYTE(v27) = v27 & 0xF7 | (8 * ((a2[2] & 8) != 0));
  a1[4] = v27;
  v28 = (unsigned __int8)a1[5];
  a1[4] = v27 & 0xCF | a2[2] & 0x30;
  v29 = *(_QWORD *)(a2 + 1);
  v30 = v28 & 0xFFFFFFFD | (2 * (((unsigned int)v29 >> 17) & 1));
  a1[5] = v30;
  v31 = v30 & 0xFFFFFFFB | (4 * (((unsigned __int8)a2[3] >> 2) & 1));
  a1[5] = v31;
  v32 = v31 & 0xFFFFFFF7 | (8 * (((unsigned __int8)a2[3] >> 3) & 1));
  a1[5] = v32;
  v33 = v32 & 0xFFFFFFEF | (16 * (((unsigned __int8)a2[3] >> 4) & 1));
  a1[5] = v33;
  v34 = v33 & 0xFFFFFFDF | (32 * (((unsigned __int8)a2[3] >> 5) & 1));
  a1[5] = v34;
  LOBYTE(v34) = v34 & 0xBF | (((a2[3] & 0x40) != 0) << 6);
  a1[5] = v34;
  v35 = *(_DWORD *)(a2 + 1);
  v36 = v19 & 0xFFFFFFFC | (v35 >> 25) & 3;
  a1[6] = v36;
  a1[5] = (v35 >> 17) & 0x80 | v34 & 0x7F;
  LOBYTE(v34) = (*(_DWORD *)(a2 + 1) >> 25) & 0x1C;
  a1[6] = v34 | v36 & 0xE3;
  v37 = (*(_QWORD *)(a2 + 1) >> 25) & 0xE0 | (v35 >> 25) & 3;
  LOBYTE(v35) = a1[7] & 0xF8;
  a1[6] = v37 | v34;
  v38 = (*(_QWORD *)(a2 + 1) >> 33) & 7LL;
  LOBYTE(v35) = v38 | v35;
  a1[7] = v35;
  v39 = (*(_QWORD *)(a2 + 1) >> 33) & 0x38LL;
  a1[7] = v39 | v35 & 0xC7;
  v40 = (unsigned __int8)a1[8];
  a1[7] = v38 | (*(_QWORD *)(a2 + 1) >> 33) & 0xC0 | v39;
  v41 = v40 & 0xFFFFFFFD | (2 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 41) >> 1) & 1));
  a1[8] = v41;
  v42 = v41 & 0xFFFFFFFB | (4 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 41) >> 2) & 1));
  a1[8] = v42;
  v43 = v42 & 0xFFFFFFF7 | (8 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 41) >> 3) & 1));
  a1[8] = v43;
  v44 = v43 & 0xFFFFFFEF | (16 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 41) >> 4) & 1));
  a1[8] = v44;
  v45 = v44 & 0xFFFFFFDF | (32 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 41) >> 5) & 1));
  a1[8] = v45;
  LOBYTE(v45) = v45 & 0xBF | ((((*(_QWORD *)(a2 + 1) >> 41) & 0x40) != 0) << 6);
  a1[8] = v45;
  LOBYTE(v38) = (*(_QWORD *)(a2 + 1) >> 41) & 0x80 | v45 & 0x7F;
  v46 = (unsigned __int8)a1[9];
  a1[8] = v38;
  v47 = v46 & 0xFFFFFFFE | (*(_QWORD *)(a2 + 1) >> 49) & 1;
  a1[9] = v47;
  v48 = v47 & 0xFFFFFFFD | (2 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 49) >> 1) & 1));
  a1[9] = v48;
  v49 = v48 & 0xFFFFFFFB | (4 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 49) >> 2) & 1));
  a1[9] = v49;
  LOBYTE(v49) = v49 & 0xF7 | (8 * (((*(_QWORD *)(a2 + 1) >> 49) & 8) != 0));
  a1[9] = v49;
  LOBYTE(v38) = (*(_QWORD *)(a2 + 1) >> 52) & 0xF0 | v49 & 0xF;
  v50 = (unsigned __int8)a1[10];
  a1[9] = v38;
  v51 = v50 & 0xFFFFFFFE | ((*(_QWORD *)(a2 + 1) & 0x1000000000000000LL) != 0);
  a1[10] = v51;
  v52 = v51 & 0xFFFFFFFD | (2 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 60) >> 1) & 1));
  a1[10] = v52;
  v53 = v52 & 0xFFFFFFFB | (4 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 60) >> 2) & 1));
  a1[10] = v53;
  v54 = v53 & 0xFFFFFFF7 | (8 * (((unsigned int)(*(_QWORD *)(a2 + 1) >> 60) >> 3) & 1));
  a1[10] = v54;
  LOBYTE(v54) = v54 & 0xCF | (16 * (a2[9] & 3));
  a1[10] = v54;
  LOBYTE(v38) = (16 * a2[9]) & 0xC0 | v54 & 0x3F;
  LOBYTE(v54) = a1[11];
  a1[10] = v38;
  LOBYTE(v54) = v54 & 0x87 | (8 * ((*(_DWORD *)(a2 + 9) >> 7) & 0xF));
  a1[11] = v54;
  LOBYTE(v38) = (*(_DWORD *)(a2 + 9) >> 4) & 0x80 | v54 & 0x7F;
  v55 = (unsigned __int8)a1[12];
  a1[11] = v38;
  v56 = v55 & 0xFFFFFFFE | (*(_DWORD *)(a2 + 9) >> 12) & 1;
  a1[12] = v56;
  v57 = v56 & 0xFFFFFFFD | (2 * ((*(_DWORD *)(a2 + 9) >> 13) & 1));
  a1[12] = v57;
  v58 = v57 & 0xFFFFFFFB | (4 * ((*(_DWORD *)(a2 + 9) >> 14) & 1));
  a1[12] = v58;
  v59 = v58 & 0xFFFFFFF7 | (8 * ((*(_DWORD *)(a2 + 9) >> 15) & 1));
  a1[12] = v59;
  v60 = v59 & 0xFFFFFFEF | (16 * (HIWORD(*(_DWORD *)(a2 + 9)) & 1));
  a1[12] = v60;
  v61 = v60 & 0xFFFFFFDF | (32 * ((*(_DWORD *)(a2 + 9) >> 17) & 1));
  a1[12] = v61;
  LOBYTE(v61) = v61 & 0xBF | (((*(_DWORD *)(a2 + 9) & 0x40000) != 0) << 6);
  a1[12] = v61;
  LOBYTE(v38) = (*(_DWORD *)(a2 + 9) >> 12) & 0x80 | v61 & 0x7F;
  v62 = (unsigned __int8)a1[13];
  a1[12] = v38;
  v63 = v62 & 0xFFFFFFFE | (*(_DWORD *)(a2 + 9) >> 20) & 1;
  a1[13] = v63;
  v64 = v63 & 0xFFFFFFFD | (2 * ((*(_DWORD *)(a2 + 9) >> 21) & 1));
  a1[13] = v64;
  v65 = v64 & 0xFFFFFFFB | (4 * ((*(_DWORD *)(a2 + 9) >> 22) & 1));
  a1[13] = v65;
  v66 = v65 & 0xFFFFFFF7 | (8 * ((*(_DWORD *)(a2 + 9) >> 23) & 1));
  a1[13] = v66;
  a1[13] = v66 & 0xEF | (*(_DWORD *)(a2 + 9) >> 20) & 0x10;
  v67 = *(_QWORD *)(a3 + 1);
  if ( (a4 & 1) != 0 )
  {
    if ( (v67 & 0x4000000000000LL) != 0 )
    {
LABEL_15:
      v77 = *(_QWORD *)(a2 + 9) >> 60;
      a1[14] = a1[14] & 0xF0 | v77;
      v78 = a1[15];
      a1[14] = v77 | (16 * a2[17]);
      LODWORD(v77) = (unsigned __int8)a2[17] >> 4;
      a1[15] = v78 & 0xF0 | v77;
      v79 = a1[16];
      a1[15] = (*(_DWORD *)(a2 + 17) >> 4) & 0xF0 | v77;
      LODWORD(v77) = *(_DWORD *)(a2 + 17);
      a1[16] = v79 & 0xF0 | ((unsigned __int16)v77 >> 12);
      v80 = (*(_DWORD *)(a2 + 17) >> 12) & 0xF0 | ((unsigned __int16)v77 >> 12);
      v68 = 3;
      a1[16] = v80;
      if ( (*(_QWORD *)(a3 + 1) & 0x10000000000000LL) == 0 )
        goto LABEL_17;
      goto LABEL_16;
    }
LABEL_10:
    v69 = *(_DWORD *)(a2 + 9);
    v70 = a1 + 14;
    a1[14] = a1[14] & 0xF0 | (v69 >> 28);
    v71 = (*(_QWORD *)(a2 + 9) >> 28) & 0xF0 | (v69 >> 28);
    v72 = &a1[(a5 & 1) + 14];
    a1[14] = v71;
    v73 = (*(_QWORD *)(a2 + 9) >> 36) & 0xFLL;
    *v72 = v73 | *v72 & 0xF0;
    *v72 = (*(_QWORD *)(a2 + 9) >> 36) & 0xF0 | v73;
    v74 = 1;
    if ( (a5 & 1) != 0 )
      v74 = 2;
    v75 = (*(_QWORD *)(a2 + 9) >> 44) & 0xFLL;
    v70[v74] = v75 | v70[v74] & 0xF0;
    v70[v74] = (*(_QWORD *)(a2 + 9) >> 44) & 0xF0 | v75;
    v76 = (*(_QWORD *)(a2 + 9) >> 52) & 0xFLL;
    v72[2] = v76 | v72[2] & 0xF0;
    v72[2] = (*(_QWORD *)(a2 + 9) >> 52) & 0xF0 | v76;
    if ( (a5 & 1) != 0 )
      LOBYTE(v68) = 4;
    else
      LOBYTE(v68) = 3;
    goto LABEL_19;
  }
  if ( (v67 & 0x38000000000000LL) == 0 )
    goto LABEL_10;
  if ( (v67 & 0x8000000000000LL) != 0 )
    goto LABEL_15;
  v68 = 0;
  if ( (v67 & 0x10000000000000LL) != 0 )
  {
LABEL_16:
    v81 = &a1[v68];
    v82 = *(_DWORD *)(a2 + 17);
    v68 += 3;
    v81[14] = v81[14] & 0xF0 | (v82 >> 20) & 0xF;
    v81[14] = (*(_DWORD *)(a2 + 17) >> 20) & 0xF0 | (v82 >> 20) & 0xF;
    v83 = *(_DWORD *)(a2 + 17);
    v81[15] = v81[15] & 0xF0 | (v83 >> 28);
    v81[15] = (*(_QWORD *)(a2 + 17) >> 28) & 0xF0 | (v83 >> 28);
    v84 = (*(_QWORD *)(a2 + 17) >> 36) & 0xFLL;
    v81[16] = v84 | v81[16] & 0xF0;
    v81[16] = (*(_QWORD *)(a2 + 17) >> 36) & 0xF0 | v84;
  }
LABEL_17:
  if ( (v29 & 0x20000) != 0 )
  {
    v85 = &a1[v68];
    LOBYTE(v68) = v68 + 3;
    v86 = (*(_QWORD *)(a2 + 17) >> 44) & 0xFLL;
    v85[14] = v86 | v85[14] & 0xF0;
    v87 = v85[15];
    v85[14] = (*(_QWORD *)(a2 + 17) >> 44) & 0xF0 | v86;
    v88 = (*(_QWORD *)(a2 + 17) >> 52) & 0xFLL;
    v85[15] = v88 | v87 & 0xF0;
    v89 = v85[16];
    v85[15] = (*(_QWORD *)(a2 + 17) >> 52) & 0xF0 | v88;
    v90 = *(_QWORD *)(a2 + 17) >> 60;
    v85[16] = v89 & 0xF0 | v90;
    v85[16] = v90 | (16 * a2[25]);
  }
LABEL_19:
  a1[1] = v68 + 12;
  return result;
}
