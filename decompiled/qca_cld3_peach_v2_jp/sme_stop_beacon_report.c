__int64 __fastcall sme_stop_beacon_report(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0

  if ( a2 > 5 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: vdev_id %d not found",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "sme_stop_beacon_report",
             a2);
  v11 = *(_QWORD *)(a1 + 17224) + 96LL * a2;
  if ( !v11 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: vdev_id %d not found",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "sme_stop_beacon_report",
             a2);
  if ( (unsigned int)wma_cli_set_command(a2, 146, 0, 1) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: wmi_vdev_param_nth_beacon_to_host command failed to FW",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sme_stop_beacon_report");
  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    *(_WORD *)(v11 + 51) = 0;
    return qdf_mutex_release(a1 + 12776);
  }
  return result;
}
