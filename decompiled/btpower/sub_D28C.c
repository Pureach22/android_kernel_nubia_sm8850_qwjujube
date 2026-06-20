__int64 __fastcall sub_D28C(long double a1, int64x2_t a2, double a3, double a4, double a5, double a6, int32x4_t a7)
{
  int32x2_t v7; // d21

  return bt_aop_send_msg(a1, COERCE_LONG_DOUBLE(vmlal_laneq_s32(a2, v7, a7, 3)));
}
