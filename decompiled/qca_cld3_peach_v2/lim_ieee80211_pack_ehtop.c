void *__fastcall lim_ieee80211_pack_ehtop(
        _BYTE *a1,
        unsigned __int64 a2,
        unsigned int a3,
        int a4,
        _BYTE *a5,
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned __int64 v16; // x25
  void *result; // x0
  unsigned int v22; // w8
  int v23; // w8
  unsigned int v24; // w9
  int v25; // w9
  int v26; // w9
  unsigned int v27; // w10
  char v28; // w9
  char v29; // w8
  char v30; // w10

  if ( !a1 )
    return (void *)qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: ie is null",
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     a12,
                     a13,
                     a14,
                     "lim_ieee80211_pack_ehtop");
  v16 = a2 >> 40;
  qdf_mem_set(a1, 0xDu, 0);
  *a1 = -1;
  result = qdf_mem_copy(a1 + 2, "j", 1u);
  v22 = ((unsigned int)v16 >> 8) & 7;
  if ( v22 > 4 )
  {
    v23 = 8;
    if ( !*a5 )
      goto LABEL_36;
  }
  else
  {
    v23 = dword_B08DC8[v22];
    if ( !*a5 )
      goto LABEL_36;
  }
  if ( (a5[3] & 0x20) != 0 )
  {
    v24 = a5[13] & 3;
    if ( v24 <= 1 )
    {
      if ( (a5[13] & 3) == 0 )
        goto LABEL_37;
LABEL_29:
      v24 = 1;
      goto LABEL_37;
    }
    if ( v24 == 2 )
      goto LABEL_37;
    if ( a5[15] )
    {
      v25 = (unsigned __int8)a5[15] - (unsigned __int8)a5[14];
      if ( v25 != 8 )
        goto LABEL_34;
      goto LABEL_46;
    }
LABEL_36:
    v24 = 8;
    goto LABEL_37;
  }
  if ( !(_BYTE)a4 )
  {
    if ( *(_BYTE *)a6 )
    {
      v24 = (*(_DWORD *)(a6 + 2) >> 2) & 1;
      goto LABEL_37;
    }
    goto LABEL_36;
  }
  if ( *(_BYTE *)a6 && (*(_BYTE *)(a6 + 2) & 4) == 0 )
  {
    v24 = 0;
    goto LABEL_37;
  }
  if ( BYTE1(a4) > 1u )
  {
    if ( BYTE1(a4) != 2 )
    {
      if ( BYTE1(a4) != 3 || !HIBYTE(a4) )
        goto LABEL_36;
      v25 = HIBYTE(a4) - BYTE2(a4);
LABEL_34:
      if ( v25 > 16 )
      {
        v24 = 4;
        goto LABEL_37;
      }
      goto LABEL_36;
    }
LABEL_46:
    v24 = 3;
    goto LABEL_37;
  }
  if ( !BYTE1(a4) )
    goto LABEL_29;
  if ( BYTE1(a4) != 1 )
    goto LABEL_36;
  if ( !HIBYTE(a4) )
  {
    v24 = 2;
    goto LABEL_37;
  }
  v26 = HIBYTE(a4) - BYTE2(a4);
  if ( v26 == 8 )
    goto LABEL_46;
  if ( v26 <= 16 )
    v24 = 8;
  else
    v24 = 4;
LABEL_37:
  v27 = (unsigned __int8)a1[3];
  a1[7] = v16;
  a1[4] = BYTE2(a2);
  if ( v23 == v24 )
    v28 = v27;
  else
    v28 = BYTE1(a2) & 1 | (2 * (v27 >> 1));
  a1[6] = BYTE4(a2);
  a1[5] = BYTE3(a2);
  a1[3] = BYTE1(a2) & 0x3C | v28 & 0x83 | ((((a2 >> 8) & 0x10) != 0) << 6);
  if ( (v28 & 1) != 0 )
  {
    v30 = a1[8];
    a1[10] = a3;
    a1[9] = HIBYTE(a2);
    a1[8] = v30 & 0xF8 | ((unsigned __int16)(HIDWORD(a2) >> 8) >> 8) & 7;
    if ( (a2 & 0x200) != 0 )
    {
      a1[3] = BYTE1(a2) & 0x3C | v28 & 0x83 | ((((a2 >> 8) & 0x10) != 0) << 6) | 2;
      v29 = 11;
      *(_WORD *)(a1 + 11) = a3 >> 8;
    }
    else
    {
      v29 = 9;
    }
  }
  else
  {
    v29 = 6;
  }
  a1[1] = v29;
  return result;
}
