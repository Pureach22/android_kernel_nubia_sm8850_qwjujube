bool rmnet_shs_wq_set_quickack_thresh()
{
  return (unsigned int)rmnet_module_hook_perf_set_thresh() != 0;
}
