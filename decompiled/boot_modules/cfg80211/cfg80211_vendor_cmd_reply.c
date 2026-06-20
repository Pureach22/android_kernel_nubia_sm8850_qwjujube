__int64 __fastcall cfg80211_vendor_cmd_reply(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  _WORD *v3; // x10
  int v4; // w0

  v2 = *(_QWORD *)(a1 + 40);
  v1 = *(_QWORD *)(a1 + 48);
  *(_QWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  v3 = *(_WORD **)(a1 + 56);
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 64) = 0;
  if ( *(_QWORD *)(v2 + 296) )
  {
    *v3 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v3;
    *(_DWORD *)(v1 - 20) = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (v1 - 20);
    v4 = netlink_unicast(
           *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 296) + 40LL) + 288LL),
           a1,
           *(unsigned int *)(*(_QWORD *)(v2 + 296) + 4LL),
           64);
    return v4 & (unsigned int)(v4 >> 31);
  }
  else
  {
    __break(0x800u);
    sk_skb_reason_drop(0, a1, 2);
    return 4294967274LL;
  }
}
