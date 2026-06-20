__int64 __fastcall hdd_sta_info_deinit(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v9; // x2
  const char *v10; // x3

  if ( result )
  {
    if ( !*(_DWORD *)(result + 16) )
      return result;
    v9 = "%s: list length not equal to zero";
    v10 = "qdf_list_destroy";
  }
  else
  {
    v9 = "%s: Parameter null";
    v10 = "hdd_sta_info_deinit";
  }
  return qdf_trace_msg(0x33u, 2u, v9, a2, a3, a4, a5, a6, a7, a8, a9, v10);
}
