__int64 __fastcall aw8693x_set_bst_vol(__int64 a1, unsigned __int8 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x3

  if ( a2 <= 5u )
    v2 = 5;
  else
    v2 = a2;
  if ( v2 >= 0x19 )
    v3 = 25;
  else
    v3 = v2;
  return i2c_w_bits(a1, 6, 4294967264LL, v3);
}
