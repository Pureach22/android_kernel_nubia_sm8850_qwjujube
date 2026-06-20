__int64 __fastcall ieee80211_parse_bitrates(int a1, __int64 a2, __int64 a3, int a4, _DWORD *a5)
{
  int v5; // w8
  int v6; // w9
  __int64 v7; // x10
  __int64 result; // x0
  __int64 v9; // x14
  __int64 v10; // x15
  unsigned __int16 *v11; // x17

  *a5 = 0;
  if ( a1 == 6 )
    v5 = 32;
  else
    v5 = (a1 == 7) << 6;
  if ( a4 < 1 )
    return 0;
  v6 = 0;
  v7 = 0;
  result = 0;
  do
  {
    v9 = *(unsigned int *)(a2 + 24);
    if ( (int)v9 >= 1 )
    {
      v10 = 0;
      v11 = (unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 4LL);
      while ( (v5 & ~*((_DWORD *)v11 - 1)) != 0
           || (858993460 * (unsigned __int64)((unsigned int)*v11 + 4)) >> 32 != (*(_BYTE *)(a3 + v7) & 0x7F) )
      {
        ++v10;
        v11 += 6;
        if ( v9 == v10 )
          goto LABEL_6;
      }
      result = (unsigned int)(result + 1);
      v6 |= 1LL << v10;
      *a5 = v6;
    }
LABEL_6:
    ++v7;
  }
  while ( v7 != a4 );
  return result;
}
