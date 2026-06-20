__int64 __fastcall nl80211_send_scan_start(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x0
  __int64 v7; // x3

  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v5 = result;
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))nl80211_prep_scan_msg)(result, a1, a2, 33);
    if ( (result & 0x80000000) != 0 )
    {
      return sk_skb_reason_drop(0, v5, 2);
    }
    else if ( (unsigned __int8)byte_BF570 <= 1u )
    {
      __break(0x800u);
    }
    else
    {
      v6 = *(_QWORD *)(*(_QWORD *)(a1 + 2344) + 288LL);
      v7 = (unsigned int)(dword_BF5E4 + 1);
      *(_DWORD *)(v5 + 56) = v7;
      return netlink_broadcast_filtered(v6, v5, 0, v7, 3264, 0, 0);
    }
  }
  return result;
}
