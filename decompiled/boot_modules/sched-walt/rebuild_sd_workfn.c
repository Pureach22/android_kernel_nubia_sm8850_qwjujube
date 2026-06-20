__int64 rebuild_sd_workfn()
{
  char v0; // w8
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x19

  v0 = 0;
  while ( 1 )
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
    {
LABEL_5:
      rebuild_sched_domains();
      return complete(&rebuild_domains_completion);
    }
    v2 = __clz(__rbit64(v1));
    if ( !*(_QWORD *)(get_cpu_device((unsigned int)v2) + 600) )
      break;
    v0 = v2 + 1;
    if ( v2 > 0x1E )
      goto LABEL_5;
  }
  if ( (rebuild_sd_workfn___already_done & 1) == 0 )
  {
    rebuild_sd_workfn___already_done = 1;
    _warn_printk("must wait for perf domains to be created");
    __break(0x800u);
  }
  return queue_work_on(32, system_wq, &rebuild_sd_work);
}
