__int64 stp_configfs_exit()
{
  return configfs_unregister_subsystem(&stp_policy_subsys);
}
