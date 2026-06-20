__int64 __fastcall target_if_vdev_mgr_set_neighbour_rx_cmd_send(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  _QWORD *v12; // x8
  const char *v14; // x2
  const char *v15; // x2

  if ( a1 && a2 )
  {
    v11 = *(_QWORD *)(a1 + 216);
    if ( v11 )
    {
      v12 = *(_QWORD **)(v11 + 1240);
      if ( v12 && *v12 )
        return wmi_unified_vdev_set_neighbour_rx_cmd_send(*v12, a3, a2);
      v15 = "%s: wmi_handle is null";
    }
    else
    {
      v15 = "%s: PDEV is NULL";
    }
    qdf_trace_msg(0x68u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "target_if_vdev_mgr_wmi_handle_get");
    v14 = "%s: Failed to get WMI handle!";
  }
  else
  {
    v14 = "%s: Invalid input";
  }
  qdf_trace_msg(0x68u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "target_if_vdev_mgr_set_neighbour_rx_cmd_send");
  return 4;
}
