__int64 cleanup_module()
{
  adci_shutdown();
  sysfs_remove_group(si_core_kobj, &attr_group);
  return kobject_put(si_core_kobj);
}
