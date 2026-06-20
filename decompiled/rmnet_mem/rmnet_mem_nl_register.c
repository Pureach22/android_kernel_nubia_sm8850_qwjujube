__int64 rmnet_mem_nl_register()
{
  return genl_register_family(&rmnet_mem_nl_family);
}
