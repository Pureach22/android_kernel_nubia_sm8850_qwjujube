__int64 __fastcall target_if_coap_register_event_handler(
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

  if ( !a1 )
  {
    v11 = 29;
    v12 = "%s: PSOC is NULL!";
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( !v9 || (v10 = *(_QWORD **)(v9 + 16)) == nullptr )
  {
    v11 = 4;
    v12 = "%s: wmi_handle is null";
    goto LABEL_8;
  }
  v11 = wmi_unified_register_event_handler(
          v10,
          0x101u,
          (__int64)target_if_wow_coap_buf_info_event_handler,
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
    v12 = "%s: Failed to register coap buf info event cb";
LABEL_8:
    qdf_trace_msg(0x9Cu, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_coap_register_event_handler");
  }
  return v11;
}
