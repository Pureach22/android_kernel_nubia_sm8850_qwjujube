void *__fastcall wma_convert_he_ppet(
        _BYTE *a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v11; // w9
  int v12; // w8
  char v13; // w11
  unsigned __int8 v14; // w9
  unsigned __int8 v15; // w10
  unsigned int v16; // w11
  char v17; // w12
  int v18; // w21
  _BYTE *v19; // x27
  void *result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x22
  int v30; // w23
  int v31; // w28
  int v32; // w20
  int v33; // w8
  unsigned int v34; // w10
  int v35; // w8
  unsigned int v36; // w9
  char v37; // w8
  unsigned int v38; // w26
  unsigned int v39; // w25
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w9
  int v49; // w9
  char v50; // w14
  char v51; // w12
  __int64 v52; // [xsp+8h] [xbp-8h]

  if ( a2 )
  {
    v11 = *a1 & 0xF8 | *a2 & 7;
    v12 = *a2 & 7;
    *a1 = v11;
    v13 = (8 * (a2[4] & 0xF)) | v11 & 0x87;
    v14 = a2[4] & 0xF;
    v15 = 0;
    *a1 = v13;
    if ( v14 )
    {
      do
      {
        v16 = v14;
        v17 = v14 & 1;
        v14 >>= 1;
        v15 += v17;
      }
      while ( v16 > 1 );
    }
    v18 = v15;
    v19 = a2 + 8;
    v52 = (unsigned int)(v12 + 1);
    result = (void *)qdf_trace_msg(
                       0x36u,
                       8u,
                       "%s: nss: %d ru: %d req_byte: %d",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       "wma_he_populate_ppet");
    v29 = 0;
    v30 = 0;
    v31 = 7;
    while ( !v18 )
    {
LABEL_5:
      if ( ++v29 == v52 )
        return result;
    }
    v32 = 0;
    while ( 1 )
    {
      v36 = *(_DWORD *)&v19[4 * v29];
      v37 = 6 * ((v32 + 4) & 3);
      v38 = (v36 >> v37) & 7;
      v39 = (v36 >> (v37 + 3)) & 7;
      qdf_trace_msg(
        0x36u,
        8u,
        "ppet16 (nss:%d ru:%d): %04x",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        (unsigned int)v29,
        (unsigned int)(v32 + 1),
        v38);
      result = (void *)qdf_trace_msg(
                         0x36u,
                         8u,
                         "ppet8 (nss:%d ru:%d): %04x",
                         v40,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47,
                         (unsigned int)v29,
                         (unsigned int)(v32 + 1),
                         v39);
      v48 = v38 << v31;
      v33 = v31 - 5;
      if ( v31 > 5 )
      {
        v50 = a1[v30 + 1];
        a1[v30] |= v48;
        a1[v30 + 1] = v50 | (v38 >> (8 - v31));
        v49 = v30 + 1;
        v31 -= 10;
        if ( v33 <= 5 )
          goto LABEL_9;
      }
      else
      {
        v33 = v31 + 3;
        a1[v30] |= v48;
        if ( v31 == 5 )
          v49 = v30 + 1;
        else
          v49 = v30;
        if ( v31 == 5 )
        {
          v33 = 0;
LABEL_9:
          v34 = v39 << v33;
          v35 = v33 + 3;
          a1[v49] |= v34;
          if ( v35 == 8 )
            v30 = v49 + 1;
          else
            v30 = v49;
          if ( v35 == 8 )
            v31 = 0;
          else
            v31 = v35;
          goto LABEL_15;
        }
        v31 -= 2;
        if ( v33 <= 5 )
          goto LABEL_9;
      }
      v30 = v49 + 1;
      v51 = a1[v49 + 1];
      a1[v49] |= v39 << v33;
      a1[v49 + 1] = v51 | (v39 >> (8 - v33));
LABEL_15:
      if ( v18 == ++v32 )
        goto LABEL_5;
    }
  }
  qdf_trace_msg(0x36u, 2u, "%s: PPET is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wma_convert_he_ppet");
  return qdf_mem_set(a1, 0x19u, 0);
}
