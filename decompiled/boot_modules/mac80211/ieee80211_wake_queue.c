__int64 __fastcall ieee80211_wake_queue(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = raw_spin_lock_irqsave(a1 + 1312);
  _ieee80211_wake_queue(a1, a2, 0, 0, (__int64)v5);
  result = raw_spin_unlock_irqrestore(a1 + 1312, v5[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
