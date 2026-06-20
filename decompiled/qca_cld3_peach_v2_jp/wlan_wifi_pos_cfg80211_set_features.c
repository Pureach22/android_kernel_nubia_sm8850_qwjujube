__int64 __fastcall wlan_wifi_pos_cfg80211_set_features(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _BYTE *v5; // x20
  char v6; // t1
  char v7; // w8
  char v8; // t1
  char v9; // w8

  if ( (unsigned int)wifi_pos_get_rsta_11az_ranging_cap(a1) )
  {
    result = wifi_pos_get_rsta_sec_ltf_cap();
    v6 = *(_BYTE *)(a1 + 24);
    v5 = (_BYTE *)(a1 + 24);
    if ( (v6 & 4) != 0 )
    {
      v7 = *(_BYTE *)(a2 + 2);
      *(_BYTE *)(a2 + 2) = v7 | 1;
      if ( (result & 1) != 0 )
      {
        result = 1;
        *(_BYTE *)(a2 + 2) = v7 | 3;
        if ( (*v5 & 2) == 0 )
          return result;
        goto LABEL_11;
      }
LABEL_7:
      result = 0;
      if ( (*v5 & 2) == 0 )
        return result;
      goto LABEL_11;
    }
  }
  else
  {
    v8 = *(_BYTE *)(a1 + 24);
    v5 = (_BYTE *)(a1 + 24);
    if ( (v8 & 4) == 0 )
      goto LABEL_7;
    result = 0;
    *(_BYTE *)(a2 + 2) |= 1u;
  }
  if ( (*v5 & 2) == 0 )
    return result;
LABEL_11:
  v9 = *(_BYTE *)(a2 + 2);
  *(_BYTE *)(a2 + 2) = v9 | 0x10;
  if ( (result & 1) != 0 )
    *(_BYTE *)(a2 + 2) = v9 | 0x30;
  return result;
}
