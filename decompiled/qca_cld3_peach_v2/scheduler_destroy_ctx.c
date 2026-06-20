__int64 scheduler_destroy_ctx()
{
  gp_sched_ctx = 0;
  qdf_flex_mem_deinit(sched_pool);
  return 0;
}
