__int64 __fastcall ieee80211_stop_queues_by_reason(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v7; // x22
  int i; // w8
  signed int next_bit; // w23
  __int64 result; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = a2;
  v7 = raw_spin_lock_irqsave(a1 + 1312);
  for ( i = 0; ; i = next_bit + 1 )
  {
    next_bit = find_next_bit(v11, *(unsigned __int16 *)(a1 + 128), i);
    if ( next_bit >= *(unsigned __int16 *)(a1 + 128) )
      break;
    _ieee80211_stop_queue(a1, next_bit, a3, a4 & 1);
  }
  result = raw_spin_unlock_irqrestore(a1 + 1312, v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
