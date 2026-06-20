__int64 scheduler_create_ctx()
{
  qdf_flex_mem_init((__int64)sched_pool);
  gp_sched_ctx = (__int64)&g_sched_ctx;
  return 0;
}
