__int64 __fastcall rtc6226_q_event(__int64 a1, char a2)
{
  __int64 v3; // x20
  int v4; // w21
  __int64 result; // x0
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = a2;
  v3 = raw_spin_lock_irqsave(a1 + 1976);
  v4 = _kfifo_in(a1 + 3160, v6, 1);
  result = raw_spin_unlock_irqrestore(a1 + 1976, v3);
  if ( v4 )
    result = _wake_up(a1 + 2520, 1, 1, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
