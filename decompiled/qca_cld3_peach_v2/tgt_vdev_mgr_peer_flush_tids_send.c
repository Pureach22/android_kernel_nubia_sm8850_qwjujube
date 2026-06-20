__int64 __fastcall tgt_vdev_mgr_peer_flush_tids_send(
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
  __int64 v14; // x8
  __int64 (*v15)(void); // x8
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  if ( !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_peer_flush_tids_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 520);
  v11 = *(_QWORD *)(v10 + 216);
  v12 = *(unsigned __int8 *)(v10 + 168);
  if ( !v11 || (v13 = *(_QWORD *)(v11 + 80)) == 0 || (v14 = *(_QWORD *)(v13 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_11;
  }
  v15 = *(__int64 (**)(void))(v14 + 1504);
  if ( !v15 )
  {
LABEL_11:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: No Tx Ops",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_vdev_mgr_peer_flush_tids_send",
      v12);
    return 4;
  }
  if ( *((_DWORD *)v15 - 1) != -458994747 )
    __break(0x8228u);
  result = v15();
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: Tx Ops Error : %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "tgt_vdev_mgr_peer_flush_tids_send",
      v12,
      (unsigned int)result);
    return 0;
  }
  return result;
}
