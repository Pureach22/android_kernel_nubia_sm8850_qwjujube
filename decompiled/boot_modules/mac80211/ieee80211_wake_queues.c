__int64 __fastcall ieee80211_wake_queues(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w8
  signed int next_bit; // w20
  __int64 result; // x0
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v7[2]; // [xsp+10h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0xFFFF;
  v2 = raw_spin_lock_irqsave(a1 + 1312);
  v3 = 0;
  v6 = v2;
  while ( 1 )
  {
    next_bit = find_next_bit(v7, *(unsigned __int16 *)(a1 + 128), v3);
    if ( next_bit >= *(unsigned __int16 *)(a1 + 128) )
      break;
    _ieee80211_wake_queue(a1, next_bit, 0, 0, (__int64)&v6);
    v3 = next_bit + 1;
  }
  result = raw_spin_unlock_irqrestore(a1 + 1312, v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
