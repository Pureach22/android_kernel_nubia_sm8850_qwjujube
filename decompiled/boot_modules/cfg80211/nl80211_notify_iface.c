__int64 __fastcall nl80211_notify_iface(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x19
  __int64 v8; // x3
  __int64 v9; // x0

  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v7 = result;
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD))nl80211_send_iface)(
               result,
               0,
               0,
               0,
               a1,
               a2,
               a3);
    if ( (result & 0x80000000) != 0 )
    {
      return sk_skb_reason_drop(0, v7, 2);
    }
    else if ( byte_BF570 )
    {
      v8 = (unsigned int)dword_BF5E4;
      v9 = *(_QWORD *)(*(_QWORD *)(a1 + 2344) + 288LL);
      *(_DWORD *)(v7 + 56) = dword_BF5E4;
      return netlink_broadcast_filtered(v9, v7, 0, v8, 3264, 0, 0);
    }
    else
    {
      __break(0x800u);
    }
  }
  return result;
}
