__int64 __fastcall hdd_tx_queue_cb(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 link_info_by_vdev; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 *v24; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  if ( !a1 )
    return qdf_trace_msg(0x33u, 2u, "%s: Invalid context passed", a5, a6, a7, a8, a9, a10, a11, a12, "hdd_tx_queue_cb");
  link_info_by_vdev = hdd_get_link_info_by_vdev(a1, a2);
  if ( !link_info_by_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: vdev_id %d does not exist with host",
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             "hdd_tx_queue_cb",
             a2);
  v24 = (__int64 *)link_info_by_vdev;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Tx Queue action %d on vdev %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "hdd_tx_queue_cb",
    a3,
    a2);
  return wlan_hdd_netif_queue_control(*v24, a3, a4, v25, v26, v27, v28, v29, v30, v31, v32);
}
