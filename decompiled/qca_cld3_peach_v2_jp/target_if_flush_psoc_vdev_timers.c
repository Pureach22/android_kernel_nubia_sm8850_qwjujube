__int64 __fastcall target_if_flush_psoc_vdev_timers(
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
  __int64 v9; // x20
  __int64 (*v11)(void); // x8
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  __int64 v15; // x0
  __int64 v16; // x21
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  __int64 v18; // x0
  __int64 v19; // x21
  __int64 (__fastcall *v20)(__int64, __int64); // x8
  __int64 v21; // x0
  __int64 v22; // x21
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x0
  __int64 v25; // x21
  __int64 (__fastcall *v26)(__int64, __int64); // x8
  __int64 result; // x0
  __int64 v28; // x19
  __int64 v29; // x4

  if ( !a1 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_rx_ops");
    v29 = 255;
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: PSOC_%d No Rx Ops",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "target_if_flush_psoc_vdev_timers",
             v29);
  }
  v9 = *(_QWORD *)(a1 + 2136);
  if ( !v9 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_42;
  }
  v11 = *(__int64 (**)(void))(v9 + 1136);
  if ( !v11 )
  {
LABEL_42:
    v29 = *(unsigned __int8 *)(a1 + 48);
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: PSOC_%d No Rx Ops",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "target_if_flush_psoc_vdev_timers",
             v29);
  }
  if ( *((_DWORD *)v11 - 1) != -672477040 )
    __break(0x8228u);
  v12 = v11();
  if ( v12 )
  {
    if ( *(_DWORD *)(v12 + 80) )
    {
      v13 = v12;
      if ( (unsigned int)timer_delete_sync(v12 + 8) )
        target_if_vdev_mgr_rsp_timer_cb(v13);
    }
  }
  v14 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 1136);
  if ( *((_DWORD *)v14 - 1) != -672477040 )
    __break(0x8228u);
  v15 = v14(a1, 1);
  if ( v15 )
  {
    if ( *(_DWORD *)(v15 + 80) )
    {
      v16 = v15;
      if ( (unsigned int)timer_delete_sync(v15 + 8) )
        target_if_vdev_mgr_rsp_timer_cb(v16);
    }
  }
  v17 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 1136);
  if ( *((_DWORD *)v17 - 1) != -672477040 )
    __break(0x8228u);
  v18 = v17(a1, 2);
  if ( v18 )
  {
    if ( *(_DWORD *)(v18 + 80) )
    {
      v19 = v18;
      if ( (unsigned int)timer_delete_sync(v18 + 8) )
        target_if_vdev_mgr_rsp_timer_cb(v19);
    }
  }
  v20 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 1136);
  if ( *((_DWORD *)v20 - 1) != -672477040 )
    __break(0x8228u);
  v21 = v20(a1, 3);
  if ( v21 )
  {
    if ( *(_DWORD *)(v21 + 80) )
    {
      v22 = v21;
      if ( (unsigned int)timer_delete_sync(v21 + 8) )
        target_if_vdev_mgr_rsp_timer_cb(v22);
    }
  }
  v23 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 1136);
  if ( *((_DWORD *)v23 - 1) != -672477040 )
    __break(0x8228u);
  v24 = v23(a1, 4);
  if ( v24 )
  {
    if ( *(_DWORD *)(v24 + 80) )
    {
      v25 = v24;
      if ( (unsigned int)timer_delete_sync(v24 + 8) )
        target_if_vdev_mgr_rsp_timer_cb(v25);
    }
  }
  v26 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 1136);
  if ( *((_DWORD *)v26 - 1) != -672477040 )
    __break(0x8228u);
  result = v26(a1, 5);
  if ( result && *(_DWORD *)(result + 80) )
  {
    v28 = result;
    result = timer_delete_sync(result + 8);
    if ( (_DWORD)result )
      return target_if_vdev_mgr_rsp_timer_cb(v28);
  }
  return result;
}
