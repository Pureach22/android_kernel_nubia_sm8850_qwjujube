__int64 __fastcall nl80211_get_interface(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v5; // x0
  __int64 v6; // x20
  int v7; // w0

  v2 = *((_QWORD *)a2 + 6);
  v3 = *((_QWORD *)a2 + 7);
  v5 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( !v5 )
    return 4294967284LL;
  v6 = v5;
  if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, __int64))nl80211_send_iface)(
          v5,
          a2[1],
          *a2,
          0,
          v2,
          v3,
          7)
      & 0x80000000) != 0 )
  {
    sk_skb_reason_drop(0, v6, 2);
    return 4294967191LL;
  }
  else
  {
    v7 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v6, a2[1], 64);
    return v7 & (unsigned int)(v7 >> 31);
  }
}
