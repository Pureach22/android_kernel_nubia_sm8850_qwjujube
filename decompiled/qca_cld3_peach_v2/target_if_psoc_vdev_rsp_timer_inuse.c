__int64 __fastcall target_if_psoc_vdev_rsp_timer_inuse(
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
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v16; // x5
  __int64 v17; // x20
  const char *v18; // x2

  v10 = a2;
  if ( a2 >= 6u )
  {
    qdf_trace_msg(
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
      "target_if_psoc_vdev_rsp_timer_inuse",
      a2);
    return 4;
  }
  if ( !a1 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    v16 = 255;
LABEL_14:
    v18 = "%s: VDEV_%d PSOC_%d No Rx Ops";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v18, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_psoc_vdev_rsp_timer_inuse", v10, v16);
    return 4;
  }
  v11 = *(_QWORD *)(a1 + 2136);
  if ( !v11 )
  {
    v17 = a1;
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    a1 = v17;
    goto LABEL_13;
  }
  v12 = *(__int64 (**)(void))(v11 + 1136);
  if ( !v12 )
  {
LABEL_13:
    v16 = *(unsigned __int8 *)(a1 + 48);
    goto LABEL_14;
  }
  v13 = a1;
  if ( *((_DWORD *)v12 - 1) != -672477040 )
    __break(0x8228u);
  v14 = v12();
  if ( !v14 )
  {
    v16 = *(unsigned __int8 *)(v13 + 48);
    v18 = "%s: vdev response is NULL for VDEV_%d PSOC_%d";
    goto LABEL_15;
  }
  if ( !*(_DWORD *)(v14 + 80) )
    return 0;
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev response timer still inuse VDEV_%d PSOC_%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_psoc_vdev_rsp_timer_inuse",
    v10,
    *(unsigned __int8 *)(v13 + 48));
  return 6;
}
