__int64 __fastcall lim_populate_eht_mcs_set(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v17; // x20
  int v19; // w19
  unsigned int max_bw; // w0
  int v22; // w9
  char is_dnw_in_progress; // w0
  const char *v24; // x2
  __int64 v26; // x8
  __int64 v27; // x9
  int v28; // w19
  __int64 v29; // x10
  __int64 v30; // x10
  unsigned int v31; // w11
  unsigned __int64 v32; // x11
  unsigned __int64 v33; // x11
  __int64 v34; // x12
  unsigned __int64 v35; // x11
  unsigned __int64 v36; // x11
  unsigned int v37; // w12
  unsigned __int64 v38; // x11
  unsigned __int64 v39; // x11
  __int64 v40; // x12
  unsigned __int64 v41; // x11
  unsigned __int64 v42; // x11
  __int64 v43; // x12
  unsigned __int64 v44; // x11
  unsigned __int64 v45; // x11
  __int64 v46; // x12
  unsigned __int64 v47; // x11
  unsigned __int64 v48; // x11
  unsigned int v49; // w12
  unsigned __int64 v50; // x11
  __int64 v51; // x9
  unsigned int v52; // w10
  unsigned int v53; // w11
  _QWORD *v54; // x10
  unsigned __int64 v55; // x12
  unsigned int v56; // w12
  int v57; // w11
  __int64 v58; // x12
  int v59; // w11
  __int64 v60; // x12
  int v61; // w11
  unsigned int v62; // w12
  unsigned int v63; // w11
  __int64 v64; // x12
  __int64 v65; // x10
  _QWORD *v66; // x10
  __int64 v67; // x11
  int v68; // w13
  __int64 v69; // x11
  int v70; // w13
  unsigned int v71; // w11
  unsigned int v72; // w12
  unsigned int v73; // w13
  unsigned int v74; // w11
  unsigned int v75; // w12
  __int64 v76; // x13
  unsigned int v77; // w11
  unsigned __int64 v78; // x13
  unsigned int v79; // w10
  _DWORD *v80; // x11
  unsigned int v81; // w12
  unsigned __int64 v82; // x10
  unsigned int v83; // w12
  unsigned __int64 v84; // x10
  unsigned int v85; // w12
  unsigned __int64 v86; // x10
  unsigned int v87; // w12
  unsigned __int64 v88; // x10
  unsigned int v89; // w12
  unsigned int v90; // w11
  unsigned __int64 v91; // x10
  unsigned __int64 v92; // x9

  if ( !a3 || !*(_BYTE *)a3 )
  {
    v24 = "%s: peer not eht capable or eht_caps NULL";
LABEL_16:
    qdf_trace_msg(0x35u, 8u, v24, a7, a8, a9, a10, a11, a12, a13, a14, "lim_populate_eht_mcs_set");
    return 0;
  }
  if ( !a4 || (*(_BYTE *)(a4 + 10071) & 1) == 0 )
  {
    v24 = "%s: session not eht capable";
    goto LABEL_16;
  }
  v17 = a1 + 20480;
  if ( !a1 )
    goto LABEL_21;
  v19 = a5;
  max_bw = wlan_mlme_get_max_bw();
  v22 = *(_DWORD *)(a4 + 7036);
  if ( !v22 )
  {
    a5 = v19;
    if ( v19 != 2 || max_bw <= 2 )
      goto LABEL_21;
LABEL_20:
    qdf_trace_msg(0x35u, 8u, "%s: bw is %d", a7, a8, a9, a10, a11, a12, a13, a14, "lim_populate_eht_mcs_set", 3);
    v26 = a2;
    v27 = a3;
LABEL_63:
    v66 = (_QWORD *)(v17 + 1693);
    v67 = (*(_QWORD *)(v27 + 17) >> 40) & 0xFLL;
    if ( (unsigned int)v67 >= ((unsigned int)(*(_QWORD *)(v17 + 1693) >> 40) & 0xF) )
      LOBYTE(v67) = ((unsigned __int16)WORD2(*(_QWORD *)(v17 + 1693)) >> 8) & 0xF;
    v68 = *(_DWORD *)(v26 + 70) & 0xFFFF0FFF | ((v67 & 0xF) << 12);
    *(_DWORD *)(v26 + 70) = v68;
    v69 = (*(_QWORD *)(v27 + 17) >> 36) & 0xFLL;
    if ( (unsigned int)v69 >= ((unsigned int)(*v66 >> 36) & 0xF) )
      LOBYTE(v69) = (*v66 >> 36) & 0xF;
    v70 = v68 & 0xFFFFF0FF | ((v69 & 0xF) << 8);
    *(_DWORD *)(v26 + 70) = v70;
    v71 = *(_DWORD *)(v27 + 21) & 0xF;
    v72 = *(_DWORD *)(v17 + 1697) & 0xF;
    if ( v71 >= v72 )
      LOBYTE(v71) = v72;
    v73 = v70 & 0xFFFFFF0F | (16 * (v71 & 0xF));
    *(_DWORD *)(v26 + 70) = v73;
    v74 = *(_DWORD *)(v27 + 17) >> 28;
    if ( v74 >= *(_DWORD *)v66 >> 28 )
      v74 = *(_DWORD *)v66 >> 28;
    v75 = v73 & 0xFFFFFFF0;
    v76 = *(_QWORD *)(v26 + 62);
    *(_DWORD *)(v26 + 70) = v75 | v74;
    v77 = *(_BYTE *)(v27 + 20) & 0xF;
    if ( v77 >= (*(_BYTE *)(v17 + 1696) & 0xFu) )
      LOBYTE(v77) = *(_BYTE *)(v17 + 1696) & 0xF;
    v78 = v76 & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)(unsigned __int8)v77 << 60);
    *(_QWORD *)(v26 + 62) = v78;
    v79 = (*(_DWORD *)v66 >> 20) & 0xF;
    if ( ((*(_DWORD *)(v27 + 17) >> 20) & 0xFu) < v79 )
      LOBYTE(v79) = (*(_DWORD *)(v27 + 17) >> 20) & 0xF;
    *(_QWORD *)(v26 + 62) = v78 & 0xF0FFFFFFFFFFFFFFLL | ((unsigned __int64)(v79 & 0xF) << 56);
    goto LABEL_76;
  }
  a5 = v19;
  if ( v19 == 2 && v22 == 2 && max_bw > 2 )
    goto LABEL_20;
  if ( (v22 | 2) == 3 && *(_DWORD *)(a4 + 7176) != v19 )
  {
    is_dnw_in_progress = wlan_is_dnw_in_progress(*(_QWORD *)(a1 + 21632), *(unsigned __int8 *)(a4 + 10));
    a5 = v19;
    if ( (is_dnw_in_progress & 1) != 0 )
      a5 = *(_DWORD *)(a4 + 7176);
  }
LABEL_21:
  v28 = a5;
  qdf_trace_msg(0x35u, 8u, "%s: bw is %d", a7, a8, a9, a10, a11, a12, a13, a14, "lim_populate_eht_mcs_set");
  if ( v28 > 2 )
  {
    v26 = a2;
    v27 = a3;
    if ( v28 != 3 )
    {
      if ( v28 != 7 )
        return 0;
      v53 = *(_BYTE *)(v17 + 1701) & 0xF;
      if ( (*(_BYTE *)(a3 + 25) & 0xFu) < v53 )
        LOBYTE(v53) = *(_BYTE *)(a3 + 25) & 0xF;
      v54 = (_QWORD *)(v17 + 1693);
      *(_BYTE *)(a2 + 74) = *(_BYTE *)(a2 + 74) & 0xF | (16 * (v53 & 0xF));
      v55 = *(_QWORD *)(a3 + 17) >> 60;
      if ( v55 >= *(_QWORD *)(v17 + 1693) >> 60 )
        v55 = *(_QWORD *)(v17 + 1693) >> 60;
      *(_BYTE *)(a2 + 74) = v55 & 0xF | (16 * (v53 & 0xF));
      v56 = *(_BYTE *)(v17 + 1700) & 0xF;
      if ( (*(_BYTE *)(a3 + 24) & 0xFu) < v56 )
        LOBYTE(v56) = *(_BYTE *)(a3 + 24) & 0xF;
      v57 = *(_DWORD *)(a2 + 70) & 0xFFFFFFF | ((unsigned __int8)v56 << 28);
      *(_DWORD *)(a2 + 70) = v57;
      v58 = (*(_QWORD *)(a3 + 17) >> 52) & 0xFLL;
      if ( (unsigned int)v58 >= ((unsigned int)(*v54 >> 52) & 0xF) )
        LOBYTE(v58) = (*v54 >> 52) & 0xF;
      v59 = v57 & 0xF0FFFFFF | ((v58 & 0xF) << 24);
      *(_DWORD *)(a2 + 70) = v59;
      v60 = (*(_QWORD *)(a3 + 17) >> 44) & 0xFLL;
      if ( (unsigned int)v60 >= ((unsigned int)(*v54 >> 44) & 0xF) )
        LOBYTE(v60) = (*v54 >> 44) & 0xF;
      v61 = v59 & 0xFFF0FFFF | ((v60 & 0xF) << 16);
      *(_DWORD *)(a2 + 70) = v61;
      v62 = *(_WORD *)(a3 + 23) & 0xF;
      if ( v62 >= (*(_WORD *)(v17 + 1699) & 0xFu) )
        LOBYTE(v62) = *(_WORD *)(v17 + 1699) & 0xF;
      v63 = v61 & 0xFF0FFFFF | ((v62 & 0xF) << 20);
      *(_DWORD *)(a2 + 70) = v63;
      v64 = (*(_QWORD *)(a3 + 17) >> 44) & 0xFLL;
      if ( (unsigned int)v64 >= ((unsigned int)(*v54 >> 44) & 0xF) )
        LOBYTE(v64) = (*v54 >> 44) & 0xF;
      *(_DWORD *)(a2 + 70) = v63 & 0xFFF0FFFF | ((v64 & 0xF) << 16);
      v65 = (*v54 >> 44) & 0xFLL;
      if ( ((unsigned int)(*(_QWORD *)(a3 + 17) >> 44) & 0xF) < (unsigned int)v65 )
        LOBYTE(v65) = (*(_QWORD *)(a3 + 17) >> 44) & 0xF;
      *(_DWORD *)(a2 + 70) = v63 & 0xFFF0FFFF | ((v65 & 0xF) << 16);
    }
    goto LABEL_63;
  }
  v27 = a3;
  v26 = a2;
  if ( (unsigned int)(v28 - 1) >= 2 )
  {
    if ( !v28 )
    {
      v29 = 22156;
      if ( (a6 & 1) != 0 )
        v29 = 22064;
      v30 = a1 + v29;
      v31 = *(_BYTE *)(a3 + 16) & 0xF;
      if ( v31 >= (*(_BYTE *)(v30 + 16) & 0xFu) )
        v31 = *(_BYTE *)(v30 + 16) & 0xF;
      v32 = *(_QWORD *)(a2 + 62) & 0xFFFFFFFF0FFFFFFFLL | (v31 << 28);
      *(_QWORD *)(a2 + 62) = v32;
      v33 = v32 & 0xFFFFFFFFF0FFFFFFLL;
      v34 = (*(_QWORD *)(a3 + 9) >> 52) & 0xFLL;
      if ( (unsigned int)v34 >= ((unsigned int)(*(_QWORD *)(v30 + 9) >> 52) & 0xF) )
        LODWORD(v34) = (*(_QWORD *)(v30 + 9) >> 52) & 0xF;
      v35 = v33 | (unsigned int)((_DWORD)v34 << 24);
      *(_QWORD *)(a2 + 62) = v35;
      v36 = v35 & 0xFFFFFFFFFF0FFFFFLL;
      v37 = *(_WORD *)(a3 + 15) & 0xF;
      if ( v37 >= (*(_WORD *)(v30 + 15) & 0xFu) )
        v37 = *(_WORD *)(v30 + 15) & 0xF;
      v38 = v36 | (v37 << 20);
      *(_QWORD *)(a2 + 62) = v38;
      v39 = v38 & 0xFFFFFFFFFFF0FFFFLL;
      v40 = (*(_QWORD *)(a3 + 9) >> 44) & 0xFLL;
      if ( (unsigned int)v40 >= ((unsigned int)(*(_QWORD *)(v30 + 9) >> 44) & 0xF) )
        LODWORD(v40) = (*(_QWORD *)(v30 + 9) >> 44) & 0xF;
      v41 = v39 | (unsigned int)((_DWORD)v40 << 16);
      *(_QWORD *)(a2 + 62) = v41;
      v42 = v41 & 0xFFFFFFFFFFFF0FFFLL;
      v43 = (*(_QWORD *)(a3 + 9) >> 40) & 0xFLL;
      if ( (unsigned int)v43 >= ((unsigned int)(*(_QWORD *)(v30 + 9) >> 40) & 0xF) )
        LODWORD(v43) = (*(_QWORD *)(v30 + 9) >> 40) & 0xF;
      v44 = v42 | (unsigned int)((_DWORD)v43 << 12);
      *(_QWORD *)(a2 + 62) = v44;
      v45 = v44 & 0xFFFFFFFFFFFFF0FFLL;
      v46 = (*(_QWORD *)(a3 + 9) >> 36) & 0xFLL;
      if ( (unsigned int)v46 >= ((unsigned int)(*(_QWORD *)(v30 + 9) >> 36) & 0xF) )
        LODWORD(v46) = (*(_QWORD *)(v30 + 9) >> 36) & 0xF;
      v47 = v45 | (unsigned int)((_DWORD)v46 << 8);
      *(_QWORD *)(a2 + 62) = v47;
      v48 = v47 & 0xFFFFFFFFFFFFFF0FLL;
      v49 = *(_DWORD *)(a3 + 13) & 0xF;
      if ( v49 >= (*(_DWORD *)(v30 + 13) & 0xFu) )
        v49 = *(_DWORD *)(v30 + 13) & 0xF;
      v50 = v48 | (16 * v49);
      *(_QWORD *)(a2 + 62) = v50;
      LODWORD(v51) = *(_DWORD *)(a3 + 9) >> 28;
      v52 = *(_DWORD *)(v30 + 9) >> 28;
      if ( (unsigned int)v51 >= v52 )
        v51 = v52;
      else
        v51 = (unsigned int)v51;
      *(_QWORD *)(a2 + 62) = v50 & 0xFFFFFFFFFFFFFFF0LL | v51;
    }
    return 0;
  }
LABEL_76:
  v80 = (_DWORD *)(v17 + 1693);
  v81 = *(_WORD *)(v17 + 1695) & 0xF;
  if ( (*(_WORD *)(v27 + 19) & 0xFu) < v81 )
    LOBYTE(v81) = *(_WORD *)(v27 + 19) & 0xF;
  v82 = *(_QWORD *)(v26 + 62) & 0xFF0FFFFFFFFFFFFFLL | ((unsigned __int64)(v81 & 0xF) << 52);
  *(_QWORD *)(v26 + 62) = v82;
  v83 = (unsigned __int16)*(_DWORD *)(v27 + 17) >> 12;
  if ( v83 >= (unsigned __int16)*v80 >> 12 )
    LOBYTE(v83) = (unsigned __int16)*v80 >> 12;
  v84 = v82 & 0xFFF0FFFFFFFFFFFFLL | ((unsigned __int64)(v83 & 0xF) << 48);
  *(_QWORD *)(v26 + 62) = v84;
  v85 = (*(_DWORD *)(v27 + 17) >> 8) & 0xF;
  if ( v85 >= ((*v80 >> 8) & 0xFu) )
    LOBYTE(v85) = BYTE1(*v80) & 0xF;
  v86 = v84 & 0xFFFF0FFFFFFFFFFFLL | ((unsigned __int64)(v85 & 0xF) << 44);
  *(_QWORD *)(v26 + 62) = v86;
  v87 = (unsigned __int8)*(_DWORD *)(v27 + 17) >> 4;
  if ( v87 >= (unsigned __int8)*v80 >> 4 )
    LOBYTE(v87) = (unsigned __int8)*v80 >> 4;
  v88 = v86 & 0xFFFFF0FFFFFFFFFFLL | ((unsigned __int64)(v87 & 0xF) << 40);
  *(_QWORD *)(v26 + 62) = v88;
  v89 = *(_DWORD *)(v27 + 17) & 0xF;
  v90 = *v80 & 0xF;
  if ( v89 < v90 )
    LOBYTE(v90) = v89;
  v91 = v88 & 0xFFFFFF0FFFFFFFFFLL | ((unsigned __int64)(v90 & 0xF) << 36);
  *(_QWORD *)(v26 + 62) = v91;
  v92 = *(_QWORD *)(v27 + 9) >> 60;
  if ( v92 >= *(_QWORD *)(v17 + 1685) >> 60 )
    v92 = *(_QWORD *)(v17 + 1685) >> 60;
  *(_QWORD *)(v26 + 62) = v91 & 0xFFFFFFF0FFFFFFFFLL | ((v92 & 0xF) << 32);
  return 0;
}
