__int64 __fastcall cam_common_util_thread_switch_delay_detect(
        const char *a1,
        const char *a2,
        const void *a3,
        __int64 a4,
        unsigned int a5)
{
  __int64 result; // x0
  unsigned __int64 v11; // x28
  __int64 v12; // x24
  __int64 v13; // x23
  __int64 v14; // x1
  __int64 v15; // x25
  __int64 v16; // x24
  __int64 v17; // x1
  __int64 v18; // x26
  __int64 v19; // x0

  result = ktime_get_with_offset(1);
  v11 = (result - a4) / 1000000;
  if ( v11 > a5 )
  {
    v12 = result;
    v13 = ns_to_timespec64(a4);
    v15 = v14;
    v16 = ns_to_timespec64(v12);
    v18 = v17;
    if ( (unsigned int)__ratelimit(
                         &cam_common_util_thread_switch_delay_detect__rs,
                         "cam_common_util_thread_switch_delay_detect") )
      v19 = 3;
    else
      v19 = 2;
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             v19,
             0x20000,
             2,
             "cam_common_util_thread_switch_delay_detect",
             166,
             "%s cb: %ps delay in %s detected %ld:%06ld cur %ld:%06ld\ndiff %ld: threshold %d",
             a1,
             a3,
             a2,
             v13,
             v15 / 1000,
             v16,
             v18 / 1000,
             v11,
             a5);
  }
  return result;
}
