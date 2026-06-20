__int64 __fastcall wma_remove_peer_req(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *req; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Remove req for vdev: %d type: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "wma_remove_peer_req",
    a2,
    a3);
  req = wma_find_req(a1, a2, a3, a4);
  if ( !req )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: target req not found for vdev: %d type: %d",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "wma_remove_peer_req",
             a2,
             a3);
  v25 = (__int64)req;
  qdf_mc_timer_stop((__int64)req);
  qdf_mc_timer_destroy(v25);
  return _qdf_mem_free(v25);
}
