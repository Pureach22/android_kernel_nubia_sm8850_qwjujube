__int64 ifas_sysfs_init()
{
  __int64 result; // x0

  result = kobject_create_and_add("ifas", kernel_kobj);
  ifas_kobj = result;
  if ( !result )
    return printk(&unk_F788, "ifas");
  return result;
}
