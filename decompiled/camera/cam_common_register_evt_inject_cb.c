__int64 __fastcall cam_common_register_evt_inject_cb(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned __int8 v3; // w8
  const char *v4; // x6

  if ( (unsigned __int8)byte_394040 >= 3u )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_register_evt_inject_cb",
      402,
      "No free index available");
    return 4294967274LL;
  }
  if ( !a1 || a2 >= 3 )
  {
    if ( a1 )
      v4 = "Non-NULL";
    else
      v4 = "NULL";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_register_evt_inject_cb",
      408,
      "Invalid params evt_inject_cb %s hw_id: %d",
      v4,
      a2);
    return 4294967274LL;
  }
  g_inject_evt_info[a2] = a1;
  result = 0;
  v3 = ++byte_394040;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_common_register_evt_inject_cb",
      415,
      "Evt inject cb registered for HW_id: %d, total registered: %d",
      a2,
      v3);
    return 0;
  }
  return result;
}
