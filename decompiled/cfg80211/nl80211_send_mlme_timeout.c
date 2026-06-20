__int64 __fastcall nl80211_send_mlme_timeout(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x24
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb(3712, a5, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v11 = result;
    v12 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, a3);
    if ( v12 )
    {
      v13 = v12;
      v14 = *(_DWORD *)(a1 + 100);
      if ( !(unsigned int)nla_put(v11, 1, 4, &v14) )
      {
        v14 = *(_DWORD *)(a2 + 224);
        if ( !(unsigned int)nla_put(v11, 3, 4, &v14)
          && !(unsigned int)nla_put(v11, 65, 0, 0)
          && !(unsigned int)nla_put(v11, 6, 6, a4) )
        {
          *(_DWORD *)(v13 - 20) = *(_DWORD *)(v11 + 216) + *(_DWORD *)(v11 + 208) - (v13 - 20);
          result = genlmsg_multicast_netns(*(_QWORD *)(a1 + 2344), v11, 3u, a5);
          goto LABEL_9;
        }
      }
      v12 = 0;
    }
    result = sk_skb_reason_drop(v12, v11, 2);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
