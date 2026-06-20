__int64 __fastcall scheduler_msg_flush_mc(
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
  __int64 v9; // x0

  v9 = *(_QWORD *)(a1 + 8);
  if ( v9 )
    _qdf_mem_free(v9);
  else
    qdf_trace_msg(
      0x4Au,
      2u,
      "%s: pointer to wrapper ptr is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "scheduler_qdf_mc_timer_deinit_return_data_ptr");
  return 0;
}
