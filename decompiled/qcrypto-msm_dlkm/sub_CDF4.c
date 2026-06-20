__int64 __fastcall sub_CDF4(long double a1, long double a2, double a3, double a4, double a5, double a6, uint8x16_t a7)
{
  uint8x16_t v7; // q9
  uint8x16_t v8; // q23

  return qcrypto_dec_des_ecb(a1, a2, COERCE_LONG_DOUBLE(veorq_u8(veorq_u8(a7, v7), v8)));
}
