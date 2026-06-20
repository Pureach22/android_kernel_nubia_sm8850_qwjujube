__int64 __fastcall wma_process_power_debug_stats_req(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid WMA handle (via %s)",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "__wma_validate_handle",
             "wma_process_power_debug_stats_req");
  result = wmi_buf_alloc_fl(*a1, 8u, "wma_process_power_debug_stats_req", 0x2185u);
  if ( result )
  {
    v19 = result;
    **(_QWORD **)(result + 224) = 37093380;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: POWER_DEBUG_STATS - Get Request Params; Pdev id - %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_process_power_debug_stats_req",
      0);
    result = wmi_unified_cmd_send_fl(
               *a1,
               v19,
               8u,
               0x4026u,
               "wma_process_power_debug_stats_req",
               0x2195u,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27);
    if ( (_DWORD)result )
      return wmi_buf_free();
  }
  return result;
}
