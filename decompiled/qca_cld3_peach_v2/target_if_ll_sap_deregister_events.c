__int64 __fastcall target_if_ll_sap_deregister_events(
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
  _QWORD *v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD **)(v9 + 16)) != nullptr )
  {
    wmi_unified_unregister_event_handler(*(_QWORD **)(v9 + 16), 0x115u, a2, a3, a4, a5, a6, a7, a8, a9);
    return wmi_unified_unregister_event_handler(v10, 0x116u, v11, v12, v13, v14, v15, v16, v17, v18);
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: handle is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_ll_sap_deregister_events");
    return 16;
  }
}
