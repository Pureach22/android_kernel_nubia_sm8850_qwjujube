__int64 __fastcall rtc6226_enable(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w22
  __int64 v4; // x20
  __int64 v5; // x0
  char *v6; // x1
  int v7; // w21
  char v8; // [xsp+0h] [xbp-10h] BYREF
  char v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ((void (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 6);
  result = rtc6226_power_up(a1);
  if ( (result & 0x80000000) == 0 )
  {
    if ( (*(_WORD *)(a1 + 1770) & 0x4000) != 0 )
    {
      v3 = result;
      v9 = 0;
      v4 = raw_spin_lock_irqsave(a1 + 1976);
      v5 = a1 + 3160;
      v6 = &v9;
    }
    else
    {
      *(_WORD *)(a1 + 1770) |= 0xC000u;
      v3 = rtc6226_set_register(a1, 4);
      if ( (v3 & 0x80000000) != 0 )
      {
        printk(&unk_CEB0, "rtc6226_enable");
LABEL_9:
        result = v3;
        goto LABEL_10;
      }
      v8 = 0;
      v4 = raw_spin_lock_irqsave(a1 + 1976);
      v5 = a1 + 3160;
      v6 = &v8;
    }
    v7 = _kfifo_in(v5, v6, 1);
    raw_spin_unlock_irqrestore(a1 + 1976, v4);
    if ( v7 )
      _wake_up(a1 + 2520, 1, 1, 0);
    *(_DWORD *)(a1 + 1756) = 1;
    goto LABEL_9;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
