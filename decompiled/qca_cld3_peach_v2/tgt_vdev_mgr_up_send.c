__int64 __fastcall tgt_vdev_mgr_up_send(
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
  __int64 v10; // x0
  __int64 v11; // x8
  unsigned int v12; // w19
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 (*v15)(void); // x9
  unsigned int v16; // w20
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  if ( !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_up_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 520);
  v11 = *(_QWORD *)(v10 + 216);
  v12 = *(unsigned __int8 *)(v10 + 168);
  if ( !v11 || (v13 = *(_QWORD *)(v11 + 80)) == 0 || (v14 = *(_QWORD *)(v13 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_13;
  }
  v15 = *(__int64 (**)(void))(v14 + 1416);
  if ( !v15 )
  {
LABEL_13:
    qdf_trace_msg(0x68u, 2u, "%s: VDEV_%d: No Tx Ops", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_up_send", v12);
    return 4;
  }
  v16 = 4;
  if ( *(_QWORD *)(v13 + 2808) && v12 != 255 )
  {
    if ( *((_DWORD *)v15 - 1) != 704617364 )
      __break(0x8229u);
    v17 = v15();
    if ( v17 )
    {
      v16 = v17;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: VDEV_%d: Tx Ops Error : %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "tgt_vdev_mgr_up_send",
        v12,
        v17);
    }
    else
    {
      return 0;
    }
  }
  return v16;
}
