__int64 __fastcall sub_521E38(
        long double a1,
        long double a2,
        long double a3,
        int16x4_t a4,
        double a5,
        double a6,
        double a7,
        int16x4_t a8)
{
  return hal_rx_mpdu_get_addr2_be(a1, a2, a3, vmls_laneq_s16(a4, a8, *(int16x8_t *)&a2, 7).n64_f64[0]);
}
