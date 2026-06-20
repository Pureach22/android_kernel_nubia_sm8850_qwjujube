__int64 __fastcall wma_send_invoke_neighbor_report(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid WMA handle (via %s)",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "__wma_validate_handle",
             "wma_send_invoke_neighbor_report");
  v10 = *a1;
  result = _wmi_validate_handle(*a1, (__int64)"wma_send_invoke_neighbor_report", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    result = wmi_unified_invoke_neighbor_report_cmd(v10, a2);
    if ( (_DWORD)result )
      return qdf_trace_msg(
               0x36u,
               2u,
               "%s: failed to send invoke neighbor report command",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "wma_send_invoke_neighbor_report");
  }
  return result;
}
