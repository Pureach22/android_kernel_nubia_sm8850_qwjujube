__int64 walt_dump()
{
  __int64 v0; // x0
  __int64 v1; // x1
  __int64 i; // x1
  char v3; // w8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x19
  __int64 v6; // x21
  __int64 v7; // x3
  __int64 v8; // x3
  __int64 v9; // x3
  __int64 v10; // x3

  v0 = printk_deferred("============ WALT RQ DUMP START ==============\n");
  if ( walt_clock_suspended == 1 )
    goto LABEL_14;
  for ( i = sched_clock(v0, v1); ; i = sched_clock_last )
  {
    printk_deferred("Sched clock: %llu\n", i);
    printk_deferred("Time last window changed=%llu\n", sched_ravg_window_change_time);
    printk_deferred("global_ws=%llu\n", walt_irq_work_lastq_ws);
    printk_deferred(
      "last_migration_irqwork_ts=%llu last_rollover_irqwork_ts=%llu\n",
      last_migration_irqwork_ts,
      last_rollover_irqwork_ts);
    printk_deferred("%s=%llu", "sched_ravg_window", (unsigned int)sched_ravg_window);
    printk_deferred("%s=%llu", "new_sched_ravg_window", (unsigned int)new_sched_ravg_window);
    v3 = 0;
    do
    {
      v4 = (unsigned int)(-1LL << v3) & _cpu_online_mask;
      if ( !(_DWORD)v4 )
        break;
      v5 = __clz(__rbit64(v4));
      walt_rq_dump((unsigned int *)(unsigned int)v5);
      v3 = v5 + 1;
    }
    while ( v5 < 0x1F );
    printk_deferred("%s=%llu", "max_possible_cluster_id", max_possible_cluster_id);
    v6 = cluster_head;
    if ( (__int64 *)cluster_head == &cluster_head )
      break;
    while ( 1 )
    {
      v7 = *(unsigned int *)(v6 + 24);
      if ( (unsigned int)v7 >= 4 )
        break;
      printk_deferred(
        "up=%u down=%u cluster=%d cgroup=%s\n",
        sched_capacity_margin_up[v7],
        sched_capacity_margin_down[v7],
        v7,
        (const char *)cgroup_names);
      v8 = *(unsigned int *)(v6 + 24);
      if ( (unsigned int)v8 > 3 )
        break;
      printk_deferred(
        "up=%u down=%u cluster=%d cgroup=%s\n",
        sched_capacity_margin_up[v8 + 4],
        sched_capacity_margin_down[v8 + 4],
        v8,
        off_DAD0[0]);
      v9 = *(unsigned int *)(v6 + 24);
      if ( (unsigned int)v9 > 3 )
        break;
      printk_deferred(
        "up=%u down=%u cluster=%d cgroup=%s\n",
        sched_capacity_margin_up[v9 + 8],
        sched_capacity_margin_down[v9 + 8],
        v9,
        off_DAD8[0]);
      v10 = *(unsigned int *)(v6 + 24);
      if ( (unsigned int)v10 > 3 )
        break;
      printk_deferred(
        "up=%u down=%u cluster=%d cgroup=%s\n",
        sched_capacity_margin_up[v10 + 12],
        sched_capacity_margin_down[v10 + 12],
        v10,
        off_DAE0);
      v6 = *(_QWORD *)v6;
      if ( (__int64 *)v6 == &cluster_head )
        return printk_deferred("============ WALT RQ DUMP END ==============\n");
    }
    __break(0x5512u);
LABEL_14:
    ;
  }
  return printk_deferred("============ WALT RQ DUMP END ==============\n");
}
