__int64 __fastcall target_if_vdev_mgr_start_send(
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
  __int64 *v11; // x9
  __int64 v12; // x22
  __int64 v13; // x20
  unsigned int v14; // w19
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 v19; // x0
  __int64 v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int started; // w0
  unsigned int v30; // w22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  const char *v40; // x2
  const char *v41; // x2

  if ( !a1 || !a2 )
  {
    v39 = "%s: Invalid input";
LABEL_18:
    qdf_trace_msg(0x68u, 2u, v39, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_start_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 )
  {
    v40 = "%s: PDEV is NULL";
    goto LABEL_17;
  }
  v11 = *(__int64 **)(v10 + 1232);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v40 = "%s: wmi_handle is null";
LABEL_17:
    qdf_trace_msg(0x68u, 2u, v40, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v39 = "%s: Failed to get WMI handle!";
    goto LABEL_18;
  }
  v13 = *(_QWORD *)(v10 + 80);
  v14 = *(unsigned __int8 *)(a1 + 104);
  if ( !v13 || (v15 = *(_QWORD *)(v13 + 2136)) == 0 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_21;
  }
  v16 = *(_DWORD **)(v15 + 1136);
  if ( !v16 )
  {
LABEL_21:
    v41 = "%s: VDEV %d: No Rx Ops";
LABEL_22:
    qdf_trace_msg(0x68u, 2u, v41, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_start_send", v14);
    return 4;
  }
  if ( *(v16 - 1) != -672477040 )
    __break(0x8228u);
  v19 = ((__int64 (__fastcall *)(__int64, _QWORD))v16)(v13, v14);
  if ( !v19 )
  {
    v41 = "%s: VDEV %d: No vdev rsp timer";
    goto LABEL_22;
  }
  v20 = v19;
  *(_DWORD *)(v19 + 72) = 10000;
  v21 = target_if_wake_lock_timeout_acquire(v13, 0);
  target_if_acquire_vdev_cmd_rt_lock(v20, v21, v22, v23, v24, v25, v26, v27, v28);
  target_if_vdev_mgr_rsp_timer_start(v13, v20, *(unsigned __int8 *)(a2 + 12));
  started = wmi_unified_vdev_start_send(v12, a2);
  if ( started )
  {
    v30 = started;
    *(_QWORD *)(v20 + 72) = 0x900000000LL;
    target_if_wake_lock_timeout_release(v13, 0);
    target_if_release_vdev_cmd_rt_lock(v13, v14, v31, v32, v33, v34, v35, v36, v37, v38);
    target_if_vdev_mgr_rsp_timer_stop(v13, v20, *(unsigned __int8 *)(a2 + 12) == 1);
    return v30;
  }
  else
  {
    target_if_vdev_start_link_handler(a1, *(unsigned __int8 *)(a2 + 12));
    return 0;
  }
}
