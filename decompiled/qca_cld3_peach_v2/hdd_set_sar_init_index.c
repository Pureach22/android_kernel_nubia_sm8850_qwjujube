__int64 __fastcall hdd_set_sar_init_index(
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
  if ( !result )
    return qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx NULL", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_set_sar_init_index");
  if ( !*(_DWORD *)(result + 3688) )
    return qdf_trace_msg(0x33u, 8u, "FW SAR version: %d", a2, a3, a4, a5, a6, a7, a8, a9, 0);
  if ( (*(_BYTE *)(*(_QWORD *)(result + 104) + 172LL) & 2) != 0 )
    return hdd_configure_sar_index();
  return result;
}
