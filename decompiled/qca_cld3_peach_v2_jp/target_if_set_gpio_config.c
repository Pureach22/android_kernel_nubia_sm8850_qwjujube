__int64 __fastcall target_if_set_gpio_config(
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
  __int64 v9; // x8

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 )
    {
      if ( *(_QWORD *)(v9 + 16) )
        return wmi_unified_gpio_config_cmd_send();
    }
  }
  qdf_trace_msg(0x49u, 2u, "%s: wmi_handle is null.", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_set_gpio_config");
  return 29;
}
