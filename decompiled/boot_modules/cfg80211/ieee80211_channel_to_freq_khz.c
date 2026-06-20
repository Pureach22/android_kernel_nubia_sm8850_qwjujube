__int64 __fastcall ieee80211_channel_to_freq_khz(unsigned int a1, int a2)
{
  unsigned int v2; // w8
  int v3; // w8
  int v4; // w9
  int v6; // w8

  if ( (int)a1 < 1 )
    return 0;
  v2 = 0;
  if ( a2 > 2 )
  {
    if ( a2 != 3 )
    {
      if ( a2 == 4 )
      {
        v3 = 500;
        v4 = 902000;
        return v4 + a1 * v3;
      }
      if ( a2 != 5 )
        return v2;
LABEL_11:
      if ( a1 == 14 )
        return 2484000;
      if ( a1 <= 0xD )
      {
        v3 = 5000;
        v4 = 2407000;
        return v4 + a1 * v3;
      }
      return 0;
    }
    if ( a1 == 2 )
      return 5935000;
    if ( a1 <= 0xE9 )
    {
      v3 = 5000;
      v4 = 5950000;
      return v4 + a1 * v3;
    }
    return 0;
  }
  if ( !a2 )
    goto LABEL_11;
  if ( a2 != 1 )
  {
    if ( a2 == 2 )
    {
      if ( a1 <= 6 )
      {
        v3 = 2160000;
        v4 = 56160000;
        return v4 + a1 * v3;
      }
      return 0;
    }
    return v2;
  }
  v6 = 5000 * a1;
  if ( a1 - 182 > 0xE )
    return (unsigned int)(v6 + 5000000);
  else
    return (unsigned int)(v6 + 4000000);
}
