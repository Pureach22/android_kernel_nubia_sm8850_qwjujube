__int64 __fastcall bcl_soc_get_trend(__int64 a1, _DWORD *a2, int *a3)
{
  __int64 result; // x0
  int v5; // w10
  int v6; // w8
  int v7; // w8

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = a2[1];
    v6 = *(_DWORD *)(a1 + 1088);
    if ( v6 >= *a2 )
    {
      v7 = 1;
    }
    else if ( v5 )
    {
      v7 = 2 * (v6 <= *a2 - v5);
    }
    else
    {
      v7 = 2;
    }
    *a3 = v7;
    return 0;
  }
  return result;
}
