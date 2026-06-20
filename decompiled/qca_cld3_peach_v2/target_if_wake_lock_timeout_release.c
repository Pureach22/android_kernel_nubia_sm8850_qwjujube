__int64 __fastcall target_if_wake_lock_timeout_release(
        __int64 a1,
        int a2,
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
  __int64 (*v11)(void); // x8
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v23; // x4
  __int64 v24; // x19

  if ( !a1 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    v23 = 255;
LABEL_13:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: psoc_id:%d No Rx Ops",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_wake_lock_timeout_release",
      v23);
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 2136);
  if ( !v10 )
  {
    v24 = a1;
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    a1 = v24;
    goto LABEL_12;
  }
  v11 = *(__int64 (**)(void))(v10 + 1128);
  if ( !v11 )
  {
LABEL_12:
    v23 = *(unsigned __int8 *)(a1 + 48);
    goto LABEL_13;
  }
  if ( *((_DWORD *)v11 - 1) != -868578850 )
    __break(0x8228u);
  v13 = v11();
  if ( a2 == 2 )
  {
    v13 += 400;
  }
  else if ( a2 == 1 )
  {
    v13 += 200;
  }
  else if ( a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: operation mode is invalid",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_wake_lock_timeout_release");
    return 16;
  }
  qdf_wake_lock_release(v13, 0x10u);
  return 0;
}
