__int64 __fastcall target_if_scan_unregister_event_handler(
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
  unsigned int v12; // w19
  const char *v13; // x2
  __int64 v15; // x8
  __int64 v16; // x20
  const char *v17; // x2

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2800)) == 0 || (v10 = *(_QWORD *)(v9 + 16)) == 0 )
  {
    v12 = 16;
    v13 = "%s: Invalid WMI handle";
    goto LABEL_7;
  }
  if ( (unsigned int)wmi_unified_unregister_event(*(_QWORD *)(v9 + 16), 3) )
  {
    v12 = 16;
    v13 = "%s: Failed to unregister Scan match event cb";
    goto LABEL_7;
  }
  v15 = *(_QWORD *)(a1 + 2800);
  if ( !v15 || (v16 = *(_QWORD *)(v15 + 16)) == 0 )
  {
    v17 = "%s: Invalid WMI handle";
    goto LABEL_14;
  }
  if ( (unsigned int)wmi_unified_unregister_event(*(_QWORD *)(v15 + 16), 92) )
  {
    v17 = "%s: Failed to unregister nlo match event cb";
LABEL_14:
    qdf_trace_msg(0x49u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_scan_unregister_pno_event_handler");
    v12 = 16;
    v13 = "%s: Failed to unregister pno event cb";
    goto LABEL_7;
  }
  if ( (unsigned int)wmi_unified_unregister_event(v16, 93) )
  {
    v17 = "%s: Failed to unregister nlo scan comp event cb";
    goto LABEL_14;
  }
  v12 = wmi_unified_unregister_event(v10, 268);
  if ( !v12 )
    return v12;
  v13 = "%s: Failed to unregister cached scan report";
LABEL_7:
  qdf_trace_msg(0x49u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_scan_unregister_event_handler");
  return v12;
}
