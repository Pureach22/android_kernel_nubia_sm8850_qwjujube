__int64 __fastcall wlan_hdd_set_tx_rx_nss_cb(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        unsigned int a11,
        unsigned int a12)
{
  _QWORD *context; // x0
  __int64 *link_info_by_vdev; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  context = _cds_get_context(51, (__int64)"wlan_hdd_get_link_info_from_vdev", a1, a2, a3, a4, a5, a6, a7, a8);
  link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev((__int64)context, a10);
  if ( link_info_by_vdev )
    return hdd_update_nss(link_info_by_vdev, a11, a12, v17, v18, v19, v20, v21, v22, v23, v24);
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: vdev %d Get adapter by vdev id failed",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wlan_hdd_get_link_info_from_vdev",
    a10);
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Invalid vdev %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_hdd_set_tx_rx_nss_cb",
    a10);
  return 16;
}
