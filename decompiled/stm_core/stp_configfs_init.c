__int64 stp_configfs_init()
{
  config_group_init(&stp_policy_subsys);
  _mutex_init(&unk_440, "&stp_policy_subsys.su_mutex", &stp_configfs_init___key);
  return configfs_register_subsystem(&stp_policy_subsys);
}
