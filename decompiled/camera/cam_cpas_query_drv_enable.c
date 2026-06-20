__int64 __fastcall cam_cpas_query_drv_enable(unsigned __int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0

  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    if ( a1 | a2 )
    {
      v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL) + 3392LL);
      if ( a1 )
        *(_BYTE *)a1 = *(_BYTE *)(v2 + 1609);
      result = 0;
      if ( a2 )
        *(_BYTE *)a2 = *(_BYTE *)(v2 + 1610);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_query_drv_enable",
        248,
        "invalid input ddr: %pK clk: %pK",
        nullptr,
        nullptr);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_query_drv_enable",
      242,
      "cpas intf not initialized");
    return 4294967277LL;
  }
  return result;
}
