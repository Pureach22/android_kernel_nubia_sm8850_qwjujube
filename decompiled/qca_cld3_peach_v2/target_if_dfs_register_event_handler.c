__int64 __fastcall target_if_dfs_register_event_handler(
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
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  unsigned int v15; // w19
  const char *v16; // x2
  const char *v17; // x2

  if ( !a1 )
  {
    v17 = "%s: null psoc";
LABEL_14:
    qdf_trace_msg(0x49u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_dfs_register_event_handler");
    return 16;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( v9 && (v11 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    if ( (wmi_service_enabled(v11, 0x7Fu, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
      return target_if_dfs_reg_offload_events(a1);
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: null wmi_handle", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_dfs_offload");
  }
  v13 = *(_QWORD *)(a1 + 2800);
  if ( !v13 )
  {
    v17 = "%s: null tgt_psoc_info";
    goto LABEL_14;
  }
  if ( *(_DWORD *)(v13 + 496) != 8 )
    return 0;
  v14 = *(_QWORD *)(v13 + 16);
  if ( v14 )
  {
    result = wmi_unified_register_event(v14, 60, (__int64)target_if_radar_event_handler);
    if ( !(_DWORD)result )
      return result;
    v15 = 16;
    v16 = "%s: failed to register wmi_dfs_radar_event_id";
  }
  else
  {
    v15 = 4;
    v16 = "%s: null wmi_handle";
  }
  qdf_trace_msg(0x49u, 2u, v16, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_reg_phyerr_events_dfs2");
  return v15;
}
