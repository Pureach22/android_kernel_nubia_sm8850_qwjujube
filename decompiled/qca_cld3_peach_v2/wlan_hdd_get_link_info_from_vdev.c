__int64 __fastcall wlan_hdd_get_link_info_from_vdev(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10)
{
  _QWORD *context; // x0
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  context = _cds_get_context(51, (__int64)"wlan_hdd_get_link_info_from_vdev", a1, a2, a3, a4, a5, a6, a7, a8);
  result = hdd_get_link_info_by_vdev(context);
  if ( !result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d Get adapter by vdev id failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_hdd_get_link_info_from_vdev",
      a10);
    return 0;
  }
  return result;
}
