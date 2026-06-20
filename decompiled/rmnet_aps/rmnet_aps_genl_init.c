__int64 rmnet_aps_genl_init()
{
  return genl_register_family(&rmnet_aps_genl_family);
}
