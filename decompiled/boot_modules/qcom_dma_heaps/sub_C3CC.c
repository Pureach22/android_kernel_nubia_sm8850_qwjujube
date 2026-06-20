__int64 __fastcall sub_C3CC(long double a1)
{
  int16x8_t v1; // q17
  int16x8_t v2; // q24

  return get_vmperm_from_ion_flags(a1, COERCE_LONG_DOUBLE(vaddq_s16(v2, v1)));
}
