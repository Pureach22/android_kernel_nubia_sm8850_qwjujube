__int64 __fastcall target_if_psoc_vdev_rsp_timer_deinit(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 v11; // x5
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x19
  __int64 result; // x0
  const char *v18; // x2
  __int64 v19; // x20

  v10 = a2;
  if ( a2 >= 6u )
  {
    if ( a1 )
      v11 = *(unsigned __int8 *)(a1 + 48);
    else
      v11 = 255;
    v18 = "%s: Invalid vdev id passed VDEV_%d PSOC_%d";
    return qdf_trace_msg(
             0x68u,
             2u,
             v18,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "target_if_psoc_vdev_rsp_timer_deinit",
             v10,
             v11);
  }
  if ( !a1 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    v11 = 255;
LABEL_16:
    v18 = "%s: VDEV_%d PSOC_%d No Rx Ops";
    return qdf_trace_msg(
             0x68u,
             2u,
             v18,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "target_if_psoc_vdev_rsp_timer_deinit",
             v10,
             v11);
  }
  v12 = *(_QWORD *)(a1 + 2136);
  if ( !v12 )
  {
    v19 = a1;
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    a1 = v19;
    goto LABEL_15;
  }
  v13 = *(__int64 (**)(void))(v12 + 1136);
  if ( !v13 )
  {
LABEL_15:
    v11 = *(unsigned __int8 *)(a1 + 48);
    goto LABEL_16;
  }
  v14 = a1;
  if ( *((_DWORD *)v13 - 1) != -672477040 )
    __break(0x8228u);
  v15 = v13();
  if ( v15 )
  {
    v16 = v15;
    timer_delete_sync(v15 + 8);
    *(_DWORD *)(v16 + 80) = 0;
    *(_BYTE *)(v16 + 96) = 0;
    result = qdf_runtime_lock_deinit((__int64 *)(v16 + 104));
    *(_QWORD *)v16 = 0;
    return result;
  }
  v11 = *(unsigned __int8 *)(v14 + 48);
  v18 = "%s: vdev response is NULL for VDEV_%d PSOC_%d";
  return qdf_trace_msg(
           0x68u,
           2u,
           v18,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "target_if_psoc_vdev_rsp_timer_deinit",
           v10,
           v11);
}
