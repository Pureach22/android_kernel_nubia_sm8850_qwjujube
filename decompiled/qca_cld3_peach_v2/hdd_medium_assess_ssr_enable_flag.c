void *hdd_medium_assess_ssr_enable_flag()
{
  void *result; // x0

  ssr_flag = 1;
  qdf_mem_set(&unk_932C50, 0x2E8u, 0);
  result = qdf_mem_set(&unk_932F44, 0x2E8u, 0);
  if ( timer_enable == 1 )
    return (void *)qdf_mc_timer_destroy((__int64)&hdd_medium_assess_timer);
  return result;
}
