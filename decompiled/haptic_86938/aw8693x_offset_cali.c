__int64 __fastcall aw8693x_offset_cali(__int64 a1)
{
  __int64 v2; // x3
  unsigned __int64 v3; // x8
  int v4; // w8
  int v5; // w19
  __int64 result; // x0
  __int16 v7; // [xsp+4h] [xbp-Ch] BYREF
  char v8; // [xsp+6h] [xbp-Ah]
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 1173);
  v8 = 0;
  v7 = 0;
  i2c_w_bits(a1, 78, 4294967288LL, v2);
  i2c_w_bits(a1, 69, 4294967291LL, 4);
  usleep_range_state(500, 600, 2);
  i2c_w_bits(a1, 78, 4294967175LL, 32);
  i2c_w_bits(a1, 77, 4294967292LL, 1);
  usleep_range_state(3000, 3500, 2);
  i2c_w_bits(a1, 77, 4294967292LL, 0);
  i2c_r_bytes(a1, 79, &v7, 2);
  i2c_w_bits(a1, 69, 4294967291LL, 0);
  v3 = *(unsigned __int8 *)(a1 + 1173);
  if ( v3 >= 8 )
  {
    printk(&unk_151CE, "haptic_hv", 1545, "aw8693x_offset_cali");
    v4 = 0;
  }
  else
  {
    v4 = dword_16BBC[v3];
  }
  v5 = (2440 * (HIBYTE(v7) | ((v7 & 3) << 8)) - 1249280) / v4;
  result = printk(&unk_16780, "haptic_hv", 1550, "aw8693x_offset_cali");
  if ( (unsigned int)(v5 - 16) <= 0xFFFFFFE0 )
    result = printk(&unk_15C5B, "haptic_hv", 1552, "aw8693x_offset_cali");
  _ReadStatusReg(SP_EL0);
  return result;
}
