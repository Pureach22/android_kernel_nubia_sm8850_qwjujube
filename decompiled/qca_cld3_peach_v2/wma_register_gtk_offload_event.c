__int64 __fastcall wma_register_gtk_offload_event(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( a1 )
  {
    if ( (wmi_service_enabled(*a1, 0x13u, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
      return wmi_unified_register_event_handler(
               (_QWORD *)*a1,
               0x1Fu,
               (__int64)target_if_pmo_gtk_offload_status_event,
               0,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__wma_validate_handle",
      "wma_register_gtk_offload_event");
  }
  return 16;
}
