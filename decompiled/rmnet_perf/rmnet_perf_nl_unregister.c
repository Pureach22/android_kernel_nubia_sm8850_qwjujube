__int64 rmnet_perf_nl_unregister()
{
  return genl_unregister_family(&rmnet_perf_nl_family);
}
