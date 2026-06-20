__int64 __fastcall ieee80211_is_our_addr(__int64 a1, __int64 a2, _DWORD *a3)
{
  int v3; // w8
  __int64 v4; // x10
  __int64 v5; // x12

  v3 = *(unsigned __int16 *)(a2 + 4);
  if ( *(_DWORD *)a2 ^ *(_DWORD *)(a1 + 5842) | (unsigned __int16)(v3 ^ *(_WORD *)(a1 + 5846)) )
  {
    if ( !*(_WORD *)(a1 + 5800) )
      return 0;
    v4 = 0;
    while ( 1 )
    {
      v5 = *(_QWORD *)(a1 + 5680 + 8 * v4);
      if ( v5 )
      {
        if ( !(*(_DWORD *)a2 ^ *(_DWORD *)(v5 + 28) | v3 ^ *(unsigned __int16 *)(v5 + 32)) )
          break;
      }
      if ( ++v4 == 15 )
        return 0;
    }
    if ( a3 )
    {
      *a3 = v4;
      return 1;
    }
  }
  return 1;
}
