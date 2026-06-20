__int64 __fastcall wma_fill_tx_stats(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        void **a4,
        unsigned int *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x28
  char *v14; // x22
  unsigned int v15; // w5
  __int64 v16; // x27
  __int64 v17; // x20
  __int64 v18; // x21
  unsigned int v19; // w8
  unsigned int v20; // w24
  bool v21; // cc
  const void *v23; // x1
  unsigned int v25; // w26
  __int64 v26; // x4
  unsigned int v27; // w23
  const void *v28; // x1
  int v29; // w24
  unsigned int v30; // w26
  const void *v31; // x1
  int v32; // w23
  char *v33; // x24
  const void *v34; // x1
  char *v35; // x0
  int v36; // w24
  char *v37; // x26
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  __int64 v47; // x23
  int v48; // w9
  const char *v49; // x2
  char *v51; // x25
  void **v52; // x10
  char *v53; // x3
  unsigned __int64 v54; // x26
  char *v55; // x24
  __int64 v56; // x14
  unsigned __int64 v57; // x12
  int v58; // w13
  _DWORD *v60; // x13
  int v61; // w12
  _DWORD *v62; // x15
  char *v63; // x1
  _DWORD *v64; // x11
  char *v65; // x17
  int v66; // w0
  char *v67; // x2
  char *v68; // x17
  char *v69; // x3
  _DWORD *v70; // x0
  char *v71; // x25
  int v72; // w16
  char *v73; // x0
  char *v74; // x1
  char *v75; // x2
  char *v76; // x17
  char *v77; // x16
  char *v78; // x0
  char *v79; // x1
  char *v80; // x11
  unsigned int v81; // [xsp+4h] [xbp-5Ch]
  __int64 v82; // [xsp+8h] [xbp-58h]
  __int64 v83; // [xsp+10h] [xbp-50h]
  __int64 v84; // [xsp+18h] [xbp-48h]
  __int64 v85; // [xsp+20h] [xbp-40h]
  char *v86; // [xsp+28h] [xbp-38h]
  char *v87; // [xsp+30h] [xbp-30h]
  __int64 v89; // [xsp+40h] [xbp-20h]
  __int64 v92; // [xsp+58h] [xbp-8h]

  v13 = (unsigned int)a2[9];
  v14 = (char *)*a4;
  v15 = *a5;
  *(_DWORD *)(a1 + 24) = v13;
  v16 = (unsigned int)a2[10];
  *(_DWORD *)(a1 + 28) = v16;
  v17 = (unsigned int)a2[11];
  *(_DWORD *)(a1 + 32) = v17;
  v18 = (unsigned int)a2[13];
  *(_DWORD *)(a1 + 36) = v18;
  v19 = 16 * v13 * a2[8];
  v20 = v15 - v19;
  v21 = v15 < v19 || v19 > 4 * *(_DWORD *)(a3 + 88);
  if ( v21 || (v23 = *(const void **)(a3 + 80)) == nullptr )
  {
    v49 = "%s: TX_MPDU_AGGR invalid arg, %d, %d, %d";
    v26 = v19;
LABEL_24:
    qdf_trace_msg(0x36u, 2u, v49, a6, a7, a8, a9, a10, a11, a12, a13, "wma_fill_tx_stats", v26);
    return 16;
  }
  v25 = v19;
  v92 = *(_QWORD *)(a3 + 48);
  v89 = *(_QWORD *)(a3 + 64);
  qdf_mem_copy(v14, v23, v19);
  v26 = (unsigned int)(16 * v16 * a2[8]);
  v27 = v20 - v26;
  if ( v20 < (unsigned int)v26
    || (unsigned int)v26 > 4 * *(_DWORD *)(a3 + 104)
    || (v28 = *(const void **)(a3 + 96)) == nullptr )
  {
    v49 = "%s: TX_SUCC_MCS invalid arg, %d, %d, %d";
    goto LABEL_24;
  }
  v29 = 16 * v16 * a2[8];
  v87 = &v14[v25];
  qdf_mem_copy(v87, v28, (unsigned int)v26);
  v26 = (unsigned int)(16 * v17 * a2[8]);
  v30 = v27 - v26;
  if ( v27 < (unsigned int)v26
    || (unsigned int)v26 > 4 * *(_DWORD *)(a3 + 120)
    || (v31 = *(const void **)(a3 + 112)) == nullptr )
  {
    v49 = "%s: TX_FAIL_MCS invalid arg, %d, %d %d";
    goto LABEL_24;
  }
  v32 = 16 * v17 * a2[8];
  v33 = &v87[v29];
  qdf_mem_copy(v33, v31, (unsigned int)v26);
  v26 = (unsigned int)(16 * v18 * a2[8]);
  if ( v30 < (unsigned int)v26
    || (unsigned int)v26 > 4 * *(_DWORD *)(a3 + 136)
    || (v34 = *(const void **)(a3 + 128)) == nullptr )
  {
    v49 = "%s: TX_DELAY invalid arg, %d, %d, %d";
    goto LABEL_24;
  }
  v35 = &v33[v32];
  v81 = v30 - v26;
  v86 = v33;
  v36 = 16 * v18 * a2[8];
  v37 = v35;
  qdf_mem_copy(v35, v34, (unsigned int)v26);
  v46 = a1;
  v47 = *(_QWORD *)(a1 + 48);
  if ( !v92 || !v89 || !v47 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid arg, peer_tx %pK, wmi_tx %pK stats %pK",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wma_fill_tx_stats",
      v92,
      v89,
      *(_QWORD *)(a1 + 48));
    return 16;
  }
  v48 = a2[8];
  if ( (unsigned int)(4 * v48) > *(_DWORD *)(a3 + 72) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: tx stats invalid arg, %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wma_fill_tx_stats");
    return 16;
  }
  v51 = &v37[v36];
  if ( v48 )
  {
    v52 = a4;
    v53 = v37;
    v54 = 0;
    v85 = (unsigned int)(4 * v13);
    v84 = (unsigned int)(4 * v16);
    v83 = (unsigned int)(4 * v17);
    v82 = (unsigned int)(4 * v18);
    do
    {
      if ( *(_BYTE *)(v46 + 20) )
      {
        v56 = 0;
        v57 = v92 + 12 * v54;
        v58 = *(_DWORD *)(v57 + 8);
        while ( 1 )
        {
          v47 += 272 * v56;
          if ( *(_DWORD *)v47 == -1 || *(_DWORD *)v47 == v58 )
            break;
          if ( *(unsigned __int8 *)(v46 + 20) == ++v56 )
            goto LABEL_30;
        }
        *(_DWORD *)v47 = v58;
        v60 = (_DWORD *)(v89 + 40LL * (unsigned int)(4 * v54));
        *(_DWORD *)(v47 + 4) = *(_DWORD *)(v57 + 4);
        *(_DWORD *)v51 = v60[1];
        *((_DWORD *)v51 + 1) = v60[2];
        *((_DWORD *)v51 + 2) = v60[3];
        *((_DWORD *)v51 + 3) = v60[4];
        *((_DWORD *)v51 + 4) = v60[5];
        *((_DWORD *)v51 + 5) = v60[6];
        *((_DWORD *)v51 + 6) = v60[7];
        v61 = v60[8];
        *((_QWORD *)v51 + 5) = v14;
        v62 = (_DWORD *)(v89 + 40LL * ((4 * (_DWORD)v54) | 1u));
        *((_DWORD *)v51 + 12) = v84;
        *((_QWORD *)v51 + 7) = v87;
        *((_QWORD *)v51 + 9) = v86;
        v63 = &v87[4 * v16];
        v64 = (_DWORD *)(v89 + 40LL * ((4 * (_DWORD)v54) | 3u));
        *((_DWORD *)v51 + 16) = v83;
        *((_QWORD *)v51 + 11) = v53;
        *((_DWORD *)v51 + 20) = v82;
        *((_DWORD *)v51 + 7) = v61;
        *((_DWORD *)v51 + 8) = v85;
        *(_QWORD *)(v47 + 184) = v51;
        *(_DWORD *)(v47 + 176) = 0;
        *((_DWORD *)v51 + 24) = v62[1];
        *((_DWORD *)v51 + 25) = v62[2];
        *((_DWORD *)v51 + 26) = v62[3];
        *((_DWORD *)v51 + 27) = v62[4];
        *((_DWORD *)v51 + 28) = v62[5];
        *((_DWORD *)v51 + 29) = v62[6];
        v65 = &v14[4 * v13];
        *((_DWORD *)v51 + 30) = v62[7];
        v66 = v62[8];
        *((_QWORD *)v51 + 17) = v65;
        v67 = &v86[4 * v17];
        *((_DWORD *)v51 + 36) = v84;
        v68 = &v65[4 * v13];
        v69 = &v53[4 * v18];
        *((_DWORD *)v51 + 31) = v66;
        *((_DWORD *)v51 + 32) = v85;
        v70 = (_DWORD *)(v89 + 40LL * ((4 * (_DWORD)v54) | 2u));
        *((_QWORD *)v51 + 19) = v63;
        *((_QWORD *)v51 + 21) = v67;
        *((_DWORD *)v51 + 40) = v83;
        *((_QWORD *)v51 + 23) = v69;
        *((_DWORD *)v51 + 44) = v82;
        *(_QWORD *)(v47 + 208) = v51 + 96;
        *(_DWORD *)(v47 + 200) = 1;
        *((_DWORD *)v51 + 48) = v70[1];
        v71 = v51 + 192;
        *((_DWORD *)v71 + 1) = v70[2];
        *((_DWORD *)v71 + 2) = v70[3];
        *((_DWORD *)v71 + 3) = v70[4];
        *((_DWORD *)v71 + 4) = v70[5];
        *((_DWORD *)v71 + 5) = v70[6];
        *((_DWORD *)v71 + 6) = v70[7];
        v72 = v70[8];
        v73 = &v63[4 * v16];
        v74 = &v67[4 * v17];
        v75 = &v69[4 * v18];
        *((_QWORD *)v71 + 5) = v68;
        v76 = &v68[4 * v13];
        *((_DWORD *)v71 + 7) = v72;
        *((_DWORD *)v71 + 8) = v85;
        v14 = &v76[4 * v13];
        *((_DWORD *)v71 + 12) = v84;
        *((_QWORD *)v71 + 7) = v73;
        *((_QWORD *)v71 + 9) = v74;
        *((_DWORD *)v71 + 16) = v83;
        *((_QWORD *)v71 + 11) = v75;
        *((_DWORD *)v71 + 20) = v82;
        *(_QWORD *)(v47 + 232) = v71;
        *(_DWORD *)(v47 + 224) = 2;
        *((_DWORD *)v71 + 24) = v64[1];
        *((_DWORD *)v71 + 25) = v64[2];
        *((_DWORD *)v71 + 26) = v64[3];
        *((_DWORD *)v71 + 27) = v64[4];
        *((_DWORD *)v71 + 28) = v64[5];
        *((_DWORD *)v71 + 29) = v64[6];
        *((_DWORD *)v71 + 30) = v64[7];
        v77 = &v73[4 * v16];
        v78 = &v74[4 * v17];
        LODWORD(v64) = v64[8];
        v79 = &v75[4 * v18];
        *((_QWORD *)v71 + 17) = v76;
        *((_DWORD *)v71 + 36) = v84;
        v53 = &v79[4 * v18];
        *((_DWORD *)v71 + 31) = (_DWORD)v64;
        *((_DWORD *)v71 + 32) = v85;
        v80 = v71 + 96;
        *((_QWORD *)v71 + 19) = v77;
        *((_QWORD *)v71 + 21) = v78;
        *((_DWORD *)v71 + 40) = v83;
        *((_QWORD *)v71 + 23) = v79;
        *((_DWORD *)v71 + 44) = v82;
        v51 = v71 + 192;
        *(_QWORD *)(v47 + 256) = v80;
        *(_DWORD *)(v47 + 248) = 3;
        v86 = &v78[4 * v17];
        v87 = &v77[4 * v16];
      }
      else
      {
LABEL_30:
        v55 = v53;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: One peer TX info is dropped",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wma_fill_tx_stats");
        v52 = a4;
        v46 = a1;
        v14 += 4 * v85;
        v53 = &v55[4 * v82];
        v86 += 4 * v83;
        v87 += 4 * v84;
      }
      ++v54;
    }
    while ( v54 < (unsigned int)a2[8] );
  }
  else
  {
    v52 = a4;
  }
  *v52 = v51;
  *a5 = v81;
  return 0;
}
