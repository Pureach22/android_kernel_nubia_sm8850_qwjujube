__int64 __fastcall wma_process_beacon_debug_stats_req(
        __int64 *a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _DWORD *v29; // x8
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7

  qdf_trace_msg(0x36u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_beacon_debug_stats_req");
  if ( !a1 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid WMA handle (via %s)",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "__wma_validate_handle",
             "wma_process_beacon_debug_stats_req");
  result = wmi_buf_alloc_fl(*a1, 8u, "wma_process_beacon_debug_stats_req", 0x21B1u);
  if ( result )
  {
    v29 = *(_DWORD **)(result + 224);
    v30 = result;
    *v29 = 50593796;
    v29[1] = *a2;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: BEACON_DEBUG_STATS - Get Request Params; vdev id - %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wma_process_beacon_debug_stats_req");
    if ( (unsigned int)wmi_unified_cmd_send_fl(
                         *a1,
                         v30,
                         8u,
                         0x5022u,
                         "wma_process_beacon_debug_stats_req",
                         0x21C1u,
                         v31,
                         v32,
                         v33,
                         v34,
                         v35,
                         v36,
                         v37,
                         v38) )
      return wmi_buf_free();
    else
      return qdf_trace_msg(
               0x36u,
               8u,
               "%s: Exit",
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               v46,
               "wma_process_beacon_debug_stats_req");
  }
  return result;
}
