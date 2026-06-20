__int64 remove_global_sysfs_nodes()
{
  return kobject_put(qcom_lpm_kobj);
}
