__int64 __fastcall ieee80211_add_pending_skbs(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned __int64 v7; // x23
  __int64 v8; // x8
  __int64 *v9; // x9
  unsigned int v10; // w20
  __int64 result; // x0
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = raw_spin_lock_irqsave(a1 + 1312);
  v12[0] = v4;
  v5 = skb_dequeue(a2);
  if ( v5 )
  {
    v6 = v5;
    do
    {
      if ( *(_QWORD *)(v6 + 64) )
      {
        v7 = ((unsigned __int64)*(unsigned int *)(v6 + 44) >> 17) & 0xF;
        _ieee80211_stop_queue(a1, (*(_DWORD *)(v6 + 44) >> 17) & 0xF, 5u, 0);
        v8 = a1 + 2000 + 24LL * (unsigned int)v7;
        v9 = *(__int64 **)(v8 + 8);
        *(_QWORD *)v6 = v8;
        *(_QWORD *)(v6 + 8) = v9;
        *(_QWORD *)(v8 + 8) = v6;
        *v9 = v6;
        ++*(_DWORD *)(v8 + 16);
      }
      else
      {
        __break(0x800u);
        ieee80211_free_txskb(a1, v6);
      }
      v6 = skb_dequeue(a2);
    }
    while ( v6 );
  }
  if ( *(_WORD *)(a1 + 128) )
  {
    v10 = 0;
    do
      _ieee80211_wake_queue(a1, v10++, 5u, 0, (__int64)v12);
    while ( v10 < *(unsigned __int16 *)(a1 + 128) );
    v4 = v12[0];
  }
  result = raw_spin_unlock_irqrestore(a1 + 1312, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
