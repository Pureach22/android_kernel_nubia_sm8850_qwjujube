__int64 __fastcall sub_4AA3F0(long double a1, long double a2, long double a3, long double a4, long double a5, float a6)
{
  short float v6; // h25
  short float v7; // h26

  *(short float *)&a6 = v6 - (short float)(*(short float *)&a6 * v7);
  return dp_mlo_tx_pool_unmap_be(a1, a2, a3, a4, a5, a6);
}
