__int64 __fastcall target_if_scan_register_event_handler(
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
  const char *v12; // x2
  __int64 v14; // x8
  __int64 v15; // x20
  const char *v16; // x2

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    if ( (unsigned int)wmi_unified_register_event(*(_QWORD *)(v9 + 16), 3, target_if_scan_event_handler) )
    {
      v12 = "%s: Failed to register Scan match event cb";
    }
    else
    {
      v14 = *(_QWORD *)(a1 + 2800);
      if ( v14 && (v15 = *(_QWORD *)(v14 + 16)) != 0 )
      {
        if ( (unsigned int)wmi_unified_register_event(*(_QWORD *)(v14 + 16), 92, target_if_nlo_match_event_handler) )
        {
          v16 = "%s: Failed to register nlo match event cb";
        }
        else
        {
          if ( !(unsigned int)wmi_unified_register_event(v15, 93, target_if_nlo_complete_handler) )
            return wmi_unified_register_event(v10, 268, target_if_scan_cached_scan_report_handler);
          v16 = "%s: Failed to register nlo scan comp event cb";
        }
      }
      else
      {
        v16 = "%s: Invalid WMI handle";
      }
      qdf_trace_msg(0x49u, 2u, v16, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_scan_register_pno_event_handler");
      v12 = "%s: Failed to register pno event handler cb";
    }
  }
  else
  {
    v12 = "%s: Invalid WMI handle";
  }
  qdf_trace_msg(0x49u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_scan_register_event_handler");
  return 16;
}
