__int64 __fastcall lim_fill_complete_tpe_ie(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int16 a10,
        __int64 a11,
        unsigned __int16 a12,
        char *a13)
{
  unsigned int v15; // w20
  __int64 v16; // x25
  char *v17; // x22
  char *v18; // x27
  char *v19; // x23
  __int64 v20; // x9
  unsigned int v21; // w10
  int v22; // w8
  char v23; // w10
  size_t v24; // x24
  char *v25; // x23
  int v26; // w28

  if ( !a13 )
    return 4;
  if ( a12 )
  {
    v15 = 0;
    v16 = a12;
    v17 = (char *)(a11 + 12);
    v18 = a13;
    while ( !*(v17 - 12) )
    {
      v19 = v18;
LABEL_5:
      --v16;
      v17 += 27;
      v18 = v19;
      if ( !v16 )
        goto LABEL_20;
    }
    *v18 = -61;
    v18[2] = *(v17 - 11);
    qdf_mem_copy(v18 + 3, v17 - 9, (unsigned __int8)*(v17 - 10));
    v20 = (unsigned __int8)*(v17 - 10);
    v21 = ((unsigned __int8)*(v17 - 11) >> 3) & 7;
    v22 = v20 + 3;
    v19 = &v18[v20 + 3];
    if ( v21 > 1 )
    {
      if ( v21 != 2 )
      {
        if ( v21 != 3 )
        {
LABEL_16:
          if ( v18 != (char *)-1LL )
          {
            v15 += v22;
            v18[1] = v22 - 2;
          }
          goto LABEL_5;
        }
LABEL_12:
        v23 = *(v17 - 1);
        if ( v23 )
        {
          v24 = v23 & 0xF;
          *v19 = v23;
          v25 = v19 + 1;
          v26 = v20 + (v23 & 0xF);
          qdf_mem_copy(v25, v17, v24);
          v19 = &v25[v24];
          v22 = v26 + 4;
        }
        goto LABEL_16;
      }
    }
    else if ( v21 )
    {
      goto LABEL_12;
    }
    if ( *(v17 - 1) )
    {
      v22 = v20 + 4;
      *v19++ = *(v17 - 1);
    }
    goto LABEL_16;
  }
  v15 = 0;
LABEL_20:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: pack tpe ie %d bytes, expected to copy %d bytes",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "lim_fill_complete_tpe_ie",
    v15,
    a10);
  ((void (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(53, 8, a13, v15);
  return 0;
}
