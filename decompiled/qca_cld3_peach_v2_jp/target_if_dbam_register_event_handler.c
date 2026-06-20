__int64 __fastcall target_if_dbam_register_event_handler(
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
  _QWORD *v10; // x0
  unsigned int v11; // w19
  const char *v12; // x2

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2800)) == 0 || (v10 = *(_QWORD **)(v9 + 16)) == nullptr )
  {
    v11 = 4;
    v12 = "%s: Invalid WMI handle";
    goto LABEL_7;
  }
  v11 = wmi_unified_register_event_handler(
          v10,
          0xFFu,
          (__int64)target_if_dbam_response_event_handler,
          0,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9);
  if ( v11 )
  {
    v12 = "%s: Failed to register dbam complete event cb";
LABEL_7:
    qdf_trace_msg(0x49u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_dbam_register_event_handler");
  }
  return v11;
}
