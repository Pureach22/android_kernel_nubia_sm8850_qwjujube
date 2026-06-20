__int64 __fastcall sub_3E1210(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        int64x2_t a8)
{
  int32x4_t v8; // q8
  int32x4_t v9; // q15

  return dot11f_unpack_ie_chan_switch_ann(a1, a2, a3, a4, a5, a6, a7, COERCE_LONG_DOUBLE(vqdmlsl_high_s32(a8, v8, v9)));
}
