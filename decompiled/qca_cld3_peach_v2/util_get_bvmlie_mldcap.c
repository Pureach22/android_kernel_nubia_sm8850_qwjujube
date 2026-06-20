__int64 __fastcall util_get_bvmlie_mldcap(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _BYTE *a3,
        _WORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  unsigned int v14; // w22
  unsigned __int8 *v15; // x23
  unsigned int v19; // w14
  __int64 v20; // x11
  _BYTE *v21; // x9
  _WORD *v22; // x10
  unsigned __int64 v23; // x13

  result = 29;
  if ( !a1 || !a2 || !a3 || !a4 )
    return result;
  *a3 = 0;
  *a4 = 0;
  if ( a2 < 5 || *a1 != 255 || a1[2] != 107 )
    return 4;
  v14 = *(unsigned __int16 *)(a1 + 3);
  if ( (v14 & 7) != 0 )
    return 11;
  v15 = a1;
  if ( (unsigned int)util_validate_bv_mlie_min_seq_len(a2, a5, a6, a7, a8, a9, a10, a11, a12) )
    return 4;
  v19 = v14 >> 4;
  if ( ((v14 >> 4) & 1) != 0 )
  {
    if ( a2 < 0xD )
      return 27;
    v23 = a2;
    v21 = a3;
    v22 = a4;
    v20 = 8;
  }
  else
  {
    v20 = 7;
    v21 = a3;
    v22 = a4;
    v23 = a2;
  }
  if ( (v19 & 2) != 0 )
  {
    if ( v20 + 6 > v23 )
      return 27;
    ++v20;
  }
  if ( (v19 & 4) != 0 )
  {
    if ( v20 + 7 <= v23 )
    {
      v20 += 2;
      goto LABEL_24;
    }
    return 27;
  }
LABEL_24:
  if ( (v19 & 8) != 0 )
  {
    if ( v20 + 7 > v23 )
      return 27;
    v20 += 2;
  }
  if ( (v19 & 0x10) == 0 )
    return 0;
  result = 27;
  if ( v20 + 2 <= (unsigned __int64)v15[5] && v20 + 7 <= v23 )
  {
    *v22 = *(_WORD *)&v15[v20 + 5];
    *v21 = 1;
    return 0;
  }
  return result;
}
