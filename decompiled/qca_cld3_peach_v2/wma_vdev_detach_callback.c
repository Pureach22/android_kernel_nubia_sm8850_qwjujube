__int64 __fastcall wma_vdev_detach_callback(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x20
  __int64 v20; // x0

  context = _cds_get_context(54, (__int64)"wma_vdev_detach_callback", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 16;
  if ( *((unsigned __int16 *)context + 81) <= (unsigned int)*a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev delete response with invalid vdev_id :%d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_vdev_detach_callback");
    return 16;
  }
  v19 = (_QWORD *)(context[65] + 488LL * *a1);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev del response received for VDEV_%d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wma_vdev_detach_callback");
  v20 = v19[55];
  v19[27] = 0;
  if ( v20 )
  {
    v19[55] = 0;
    _qdf_mem_free(v20);
  }
  wma_vdev_deinit(v19);
  qdf_mem_set(v19, 0x1E8u, 0);
  wma_vdev_init(v19);
  mlme_vdev_del_resp();
  return 0;
}
