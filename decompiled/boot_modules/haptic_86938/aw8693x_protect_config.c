__int64 __fastcall aw8693x_protect_config(__int64 a1, char a2, unsigned __int8 a3)
{
  int v4; // w21
  __int64 result; // x0
  _BYTE v7[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v4 = a3;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = a2;
  i2c_w_bits(a1, 72, 4294967167LL, 0);
  if ( v4 )
  {
    printk(&unk_16079, "haptic_hv", 742, "aw8693x_protect_config");
    v7[0] = a3 | 0x80;
    i2c_w_bytes(a1, 74, v7, 1);
    result = i2c_w_bytes(a1, 75, v8, 1);
  }
  else
  {
    printk(&unk_13F70, "haptic_hv", 749, "aw8693x_protect_config");
    result = i2c_w_bits(a1, 74, 4294967167LL, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
