__int64 __fastcall ieee80211_wake_queue_by_reason(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = raw_spin_lock_irqsave(a1 + 1312);
  _ieee80211_wake_queue(a1, a2, a3, a4, v9);
  result = raw_spin_unlock_irqrestore(a1 + 1312, v9[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
