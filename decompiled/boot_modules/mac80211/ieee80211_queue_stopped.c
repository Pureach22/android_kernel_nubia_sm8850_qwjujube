__int64 __fastcall ieee80211_queue_stopped(__int64 a1, int a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x20

  if ( *(unsigned __int16 *)(a1 + 128) <= a2 )
  {
    __break(0x800u);
    LODWORD(v8) = 1;
    return (unsigned int)v8;
  }
  v4 = raw_spin_lock_irqsave(a1 + 1312);
  if ( (unsigned int)a2 < 0x11 )
  {
    v8 = *(_QWORD *)(a1 + 8LL * (unsigned int)a2 + 480) & 1LL;
    raw_spin_unlock_irqrestore(a1 + 1312, v4);
    return (unsigned int)v8;
  }
  __break(0x5512u);
  return ieee80211_wake_queues_by_reason(v4, v5, v6, v7);
}
