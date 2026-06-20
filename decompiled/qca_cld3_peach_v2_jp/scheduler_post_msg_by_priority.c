__int64 __fastcall scheduler_post_msg_by_priority(__int64 a1, unsigned __int16 *a2, char a3)
{
  unsigned int v4; // w20
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w1
  unsigned int v16; // w8
  __int64 v17; // x22
  unsigned int v18; // w2
  unsigned int v19; // w20
  const char *v21; // x2
  unsigned __int64 v22; // x23
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x0
  unsigned __int64 v32; // x9

  if ( !a2 )
    return 4;
  v4 = a1;
  context = scheduler_get_context(a1);
  if ( !context )
    return 4;
  if ( !*(_QWORD *)(context + 544) )
  {
    v21 = "%s: Cannot post message; scheduler thread is stopped";
LABEL_17:
    qdf_trace_msg(0x4Au, 2u, v21, v7, v8, v9, v10, v11, v12, v13, v14, "scheduler_post_msg_by_priority");
    return 16;
  }
  if ( a2[1] != 64206 && a2[1] )
    return 16;
  v15 = (v4 >> 10) & 0x3FF;
  if ( v15 > 0xA6 || (v4 & 0x3FF) > 0xA6 || (v16 = (v4 >> 20) & 0x3FF, v16 >= 0xA7) )
  {
    v21 = "%s: Src_id/Dest_id invalid, cannot post message";
    goto LABEL_17;
  }
  v17 = context;
  if ( (v4 & 0x3FF) == 0x36 )
  {
    v18 = *a2;
    *((_QWORD *)a2 + 2) = 0;
    qdf_mtrace(v16, v15, v18, 0xFFu, 0);
    v19 = 73;
  }
  else
  {
    v19 = v4 & 0x3FF;
    qdf_mtrace(v16, v15, *a2, 0xFFu, 0);
    if ( v19 >= 0xA7 )
    {
      __break(0x5512u);
      goto LABEL_28;
    }
  }
  v22 = *(unsigned __int8 *)(v17 + v19 + 288);
  if ( v22 >= 6 )
  {
    v21 = "%s: Scheduler is deinitialized ignore msg";
    goto LABEL_17;
  }
  if ( !*(_QWORD *)(v17 + 8 * v22 + 456) )
  {
    qdf_trace_msg(
      0x4Au,
      2u,
      "%s: callback not registered for qid[%d]",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "scheduler_post_msg_by_priority",
      v19);
    return 16;
  }
  v23 = scheduler_core_msg_dup(a2);
  if ( !v23 )
    return 2;
  v24 = v23;
  v25 = v17 + 48LL * (unsigned int)v22;
  if ( (a3 & 1) != 0 )
    scheduler_mq_put_front(v25, v24);
  else
    scheduler_mq_put(v25, v24);
LABEL_28:
  _X8 = (unsigned __int64 *)(v17 + 616);
  __asm { PRFM            #0x11, [X8] }
  do
    v32 = __ldxr(_X8);
  while ( __stxr(v32 | 2, _X8) );
  _wake_up(v17 + 592, 1, 1, 0);
  return 0;
}
