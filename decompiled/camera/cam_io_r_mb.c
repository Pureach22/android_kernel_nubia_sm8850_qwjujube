__int64 __fastcall cam_io_r_mb(const void *a1)
{
  __int64 result; // x0
  unsigned int v3; // w20

  if ( a1 )
  {
    result = readl_0();
    if ( (debug_mdl & 0x20000000) != 0 && !debug_priority )
    {
      v3 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000000,
        4,
        "cam_io_r_mb",
        62,
        "0x%pK %08x",
        a1,
        result);
      return v3;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000000,
      1,
      "cam_io_r_mb",
      57,
      "Invalid args");
    return 0;
  }
  return result;
}
