__int64 __fastcall sub_4002FC(long double a1, long double a2)
{
  int16x8_t v2; // q14
  int16x8_t v3; // q16

  return dot11f_pack_tdls_setup_cnf(a1, a2, COERCE_LONG_DOUBLE(vrhaddq_s16(v2, v3)));
}
