__int64 __fastcall aw8693x_cont_config(_BYTE *a1)
{
  __int64 result; // x0
  char v3[4]; // [xsp+0h] [xbp-10h] BYREF
  char v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = -1;
  printk(&unk_156A1, "haptic_hv", 629, "aw8693x_play_mode");
  a1[23] = 4;
  i2c_w_bits(a1, 8, 4294967292LL, 2);
  i2c_w_bits(a1, 8, 4294967291LL, 4);
  printk(&unk_143C9, "haptic_hv", 510, "aw8693x_bst_mode_config");
  i2c_w_bits(a1, 6, 4294967263LL, 0);
  i2c_w_bits(a1, 76, 4294967231LL, 64);
  i2c_w_bits(a1, 29, 4294967167LL, (unsigned __int8)a1[1216] << 7);
  i2c_w_bits(a1, 29, 4294967168LL, (unsigned __int8)a1[1178]);
  i2c_w_bytes(a1, 30, a1 + 1179, 1);
  i2c_w_bytes(a1, 32, v3, 1);
  printk(&unk_14720, "haptic_hv", 471, "aw8693x_play_go");
  v4[0] = 1;
  result = i2c_w_bytes(a1, 9, v4, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
