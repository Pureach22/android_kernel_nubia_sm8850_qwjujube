__int64 __fastcall ieee80211_freq_khz_to_channel(unsigned int a1)
{
  unsigned int v2; // w8
  unsigned int v3; // w8
  int v4; // w9

  if ( a1 - 2484000 < 0x3E8 )
    return 14;
  v2 = a1 / 0x3E8;
  if ( a1 <= 0x25E71F )
    return (v2 - 2407) / 5uLL;
  if ( a1 - 4910000 <= 0x11557 )
  {
    v3 = v2 - 4000;
    return v3 / 5uLL;
  }
  if ( a1 <= 0x5A6887 )
  {
    v4 = -5000;
LABEL_9:
    v3 = v2 + v4;
    return v3 / 5uLL;
  }
  if ( a1 - 5935000 < 0x3E8 )
    return 2;
  if ( a1 <= 0x2AEA927 )
  {
    v4 = -5950;
    goto LABEL_9;
  }
  if ( a1 - 58320000 > 0xB54A27 )
    return 0;
  else
    return (v2 - 56160) / 0x870uLL;
}
