__int64 rmnet_core_genl_deinit()
{
  genl_unregister_family(&rmnet_core_genl_family);
  return 0;
}
