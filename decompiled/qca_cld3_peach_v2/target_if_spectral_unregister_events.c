__int64 __fastcall target_if_spectral_unregister_events(
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
  _QWORD *v11; // x0
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  _QWORD *v22; // x0
  unsigned int v23; // w0
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x56u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_spectral_unregister_events");
    return 4;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( v9 && (v11 = *(_QWORD **)(v9 + 16)) != nullptr )
  {
    v12 = wmi_unified_unregister_event_handler(v11, 0x10Bu, a2, a3, a4, a5, a6, a7, a8, a9);
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: WMI handle is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_spectral_wmi_unified_unregister_event_handler");
    v12 = 4;
  }
  qdf_status_to_os_return(v12);
  v21 = *(_QWORD *)(a1 + 2800);
  if ( !v21 || (v22 = *(_QWORD **)(v21 + 16)) == nullptr )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: WMI handle is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_spectral_wmi_unified_unregister_event_handler");
    result = qdf_status_to_os_return(4u);
    if ( !(_DWORD)result )
      return result;
    goto LABEL_11;
  }
  v23 = wmi_unified_unregister_event_handler(v22, 0xE9u, v13, v14, v15, v16, v17, v18, v19, v20);
  result = qdf_status_to_os_return(v23);
  if ( (_DWORD)result )
  {
LABEL_11:
    qdf_trace_msg(
      0x56u,
      8u,
      "%s: Unregister WMI event handler failed, ret = %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "target_if_spectral_unregister_events",
      (unsigned int)result);
    return 0;
  }
  return result;
}
