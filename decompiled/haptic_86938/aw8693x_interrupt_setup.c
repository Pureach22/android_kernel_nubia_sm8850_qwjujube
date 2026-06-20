__int64 __fastcall aw8693x_interrupt_setup(__int64 a1)
{
  __int64 result; // x0
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  i2c_r_bytes(a1, 2, v3, 1);
  i2c_w_bits(a1, 70, 4294967271LL, 8);
  result = i2c_w_bits(a1, 3, 4294967065LL, 64);
  _ReadStatusReg(SP_EL0);
  return result;
}
