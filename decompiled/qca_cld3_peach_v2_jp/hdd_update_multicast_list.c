__int64 __fastcall hdd_update_multicast_list(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  __int64 link_info_by_vdev; // x0
  const char *v22; // x2

  context = _cds_get_context(51, (__int64)"hdd_update_multicast_list", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = *(unsigned __int8 *)(a1 + 104);
    link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, v19);
    if ( !link_info_by_vdev || !*(_QWORD *)link_info_by_vdev )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: adapter is null for vdev_id %d",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "hdd_update_multicast_list",
               v19);
    if ( *(_QWORD *)(*(_QWORD *)link_info_by_vdev + 32LL) )
      return _hdd_set_multicast_list();
    v22 = "%s: netdev is null";
  }
  else
  {
    v22 = "%s: hdd_ctx is null";
  }
  return qdf_trace_msg(0x33u, 2u, v22, v11, v12, v13, v14, v15, v16, v17, v18, "hdd_update_multicast_list");
}
