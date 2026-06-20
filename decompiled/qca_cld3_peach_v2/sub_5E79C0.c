__int64 __fastcall sub_5E79C0(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        double a6,
        double a7,
        int8x16_t a8)
{
  int8x16_t v8; // q13

  return wmi_unified_action_frame_patterns_cmd(a1, a2, a3, a4, a5, COERCE_LONG_DOUBLE(vextq_s8(a8, v8, 7u)));
}
