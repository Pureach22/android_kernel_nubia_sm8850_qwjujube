__int64 __fastcall wma_get_arp_req_stats(
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
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

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
             "wma_get_arp_req_stats");
  v10 = *a1;
  result = _wmi_validate_handle(*a1, (__int64)"wma_get_arp_req_stats", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    if ( (wma_is_vdev_valid(*(_DWORD *)(a2 + 4), v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0 )
    {
      result = wmi_unified_get_arp_stats_req(v10, a2);
      if ( (_DWORD)result )
        return qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: failed to send get arp stats to FW",
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 "wma_get_arp_req_stats");
    }
    else
    {
      return qdf_trace_msg(
               0x36u,
               2u,
               "%s: vdev id:%d is not active",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "wma_get_arp_req_stats",
               *(unsigned int *)(a2 + 4));
    }
  }
  return result;
}
