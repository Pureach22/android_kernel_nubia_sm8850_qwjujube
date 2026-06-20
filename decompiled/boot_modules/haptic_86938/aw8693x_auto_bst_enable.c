__int64 __fastcall aw8693x_auto_bst_enable(__int64 a1, char a2)
{
  *(_BYTE *)(a1 + 24) = a2;
  return i2c_w_bits(a1, 8, 4294967279LL, 16 * (unsigned int)(a2 != 0));
}
