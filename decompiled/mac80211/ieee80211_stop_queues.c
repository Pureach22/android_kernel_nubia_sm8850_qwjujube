__int64 __fastcall ieee80211_stop_queues(__int64 a1)
{
  __int64 v2; // x20
  int i; // w8
  signed int next_bit; // w21
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0xFFFF;
  v2 = raw_spin_lock_irqsave(a1 + 1312);
  for ( i = 0; ; i = next_bit + 1 )
  {
    next_bit = find_next_bit(v6, *(unsigned __int16 *)(a1 + 128), i);
    if ( next_bit >= *(unsigned __int16 *)(a1 + 128) )
      break;
    _ieee80211_stop_queue(a1, next_bit, 0, 0);
  }
  result = raw_spin_unlock_irqrestore(a1 + 1312, v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
