void *__fastcall scheduler_core_msg_dup(const void *a1)
{
  unsigned int v8; // w8
  signed int v9; // w8
  void *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  void *v19; // x20
  unsigned int v23; // w10
  unsigned int v26; // w9

  _X9 = &_sched_queue_depth;
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v8 = __ldxr((unsigned int *)&_sched_queue_depth);
    v9 = v8 + 1;
  }
  while ( __stlxr(v9, (unsigned int *)&_sched_queue_depth) );
  __dmb(0xBu);
  if ( v9 > 1000 )
  {
    _X8 = &_sched_dup_fail_count;
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr((unsigned int *)&_sched_dup_fail_count);
    while ( __stlxr(v26 + 1, (unsigned int *)&_sched_dup_fail_count) );
    __dmb(0xBu);
  }
  else
  {
    v10 = qdf_flex_mem_alloc((__int64)sched_pool);
    if ( v10 )
    {
      v19 = v10;
      qdf_mem_copy(v10, a1, 0x30u);
      _sched_dup_fail_count = 0;
      return v19;
    }
    qdf_trace_msg(0x4Au, 2u, "%s: out of memory", v11, v12, v13, v14, v15, v16, v17, v18, "scheduler_core_msg_dup");
  }
  _X9 = &_sched_queue_depth;
  __asm { PRFM            #0x11, [X9] }
  do
    v23 = __ldxr((unsigned int *)&_sched_queue_depth);
  while ( __stxr(v23 - 1, (unsigned int *)&_sched_queue_depth) );
  return nullptr;
}
