__int64 __fastcall ieee80211_get_radio_mask(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x12
  __int64 v5; // x12
  int v6; // w12

  v2 = 0;
  result = 0;
  do
  {
    if ( !*(_WORD *)(a2 + 8490) || (((unsigned __int64)*(unsigned __int16 *)(a2 + 8490) >> v2) & 1) != 0 )
    {
      v4 = *(_QWORD *)(a2 + 8368 + 8 * v2);
      if ( v4 )
      {
        v5 = *(_QWORD *)(v4 + 832);
        if ( v5 )
        {
          v6 = *(_DWORD *)(v5 + 96);
          if ( (v6 & 0x80000000) == 0 )
            result = (unsigned int)result | (unsigned int)(1LL << v6);
        }
      }
    }
    ++v2;
  }
  while ( v2 != 15 );
  return result;
}
