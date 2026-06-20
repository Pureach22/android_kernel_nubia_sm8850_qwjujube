__int64 __fastcall aw8693x_set_rtp_aei(__int64 a1, char a2)
{
  __int64 v2; // x3

  if ( (a2 & 1) != 0 )
    v2 = 0;
  else
    v2 = 16;
  return i2c_w_bits(a1, 3, 4294967279LL, v2);
}
