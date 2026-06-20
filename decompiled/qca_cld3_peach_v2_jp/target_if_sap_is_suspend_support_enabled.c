__int64 __fastcall target_if_sap_is_suspend_support_enabled(
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
  char v11; // w0
  const char *v12; // x2
  const char *v13; // x2

  if ( !a1 )
  {
    v12 = "%s: Vdev NULL";
LABEL_10:
    qdf_trace_msg(0x68u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_sap_is_suspend_support_enabled");
    v11 = 0;
    return v11 & 1;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 )
  {
    v13 = "%s: PDEV is NULL";
    goto LABEL_9;
  }
  v10 = *(_QWORD **)(v9 + 1232);
  if ( !v10 || !*v10 )
  {
    v13 = "%s: wmi_handle is null";
LABEL_9:
    qdf_trace_msg(0x68u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_wmi_handle_get");
    v12 = "%s: Failed to get WMI handle!";
    goto LABEL_10;
  }
  v11 = wmi_service_enabled(*v10, 313);
  return v11 & 1;
}
