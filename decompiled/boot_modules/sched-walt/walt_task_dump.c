__int64 __fastcall walt_task_dump(unsigned __int64 *a1)
{
  unsigned __int64 v2; // x23
  __int64 v3; // x2
  _QWORD *v4; // x22
  unsigned __int64 v5; // x24
  unsigned int v6; // w25
  int v7; // w0
  unsigned __int64 v8; // x25
  unsigned int v9; // w26
  int v10; // w0
  __int64 result; // x0
  _QWORD v12[17]; // [xsp+8h] [xbp-88h] BYREF

  v12[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v3 = *((unsigned int *)a1 + 450);
  memset(v12, 0, 32);
  if ( a1 == (unsigned __int64 *)&init_task )
    v4 = &vendor_data_pad;
  else
    v4 = a1 + 648;
  memset(&v12[4], 0, 96);
  printk_deferred("Task: %.16s-%d\n", a1 + 290, v3);
  printk_deferred("%s=%llu", "READ_ONCE(p->__state)", *((unsigned int *)a1 + 12));
  printk_deferred("%s=%llu", "task_thread_info(p)->cpu", *((unsigned int *)a1 + 10));
  printk_deferred("%s=%llu", "p->policy", *((unsigned int *)a1 + 338));
  printk_deferred("%s=%llu", "p->prio", *((int *)a1 + 37));
  printk_deferred("%s=%llu", "wts->mark_start", v4[1]);
  printk_deferred("%s=%llu", "wts->window_start", v4[2]);
  printk_deferred("%s=%llu", "wts->demand", *((unsigned int *)v4 + 7));
  printk_deferred("%s=%llu", "wts->coloc_demand", *((unsigned int *)v4 + 8));
  printk_deferred("%s=%llu", "wts->enqueue_after_migration", *((unsigned __int8 *)v4 + 360));
  printk_deferred("%s=%lld", "wts->prev_cpu", *((int *)v4 + 88));
  printk_deferred("%s=%lld", "wts->new_cpu", *((int *)v4 + 89));
  printk_deferred("%s=%llu", "wts->misfit", *((unsigned __int8 *)v4 + 189));
  printk_deferred("%s=%llu", "wts->prev_on_rq", *((int *)v4 + 69));
  printk_deferred("%s=%lld", "wts->prev_on_rq_cpu", *((int *)v4 + 70));
  printk_deferred("%s=%lld", "wts->mvp_prio", *((int *)v4 + 82));
  printk_deferred("%s=%llu", "wts->iowaited", *((unsigned __int8 *)v4 + 272));
  if ( nr_cpu_ids )
  {
    v5 = 0;
    v6 = 0;
    while ( v6 <= 0x80 && v5 < 8 )
    {
      v7 = scnprintf((char *)v12 + v6, 128 - v6, "%u ", *((_DWORD *)v4 + v5++ + 17));
      v6 += v7;
      if ( v5 >= nr_cpu_ids )
        goto LABEL_9;
    }
LABEL_15:
    __break(0x5512u);
  }
LABEL_9:
  printk_deferred("%s=%u (%s)\n", "wts->curr_window", *((_DWORD *)v4 + 33), (const char *)v12);
  if ( nr_cpu_ids )
  {
    v8 = 0;
    v9 = 0;
    while ( v9 <= 0x80 && v8 <= 7 )
    {
      v10 = scnprintf((char *)v12 + v9, 128 - v9, "%u ", *((_DWORD *)v4 + v8++ + 25));
      v9 += v10;
      if ( v8 >= nr_cpu_ids )
        goto LABEL_14;
    }
    goto LABEL_15;
  }
LABEL_14:
  printk_deferred("%s=%u (%s)\n", "wts->prev_window", *((_DWORD *)v4 + 34), (const char *)v12);
  printk_deferred("%s=%llu", "wts->last_sleep_ts", v4[26]);
  printk_deferred("%s=%llu", "wts->last_wake_ts", v4[28]);
  printk_deferred("%s=%llu", "wts->last_enqueued_ts", v4[29]);
  printk_deferred("%s=%llu", "wts->mark_start_birth_ts", v4[47]);
  printk_deferred("%s=%llu", "wts->misfit", *((unsigned __int8 *)v4 + 189));
  printk_deferred("%s=%llu", "wts->unfilter", *((unsigned int *)v4 + 55));
  printk_deferred("%s=%llu", "is_32bit_thread", (v2 >> 22) & 1);
  printk_deferred("%s=%llu", "wts->grp", v4[30]);
  printk_deferred("%s=%llu", "p->on_cpu", *((int *)a1 + 22));
  printk_deferred("%s=%llu", "p->on_rq", *((int *)a1 + 36));
  result = printk_deferred("%s=%llu", "p->se.sched_delayed", *((unsigned __int8 *)a1 + 273));
  _ReadStatusReg(SP_EL0);
  return result;
}
