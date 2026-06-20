__int64 __fastcall cam_sfe_bus_init_hw(int *a1)
{
  int v1; // w20
  unsigned int v2; // w8
  int v3; // w19
  int v4; // w0

  if ( a1 )
  {
    v1 = debug_mdl;
    v2 = 0;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      v3 = *a1;
      v4 = cam_io_r_mb(*((_QWORD *)a1 + 1) + **((unsigned int **)a1 + 3));
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v1 & 0x40000000,
        4,
        "cam_sfe_bus_init_hw",
        1905,
        "SFE:%d bus-rd hw-version:0x%x",
        v3,
        v4);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_init_hw",
      1898,
      "Invalid args");
    return (unsigned int)-22;
  }
  return v2;
}
