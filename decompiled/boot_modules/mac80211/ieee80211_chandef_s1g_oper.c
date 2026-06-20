__int64 __fastcall ieee80211_chandef_s1g_oper(unsigned __int8 *a1, __int64 a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w8
  int v4; // w8
  unsigned int v7; // w0

  if ( !a1 )
    return 0;
  v2 = (*a1 >> 1) & 0xF;
  v3 = 0;
  if ( v2 <= 2 )
  {
    if ( !v2 )
    {
      v4 = 8;
      goto LABEL_14;
    }
    if ( v2 == 1 )
    {
      v4 = 9;
      goto LABEL_14;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 3u:
        v4 = 10;
        goto LABEL_14;
      case 7u:
        v4 = 11;
        goto LABEL_14;
      case 0xFu:
        v4 = 12;
LABEL_14:
        *(_DWORD *)(a2 + 8) = v4;
        v7 = ieee80211_channel_to_freq_khz(a1[3], 4);
        *(_DWORD *)(a2 + 12) = v7 / 0x3E8;
        *(_WORD *)(a2 + 28) = v7 % 0x3E8;
        return 1;
    }
  }
  return v3;
}
