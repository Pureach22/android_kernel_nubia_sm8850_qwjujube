__int64 __fastcall target_if_wake_lock_init(
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
  __int64 (*v10)(void); // x8
  __int64 v11; // x19
  __int64 result; // x0
  __int64 v13; // x4
  __int64 v14; // x19

  if ( !a1 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_rx_ops");
    v13 = 255;
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: psoc_id:%d No Rx Ops",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "target_if_wake_lock_init",
             v13);
  }
  v9 = *(_QWORD *)(a1 + 2136);
  if ( !v9 )
  {
    v14 = a1;
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_rx_ops");
    a1 = v14;
    goto LABEL_9;
  }
  v10 = *(__int64 (**)(void))(v9 + 1128);
  if ( !v10 )
  {
LABEL_9:
    v13 = *(unsigned __int8 *)(a1 + 48);
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: psoc_id:%d No Rx Ops",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "target_if_wake_lock_init",
             v13);
  }
  if ( *((_DWORD *)v10 - 1) != -868578850 )
    __break(0x8228u);
  v11 = v10();
  _qdf_wake_lock_create((_QWORD *)v11, (__int64)"vdev_start");
  _qdf_wake_lock_create((_QWORD *)(v11 + 200), (__int64)"vdev_stop");
  _qdf_wake_lock_create((_QWORD *)(v11 + 400), (__int64)"vdev_delete");
  _qdf_runtime_lock_init((__int64 *)(v11 + 600), "&psoc_wakelock->prevent_runtime_lock");
  result = _qdf_runtime_lock_init((__int64 *)(v11 + 608), "&psoc_wakelock->roam_sync_runtime_lock");
  *(_BYTE *)(v11 + 616) = 0;
  return result;
}
