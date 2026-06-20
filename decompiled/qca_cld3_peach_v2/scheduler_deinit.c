__int64 __fastcall scheduler_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x0
  __int64 context; // x0
  __int64 v10; // x19
  __int64 v11; // x1
  __int64 v12; // x1
  __int64 v13; // x1
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v8 = qdf_trace_msg(0x4Au, 8u, "%s: Deinitializing Scheduler", a1, a2, a3, a4, a5, a6, a7, a8, "scheduler_deinit");
  context = scheduler_get_context(v8);
  if ( !context )
    return 4;
  v10 = context;
  timer_delete_sync(context + 720);
  qdf_event_destroy(v10 + 624, v11);
  qdf_event_destroy(v10 + 552, v12);
  qdf_event_destroy(v10 + 504, v13);
  v14 = scheduler_queues_deinit(v10);
  if ( (_DWORD)v14 )
    v14 = qdf_trace_msg(
            0x4Au,
            2u,
            "%s: Failed to deinit queues; status:%d",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "scheduler_deinit",
            (unsigned int)v14);
  result = scheduler_destroy_ctx(v14);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x4Au,
      2u,
      "%s: Failed to destroy context; status:%d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "scheduler_deinit",
      (unsigned int)result);
    return 0;
  }
  return result;
}
