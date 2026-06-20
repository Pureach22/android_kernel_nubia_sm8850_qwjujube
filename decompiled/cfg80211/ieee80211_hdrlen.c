__int64 __fastcall ieee80211_hdrlen(unsigned int a1)
{
  unsigned int v1; // w9
  __int16 v2; // w8
  unsigned int v3; // w10
  unsigned int v4; // w8
  __int64 result; // x0
  int v6; // w8

  v1 = (a1 >> 2) & 3;
  v2 = a1;
  if ( v1 > 1 )
  {
    if ( v1 == 3 )
    {
      return 4;
    }
    else
    {
      if ( (~(unsigned __int16)a1 & 0x300) != 0 )
        result = 24;
      else
        result = 30;
      if ( (v2 & 0x8C) == 0x88 )
      {
        if ( v2 >= 0 )
          v6 = 2;
        else
          v6 = 6;
        return (unsigned int)(result + v6);
      }
    }
  }
  else
  {
    if ( (a1 & 0x8000u) == 0 )
      v3 = 24;
    else
      v3 = 28;
    if ( (a1 & 0xE0) == 0xC0 )
      v4 = 10;
    else
      v4 = 16;
    if ( v1 )
      return v4;
    else
      return v3;
  }
  return result;
}
