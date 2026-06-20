__int64 rmnet_perf_nl_register()
{
  return genl_register_family(&rmnet_perf_nl_family);
}
