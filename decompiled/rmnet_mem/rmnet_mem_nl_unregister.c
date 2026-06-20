__int64 rmnet_mem_nl_unregister()
{
  return genl_unregister_family(&rmnet_mem_nl_family);
}
