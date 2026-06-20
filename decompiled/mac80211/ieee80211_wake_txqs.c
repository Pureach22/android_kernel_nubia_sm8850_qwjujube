__int64 __fastcall ieee80211_wake_txqs(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 - 1112;
  v2 = a1 - 2424;
  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = raw_spin_lock_irqsave(a1 - 1112);
  ((void (__fastcall *)(__int64, _QWORD *))ieee80211_wake_txqs)(v2, v4);
  result = raw_spin_unlock_irqrestore(v1, v4[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
