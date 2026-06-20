__int64 __fastcall wma_cleanup_vdev_resp_and_hold_req(
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
  __int64 v9; // x19

  if ( a1 && (v9 = *(_QWORD *)(a1 + 8)) != 0 )
  {
    target_if_flush_psoc_vdev_timers(*(_QWORD *)(v9 + 24), a2, a3, a4, a5, a6, a7, a8, a9);
    wma_cleanup_hold_req(v9);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: msg or body pointer is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_cleanup_vdev_resp_and_hold_req");
    return 4;
  }
}
