__int64 nr_notify_userspace()
{
  sysfs_notify(notify_kobj, 0, "aggr_top_load");
  sysfs_notify(notify_kobj, 0, "aggr_big_nr");
  sysfs_notify(notify_kobj, 0, "top_load_cluster");
  return sysfs_notify(notify_kobj, 0, "curr_cap_cluster");
}
