__int64 __fastcall init_deinit_is_service_ext_msg(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  if ( a10 )
  {
    if ( (wmi_service_enabled(*(_QWORD *)(a10 + 16), 92) & 1) != 0 )
      return 0;
    else
      return 16;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc target_psoc_info is null in service ext msg",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "init_deinit_is_service_ext_msg");
    return 4;
  }
}
