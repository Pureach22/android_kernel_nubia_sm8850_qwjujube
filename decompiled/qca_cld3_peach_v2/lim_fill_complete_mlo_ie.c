__int64 __fastcall lim_fill_complete_mlo_ie(unsigned __int16 *a1, unsigned __int16 a2, _BYTE *a3)
{
  int v3; // w18
  unsigned int v4; // w20
  unsigned __int16 *v5; // x24
  char v7; // w8
  _BYTE *v9; // x0
  _BYTE *v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char *v19; // x23
  unsigned int v20; // w4
  int v22; // w8
  unsigned int v23; // w22
  int v24; // w14
  unsigned int v25; // w9
  int v26; // w15
  __int64 v27; // x16
  char v28; // w0
  unsigned __int16 v29; // w16
  __int64 v30; // x17
  __int64 v31; // x16
  __int64 v32; // x17
  char v33; // w16
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  if ( !a1 )
    return 4;
  v4 = a2;
  v5 = a1 + 5448;
  if ( a2 > 0x101u )
    v7 = -1;
  else
    v7 = a2 - 2;
  *((_BYTE *)a1 + 12965) = v7;
  v9 = (_BYTE *)_qdf_mem_malloc(a2, "lim_fill_complete_mlo_ie", 1160);
  if ( !v9 )
    return 2;
  v10 = v9;
  qdf_mem_copy(v9, a1 + 6482, v5[1033]);
  v19 = &v10[v5[1033]];
  if ( *v5 )
  {
    qdf_mem_copy(v19, a1 + 5450, v5[1]);
    v19 += v5[1];
    if ( *v5 >= 2u )
    {
      qdf_mem_copy(v19, a1 + 5708, v5[259]);
      v19 += v5[259];
      if ( *v5 >= 3u )
      {
        qdf_mem_copy(v19, a1 + 5966, v5[517]);
        v19 += v5[517];
        if ( *v5 >= 4u )
        {
          qdf_mem_copy(v19, a1 + 6224, v5[775]);
          v19 += v5[775];
          if ( *v5 >= 5u )
          {
            qdf_mem_copy(v19, a1 + 6482, v5[1033]);
            if ( *v5 > 5u )
            {
              __break(0x5512u);
              if ( v3 )
                JUMPOUT(0x6A5CF8);
              JUMPOUT(0x68E614);
            }
            LOWORD(v19) = (_WORD)v19 + v5[1033];
          }
        }
      }
    }
  }
  *a3 = *v10;
  v20 = (unsigned __int16)((_WORD)v19 - (_WORD)v10 - 2);
  a3[1] = v10[1];
  if ( (int)v20 > (int)(v4 - 2) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid len: %u, %u",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "lim_fill_complete_mlo_ie");
    _qdf_mem_free((__int64)v10);
    return 4;
  }
  if ( (_WORD)v19 - (_WORD)v10 == 2 )
  {
    v23 = 2;
  }
  else
  {
    v22 = v20 - 1;
    a3[2] = v10[2];
    if ( v20 == 1 )
    {
      v23 = 3;
    }
    else
    {
      v24 = 3;
      v25 = 1;
      v26 = 3;
      do
      {
        if ( -16843009 * v25 <= 0x1010101 )
        {
          v31 = (unsigned __int16)v26;
          v32 = (unsigned __int16)(v26 + 1);
          v26 += 2;
          a3[v31] = -14;
          if ( v22 >= 255 )
            v33 = -1;
          else
            v33 = v22;
          a3[v32] = v33;
        }
        v27 = (unsigned __int16)v24;
        ++v25;
        ++v24;
        v28 = v10[v27];
        v29 = v26 + 1;
        v30 = (unsigned __int16)v26;
        --v22;
        ++v26;
        a3[v30] = v28;
      }
      while ( v20 > v25 );
      v23 = v29;
    }
  }
  _qdf_mem_free((__int64)v10);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: pack mlo ie %d bytes, expected to copy %d bytes",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "lim_fill_complete_mlo_ie",
    v23,
    v4);
  ((void (__fastcall *)(__int64, __int64, _BYTE *, _QWORD))qdf_trace_hex_dump)(53, 8, a3, v23);
  return 0;
}
