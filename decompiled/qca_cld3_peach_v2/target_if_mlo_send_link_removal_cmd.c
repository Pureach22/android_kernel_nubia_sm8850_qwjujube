__int64 __fastcall target_if_mlo_send_link_removal_cmd(
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
    if ( v9 && *(_QWORD *)(v9 + 16) )
    {
      return wmi_send_mlo_link_removal_cmd();
    }
    else
    {
      qdf_trace_msg(0x49u, 2u, "%s: null handle", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_mlo_send_link_removal_cmd");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: null psoc", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_mlo_send_link_removal_cmd");
    return 29;
  }
}
