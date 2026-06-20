__int64 __fastcall sub_7DB0(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7)
{
  int16x4_t v7; // d24

  return trace_event_raw_event_qseecom_process_listener_from_smcinvoke_ret(
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           vceq_s16(*(int16x4_t *)&a2, v7).n64_f64[0]);
}
