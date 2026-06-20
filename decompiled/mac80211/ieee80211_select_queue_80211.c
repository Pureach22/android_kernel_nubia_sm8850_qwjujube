__int64 __fastcall ieee80211_select_queue_80211(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 v3; // x22
  __int64 result; // x0
  int v8; // w8
  bool v9; // zf
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned int v12; // w13
  __int64 v13; // x9

  v3 = *(_QWORD *)(a1 + 1616);
  if ( (*(_BYTE *)(a2 + 130) & 6) == 0 )
  {
    _skb_get_hash_net(0, a2);
    if ( (*(_BYTE *)(a2 + 81) & 1) == 0 )
      goto LABEL_5;
    return 0;
  }
  if ( (*(_BYTE *)(a2 + 81) & 1) != 0 )
    return 0;
LABEL_5:
  if ( *(unsigned __int16 *)(v3 + 128) < 4u )
    return 0;
  v8 = *a3;
  if ( (v8 & 0xC) == 8 )
  {
    if ( (~v8 & 0x88) != 0 )
    {
      *(_DWORD *)(a2 + 144) = 0;
      return 2;
    }
    else
    {
      v9 = (~v8 & 0x300) == 0;
      v10 = 12;
      if ( v9 )
        v10 = 15;
      v11 = a3[v10] & 7;
      *(_DWORD *)(a2 + 144) = v11;
      if ( (((unsigned __int64)*(unsigned __int8 *)(a1 + 1890) >> v11) & 1) != 0 )
      {
        v12 = v11;
        while ( 1 )
        {
          result = (int)ieee802_1d_to_ac[v11];
          v13 = a1 + 2744 + 32 * result;
          if ( *(_DWORD *)(v13 + 8) )
          {
            if ( v12 == *(char *)(v13 + 13) )
              break;
          }
          if ( v12 > 7 || ((0xF9u >> v12) & 1) == 0 )
          {
            LODWORD(v11) = v12;
            return ieee802_1d_to_ac[(unsigned int)v11];
          }
          v11 = dword_C1570[v12];
          *(_DWORD *)(a2 + 144) = v11;
          v12 = v11;
          if ( (((unsigned __int64)*(unsigned __int8 *)(a1 + 1890) >> v11) & 1) == 0 )
            return ieee802_1d_to_ac[(unsigned int)v11];
        }
      }
      else
      {
        return ieee802_1d_to_ac[(unsigned int)v11];
      }
    }
  }
  else
  {
    *(_DWORD *)(a2 + 144) = 7;
    return 0;
  }
  return result;
}
