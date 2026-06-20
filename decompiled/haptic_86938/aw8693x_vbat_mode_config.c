__int64 __fastcall aw8693x_vbat_mode_config(__int64 a1, char a2)
{
  return i2c_w_bits(a1, 76, 4294967231LL, (unsigned __int8)(a2 == 1) << 6);
}
