__int64 __fastcall wma_remove_req(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *req; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Remove req for vdev: %d type: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wma_remove_req",
    a2,
    a3);
  req = wma_find_req(a1, a2, a3, 0);
  if ( !req )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: target req not found for vdev: %d type: %d",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "wma_remove_req",
             a2,
             a3);
  v23 = (__int64)req;
  qdf_mc_timer_stop((__int64)req);
  qdf_mc_timer_destroy(v23);
  return _qdf_mem_free(v23);
}
