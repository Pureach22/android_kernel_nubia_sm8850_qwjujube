__int64 __fastcall target_if_green_ap_set_ps_on_off(
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
    if ( v9 && *v9 )
    {
      return wmi_unified_green_ap_ps_send(*v9);
    }
    else
    {
      qdf_trace_msg(0x5Du, 2u, "%s: null wmi_hdl", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_green_ap_set_ps_on_off");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: pdev context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_green_ap_set_ps_on_off");
    return 4;
  }
}
