__int64 __fastcall target_if_vdev_mgr_stop_send(
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
  __int64 v12; // x21
  __int64 v13; // x20
  unsigned int v14; // w19
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 v19; // x0
  __int64 v20; // x23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  unsigned int v38; // w0
  unsigned int v39; // w21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v49; // x2
  const char *v50; // x2
  const char *v51; // x2

  if ( !a1 || !a2 )
  {
    v49 = "%s: Invalid input";
LABEL_18:
    qdf_trace_msg(0x68u, 2u, v49, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_stop_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v50 = "%s: PDEV is NULL";
    goto LABEL_17;
  }
  v11 = *(__int64 **)(v10 + 1240);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v50 = "%s: wmi_handle is null";
LABEL_17:
    qdf_trace_msg(0x68u, 2u, v50, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v49 = "%s: Failed to get WMI handle!";
    goto LABEL_18;
  }
  v13 = *(_QWORD *)(v10 + 80);
  v14 = *(unsigned __int8 *)(a1 + 168);
  if ( !v13 || (v15 = *(_QWORD *)(v13 + 2136)) == 0 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_22;
  }
  v16 = *(_DWORD **)(v15 + 1136);
  if ( !v16 )
  {
LABEL_22:
    v51 = "%s: VDEV %d: No Rx Ops";
LABEL_23:
    qdf_trace_msg(0x68u, 2u, v51, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_stop_send", v14);
    return 4;
  }
  if ( *(v16 - 1) != -672477040 )
    __break(0x8228u);
  v19 = ((__int64 (__fastcall *)(__int64, _QWORD))v16)(v13, v14);
  if ( !v19 )
  {
    v51 = "%s: VDEV %d:No vdev rsp timer";
    goto LABEL_23;
  }
  v20 = v19;
  *(_DWORD *)(v19 + 72) = 8000;
  target_if_vdev_mgr_rsp_timer_start(v13, v19, 2u);
  target_if_release_vdev_cmd_rt_lock(v13, v14, v21, v22, v23, v24, v25, v26, v27, v28);
  target_if_wake_lock_timeout_release(v13, 0);
  target_if_acquire_vdev_cmd_rt_lock(v20, v29, v30, v31, v32, v33, v34, v35, v36);
  v37 = target_if_wake_lock_timeout_acquire(v13, 1);
  v38 = wmi_unified_vdev_stop_send(v12, a2, v37);
  if ( v38 )
  {
    v39 = v38;
    *(_QWORD *)(v20 + 72) = 0x900000000LL;
    target_if_vdev_mgr_rsp_timer_stop(v13, v20, 2u);
    target_if_wake_lock_timeout_release(v13, 1);
    target_if_release_vdev_cmd_rt_lock(v13, v14, v40, v41, v42, v43, v44, v45, v46, v47);
    return v39;
  }
  else
  {
    target_if_vdev_stop_link_handler(a1);
    return 0;
  }
}
