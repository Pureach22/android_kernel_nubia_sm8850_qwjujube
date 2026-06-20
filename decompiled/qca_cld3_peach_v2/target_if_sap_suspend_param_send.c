__int64 __fastcall target_if_sap_suspend_param_send(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 *v11; // x8
  __int64 v12; // x19
  _DWORD *v14; // x21
  char is_mlo_vdev; // w0
  const char *v17; // x2
  const char *v18; // x2

  if ( !a1 || !a2 )
  {
    v17 = "%s: Vdev/param NULL";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_sap_suspend_param_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v18 = "%s: PDEV is NULL";
    goto LABEL_14;
  }
  v11 = *(__int64 **)(v10 + 1240);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v18 = "%s: wmi_handle is null";
LABEL_14:
    qdf_trace_msg(0x68u, 2u, v18, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v17 = "%s: Failed to get WMI handle!";
    goto LABEL_15;
  }
  if ( *(_DWORD *)(a1 + 16) == 1 )
  {
    v14 = a2;
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(a1);
    a2 = v14;
    if ( (is_mlo_vdev & 1) != 0 && *(unsigned __int16 *)(*(_QWORD *)(a1 + 1360) + 40LL) >= 2u )
      *v14 = 255;
  }
  return wmi_unified_sap_suspend_cmd_send(v12, a2);
}
