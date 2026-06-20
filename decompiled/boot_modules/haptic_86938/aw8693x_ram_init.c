__int64 __fastcall aw8693x_ram_init(__int64 a1, char a2)
{
  if ( (a2 & 1) == 0 )
    return i2c_w_bits(a1, 69, 4294967291LL, 0);
  i2c_w_bits(a1, 69, 4294967291LL, 4);
  return usleep_range_state(500, 600, 2);
}
