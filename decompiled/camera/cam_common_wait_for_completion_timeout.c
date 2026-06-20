__int64 __fastcall cam_common_wait_for_completion_timeout(__int64 a1)
{
  if ( a1 )
  {
    if ( !timeout_multiplier )
      timeout_multiplier = 1;
    return wait_for_completion_timeout();
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_wait_for_completion_timeout",
      82,
      "Null complete pointer");
    return 0;
  }
}
