__int64 __fastcall mlme_vdev_self_peer_create(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9) )
    return wma_vdev_self_peer_create();
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: Failed to get vdev mlme obj for vdev id %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "mlme_vdev_self_peer_create",
    *(unsigned __int8 *)(a1 + 168));
  return 4;
}
