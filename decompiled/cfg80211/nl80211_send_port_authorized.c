__int64 __fastcall nl80211_send_port_authorized(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int8 a5)
{
  __int64 result; // x0
  __int64 v11; // x19
  __int64 v12; // x0
  __int64 v13; // x25
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v11 = result;
    v12 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 125);
    if ( v12 )
    {
      v13 = v12;
      v14 = *(_DWORD *)(a1 + 100);
      if ( !(unsigned int)nla_put(v11, 1, 4, &v14) )
      {
        v14 = *(_DWORD *)(a2 + 224);
        if ( !(unsigned int)nla_put(v11, 3, 4, &v14)
          && !(unsigned int)nla_put(v11, 6, 6, a3)
          && (!a4 || !a5 || !(unsigned int)nla_put(v11, 321, a5, a4)) )
        {
          *(_DWORD *)(v13 - 20) = *(_DWORD *)(v11 + 216) + *(_DWORD *)(v11 + 208) - (v13 - 20);
          result = genlmsg_multicast_netns(*(_QWORD *)(a1 + 2344), v11, 3u, 0xCC0u);
          goto LABEL_8;
        }
      }
      v12 = 0;
    }
    result = sk_skb_reason_drop(v12, v11, 2);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
