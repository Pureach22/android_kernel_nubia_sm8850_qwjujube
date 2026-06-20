__int64 __fastcall rtc6226_cancel_seek(__int64 a1)
{
  unsigned int v2; // w19
  int v3; // w8
  __int64 v4; // x21
  int v5; // w22
  char v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 1872);
  *(_WORD *)(a1 + 1772) &= ~0x8000u;
  v2 = rtc6226_set_register(a1, 5);
  complete(a1 + 3448);
  mutex_unlock(a1 + 1872);
  v3 = *(unsigned __int8 *)(a1 + 1929);
  *(_BYTE *)(a1 + 1928) = 1;
  if ( !v3 )
  {
    v7[0] = 2;
    v4 = raw_spin_lock_irqsave(a1 + 1976);
    v5 = _kfifo_in(a1 + 3160, v7, 1);
    raw_spin_unlock_irqrestore(a1 + 1976, v4);
    if ( v5 )
      _wake_up(a1 + 2520, 1, 1, 0);
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
