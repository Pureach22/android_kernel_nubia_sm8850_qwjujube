__int64 __fastcall cam_sensor_util_get_current_qtimer_ns(unsigned __int64 *a1)
{
  __int64 (*v2)(void); // x8
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x10
  unsigned __int64 v5; // x8
  __int64 result; // x0
  unsigned __int64 v7; // x6

  v2 = (__int64 (*)(void))arch_timer_read_counter;
  if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
    __break(0x8228u);
  v3 = v2();
  if ( !v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_get_current_qtimer_ns",
      150,
      "qtimer returned 0, rc:%d",
      0);
    return 4294967274LL;
  }
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_get_current_qtimer_ns",
      159,
      "NULL pointer passed");
    return 4294967274LL;
  }
  v4 = HIDWORD(v3);
  v5 = 10000LL * (unsigned int)v3;
  result = 0;
  v7 = (((unsigned __int64)(HIDWORD(v5) + 10000LL * (unsigned int)v4) / 0xC0) << 32)
     | (unsigned int)((unsigned __int64)((((unsigned int)v5 & 0xFFFFFFC0
                                         | (((unsigned __int64)(HIDWORD(v5) + 10000LL * (unsigned int)v4) % 0xC0) << 32))
                                        * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
  *a1 = v7;
  if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_util_get_current_qtimer_ns",
      157,
      "Qtimer time: 0x%lx",
      v7);
    return 0;
  }
  return result;
}
