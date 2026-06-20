__int64 __fastcall target_if_dlm_send_reject_ap_list(
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
  _QWORD *v9; // x8

  if ( a1 )
  {
    v9 = *(_QWORD **)(a1 + 1240);
    if ( v9 )
    {
      if ( *v9 )
        return wmi_unified_send_reject_ap_list();
    }
  }
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Invalid wmi handle",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "target_if_dlm_send_reject_ap_list");
  return 4;
}
