__int64 __fastcall nl80211_notify_wiphy(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x3
  __int64 v7; // x0
  _QWORD v8[8]; // [xsp+0h] [xbp-40h] BYREF

  v8[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v8, 0, 56);
  if ( a2 - 5 <= 0xFFFFFFFD )
    __break(0x800u);
  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v5 = result;
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _QWORD *))nl80211_send_wiphy)(
               a1,
               a2,
               result,
               0,
               0,
               0,
               v8);
    if ( (result & 0x80000000) != 0 )
    {
      result = sk_skb_reason_drop(0, v5, 2);
    }
    else if ( byte_BF570 )
    {
      v6 = (unsigned int)dword_BF5E4;
      v7 = *(_QWORD *)(*(_QWORD *)(a1 + 2344) + 288LL);
      *(_DWORD *)(v5 + 56) = dword_BF5E4;
      result = netlink_broadcast_filtered(v7, v5, 0, v6, 3264, 0, 0);
    }
    else
    {
      __break(0x800u);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
