__int64 __fastcall wlan_create_elemsubelem_fragseq(
        char a1,
        char a2,
        char a3,
        char a4,
        char a5,
        _BYTE *a6,
        unsigned __int64 a7,
        unsigned __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        _BYTE *a17,
        unsigned __int64 a18,
        unsigned __int64 *a19)
{
  __int64 v20; // x12
  char v21; // w13
  __int64 v22; // x9
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x15
  unsigned __int64 v26; // x27
  __int64 v27; // x28
  unsigned __int64 v28; // x25
  __int64 v29; // x10
  const char *v30; // x2
  unsigned __int64 v31; // x3
  unsigned __int64 v32; // x4
  const char *v33; // x2
  const char *v34; // x2
  const char *v36; // x2
  unsigned __int64 v37; // x14
  _BYTE *v39; // x21
  __int64 v40; // x9
  _BYTE *v41; // x10
  _BYTE *v42; // x19
  _BYTE *v43; // x1
  char v44; // w9
  _BYTE *v45; // x0
  int v46; // w8
  unsigned __int64 v47; // x20
  int v48; // w8
  unsigned __int64 v49; // x26
  char *v50; // x8
  int v51; // w11
  _BYTE *v52; // x26
  _BYTE *v53; // x9
  bool v54; // zf
  _BYTE *v55; // x20
  int v56; // w8
  int v57; // w10
  int v58; // w9
  unsigned int v59; // w27
  _BYTE *v60; // x19
  _BYTE *v61; // x25
  int v62; // w28
  char *v63; // x8
  __int64 v64; // x21
  __int64 v65; // x22
  _BYTE *v66; // x1
  unsigned int v67; // w9
  unsigned int v68; // w9
  size_t v69; // x2
  _BYTE *v70; // x19
  unsigned __int64 v71; // [xsp+8h] [xbp-48h]
  char v72; // [xsp+14h] [xbp-3Ch]
  __int64 v73; // [xsp+18h] [xbp-38h]
  char v75; // [xsp+24h] [xbp-2Ch]
  _BYTE *v76; // [xsp+30h] [xbp-20h]
  int v77; // [xsp+3Ch] [xbp-14h]
  int v78; // [xsp+40h] [xbp-10h]
  char v79; // [xsp+4Ch] [xbp-4h]

  if ( (a2 & 1) != 0 )
  {
    v20 = -1;
    if ( a8 > 0xFF )
    {
LABEL_3:
      v21 = 1;
      v22 = 2;
      v23 = a8;
      v24 = a8;
      goto LABEL_4;
    }
    goto LABEL_14;
  }
  if ( a3 != -1 )
  {
    a5 = -14;
    v20 = 2;
    if ( a8 > 0xFF )
      goto LABEL_3;
LABEL_14:
    v33 = "Fragmentation inapplicable for subelem/elem without elem ID ext and with payload len %zu";
LABEL_15:
    qdf_trace_msg(0x38u, 2u, v33, a9, a10, a11, a12, a13, a14, a15, a16, a8);
    return 4;
  }
  v24 = a8 - 254;
  if ( a8 <= 0xFE )
  {
    v33 = "Fragmentation inapplicable for elem with elem ID ext and post elem ID ext payload len %zu";
    goto LABEL_15;
  }
  v21 = 0;
  v23 = a8 + 1;
  a5 = -14;
  v20 = 2;
  v22 = 3;
LABEL_4:
  v25 = v23 / 0xFF;
  v26 = 2 * (v23 / 0xFF) + 0x1FFFFFFFELL;
  v27 = v26 & 0x1FFFFFFFELL;
  v28 = v24 % 0xFF;
  if ( v24 % 0xFF )
    v29 = (v26 & 0x1FFFFFFFELL) + 2;
  else
    v29 = v26 & 0x1FFFFFFFELL;
  if ( !a6 )
  {
    v34 = "Payload buff is NULL";
    goto LABEL_17;
  }
  if ( !a7 )
  {
    v36 = "Payload buff max size is 0";
    goto LABEL_21;
  }
  if ( a7 < a8 )
  {
    v30 = "Payload buff max size %zu < payload len %zu";
    v31 = a7;
    v32 = a8;
LABEL_11:
    qdf_trace_msg(0x38u, 2u, v30, a9, a10, a11, a12, a13, a14, a15, a16, v31, v32);
    return 4;
  }
  v37 = v22 + a8;
  v32 = v22 + a8 + v29;
  if ( (a1 & 1) == 0 )
  {
    if ( a17 )
    {
      v31 = a18;
      if ( a18 )
      {
        if ( v32 > a18 )
        {
          v30 = "Frag sequence buff max size %zu < frag sequence expected len %zu";
          goto LABEL_11;
        }
        goto LABEL_31;
      }
      v36 = "Frag sequence buff max size is 0";
LABEL_21:
      qdf_trace_msg(0x38u, 2u, v36, a9, a10, a11, a12, a13, a14, a15, a16);
      return 4;
    }
    v34 = "Frag sequence buff is NULL";
LABEL_17:
    qdf_trace_msg(0x38u, 2u, v34, a9, a10, a11, a12, a13, a14, a15, a16);
    return 29;
  }
  if ( v32 > a7 )
  {
    v30 = "Inline frag buff max size %zu < frag sequence expected len %zu";
    v31 = a7;
    goto LABEL_11;
  }
LABEL_31:
  if ( !a19 )
  {
    v34 = "Pointer to location of frag sequence len is NULL";
    goto LABEL_17;
  }
  v71 = v22 + a8 + v29;
  v72 = v21;
  v73 = v20;
  v75 = a4;
  v79 = a1;
  v78 = v25;
  if ( v28 )
  {
    v39 = a6;
    v40 = 255LL * (unsigned int)v25;
    if ( (a1 & 1) != 0 )
      v41 = a6 + 2;
    else
      v41 = a17 + 2;
    v42 = &v41[v40];
    v43 = &a6[v40 + 2];
    v44 = a1;
    v45 = &v42[(v26 & 0x1FFFFFFFELL) + 2];
    if ( (v44 & 1) != 0 )
    {
      v46 = (_DWORD)v43 - (_DWORD)v45;
      if ( v45 <= v43 )
        v46 = 0;
      v47 = a7;
      v48 = a7 - v37 + v46;
      v49 = v37;
      if ( a7 <= v37 )
        v48 = 0;
      qdf_mem_move(v45, v43, (unsigned int)(v48 + v28));
    }
    else
    {
      v49 = v37;
      v47 = a7;
      qdf_mem_copy(v45, v43, (unsigned int)v28);
    }
    a1 = v79;
    LOWORD(v25) = v78;
    v50 = &v42[v27];
    a7 = v47;
    a6 = v39;
    v37 = v49;
    *v50 = a5;
    v50[1] = v28;
  }
  v76 = a6;
  if ( (v25 & 0xFFFE) != 0 )
  {
    v51 = v26 & 0xFFFFFFFE;
    v52 = a6 + 2;
    if ( (a1 & 1) != 0 )
      v53 = a6 + 2;
    else
      v53 = a17 + 2;
    v54 = a7 > v37 && v28 == 0;
    v55 = &v53[v27];
    v56 = (unsigned __int16)v78;
    v57 = a7 - (_DWORD)v53 - v37;
    v58 = !v54;
    v59 = (unsigned __int16)v78 - 1;
    v60 = v55 - 2;
    v61 = v55;
    v77 = v58;
    v62 = v57 - v51 - 255 * (unsigned __int16)v78 + 510;
    do
    {
      v64 = (unsigned int)(v56 - 1);
      v65 = 255LL * v59;
      v66 = &v52[256 * v64 - v64];
      v67 = (_DWORD)v52 + 255 * v59;
      if ( &v52[v65] >= &v61[v65] )
        v67 = (_DWORD)v61 + 255 * v59;
      if ( (a1 & 1) != 0 )
      {
        v68 = v62 + v67;
        if ( v77 )
          v68 = 255;
        if ( v78 == v56 )
          v69 = v68;
        else
          v69 = 255;
        qdf_mem_move(&v55[v65], v66, v69);
      }
      else
      {
        qdf_mem_copy(&v55[v65], v66, 0xFFu);
      }
      v63 = &v60[v65];
      a1 = v79;
      v62 += 257;
      *v63 = a5;
      --v59;
      v63[1] = -1;
      v61 -= 2;
      v55 -= 2;
      v60 -= 2;
      v56 = v64;
    }
    while ( (v64 & 0xFFFE) != 0 );
  }
  if ( (a1 & 1) != 0 )
  {
    v70 = v76;
  }
  else
  {
    v70 = a17;
    qdf_mem_copy(a17 + 2, v76 + 2, 0xFFu);
  }
  *v70 = a3;
  v70[1] = -1;
  if ( (v72 & 1) == 0 )
    v70[v73] = v75;
  *a19 = v71;
  return 0;
}
