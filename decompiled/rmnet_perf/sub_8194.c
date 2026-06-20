__int64 __fastcall sub_8194(long double a1, long double a2, long double a3, long double a4, long double a5)
{
  uint8x16_t v5; // q21
  uint8x16_t v6; // q28

  return rmnet_perf_ingress_tcp_ecn(a1, a2, a3, a4, a5, COERCE_LONG_DOUBLE(vqaddq_u8(v5, v6)));
}
