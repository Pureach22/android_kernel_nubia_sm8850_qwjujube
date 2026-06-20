__int64 __fastcall target_if_cm_roam_send_roam_invoke_cmd(
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
  _QWORD *v10; // x8
  const char *v12; // x2

  v9 = *(_QWORD *)(a1 + 216);
  if ( v9 )
  {
    v10 = *(_QWORD **)(v9 + 1240);
    if ( v10 && *v10 )
      return wmi_unified_roam_invoke_cmd();
    v12 = "%s: wmi_handle is null";
  }
  else
  {
    v12 = "%s: PDEV is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_cm_roam_get_wmi_handle_from_vdev");
  return 16;
}
