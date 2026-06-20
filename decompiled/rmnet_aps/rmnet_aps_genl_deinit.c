__int64 rmnet_aps_genl_deinit()
{
  return genl_unregister_family(&rmnet_aps_genl_family);
}
