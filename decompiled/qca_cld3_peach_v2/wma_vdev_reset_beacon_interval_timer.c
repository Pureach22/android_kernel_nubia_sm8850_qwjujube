__int64 __fastcall wma_vdev_reset_beacon_interval_timer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w20
  unsigned int v11; // w21
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x22

  v10 = *(unsigned __int16 *)(a1 + 58);
  v11 = *(unsigned __int8 *)(a1 + 56);
  context = _cds_get_context(54, (__int64)"wma_vdev_reset_beacon_interval_timer", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v21 = context;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Change beacon interval back to %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_vdev_reset_beacon_interval_timer",
      v10);
    wma_update_beacon_interval(v21, v11, v10);
  }
  timer_delete((timer_t)a1);
  timer_delete_sync(a1);
  return _qdf_mem_free(a1);
}
