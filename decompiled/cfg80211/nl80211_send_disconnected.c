__int64 __fastcall nl80211_send_disconnected(__int64 a1, __int64 a2, __int16 a3, __int64 a4, unsigned int a5, char a6)
{
  __int64 result; // x0
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x26
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb((a5 + 119) & 0xFFFFFFFC, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v13 = result;
    v14 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 48);
    if ( v14 )
    {
      v15 = v14;
      v16 = *(_DWORD *)(a1 + 100);
      if ( !(unsigned int)nla_put(v13, 1, 4, &v16) )
      {
        v16 = *(_DWORD *)(a2 + 224);
        if ( !(unsigned int)nla_put(v13, 3, 4, &v16) )
        {
          if ( !a3 || (LOWORD(v16) = a3, !(unsigned int)nla_put(v13, 54, 2, &v16)) )
          {
            if ( ((a6 & 1) == 0 || !(unsigned int)nla_put(v13, 71, 0, 0))
              && (!a4 || !(unsigned int)nla_put(v13, 42, a5, a4)) )
            {
              *(_DWORD *)(v15 - 20) = *(_DWORD *)(v13 + 216) + *(_DWORD *)(v13 + 208) - (v15 - 20);
              result = genlmsg_multicast_netns(*(_QWORD *)(a1 + 2344), v13, 3u, 0xCC0u);
              goto LABEL_7;
            }
          }
        }
      }
      v14 = 0;
    }
    result = sk_skb_reason_drop(v14, v13, 2);
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
