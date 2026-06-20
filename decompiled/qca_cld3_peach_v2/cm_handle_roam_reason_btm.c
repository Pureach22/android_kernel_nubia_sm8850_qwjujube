__int64 __fastcall cm_handle_roam_reason_btm(
        char a1,
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
  __int64 v19; // x20

  result = (__int64)_cds_get_context(54, (__int64)"wma_handle_roam_reason_btm", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v19 = result;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Kickout due to btm request",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_handle_roam_reason_btm");
    wma_sta_kickout_event(4, a1, nullptr);
    result = _qdf_mem_malloc(0x14u, "wma_handle_disconnect_reason", 267);
    if ( result )
    {
      *(_BYTE *)(result + 1) = a1;
      *(_WORD *)(result + 16) = 5;
      return wma_send_msg(v19, 0x13C1u, result, 0);
    }
  }
  return result;
}
