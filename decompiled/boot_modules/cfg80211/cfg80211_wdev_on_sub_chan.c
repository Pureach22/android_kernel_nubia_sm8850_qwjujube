__int64 __fastcall cfg80211_wdev_on_sub_chan(__int64 a1, __int64 a2, char a3)
{
  int v3; // w8
  char is_sub_chan; // w0
  unsigned int v8; // w8
  unsigned int v9; // w23
  __int64 *v10; // x22
  bool v11; // w9
  bool v12; // cc
  __int64 v13; // x8

  v3 = *(_DWORD *)(a1 + 8);
  is_sub_chan = 0;
  if ( v3 <= 6 )
  {
    if ( v3 != 1 )
    {
      if ( v3 != 3 )
        return is_sub_chan & 1;
      goto LABEL_7;
    }
    v13 = 288;
    goto LABEL_18;
  }
  if ( v3 == 7 )
  {
    v13 = 320;
LABEL_18:
    is_sub_chan = cfg80211_is_sub_chan((__int64 *)(a1 + v13), a2, a3 & 1);
    return is_sub_chan & 1;
  }
  if ( v3 == 9 )
  {
LABEL_7:
    v8 = *(unsigned __int16 *)(a1 + 1472);
    v9 = 0;
    v10 = (__int64 *)(a1 + 408);
    v11 = *(_WORD *)(a1 + 1472) == 0;
    while ( 1 )
    {
      if ( v11 || (((unsigned __int64)v8 >> v9) & 1) != 0 )
      {
        if ( (cfg80211_is_sub_chan(v10, a2, a3 & 1) & 1) != 0 )
        {
          is_sub_chan = 1;
          return is_sub_chan & 1;
        }
        v8 = *(unsigned __int16 *)(a1 + 1472);
      }
      is_sub_chan = 0;
      v11 = v8 == 0;
      if ( v8 )
      {
        v12 = v9++ > 0xD;
        v10 += 9;
        if ( !v12 )
          continue;
      }
      return is_sub_chan & 1;
    }
  }
  return is_sub_chan & 1;
}
