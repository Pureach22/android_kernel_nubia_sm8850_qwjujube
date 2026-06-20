__int64 __fastcall target_if_vdev_mgr_down_send(
        __int64 a1,
        unsigned __int8 *a2,
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
  _QWORD *v11; // x9
  __int64 v12; // x19
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v24; // x2
  const char *v25; // x2

  if ( !a1 || !a2 )
  {
    v24 = "%s: Invalid input";
    goto LABEL_12;
  }
  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 )
  {
    v25 = "%s: PDEV is NULL";
    goto LABEL_11;
  }
  v11 = *(_QWORD **)(v10 + 1232);
  if ( !v11 || !*v11 )
  {
    v25 = "%s: wmi_handle is null";
LABEL_11:
    qdf_trace_msg(0x68u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v24 = "%s: Failed to get WMI handle!";
    goto LABEL_12;
  }
  v12 = *(_QWORD *)(v10 + 80);
  if ( v12 )
  {
    v14 = wmi_unified_vdev_down_send();
    target_if_wake_lock_timeout_release(v12, 1);
    target_if_release_vdev_cmd_rt_lock(v12, *a2, v15, v16, v17, v18, v19, v20, v21, v22);
    return v14;
  }
  v24 = "%s: Failed to get PSOC Object";
LABEL_12:
  qdf_trace_msg(0x68u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_down_send");
  return 4;
}
