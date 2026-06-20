__int64 gpu_ctrl_init()
{
  ifas_sysfs_create_file(0, &kobj_attr_gpu_min_pwrlevel_limit);
  ifas_sysfs_create_file(0, &kobj_attr_gpu_max_pwrlevel_limit);
  return ifas_sysfs_create_file(0, &kobj_attr_gpu_max_pwrlevel_ceiling);
}
