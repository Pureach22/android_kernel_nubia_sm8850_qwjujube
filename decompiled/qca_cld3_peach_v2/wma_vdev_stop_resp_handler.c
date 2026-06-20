__int64 __fastcall wma_vdev_stop_resp_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10)
{
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  context = _cds_get_context(54, (__int64)"wma_vdev_stop_resp_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 16;
  if ( *((unsigned __int16 *)context + 81) > (unsigned int)*a10 )
    return wlan_vdev_mlme_sm_deliver_evt(
             *(_QWORD *)(context[65] + 488LL * *a10),
             0xEu,
             1u,
             (__int64)a10,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19);
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Invalid vdev_id %d from FW",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wma_vdev_stop_resp_handler");
  return 4;
}
