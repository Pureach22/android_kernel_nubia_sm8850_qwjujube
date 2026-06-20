__int64 __fastcall cfg80211_get_unii(int a1)
{
  if ( (unsigned int)(a1 - 5150) < 0x65 )
    return 0;
  if ( (unsigned int)(a1 - 5251) < 0x64 )
    return 1;
  if ( (unsigned int)(a1 - 5351) < 0x78 )
    return 2;
  if ( (unsigned int)(a1 - 5471) < 0xFF )
    return 3;
  if ( (unsigned int)(a1 - 5726) < 0x64 )
    return 4;
  if ( (unsigned int)(a1 - 5926) < 0x1F4 )
    return 5;
  if ( (unsigned int)(a1 - 6426) < 0x64 )
    return 6;
  if ( (unsigned int)(a1 - 6526) < 0x15E )
    return 7;
  if ( (unsigned int)(a1 - 6876) >= 0xFA )
    return 4294967274LL;
  return 8;
}
