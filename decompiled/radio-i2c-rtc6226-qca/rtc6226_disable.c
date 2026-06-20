__int64 __fastcall rtc6226_disable(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  unsigned int v4; // w22
  __int64 v5; // x20
  int v6; // w21
  void *v7; // x8
  unsigned int v8; // w19
  char v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_WORD *)(a1 + 1770) &= 0x2FFFu;
  LODWORD(result) = rtc6226_set_register(a1, 4);
  if ( (result & 0x80000000) != 0 )
  {
    v7 = &unk_D2F0;
LABEL_11:
    v8 = result;
    printk(v7, "rtc6226_disable");
    result = v8;
    goto LABEL_8;
  }
  result = rtc6226_power_down((_WORD *)a1);
  if ( (result & 0x80000000) != 0 )
  {
    v7 = &unk_D0B3;
    goto LABEL_11;
  }
  v3 = *(_DWORD *)(a1 + 1756);
  if ( v3 == 4 || v3 == 1 )
  {
    v4 = result;
    v9[0] = 18;
    v5 = raw_spin_lock_irqsave(a1 + 1976);
    v6 = _kfifo_in(a1 + 3160, v9, 1);
    raw_spin_unlock_irqrestore(a1 + 1976, v5);
    if ( v6 )
      _wake_up(a1 + 2520, 1, 1, 0);
    result = v4;
    *(_DWORD *)(a1 + 1756) = 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
