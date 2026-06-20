__int64 __fastcall scheduler_init(
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
  __int64 ctx; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19
  __int64 context; // x0
  __int64 v20; // x20
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x1
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x1

  v8 = qdf_trace_msg(0x4Au, 8u, "%s: Initializing Scheduler", a1, a2, a3, a4, a5, a6, a7, a8, "scheduler_init");
  ctx = scheduler_create_ctx(v8);
  if ( (_DWORD)ctx )
  {
    v18 = ctx;
    qdf_trace_msg(
      0x4Au,
      1u,
      "%s: Failed to create context; status:%d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "scheduler_init",
      (unsigned int)ctx);
  }
  else
  {
    context = scheduler_get_context(ctx);
    if ( context )
    {
      v20 = context;
      v21 = scheduler_queues_init();
      if ( v21 )
      {
        v18 = v21;
        context = qdf_trace_msg(
                    0x4Au,
                    1u,
                    "%s: Failed to init queues; status:%d",
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    "scheduler_init",
                    v21);
      }
      else
      {
        v30 = qdf_event_create((_DWORD *)(v20 + 504));
        if ( v30 )
        {
          v18 = v30;
          qdf_trace_msg(
            0x4Au,
            1u,
            "%s: Failed to create start event; status:%d",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "scheduler_init",
            v30);
        }
        else
        {
          v39 = qdf_event_create((_DWORD *)(v20 + 552));
          if ( v39 )
          {
            v18 = v39;
            qdf_trace_msg(
              0x4Au,
              1u,
              "%s: Failed to create shutdown event; status:%d",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "scheduler_init",
              v39);
          }
          else
          {
            v18 = qdf_event_create((_DWORD *)(v20 + 624));
            if ( !v18 )
            {
              *(_DWORD *)(v20 + 664) = 0;
              *(_QWORD *)(v20 + 672) = 0;
              _init_waitqueue_head(v20 + 592, "&sched_ctx->sch_wait_queue", &scheduler_init___key);
              *(_DWORD *)(v20 + 712) = 10000;
              *(_QWORD *)(v20 + 616) = 0;
              *(_QWORD *)(v20 + 760) = scheduler_watchdog_timeout;
              *(_QWORD *)(v20 + 768) = v20;
              init_timer_key(v20 + 720, _os_timer_shim_1, 0x80000, 0, 0);
              qdf_register_mc_timer_callback(scheduler_mc_timer_callback);
              return v18;
            }
            qdf_trace_msg(
              0x4Au,
              1u,
              "%s: Failed to create resume event; status:%d",
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "scheduler_init",
              v18);
            qdf_event_destroy(v20 + 552, v57);
          }
          qdf_event_destroy(v20 + 504, v48);
        }
        context = scheduler_queues_deinit(v20);
      }
    }
    else
    {
      v18 = 16;
    }
    scheduler_destroy_ctx(context);
  }
  return v18;
}
