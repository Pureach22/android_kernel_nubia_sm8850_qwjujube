__int64 __fastcall dp_rx_refill_buff_pool_enqueue(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x23
  unsigned int v3; // w24
  unsigned int v4; // w8
  unsigned __int16 v5; // w25
  __int64 v6; // x20
  unsigned __int16 *v7; // x27
  int v8; // w28
  int v9; // w26
  __int64 v10; // x22
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int16 v13; // [xsp+8h] [xbp-8h]

  if ( !result )
    return result;
  v1 = result;
  v2 = result + 18800;
  if ( *(_BYTE *)(result + 18800) != 1 )
    return result;
  v3 = *(unsigned __int16 *)(result + 18802);
  v4 = *(unsigned __int16 *)(result + 18804);
  if ( v4 <= v3 )
  {
    v5 = v4 + *(_WORD *)(result + 18816) + ~(_WORD)v3;
    if ( v5 )
      goto LABEL_5;
  }
  else
  {
    v5 = v4 + ~(_WORD)v3;
    if ( v5 )
    {
LABEL_5:
      v6 = *(_QWORD *)(result + 24);
      v7 = (unsigned __int16 *)(result + 12442);
      v13 = 0;
      while ( 1 )
      {
        v8 = 0;
        if ( (v5 & 0xFFC0) != 0 )
          v9 = 64;
        else
          v9 = v5;
        do
        {
          while ( 1 )
          {
            result = _qdf_nbuf_alloc(
                       v6,
                       *v7,
                       0,
                       *(unsigned __int8 *)(v1 + 12444),
                       0,
                       "dp_rx_refill_buff_pool_enqueue",
                       164);
            if ( result )
              break;
LABEL_13:
            if ( !--v9 )
              goto LABEL_16;
          }
          v10 = result;
          result = qdf_nbuf_map_nbytes_single_0(v6, result, *v7);
          if ( !(_DWORD)result )
          {
            ++v8;
            *(_QWORD *)(*(_QWORD *)(v1 + 18824) + 8LL * (unsigned __int16)v3) = v10;
            LOWORD(v3) = (*(_WORD *)(v2 + 16) - 1) & (v3 + 1);
            goto LABEL_13;
          }
          result = _qdf_nbuf_free(v10);
          --v9;
        }
        while ( v9 );
LABEL_16:
        __dsb(0xEu);
        if ( v8 )
        {
          v5 -= v8;
          *(_WORD *)(v2 + 2) = v3;
          v13 += v8;
        }
        if ( !v5 )
        {
          v11 = v13;
          v12 = *(_QWORD *)(v1 + 18808);
          if ( v12 )
            goto LABEL_19;
          return result;
        }
      }
    }
  }
  v11 = 0;
  v12 = *(_QWORD *)(result + 18808);
  if ( v12 )
LABEL_19:
    *(_QWORD *)(v12 + 93472) += v11;
  return result;
}
