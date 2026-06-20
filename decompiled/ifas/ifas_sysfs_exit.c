__int64 ifas_sysfs_exit()
{
  __int64 result; // x0

  result = kobject_put(ifas_kobj);
  ifas_kobj = 0;
  return result;
}
