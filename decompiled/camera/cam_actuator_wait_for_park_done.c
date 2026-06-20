__int64 __fastcall cam_actuator_wait_for_park_done(__int64 a1)
{
  if ( cam_common_wait_for_completion_timeout(a1 + 4736) )
    return 0;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x2000,
    1,
    "cam_actuator_wait_for_park_done",
    532,
    "Async park done completion timeout");
  return 4294967186LL;
}
