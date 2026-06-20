__int64 __fastcall sub_77A38(long double a1, long double a2, long double a3, uint64x2_t a4)
{
  uint32x2_t v4; // d20

  return venus_hfi_queue_super_buffer(a1, a2, a3, COERCE_LONG_DOUBLE(vmlsl_lane_u32(a4, v4, *(uint32x2_t *)&a2, 0)));
}
