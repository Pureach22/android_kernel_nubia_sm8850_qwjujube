__int64 __fastcall target_if_release_vdev_cmd_rt_lock(
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
  __int64 result; // x0
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  __int64 v14; // x20
  __int64 v15; // x19
  __int64 v16; // x5
  __int64 v17; // x20
  const char *v18; // x2

  v10 = a2;
  if ( a2 >= 6u )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: Invalid vdev id passed VDEV_%d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "target_if_release_vdev_cmd_rt_lock",
             a2);
  if ( !a1 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    v16 = 255;
LABEL_14:
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
             "target_if_release_vdev_cmd_rt_lock",
             v10,
             v16);
  }
  v12 = *(_QWORD *)(a1 + 2136);
  if ( !v12 )
  {
    v17 = a1;
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    a1 = v17;
    goto LABEL_13;
  }
  v13 = *(__int64 (**)(void))(v12 + 1136);
  if ( !v13 )
  {
LABEL_13:
    v16 = *(unsigned __int8 *)(a1 + 48);
    goto LABEL_14;
  }
  v14 = a1;
  if ( *((_DWORD *)v13 - 1) != -672477040 )
    __break(0x8228u);
  result = v13();
  if ( !result )
  {
    v16 = *(unsigned __int8 *)(v14 + 48);
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
             "target_if_release_vdev_cmd_rt_lock",
             v10,
             v16);
  }
  if ( *(_BYTE *)(result + 96) == 1 )
  {
    v15 = result;
    result = qdf_runtime_pm_allow_suspend((__int64 *)(result + 104));
    *(_BYTE *)(v15 + 96) = 0;
  }
  return result;
}
