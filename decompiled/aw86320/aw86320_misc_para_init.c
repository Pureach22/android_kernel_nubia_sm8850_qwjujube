__int64 __fastcall aw86320_misc_para_init(__int64 a1)
{
  haptic_i2c_write(a1, 0, 0xAAAAu);
  haptic_i2c_write(a1, 64, 0x7D7Du);
  haptic_i2c_write(a1, 18, 0x1108u);
  haptic_i2c_write(a1, 54, 0x2825u);
  haptic_i2c_write(a1, 66, 0x1800u);
  haptic_i2c_write(a1, 70, 0x103Au);
  haptic_i2c_write(a1, 71, 0x13E5u);
  haptic_i2c_write(a1, 72, 0x869Cu);
  haptic_i2c_write(a1, 74, 0x805u);
  return haptic_i2c_write(a1, 75, 0x8000u);
}
