__int64 __fastcall sub_2B9D10(long double a1, int32x4_t a2, double a3, int32x4_t a4)
{
  return dsc_driver_op_stop(a1, COERCE_LONG_DOUBLE(vsubq_s32(a4, a2)));
}
