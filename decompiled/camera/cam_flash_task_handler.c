__int64 __fastcall cam_flash_task_handler(_QWORD *a1, const void *a2)
{
  if ( a1 && a2 )
  {
    hrtimer_start_range_ns(a1 + 844, 1000000LL * a1[860], 0, 1);
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_task_handler",
      469,
      "Invalid params: data:%pK priv:%pK",
      a2,
      a1);
    return 4294967274LL;
  }
}
