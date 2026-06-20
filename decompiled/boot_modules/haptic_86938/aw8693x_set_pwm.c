__int64 __fastcall aw8693x_set_pwm(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x3

  if ( a2 > 1u )
  {
    if ( a2 == 2 )
    {
      v2 = 64;
      return i2c_w_bits(a1, 70, 4294967199LL, v2);
    }
    if ( a2 == 3 )
    {
      v2 = 96;
      return i2c_w_bits(a1, 70, 4294967199LL, v2);
    }
    return printk(&unk_14236, "haptic_hv", 342, "aw8693x_set_pwm");
  }
  if ( !a2 )
  {
    v2 = 32;
    return i2c_w_bits(a1, 70, 4294967199LL, v2);
  }
  if ( a2 != 1 )
    return printk(&unk_14236, "haptic_hv", 342, "aw8693x_set_pwm");
  v2 = 0;
  return i2c_w_bits(a1, 70, 4294967199LL, v2);
}
