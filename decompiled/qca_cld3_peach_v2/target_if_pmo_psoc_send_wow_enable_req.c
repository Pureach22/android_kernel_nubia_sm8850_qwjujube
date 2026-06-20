__int64 __fastcall target_if_pmo_psoc_send_wow_enable_req(
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
  __int64 v10; // x19

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    wma_check_and_set_wake_timer(0x11170u, a2, a3, a4, a5, a6, a7, a8, a9);
    return wmi_unified_wow_enable_send(v10);
  }
  else
  {
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
      "target_if_pmo_psoc_send_wow_enable_req");
    return 4;
  }
}
