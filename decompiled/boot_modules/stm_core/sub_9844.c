__int64 __fastcall sub_9844(long double a1, long double a2, long double a3, long double a4, long double a5)
{
  int8x16_t v5; // q17

  return stp_policy_make(a1, a2, a3, a4, a5, COERCE_LONG_DOUBLE(vsubw_high_s8(*(int16x8_t *)&a1, v5)));
}
