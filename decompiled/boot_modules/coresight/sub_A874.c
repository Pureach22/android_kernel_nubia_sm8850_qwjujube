__int64 __fastcall sub_A874(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        float a6,
        double a7,
        __n128 a8)
{
  unsigned __int16 v8; // h27

  LOWORD(a6) = vqrshlh_u16(v8, a8.n128_u16[0]);
  return coresight_validate_sink(a1, a2, a3, a4, a5, a6);
}
