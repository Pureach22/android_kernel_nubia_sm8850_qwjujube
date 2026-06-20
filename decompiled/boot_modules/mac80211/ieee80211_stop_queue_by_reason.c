__int64 __fastcall ieee80211_stop_queue_by_reason(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __int64 v8; // x23

  v8 = raw_spin_lock_irqsave(a1 + 1312);
  _ieee80211_stop_queue(a1, a2, a3, a4);
  return raw_spin_unlock_irqrestore(a1 + 1312, v8);
}
