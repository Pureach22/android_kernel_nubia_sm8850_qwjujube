__int64 __fastcall ieee80211_encode_usf(int a1)
{
  unsigned __int64 v1; // t2
  int v2; // w8
  unsigned __int64 v3; // t2
  unsigned __int64 v4; // t2
  int v5; // w0

  HIDWORD(v1) = -858993459 * a1 + 429496728;
  LODWORD(v1) = HIDWORD(v1);
  if ( (unsigned int)(v1 >> 1) <= 0x19999998 )
  {
    HIDWORD(v3) = 652835029 * a1 + 17179864;
    LODWORD(v3) = HIDWORD(v3);
    if ( (unsigned int)(v3 >> 3) <= 0x418936 )
    {
      HIDWORD(v4) = 989560465 * a1 + 3435968;
      LODWORD(v4) = HIDWORD(v4);
      if ( (unsigned int)(v4 >> 4) >= 0x68DB9 )
        v2 = 2;
      else
        v2 = 3;
    }
    else
    {
      v2 = 1;
    }
  }
  else
  {
    v2 = 0;
  }
  v5 = a1 / ieee80211_encode_usf_listen_int_usf[(unsigned __int16)v2];
  if ( (v5 & 0xC000) != 0 )
    __break(0x800u);
  return v5 & 0x3FFF | (unsigned int)(v2 << 14);
}
