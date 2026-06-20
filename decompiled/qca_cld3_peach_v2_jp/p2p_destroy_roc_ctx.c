__int64 __fastcall p2p_destroy_roc_ctx(
        __int64 a1,
        char a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v11 = *(_QWORD *)(a1 + 16);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: p2p_soc_obj:%pK, roc_ctx:%pK, up_layer_event:%d, in_roc_queue:%d vdev_id:%d freq:%d duration:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "p2p_destroy_roc_ctx",
    v11,
    a1,
    a2 & 1,
    a3 & 1,
    *(_DWORD *)(a1 + 24),
    *(_DWORD *)(a1 + 40),
    *(_DWORD *)(a1 + 48));
  if ( (a2 & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 224) <= 2u )
      p2p_send_roc_event(a1, 0);
    v15 = p2p_send_roc_event(a1, 1);
  }
  p2p_cancel_tx_frame_by_roc(v11, a1, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( (a3 & 1) != 0 )
  {
    v23 = qdf_list_remove_node(v11 + 8, (_QWORD *)a1);
    if ( v23 )
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: Failed to remove roc req, status %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "p2p_destroy_roc_ctx",
        v23);
  }
  else
  {
    v23 = 0;
  }
  qdf_idr_remove(v11 + 224, *(_DWORD *)(a1 + 228));
  _qdf_mem_free(a1);
  return v23;
}
