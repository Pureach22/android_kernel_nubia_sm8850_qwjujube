__int64 __fastcall target_if_coex_config_send(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x8

  if ( a1 )
  {
    v9 = *(__int64 **)(a1 + 1232);
    if ( v9 )
    {
      if ( *v9 )
        return wmi_unified_send_coex_config_cmd(*v9);
    }
  }
  qdf_trace_msg(0x70u, 2u, "%s: Invalid PDEV WMI handle", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_coex_config_send");
  return 16;
}
