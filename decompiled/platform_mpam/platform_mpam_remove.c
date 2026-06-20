__int64 platform_mpam_remove()
{
  return configfs_unregister_subsystem(&platform_mpam_subsys);
}
