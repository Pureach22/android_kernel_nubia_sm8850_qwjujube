__int64 __fastcall ieee80211_store_ack_skb(__int64 a1, __int64 a2, _DWORD *a3, __int64 *a4)
{
  __int64 v7; // x22
  __int64 v8; // x23
  unsigned int v9; // w24
  __int64 result; // x0
  __int64 v11; // x8

  if ( *(_QWORD *)(a2 + 24) )
  {
    v7 = skb_clone_sk(a2);
    if ( !v7 )
      return 0;
  }
  else
  {
    v7 = skb_clone(a2, 2080);
    if ( !v7 )
      return 0;
  }
  v8 = raw_spin_lock_irqsave(a1 + 5368);
  v9 = idr_alloc(a1 + 5344, v7, 1, 0x2000, 2080);
  raw_spin_unlock_irqrestore(a1 + 5368, v8);
  if ( (v9 & 0x80000000) != 0 )
  {
    sk_skb_reason_drop(0);
    return 0;
  }
  result = v9;
  *a3 |= 1u;
  if ( a4 )
  {
    v11 = ieee80211_mgmt_tx_cookie(a1);
    *a4 = v11;
    *(_QWORD *)(v7 + 48) = v11;
    return v9;
  }
  return result;
}
