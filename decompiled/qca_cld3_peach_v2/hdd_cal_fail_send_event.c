__int64 __fastcall hdd_cal_fail_send_event(
        unsigned __int8 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  return qdf_trace_msg(
           0x33u,
           8u,
           "%s: Received cal failure event with cal_type:%x reason:%x",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "hdd_cal_fail_send_event",
           a1,
           a2);
}
