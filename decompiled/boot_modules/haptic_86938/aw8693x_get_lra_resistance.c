__int64 __fastcall aw8693x_get_lra_resistance(__int64 a1)
{
  char v2; // w20
  char v3; // w21
  __int64 result; // x0
  _BYTE v5[4]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v6 = 0;
  aw8693x_stop(a1);
  i2c_w_bits(a1, 69, 4294967291LL, 4);
  usleep_range_state(500, 600, 2);
  i2c_w_bits(a1, 78, 4294967175LL, 24);
  i2c_r_bytes(a1, 77, v5, 1);
  v2 = v5[0];
  i2c_r_bytes(a1, 78, v5, 1);
  v3 = v5[0];
  i2c_w_bits(a1, 78, 4294967288LL, 4);
  i2c_w_bits(a1, 77, 4294967280LL, 5);
  usleep_range_state(3000, 3500, 2);
  i2c_w_bits(a1, 77, 4294967292LL, 0);
  i2c_w_bits(a1, 69, 4294967291LL, 0);
  i2c_w_bits(a1, 77, 4294967283LL, v2 & 0xC);
  i2c_w_bits(a1, 78, 4294967288LL, v3 & 7);
  result = i2c_r_bytes(a1, 79, &v6, 2);
  *(_DWORD *)(a1 + 100) = (unsigned int)((1719666281
                                        * (unsigned __int64)(610000 * (HIBYTE(v6) | ((unsigned __int8)(v6 & 3) << 8)))) >> 32) >> 12;
  _ReadStatusReg(SP_EL0);
  return result;
}
