__int64 __fastcall target_if_vdev_mgr_sta_ps_param_send(
        __int64 a1,
        __int64 a2,
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
  _QWORD *v11; // x8
  unsigned int v12; // w8
  const char *v14; // x2
  const char *v15; // x2

  if ( !a1 || !a2 )
  {
    v14 = "%s: Invalid input";
LABEL_14:
    qdf_trace_msg(0x68u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_sta_ps_param_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v15 = "%s: PDEV is NULL";
    goto LABEL_13;
  }
  v11 = *(_QWORD **)(v10 + 1240);
  if ( !v11 || !*v11 )
  {
    v15 = "%s: wmi_handle is null";
LABEL_13:
    qdf_trace_msg(0x68u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v14 = "%s: Failed to get WMI handle!";
    goto LABEL_14;
  }
  v12 = *(_DWORD *)(a2 + 4);
  if ( v12 <= 0xE && ((0x777Fu >> v12) & 1) != 0 )
    v12 = dword_AD0754[v12];
  *(_DWORD *)(a2 + 4) = v12;
  return wmi_unified_sta_ps_cmd_send();
}
