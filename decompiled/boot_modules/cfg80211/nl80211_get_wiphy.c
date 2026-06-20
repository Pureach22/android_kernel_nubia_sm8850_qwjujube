__int64 __fastcall nl80211_get_wiphy(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x20
  int v6; // w0
  __int64 result; // x0
  _QWORD v8[8]; // [xsp+0h] [xbp-40h] BYREF

  v8[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 48);
  memset(v8, 0, 56);
  v4 = _alloc_skb(4112, 3264, 0, 0xFFFFFFFFLL);
  if ( v4 )
  {
    v5 = v4;
    if ( (nl80211_send_wiphy(v3, 3u, v4, *(_DWORD *)(a2 + 4), *(_DWORD *)a2, 0, (__int64)v8) & 0x80000000) != 0 )
    {
      sk_skb_reason_drop(0, v5, 2);
      result = 4294967191LL;
    }
    else
    {
      v6 = netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v5, *(unsigned int *)(a2 + 4), 64);
      result = v6 & (unsigned int)(v6 >> 31);
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
