__int64 __fastcall target_if_cm_roam_send_roam_sync_complete(
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
  __int64 *v11; // x8
  __int64 v12; // x8
  unsigned int v13; // w20
  const char *v15; // x2
  const char *v16; // x3

  v9 = *(_QWORD *)(a1 + 152);
  if ( v9 && (v10 = *(_QWORD *)(v9 + 80)) != 0 )
  {
    v11 = *(__int64 **)(v9 + 1232);
    if ( v11 )
    {
      v12 = *v11;
      if ( v12 )
      {
        v13 = wmi_unified_roam_synch_complete_cmd(v12, *(unsigned __int8 *)(a1 + 104));
        target_if_allow_pm_after_roam_sync(v10);
        return v13;
      }
    }
    v15 = "%s: wmi_handle is null";
    v16 = "target_if_cm_roam_get_wmi_handle_from_vdev";
  }
  else
  {
    v15 = "%s: psoc handle is NULL";
    v16 = "target_if_cm_roam_send_roam_sync_complete";
  }
  qdf_trace_msg(0x49u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, v16);
  return 16;
}
