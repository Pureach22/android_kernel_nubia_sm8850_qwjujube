__int64 __fastcall wma_fill_rx_stats(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        void **a4,
        _DWORD *n,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x27
  __int64 v15; // x23
  unsigned int v16; // w5
  unsigned int v17; // w4
  unsigned int v18; // w25
  bool v19; // cc
  const void *v21; // x1
  char *v22; // x28
  unsigned int v26; // w19
  __int64 v27; // x8
  unsigned int v28; // w4
  unsigned int v29; // w6
  int v30; // w22
  const void *v31; // x1
  char *v32; // x26
  int v33; // w19
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x25
  char *v43; // x22
  unsigned __int64 v44; // x24
  const char *v45; // x2
  __int64 v46; // x11
  _DWORD *v47; // x9
  int v48; // w10
  _DWORD *v50; // x10
  int v51; // w9
  _DWORD *v52; // x11
  _DWORD *v53; // x8
  char *v54; // x14
  char *v55; // x13
  char *v56; // x14
  _DWORD *v57; // x11
  char *v58; // x12
  char *v59; // x13
  char *v60; // x22
  char *v61; // x11
  int v63; // [xsp+Ch] [xbp-34h]
  _DWORD *v64; // [xsp+10h] [xbp-30h]
  void **v65; // [xsp+18h] [xbp-28h]
  __int64 v66; // [xsp+20h] [xbp-20h]
  __int64 v67; // [xsp+28h] [xbp-18h]
  __int64 v68; // [xsp+30h] [xbp-10h]
  __int64 v69; // [xsp+38h] [xbp-8h]

  v13 = (unsigned int)a2[15];
  *(_DWORD *)(a1 + 40) = v13;
  v15 = (unsigned int)a2[16];
  *(_DWORD *)(a1 + 44) = v15;
  v16 = *n;
  v17 = 16 * v13 * a2[14];
  v18 = v16 - v17;
  v19 = v16 < v17 || v17 > 4 * *(_DWORD *)(a3 + 184);
  if ( v19 || (v21 = *(const void **)(a3 + 176)) == nullptr )
  {
    v45 = "%s: RX_MPDU_AGGR invalid arg %d, %d, %d";
LABEL_27:
    qdf_trace_msg(0x36u, 2u, v45, a6, a7, a8, a9, a10, a11, a12, a13, "wma_fill_rx_stats");
    return 16;
  }
  v22 = (char *)*a4;
  v26 = v17;
  v69 = *(_QWORD *)(a3 + 144);
  v66 = *(_QWORD *)(a3 + 160);
  qdf_mem_copy(*a4, v21, v17);
  v27 = a3;
  v28 = 16 * v15 * a2[14];
  v29 = 4 * *(_DWORD *)(a3 + 200);
  v30 = v18 - v28;
  if ( v18 < v28 || v28 > v29 || (v31 = *(const void **)(v27 + 192)) == nullptr )
  {
    v45 = "%s: RX_MCS invalid arg %d, %d, %d";
    goto LABEL_27;
  }
  v65 = a4;
  v32 = &v22[v26];
  v33 = 16 * v15 * a2[14];
  qdf_mem_copy(v32, v31, v28);
  v42 = *(_QWORD *)(a1 + 48);
  if ( !v69 || !v66 || !v42 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid arg, peer_rx %pK, wmi_rx %pK stats %pK",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wma_fill_rx_stats",
      v69,
      v66,
      *(_QWORD *)(a1 + 48));
    return 16;
  }
  v63 = v30;
  v43 = &v32[v33];
  v64 = n;
  if ( a2[14] )
  {
    v44 = 0;
    v68 = (unsigned int)(4 * v13);
    v67 = (unsigned int)(4 * v15);
    do
    {
      if ( *(_BYTE *)(a1 + 20) )
      {
        v46 = 0;
        v47 = (_DWORD *)(v69 + 28 * v44);
        v48 = v47[2];
        while ( 1 )
        {
          v42 += 272 * v46;
          if ( *(_DWORD *)v42 == -1 || *(_DWORD *)v42 == v48 )
            break;
          if ( *(unsigned __int8 *)(a1 + 20) == ++v46 )
            goto LABEL_15;
        }
        *(_DWORD *)v42 = v48;
        *(_DWORD *)(v42 + 4) = v47[1];
        *(_DWORD *)(v42 + 16) = v47[3];
        *(_DWORD *)(v42 + 20) = v47[4];
        *(_DWORD *)(v42 + 24) = v47[5];
        v50 = (_DWORD *)(v66 + 36LL * (unsigned int)(4 * v44));
        *(_DWORD *)(v42 + 28) = v47[6];
        *(_DWORD *)v43 = v50[1];
        *((_DWORD *)v43 + 1) = v50[2];
        *((_DWORD *)v43 + 2) = v50[3];
        *((_DWORD *)v43 + 3) = v50[4];
        *((_DWORD *)v43 + 5) = v50[6];
        *((_DWORD *)v43 + 6) = v50[7];
        v51 = v50[8];
        *((_QWORD *)v43 + 5) = v22;
        v52 = (_DWORD *)(v66 + 36LL * ((4 * (_DWORD)v44) | 1u));
        *((_QWORD *)v43 + 7) = v32;
        *((_DWORD *)v43 + 12) = v67;
        *((_DWORD *)v43 + 7) = v51;
        *((_DWORD *)v43 + 8) = v68;
        v53 = (_DWORD *)(v66 + 36LL * ((4 * (_DWORD)v44) | 3u));
        *(_QWORD *)(v42 + 192) = v43;
        *(_DWORD *)(v42 + 176) = 0;
        *((_DWORD *)v43 + 16) = v52[1];
        *((_DWORD *)v43 + 17) = v52[2];
        *((_DWORD *)v43 + 18) = v52[3];
        *((_DWORD *)v43 + 19) = v52[4];
        *((_DWORD *)v43 + 21) = v52[6];
        v54 = &v22[4 * v13];
        *((_DWORD *)v43 + 22) = v52[7];
        v55 = &v32[4 * v15];
        LODWORD(v52) = v52[8];
        *((_QWORD *)v43 + 13) = v54;
        v56 = &v54[4 * v13];
        *((_QWORD *)v43 + 15) = v55;
        *((_DWORD *)v43 + 23) = (_DWORD)v52;
        *((_DWORD *)v43 + 24) = v68;
        v57 = (_DWORD *)(v66 + 36LL * ((4 * (_DWORD)v44) | 2u));
        *((_DWORD *)v43 + 28) = v67;
        *(_QWORD *)(v42 + 216) = v43 + 64;
        *(_DWORD *)(v42 + 200) = 1;
        *((_DWORD *)v43 + 32) = v57[1];
        *((_DWORD *)v43 + 33) = v57[2];
        *((_DWORD *)v43 + 34) = v57[3];
        *((_DWORD *)v43 + 35) = v57[4];
        *((_DWORD *)v43 + 37) = v57[6];
        *((_DWORD *)v43 + 38) = v57[7];
        v58 = &v55[4 * v15];
        v59 = &v56[4 * v13];
        LODWORD(v57) = v57[8];
        *((_QWORD *)v43 + 21) = v56;
        v22 = &v59[4 * v13];
        *((_QWORD *)v43 + 23) = v58;
        *((_DWORD *)v43 + 39) = (_DWORD)v57;
        *((_DWORD *)v43 + 40) = v68;
        *((_DWORD *)v43 + 44) = v67;
        *(_QWORD *)(v42 + 240) = v43 + 128;
        *(_DWORD *)(v42 + 224) = 2;
        *((_DWORD *)v43 + 48) = v53[1];
        v60 = v43 + 192;
        *((_DWORD *)v60 + 1) = v53[2];
        *((_DWORD *)v60 + 2) = v53[3];
        *((_DWORD *)v60 + 3) = v53[4];
        *((_DWORD *)v60 + 5) = v53[6];
        *((_DWORD *)v60 + 6) = v53[7];
        v61 = &v58[4 * v15];
        LODWORD(v53) = v53[8];
        *((_QWORD *)v60 + 5) = v59;
        v32 = &v61[4 * v15];
        *((_QWORD *)v60 + 7) = v61;
        *((_DWORD *)v60 + 7) = (_DWORD)v53;
        *((_DWORD *)v60 + 8) = v68;
        *((_DWORD *)v60 + 12) = v67;
        *(_QWORD *)(v42 + 264) = v60;
        v43 = v60 + 64;
        *(_DWORD *)(v42 + 248) = 3;
      }
      else
      {
LABEL_15:
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: One peer RX info is dropped",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wma_fill_rx_stats");
        v22 += 4 * v68;
        v32 += 4 * v67;
      }
      ++v44;
    }
    while ( v44 < (unsigned int)a2[14] );
  }
  *v65 = v43;
  *v64 = v63;
  return 0;
}
