__int64 __fastcall compute_intercept_slope(__int64 result, __int64 a2, __int64 a3, int a4)
{
  unsigned int v4; // w15
  int v5; // w17
  __int64 v6; // x14
  int v7; // w16

  if ( *(_DWORD *)(result + 8) )
  {
    v4 = 0;
    do
    {
      v6 = result + 2600 + 88LL * (int)v4;
      v7 = *(_DWORD *)(v6 + 72);
      if ( !v7 )
      {
        v7 = 3200;
        *(_DWORD *)(v6 + 72) = 3200;
      }
      if ( (a4 & 0xFFFFFFFB) == 3 )
      {
        v7 = 1000 * (*(_DWORD *)(a3 + 4LL * (int)v4) - *(_DWORD *)(a2 + 4LL * (int)v4)) / 90;
        *(_DWORD *)(v6 + 72) = v7;
      }
      v5 = *(_DWORD *)(a2 + 4LL * (int)v4++);
      *(_DWORD *)(v6 + 64) = 1000 * v5 - 30 * v7;
    }
    while ( v4 < *(_DWORD *)(result + 8) );
  }
  return result;
}
