__int64 __fastcall walt_rq_dump(unsigned int *_X0)
{
  __int64 v1; // x19
  int v2; // w20
  char *v3; // x21
  __int64 v4; // x22
  __int64 v5; // x9
  unsigned int v12; // w8

  if ( (unsigned int)_X0 >= 0x20
    || (v2 = (int)_X0,
        v3 = (char *)&runqueues + *((_QWORD *)&_per_cpu_offset + (unsigned int)_X0),
        v5 = *((unsigned int *)v3 + 908),
        (unsigned int)v5 > 0x1F) )
  {
    __break(0x5512u);
  }
  else
  {
    v1 = *((_QWORD *)v3 + 418);
    v4 = *((_QWORD *)&_per_cpu_offset + v5);
    _X0 = (unsigned int *)(v1 + 64);
  }
  __asm { PRFM            #0x11, [X0] }
  do
    v12 = __ldxr(_X0);
  while ( __stxr(v12 + 1, _X0) );
  if ( !v12 || (((v12 + 1) | v12) & 0x80000000) != 0 )
    refcount_warn_saturate();
  printk_deferred(
    "CPU:%d nr_running:%u current: %d (%s)\n",
    v2,
    *((_DWORD *)v3 + 1),
    *(_DWORD *)(v1 + 1800),
    (const char *)(v1 + 2320));
  printk_deferred("==========================================");
  printk_deferred("%s=%llu", "wrq->latest_clock", *(_QWORD *)((char *)&walt_rq + v4 + 616));
  printk_deferred("%s=%llu", "wrq->window_start", *(_QWORD *)((char *)&walt_rq + v4 + 64));
  printk_deferred("%s=%llu", "wrq->prev_window_size", *(unsigned int *)((char *)&walt_rq + v4 + 72));
  printk_deferred("%s=%llu", "wrq->curr_runnable_sum", *(_QWORD *)((char *)&walt_rq + v4 + 144));
  printk_deferred("%s=%llu", "wrq->prev_runnable_sum", *(_QWORD *)((char *)&walt_rq + v4 + 152));
  printk_deferred("%s=%llu", "wrq->nt_curr_runnable_sum", *(_QWORD *)((char *)&walt_rq + v4 + 160));
  printk_deferred("%s=%llu", "wrq->nt_prev_runnable_sum", *(_QWORD *)((char *)&walt_rq + v4 + 168));
  printk_deferred("%s=%llu", "wrq->task_exec_scale", *(_QWORD *)((char *)&walt_rq + v4 + 120));
  printk_deferred("%s=%llu", "wrq->grp_time.curr_runnable_sum", *(_QWORD *)((char *)&walt_rq + v4 + 176));
  printk_deferred("%s=%llu", "wrq->grp_time.prev_runnable_sum", *(_QWORD *)((char *)&walt_rq + v4 + 184));
  printk_deferred("%s=%llu", "wrq->grp_time.nt_curr_runnable_sum", *(_QWORD *)((char *)&walt_rq + v4 + 192));
  printk_deferred("%s=%llu", "wrq->grp_time.nt_prev_runnable_sum", *(_QWORD *)((char *)&walt_rq + v4 + 200));
  printk_deferred("wrq->load_subs[%d].window_start=%llu)\n", 0, *(_QWORD *)((char *)&walt_rq + v4 + 208));
  printk_deferred("wrq->load_subs[%d].subs=%llu)\n", 0, *(_QWORD *)((char *)&walt_rq + v4 + 216));
  printk_deferred("wrq->load_subs[%d].new_subs=%llu)\n", 0, *(_QWORD *)((char *)&walt_rq + v4 + 224));
  printk_deferred("wrq->load_subs[%d].window_start=%llu)\n", 1, *(_QWORD *)((char *)&walt_rq + v4 + 232));
  printk_deferred("wrq->load_subs[%d].subs=%llu)\n", 1, *(_QWORD *)((char *)&walt_rq + v4 + 240));
  printk_deferred("wrq->load_subs[%d].new_subs=%llu)\n", 1, *(_QWORD *)((char *)&walt_rq + v4 + 248));
  return walt_task_dump((unsigned __int64 *)v1);
}
