bool __fastcall lim_decrypt_auth_frame(int a1, const void *a2, char *a3, _BYTE *a4, unsigned int a5, int a6)
{
  unsigned __int16 v8; // w20
  int v11; // w24
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 i; // x8
  _BYTE *v21; // x9
  char v22; // w10
  unsigned __int16 v23; // w8
  unsigned __int16 v24; // w10
  __int64 j; // x11
  char v26; // w14
  int v27; // w8
  int v28; // w9
  char *v29; // x10
  _BYTE *v30; // x11
  char v31; // w14
  char v32; // t1
  int v33; // w12
  char v34; // w13
  int v35; // w8
  __int16 v36; // w9
  unsigned int v37; // w12
  unsigned __int8 *v38; // x11
  int v39; // t1
  unsigned int v40; // w12
  unsigned int v41; // w12
  unsigned int v42; // w12
  unsigned int v43; // w12
  unsigned int v44; // w12
  unsigned int v45; // w12
  unsigned int v46; // w12
  unsigned int v47; // w12
  unsigned int v48; // w22
  __int64 v49; // x23
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _BYTE *v58; // x24
  _BOOL4 v59; // w20
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  _BYTE *v76; // x19
  _QWORD v78[2]; // [xsp+0h] [xbp-120h] BYREF
  _BYTE s[258]; // [xsp+16h] [xbp-10Ah] BYREF
  __int64 v80; // [xsp+118h] [xbp-8h]

  v8 = a6;
  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = a6;
  v78[0] = 0;
  v78[1] = 0;
  qdf_mem_copy(v78, a3, 3u);
  qdf_mem_copy((char *)v78 + 3, a2, a5);
  memset(s, 0, sizeof(s));
  for ( i = 0; i != 256; i += 2 )
  {
    v21 = &s[i];
    v22 = i | 1;
    v21[2] = i;
    v21[3] = v22;
  }
  v23 = 0;
  v24 = 0;
  for ( j = 2; j != 258; ++j )
  {
    v26 = s[j];
    if ( v23 < 0x10u )
      v24 = (unsigned __int8)(v26 + v24 + *((_BYTE *)v78 + v23));
    s[j] = s[v24 + 2];
    if ( a5 + 3 > (unsigned __int16)(v23 + 1) )
      ++v23;
    else
      v23 = 0;
    s[v24 + 2] = v26;
  }
  if ( v8 )
  {
    v27 = 0;
    v28 = 0;
    v29 = a3 + 4;
    v30 = a4;
    do
    {
      v33 = (unsigned __int8)s[(unsigned __int8)++v28 + 2];
      v27 += v33;
      v34 = s[(unsigned __int8)v27 + 2];
      s[(unsigned __int8)v28 + 2] = v34;
      s[(unsigned __int8)v27 + 2] = v33;
      if ( v29 )
      {
        v32 = *v29++;
        v31 = v32;
      }
      else
      {
        v31 = 0;
      }
      --v11;
      *v30++ = v31 ^ s[(unsigned __int8)(v34 + v33) + 2];
    }
    while ( (_WORD)v11 );
    v35 = v8 - 4;
    if ( v8 == 4 )
    {
      v48 = 0;
      goto LABEL_48;
    }
    v36 = v8 - 4;
  }
  else
  {
    v35 = -4;
    v36 = -4;
  }
  v37 = -1;
  v38 = a4;
  do
  {
    v39 = *v38++;
    --v36;
    v40 = v37 ^ v39;
    if ( (v40 & 1) != 0 )
      v41 = (v40 >> 1) ^ 0xEDB88320;
    else
      v41 = v40 >> 1;
    if ( (v41 & 1) != 0 )
      v42 = (v41 >> 1) ^ 0xEDB88320;
    else
      v42 = v41 >> 1;
    if ( (v42 & 1) != 0 )
      v43 = (v42 >> 1) ^ 0xEDB88320;
    else
      v43 = v42 >> 1;
    if ( (v43 & 1) != 0 )
      v44 = (v43 >> 1) ^ 0xEDB88320;
    else
      v44 = v43 >> 1;
    if ( (v44 & 1) != 0 )
      v45 = (v44 >> 1) ^ 0xEDB88320;
    else
      v45 = v44 >> 1;
    if ( (v45 & 1) != 0 )
      v46 = (v45 >> 1) ^ 0xEDB88320;
    else
      v46 = v45 >> 1;
    if ( (v46 & 1) != 0 )
      v47 = (v46 >> 1) ^ 0xEDB88320;
    else
      v47 = v46 >> 1;
    if ( (v47 & 1) != 0 )
      v37 = (v47 >> 1) ^ 0xEDB88320;
    else
      v37 = v47 >> 1;
  }
  while ( v36 );
  v48 = ~v37;
LABEL_48:
  v49 = v35;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: computed ICV%d[%x], rxed ICV%d[%x]",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "lim_decrypt_auth_frame",
    0,
    (unsigned __int8)v48,
    0,
    (unsigned __int8)a4[v35]);
  if ( (unsigned __int8)a4[v49] != (unsigned __int8)v48 )
    goto LABEL_52;
  v58 = &a4[v49];
  v59 = 1;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: computed ICV%d[%x], rxed ICV%d[%x]",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "lim_decrypt_auth_frame",
    1,
    BYTE1(v48),
    1,
    (unsigned __int8)a4[v49 + 1]);
  if ( (unsigned __int8)a4[v49 + 1] == BYTE1(v48) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: computed ICV%d[%x], rxed ICV%d[%x]",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "lim_decrypt_auth_frame",
      2,
      BYTE2(v48),
      2,
      (unsigned __int8)v58[2]);
    if ( (unsigned __int8)v58[2] == BYTE2(v48) )
    {
      v76 = &a4[v49];
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: computed ICV%d[%x], rxed ICV%d[%x]",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "lim_decrypt_auth_frame",
        3,
        HIBYTE(v48),
        3,
        (unsigned __int8)v76[3]);
      v59 = (unsigned __int8)v76[3] != HIBYTE(v48);
      goto LABEL_53;
    }
LABEL_52:
    v59 = 1;
  }
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return v59;
}
