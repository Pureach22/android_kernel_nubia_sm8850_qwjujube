__int64 __fastcall populate_disallowed_mode_bmap(
        __int64 result,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v13; // x20
  __int64 v14; // x4
  int v15; // w24
  __int64 v16; // x25
  int v17; // w8
  unsigned int v18; // w8
  unsigned int v19; // w8
  int v20; // w8

  if ( !result )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: Buffer pointer is NULL",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "populate_disallowed_mode_bmap");
  if ( *(_DWORD *)(a2 + 88) >= 5u )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: invalid num_disallow_mode_comb %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "populate_disallowed_mode_bmap");
  *a3 = 8;
  if ( *(_DWORD *)(a2 + 88) )
  {
    v13 = (_DWORD *)result;
    v14 = 0;
    v15 = 0;
    v16 = a2 + 92;
    do
    {
      *v13 = *(unsigned __int16 *)a3;
      v13[1] = *(_DWORD *)v16;
      v17 = *(_DWORD *)(v16 + 4);
      v13[2] = v17 & 0xFFFFFF00;
      v18 = v17 & 0xFFFF0000 | *(unsigned __int8 *)(v16 + 4);
      v13[2] = v18;
      v19 = v18 & 0xFF0000FF | (*(unsigned __int8 *)(v16 + 5) << 8);
      v13[2] = v19;
      v20 = (unsigned __int16)v19 | (*(unsigned __int8 *)(v16 + 6) << 16);
      v13[2] = v20;
      v13[2] = v20 | (*(unsigned __int8 *)(v16 + 7) << 24);
      result = qdf_trace_msg(
                 0x31u,
                 8u,
                 "%s: entry[%d]: disallowed_mode %d ieee_link_id_comb 0x%x",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "populate_disallowed_mode_bmap",
                 v14);
      ++v15;
      v13 += 3;
      v14 = (unsigned __int8)v15;
      v16 += 8;
    }
    while ( *(_DWORD *)(a2 + 88) > (unsigned int)(unsigned __int8)v15 );
  }
  return result;
}
