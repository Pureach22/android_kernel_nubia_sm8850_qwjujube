__int64 gh_sysfs_unregister()
{
  sysfs_remove_file_ns(hypervisor_kobj, &type_attr, 0);
  return sysfs_remove_group(hypervisor_kobj, &version_group);
}
