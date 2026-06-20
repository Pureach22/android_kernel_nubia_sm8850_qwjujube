unsigned __int64 *__fastcall cam_common_user_dump_clock(__int64 a1, unsigned __int64 *a2)
{
  if ( a1 && a2 )
  {
    *a2 = cam_soc_util_get_applied_src_clk((_QWORD *)(a1 + 96), 1);
    return a2 + 1;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_common_user_dump_clock",
      307,
      "HW info or address pointer NULL");
    return nullptr;
  }
}
