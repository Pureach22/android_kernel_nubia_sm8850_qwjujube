__int64 __fastcall scheduler_enable(
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
  unsigned __int64 thread; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int64 v35; // x10
  unsigned __int64 v38; // x10

  v8 = qdf_trace_msg(0x4Au, 8u, "%s: Enabling Scheduler", a1, a2, a3, a4, a5, a6, a7, a8, "scheduler_enable");
  context = scheduler_get_context(v8);
  if ( !context )
    return 4;
  v10 = context;
  _X8 = (unsigned __int64 *)(context + 616);
  __asm { PRFM            #0x11, [X8] }
  do
    v35 = __ldxr(_X8);
  while ( __stxr(v35 & 0xFFFFFFFFFFFEFFFFLL, _X8) );
  _X8 = (unsigned __int64 *)(context + 616);
  __asm { PRFM            #0x11, [X8] }
  do
    v38 = __ldxr(_X8);
  while ( __stxr(v38 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  thread = qdf_create_thread((__int64)scheduler_thread, context, (__int64)"scheduler_thread");
  *(_QWORD *)(v10 + 544) = thread;
  if ( thread )
  {
    qdf_trace_msg(0x4Au, 8u, "%s: Scheduler thread created", v12, v13, v14, v15, v16, v17, v18, v19, "scheduler_enable");
    qdf_wake_up_process(*(_QWORD *)(v10 + 544));
    qdf_wait_single_event(v10 + 504, 0);
    qdf_trace_msg(0x4Au, 8u, "%s: Scheduler thread started", v20, v21, v22, v23, v24, v25, v26, v27, "scheduler_enable");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Au,
      1u,
      "%s: Failed to create scheduler thread",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "scheduler_enable");
    return 1;
  }
}
