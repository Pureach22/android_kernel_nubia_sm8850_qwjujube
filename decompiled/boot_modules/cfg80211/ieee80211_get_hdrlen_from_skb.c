__int64 __fastcall ieee80211_get_hdrlen_from_skb(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v2; // w9
  unsigned int v3; // w10
  unsigned int v4; // w10
  int v5; // w9

  v1 = *(_DWORD *)(a1 + 112);
  if ( v1 < 0xA )
    return 0;
  v2 = **(unsigned __int16 **)(a1 + 224);
  v3 = (v2 >> 2) & 3;
  if ( v3 > 1 )
  {
    if ( v3 == 3 )
    {
      v4 = 4;
    }
    else
    {
      if ( (~v2 & 0x300) != 0 )
        v4 = 24;
      else
        v4 = 30;
      if ( (v2 & 0x8C) == 0x88 )
      {
        if ( (v2 & 0x8000u) == 0 )
          v5 = 2;
        else
          v5 = 6;
        v4 += v5;
      }
    }
  }
  else if ( v3 )
  {
    if ( (v2 & 0xE0) == 0xC0 )
      v4 = 10;
    else
      v4 = 16;
  }
  else if ( (v2 & 0x8000u) == 0 )
  {
    v4 = 24;
  }
  else
  {
    v4 = 28;
  }
  if ( v4 <= v1 )
    return v4;
  else
    return 0;
}
