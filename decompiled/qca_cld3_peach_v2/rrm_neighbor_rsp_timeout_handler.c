__int64 __fastcall rrm_neighbor_rsp_timeout_handler(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 (__fastcall *v18)(__int64, __int64); // x8
  __int64 result; // x0

  qdf_trace_msg(
    0x34u,
    3u,
    "%s: Neighbor Response timed out",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "rrm_neighbor_rsp_timeout_handler");
  *(_BYTE *)(a1 + 17720) = 0;
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 17728) == 21 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: No entry in neighbor report cache",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "rrm_indicate_neighbor_report_result");
    qdf_mc_timer_stop(a1 + 17728);
  }
  v18 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 17904);
  result = *(_QWORD *)(a1 + 17912);
  *(_QWORD *)(a1 + 17904) = 0;
  *(_QWORD *)(a1 + 17912) = 0;
  if ( v18 )
  {
    if ( *((_DWORD *)v18 - 1) != -963780396 )
      __break(0x8228u);
    return v18(result, 16);
  }
  return result;
}
