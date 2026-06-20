__int64 __fastcall rtc6226_get_freq(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  int v5; // w21
  unsigned int v6; // w0
  unsigned int v7; // w9
  unsigned int v8; // w20
  __int64 v9; // x21
  __int64 v10; // x0
  char *v11; // x1
  int v12; // w22
  char v13; // [xsp+0h] [xbp-10h] BYREF
  char v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 30);
  if ( (result & 0x80000000) == 0 )
  {
    v5 = *(_WORD *)(a1 + 1822) & 0x7FFF;
    v6 = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 11);
    v7 = *(unsigned __int8 *)(a1 + 1784);
    *a2 = 10 * v5;
    v8 = v6;
    if ( v7 >= *(unsigned __int8 *)(a1 + 1761) )
    {
      v14 = 9;
      v9 = raw_spin_lock_irqsave(a1 + 1976);
      v10 = a1 + 3160;
      v11 = &v14;
    }
    else
    {
      v13 = 8;
      v9 = raw_spin_lock_irqsave(a1 + 1976);
      v10 = a1 + 3160;
      v11 = &v13;
    }
    v12 = _kfifo_in(v10, v11, 1);
    raw_spin_unlock_irqrestore(a1 + 1976, v9);
    if ( v12 )
      _wake_up(a1 + 2520, 1, 1, 0);
    result = v8;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
