__int64 __fastcall sub_1CF4F4(long double a1, long double a2, long double a3, long double a4, long double a5)
{
  float32x4_t v5; // q16

  return mlme_set_osif_twt_cb(a1, a2, a3, a4, a5, COERCE_LONG_DOUBLE(vmulq_laneq_f32(v5, *(float32x4_t *)&a1, 3)));
}
