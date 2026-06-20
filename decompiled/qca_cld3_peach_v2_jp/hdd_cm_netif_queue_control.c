__int64 __fastcall hdd_cm_netif_queue_control(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *link_info_by_vdev; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  context = _cds_get_context(51, (__int64)"hdd_cm_netif_queue_control", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev(context);
    if ( link_info_by_vdev )
    {
      wlan_hdd_netif_queue_control(*link_info_by_vdev, a2, a3);
      return 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: adapter is NULL for vdev %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "hdd_cm_netif_queue_control",
      *(unsigned __int8 *)(a1 + 104));
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd_ctx is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_cm_netif_queue_control");
  }
  return 4;
}
