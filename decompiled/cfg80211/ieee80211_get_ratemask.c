__int64 __fastcall ieee80211_get_ratemask(__int64 a1, __int64 a2, int a3, _DWORD *a4)
{
  unsigned int v4; // w8
  int v5; // w9
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x13
  unsigned __int16 *v9; // x15
  int v10; // t1

  v4 = -22;
  if ( a1 && (unsigned int)(a3 - 33) >= 0xFFFFFFE0 )
  {
    v5 = 0;
    v6 = 0;
    *a4 = 0;
    while ( 1 )
    {
      v7 = *(unsigned int *)(a1 + 24);
      if ( (int)v7 < 1 )
        break;
      v8 = 0;
      v9 = (unsigned __int16 *)(*(_QWORD *)(a1 + 8) + 4LL);
      while ( 1 )
      {
        v10 = *v9;
        v9 += 6;
        if ( 5 * (*(_BYTE *)(a2 + v6) & 0x7F) == v10 )
          break;
        if ( v7 == ++v8 )
          return (unsigned int)-22;
      }
      ++v6;
      v4 = 0;
      v5 |= 1LL << v8;
      *a4 = v5;
      if ( v6 == a3 )
        return v4;
    }
    return (unsigned int)-22;
  }
  return v4;
}
