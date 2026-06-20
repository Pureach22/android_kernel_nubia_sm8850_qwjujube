__int64 __fastcall ieee80211_attach_ack_skb(__int64 a1, __int64 a2, __int64 *a3, unsigned int a4)
{
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x24
  int v10; // w23
  __int64 v11; // x8
  bool v12; // cf
  __int64 v13; // x8

  v7 = skb_copy(a2, a4);
  if ( !v7 )
    return 4294967284LL;
  v8 = v7;
  v9 = raw_spin_lock_irqsave(a1 + 5368);
  v10 = idr_alloc(a1 + 5344, v8, 1, 0x2000, 2080);
  raw_spin_unlock_irqrestore(a1 + 5368, v9);
  if ( v10 < 0 )
  {
    sk_skb_reason_drop(0);
    return 4294967284LL;
  }
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a2 + 44) & 0xFFFE0007 | (16 * (v10 & 0x1FFF)) | 8;
  v11 = *(_QWORD *)(a1 + 5336);
  v12 = __CFADD__(v11, 1);
  v13 = v11 + 1;
  *(_QWORD *)(a1 + 5336) = v13;
  if ( v12 )
  {
    __break(0x800u);
    v13 = *(_QWORD *)(a1 + 5336) + 1LL;
    *(_QWORD *)(a1 + 5336) = v13;
  }
  *a3 = v13;
  *(_QWORD *)(v8 + 48) = v13;
  return 0;
}
