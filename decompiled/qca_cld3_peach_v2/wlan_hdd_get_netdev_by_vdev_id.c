__int64 __fastcall wlan_hdd_get_netdev_by_vdev_id(
        unsigned int a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  __int64 link_info_by_vdev; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8

  context = _cds_get_context(51, (__int64)"wlan_hdd_get_netdev_by_vdev_id", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, a1);
    if ( link_info_by_vdev )
    {
      v22 = link_info_by_vdev;
      *a2 = *(_QWORD *)(*(_QWORD *)v22 + 32LL);
      return 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to get link info by vdev id %u",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_hdd_get_netdev_by_vdev_id",
      a1);
  }
  return 4;
}
