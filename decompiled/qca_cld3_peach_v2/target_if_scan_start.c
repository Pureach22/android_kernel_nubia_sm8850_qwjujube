__int64 __fastcall target_if_scan_start(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x8

  if ( a1 )
  {
    v10 = *(_QWORD **)(a1 + 1240);
    if ( v10 )
    {
      if ( *v10 )
        return wmi_unified_scan_start_cmd_send(*v10, a2 + 8);
    }
  }
  qdf_trace_msg(0x49u, 2u, "%s: Invalid PDEV WMI handle", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_scan_start");
  return 16;
}
