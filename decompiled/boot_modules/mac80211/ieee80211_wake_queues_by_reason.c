__int64 __fastcall ieee80211_wake_queues_by_reason(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v7; // x0
  int v8; // w8
  signed int next_bit; // w22
  __int64 result; // x0
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = a2;
  v7 = raw_spin_lock_irqsave(a1 + 1312);
  v8 = 0;
  v11 = v7;
  while ( 1 )
  {
    next_bit = find_next_bit(v12, *(unsigned __int16 *)(a1 + 128), v8);
    if ( next_bit >= *(unsigned __int16 *)(a1 + 128) )
      break;
    _ieee80211_wake_queue(a1, next_bit, a3, a4 & 1, (__int64)&v11);
    v8 = next_bit + 1;
  }
  result = raw_spin_unlock_irqrestore(a1 + 1312, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
