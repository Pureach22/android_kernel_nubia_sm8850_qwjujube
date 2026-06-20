__int64 __fastcall cfg80211_find_ssid_match(__int64 a1, __int64 a2)
{
  int v2; // w23
  unsigned __int8 *v3; // x21
  __int64 i; // x22

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 >= 1 )
  {
    v3 = *(unsigned __int8 **)a2;
    for ( i = 0; i < v2; ++i )
    {
      if ( v3[32] )
      {
        if ( *(_QWORD *)(a1 + 56) == v3[32] )
        {
          if ( !bcmp(v3, (const void *)(a1 + 22), *(_QWORD *)(a1 + 56)) )
            return 1;
          v2 = *(_DWORD *)(a2 + 8);
        }
        else if ( (*(_BYTE *)(a1 + 72) & 0x40) != 0
               && (*(_DWORD *)(a1 + 64) ^ (unsigned int)crc32_le(0xFFFFFFFFLL, v3)) == 0xFFFFFFFF )
        {
          return 1;
        }
      }
      else if ( (*(_BYTE *)(a1 + 72) & 0x18) != 8 )
      {
        return 1;
      }
      v3 += 33;
    }
  }
  return 0;
}
