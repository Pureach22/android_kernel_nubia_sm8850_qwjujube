__int64 __fastcall nl80211_parse_counter_offsets(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        int a4,
        _WORD *a5,
        _QWORD *a6,
        unsigned int *a7)
{
  __int64 result; // x0
  unsigned int v9; // w9
  unsigned int v10; // w8
  int v11; // w10
  unsigned __int64 v12; // x11

  *a7 = 0;
  if ( !a5 )
    return 0;
  result = 4294967274LL;
  if ( *a5 == 4 )
    return result;
  if ( (*a5 & 1) != 0 )
    return result;
  v9 = (unsigned __int16)(*a5 - 4) >> 1;
  *a7 = v9;
  v10 = *(unsigned __int8 *)(a1 + 2386);
  if ( v10 )
  {
    if ( v9 > v10 )
      return result;
  }
  *a6 = a5 + 2;
  if ( !*a7 )
    return 0;
  v11 = 0;
  while ( 1 )
  {
    v12 = (unsigned __int16)a5[v11 + 2];
    if ( v12 >= a3 || a4 != -1 && *(unsigned __int8 *)(a2 + v12) != a4 )
      break;
    if ( *a7 == ++v11 )
      return 0;
  }
  return 4294967274LL;
}
