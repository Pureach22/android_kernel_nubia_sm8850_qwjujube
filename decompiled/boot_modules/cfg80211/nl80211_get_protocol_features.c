__int64 __fastcall nl80211_get_protocol_features(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 result; // x0
  int v8; // w0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( v3 )
  {
    v4 = v3;
    v5 = genlmsg_put(v3, a2[1], *a2, &nl80211_fam, 0, 95);
    if ( v5 && (v6 = v5, v9 = 1, !(unsigned int)nla_put(v4, 173, 4, &v9)) )
    {
      *(_DWORD *)(v6 - 20) = *(_DWORD *)(v4 + 216) + *(_DWORD *)(v4 + 208) - (v6 - 20);
      v8 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v4, a2[1], 64);
      result = v8 & (unsigned int)(v8 >> 31);
    }
    else
    {
      sk_skb_reason_drop(0, v4, 2);
      result = 4294967191LL;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
