__int64 __fastcall ieee80211_add_pending_skb(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x21
  __int64 v5; // x8
  __int64 *v6; // x10
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a2 + 64) )
  {
    v4 = ((unsigned __int64)*(unsigned int *)(a2 + 44) >> 17) & 0xF;
    v8[0] = raw_spin_lock_irqsave(a1 + 1312);
    _ieee80211_stop_queue(a1, v4, 5u, 0);
    v5 = a1 + 24LL * (unsigned int)v4;
    v6 = *(__int64 **)(v5 + 2008);
    *(_QWORD *)a2 = v5 + 2000;
    *(_QWORD *)(a2 + 8) = v6;
    *(_QWORD *)(v5 + 2008) = a2;
    *v6 = a2;
    ++*(_DWORD *)(v5 + 2016);
    _ieee80211_wake_queue(a1, v4, 5u, 0, (__int64)v8);
    result = raw_spin_unlock_irqrestore(a1 + 1312, v8[0]);
  }
  else
  {
    __break(0x800u);
    result = ieee80211_free_txskb(a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
