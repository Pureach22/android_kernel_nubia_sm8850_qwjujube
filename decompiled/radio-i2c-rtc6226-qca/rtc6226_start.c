__int64 __fastcall rtc6226_start(__int64 a1)
{
  unsigned int v2; // w20
  int v3; // w2
  bool v4; // cf
  unsigned int v5; // w20
  int v6; // w2
  __int64 result; // x0
  _WORD v8[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  *(_WORD *)(a1 + 1778) = 0;
  *(_WORD *)(a1 + 1762) = 5802;
  if ( (rtc6226_set_register(a1, 0) & 0x80000000) != 0 )
  {
    v2 = 0;
    do
    {
      v3 = rtc6226_set_register(a1, 0);
      if ( (v3 & 0x80000000) == 0 )
        break;
      v4 = v2++ >= 9;
    }
    while ( !v4 );
    if ( v3 < 0 )
      printk(&unk_D8CE, "rtc6226_start");
  }
  msleep(30);
  *(_WORD *)(a1 + 1762) = -26966;
  if ( (rtc6226_set_register(a1, 0) & 0x80000000) != 0 )
  {
    v5 = 0;
    do
    {
      v6 = rtc6226_set_register(a1, 0);
      if ( (v6 & 0x80000000) == 0 )
        break;
      v4 = v5++ >= 9;
    }
    while ( !v4 );
    if ( v6 < 0 )
      printk(&unk_DB3E, "rtc6226_start");
  }
  msleep(30);
  ((void (__fastcall *)(__int64, _QWORD))rtc6226_get_register)(a1, 0);
  ((void (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 1);
  result = rtc6226_get_all_registers(a1);
  if ( (result & 0x80000000) == 0 )
  {
    v8[0] = 56;
    result = rtc6226_set_serial_registers(a1, v8, 64);
    if ( (result & 0x80000000) == 0 )
    {
      v8[0] = -16128;
      result = rtc6226_set_serial_registers(a1, v8, 142);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
