__int64 __fastcall scheduler_disable(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  unsigned __int64 v26; // x9
  unsigned __int64 v29; // x9

  v8 = qdf_trace_msg(0x4Au, 8u, "%s: Disabling Scheduler", a1, a2, a3, a4, a5, a6, a7, a8, "scheduler_disable");
  context = scheduler_get_context(v8);
  if ( !context )
    return 4;
  if ( *(_QWORD *)(context + 544) )
  {
    _X8 = (unsigned __int64 *)(context + 616);
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr(_X8);
    while ( __stxr(v26 | 0x10000, _X8) );
    _X8 = (unsigned __int64 *)(context + 616);
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr(_X8);
    while ( __stxr(v29 | 2, _X8) );
    v18 = context;
    _wake_up(context + 592, 1, 1, 0);
    qdf_wait_single_event(v18 + 552, 0);
    *(_QWORD *)(v18 + 544) = 0;
    scheduler_queues_flush(v18);
  }
  else
  {
    qdf_trace_msg(
      0x4Au,
      8u,
      "%s: Scheduler already disabled",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "scheduler_disable");
  }
  return 0;
}
