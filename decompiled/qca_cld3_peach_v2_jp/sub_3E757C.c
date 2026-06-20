__int64 __fastcall sub_3E757C(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        float16x8_t a8)
{
  return dot11f_unpack_tdls_peer_traffic_ind(
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           COERCE_LONG_DOUBLE(vmlsq_lane_f16(a8, *(float16x8_t *)&a2, *(float16x4_t *)&a1, 1)));
}
