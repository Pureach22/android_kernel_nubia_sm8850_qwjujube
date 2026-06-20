__int64 __fastcall aw8693x_get_vbat(__int64 a1)
{
  unsigned int v2; // w20
  unsigned __int64 v3; // x4
  __int64 result; // x0
  __int16 v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  aw8693x_stop(a1);
  i2c_w_bits(a1, 69, 4294967291LL, 4);
  usleep_range_state(500, 600, 2);
  i2c_w_bits(a1, 78, 4294967175LL, 0);
  i2c_w_bits(a1, 77, 4294967292LL, 1);
  usleep_range_state(3000, 3500, 2);
  i2c_w_bits(a1, 77, 4294967292LL, 0);
  i2c_r_bytes(a1, 79, &v5, 2);
  i2c_w_bits(a1, 69, 4294967291LL, 0);
  v2 = HIBYTE(v5) | ((v5 & 3) << 8);
  v3 = (8396809 * (unsigned __int64)(6100 * v2)) >> 33;
  *(_DWORD *)(a1 + 104) = (unsigned int)((8396809 * (unsigned __int64)(6100 * v2)) >> 32) >> 1;
  if ( v2 >= 0x2F3 )
  {
    *(_DWORD *)(a1 + 104) = 4500;
    printk(&unk_16AA9, "haptic_hv", 1495, "aw8693x_get_vbat");
    LODWORD(v3) = *(_DWORD *)(a1 + 104);
  }
  if ( (unsigned int)v3 <= 0xBB7 )
  {
    *(_DWORD *)(a1 + 104) = 3000;
    printk(&unk_14F20, "haptic_hv", 1499, "aw8693x_get_vbat");
  }
  result = printk(&unk_15329, "haptic_hv", 1501, "aw8693x_get_vbat");
  _ReadStatusReg(SP_EL0);
  return result;
}
