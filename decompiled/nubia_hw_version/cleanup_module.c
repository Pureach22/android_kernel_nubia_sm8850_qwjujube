__int64 cleanup_module()
{
  sysfs_remove_group(hw_version_kobj, &nubia_hw_version_attr_group);
  return kobject_put(hw_version_kobj);
}
