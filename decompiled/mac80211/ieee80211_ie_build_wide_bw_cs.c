__int64 __fastcall ieee80211_ie_build_wide_bw_cs(__int64 a1, _DWORD *a2)
{
  int v4; // w8
  char v5; // w8
  int v6; // w8
  __int64 result; // x0

  *(_WORD *)a1 = 962;
  v4 = a2[2];
  if ( v4 > 4 )
  {
    if ( v4 == 13 )
    {
      __break(0x800u);
    }
    else if ( v4 == 5 )
    {
      v5 = 2;
      goto LABEL_11;
    }
  }
  else
  {
    if ( v4 == 3 )
    {
      v5 = 1;
      goto LABEL_11;
    }
    if ( v4 == 4 )
    {
      v5 = 3;
      goto LABEL_11;
    }
  }
  v5 = 0;
LABEL_11:
  *(_BYTE *)(a1 + 2) = v5;
  *(_BYTE *)(a1 + 3) = ieee80211_freq_khz_to_channel((unsigned int)(1000 * a2[3]));
  v6 = a2[4];
  if ( v6 )
    result = ieee80211_freq_khz_to_channel((unsigned int)(1000 * v6));
  else
    result = 0;
  *(_BYTE *)(a1 + 4) = result;
  return result;
}
