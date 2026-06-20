__int64 __fastcall target_if_vdev_mgr_peer_delete_all_send(
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
  __int64 v18; // x0
  __int64 v19; // x22
  __int64 result; // x0
  unsigned int v21; // w19
  const char *v22; // x2
  const char *v23; // x2
  const char *v24; // x2

  if ( !a1 || !a2 )
  {
    v22 = "%s: Invalid input";
LABEL_18:
    qdf_trace_msg(0x68u, 2u, v22, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_peer_delete_all_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v23 = "%s: PDEV is NULL";
    goto LABEL_17;
  }
  v11 = *(__int64 **)(v10 + 1240);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v23 = "%s: wmi_handle is null";
LABEL_17:
    qdf_trace_msg(0x68u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v22 = "%s: Failed to get WMI handle!";
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
    v24 = "%s: VDEV %d: No Rx Ops";
LABEL_23:
    qdf_trace_msg(0x68u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_peer_delete_all_send", v14);
    return 4;
  }
  if ( *(v16 - 1) != -672477040 )
    __break(0x8228u);
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD))v16)(v13, v14);
  if ( !v18 )
  {
    v24 = "%s: VDEV %d: No vdev rsp timer";
    goto LABEL_23;
  }
  v19 = v18;
  *(_DWORD *)(v18 + 72) = 10000;
  *(_DWORD *)(v18 + 88) = *(_DWORD *)(a2 + 4);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: VDEV %d: vdev delete all: bitmap:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_vdev_mgr_peer_delete_all_send",
    v14);
  target_if_vdev_mgr_rsp_timer_start(v13, v19, 4u);
  result = wmi_unified_peer_delete_all_send(v12, a2);
  if ( (_DWORD)result )
  {
    v21 = result;
    *(_QWORD *)(v19 + 72) = 0x900000000LL;
    target_if_vdev_mgr_rsp_timer_stop(v13, v19, 4u);
    return v21;
  }
  return result;
}
