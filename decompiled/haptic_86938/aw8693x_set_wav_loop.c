__int64 __fastcall aw8693x_set_wav_loop(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  __int64 v3; // x3
  __int64 v4; // x2

  v3 = a3;
  if ( (a2 & 1) != 0 )
  {
    v4 = 4294967280LL;
  }
  else
  {
    v3 = 16 * a3;
    v4 = 4294967055LL;
  }
  return i2c_w_bits(a1, (unsigned int)(a2 >> 1) + 18, v4, v3);
}
