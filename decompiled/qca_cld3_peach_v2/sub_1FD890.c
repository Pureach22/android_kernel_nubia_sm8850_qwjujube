__int64 __fastcall sub_1FD890(long double a1, long double a2, long double a3)
{
  int16x8_t v3; // q9
  int16x8_t v4; // q20

  return reg_is_2ghz_op_class(a1, a2, a3, COERCE_LONG_DOUBLE(vqrdmulhq_s16(v3, v4)));
}
