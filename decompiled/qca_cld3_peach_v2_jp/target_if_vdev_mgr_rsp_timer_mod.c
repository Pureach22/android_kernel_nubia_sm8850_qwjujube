__int64 __fastcall target_if_vdev_mgr_rsp_timer_mod(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
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
  __int64 (*v12)(void); // x8
  __int64 v14; // x20
  __int64 v15; // x22
  unsigned int multiplier; // w21
  __int64 v17; // x0
  __int64 v19; // x19
  unsigned __int8 v20; // w20

  if ( !a1 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid input", a4, a5, a6, a7, a8, a9, a10, a11, "target_if_vdev_mgr_rsp_timer_mod");
    return 16;
  }
  v11 = *(_QWORD *)(a1 + 2136);
  if ( !v11 )
  {
    v19 = a1;
    v20 = a2;
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "target_if_vdev_mgr_get_rx_ops");
    a1 = v19;
    a2 = v20;
    goto LABEL_9;
  }
  v12 = *(__int64 (**)(void))(v11 + 1136);
  if ( !v12 )
  {
LABEL_9:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d PSOC_%d No Rx Ops",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_vdev_mgr_rsp_timer_mod",
      a2,
      *(unsigned __int8 *)(a1 + 48));
    return 16;
  }
  if ( *((_DWORD *)v12 - 1) != -672477040 )
    __break(0x8228u);
  v14 = v12();
  v15 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  v17 = _msecs_to_jiffies(a3);
  mod_timer(v14 + 8, v15 + v17 * multiplier);
  return 0;
}
