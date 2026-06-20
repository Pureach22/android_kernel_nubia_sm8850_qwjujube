__int16 *__fastcall ieee80211_get_bssid(__int16 *a1, unsigned __int64 a2, int a3)
{
  __int16 v3; // w9
  int v4; // w8
  __int64 v5; // x8
  int v7; // w9

  v3 = *a1;
  v4 = *a1 & 0xC;
  if ( v4 == 8 )
  {
    v5 = 0;
    if ( a2 < 0x18 || (v3 & 0x300) == 0x300 )
      return (__int16 *)v5;
    if ( (*a1 & 0x100) == 0 )
    {
      if ( (*a1 & 0x200) == 0 )
        return a1 + 8;
      return a1 + 5;
    }
    return a1 + 2;
  }
  v7 = v3 & 0xFC;
  if ( v7 == 28 )
    return a1 + 2;
  if ( v4 == 4 )
  {
    if ( v7 == 132 )
    {
      if ( (unsigned int)(a3 - 3) < 2 )
        return a1 + 2;
      if ( a3 == 2 )
        return a1 + 5;
    }
    else if ( v7 == 164 )
    {
      return a1 + 2;
    }
    return nullptr;
  }
  if ( v4 )
    return nullptr;
  if ( a2 >= 0x18 )
    return a1 + 8;
  else
    return nullptr;
}
