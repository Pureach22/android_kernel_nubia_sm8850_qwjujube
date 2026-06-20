__int64 __fastcall sub_10D90C(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7)
{
  uint8x16_t v7; // q15

  return cam_soc_util_get_clk_level(
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           COERCE_LONG_DOUBLE(veorq_u8(veorq_u8(v7, *(uint8x16_t *)&a7), *(uint8x16_t *)&a4)));
}
