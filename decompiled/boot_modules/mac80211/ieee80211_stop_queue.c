__int64 __fastcall ieee80211_stop_queue(__int64 a1, unsigned int a2)
{
  __int64 v4; // x21

  v4 = raw_spin_lock_irqsave(a1 + 1312);
  _ieee80211_stop_queue(a1, a2, 0, 0);
  return raw_spin_unlock_irqrestore(a1 + 1312, v4);
}
