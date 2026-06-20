__int64 __fastcall hdd_get_device_mode(
        int a1,
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
  __int64 link_info_by_vdev; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  context = _cds_get_context(51, (__int64)"hdd_get_device_mode", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, a1);
    if ( link_info_by_vdev )
      return *(unsigned int *)(*(_QWORD *)link_info_by_vdev + 40LL);
    qdf_trace_msg(0x33u, 2u, "%s: Invalid vdev", v12, v13, v14, v15, v16, v17, v18, v19, "hdd_get_device_mode");
  }
  return 17;
}
