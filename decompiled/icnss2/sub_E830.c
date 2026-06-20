__int64 __fastcall sub_E830(long double a1, long double a2, long double a3, long double a4)
{
  float16x4_t v4; // d13

  return icnss_get_soc_info(a1, a2, a3, a4, vcvta_s16_f16(v4).n64_f64[0]);
}
