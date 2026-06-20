__int64 __fastcall hdd_mlo_update_vdev_active_flag(
        unsigned __int8 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  context = _cds_get_context(51, (__int64)"hdd_mlo_update_vdev_active_flag", a3, a4, a5, a6, a7, a8, a9, a10);
  result = _wlan_hdd_validate_context(
             (__int64)context,
             (__int64)"hdd_mlo_update_vdev_active_flag",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20);
  if ( !(_DWORD)result )
  {
    result = hdd_get_link_info_by_vdev((__int64)context, a1);
    if ( result )
      *(_BYTE *)(result + 2697) = a2 & 1;
    else
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: link info is null for vdev:%d",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "hdd_mlo_update_vdev_active_flag",
               a1);
  }
  return result;
}
