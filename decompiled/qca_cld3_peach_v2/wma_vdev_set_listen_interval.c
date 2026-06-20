__int64 __fastcall wma_vdev_set_listen_interval(
        unsigned __int8 a1,
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
  __int64 *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  context = _cds_get_context(54, (__int64)"wma_vdev_set_listen_interval", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: wma handle is null",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wma_vdev_set_listen_interval");
  result = wma_vdev_set_param(*context, a1, 4u, a2, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: failed to set Listen interval for vdev: %d",
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             "wma_vdev_set_listen_interval",
             a1);
  return result;
}
