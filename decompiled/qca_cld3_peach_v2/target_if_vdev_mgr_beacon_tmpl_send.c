__int64 __fastcall target_if_vdev_mgr_beacon_tmpl_send(
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
  const char *v13; // x2
  const char *v14; // x2

  if ( a1 && a2 )
  {
    v10 = *(_QWORD *)(a1 + 216);
    if ( v10 )
    {
      v11 = *(_QWORD **)(v10 + 1240);
      if ( v11 && *v11 )
        return wmi_unified_beacon_tmpl_send_cmd();
      v14 = "%s: wmi_handle is null";
    }
    else
    {
      v14 = "%s: PDEV is NULL";
    }
    qdf_trace_msg(0x68u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v13 = "%s: Failed to get WMI handle!";
  }
  else
  {
    v13 = "%s: Invalid input";
  }
  qdf_trace_msg(0x68u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_beacon_tmpl_send");
  return 4;
}
