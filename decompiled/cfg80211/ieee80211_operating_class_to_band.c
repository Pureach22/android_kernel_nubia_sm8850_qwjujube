__int64 __fastcall ieee80211_operating_class_to_band(unsigned __int8 a1, int *a2)
{
  int v2; // w8

  if ( (unsigned int)a1 - 81 <= 0x38 )
  {
    if ( ((1LL << (a1 - 81)) & 0x3FFFC80000000LL) != 0 )
    {
      v2 = 1;
LABEL_8:
      *a2 = v2;
      return 1;
    }
    if ( ((1LL << (a1 - 81)) & 0x17C000000000000LL) != 0 )
    {
      v2 = 3;
      goto LABEL_8;
    }
    if ( ((1LL << (a1 - 81)) & 0xF) != 0 )
    {
      v2 = 0;
      goto LABEL_8;
    }
  }
  if ( a1 == 180 )
  {
    v2 = 2;
    goto LABEL_8;
  }
  return 0;
}
