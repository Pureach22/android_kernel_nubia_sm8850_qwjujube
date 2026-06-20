__int64 __fastcall target_if_spectral_register_events(
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
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  _QWORD *v23; // x0
  unsigned int v24; // w0
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x56u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_spectral_register_events");
    return 4;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( v9 )
  {
    v11 = *(_QWORD **)(v9 + 16);
    if ( v11 )
    {
      v12 = wmi_unified_register_event_handler(
              v11,
              0xE9u,
              (__int64)&target_if_spectral_fw_param_event_handler,
              1u,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9);
      v13 = qdf_status_to_os_return(v12);
      if ( !v13 )
        goto LABEL_8;
      goto LABEL_7;
    }
  }
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
    "target_if_spectral_wmi_unified_register_event_handler");
  v13 = qdf_status_to_os_return(4u);
  if ( v13 )
LABEL_7:
    qdf_trace_msg(
      0x56u,
      8u,
      "%s: event handler not supported, ret=%d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_spectral_register_events",
      v13);
LABEL_8:
  v22 = *(_QWORD *)(a1 + 2800);
  if ( !v22 || (v23 = *(_QWORD **)(v22 + 16)) == nullptr )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: WMI handle is null",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_spectral_wmi_unified_register_event_handler");
    result = qdf_status_to_os_return(4u);
    if ( !(_DWORD)result )
      return result;
    goto LABEL_13;
  }
  v24 = wmi_unified_register_event_handler(
          v23,
          0x100u,
          (__int64)target_if_spectral_capabilities_event_handler,
          1u,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21);
  result = qdf_status_to_os_return(v24);
  if ( (_DWORD)result )
  {
LABEL_13:
    qdf_trace_msg(
      0x56u,
      8u,
      "%s: event handler not supported, ret=%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "target_if_spectral_register_events",
      (unsigned int)result);
    return 0;
  }
  return result;
}
