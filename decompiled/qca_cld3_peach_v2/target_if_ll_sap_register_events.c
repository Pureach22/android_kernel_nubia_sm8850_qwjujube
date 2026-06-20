__int64 __fastcall target_if_ll_sap_register_events(
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
  _QWORD *v10; // x20
  unsigned int v11; // w0
  unsigned int v12; // w19
  const char *v13; // x2

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD **)(v9 + 16)) != nullptr )
  {
    v11 = wmi_unified_register_event_handler(
            *(_QWORD **)(v9 + 16),
            0x115u,
            (__int64)target_if_send_audio_transport_switch_req_event_handler,
            2u,
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
      v12 = v11;
      v13 = "%s: audio_transport_switch_req_event_handler registration failed";
    }
    else
    {
      v12 = wmi_unified_register_event_handler(
              v10,
              0x116u,
              (__int64)target_if_oob_connect_response_event_handler,
              2u,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9);
      if ( !v12 )
        return v12;
      v13 = "%s: oob_connect_response_event_handler registration failed";
    }
  }
  else
  {
    v12 = 16;
    v13 = "%s: handle is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_ll_sap_register_events");
  return v12;
}
