unsigned __int8 *__fastcall sch_get_csa_ecsa_count_offset(
        unsigned __int8 *result,
        unsigned int a2,
        _DWORD *a3,
        _DWORD *a4)
{
  int v4; // w8
  unsigned int v5; // w10
  __int64 v6; // x9
  int v7; // w10
  _DWORD *v8; // x11
  unsigned int v9; // w10

  if ( a2 >= 2 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *result;
      v6 = result[1];
      if ( __PAIR64__(v6, v5) == 0x300000025LL )
      {
        v7 = 4;
        v8 = a3;
      }
      else
      {
        if ( __PAIR64__(v6, v5) != 0x40000003CLL )
          goto LABEL_8;
        v7 = 5;
        v8 = a4;
      }
      *v8 = v4 + v7;
LABEL_8:
      v9 = a2 - 2;
      a2 = a2 - 2 - v6;
      if ( v9 >= (unsigned int)v6 )
      {
        v4 += 2 + v6;
        result += v6 + 2;
        if ( a2 > 1 )
          continue;
      }
      return result;
    }
  }
  return result;
}
