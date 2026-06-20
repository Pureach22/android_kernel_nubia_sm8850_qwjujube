__int64 __fastcall aw8693x_irq_clear(__int64 a1)
{
  __int64 result; // x0
  _BYTE v2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  i2c_r_bytes(a1, 2, v2, 1);
  result = printk(&unk_15956, "haptic_hv", 1099, "aw8693x_irq_clear");
  _ReadStatusReg(SP_EL0);
  return result;
}
