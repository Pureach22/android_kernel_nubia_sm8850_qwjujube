__int64 __fastcall populate_dot11f_vht_caps(
        __int64 is_24ghz_ch_freq,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  __int64 v12; // x19
  __int16 v13; // w8
  char v14; // w9
  __int16 v15; // w8
  __int64 result; // x0
  __int16 v17; // w8
  __int16 v18; // w8
  __int16 v19; // w11
  __int16 v20; // w8
  __int16 v21; // w8
  __int16 v22; // w8
  char v23; // w9
  char v24; // w9
  __int16 v25; // w8
  unsigned int v26; // w8
  char v27; // w9
  char v28; // w9
  unsigned int v29; // w9
  __int16 v30; // w11
  __int16 v31; // w11
  __int16 v32; // w11
  __int16 v33; // w11
  unsigned int v34; // w10
  __int64 v35; // x22
  __int64 v36; // x21
  unsigned int v37; // w10
  bool v38; // zf
  unsigned int v39; // w10
  __int16 v40; // w8
  unsigned int v41; // w10
  int v42; // w8
  unsigned int v43; // w9
  unsigned int v44; // w9
  int v45; // w8
  unsigned int v46; // w9
  unsigned int v47; // w9
  int v48; // w11
  unsigned int v49; // w11
  unsigned int v50; // w11
  unsigned int v51; // w11
  unsigned int v52; // w11
  __int16 v53; // w14
  __int16 v54; // w11
  __int16 v55; // w14
  __int16 v56; // w9
  int v57; // w12
  int v58; // w11
  char v59; // w10
  unsigned int v60; // w11
  int v61; // w12
  unsigned int v62; // w13
  int v63; // w17
  char v64; // w0
  int v65; // w0
  unsigned __int64 v66; // x11
  __int64 v67; // x8
  unsigned __int64 v68; // x8

  v11 = *(_QWORD *)(is_24ghz_ch_freq + 8);
  if ( !v11 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: invalid mlme cfg", a4, a5, a6, a7, a8, a9, a10, a11, "populate_dot11f_vht_caps");
    return 16;
  }
  v12 = a2 + 0x2000;
  *(_BYTE *)a3 = 1;
  v13 = *(_WORD *)(a3 + 1) & 0xFFFC | *(_BYTE *)(v11 + 2878) & 3;
  *(_WORD *)(a3 + 1) = v13;
  v14 = *(_BYTE *)(v11 + 2820);
  v15 = v13 & 0xFFF3 | (4 * (v14 & 3));
  *(_WORD *)(a3 + 1) = v15;
  if ( a2 )
  {
    if ( *(_BYTE *)(a2 + 8764) == 1 )
    {
      *(_BYTE *)a3 = 0;
      return 0;
    }
    v35 = a3;
    v36 = a2;
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284));
    if ( (is_24ghz_ch_freq & 1) != 0 )
    {
      LOWORD(v37) = *(_WORD *)(v35 + 1);
      a3 = v35;
      a2 = v36;
    }
    else
    {
      v37 = *(unsigned __int16 *)(v35 + 1);
      a2 = v36;
      a3 = v35;
      if ( *(_DWORD *)(v36 + 7176) > 2u )
      {
LABEL_13:
        if ( (*(_WORD *)(a2 + 7266) & 1) != 0 )
        {
          v37 = v37 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)(a2 + 7268) >> 4) & 1));
          *(_WORD *)(a3 + 1) = v37;
        }
        v38 = (v37 & 0xC) == 0;
        v39 = v37 & 0xFFFFFFDF | (32 * ((*(unsigned __int16 *)(a2 + 7268) >> 5) & 1));
        *(_WORD *)(a3 + 1) = v39;
        if ( !v38 )
        {
          v39 = v39 & 0xFFFFFFBF | (((*(unsigned __int16 *)(a2 + 7268) >> 6) & 1) << 6);
          *(_WORD *)(a3 + 1) = v39;
        }
        v40 = *(_WORD *)(a2 + 7266);
        if ( (v40 & 0x80) != 0 )
        {
          v39 = v39 & 0xFFFFFF7F | (((*(unsigned __int16 *)(a2 + 7268) >> 7) & 1) << 7);
          *(_WORD *)(a3 + 1) = v39;
          v40 = *(_WORD *)(a2 + 7266);
        }
        if ( (v40 & 0x300) != 0 )
        {
          v39 = v39 & 0xFFFFF8FF | ((HIBYTE(*(unsigned __int16 *)(a2 + 7268)) & 7) << 8);
          *(_WORD *)(a3 + 1) = v39;
        }
        v41 = v39 & 0xFFFFEFFF | (((*(unsigned __int16 *)(a2 + 7268) >> 12) & 1) << 12);
        v42 = *(unsigned __int8 *)(a3 + 3);
        *(_WORD *)(a3 + 1) = v41;
        v43 = *(_DWORD *)(a2 + 7268);
        if ( (v43 & 0x1000) != 0 )
        {
          v44 = v42 & 0xFFFFFFEF | HIWORD(v43) & 0x10;
          *(_BYTE *)(a3 + 3) = v44;
          v45 = *(_WORD *)(a2 + 7268) & 0xE000 | v41 & 0x1FFF;
          *(_WORD *)(a3 + 1) = *(_WORD *)(a2 + 7268) & 0xE000 | v41 & 0x1FFF;
        }
        else
        {
          v44 = v42 & 0xFFFFFFEF;
          v45 = v41;
          *(_BYTE *)(a3 + 3) = v44;
        }
        v26 = v45 & 0xFFFFF7FF | (((*(unsigned __int16 *)(a2 + 7268) >> 11) & 1) << 11);
        *(_WORD *)(a3 + 1) = v26;
        v46 = v44 & 0xFFFFFFDF | (32 * ((*(unsigned __int8 *)(a2 + 7270) >> 5) & 1));
        *(_BYTE *)(a3 + 3) = v46;
        v47 = v46 & 0xFFFFFFF8 | *(_BYTE *)(a2 + 7270) & 7;
        v48 = *(unsigned __int16 *)(a3 + 4);
        *(_BYTE *)(a3 + 3) = v47;
        v29 = v47 & 0xFFFFFFBF | (((*(unsigned __int8 *)(a2 + 7270) >> 6) & 1) << 6);
        *(_BYTE *)(a3 + 3) = v29;
        v49 = v48 & 0xFFFFFFDF | (32 * ((*(_DWORD *)(a2 + 7268) >> 28) & 1));
        *(_WORD *)(a3 + 4) = v49;
        v50 = v49 & 0xFFFFFFBF | (((*(_DWORD *)(a2 + 7268) >> 29) & 1) << 6);
        *(_WORD *)(a3 + 4) = v50;
        v51 = v50 & 0xFFFFFE7F | ((unsigned __int8)HIBYTE(*(_DWORD *)(a2 + 7268)) >> 6 << 7);
        *(_WORD *)(a3 + 4) = v51;
        v52 = v51 & 0xFFFFFFF8 | (*(_DWORD *)(a2 + 7268) >> 23) & 7;
        *(_WORD *)(a3 + 4) = v52;
        v34 = v52 & 0xFFFFFFE7 | (*(_DWORD *)(a2 + 7268) >> 23) & 0x18;
        goto LABEL_25;
      }
    }
    v37 &= 0xFFF3u;
    *(_WORD *)(a3 + 1) = v37;
    goto LABEL_13;
  }
  v17 = v15 & 0xFFEF | (16 * (*(_BYTE *)(v11 + 2821) & 1));
  *(_WORD *)(a3 + 1) = v17;
  v18 = v17 & 0xFFDF | (32 * (*(_BYTE *)(v11 + 2822) & 1));
  *(_WORD *)(a3 + 1) = v18;
  if ( 4 * (v14 & 3) )
  {
    v18 = v18 & 0xFFBF | ((*(_BYTE *)(v11 + 2823) & 1) << 6);
    *(_WORD *)(a3 + 1) = v18;
  }
  v19 = *(_WORD *)(a3 + 4);
  v20 = v18 & 0xFF7F | ((*(_BYTE *)(v11 + 2824) & 1) << 7);
  *(_WORD *)(a3 + 1) = v20;
  v21 = v20 & 0xF8FF | (*(unsigned __int8 *)(v11 + 2825) << 8);
  *(_WORD *)(a3 + 1) = v21;
  v22 = v21 & 0xEFFF | (*(unsigned __int8 *)(v11 + 2827) << 12);
  v23 = *(_BYTE *)(a3 + 3);
  *(_WORD *)(a3 + 1) = v22;
  v24 = v23 & 0xEF | (16 * *(_BYTE *)(v11 + 2872));
  *(_BYTE *)(a3 + 3) = v24;
  v25 = v22 & 0xF1FF | (*(unsigned __int8 *)(v11 + 2826) << 11);
  *(_WORD *)(a3 + 1) = v25;
  LOWORD(v26) = v25 & 0x1FFF | (*(unsigned __int8 *)(v11 + 2828) << 13);
  *(_WORD *)(a3 + 1) = v26;
  v27 = v24 & 0xDF | (32 * *(_BYTE *)(v11 + 2831));
  *(_BYTE *)(a3 + 3) = v27;
  v28 = v27 & 0xF8 | *(_BYTE *)(v11 + 2829) & 7;
  *(_BYTE *)(a3 + 3) = v28;
  LOBYTE(v29) = v28 & 0xBF | (*(_BYTE *)(v11 + 2832) << 6);
  *(_BYTE *)(a3 + 3) = v29;
  v30 = v19 & 0xFFDF | (32 * (*(_BYTE *)(v11 + 2834) & 1));
  *(_WORD *)(a3 + 4) = v30;
  v31 = v30 & 0xFFBF | ((*(_BYTE *)(v11 + 2835) & 1) << 6);
  *(_WORD *)(a3 + 4) = v31;
  v32 = v31 & 0xFFF8 | *(_BYTE *)(v11 + 2877) & 7;
  *(_WORD *)(a3 + 4) = v32;
  v33 = v32 & 0xFFE7 | (8 * (*(_BYTE *)(v11 + 2833) & 3));
  *(_WORD *)(a3 + 4) = v33;
  LOWORD(v34) = v33 & 0xFE7F | ((*(_BYTE *)(v11 + 2885) & 3) << 7);
LABEL_25:
  *(_WORD *)(a3 + 4) = v34;
  v53 = *(_WORD *)(a3 + 12);
  v54 = *(unsigned __int8 *)(v11 + 2887);
  *(_WORD *)(a3 + 8) = *(_WORD *)(a3 + 8) & 0x1FFF | (v54 << 13);
  v55 = v53 & 0xDFFF | ((*(_BYTE *)(v11 + 2886) & 1) << 13);
  *(_WORD *)(a3 + 12) = v55;
  *(_BYTE *)(a3 + 3) = v29 & 0xF7 | (8 * *(_BYTE *)(v11 + 2830));
  v56 = v54 << 13;
  v57 = *(unsigned __int16 *)(v11 + 2836);
  *(_WORD *)(a3 + 6) = v57;
  *(_WORD *)(a3 + 8) = (v54 << 13) | *(_WORD *)(v11 + 2844) & 0x1FFF;
  v58 = *(unsigned __int16 *)(v11 + 2840);
  *(_WORD *)(a3 + 10) = v58;
  *(_WORD *)(a3 + 12) = v55 & 0xE000 | *(_WORD *)(v11 + 2848) & 0x1FFF;
  if ( !a2 )
    return 0;
  if ( *(_DWORD *)(a2 + 7176) )
    v59 = 0;
  else
    v59 = *(_BYTE *)(v11 + 2870) ^ 1;
  v60 = (unsigned __int16)(-1LL << (2 * *(_BYTE *)(v12 + 443))) | v58;
  *(_WORD *)(a3 + 10) = v60;
  v61 = (unsigned __int16)(-1LL << (2 * *(_BYTE *)(v12 + 443))) | v57;
  *(_WORD *)(a3 + 6) = v61;
  v62 = *(unsigned __int8 *)(v12 + 443);
  if ( v62 <= 1 )
  {
    *(_WORD *)(a3 + 1) = v26 & 0xFF7F;
    LOBYTE(v62) = *(_BYTE *)(v12 + 443);
    if ( !(_BYTE)v62 )
      goto LABEL_46;
  }
  LOBYTE(is_24ghz_ch_freq) = 1;
  v63 = 1;
  do
  {
    if ( (v59 & 1) != 0 )
    {
      v64 = 2 * is_24ghz_ch_freq - 2;
      a2 = (v60 >> v64) & 3;
      if ( (_DWORD)a2 == 2 )
      {
        v62 = (unsigned __int16)~(3 << v64);
        v65 = (unsigned __int16)(1 << v64);
        v60 = v60 & v62 | v65;
        v61 = v61 & v62 | v65;
        *(_WORD *)(a3 + 10) = v60;
        *(_WORD *)(a3 + 6) = v61;
        LOBYTE(v62) = *(_BYTE *)(v12 + 443);
      }
    }
    is_24ghz_ch_freq = (unsigned __int8)++v63;
  }
  while ( (unsigned __int8)v63 <= (unsigned int)(unsigned __int8)v62 );
  if ( (unsigned __int8)v62 <= 2u )
  {
    v66 = (unsigned __int8)v62 - 1LL;
    if ( v66 >= 4 )
    {
LABEL_46:
      __break(0x5512u);
      return populate_dot11f_vht_operation(is_24ghz_ch_freq, a2, a3);
    }
  }
  else
  {
    v66 = 1;
  }
  *(_WORD *)(a3 + 12) = vht_supported_datarate_bw80_gi400ns[v66] & 0x1FFF | v55 & 0xE000;
  v67 = *(unsigned __int8 *)(v12 + 443);
  if ( (unsigned int)v67 > 2 )
    v68 = 1;
  else
    v68 = v67 - 1;
  if ( v68 > 3 )
    goto LABEL_46;
  result = 0;
  *(_WORD *)(a3 + 8) = vht_supported_datarate_bw80_gi400ns[v68] & 0x1FFF | v56;
  return result;
}
